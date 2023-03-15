/* Jūlija Tatarinceva, jt22005
G19. Uzrakstīt funkciju, kas no saraksta izmet tos elementus, 
tieši aiz kuriem sarakstā seko elementi, kuru vērtība ir pāra skaitlis.
Programma izveidota: 2023/03/02 */

#include <iostream>
#include <list>
#include <time.h>
using namespace std;

void ScaredOfEvenElements(list<int> &list){
    auto it = list.begin();
    auto it1 = it;
    while(it!=--(list.end())){
        it1=it;     
        ++it1; //šeit it1 tiek parvietots uz priekšu uz vienu soli no it un, 
        if((*(it1))%2==0) it=list.erase(it); //ja it1 ir pāra skaitlis, tad iepriekšejais elements it tiek izdzēsts
        else ++it;
    }
}

int main(){
    list<int> saraksts;
    int ievadit, redo, num, garums, i;
    do{ //cikls koda atkārtošanai
        do{ //garuma pārbaude
            cout<<"Ievadiet saraksta garumu: ";
            cin>>garums;
            if(garums<=0)cout<<"Slikts ievads, ievadiet veselo pozitiivo skaitli!"<<endl;
        }while(garums<=0);
        
        cout<<"Ievadiet 0, ja negribat ievadiit elementus."<<endl;
        cin >> ievadit;
        i=0;
        if(ievadit!=0){ 
            cout<<endl<<"Ievadiet elementus: ";
            while(i<garums){ //elementu ievadīšana no klaviatūras
                cin>>num;
                saraksts.push_back(num);
                i++;
            }
        }
        else{
            srand(time(0));
            cout<<endl<<"Tika izveidots saraksts: ";
            while(i<garums){ //elementu izveidošana ar randomu
                num = rand() % 101;
                saraksts.push_back(num);
                cout<<num<<" ";
                i++;
            }
            cout<<endl;
        }
        ScaredOfEvenElements(saraksts);
        for(auto s:saraksts)
            cout<<s<<" "; //rezultāta izvadīšana
        saraksts.clear(); //saraksta iznicināšana
        cout<<endl<<"Turpinaat(nenulles ievads) vai beigt(0)?"<<endl;
        cin>>redo;
    }while(redo);
}