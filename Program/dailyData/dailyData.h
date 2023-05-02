#ifndef DAILYDATA_H_INCLUDED
#define DAILYDATA_H_INCLUDED

#include "../Time/Time.h"
#include "../Date/Date.h"
#include "../Vector/vector.h"

    /**
     * @struct AllData
     * @brief struct to store data
     * struct to store all the raw data read in from file. Contains only setters and getters
     */

typedef struct
{
    void SetSpeed(float n);
    float GetSpeed() const;
    void SetAirTemp(float n);
    float GetAirTemp() const;
    void SetSolarRad(float n);
    float GetSolarRad() const;
    void SetDate(Date d);
    Date GetDate() const;
    void SetTime(Time t);
    Time GetTime() const;
private:
    Date date;
    Time time;
    float speed;
    float ambientAirTemp;
    float solarRadiation;
} AllData;

typedef Vector<AllData> RawData;

#endif // DAILYDATA_H_INCLUDED
