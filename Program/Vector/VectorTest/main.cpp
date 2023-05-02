#include <iostream>
#include <string>
#include "../../Vector/Vector.h"
#include "../../Date/Date.h"
#include "../../Time/Time.h"

#include "funct.h"

void VectorOOB();
void VectorConst();
void VectorSize();
void VectorPoint();


int main()
{
    VectorConst();
    VectorSize();
    VectorPoint();
    Vector<int> IVect;
    Vector<Date> DVect;
    Vector<Time> TVect;

    testIntVect(IVect);
    testDateVect(DVect);
    testTimeVect(TVect);

    std::cout<<"Int Vector print" <<endl;
    std::cout<<IVect;
    std::cout<<"Date Vector print" << endl;
    std::cout<<DVect;
    std::cout<<"Time Vector print" << endl;
    std::cout<<TVect;

    try
    {
        VectorOOB();
    }
    catch (const char* e)
    {
        std::cout<<"Caught: ";
        std::cout<<e;
    }
    return 0;
}


void VectorOOB()
{
    Vector<int> Vect;
    Vect.AddTo(4);
    Vect.AddTo(5);
     try
    {
        std::cout<<"Negative" <<std::endl;
        std::cout<<Vect[-1];
    }
    catch (const char* e)
    {
        std::cout<<e;
    }
    std::cout<<"testing vector out of bounds" <<endl;

    std::cout<<"length: " << Vect.GetLength() <<std::endl;
    std::cout<< "Vector[1] = " << Vect[1] <<std::endl;
    std::cout<<"Vector[2] = ";

    std::cout<<Vect[2];
}

void VectorConst()
{
    std::cout<<"testing default (int)" <<std::endl;
    Vector<int> Vect;
    std::cout << "default constructor" <<std::endl;
    std::cout<< "Length: " << Vect.GetLength() << " Size: " << Vect.GetSize() <<std::endl;;
    Vector<int>Vect1(10);
    std::cout<<"Size constructor, 10" <<std::endl;
    std::cout<< "Length: " << Vect1.GetLength() << " Size: " << Vect1.GetSize() <<std::endl;
    Vect.AddTo(10);
    Vect.AddTo(54);
    std::cout<<"= operator, 10 and 54" <<std::endl;
    std::cout<<Vect;
    Vect1= Vect;
    std::cout<< "copied" <<std::endl << Vect1;

    Vector<int> Vect2(Vect);
    std::cout<<"copy constructor" <<std::endl;
    std::cout<<Vect2;
    std::cout<<"0 int construtor" <<std::endl;
    try
    {
        Vector<int>Vect3(0);
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }
    std::cout<<std::endl;


}

void VectorSize()
{
    Vector<int> Vect;
    std::cout<<"Current size: "  << Vect.GetSize() <<" Current length: " << Vect.GetLength() <<std::endl;
    std::cout<<"Set size 20" <<std::endl;
    Vect.SetSize(20);
    std::cout<<"current size: " << Vect.GetSize() << " Current Length: " <<Vect.GetLength() << std::endl;
    std::cout<<"Set lower than current length"<<std::endl;
    Vect.AddTo(1);
    Vect.AddTo(2);
    Vect.AddTo(3);
    std::cout<<"Current length: " << Vect.GetLength() <<std::endl;
    try
    {
        Vect.SetSize(1);
        std::cout<<Vect;
    }
    catch (const char* e)
    {
        std::cout<<e<<std::endl;
    }


    std::cout<<std::endl;
}

void VectorPoint()
{
    std::cout<<"Pointer" <<std::endl;
    Vector<int*> VectP;
    int a = 10;
    int b = 20;
    VectP.AddTo(&a);
    VectP.AddTo(&b);
    Vector<int*> VectP1(VectP);
    std::cout<<"Added pointers to a(10) and b(20)" << std::endl;
    std::cout<<"copy constructored to new vector" <<std::endl;

    for (int i = 0; i < VectP.GetLength(); i++)
    {
        std::cout<<i << " " <<std::endl;
        std::cout<< *VectP[i] <<std::endl;
        std::cout << *VectP1[i] <<std::endl <<std::endl;
    }
    std::cout<<"a = 15"<< std::endl;
    a = 15;

    for (int i = 0; i < VectP.GetLength(); i++)
    {
        std::cout<<i << " " <<std::endl;
        std::cout<< *VectP[i] <<std::endl;
        std::cout << *VectP1[i] <<std::endl <<std::endl;
    }
}


