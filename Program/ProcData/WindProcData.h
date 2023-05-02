#ifndef WINDPROCDATA_H_INCLUDED
#define WINDPROCDATA_H_INCLUDED

#include "procdata.h"

    /**
     * @class WindProcData
     * @brief Concrete class for wind data
     */

class WindProcData : public ProcData
{
public:
    WindProcData();
    WindProcData(int y, int m);
        /**
         * @brief method to get and store information
         */
    void GetData(RawData & MD);
    ~WindProcData();
};

#endif // WINDPROCDATA_H_INCLUDED
