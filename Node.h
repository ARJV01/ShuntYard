#ifndef BRAVO
#define BRAVO

#include<iostream>
#include<cstring>
#include"Student.h"

using namespace std;

class Node{//node class
public:
  Node(Student*);//contructor for node class
  Student* getStudent();//will return the student inside the node
  Node* getNext();//will get the next node in the list
  void setNext(Node*);//sets the next node in the list
  ~Node();//node destructor
  private:
  Student* student;
  Node* next;
     
};

#endif
