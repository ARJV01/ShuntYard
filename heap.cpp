#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

void add(int ary[], int counter);
void sort(int ary[], int index);
void print(int ary[], int counter);
void arrayNuller(int ary[], int size);//Makes all elements in an array null

int main() {
  char input[20];
  bool stillRunning = true;
  int ary[100];
  int counter = 1;
  int size = sizeof(ary)/sizeof(ary[0]);
  arrayNuller(ary, size);
  while(stillRunning == true) {
  cout << "please enter add print or quit " << endl;
    cin >> input;
    cin.ignore(256, '\n');
    if(strcmp(input, "add") == 0) {
      add(ary, counter);
    }
    if(strcmp(input, "print") == 0) {
      print(ary, counter);
    }
    if(strcmp(input, "quit") == 0) {
      stillRunning = false;
    }
  }
  return 0;
}

void arrayNuller(int ary[], int size) {
  for(int i = 0; i < size; i++) {
    ary[i] = NULL;
  }
}

void add(int ary[], int counter) {
  cout << "enter you numbers when your done enter 00 " << endl;
  int input = 1;
  while(input != 00) {
    cin >> input;
    cin.ignore(256, '\n');
    ary[counter] = input;
    counter++;
    sort(ary, counter-1);
  }
  print(ary, counter);
}

void sort(int ary[], int index) {
  int l = 2*index;
  int r = 2*index+1;
  int largest = index;

  if (ary[largest] < ary[r]) {
    r = largest;
  }
  if (ary[largest] < ary[l]) {
    l = largest;
  }

  if (largest!= index) {
  swap(ary[index], ary[largest]);
  sort(ary, largest);
}
}

void print(int ary[], int counter) {
  for(int i = 0; i < counter; i++) { 
    int parent = (floor(i/2));
    int current = ary[i];
    int rChild = (i * 2 + 1);
    int lChild = (i * 2);

    int tC = 1;

    cout << "current " << current << "child " << ary[lChild] << "parrent " << ary[parent] << endl;
    if (ary[parent] != NULL) {
      tC ++; 
    }
    if (ary[rChild] != NULL || ary[lChild] != NULL) {
      tC = tC - 1;
    }
    for(int a =0; a < tC; a++) {
      cout << "\t";
    }
    cout << current << endl;
  }
}

