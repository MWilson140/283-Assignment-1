#include <iostream>
#include <string>

#include "../Time.h"

using namespace std;

void Constructor();
void AssignEqual();
void OOB();

ostream & operator << (ostream & output, Time t);


int main()
{
    Constructor();
    AssignEqual();
    OOB();
    return 0;
}

void Constructor()
{
    std::cout<<"Testing constructors" <<std::endl;
    std::cout<<"Default and setters"<<std::endl;
    Time t;
    t.SetHour(12);
    t.SetMinute(14);
    t.SetSecond(55);
    std::cout<<t;
    std::cout<<"param constructor"  << std::endl;
    Time t1 (12,53,21);
    std::cout<<t1;
     std::cout << "done testing" << std::endl<<std::endl;
}
void AssignEqual()
{
    std::cout<<"Testing Assignment opperator" << std::endl;
    Time t(12,22,20);
    Time t1;
    t1 =t;
    std::cout<<t;
    std::cout<<t1;
    std::cout<<"Testing copy constructor" << std::endl;
    Time t3(t);
    std::cout<<t3;
    std::cout << "done testing" << std::endl<<std::endl;
}
void OOB()
{
    std::cout<<"Testing out of bounds" << std::endl;
    std::cout<<"Constructor, second, minute, hour too high" << std::endl;
    try
    {
        Time t(60, 1, 1);
        std::cout<<t;
    }
    catch(const char* e)
    {
        std::cout<<e << std::endl;
    }
        try
    {
        Time t(1, 60, 1);
        std::cout<<t;
    }
    catch(const char* e)
    {
        std::cout<<e << std::endl;
    }

        try
    {
        Time t(1, 4, 24);
        std::cout<<t;
    }
    catch(const char* e)
    {
        std::cout<<e << std::endl;
    }

     std::cout<<"Constructor, second, minute, hour Zeros" << std::endl;
         try
    {
        Time t(0, 1, 1);
        std::cout<<t;
    }
    catch(const char* e)
    {
        std::cout<<e << std::endl;
    }
        try
    {
        Time t(1, 0, 1);
        std::cout<<t;
    }
    catch(const char* e)
    {
        std::cout<<e << std::endl;
    }

        try
    {
        Time t(1, 1, 0);
        std::cout<<t;
    }
    catch(const char* e)
    {
        std::cout<<e << std::endl;
    }
     std::cout<<"Constructor, second, minute, hour too low" << std::endl;
         try
    {
        Time t(-1, 1, 1);
        std::cout<<t;
    }
    catch(const char* e)
    {
        std::cout<<e << std::endl;
    }
        try
    {
        Time t(1, -1, 1);
        std::cout<<t;
    }
    catch(const char* e)
    {
        std::cout<<e << std::endl;
    }

        try
    {
        Time t(1, 1, -1);
        std::cout<<t;
    }
    catch(const char* e)
    {
        std::cout<<e << std::endl;
    }


     std::cout<<"Constructor, second, minute, Highest" << std::endl;
         try
    {
        Time t(59, 1, 1);
        std::cout<<t;
    }
    catch(const char* e)
    {
        std::cout<<e << std::endl;
    }
        try
    {
        Time t(1, 59, 1);
        std::cout<<t;
    }
    catch(const char* e)
    {
        std::cout<<e << std::endl;
    }
std::cout << "done testing" << std::endl<<std::endl;
        try
    {
        Time t(1, 1, 23);
        std::cout<<t;
    }
    catch(const char* e)
    {
        std::cout<<e << std::endl;
    }
    std::cout << "done testing" << std::endl<<std::endl;
}

ostream & operator << (ostream & output, Time t)
{
    std::cout<<"Hour: " << t.GetHour() << " Minute : " <<t.GetMinute() << " Second : " <<t.GetSecond() << std::endl;
    return output;
}

