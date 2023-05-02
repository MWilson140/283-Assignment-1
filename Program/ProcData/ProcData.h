#ifndef PROCDATA_H_INCLUDED
#define PROCDATA_H_INCLUDED

#include "../Vector/Vector.h"
#include "../dailyData/dailyData.h"
#include "../Data/Data.h"

    /**
     * @class ProcData
     * @brief abstract class for proccessing data and storing it
     */

class ProcData
{
public:
    ProcData(){}
    ProcData(int n);
    ProcData(int y, int m);
    Vector<Vector<float> > months;
    Vector<float> stdDev;
    Vector<float> mean;
    int year;
    int month;
    int start;
    int end;

    virtual void GetData(RawData & MD) = 0;
        /**
         * @brief Finds the start of desired data
         * Takes the user input month and year and finds the start of the data
         */
    void FindStart(const RawData & MD);
        /**
         * @brief Finds the end of desired data
         * Takes the user input month and year and finds the ebd of the data
         */
    void FindEnd(const RawData & MD);
    virtual ~ProcData(){}
};




#endif // PROCDATA_H_INCLUDED
