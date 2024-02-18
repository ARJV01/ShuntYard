#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>

using namespace std;

void addInput(int (&ary)[], int &counter);
void addFile(int (&ary)[], int &counter);
void sort(int (&ary)[], int &index);
void print(int ary[], int counter);
int remove(int (&ary)[], int &index, int &counter);
void removeAll(int (&ary)[], int &index, int &counter);
void arrayNuller(int (&ary)[], int &size);//Makes all elements in an array null

int main() {
  char input[20];
  bool stillRunning = true;
  int ary[100];
  int counter = 0;
  int index = 0;
  int size = sizeof(ary)/sizeof(ary[0]);
  arrayNuller(ary, size);
  while(stillRunning == true) {
  cout << "please enter addFile, addInput, print, remove, removeAll, or quit " << endl;
    cin >> input;
    cin.ignore(256, '\n');
      if (strcmp(input, "addInput") == 0) {
	addInput(ary, counter);
      }
      if (strcmp(input, "addFile") == 0) {
        addFile(ary, counter);
      }
    if(strcmp(input, "print") == 0) {
      print(ary, counter);
    }
     if(strcmp(input, "removeAll") == 0) {
       removeAll(ary, index, counter);
      counter = 0;
    }
     if(strcmp(input, "remove") == 0) {
       cout << remove(ary, index, counter) << endl;
    }

    if(strcmp(input, "quit") == 0) {
      stillRunning = false;
    }
  }
  return 0;
}

void arrayNuller(int (&ary)[], int &size) {
  for(int i = 0; i < size; i++) {
    ary[i] = NULL;
  }
}

void addInput(int (&ary)[], int &counter) {
  cout << "enter how many numbers you wish to input up too 100 " << endl;
  int inputL = 0;
  int i = 0;
  cin >> inputL;
  int input = 0;
  cout << "enter your numbers" << endl;
  while(i < inputL) {
    cin >> input;
    cin.ignore(256, '\n');
    ary[counter] = input;
    sort(ary, counter);
    counter++;
    i++;
  }
  print(ary, counter);
}

void addFile(int (&ary)[], int &counter) {
  cout << "enter file name " << endl;
  char input[20];
  cin >> input;
  ifstream fin(input);
  char* temp;
  temp = new char[20];
  while(fin >> temp) {
    ary[counter] = (int)(*temp);
    counter++;
    sort(ary, counter); 
    temp = new char[20];
  }
  print(ary, counter);
  cout << "alive" << endl;
  fin.close();
  cout << "dead" << endl;
}


void sort(int (&ary)[], int &index) {
  int parent = (floor(index / 2));
   if(ary[index] > ary[parent]) {
     swap(ary[index], ary[parent]);
     int newParrent = (floor(parent / 2));
      if (ary[parent] > ary[newParrent]) {
	sort(ary,parent);
      }
   }
}




void print(int ary[], int counter) {
  int level = 0;
  for (int i = 0; i < counter; ++i) {
    int current = ary[i];
    while(ary[current] != ary[0]) {
	level++;
	current = (floor(current/2));
    }
    for(int i =0; i < level; i++) {
      //cout << '\t';
    }
    //cout << ary[i] << endl;
    level = 0;
    int parent = (floor((i-1)/2));
    int current1 = ary[i];
    int rChild = (i * 2 + 1);
    int lChild = (i * 2 + 2);

    cout << "current " << current1 << "rchild " << ary[rChild] << "lchild " << ary[lChild] << "parrent " << ary[parent] << endl;
}
}

int remove(int (&ary)[], int &index, int &counter) {
  int temp = ary[0];
  ary[0] = ary[counter];
  counter = counter - 1;
  index++;
  sort(ary, index);
  return temp;
}

void removeAll(int (&ary)[], int &index,int &counter) {
  int i = 0;
  while(i < counter) {
    remove(ary,index,counter);
    i++;
  }
}

