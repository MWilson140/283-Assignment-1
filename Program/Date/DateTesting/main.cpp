#include <iostream>
#include "../Date.h"
#include <string>

using namespace std;
ostream & operator << (ostream & output, Date & d);
void Constructor();
void LYear();
void YOOB();
void MOOB();
void MtD();
void DtM();
void DtY();
void AssignEqul();

int main()
{
    Constructor();
    YOOB();
    MOOB();
    LYear();
    MtD();
    DtM();
    DtY();
    AssignEqul();
    return 0;
}

void Constructor()
{

    std::cout<<"testing param constructor" <<std::endl;
    Date d(11,2,1995);
    std::cout<<d;
    std::cout<<"testing default con and setters" <<std::endl;
    Date d1;
    std::cout<<"also tested different orders"  <<std::endl;
    d1.SetYear(1995);
    d1.SetDay(1);
    d1.SetMonth(5);
    std::cout<<d1;
    std::cout<<"testing invalid Day"<<std::endl;
    try
    {
        Date d2(41, 2, 1996);
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }
    std::cout<<"testing invalid Month"<<std::endl;
    try
    {
        Date d3(10, 15, 1996);
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }
    std::cout<<"testing invalid Year"<<std::endl;
    try
    {
        Date d3(10, 10, -1);
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }

    std::cout<<"Done" <<std::endl <<std::endl;

}
void YOOB()
{
    std::cout<<"Testing year out of bounds" <<std::endl;
    std::cout<<"year 0"<<std::endl;
    Date d (11,6,1996);
    try
    {
        d.SetYear(0);
        std::cout<<d<<std::endl;
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }
    std::cout<<"year 4500"<<std::endl;
    try
    {
        d.SetYear(4500);
        std::cout<<d<<std::endl;
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }
    std::cout<<std::endl;
}
void MOOB()
{
    std::cout<<"Testing month out of bounds" <<std::endl;
    Date d(11, 6, 1996);
    std::cout << "month 0" <<std::endl;
    try
    {
        d.SetMonth(0);
        std::cout<<d<<std::endl;
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }

    std::cout<<"testing month 13"<<std::endl;
    try
    {
        d.SetMonth(13);
        std::cout<<d<<std::endl;
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }
    std::cout<<std::endl;
}

void LYear()
{
    std::cout<<"leep year testing" <<std::endl;
    std::cout<<"works, made the function public, tested then made private. this routine no longer functions"<<std::endl <<std::endl;
    /*
    Date d;
    std::cout<<"Testing leap year";
    for(int i = 1800; i < 2200; i++)
    {
        if (d.LeapYear(i) == 1)
        std::cout<<"year: " << i <<std::endl;
    }*/
}

void MtD()
{
    std::cout<<"testing setting month, then day"<<std::endl;
    std::cout<<"leep year, feb 29th" <<std::endl;
    Date d(1,1,1995);

    d.SetYear(1996);
    d.SetMonth(2);
    d.SetDay(29);
    std::cout<<d;

    std::cout<<"non leep year, feb 29th" <<std::endl;
    try
    {
        d.SetYear(1995);
        d.SetMonth(2);
        d.SetDay(29);
    }
    catch (const char* e)
    {
        std::cout<<e <<std::endl;
    }

    std::cout<<"31 day month, day 31" <<std::endl;
    d.SetMonth(3);
    d.SetDay(31);
    std::cout<< d;

    std::cout<<"30 day month, day 31" <<std::endl;

    try
    {
        d.SetMonth(4);
        d.SetDay(31);
        std::cout<<d;
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }
    std::cout<<std::endl;
}

void DtM()
{
    std::cout<<"Testing Day then Month" <<std::endl;
    Date d(1,1,2000);
    d.SetYear(2011);
    d.SetMonth(3);
    d.SetDay(31);
    std::cout<<"Month: 3, day: 31, setting month to 2"<<std::endl;
    try
    {
        d.SetMonth(2);
        std::cout<<d;
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }
    std::cout<<"done testing"<<std::endl;
    std::cout<<std::endl;
}

void DtY()
{
    std::cout<<"testing setting day then year" <<std::endl;
    Date d (29, 2, 1996);
    std::cout<<d;
    std::cout<<"setting year to non leep year"<<std::endl;
    try
    {
        d.SetYear(1995);
        std::cout<<d;
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }
}

void AssignEqul()
{
    std::cout<<"Assignemnt opperator"<<std::endl;
    Date d(11,3,2013);
    std::cout<<d;
    Date d1;
    d1=d;
    std::cout<<d1;
    std::cout<<"Copy constructor"<<std::endl;
    Date d2(d);
    std::cout<<d2;
}

ostream & operator << (ostream & output, Date & d)
{
    std::cout<< "Day: " << d.GetDay() << " Month: " << d.GetMonth() << " Year: " << d.GetYear() <<endl;

    return output;
}
