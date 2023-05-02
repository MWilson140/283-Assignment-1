#include "windprocdata.h"

WindProcData::WindProcData()
{
}

WindProcData::WindProcData(int y, int m)
{
    year = y;
    month = m;
}

WindProcData::~WindProcData()
{

}

void WindProcData::GetData(RawData & MD)
{
    float sum = 0;
    Vector<float> All;
    Vector<float> Days;

    for (int i = start+1; i < end; i++)
    {
        if (MD[i-1].GetAirTemp() != -100.0)
            {
                All.AddTo(MD[i-1].GetSpeed());
            }
        if (i + 1 == end || MD[i-1].GetDate().GetDay() != MD[i].GetDate().GetDay())
        {
            if (i + 1 == end && MD[i].GetSpeed() != -100.0)
            {
                All.AddTo(MD[i].GetSpeed());
            }
            sum = 0;
            sum = CalcTotal(All);
            Days.AddTo(CalcMean(sum, All.GetLength()));
            All.Empty();
        }
        if (i + 1 == end || MD[i-1].GetDate().GetMonth() != MD[i].GetDate().GetMonth())
            {
                months.AddTo(Days);
                Days.Empty();
            }
    }
    for (int i = 0; i < months.GetLength(); i++)
    {
        sum = 0;
        sum = CalcTotal(months[i]);
        mean.AddTo(CalcMean(sum, months[i].GetLength()));
        stdDev.AddTo(CalcStdDev(months[i],mean[i]));
        Days.Empty();
    }
}
