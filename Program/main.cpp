#include <iostream>
#include <fstream>
#include <string>

//add const []?
//added dataewef
//awdawedf
efwsef
ewfwsef
ngdfbfd

#include "Client/client.h"
#include "Date/Date.h"
#include "Time/Time.h"
#include "Vector/Vector.h"
#include "IoFuncts/IOFuncts.h"
#include "Data/data.h"
#include "dailyData/dailyData.h"
#include "ProcData/ProcData.h"
#include "ProcData/AirProcData.h"
#include "ProcData/WindProcData.h"
#include "ProcData/RadProcData.h"

InputConfig inCon;

using namespace std;
int main()
{
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

        inCon.SetInput();
        FileIn.open("data_source.txt");
        FileOut.open("WindTempSolar.csv");
        if (!FileIn || !FileOut)
        {
            std::cout<<"File did not open";
            return -1;
        }

        string temp;
        getline(FileIn,temp);
        FileIn.close();
        FileIn.open(temp);
        if (!FileIn)
        {
            std::cout<<"file did not open";
            return -1;
        }
        FileIn >> fileInput;
        inCon.SetKey(fileInput);
        FileIn >> myData;
        while (c !='5')
        {
            try
            {
                fflush(stdin);
                menu();
                c = getchar();
                switch (c)
                {
                case '1':
                    n = UserYear();
                    PD = new WindProcData(n, UserMonth());
                    PDVect.AddTo(PD);
                    break;
                case '2':
                    PD = new AirProcData(UserYear(), 0);
                    PDVect.AddTo(PD);
                    break;
                case '3':
                    PD = new RadProcData(UserYear(), 0);
                    PDVect.AddTo(PD);
                    break;
                case '4':
                    n = UserYear();
                    PD = new WindProcData(n, 0);
                    PDVect.AddTo(PD);
                    PD = new AirProcData(n, 0);
                    PDVect.AddTo(PD);
                    PD = new RadProcData(n, 0);
                    PDVect.AddTo(PD);
                    break;
                case '5':
                    std::cout<<"ending program";
                    return 1;
                    break;
                default:
                    std::cout<<"Invalid Menu input"<<endl;
                    continue;
                }
                for(int i = 0; i < PDVect.GetLength(); i++)
                {
                    PDVect[i]->FindStart(myData);
                    PDVect[i]->FindEnd(myData);
                    PDVect[i]->GetData(myData);
                    if (PDVect[i]->month == 0 && PDVect[i]->start != PDVect[i]->end)
                    {
                        PDVect[i]->month = myData[PDVect[i]->start].GetDate().GetMonth();
                    }
                }
                if (PDVect.GetLength()==1)
                {
                    RPDP = dynamic_cast<RadProcData*>(PDVect[0]);
                    if (RPDP)
                        std::cout<<RPDP;
                    APDP = dynamic_cast<AirProcData*> (PDVect[0]);
                        if (APDP)
                            std::cout<<APDP;
                    WPDP = dynamic_cast<WindProcData*> (PDVect[0]);
                    if (WPDP)
                        std::cout<<WPDP;
                }
                else
                    FileOut << PDVect;

                for (int i = 0; i < PDVect.GetLength(); i++)
                {
                    delete (PDVect[i]);
                }
                PDVect.Empty();
            }
            catch (const char* e)
            {
                std::cout<<e <<std::endl;
            }
        }
        FileOut.close();
    }
    catch (const char* e)
    {
        std::cout<<e;
    }
    return 0;
}
