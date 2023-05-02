#include <iostream>
#include "../Client/client.h"
#include "../Date/Date.h"
#include "../Time/Time.h"
#include "../Vector/Vector.h"
#include "../IoFuncts/IOFuncts.h"
#include "../Data/data.h"
#include "../dailyData/dailyData.h"
#include "../ProcData/ProcData.h"
#include "../ProcData/AirProcData.h"
#include "../ProcData/WindProcData.h"
#include "../ProcData/RadProcData.h"


using namespace std;

InputConfig inCon;

void FileTesting();

int main()
{
    FileTesting();
    return 0;
}


void FileTesting()
{
    ifstream File;
    std::cout<<"Testing the File" <<std::endl;
    std::cout<<"testing invalid file" <<std::endl;
    try
    {
        OpenFile(File, "noFile");
    }
    catch (const char* e)
    {
        std::cout<<e <<std::endl;
    }

    std::cout<<"Data is in other collumn, \nT moved to location 13 \nS to 6 \n- copied code from main program" <<std::endl;
    try
    {
        ProcData* PD;
        RadProcData* RPDP;
        WindProcData* WPDP;
        AirProcData* APDP;
        char c = '0';
        int n = 0;
        RawData myData;
        Vector<string> fileInput(numInputs);
        Vector<ProcData*> PDVect;
        ifstream FileIn;
        ofstream FileOut;

        SetInput(inCon.format); //put in config file later
        try
        {
            OpenFile(FileIn, "data_source.txt");
            FileOut.open("WindTempSolar.csv");
            string temp;
            getline(FileIn,temp);
            FileIn.close();
            OpenFile(FileIn, "Test.csv");
        }
        catch (const char* e)
        {
            std::cout<< e;
            return ;
        }
        FileIn >> fileInput;
        SetKey(inCon.format, fileInput, inCon.key);

        for(int i = 0; i < 18; i++)
        {
            std::cout<<inCon.format[i] << " Location " << inCon.key[i] <<std::endl;
        }
    }
        catch (const char* e)
        {
            std::cout<<e;
        }
}
