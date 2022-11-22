#include <iostream>
#include "prgrm.h"
using namespace std;

int main(){
    int yorn;
    BST object;
    cout<<"Izdrukaat failaa sastaptos vaardus? (1-izdrukaat 0-beigt)";
    cin>>yorn;
    if(yorn!=0){
        cout<<"Printing everything in alfabetical order:"<<endl;
        object.printA();
    }
    /*while (0){
        cout<<"search for: ";
        cin>>lookfor;
        cout<<endl<<Searchh(root, lookfor);
    }*/
}
