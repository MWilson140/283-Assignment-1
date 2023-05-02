#ifndef IOFUNCTS_H_INCLUDED
#define IOFUNCTS_H_INCLUDED

#include "../WindData/WindData.h"
#include "../Time/Time.h"
#include "../Date/Date.h"
#include "../Vector/vector.h"
#include "../Client/client.h"
#include "../dailyData/dailyData.h"
#include "../ProcData/AirProcData.h"
#include "../ProcData/ProcData.h"
#include "../ProcData/RadProcData.h"
#include "../ProcData/WindProcData.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <string>

    /**
     * @brief Method to get the format from the file
     */
std::istream & operator >> (std::istream & input, Vector<string> & IF);
    /**
     * @brief Method to read the file into the vector
     */
std::istream & operator >> (std::istream & input, RawData & WD);

    /**
     * @brief Method to store into RawData vector from a string vector
     */
Vector<std::string> & operator >> (Vector<std::string> & inData, RawData & WD);
    /**
     * @brief Method to store into RawData vector from a string vector
     */
stringstream & operator >> (stringstream & sstr, Date & d);
    /**
     * @brief Method to store into RawData vector from a string vector
     */
stringstream & operator >> (stringstream & sstr, Time & t);
    /**
     * @brief Method to store into RawData vector from a string vector
     */
std::ostream & operator << (std::ostream & output, Vector<ProcData*> data);
    /**
     * @brief Method to store into RawData vector from a string vector
     */
std::ostream & operator << (std::ostream & output, ProcData* WD);
    /**
     * @brief Method to store into RawData vector from a string vector
     */
std::ostream & operator << (std::ostream & output, WindProcData* Data);
    /**
     * @brief Method to store into RawData vector from a string vector
     */
std::ostream & operator << (std::ostream & output, RadProcData* Data);
    /**
     * @brief Method to store into RawData vector from a string vector
     */
std::ostream & operator << (std::ostream & output, AirProcData* Data);

    /**
     * @brief Gets a month from the user
     * @return int
     * @post Must be a valid full name of the month
     */
int UserMonth();
    /**
      * @brief Gets a year from the user
      * @return int
      */
int UserYear();
    /**
     * @brief Displays the menu
     */
void menu();


#endif // IOFUNCTS_H_INCLUDED
