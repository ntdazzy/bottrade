// Raw strategy parameters verified against native assignment blocks.
// Later scaling, broker limits and enable/frequency selection are not implemented here.
#ifndef BOT1_ENTRY_PROFILES_MQH
#define BOT1_ENTRY_PROFILES_MQH
struct Bot1EntryProfile
{
   int confirmation_frame;
   int hour1_flag;
   int older_width;
   int recent_width;
   int last_shift;
   double gap_points;
};
bool Bot1LoadEntryProfile(const int index,Bot1EntryProfile &profile)
{
   if(index<0 || index>=8) return false;
   int confirmation_frame[8]={16408,16388,16408,16408,16408,16408,16408,16408};
   profile.confirmation_frame=confirmation_frame[index];
   int hour1_flag[8]={1,1,1,1,1,1,1,1};
   profile.hour1_flag=hour1_flag[index];
   int older_width[8]={4,8,18,4,15,12,17,7};
   profile.older_width=older_width[index];
   int recent_width[8]={2,10,3,2,3,2,2,2};
   profile.recent_width=recent_width[index];
   int last_shift[8]={160,150,180,240,230,50,110,20};
   profile.last_shift=last_shift[index];
   double gap[8]={150.0,600.0,900.0,900.0,550.0,700.0,150.0,250.0};
   profile.gap_points=gap[index];
   return true;
}
#endif
