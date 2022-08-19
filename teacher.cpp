#include<iostream>
#include<string>
#include<conio.h>
#include<fstream>
#include"teacher.h"
#include"student.h" 
using namespace std;


int k=0;



void teacherClass:: t_insert(fstream& TeacherDetails) //teacher insert
{
	system("cls");
	system("Color E4");
	
    TeacherDetails.open("TeacherDetails.txt", ios::out | ios::app);

	cout<<"\n\n\t\t\t\tInsert Record\n\n"<<endl;
    cin.ignore();
	
	
    cout<<"\n\n Name : ";
	getline(cin,tname);
	
	
	
	cout<<"\n\n Subject : ";
	getline(cin,sub);
	 
	
	cout<<"\n\n Class Per Week : ";
	getline(cin,lec);
	
	
	cout<<"\n\n Pay : ";
	getline(cin,pay);
	
	
	cout<<"\n\n Address : ";
	getline(cin,taddress);
	
	TeacherDetails<<" "<<tname<<" "<<sub<<" "<<lec<<" "<<pay<<" "<<taddress<<"\n";
	TeacherDetails.close();


}

void teacherClass::t_display(fstream& TeacherDetails)  // teacher display
    {
	int c=0;
	system("cls");
	system("Color E4");
    
	TeacherDetails.open("TeacherDetails.txt", ios::in);
	if(!TeacherDetails)
	{
		cout<<"No data is Available.";
		TeacherDetails.close();
	}
     
   else
   {
	   TeacherDetails>>tname>>sub>>lec>>pay>>taddress;
	   while(!TeacherDetails.eof())
	   {
        //  cout<<"\n\n\n Teacher "<<c;
	
		cout<<"\n\n Name : "<<tname;
		cout<<"\n\n Subject : "<<sub;
		cout<<"\n\n Lecture Per Week : "<<lec;
		cout<<"\n\n Pay : "<<pay;
		cout<<"\n\n Adress : "<<taddress;

		TeacherDetails>>tname>>sub>>lec>>pay>>taddress;
		
		c++;
	   }
    if(c==0)
	{
		cout<<"Data Base is Emplty.";
	}
   }
   TeacherDetails.close();
  }
  
void teacherClass::t_search(fstream& TeacherDetails) // teacher search
   {
	int count=0;
	string fname;
	system("cls");
	system("Color E4");
	TeacherDetails.open("TeacherDetails.txt", ios::in);
	cout<<"\n\n\t\t\t\tSearch Record";
	if(!TeacherDetails)
	{
		cout<<"\n No Data is availabale.";
		TeacherDetails.close();
	}
	else
	{
     cin.ignore();
	 cout<<"\n\nName. For Search : ";
		getline(cin,fname);
		TeacherDetails>>tname>>sub>>lec>>pay>>taddress;
		while(!TeacherDetails.eof())
		{
			if(fname==tname)
			{
			cout<<"\n\t\t\t  Display Student Details";
			cout<<"\n\n Name : "<<tname;
		    cout<<"\n\n Subject : "<<sub;
		    cout<<"\n\n Lectures Per Week : "<<lec;
		    cout<<"\n\n Pay : "<<pay;
		    cout<<"\n\n Adress: "<<taddress;
		    count++;
			}

		
		TeacherDetails >> tname >> sub >> lec >> pay >> taddress ;
		  
		}
	    
		if(count==0)
       {
    	cout<<"\n\n Data Base is Empty...";
	    }	 
	
	}
    TeacherDetails.close();	
}
	
   
void teacherClass::t_update(fstream& TeacherDetails) // teacher update
{
	system("cls");
	system("Color E4");
	fstream Teach;
	string fname;
	int count=0;
	TeacherDetails.open("TeacherDetails.txt", ios::in);
	if(!TeacherDetails)
	{
		cout<<"No Data is available";
		TeacherDetails.close();
	}
		
	else
	{
		
	   cin.ignore();
	   cout<<"\n\n Name For Update : ";
	   getline(cin,fname);
	   Teach.open("record.txt", ios::app | ios::out);
	   TeacherDetails>>tname>>sub>>lec>>pay>>taddress;
	  	while(!TeacherDetails.eof())
	{
		if(fname!=tname)
		{
			Teach<< " " << tname << " " << sub << " " << lec << " " << pay <<" "<< taddress << "\n";
			TeacherDetails.close();
		}
		else 
		{
			
			   	cout<<"\n\n\t\t\t\tUpdate Record";
    
	         	cout<<"\n Name : ";
	            getline(cin,tname);
	
	
	            cout<<"\n\n Subject : ";
	            getline(cin,sub); 
	            
	            cout<<"\n\n Class Per Week : ";
	            getline(cin,lec);
	 
	
	            cout<<"\n\n Pay : ";
	            getline(cin,pay);
	
	
	            cout<<"\n\nAddress : ";
	            getline(cin,taddress);

                Teach << " " << tname << " " << sub << " " << lec << " " << pay <<" "<<taddress << "\n";
				
				count++;
				}

	     TeacherDetails>> tname >> sub >> lec >> pay >> taddress ;		
	     if(count == 0)
	     {
	      	 cout<<"\n\n Record Not Found...";
	     }
	}
        Teach.close();
        TeacherDetails.close();
        remove("TeacherDetails.txt");
        rename("record.txt", "TeacherDetails.txt");
    }
}
void teacherClass::t_del(fstream& TeacherDetails) // teacher delete
{
	system("cls");
	system("Color E4");
	fstream Teach;
	string fname;
    int count=0;
	TeacherDetails.open("TeacherDetails.txt", ios:: in);
	if(!TeacherDetails)
	{
		cout << "\n\t\t\tNo Data is Present..";
		TeacherDetails.close();
	}
	else
	{
     cin.ignore();
		cout<<"\n\n Name. For Delete : ";
		getline(cin,fname);
        Teach.open("TeacherDetails.txt", ios::app | ios::out);
		TeacherDetails>>tname>>sub>> lec>> pay>> taddress;

		while(!TeacherDetails.eof())
		{
			if(fname!=tname)
			{
				Teach << " " << tname << " " << sub << " " << lec << " " << pay <<" "<< taddress << "\n";
				
			}
			else
			{
				count++;
				cout << "\n\t\t\tSuccessfully Delete Data";
			}
		
		    TeacherDetails >> tname >> sub >> lec >> pay >> taddress;
		}

        if(count == 0)
		{
			cout<<"\n\n Record Not Found...";
		}
		Teach.close();
        TeacherDetails.close();
        remove("TeacherDetails.txt");
        rename("record.txt", "TeacherDetails.txt");
}

}