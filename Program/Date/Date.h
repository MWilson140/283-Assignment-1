#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

using namespace std;

    /**
     * @class Date
     * @brief Class for storing date variables
     * class used for storing and updating date variables
     * has checking to make sure only valid dates are stores
     * @bug day max is 31 when no month is set, once day is set, month cannot be set if the day is less than the max for that month
     */


class Date
{
public:
    Date();
    Date(int d, int m, int y);
    Date (const Date & d);

        /**
         * @brief Assignment opperator
         */
    Date & operator = (Date & d)
    {
        this->Day = d.Day;
        this->Month = d.Month;
        this->Year = d.Year;
        return *this;
    }
    virtual ~Date();
        /**
         * @brief
         * @param n - int for Day
         */
    void SetDay(int n);
        /**
         * @brief Getter for day
         * @return int - amount for day
         */
    int GetDay() const;
        /**
         * @brief
         * @param m - int for Month
         */
    void SetMonth(int m);
        /**
         * @brief Getter for month
         * @return string - text for the month
         */
    int GetMonth() const;
        /**
        *@brief
        *@param n - int for Year
        */
    void SetYear(int n);
        /**
         * @brief Getter for year
         * @return int - amount for year
         */
    int GetYear() const;

private:
    int Day;
    int Year;
    int Month;
        /**
         * @brief Checks if the year is a leap year
         * @param int - year
         * @return vool - true if yes, false if no
         */
    bool LeapYear(int n);
        /**
         * @brief Checks the day input
         * @param int - day
         * @return void
         */
    void DayCheck(int n);
        /**
         * @brief Checks the month input
         * @param int - month
         * @return void
         */
    void MonthCheck(int n);
        /**
        *@brief Checks the year input
        *@param int - year
        @return void
        */
    void YearCheck(int n);
};
#endif // DATE_H_INCLUDED
