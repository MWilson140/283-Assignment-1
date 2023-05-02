#include "AirProcData.h"
AirProcData::AirProcData()
{

}

AirProcData::AirProcData(int n)
{
    year = n;
}

AirProcData::AirProcData(int y, int m)
{
    year = y;
    month = m;
}


AirProcData::~AirProcData()
{
}

void AirProcData::GetData(RawData & MD) //month check in here
{
    int errors = 0;
    float sum = 0;
    Vector<float> All;
    Vector<float> Days;

    for (int i = start+1; i < end; i++)
    {
        if (MD[i-1].GetAirTemp() != -100.0)
            {
                All.AddTo(MD[i-1].GetAirTemp());
            }
        if (i + 1 == end || MD[i-1].GetDate().GetDay() != MD[i].GetDate().GetDay())
        {
            if (i + 1 == end && MD[i].GetAirTemp() != -100.0)
            {

                    All.AddTo(MD[i].GetAirTemp());
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
