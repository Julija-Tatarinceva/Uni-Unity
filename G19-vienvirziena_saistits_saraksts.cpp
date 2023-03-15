/* Jūlija Tatarinceva, jt22005
G19. Uzrakstīt funkciju, kas no saraksta izmet tos elementus, 
tieši aiz kuriem sarakstā seko elementi, kuru vērtība ir pāra skaitlis.
Programma izveidota: 2023/03/02 */
#include <iostream>
#include <time.h>
using namespace std;

struct elem{
    int num;
    elem *next = NULL;
};

void ScaredOfEvenElements(elem *&prev, elem *&root, elem *&after){
    if(after->num%2==0){
        if(root==prev) prev = after; //ja tiek pārbaudīts pirmais elements, tad iepriekšējām (kura nav) nevajag veidot jaunu norādi
        else prev->next = after; //citādi iepriekšējām elementam jāizvedo norāde uz elementu, kas sēko pēc tā, kurš tiks izdzsēsts
        delete root;
        if(after->next)ScaredOfEvenElements(prev, after, after->next);
    }
    else if(after->next)ScaredOfEvenElements(root, after, after->next);
}

int main(){
    int ievadit, redo, num, garums, i;
    do{ //cikls koda atkārtošanai
        elem *first = NULL, *last;
        #pragma region Input //man vienkārši nepatīk skatīties uz šo milzīgo daļu :D 
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
            for(i=0; i<garums; i++){ //elementu ievadīšana no klaviatūras
                elem *p = new elem;
                cin>>p->num;
                if(!first) first = last = p;
                else{
                    last->next = p;
                    last=p;
                }
            }
        }
        else{
            srand(time(0));
            cout<<endl<<"Tika izveidots saraksts: ";
            for(i=0; i<garums; i++){ //elementu izveidošana ar randomu
                elem *p = new elem;
                num = rand()%101;
                cout<<num<<" ";
                p->num = num;
                if(!first) first = last = p;
                else{
                    last->next = p;
                    last = p;
                }
            }
        }
        #pragma endregion
        ScaredOfEvenElements(first, first, first->next);
        cout<<endl;
        elem *p = first;
        while(p){ //rezultāta izavdīšana un saraksta iznīcināšana
            cout<<p->num<<" ";
            first = first->next;
            delete p;
            p=first;
        }
        cout<<endl<<"Turpinaat(nenulles ievads) vai beigt(0)?"<<endl;
        cin>>redo;
    }while(redo);
}