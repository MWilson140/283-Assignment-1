#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <cmath>
#include "../Vector/Vector.h"


    /**
     * @brief Methods for calculations
     */

using namespace std;

    /**
     * @brief Calc the total of all values
     * @param Vector of t
     * @return total sum
     */
template <class T>
T CalcTotal(Vector<T> & data)
{
    T sum = 0;
    for(int i =0; i < data.GetLength(); i++)
    {
        sum += data[i];
    }
    return sum;
}
    /**
     * @brief Calculates the mean of the values
     * @param T - sum of all values. int - total, amount of values.
     * @return float - the mean of the values
     */
template <class T>
float CalcMean(T sum, int total)
{
    if (total < 1)
        throw ("Entries is too low");
    sum = sum/total;
    if (sum < 0.1 && sum > -0.1)
        sum = 0;

    return sum;
}
    /**
     * @brief calculates the standard deviation of the values
     * @param Vector of type T, float - mean
     * @return float - the standard deviation
     * @post if the value is less than 0.1 returns 0
     */
template <class T>
float CalcStdDev(Vector<T> & All, float Mean)
{
    float sum = 0;
    for (int i =0; i < All.GetLength(); i++)
    {
        sum+= ((All[i] - Mean) * (All[i] - Mean));
    }
    sum = sum / (All.GetLength() -1);
    sum = sqrt(sum);
    if (sum < 0.1 )
        sum = 0;

    return sum;
}

#endif // DATA_H_INCLUDED
