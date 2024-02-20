#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>

using namespace std;

void addInput(int (&ary)[], int &counter);
void addFile(int (&ary)[], int &counter);
void sort(int (&ary)[], int index);
void print(int ary[], int counter, int level, int index);
int remove(int (&ary)[], int index, int &counter);
void removeAll(int (&ary)[], int index, int &counter);
void arrayNuller(int (&ary)[], int &size);//Makes all elements in an array null
void reverseSort(int (&ary)[], int index);

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
      print(ary, counter, 0, 0);
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
  cout << "alive" << endl;
  fin.close();
  cout << "dead" << endl;
}


void sort(int (&ary)[], int index) {
  int parent = (floor(index / 2));
   if(ary[index] > ary[parent]) {
     swap(ary[index], ary[parent]);
     int newParrent = (floor(parent / 2));
      if (ary[parent] > ary[newParrent]) {
	sort(ary,parent);
      }
   }
}




void print(int ary[], int counter, int level, int index) {
  if (index >= counter) {
    return;
  }
  print(ary, counter, level + 1, 2 * index + 1);

  for(int i = 0; i < level; i++) {
    cout << "\t";
  }
  cout << ary[index] << endl;
  print(ary, counter, level + 1, 2 * index + 2);
}

int remove(int (&ary)[], int index, int &counter) {
  int temp = ary[0];
  ary[0] = ary[counter];
  ary[counter] = 0;
  counter = counter - 1;
  reverseSort(ary, index);
  return temp;
}

void removeAll(int (&ary)[], int index,int &counter) {
  int i = 0;
  while(i < counter) {
    remove(ary,index,counter);
    i++;
  }
}

void reverseSort(int (&ary)[], int index) {
  int rChild = (index * 2 + 1);
  int lChild = (index * 2 + 2);
  int largest = 0;
  if (ary[rChild] < ary[lChild]) {
    largest = lChild;
  }
  else {
    largest = rChild;
  }
  if(ary[largest] > ary[index] ) {
    swap(ary[index], ary[largest]);
    reverseSort(ary, largest);
  }
}
