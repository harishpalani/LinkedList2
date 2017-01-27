#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class Student {

  public:
	Student(char*, char*, int, double);
	~Student();
	char* getName();
	int getID();
	double getGPA();

  protected:
	char* name;
	int id;
	double gpa;
	
};

#endif