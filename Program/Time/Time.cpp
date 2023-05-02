#include "Time.h"

Time::Time()
{
    second = 0;
    minute = 0;
    hour = 0;
}
Time::Time(int s, int m, int h)
{
    try
    {
        CheckSecond(s);
        CheckMinute(m);
        CheckHour(h);
    }
    catch (const char* c)
    {
        throw c;
    }
    second = s;
    minute = m;
    hour = h;
}

Time::Time(const Time & T)
{
    this->second = T.second;
    this->minute = T.minute;
    this->hour = T.hour;
}
Time::~Time()
{

}
void Time::SetSecond(int n)
{
    try
    {
        CheckSecond(n);
    }
    catch (const char* c)
    {
        throw c;
    }
    second = n;
}

void Time::CheckSecond(int n)
{
    if(n < 0 || n > 59)
        throw "Second out of bounds";
}

int Time::GetSecond() const
{
    return second;
}
void Time::SetMinute(int n)
{
    try
    {
        CheckMinute(n);
    }
    catch (const char* c)
    {
        throw c;
    }
    minute = n;

}

void Time::CheckMinute(int n)
{
    if (n < 0 || n > 59)
        throw "Minutes out of bounds";
}
int Time::GetMinute() const
{
    return minute;
}
void Time::SetHour(int n)
{
    try
    {
        CheckHour(n);
    }
    catch (const char* c)
    {
        throw c;
    }
    hour = n;
}

void Time::CheckHour(int n)
{
    if (n < 0 || n > 23)
        throw "Hour out of bounds";
}
int Time::GetHour() const
{
    return hour;
}

