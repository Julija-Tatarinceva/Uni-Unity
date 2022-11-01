#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include <stack>
using namespace std;
class Nstack {
    private:
         stack<int> Numbers;
    public:
        Nstack();
        ~Nstack();
        void Psh();
        int Pp();
        void HowMany();
        void Tops();
        void isEmpty();
        void isFull();
};
#endif
