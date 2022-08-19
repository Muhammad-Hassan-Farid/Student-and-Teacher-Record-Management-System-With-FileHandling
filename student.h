#ifndef STUDENT_H
#define STUDENT_H
#include<string>
#include<fstream>
#include"admin.h"
using namespace std;

class studentClass : public AdminClass
{

private: 
string roll,name,clas,address;

public:

void record();
void s_insert(fstream& StudentDetails); //Student Insert Fuction
void s_display(fstream& StudentDetails); // Student Display Fuction
void s_search(fstream& StudentDetails); // Student Search Fuction
void s_update(fstream& StudentDetails); //Student Update Fuction
void s_del(fstream& StudentDetails); // Student Delete Fuction

};
#endif