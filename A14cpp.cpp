/*
Jūlija Tatarinceva, jt22005
A14. Dots naturāls skaitlis n. Noteikt, vai n ir pirmskaitlis.
Programma izveidota: 2022/09/11
*/
#include <iostream>

using namespace std;

int main()
{
    int n, redo;
    do{
        bool isPrime = true; //changes to False if a factor is found, will stay True otherwise
        cout << "Please enter a natural number \n";
        cin >> n;
        if(n<2){
            cout << "Prime numbers are greater that 1 \n";
        }
        else{
            for (int i = 3; i < n; i++){ //searching for factors between 2 and n
                if((n%i) == 0){
                    isPrime = false;
                    break;
                }
            }
            if(isPrime){
                cout << n << " is prime \n";
            }else{
                cout << n << " is not considered prime \n";
            }
        }
        cout << "Would you like to continue(1) or stop(any key) testing? \n";
        cin >> redo;
    } while(redo == 1);
}
/*              Testa plāns
 ____________________________________________
 |Ievads|  Rezultāts |Vai pareizs rezultāts?|
 -------|------------|----------------------|
 |  1   |nav pirmsk. |          +           |
 -------|------------|----------------------|
 |  7   |ir pirmsk   |          +           |
 -------|------------|----------------------|
 |  8   |nav pirmsk. |          +           |
 |------|------------|----------------------|
 |  -5  |nav pirmsk. |          +           |
 ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
 */

