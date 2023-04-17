#include<iostream>//Header File
#include<string>//Header File
#include<fstream>//Header File
#include<conio.h>//Header File
#include<cctype>//Header File
#include<windows.h>//Header File
#include"map.h"
using namespace std;
void CheckBookingRecord();//Function Prototype
ofstream MYFILE;
string NewWorkerName;
string NewWorkerPassword;
string AdminName="admin";
string AdminPassword="admin";

bool wrong = false;//initializing
int main()
{
//************************************************************************************
//*                             DiSpLaYiNg WeLcOmE ScReEn                                                 *
//************************************************************************************
      int count=0;
      system("color 1E");//Setting The Color Of Console
   cout<<endl;
   cout<<"\t******************************\n"; 
   cout<<"\t*             WelCome           *\n";
      cout<<"\t*             To              *\n"; 
      cout<<"\t*           Cabzy             *\n";
      cout<<"\t******************************\n";
   cout<<endl;
   cout<<endl;
   cout<<endl;
   cout<<"\tLoAdInG ";
   Sleep(100);//For Pause 
   cout<<"<"; 
   Sleep(100);//For Pause
   cout<<">"; 
   Sleep(100);//For Pause  
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"<"; 
   Sleep(100);//For Pause
   cout<<">"; 
   Sleep(100);//For Pause  
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"<"; 
      Sleep(100);//For Pause 
   cout<<">"; 
   Sleep(100);//For Pause
   cout<<"\n\n\t Successful\n";

   Sleep(2000);//For Pause
   system("CLS");//To Clear The Screen

//*********************************************************************************************************
//*                                      Login Menu                                                       *
//*********************************************************************************************************

   
    
 char Wish;
 string Choice;
do{
  
    system("CLS");
 cout<<"\t********************"<<endl;
 cout<<"\t      *Cabzy*"<<endl;
 cout<<"\t********************"<<endl;
 cout<<endl;
  
 cout<<"*************************"<<endl;
 cout<<"*<1>  For Login Admin   *"<<endl;
 cout<<"*************************"<<endl;
 cout<<endl;   
 cout<<"**************************"<<endl;
 cout<<"*<2> For Login Customer    *"<<endl;
 cout<<"**************************"<<endl;
 cout<<endl;
 cout<<"******************"<<endl;
 cout<<"*<3> For Exit    *"<<endl;
 cout<<"******************"<<endl;
 cout<<endl;
 cout<<"Select: ";
 cin>>Choice;

    int choice = atoi( Choice.c_str() );
 switch(choice)
 {
  case 1:
             {
            string UserName;//declaration
                  string Password;//declaration
                  bool LoginSuccess= false;
    
                  do
      {
//************************************************************************************
//*                           Admin Login                                            *
//************************************************************************************     
     system("CLS");
     cout<<"\t********************"<<endl;
                 cout<<"\t*  Admin Login     *"<<endl;
                 cout<<"\t********************"<<endl;
     cout<<endl;
     Sleep(500);//For Pause
     cout<<"Hint:- admin\n";
     cout<<"\nUserName: ";
     cin>>UserName;
     cout<<"Password: ";
     cin>>Password;
 
     if(UserName== AdminName && Password == AdminPassword)
     {
      cout<<"LOgin Successful \n";
      LoginSuccess= true;
      Sleep(2000);
      system("CLS");
      char Wish;
      do
      {
                             system("CLS");
        string Choice;//declaration
        cout<<"\t********************"<<endl;
                             cout<<"\t* AdministratiOn   *"<<endl;
                             cout<<"\t********************"<<endl;
                             cout<<endl;
        cout<<"<1> Customer Record"<<endl;
                             cout<<endl;
        cout<<"<2> Cab Driver Record"<<endl;
                             cout<<endl;
        cout<<"<3> Cab Status"<<endl;
                             cout<<endl;
        cout<<"<4> Canceled Booking Record"<<endl;
                             cout<<endl;
        cout<<"<5> Change The Rate Of Per Km Charges"<<endl;
                             cout<<endl;
        cout<<"<6> New Customer Account"<<endl;
        cout<<endl;
        cout<<"<7> To Log Out"<<endl;
        cout<<"Select :";
                             cin>>Choice;
        int choice = atoi( Choice.c_str() );
                             switch(choice)
                    {
                                 case 1:
                                 {
           
                                       break;
                                 }//end of case 1
                                 
                                 case 2:
                                 {
                                      
                                 }//end of case 2                              
                                 case 3:
                                 {
                                    break;  
                                 }
         case 4:
                                 {
                                      system("CLS");
                                      ifstream InFile;//creating Object to read from file
                                      char ch;//initiailzing
                                      InFile.open("CancelBooking.txt");//file open
                                      while (!InFile.eof())  
                                      {    
                                         InFile.get ( ch ) ;
                                         cout << ch ;  
                                      }
                                      InFile.close();//file close
                                      cout<<endl;
                                      break;
                                 }//end of case 4
                                 case 5:
                                      {
               
                                      }//end of case 4
                                 case 6:
          {
           system("CLS"); 
           cout<<"\t WELCOME"<<endl;
           cout<<endl;
           cout<<"Enter The New Customer User Name: ";
           cin>>NewWorkerName;
           cout<<endl;
           cout<<"Enter New Customer Password: ";
           cin>>NewWorkerPassword;
           cout<<endl;
           cout<<"The Account has Been created successfully\n";
           cout<<endl;
           cout<<"\tThank You"<<endl;

           break;
          }
         case 7:
                                 {
          system("CLS");
                                       cout<<"\tFor Logout\n";
            break;
                                 }//end of case 5   
                                 
                                 default:
                                 {
                                 cout<<"You Enter Wrong Choice"<<endl;
                                 break;
                                 }      
                    }//end of switch
     if(choice==7)
     {
      break;
     }
                      cout<<"Press any key to continue...... ";
       Wish=getch();
                      }while(Wish);
                  }
                  else
                  {
                       cout<<"Incorrect User Name And Password\n"
                           <<"Please Try Again";
        Sleep(1000);
                  }
               }while(!LoginSuccess);
               break;   
             }//end of case 1
             
             case 2:
                  {
                       string UserName="";
                       string Password="";
                       bool LoginSuccess= false;
                       do{
                       system("CLS");
        cout<<"\t********************"<<endl;
                    cout<<"\t*  Customer Login     *"<<endl;
                    cout<<"\t********************"<<endl;
        cout<<"\nHint:- worker\n";
        cout<<"UserName: ";
                       cin>>UserName;
                       cout<<"Password: ";
                       cin>>Password;
         
                       if(UserName== "worker" && Password == "worker" || UserName== NewWorkerName && Password == NewWorkerPassword )
                       {
                            cout<<"LOgin Successful \n";
                            LoginSuccess= true;
       Sleep(2000);
                            
                            system("CLS");
                            
//*********************************************************************************************************
//*                             DiSpLaYiNg MeNu On The ScReEn                                             *
//*********************************************************************************************************

 char Wish;
 string Choice;
    do{
           x:
    system("CLS");
 cout<<"\t********************"<<endl;
 cout<<"\t*    Customer        *"<<endl;
 cout<<"\t********************"<<endl;
 cout<<endl;
 cout<<endl;
    cout<<"<1> Booking"<<endl;
 cout<<endl;
 cout<<"<2> To LogOut         "<<endl;
    cout<<endl;
 
 cout<<"Select :";
 cin>>Choice;
    int choice = atoi( Choice.c_str() );
    switch(choice)
 {
                  case 1:
                       {
           
                  //*************************************************************************
                  //*                             Booking                                   *
                  //*************************************************************************
         
         do{
        
       system("CLS");
                  char Wish;
                  string Choice;
               cout<<"\t********************"<<endl;
               cout<<"\t*     Booking      *"<<endl;
               cout<<"\t********************"<<endl;
               cout<<endl;
               booking();
                  
    
       cout<<"Do you want to continue...... ";
       Wish=getch();
         }while(Wish);
                        
                          break;
                      }                        
                     case 2:
                         {
                             system("CLS");
                             cout<<"\tFor Logout\n";
                              break;
                         }
      default:
       {
        cout<<"You Enter Wrong Choice\n";
        break;
       }
    }//end of switch
                 if(choice==2)
     {
      break;
     }
 cout<<"Press any key to continue...... ";
    Wish=getch();
    }while(Wish);  
                       }         
                       else
                       {
                            cout<<"Incorrect User Name And Password\n"
                                <<"Please Try Again";
       Sleep(2000);
       
                       }
                       }while(!LoginSuccess);
                       break; 
                  }//end of case 2
                  
            case 3:
                 {
                          system("CLS");
                          ifstream InFile;//creating object to read from file
                 char ch;//initializing
                 InFile.open("Exit.txt");//file open
                 while (!InFile.eof())  
                 {    
                   InFile.get ( ch ) ;
                    cout << ch ;  
                    }
                    InFile.close();//file close
                 cout<<endl;
                 Sleep(2000);
        exit(0);
                 break;
                 }//end of case 3
                 
            default:
                    {
                        cout<<"You Enter Wrong Choice"<<endl;
      break;
                    }//end of default
    }//end of Switch

    cout<<"Press any key to continue...... ";
    Wish=getch();
    }while(Wish);
 
 
 return 0;
  
}
