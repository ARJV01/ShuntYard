#ifndef ALPHA
#define ALPHA

#include<iostream>
#include<cstring>

using namespace std;

class Student {
public:
  Student(char* firstName, char* lastName, int newId, float newGPA);
  char* getFirstName();
  char* getLastName();
  int getId();
  float getGPA();
  void printStudent();

private:
  char* firstName;
  char* lastName;
  int id;
  float GPA;
};

#endif
