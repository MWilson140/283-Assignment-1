#ifndef WINDDATA_H_INCLUDED
#define WINDDATA_H_INCLUDED

#include "../Date/Date.h"
#include "../Time/Time.h"
#include "../Vector/Vector.h"

typedef struct
{
    Date d;
    Time t;
    float speed;
} WindRecType;

typedef Vector<WindRecType> WindLogType;

#endif // WINDDATA_H_INCLUDED
