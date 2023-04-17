#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include <ctime>
#include <cstdlib>
using namespace std;


string cabyt;
string NameArray[10] = { "Elina", "Robert", "Emao", "Rubina", "Bruse", "Dannie", "Alexa", "Lui", "Bella", "Stewart" };
string platearray[10]={ "AP 02 BK 1084" ,"AP21BP7331","UP 19 D 0343", "KA 08 J 9192","MH 12 RN 1289","199 CC 999","03D 153874H","HR 26 TC 7174","HR 26 TC 7174","199 CD 1"};
string model[8]={"Maruti Swift","Hyundai I10","Toyota Innova","Mahindra Xuv500","Renault Kwid","Hyundai I20","Swift","Inova"};


int getrandomdigit()
{
    return rand() % 10;
}

long long int callnumber()
{
    srand(time(NULL));

    int res=10;
    long long int num=910;
    for(int i=1;i<=7;i++)
    {

      num+= getrandomdigit();
      num=num*res;

    }
    return num;

}

int info()
{
    int choice,i,exit=0;
    string fname,cabtype;
    ofstream fileo;
    ifstream filei;

    while(exit==0)
    {
        cout<<"Want to choose Cab type (press 1) else press any key to exit"<<endl;
        cin>>choice;
        if(choice==1)
        {
            cout<<"Enter your CabType:";
            cin>>cabyt;

            fname="availableCab\\"+cabyt+".txt";
            filei.open(fname.c_str());
            if(!filei.is_open() && filei.fail())
            {
                cout<<"This cab is not available in our service"<<endl;
                filei.close();
                continue;
            }
            getline(filei,cabtype);

            if(cabtype==cabyt)
            {
                srand(time(NULL));
                cout<<cabtype<<" is available"<<endl;
                string Random; long long int number; string plateNum, type; int cpk;
             Random = NameArray[rand()%10];
            number=callnumber();
            plateNum= platearray[rand() % 10];
             type=model[rand() % 10];
            cpk=(getrandomdigit()+1)*10+getrandomdigit();
            fileo.open(fname.c_str());
            fileo<<cabtype<<endl<<Random<<endl<<number<<endl<<plateNum<<endl<<type<<endl<<cpk<<endl;
            cout<<"Given below your cab details"<<endl;
                cout<<"Cabtype: "<<cabtype<<endl;
                cout<<"Driver Name: "<<Random<<endl;
                cout<<"Driver Number: "<<number<<endl;
                cout<<"Plate Number: "<<plateNum<<endl;
                cout<<"Model Type: "<<type<<endl;
                cout<<"Cost Per Km: "<<cpk<<endl;

                filei.close();
                fileo.close();
            }
            else{
                cout<<"Ops! Their may be a mistake try again"<<endl;
                continue;
            }

        }

        else
        {
            exit=1;
        }
    }

}
