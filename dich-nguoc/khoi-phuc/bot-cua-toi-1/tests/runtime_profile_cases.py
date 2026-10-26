"""Finite scalar cases for Bot1RuntimeProfile.mqh.

The file contains inputs only. Expected values are collected from the native
profile blocks by check-runtime-profile.py and are never computed here.
"""
import struct

MAGIC = 0x52504631
VERSION = 1
HEADER = struct.Struct("<3i")
CASE = struct.Struct("<3iI5d")
RESULT = struct.Struct("<3i23Q")
DELTA_NAMES = ("price_delta", "stop_delta", "target_delta", "trail_delta")


def cases():
    rows = []
    next_id = 0
    for randomization in (-1.0, 0.0, 0.25, 1.0):
        for seed in (0, 1, 0xFFFFFFFF):
            for hl in (0, 1):
                for index in range(8):
                    rows.append({
                        "id": next_id, "index": index, "hl": hl, "seed": seed,
                        "randomization": randomization,
                        "price_delta": 0.0, "stop_delta": 0.0,
                        "target_delta": 0.0, "trail_delta": 0.0,
                        "group": "finite-randomization",
                    })
                    next_id += 1
    for selected in DELTA_NAMES:
        for value in (-1.0, 1.0):
            for hl in (0, 1):
                for index in range(8):
                    row = {
                        "id": next_id, "index": index, "hl": hl, "seed": 1,
                        "randomization": 0.25,
                        "price_delta": 0.0, "stop_delta": 0.0,
                        "target_delta": 0.0, "trail_delta": 0.0,
                        "group": "adjustment-" + selected,
                    }
                    row[selected] = value
                    rows.append(row)
                    next_id += 1
    for randomization in (float("nan"), float("inf"), float("-inf")):
        for hl in (0, 1):
            for index in range(8):
                rows.append({
                    "id": next_id, "index": index, "hl": hl, "seed": 1,
                    "randomization": randomization,
                    "price_delta": 0.0, "stop_delta": 0.0,
                    "target_delta": 0.0, "trail_delta": 0.0,
                    "group": "special-randomization",
                })
                next_id += 1
    for selected in DELTA_NAMES:
        for hl in (0, 1):
            for index in range(8):
                row = {
                    "id": next_id, "index": index, "hl": hl, "seed": 1,
                    "randomization": 0.0,
                    "price_delta": 0.0, "stop_delta": 0.0,
                    "target_delta": 0.0, "trail_delta": 0.0,
                    "group": "nan-adjustment-" + selected,
                }
                row[selected] = float("nan")
                rows.append(row)
                next_id += 1
    if len(rows) != 432 or any(row["id"] != i for i, row in enumerate(rows)):
        raise AssertionError("bot1 runtime profile case set changed")
    return rows


def encode(rows):
    out = bytearray(HEADER.pack(MAGIC, VERSION, len(rows)))
    for row in rows:
        out.extend(CASE.pack(
            row["id"], row["index"], row["hl"], row["seed"],
            row["randomization"], row["price_delta"], row["stop_delta"],
            row["target_delta"], row["trail_delta"],
        ))
    return bytes(out)
