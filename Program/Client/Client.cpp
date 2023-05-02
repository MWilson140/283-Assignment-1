#include "client.h"

void InputConfig::SetInput() //get from config file later on
{
    string Data[] = {"WAST", "T", "DP", "Dta", "Dts", "EV", "QFE", "QFF", "QNH", "RF", "RH", "S", "SR",
    "ST1", "ST2", "ST3", "ST4", "Sx"};
    for (int i = 0; i < numInputs; i++)
    {
        format.AddTo(Data[i]);
    }
}

void InputConfig::SetKey(Vector<std::string>inputFormat)
{
    for (int i = 0; i < numInputs; i ++)
    {
        for (int j = 0; j < numInputs; j++)
        {
            if (format[i].compare(inputFormat[j]) == 0)
            {
                key[i] = j;
            }
        }
    }
}

int MonthToInt(string month)
{
    string Months[] = {"January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"};

    for (int i = 0; i < 12; i++)
    {
        if (month == Months[i])
            return i+1;
    }
    throw "Month not found";
}


