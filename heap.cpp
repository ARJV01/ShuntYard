#include<iostream>
#include<cstring>
#include<cmath>
#include<fstream>

using namespace std;

void addInput(int (&ary)[], int &counter);
void addFile(int (&ary)[], int &counter);
void sort(int (&ary)[], int &index);
void print(int ary[], int counter);
void remove(int (&ary)[], int &index, int &counter);
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
  cout << "please enter add, print, remove, removeALL, or quit " << endl;
    cin >> input;
    cin.ignore(256, '\n');
    if(strcmp(input, "add") == 0) {
      cout << "enter file or input" << endl;
      cin >> input;
      if (strcmp(input, "input") == 0) {
	addInput(ary, counter);
      }
      if (strcmp(input, "file") == 0) {
        addFile(ary, counter);
      }
    }
    if(strcmp(input, "print") == 0) {
      print(ary, counter);
    }
     if(strcmp(input, "removeAll") == 0) {
       removeAll(ary, index, counter);
      counter = 0;
    }
     if(strcmp(input, "remove") == 0) {
       remove(ary, index, counter);
      counter = 0;
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
  int temp = 0;
  while(fin >> temp) {
    cout << temp << endl;
    ary[counter] = temp;
    counter++;
  }
  fin.close();
}


void sort(int (&ary)[], int &index) {
  int parent = (floor(index / 2));
  if(ary[index] > ary[parent]) {
    swap(ary[index], ary[parent]);
    int newParrent =  (floor(parent / 2));
      if (ary[parent] > ary[newParrent]) {
	sort(ary,parent);
      }
  }

}


void print(int ary[], int counter) {
  for (int i = 0; i < counter; ++i) {
        cout << ary[i] << " ";
    cout << "\n";
}
}

void remove(int (&ary)[], int &index, int &counter) {
  ary[0] = NULL;
  counter = counter - 1;
  //sort(ary, index+1);
}

void removeAll(int (&ary)[], int &index,int &counter) {
  int i = 0;
  while(i < counter) {
    remove(ary,index,counter);
    i++;
  }
}

