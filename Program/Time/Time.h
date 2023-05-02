#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED

    /**
     * @class Time
     * @brief Class for storing time values
    */
class Time
{
public:
    Time();
    Time (int s, int m, int h);
    Time(const Time & T);
    ~Time();

        /**
         * @brief Assignment Operator
         */
    Time & operator = (Time & t)
    {
        this->second = t.second;
        this->minute = t.minute;
        this->hour = t.hour;
        return *this;
    }
        /**
         * @brief Second setter
         * @param int - seconds
         * @return void
         */
    void SetSecond(int n);
        /**
         * @brief Seconds getter
         * @return int second value
         * @pre must be inclusive between 0 and 59
         */
    int GetSecond() const;
        /**
         * @brief Minute setter
         * @param int - seconds
         * @return void
         */
    void SetMinute(int n);
        /**
         * @brief Minute getter
         * @param int - seconds
         * @return void
         * @pre must be inclusive between 0 and 59
         */
    int GetMinute() const;
        /**
         * @brief hour setter
         * @param int - seconds
         * @return void
         */
    void SetHour(int n);
        /**
         * @brief hour setter
         * @return int
         * @pre must be inclusive between 0 and 23
         */
    int GetHour() const;

private:
    int second;
    int minute;
    int hour;

        /**
         * @brief Checks the seconds input
         * @param int - seconds
         * @return void
         */
    void CheckSecond(int n);
        /**
         * @brief Checks the minute input
         * @param int - minutes
         * @return void
         */
    void CheckMinute(int n);
        /**
         * @brief Checks the Hours
         * @param int - hours
         * @return void
         */
    void CheckHour(int n);
};

#endif // TIME_H_INCLUDED
