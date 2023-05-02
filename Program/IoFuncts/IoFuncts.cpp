#include "IOFuncts.h"
extern InputConfig inCon;

std::istream & operator >> (std::istream & input, Vector<string> & IF) //only for first lines
{
    std::string temp;
    getline(input, temp);
    stringstream sstr(temp);
    while (getline(sstr,temp,',')) //no .good? doesnt matter
    {
        IF.AddTo(temp);
    }
    return input;
}

Vector<std::string> & operator >> (Vector<std::string> & inData, RawData & WD)
{
    AllData Temp;
    Date TDate;
    Time TTime;
    try
    {
        Temp.SetSpeed(stof(inData[inCon.key[11]]));
    }
    catch (std::invalid_argument)
    {
        std::cout<<"invalid data entry ";
        std::cout<<inData[inCon.key[11]] <<std::endl;
        Temp.SetSpeed(-100.0);
    }
    stringstream sstr(inData[inCon.key[0]]);
    try
    {
        Temp.SetAirTemp(stof(inData[inCon.key[1]]));
    }
    catch (std::invalid_argument)
    {
        Temp.SetAirTemp(-100.0);
    }
    try
    {
        Temp.SetSolarRad(stof(inData[inCon.key[12]]));
    }
    catch (std::invalid_argument)
    {
        Temp.SetSolarRad(-100.0);
    }
    sstr >> TDate;
    sstr >> TTime;
    Temp.SetTime(TTime);
    Temp.SetDate(TDate);
    WD.AddTo(Temp);
    return inData;
}

stringstream & operator >> (stringstream & sstr, Date & d)
{
    string sTemp;
    stringstream ssTemp;

    getline(sstr, sTemp, ' ');
    ssTemp.str(sTemp);
    getline(ssTemp,sTemp, '/');
    d.SetDay(stoul(sTemp));
    getline(ssTemp,sTemp, '/');
    d.SetMonth(stoul(sTemp));
    getline(ssTemp,sTemp);
    d.SetYear(stoul(sTemp));
    return sstr;
}

stringstream & operator >> (stringstream & sstr, Time & t)
{
    string sTemp;
    getline(sstr,sTemp,':');
    t.SetHour(stoul(sTemp));
    getline(sstr,sTemp);
    t.SetMinute(stoul(sTemp));
    return sstr;
}

std::istream & operator >> (std::istream & input, RawData & WD)
{
    Vector<string> fileInput;
    string temp;
    stringstream sstr;

    while (getline(input, temp).good())
    {
        fileInput.Empty();
        fileInput.SetSize(numInputs);
        sstr.clear();
        sstr.str(temp);
        while (getline(sstr,temp,','))
        {
            fileInput.AddTo(temp);
        }
        fileInput >> WD;
    }
     return input;
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

std::ostream & operator << (std::ostream & output, Vector<ProcData*> Data)
{
    string Months[] = {"January1", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"};

    output<<Data[0]->year << std::endl;
    if (Data[0]->start == Data[0]-> end)
    {
        output<<"No Data" << std::endl;
        return output;
    }

    for(int i = 0;i < Data[0]->months.GetLength(); i++ )
    {
        output<<Months[i+Data[0]->month-1] << ",";

        for (int j = 0; j < Data.GetLength(); j ++)
        {
            output << Data[j]->mean[i] << "(" << Data[j]->stdDev[i] << "),";
            if (j == 1)
            {
                j++;
                output<<Data[j]->mean[i] << std::endl;
            }
        }
    }
    return output;
}

std::ostream & operator << (std::ostream & output, AirProcData* Data)
{
    int n = 0;
    string Months[] = {"January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"};
    std::cout<<"Year: " << Data->year <<std::endl;

    if (Data->month == 0)
    {
        std::cout<<"No data found" << std::endl;
        return output;
    }

    for (int i = 1; i < Data->month; i++)
    {
        std::cout<<Months[i-1] << ": No Data" << std::endl;
    }
    for (n = 0; n < Data->months.GetLength(); n++)
    {
         std::cout<< Months[Data->month+n-1] << " " << Data->mean[n] << " C, standard deviation: " << Data->stdDev[n] << std::endl;
    }

    for (n += Data->months.GetLength(); n < 13; n++)
    {
        std::cout<<Months[n-1] << ": No Data" <<std::endl;
    }
    std::cout<<std::endl;
    return output;
}

std::ostream & operator << (std::ostream & output, WindProcData* Data)
{
    string Months[] = {"January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"};
    std::cout<< Data->year << " " << Months[Data->month-1] <<std::endl;

    if (Data->start == Data->end)
    {
        std::cout<<"no data found" <<std::endl;
        return output;
    }
    std::cout<<"Average speed: " << Data->mean[0] <<std::endl;
    std::cout<<"standard deviation: " << Data->stdDev[0] <<std::endl;
    std::cout<<std::endl;
    return output;
}

std::ostream & operator << (std::ostream & output, RadProcData* Data)
{
    int n = 0;
    char c = 253;
    string Months[] = {"January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"};
    std::cout<<"Year: " << Data->year <<std::endl;

    if (Data->month == 0)
    {
        std::cout<<"No data found" <<std::endl;
        return output;
    }

    for (int i = 1; i < Data->month; i++)
    {
        std::cout<<Months[i-1] << ": No Data" << std::endl;
    }
    for (n = 0; n < Data->months.GetLength(); n++)
    {
        std::cout<< Months[Data->month+n-1] << " " << Data->mean[n] << "kwh/m" << c << std::endl;
    }

    for (n += Data->months.GetLength(); n < 13; n++)
    {
        std::cout<<Months[n-1] << ": No Data" <<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    return output;
}

int UserMonth()
{
    fflush(stdin);
    std::string temp;
    int month;
    std::cout<<"Enter the Month: ";
    std::cin>>temp;
    try
    {
        month = MonthToInt(temp);
        return month;
    }
    catch (const char* c)
    {
        throw c;
    }
}

int UserYear()
{
    fflush(stdin);
    string temp;
    int year = 0;
    std::cout<<"Enter the year: ";
    std::cin>>temp;
    try
    {
       year = stoi(temp);
    }
    catch (std::invalid_argument)
    {
        throw "Non valid input";
    }
    return year;
}

void menu()
{
    std::cout<<"1) Average Wind Speed." <<std::endl
    << "2) Average Ambient Air Temperature." <<std::endl
    <<"3) Total Solar Radiation." << std::endl
    <<"4) All." << std::endl
    <<"5) Exit" << std::endl;
}



