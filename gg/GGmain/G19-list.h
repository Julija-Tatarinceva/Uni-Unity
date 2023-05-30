#ifndef G19_LIST_H
#define G19_LIST_H

#include <iostream>
#include <time.h>
#include <sstream>
using namespace std;

struct elem{
    int num;
    elem *next = NULL;
};
void RemoveBeforeEvenElements(elem *&prev, elem *&root);
elem* CreateList(std::istream& input_stream);

#endif