
#ifndef MYSORT_H
#define MYSORT_H

#include "MyHash.h"

typedef pair<string, int> PAIR;

void heapSort(HashList, int);
void heapDown(vector<PAIR>&, int, int);
void mergeSort(vector<PAIR>& ,int, int, bool);

#endif // !MYSORT_H
