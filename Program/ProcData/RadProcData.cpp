#include "RadProcData.h"

RadProcData::RadProcData()
{
}

RadProcData::RadProcData(int n)
{
    year = n;
}

RadProcData::RadProcData(int y, int m)
{
    year = y;
    month = m;
}
RadProcData::~RadProcData()
{

}
void RadProcData::GetData(RawData & MD) //needs to be redone, dont calc mean, just add
{
    Vector<float> All;
    Vector<float> Days;
    for (int i = start+1; i < end; i++)
    {

            if (MD[i-1].GetSolarRad() >= 100)
            {
                All.AddTo(MD[i-1].GetSolarRad());
            }

            if (i + 1 == end || MD[i-1].GetDate().GetDay() != MD[i].GetDate().GetDay())
            {
                if (i + 1 == end && MD[i].GetSolarRad() >=100)
                {
                    All.AddTo(MD[i].GetSolarRad());
                }
                Days.AddTo(CalcTotal(All));
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
        for (int j = 0; j < months[i].GetLength(); j++)
        {
            months[i][j] = calcRad(months[i][j]);
        }
        mean.AddTo(CalcTotal(months[i]));
    }
}

float RadProcData::calcRad(float n)
{
    return (n/6/1000);
}

