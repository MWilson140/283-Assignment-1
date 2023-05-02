/*todo
*/
#include "date.h"
Date::Date()
{
    Day = 0;
    Year = 0;
    Month = 0;
}
Date::Date(int d, int m, int y) //change to try catch
{
    try
    {
        YearCheck(y);
        Year = y;
        MonthCheck(m);
        Month = m;
        DayCheck(d);
        Day = d;
    }
    catch (const char* a)
    {
        throw a;
    }
}

Date::Date (const Date & d)
{
    this->Day = d.Day;
    this->Month = d.Month;
    this->Year = d.Year;
}
Date::~Date()
{
}
void Date::SetDay(int n)
{
    //cout << "setday" << n;
    try
    {
        DayCheck(n);
    }
    catch (const char* a)
    {
        throw (a);
    }
    Day = n;
}
int Date::GetDay() const
{
    return Day;
}
void Date::SetMonth(int m)
{
    try
    {
        MonthCheck(m);
        Month = m;
        if (Day != 0)
            DayCheck(Day);
    }
    catch (const char* a)
    {
        throw (a);
    }

}
int Date::GetMonth() const
{
    return Month;
}
void Date::SetYear(int n)
{
        YearCheck(n);
        Year = n;
        if (Day !=0)
        DayCheck(Day);
}
int Date::GetYear() const
{
    return Year;
}

void Date::MonthCheck(int m)
{
    if (m < 1 || m > 12)
    {
       throw "Month check error";
    }
}

void Date::DayCheck(int n)
{
    //std::cout<<"day check" << n;
    int maxDay = 31;
    if (Month != 0)
    {
        //std::cout<< "switcg";
        switch (Month)
            {
                case 1:
                    maxDay = 31;
                    break;
                case 2:
                    if(LeapYear(Year))
                       maxDay = 29;
                       else
                        maxDay = 28;
                        break;
                case 3:
                    maxDay = 31;
                    break;
                case 4:
                    maxDay = 30;
                    break;
                case 5:
                    maxDay = 31;
                    break;
                case 6:
                    maxDay = 30;
                    break;
                case 7:
                    maxDay = 31;
                    break;
                case 8:
                    maxDay = 31;
                    break;
                case 9:
                    maxDay = 30;
                    break;
                case 10:
                    maxDay = 31;
                    break;
                case 11:
                    maxDay = 30;
                    break;
                case 12:
                    maxDay = 31;
                    break;
            }
    }
    if (n > 0 && n <= maxDay)
        {
            //std::cout<<"true";
        }
    else
    {
         // std::cout<<"false here";
           throw "day out of bounds";
    }

}

bool Date::LeapYear(int y)
{
    if (y % 4 == 0)
        {
            if (y % 100 == 0)
                {
                    if (y % 400 == 0)
                    {
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            else
            {
                return true;
            }
        }
    else
    {
        return false;
    }
}

void Date::YearCheck(int n)
{
    if (n < 1 || n > 3000)
        throw ("year out of bounds");
}
