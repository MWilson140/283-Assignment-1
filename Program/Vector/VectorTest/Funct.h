#ifndef FUNCT_H_INCLUDED
#define FUNCT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include "../../Vector/Vector.h"
#include "../../Date/Date.h"
#include "../../Time/Time.h"

void testIntVect(Vector<int> & InVect);
void testDateVect(Vector<Date> & DVect);
void testTimeVect(Vector<Time> & TVect);

template <class T>
std::ostream & operator << (std::ostream & out, Vector<T> &  Vect)
{
    for (int i = 0; i < Vect.GetLength();i++)
    {
        std::cout<<i << " ";
        std::cout<<Vect[i] <<std::endl;
    }
    std::cout<<"end of vector test"<<std::endl;
    return out;
}

std::ostream & operator << (std::ostream & ouput, Date & d);
std::ostream & operator << (std::ostream & ouput, Time & t);

#endif // FUNCT_H_INCLUDED
