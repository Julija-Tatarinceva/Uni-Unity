/* Jūlija Tatarinceva, jt22005
G19. Uzrakstīt funkciju, kas no saraksta izmet tos elementus, 
tieši aiz kuriem sarakstā seko elementi, kuru vērtība ir pāra skaitlis.
Programma izveidota: 2023/03/02 */
#include <iostream>
#include <time.h>
#include <sstream>
#include "G19-list.h"
using namespace std;

void RemoveBeforeEvenElements(elem*&prev, elem *&root){
    if(!root) throw -1;
    bool first = false;
    if(root==prev)first = true;
    if(root->next && root->next->num%2==0){
        elem* p = root;
        root=root->next;
        delete p;
        if(root->next){
            if(first) RemoveBeforeEvenElements(root, root);
            else RemoveBeforeEvenElements(prev, root);
        }
    }
    else if(root->next) RemoveBeforeEvenElements(root, root->next);
}

void PrintList(elem *&first){
    elem *p = first;
    while(p){ //rezultāta izavdīšana un saraksta iznīcināšana
        cout<<p->num<<" ";
        first = first->next;
        delete p;
        p=first;
    }
}

elem* CreateList(std::istream& input_stream){ //input stream, lai šo funkciju arī būtu iespējams notestet ar gatavu ievadu
    int ievadit, redo, num, garums, i;
    elem *first = NULL, *last;
    cout<<"Ievadiet saraksta garumu: ";
    input_stream>>garums;
    if(garums<=0){cout<<"Slikts ievads, ievadiet veselo pozitiivo skaitli!"<<endl; throw -1; return NULL;}
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
    cout<<"removing";
    return first;
}
