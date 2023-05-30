#include <iostream>
#include <list>
#include <time.h>
#include <sstream>
#include <cstring>
using namespace std;
//#include "G19-list.cpp"
#include "../GGmain/G19-vienvirziena_saistits_saraksts.cpp"
//#include "G19-vienvirziena_saistits_saraksts.cpp"

void Test(std::istream& input_stream){
    string a;
    input_stream>>a;
    cout<<a;
}

//pārbaudes, vai funkcija nostrādās ar tukšo sarakstu
void test_A(std::istream& istream) {
    elem* test = NULL;
    try {
        RemoveBeforeEvenElements(test, test);
    } catch (int issue) {
        if (issue != -1) {
            cout << "Test_A failed." << endl;
        } else {
            cout << "Test_A passed." << endl;
        }
    }
}
//trīs testi uz to, kas notiks ar tukšo sarakstu, ar normālu pilnu sarakstu un ar vienu elementu sarakstā
void test_B() {
    elem* last;
    elem* first;
    elem* test = new elem;
    test->num = 1;
    test->next = NULL;
    first=last=test;
    RemoveBeforeEvenElements(test, test);
    if(first->num==1 && first->next == NULL) cout << "Test_B passed." << endl;
    else cout << "Test_B failed." << endl;
}

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
            cout << "Test_C failed." << endl;
            err = true;
            break;
        }
        else j++;
    }
    if (!err) cout << "Test_C passed." << endl;
}

int main(){
    istringstream test1("0"), test2("1 0");
    cout << "Hello! Sending shit.";
    test_A(test1);
    test_B();
    test_C();
}