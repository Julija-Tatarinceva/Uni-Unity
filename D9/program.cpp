#include <iostream>
#include <stdio.h>
#include "program.h"
#include <windows.h> //for delay
using namespace std;

Nstack::Nstack() { //konstruktors
    for(int i = 0; i<5; i++){
      int num;
      cin>>num;
      cout << "Ielikts: " << num << " ";
      Numbers.push(num);
    }
    cout<<endl << "Steks ir pilns" <<endl;
}

Nstack::~Nstack() { //destruktors
  if(Numbers.size()>1) cout << "Likvideti " << Numbers.size() << " elementi"<< endl;
  else if(Numbers.size()==1) cout << "Likvidets " << Numbers.size() << " elements"<< endl;
  else if(Numbers.size()==0) cout << "Likvidets tukss steks"<< endl;
  while(!Numbers.empty()){
      Numbers.pop();
  }
}
void Nstack::Psh() {
  if(Numbers.size()<5){
    int num;
    cout << "Elements, kuru vajag ielikt: " << endl;
    cin>>num;
    Numbers.push(num);
    cout << "Ielikts " << num;
  }
  else cout <<  "Nevaru ielikt elementu: steks ir pilns" << endl;
  Sleep(1300);//pauze, lai nolasītu izvadi
}
int Nstack::Pp() {
  if(Numbers.size()>0){
    int pop = Numbers.top();
    Numbers.pop();
    return pop;
  }
  return 0;
}
void Nstack::HowMany() {
  if(Numbers.size()>0)cout<<"Steks satur " << Numbers.size() << " elementu";
  if(Numbers.size()>1)cout << "s" << endl;//lai izmantotu pareizo galotni izvadā
  if(Numbers.size()==0) cout << "Steka nav elementu"<<endl;
  Sleep(1300);
}
void Nstack::Tops() {
    if(Numbers.size()>0) cout << "Augsa atrodas "<< Numbers.top()<<endl;
    else cout << "Nevar izpildit darbibu: steks ir tukss" << endl;
    Sleep(1300);
}
void Nstack::isEmpty() {
  if(Numbers.size()==0) cout<<"Steks ir tukss" << endl;
  else cout << "Steks nav tukss, satur " << Numbers.size()<< " elementus"<< endl;
  Sleep(1300);
}
void Nstack::isFull() {
  if(Numbers.size()==5) cout << "Steks ir pilns"<< endl;
  else cout << "Steks nav pilns, satur " << Numbers.size()<< " elementus"<< endl;
  Sleep(1300);
}
