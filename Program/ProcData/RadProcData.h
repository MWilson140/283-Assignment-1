#ifndef RADPROCDATA_H_INCLUDED
#define RADPROCDATA_H_INCLUDED

#include "procData.h"

class RadProcData : public ProcData
{
public:
    RadProcData();
    RadProcData(int n);
    RadProcData(int y, int m);
        /**
         * @brief method to get and store information
         */
    void GetData(RawData & MD);
        /**
         * @brief method to convert radiation data
         * converts the 10 minute watts to kWatts per hour
         * @param n - float 10min watt value
         * @return float - kWatts per hour value
         */
    float calcRad(float n);
    ~RadProcData();
};



#endif // RADPROCDATA_H_INCLUDED
