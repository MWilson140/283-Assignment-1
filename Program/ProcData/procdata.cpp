#include "procdata.h"

void ProcData::FindStart(const RawData & MD)
{
    start = 0;
    while(start != MD.GetLength() && MD[start].GetDate().GetYear() != year)
    {
        start++;
    }
    while (month != 0 && start != MD.GetLength() && MD[start].GetDate().GetMonth() != month)
    {
        start++;
    }
}

void ProcData::FindEnd(const RawData & MD)
{
    end = start;
        while((end < MD.GetLength()-1) && ((month == 0 || MD[end].GetDate().GetMonth() == month)
          && (MD[end].GetDate().GetYear() == year)))
        {
            end++;
        }
}
