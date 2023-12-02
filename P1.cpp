#include<iostream>
#include<cstring>
#include"Student.h"
#include"Node.h"

using namespace std;

int main() {
  char* fname;
  char* lname;
  strcpy(fname, "Arjun");
  strcpy(lname, "vinsel");
  Student* stu = new Student(fname,lname,4356,4);
  Node* node = new Node(stu);
  char* fname2;
  char* lname2;
  strcpy(fname, "ian");
  strcpy(lname, "williams");
  Student* stu2 = new Student(fname2,lname2,456,2);
  Node* node2 = new Node(stu2);
  node -> setNext(node2);

  ((node) -> getStudent()) -> printStudent();
  cout << (((node) -> getNext()) ->getStudent()) -> getFirstName() << endl;
  node -> ~Node();
  return 0;
}
