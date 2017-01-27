#include "Student.h"

using namespace std;

// Constructor
Student::Student(char* _first, char* _last, int _id, double _gpa) {
  // Concatenate the first & last names into full name + store within unified variable (name)
  name = new char [51];
  strcpy(name, _first);
  strcat(name, " ");
  strcat(name, _last);

  id = _id;
  gpa = _gpa;
}

// Deconstructor
Student::~Student() {
  delete name;
}

// ACCESSORS
char* Student::getName() {  return name; }
int Student::getID() { return id; }
double Student::getGPA() { return gpa; }