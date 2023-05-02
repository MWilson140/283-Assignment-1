#ifndef AIRPROCDATA_H_INCLUDED
#define AIRPROCDATA_H_INCLUDED

#include "procdata.h"

class AirProcData : public ProcData
{
public:
    AirProcData();
    AirProcData(int n);
    AirProcData(int y, int m);
        /**
         * @brief method to get and store information
         */
    void GetData(RawData & MD);
    ~AirProcData();
};

#endif // AIRPROCDATA_H_INCLUDED
