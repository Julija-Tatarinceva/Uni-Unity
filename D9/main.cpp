/*Jūlija Tatarinceva, jt22005
D9. "Izveidot klasi ""Skaitļu steks"" - Nstack, kurā glabājas masīvs ar skaitliskām vērtībām (int) garumā 5 un steka elementu skaits. Klasei izveidot šādas metodes:
(1) konstruktors, (2) destruktors, kurš paziņo par objekta likvidēšanu un likvidēto elementu skaitu (ja likvidēšanas brīdī steks nav tukšs),
(3) metode ""Ielikt"" - push, kas pievieno stekam elementu, ja tas nav pilns,
(4) metode ""Izņemt"" - pop, kas izņem no steka augšējo elementu un atgriež tā vērtību, (5) metode ""CikElementu"" - count, kas atgriež elementu skaitu stekā,
(6) metode ""Augša"" - top, kas atgriež augšējā elementa vērtību, (7) metode ""VaiTukšs"" - isEmpty, kas noskaidro, vai steks ir tukšs,
(8) metode ""VaiPilns"" - isFull, kas noskaidro, vai steks ir pilns.
Programma izveidota: 2022/10/23*/

#include <iostream>
#include <stack>
#include "program.h"
#include <windows.h>
using namespace std;
int main() {
    cout<<"Vispirms ievadi 5 ciparus, lai aizpilditu steku: ";
    Nstack obj; //šis tiks izmantots katrai metodei
    int exec;
    do{ //cikls programmas atkartošanai
    cout<<endl<<"Ievadiet (cipars), lai:"<<endl<<"(1)Ieliktu elementu"<<endl<<"(2)Iznemtu elementu"<<endl
    <<"(3)Uzzinatu, cik steka ir elementu"<<endl<<"(4)Uzzinatu, kads elements ir augsa"<<endl<<"(5)Uzzinatu, vai steks ir tukss"<<endl<<
    "(6)Uzzinatu, vai steks ir pilns"<<endl << "Cits ievads pabeigs programmas darbibu." << endl;
    cin>>exec;
    if(exec==1)obj.Psh();
    else if(exec==2){
        int temp = obj.Pp();
        if(!temp) cout <<  "Nevaru iznemt elementu: steks ir tukss" << endl;
        else cout << "Iznemts " << temp << endl;
        Sleep(1300); //pauze, lai nolasītu izvadi
    }
    else if(exec==3) obj.HowMany();
    else if(exec==4) obj.Tops();
    else if(exec==5) obj.isEmpty();
    else if(exec==6) obj.isFull();
    else break;
    }while(true);
    cout<<"Darbiba pageigta"<<endl;
}






/*              Testa plāns

ievadīts sākumā: 1 2 3 4 5
 _______________________________________________
 |Ievads|  Rezultāts    |Vai pareizs rezultāts?|
 |------|---------------|----------------------|
 |  1   | Nevar ielikt  |          +           |
 |------|---------------|----------------------|
 |  2   | Iznemts 5     |          +           |
 |------|---------------|----------------------|
 |  3   | 4 elementi    |          +           |
 |------|---------------|----------------------|
 |  4   |Augsa atrodas 4|          +           |
 |------|---------------|----------------------|
 |  5   |Steks nav tukss|          +           |
 |------|---------------|----------------------|
 |  6   |Steks nav pilns|          +           |
 |------|---------------|----------------------|
 |  2   | Iznemts 4     |          +           |
 |------|---------------|----------------------|
 |  2   | Iznemts 3     |          +           |
 |------|---------------|----------------------|
 |  2   | Iznemts 2     |          +           |
 |------|---------------|----------------------|
 |  2   | Iznemts 1     |          +           |
 |------|---------------|----------------------|
 |  2   | Nevaru iznemt |          +           |
 |------|---------------|----------------------|
 |  4   | Nevar izpildit|          +           |
 ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*/
