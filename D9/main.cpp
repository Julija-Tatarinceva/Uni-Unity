/*Jūlija Tatarinceva, jt22005
D9. "Izveidot klasi ""Skaitļu steks"" - Nstack, kurā glabājas masīvs ar skaitliskām vērtībām (int) garumā 5 un steka elementu skaits. Klasei izveidot šādas metodes: 
(1) konstruktors, (2) destruktors, kurš paziņo par objekta likvidēšanu un likvidēto elementu skaitu (ja likvidēšanas brīdī steks nav tukšs), (3) metode ""Ielikt"" - push, kas pievieno stekam elementu, ja tas nav pilns, 
(4) metode ""Izņemt"" - pop, kas izņem no steka augšējo elementu un atgriež tā vērtību, (5) metode ""CikElementu"" - count, kas atgriež elementu skaitu stekā, 
(6) metode ""Augša"" - top, kas atgriež augšējā elementa vērtību, (7) metode ""VaiTukšs"" - isEmpty, kas noskaidro, vai steks ir tukšs, 
(8) metode ""VaiPilns"" - isFull, kas noskaidro, vai steks ir pilns.  
Programma izveidota: 2022/10/23 */

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
}/*              Testa plāns
 ____________________________________________
 |Ievads|  Rezultāts |Vai pareizs rezultāts?|
 -------|------------|----------------------|
 |      |            |                      |
 -------|------------|----------------------|
 |      |            |                      |
 -------|------------|----------------------|
 |      |            |                      |
 |------|------------|----------------------|
 |      |            |                      |
 ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*/
