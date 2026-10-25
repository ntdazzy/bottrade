// Native 0x47950: sort ulong keys with paired long values; pivot read even when left>right.
#ifndef BOT1_HISTORY_SORT_MQH
#define BOT1_HISTORY_SORT_MQH
void Bot1HistorySort(ulong &keys[],long &values[],int left,int right)
{
   do
   {
      ulong pivot=keys[(left+right)/2];
      int i=left;
      int j=right;
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
            long saved_value=values[i];
            values[i]=values[j];
            values[j]=saved_value;
            i++;
            j--;
         }
      }
      if(left<j) Bot1HistorySort(keys,values,left,j);
      left=i;
   }
   while(left<right);
}
#endif
