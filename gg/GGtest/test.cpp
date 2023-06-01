/* Jūlija Tatarinceva, jt22005
G19. Uzrakstīt funkciju, kas no saraksta izmet tos elementus, 
tieši aiz kuriem sarakstā seko elementi, kuru vērtība ir pāra skaitlis.
Programma izveidota: 2023/03/02 */

#include <iostream>
#include <list>
#include <time.h>
#include <sstream>
#include <cstring>
using namespace std;
#include "../GGmain/G19-vienvirziena_saistits_saraksts.cpp"

//Tests A - tukšs saraksts
bool test_A() {
    elem* test = NULL;
    try {
        RemoveBeforeEvenElements(test, test);
    } catch (int issue) {
        if (issue == -1) return true;
    }
    return false;
}

//Tests B - saraksts ar vienu elementu
bool test_B() {
    elem* last; elem* first; elem* test = new elem;
    test->num = 1;
    test->next = NULL;
    first=last=test;
    RemoveBeforeEvenElements(test, test);
    if(first->num==1 && first->next == NULL) return true; //tiek parbaudīts, vai elements izmainās
    else return false;
}

//Tests C - saraksts ar vairākiem elementiem
bool test_C() {
    const int test_array_length = 6;
    const int result_array_length = 4;
    int test_input[test_array_length] = {2, 3, 4, 6, 7, 9}; //saraksts sākumā
    int test_output[result_array_length] = {2, 6, 7, 9}; //sagaidāms rezultāts

    elem* last; elem* first; elem* test = new elem;
    test->num = test_input[0];
    first=last=test;
    for(int i = 1; i<test_array_length; i++){
        elem* p = new elem;
        p->num = test_input[i];
        p->next=NULL;
        last->next=p;
        last=p;
    }

    RemoveBeforeEvenElements(test, test);

    int j=0; elem* i; //skaitītāji ciklam
    for(i=first; i; i=i->next){  //tiek parbaudīts, vai rezultātā tiek izveidots pareizs saraksts
        if(j == result_array_length) return false;
        if (i->num != test_output[j]) return false;
        else j++;
    }
    return true;
}

int main(){
    cout << "Ruupiigi testeejam..."<<endl;
    if (!test_A()) cout << "Test_A failed." << endl;
    else cout << "Test_A passed." << endl;
    if (!test_B()) cout << "Test_B failed." << endl;
    else cout << "Test_B passed." << endl;
    if (!test_C()) cout << "Test_C failed." << endl;
    else cout << "Test_C passed." << endl;    test_A();
    cout << "Testeesana pabeigta!"<<endl;   
}
