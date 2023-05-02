#include <iostream>

#include <string>
#include "../dailyData.h"
#include "../../Time/Time.h"
#include "../../Date/Date.h"


using namespace std;

void TestSpeed();
void TestAirTemp();
void TestSolarRad();

int main()
{
    TestSpeed();
    TestAirTemp();
    TestSolarRad();
    return 0;
}


void TestSpeed()
{
    std::cout<<"Testing speed" <<std::endl;
    AllData RD;
    RD.SetSpeed(1);
    std::cout<<RD.GetSpeed()<< std::endl;
}
void TestAirTemp()
{
    std::cout<<"Testing Air Temp" <<std::endl;
    AllData RD;
    RD.SetAirTemp(14);
    std::cout<<RD.GetAirTemp() << std::endl;
}
void TestSolarRad()
{
    std::cout<<"Testing Solar Rad" <<std::endl;
    AllData RD;
    RD.SetSolarRad(44);
    std::cout<<RD.GetSolarRad() << std::endl;
}

