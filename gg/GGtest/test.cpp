#include <iostream>
#include <list>
#include <time.h>
#include <sstream>
#include <cstring>
using namespace std;
#include "../GGmain/G19-vienvirziena_saistits_saraksts.cpp"

//pārbauda, vai funkcija nostrādās ar tukšo sarakstu
void test_A() {
    elem* test = NULL;
    try {
        RemoveBeforeEvenElements(test, test);
    } catch (int issue) {
        if (issue != -1) {
            cout << "Test_A failed (tukss saraksts)." << endl;
        } else {
            cout << "Test_A passed (tukss saraksts)." << endl;
        }
    }
}

//tests ar vienu elementu sarakstā, tiek parbaudīts, vai elements izmainās
void test_B() {
    elem* last;
    elem* first;
    elem* test = new elem;
    test->num = 1;
    test->next = NULL;
    first=last=test;
    RemoveBeforeEvenElements(test, test);
    if(first->num==1 && first->next == NULL) cout << "Test_B passed (1 elements sarakstaa)." << endl;
    else cout << "Test_B failed (1 elements sarakstaa)." << endl;
}

//tests ar sarakstu no 6 elementiem, tiek parbaudīts, vai funkcija pareizi izmet elementus, tieši aiz kuriem seko pāra skaitlis
void test_C() {
    int test_input[6] = {2, 3, 4, 6, 7, 9};
    int test_output[4] = {2, 6, 7, 9};

    elem* last;
    elem* first;
    elem* test = new elem;
    test->num = test_input[0];
    first=last=test;
    for(int i = 1; i<6; i++){
        elem* p = new elem;
        p->num = test_input[i];
        p->next=NULL;
        last->next=p;
        last=p;
    }

    RemoveBeforeEvenElements(test, test);

    int j=0; bool err = false;
    elem* i;
    for(i=first; i; i=i->next){
        if (i->num != test_output[j]){
            cout << "Test_C failed (vairaaki elementi sarakstaa)." << endl;
            err = true;
            break;
        }
        else j++;
    }
    if (!err) cout << "Test_C passed (vairaaki elementi sarakstaa)." << endl;
}

int main(){
    cout << "Ruupiigi testeejam..."<<endl;
    test_A();
    test_B();
    test_C();
    cout << "Testeesana pabeigta!"<<endl;   
}
