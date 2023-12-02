#include<iostream>
#include<cstring>
#include"Student.h"

using namespace std;

Student :: Student(char* firstName, char* lastName, int newId, float newGPA) {
  firstName = new char[80];
  strcpy(firstName, firstName);
  lastName = new char[80];
  strcpy(lastName, lastName);
  int id = newId;
  float GPA = newGPA;

}

char* Student :: getFirstName() {
  return firstName;
}

char* Student :: getLastName() {
  return lastName;
}

int Student :: getId() {
  return id;
}

float Student :: getGPA() {
  return GPA;
}

void Student :: printStudent() {
  cout << "First name is " << firstName << endl;
  cout << "Last name is " << lastName << endl;
  cout << "ID is " << id << endl;
  cout << "GPA is " << GPA << endl;


}
