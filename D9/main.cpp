#include <iostream>
#include <stack>
#include "program.h"
using namespace std;
int main() {
    Nstack obj;
    do{
    int exec, num;
    cout<<endl<<"Press (number) for:"<<endl<<"(1)Constructor"<<endl<<"(2)Destructor"<<endl<<"(3)Push"<<endl<<"(4)Pop"<<endl<<"(5)HowMany"<<endl<<"(6)Top"<<endl<<"(7)isEmpty"<<endl<<"(8)isFull"<<endl<<"Press enything else to exit" << endl;
    cin>>exec;
    if(exec==1) Nstack();
    else if(exec==2) obj.~Nstack();
    else if(exec==3) obj.Psh();
    else if(exec==4) obj.Pp();
    else if(exec==5) obj.HowMany();
    else if(exec==6) obj.Tops();
    else if(exec==7) obj.isEmpty();
    else if(exec==8) obj.isFull();
    else break;
    }while(true);
}