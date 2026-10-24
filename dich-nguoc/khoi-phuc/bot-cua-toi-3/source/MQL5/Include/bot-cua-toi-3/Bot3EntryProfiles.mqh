// Raw strategy parameters verified against native assignment blocks.
// Later scaling, broker limits and enable/frequency selection are not implemented here.
#ifndef BOT3_ENTRY_PROFILES_MQH
#define BOT3_ENTRY_PROFILES_MQH
struct Bot3EntryProfile
{
   int confirmation_frame;
   int entry_frame;
   int older_width;
   int recent_width;
   int last_shift;
   double gap_points;
};
bool Bot3LoadEntryProfile(const int index,Bot3EntryProfile &profile)
{
   if(index<0 || index>=9) return false;
   int confirmation_frame[9]={16408,16408,16408,16388,16385,16385,16385,16385,16385};
   profile.confirmation_frame=confirmation_frame[index];
   int entry_frame[9]={15,16385,16385,16385,15,5,15,15,15};
   profile.entry_frame=entry_frame[index];
   int older_width[9]={24,15,7,12,30,26,25,26,7};
   profile.older_width=older_width[index];
   int recent_width[9]={3,3,2,8,19,24,23,20,5};
   profile.recent_width=recent_width[index];
   int last_shift[9]={105,230,20,90,110,140,145,235,200};
   profile.last_shift=last_shift[index];
   double gap[9]={45.0,550.0,250.0,1050.0,160.0,120.0,10.0,80.0,40.0};
   profile.gap_points=gap[index];
   return true;
}
#endif
