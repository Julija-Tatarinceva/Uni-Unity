#include <iostream>
#include <stdio.h>
#include "program.h"
using namespace std;
Nstack::Nstack() { //constructor
  cout<<"Input 5 numbers to push: ";
    for(int i = 0; i<5; i++){
      int num;
      cin>>num;
      cout << "Pushed: " << num << " ";
      Numbers.push(num);
    }
    cout<<"Stack filled" <<endl;
}
Nstack::~Nstack() { //destructor
  int num = 0;
  cout << "Deleting: " << Numbers.size() << " elements";
  while(!Numbers.empty()){
      Numbers.pop();
      num++;
  } 
}
void Nstack::Psh() {
  int num;
  cout << "Number to push: " << endl;
  cin >> num;
  if(Numbers.size()<5){
    Numbers.push(num);
    cout << "Pushed " << num;
  }
  else cout <<  "Its full" << endl;
}
void Nstack::Pp() {
  if(Numbers.size()>0){
    cout << "Popped " << Numbers.top() << endl;
    Numbers.pop();
  }
  else cout <<  "Its empty" << endl;
}
void Nstack::HowMany() {
  cout<<Numbers.size()<< endl;
}
void Nstack::Tops() {
  cout << Numbers.top();
}
void Nstack::isEmpty() {
  if(Numbers.size()==0) cout<<"Stack is empty";
  else cout << "Not empty";
}
void Nstack::isFull() {
  if(Numbers.size()==5) cout << "Stack is full";
  else cout << "Not full";
}