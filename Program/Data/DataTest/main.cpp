#include <iostream>

#include "../Data.h"
#include "../../Vector/Vector.h"

using namespace std;

void TestCalcTotalInt();
void TestCalcTotalFlo();
void TestCalcMeanInt();
void TestCalcMeanFlo();
void TestStdDevInt();
void TestStdDevFlo();

int main()
{
    TestCalcTotalInt();
    TestCalcTotalFlo();
    TestCalcMeanInt();
    TestCalcMeanFlo();
    TestStdDevFlo();
    return 0;
}


void TestCalcTotalInt()
{
    std::cout<<"Calc Total Int" << std::endl;
    Vector<int> IV;
    std::cout<<"10 and -4" << std::endl;
    IV.AddTo(10);
    IV.AddTo(-4);
    std::cout<<CalcTotal(IV) <<std::endl;
    std::cout<<"Sum of 0" <<std::endl;
    Vector<int> IV2;
    IV2.AddTo(15);
    IV2.AddTo(-10);
    IV2.AddTo(-5);
    std::cout<<CalcTotal(IV2) <<std::endl;
    std::cout<<"Negative total" << std::endl;
    IV.AddTo(-14);
    std::cout<<CalcTotal(IV) << std::endl;
    std::cout<<"End of testing" <<std::endl<<std::endl;
}
void TestCalcTotalFlo()
{
    std::cout<<"Calc Total Float" << std::endl;
    Vector<float> IV;
    std::cout<<"10.5 and -.9" << std::endl;
    IV.AddTo(10.5);
    IV.AddTo(-.9);
    std::cout<<CalcTotal(IV) <<std::endl;
    std::cout<<"Sum of 0" <<std::endl;
    Vector<int> IV2;
    IV2.AddTo(12.5);
    IV2.AddTo(-7.1);
    IV2.AddTo(-5.4);
    std::cout<<CalcTotal(IV2) <<std::endl;
    std::cout<<"Negative sum" << std::endl;
    IV.AddTo(-6.4);
    IV.AddTo(-8.3);
    std::cout<<CalcTotal(IV) <<std::endl;
    std::cout<<"End of testing" <<std::endl <<std::endl;
}
void TestCalcMeanInt()
{
    std::cout<<"Calc Mean Int" << std::endl;
    std::cout << "20 and 5" << std::endl;
    std::cout<<CalcMean(20, 5) <<std::endl;
    std::cout << "52 and 3" << std::endl;
    std::cout<<CalcMean(52, 3);
    std::cout<<"Negative result, -15, 3" << std::endl;
    std::cout<<CalcMean(-15, 3) << std::endl;
    std::cout<<"between 0.1 and zero" << std::endl;
    std::cout<<CalcMean(1,100) <<std::endl;
    try
    {
        std::cout<<"Negative total" <<std::endl;
        std::cout<< CalcMean(20, -2) <<std::endl;
    }
    catch (const char* e)
    {
       std::cout<<(e) <<std::endl;
    }
    std::cout<<"End of testing" << std::endl<<std::endl;

}
void TestCalcMeanFlo()
{
    std::cout<<"float sum, int total" << std::endl;
    std::cout<<CalcMean(22.4, 2) <<std::endl;
    std::cout<<"Negative total" <<std::endl;
    std::cout<<CalcMean(-31.3, 5) <<std::endl;
    std::cout <<"Between 0.1 and 0" <<std::endl;
    std::cout <<CalcMean(1, 100) <<std::endl;
    std::cout<<"Betwen -0.1 and 0" <<std::endl;
    std::cout<<CalcMean(-1, 100);
    try
    {
        std::cout<<"Negative total" <<std::endl;
        std::cout<< CalcMean(25.6, -2) <<std::endl;
    }
    catch (const char* e)
    {
       std::cout<<(e) <<std::endl;
    }
    std::cout<<"end of testing" << std::endl <<std::endl;
}
void TestStdDevFlo()
{
    std::cout<<"entries: 10, 12, 23, 23, 16, 23, 21, 16. expected: ~5.2" <<std::endl;
    Vector<float> v;
    v.AddTo(10);
    v.AddTo(12);
    v.AddTo(23);
    v.AddTo(23);
    v.AddTo(16);
    v.AddTo(23);
    v.AddTo(21);
    v.AddTo(16);
    float s = CalcTotal(v);
    s = CalcMean(s, 8);
    std::cout<<CalcStdDev(v, s);
    std::cout<<"End of testing" << std::endl<<std::endl;
}
