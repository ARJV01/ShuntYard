#include<iostream>
#include <cctype>
#include<cstring>
#include<iomanip>

using namespace std;

class Node {
public:
  char value;
  Node* next;

  Node(char newValue) {
    next = NULL;
    value = newValue;
  }
  char getValue() {
    return value;
  }
  Node* getNext() {
    return next;
  }
  void setNext(Node* nextNode) {
    next = nextNode;
  }
  void printV(Node* node) {
    if(node != NULL) {
    cout << node -> getValue() << endl;
    }
  }
  ~Node() {}
};

class NodeBT {
public:
  char value;
  NodeBT* right;
  NodeBT* left;
  NodeBT* next;

  NodeBT(char newValue) {
    left = NULL;
    right = NULL;
    next = NULL;
    value = newValue;
  }
  char getValueBT() {
    return value;
  }
  NodeBT* getR() {
    return right;
  }
  void setR(NodeBT* newRight) {
    right = newRight;
  }
  NodeBT* getL() {
    return left;
  }
  void setN(NodeBT* newNext) {
    next = newNext;
  }
  NodeBT* getN() {
    return next;
  }
  void setL(NodeBT* newLeft) {
    left = newLeft;
  }
  ~NodeBT() {}
};

void popBt(NodeBT* &sfc);
void printBT(NodeBT* sfc);
void btMaker(Node* qTail, Node* qFront,NodeBT* sfc);//makes the binary tree
int getP(char a);// will return the precedence of an operator
bool isOp(char a);//will determine if somthing is an operator
void printQ(Node* head);//will print the queue, used for debugging
void arrayNuller(char ary[]);//will null an array
void pop(Node* &stackFront);//removes the top of the stack
void push(Node* &stackFront, char newValue);//pushs a new value to the top of the stack
void pushBt(NodeBT* &stackFront, NodeBT* temp);
char peek(Node* stackFront);//returns the top value of the stack
void enqueue(Node* &qFront, Node* &qTail, char newValue);//Puts an new node at the back of the queue
Node* dequeue(Node* &qFront);//removes the node at the front of the queue
void shunter(char ary[], Node* &stackFront, Node* &qTail, Node* &qFront, int counter);// will convert an expression from infix notation to postfix notation.

int main() {
  Node* stackFront = NULL;
  Node* qFront = NULL;
  Node* qTail = NULL;
  NodeBT* sfc = NULL;
  char input[20];
  char ary[20];
  arrayNuller(input);
  arrayNuller(ary);
  int counter = 0;
  cout << "please enter the equation" << endl;
  cin.getline(input, 80);
  for(int i = 0; i < 20; i++) {
    if(input[i] != ' ' && input[i] != '\n' && input[i] != NULL) {
      ary[counter] = input[i];
      counter++;
    }
  }
  shunter(ary,stackFront,qTail,qFront,counter);
  printQ(qFront);
  btMaker(qTail,qFront,sfc);
  return 0;
}

void arrayNuller(char ary[]) {
  for(int i = 0; i < 20; i++) {
    ary[i] = NULL;
  }
}

void pop(Node* &stackFront) {
  if(stackFront != NULL) {
  Node* temp;
  temp = stackFront;
  if(temp -> getNext() != NULL) {
    stackFront = temp -> getNext();
    delete temp;
  }
  else {
    stackFront = NULL;
  }
  }
}

void push(Node* &stackFront, char newValue) {
  Node* temp = new Node(newValue);
  if(stackFront != NULL) {
  temp -> setNext(stackFront);
  }
  stackFront = temp;
}

char peek(Node* stackFront) {
  if(stackFront != NULL){
  return stackFront -> getValue();
  }
  return NULL;
}

void enqueue(Node* &qFront, Node* &qTail,char newValue) {
  Node* temp = new Node(newValue);
  if(qTail != NULL) {
  qTail -> setNext(temp);
  }
  qTail = temp;
  if(qFront == NULL) {
    qFront = qTail;
  }
}

Node* dequeue(Node* &qFront) {
  Node* temp = qFront;
  if (qFront != NULL) {
    qFront = qFront -> getNext();
    delete temp;
  }
  return qFront; 
}

void shunter(char ary[],Node* &stackFront,Node* &qTail,Node* &qFront,int counter) {
   for(int i = 0; i < counter; i++) {
    if(isdigit(ary[i])){//if number put in stack
      enqueue(qFront, qTail, ary[i]);
    }

      if(ary[i] == '(') {
        push(stackFront,ary[i]);
      }

      if(ary[i] == ')') {

        while(stackFront != NULL && stackFront -> getValue() != '(') {
          enqueue(qFront,qTail,(stackFront->getValue()));
          pop(stackFront);
        }

        if(stackFront != NULL) {
        pop(stackFront);
        }

      }
      if(isOp(ary[i])) {
        while(stackFront != NULL && getP(ary[i]) <= getP(stackFront->getValue())) {
          enqueue(qFront,qTail,stackFront -> getValue());
          pop(stackFront);
        }
        push(stackFront, ary[i]);
      }
  }
  while(stackFront != NULL) {
    enqueue(qFront, qTail, stackFront->getValue());
    pop(stackFront);
  }
}

void btMaker(Node* qTail, Node* qFront,NodeBT* sfc) {
  char pfe[20];
  arrayNuller(pfe);
  int counter = 0;
  Node* current = qFront;
  while(current != NULL) {
    pfe[counter] = current -> getValue();
    current = current->getNext();
    counter++;
  }
  for(int i = 0; i << counter; i++) {

    if(isOp(pfe[i])) {
      NodeBT* temp = new NodeBT(pfe[i]);
      NodeBT* right = sfc;
      popBt(sfc);
      NodeBT* left = sfc;
      temp ->setL(left);
      temp -> setR(right);
      pushBt(sfc,temp);
    }
    else {
      NodeBT* temp = new NodeBT(pfe[i]);
      pushBt(sfc, temp);
    }
  }
  printBT(sfc);
}

void pushBt(NodeBT* &stackFront, NodeBT* temp) {
  if(stackFront == NULL) {
    stackFront = temp;
  }
  else {
    temp -> setN(stackFront);
    stackFront = temp;
  }
}

void popBt(NodeBT* &sfc) {
  if(sfc != NULL) {
  NodeBT* temp = sfc;
  sfc = sfc -> getN();
  delete temp;
  }
}

void printQ(Node* head) {
  char temp[20];
  arrayNuller(temp);
  int count = 0;
  while(head != NULL) {
    temp[count] = head -> getValue();
    head = head->getNext();
    count++;
  }
  for(int i = 0; i < count; i++) {
    cout << temp[i];
  }
  cout << endl;
}

int getP(char a) {
  if(a == '+' || a == '-') {
    return 1;
  }
  if(a == '/' || a== '*') {
    return 2;
  }
  return 0;
}

bool isOp(char a) {
  if(a == '*' ||
     a == '/' ||
     a == '+' ||
     a == '^' ||
     a == '-') {
    return true;
  }
  return false;
}

void printBT(NodeBT* sfc) {
  if(sfc == NULL) {
    return;
  }
  else {
    printBT(sfc->getL());
    cout << sfc -> getValueBT();
    printBT(sfc->getR());
  }
}
