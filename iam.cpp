#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include"admin.cpp"
#include"admin.h"
#include"student.cpp"
#include"student.h"
#include"teacher.cpp"
#include"teacher.h"
using namespace std;

int main()
{


	int choice;
	char x;
	
    int ch;
    teacherClass t1;
    fstream StudentDetails,TeacherDetails;
	
	
	system("cls");
	system("Color E4");

	
    t1.login();
	
	p:
     system("cls");
	cout<<"\t\t\t\tSchool Managment"<<endl;
	cout<<"\n\n\n\t\tPress 1 for Student Record."<<endl;
	cout<<"\n\t\tPress 2 for Teacher Record."<<endl;
	cout<<"\n\t\tPress 3 for Exit."<<endl;
	cout<<"\n\t\tEnter your Choice: ";
	cin>>ch;
	if(ch==1)
	{
		system("cls");
        t1.record();
		cin>>choice;
	switch(choice)
	{
		case 1:
			do
			{
			t1.s_insert(StudentDetails);
			cout<<"\n\n Do You Want To Add Another Record (y,n) : ";
			cin>>x;
		    }while(x == 'y');
		    
			break;
		case 2:
			t1.s_display(StudentDetails);
			
			break;
		case 3:
			t1.s_search(StudentDetails);
			
			break;
		case 4:
			t1.s_update(StudentDetails);
			
			break;
		case 5:
			t1.s_del(StudentDetails);
			
			break;
		case 6:
			goto p;
			break;
		case 7:
			exit(0);
		default:
			cout<<"\n\n Invalid Value...Please Try Again...";
	}
		
	}
	
	else if(ch==2)
	{
	system("cls");
	t1.record();
	cin>>choice;
	switch(choice)
	{
		case 1:
			do
			{
			t1.t_insert(TeacherDetails);
			k++;
			cout<<"\n\n Do You Want To Add Another Record (y,n) : ";
			cin>>x;
		    }while(x == 'y');
		    
			break;
		case 2:
			t1.t_display(TeacherDetails);
			
			break;
		case 3:
			t1.t_search(TeacherDetails);
			
			break;
		case 4:
			t1.t_update(TeacherDetails);
			
			break;
		case 5:
			t1.t_del(TeacherDetails);
			break;
		case 6:
			goto p;
			break;
		case 7:
			exit(0);
		default:
			cout<<"\n\n Invalid Value...Please Try Again...";
	}
	}
	else if(ch==3)
	{
		exit(0);
	}
	else 
	{
		cout<<"\n\n\t\tYou Entered a Wrong Number."<<endl;
		cout<<"\t\tPress Enter and Try Again";
		
	}
	getch();
	goto p;
	
	return 0;	
}