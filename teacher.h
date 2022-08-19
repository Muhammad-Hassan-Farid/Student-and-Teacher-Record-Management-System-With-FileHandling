#ifndef TEACHER_H
#define TEACHER_H
 
#include<string>
#include<fstream>
using namespace std;


class teacherClass: public studentClass
{

private:
string tname,sub,pay,lec,taddress;

public:


void t_insert(fstream& TeacherDetails); //teacher insert
void t_display(fstream& TeacherDetails);  // teacher display 
void t_search(fstream& TeacherDetails); // teacher search  
void t_update(fstream& TeacherDetails); // teacher update
void t_del(fstream& TeacherDetails); // teacher delete

};
#endif

