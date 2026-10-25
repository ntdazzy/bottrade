// Native 0x557f0: sort history keys and move paired values; left part recursive, right part looped.
#ifndef BOT3_HISTORY_SORT_MQH
#define BOT3_HISTORY_SORT_MQH
// Keys compare as unsigned 64-bit and each array keeps its own series flag. The middle
// key is read before the left>right test so a bad middle index still hits the array check.
void Bot3HistorySort(ulong &keys[],long &values[],int left,int right)
{
   do
   {
      ulong pivot=keys[(left+right)/2];
      int i=left,j=right;
      while(i<=j)
      {
         ulong left_key=keys[i];
         while(left_key<pivot) left_key=keys[++i];
         ulong right_key=keys[j];
         while(right_key>pivot) right_key=keys[--j];
         if(i<=j)
         {
            keys[i]=right_key;
            keys[j]=left_key;
            long value=values[i];
            values[i]=values[j];
            values[j]=value;
            i++;
            j--;
         }
      }
      if(left<j) Bot3HistorySort(keys,values,left,j);
      left=i;
   }
   while(left<right);
}
#endif
