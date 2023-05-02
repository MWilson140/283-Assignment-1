#include "funct.h"

void testIntVect(Vector<int> & InVect)
{
    std::string temp;
    std::ifstream In ("IntIn.csv");
    while (getline(In, temp).good())
    {
        std::stringstream sstr (temp);
        while  (getline(sstr, temp,','))
        {
            InVect.AddTo(stoi(temp));
        }
    }
}
//checking with old values in temp, is fine since this wont be a problem in main program?;
void testDateVect(Vector<Date> & DVect)
{
    std::string temp;
    std::stringstream sstr;
    std::ifstream In ("DateIn.csv");

    while (getline(In, temp).good())
    {
        Date DTemp;
        sstr.clear();
        sstr.str(temp);
        getline(sstr,temp,',');
        DTemp.SetDay (stoi(temp));
        getline(sstr, temp,',');
        DTemp.SetMonth(stoi(temp));
        getline(sstr, temp,',');
        DTemp.SetYear(stoi(temp));
        DVect.AddTo(DTemp);
    }
}

void testTimeVect(Vector<Time> & TVect)
{
    std::string temp;
    std::stringstream sstr;
    std::ifstream In ("TimeIn.csv");
    while (getline(In, temp).good())
    {
        Time TTemp;
        sstr.clear();
        sstr.str(temp);
        getline(sstr,temp,',');
        TTemp.SetMinute(stoi(temp));
        getline(sstr,temp,',');
        TTemp.SetHour(stoi(temp));
        TVect.AddTo(TTemp);
    }
}
std::ostream & operator << (std::ostream & output, Date & d)
{
    output<<"Day: " <<d.GetDay() <<
    " Month: " << d.GetMonth() <<
    " Year: " << d.GetYear() << std::endl;
    return output;
}
std::ostream & operator << (std::ostream & output, Time & t)
{
    output << "Time: " << t.GetHour() <<":"<< t.GetMinute() << std::endl;
    return output;
}




