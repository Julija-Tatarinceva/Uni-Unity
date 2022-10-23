#ifndef __PROGRAM_H__
#define __PROGRAM_H__
#include <iostream>
#include <stack>
using namespace std;
//#define SIZE 5
class Nstack {       // The class
    
    public:
        Nstack();
        ~Nstack();
        void Psh();
        void Pp();
        void HowMany();
        void Tops();
        void isEmpty();
        void isFull();
};
static stack<int> Numbers;
#endif