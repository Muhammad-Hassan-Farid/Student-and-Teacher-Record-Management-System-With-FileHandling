#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include "admin.h"
using namespace std;


  void AdminClass::login() 
  {
      cout<<"\t\t\tLogin";
      x:
      cout<<"\n\n\tEnter The Username: \t";
      cin>>username;
      cout<<"\n\n\tEnter the Password: \t";
	  
      cin>>pass;
      if (username == "admin" && pass == "123")
        {
            cout<<"\t\tYou are login Sucessfull."<<endl<<endl;
            
        }
        else if (username != "admin" && pass == "123")
        {
            cout << "\t\tYour username is wrong. ..... Try again."<<endl<<endl;
            goto x;
        }
        else if(username=="admin" && pass!="123")
        {
          cout<<"Your password is wrong ..... Try again."<<endl<<endl;
          goto x;
        }
        else
        {
         cout<<"Your username and password are wrong ..... Try again."<<endl<<endl; 
         goto x;
          
        }
  }
