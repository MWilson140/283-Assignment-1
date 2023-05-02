#include "dailyData.h"

void AllData::SetSpeed(float n)
{
    speed = n;
}
float AllData::GetSpeed() const
{
    return speed;
}
void AllData::SetAirTemp(float n)
{
    ambientAirTemp = n;
}
float AllData::GetAirTemp() const
{
    return ambientAirTemp;
}
void AllData::SetSolarRad(float n)
{
    solarRadiation = n;
}
float AllData::GetSolarRad() const
{
    return solarRadiation;
}

void AllData::SetDate(Date d)
{
    date = d;
}
Date AllData::GetDate() const
{
    return date;
}
void AllData::SetTime(Time t)
{
    time = t;
}

Time AllData::GetTime() const
{
    return time;
}
