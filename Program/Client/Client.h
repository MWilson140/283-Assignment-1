#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include "../Vector/Vector.h"
#include "../windData/winddata.h"
#include "../dailyData/dailyData.h"
#include "../ProcData/ProcData.h"
#include"../ProcData/WindProcData.h"
#include <string>
#include <iostream>
#include <fstream>



const int numInputs = 18; //number of input fields

    /**
     * @struct InputConfig
     * @brief stores the Key for input and desired input order
     */
typedef struct
{
     /**
     * @brief Sets the desired input format
     */
    void SetInput();
     /**
     * @brief Sets the key
     * @param Vector<string> - inputFormat, the order of data from the input file
     */
    void SetKey(Vector<std::string>inputFormat);
    Vector<std::string> format;
    int key[numInputs];
}InputConfig;
    /**
     * @brief Converts month string to its int value
     * @param string - month
     * @return int - the int value of the month
     * @pre Month must be valid
     * @post throws if month is not valid
     */
int MonthToInt(string month);

#endif // CLIENT_H_INCLUDED
