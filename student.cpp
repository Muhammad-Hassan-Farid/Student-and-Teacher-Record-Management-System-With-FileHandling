#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include"admin.h"
#include"student.h"
#include<windows.h>

using namespace std;

void studentClass::record()
{
	system("Color E4");
	cout<<"\n\n\n\t\t\t\tRecord";
	cout<<"\n\n 1. Insert Record";
	cout<<"\n 2. Display Record";
	cout<<"\n 3. Search Record";
	cout<<"\n 4. Update Record";
	cout<<"\n 5. Delete Record";
	cout<<"\n 6  Goto Main";
	cout<<"\n 7. Exit";
	cout<<"\n\n Enter Your Choice : ";
}
void studentClass::s_insert(fstream& StudentDetails) //student insert fuction
{
	system("cls");
	system("Color E4");
	StudentDetails.open("StudentDetails.txt", ios::app| ios::out );
	cout<<"\n\n\t\t\t\tInsert Record\n\n"<<endl;
    cin.ignore();

    cout<<"\n\nName : ";
	getline(cin,name);
	
	cout<<" \n\nRoll No. : ";
	getline(cin,roll); 
	
	cout<<"\n\n Class : ";
	getline(cin,clas); 
	
	
	cout<<"\n\nAddress : ";
	getline(cin,address);

	StudentDetails<<" "<<name<<" "<<roll<<" "<<clas<<" "<<address<<"\n";
	StudentDetails.close();		

}

void studentClass::s_display(fstream& StudentDetails) //student display fuction
{
	system("cls");
	system("Color E4");
	int co=0;
	StudentDetails.open("StudentDetails.txt", ios::in| ios::out);

	if(!StudentDetails)
	{
		cout<<"No Data is Available.";
		StudentDetails.close();
	}
	else
	{
	StudentDetails >> name >> roll >> clas >> address ;
	while (!StudentDetails.eof())
	{
	    cout<<"\n\t\t\t  Display Student Detail"; 
		cout<<endl<<endl;
		cout<<"\n\n Name     : "<<name;
		cout<<"\n\n Roll No. : "<<roll;
		cout<<"\n\n Class    : "<<clas;
		cout<<"\n\n Adress   : "<<address;

		StudentDetails >> name >> roll >> clas >> address ;
		
		co++;
	}
	  if(co==0)
    {
    	cout<<"\n\n Data Base is Empty...";
	}	 
	
	}
    StudentDetails.close();	
}
void studentClass::s_search(fstream& StudentDetails) // student search function
{
	int count=0;
	
	string fname;
	system("cls");
	system("Color E4");
	StudentDetails.open("StudentDetails.txt", ios::in);
	cout<<"\n\n\t\t\t\tSearch Record";
	if(!StudentDetails)
	{
		cout<<"No data is present."<<endl;
		StudentDetails.close();
	}
	else
	{
		cin.ignore();
		cout<<"\n\n Name . For Search : ";
		getline(cin,fname);
		StudentDetails>>name>>roll>>clas>>address;
		while(!StudentDetails.eof())
		{
          if(fname==name)
		  {
            cout<<"\n\n Name : "<<name;
		    cout<<"\n\n Roll No. : "<<roll;
		    cout<<"\n\n Class : "<<clas;
		    cout<<"\n\n Adress: "<<address;
		    count++;
          
		  }
	    StudentDetails>>name>>roll>>clas>>address;

		}
				
	
		if(count == 0)
		{
			cout<<"\n\nn Student Name Not Found...";
		}
		StudentDetails.close();
	}
	
}
void studentClass::s_update(fstream& StudentDetails) //student update fuction
{
	system("cls");
	system("Color E4");
	fstream  Stud;
	string fname;
	int countt=0;
	StudentDetails.open("StudentDetails.txt", ios::in);
	if(!StudentDetails)
	{
		cout<<"\n\n\t No Data is Present";
		StudentDetails.close();
	}
	else
	{
		cin.ignore();
        cout << "\nEnter Name of Student: ";
	    getline(cin, fname);
        Stud.open("record.txt", ios::app | ios::out);
        StudentDetails >> name >> roll >> clas >> address ;
	while(!StudentDetails.eof())
	{
		if(fname!=name)
		{
			Stud<< " " << name << " " << roll << " " << clas << " " << address << "\n";
			StudentDetails.close();
		}
		else 
		{
			cout<<"\n\n\t\t\t\tUpdate Record"<<endl;
            cin.ignore();
    
            cout<<"\n\nName : ";
	        getline(cin,name);
	
	        cout<<"\n\nRoll No. : ";
	        getline(cin,roll); 
	
	        cout<<"\n\n Class : ";
	        getline(cin,clas); 
	
	        cout<<"\n\nAddress : ";
	        getline(cin,address);
			
			Stud << " " << name << " " << roll << " " << clas << " " << address << "\n";
    
            countt++;
		}
	StudentDetails >> name >> roll >> clas >> address;

	 if(countt == 0)
	   {
	   	 cout<<"\n\n Record Not Found...";
	   }
    }
        Stud.close();
        StudentDetails.close();
        remove("StudentDetails.txt");
        rename("record.txt", "StudentDetails.txt");
    }
}
void studentClass::s_del(fstream& StudentDetails) //student delete fuction
{
	system("cls");
	system("Color E4");
	fstream Stud;
	int count=0;
	string fname;
	
	StudentDetails.open("Studentdetails.txt", ios:: in);
	 if (StudentDetails.tellg())
    {
        cout << "\n\t\t\tNo Data is Present..";
        StudentDetails.close();
    }
	else
	{
        cout<<"\n\n\t\t\t\tDelete Record";
		cin.ignore();
		cout<<"\n\n Name . For Delete : ";
		getline(cin,fname);
		Stud.open("record.txt", ios::app | ios::out);
		StudentDetails>> name >> roll >> clas >> address;

		 while (!StudentDetails.eof())
		{
			if(fname != name)
			{  
				Stud << " " << name << " " << roll << " " << clas << " " << address << "\n";
			}
			else
			{
				count++;
				cout << "\n\t\t\tSuccessfully Delete Data";
			}

			StudentDetails >> name >> roll >> clas >> address;	

			}
		 
		if(count == 0)
		{
			cout<<"\n\n Record Not Found...";
		}
		Stud.close();
        StudentDetails.close();
        remove("StudentDetails.txt");
        rename("record.txt", "StudentDetails.txt");
}

}