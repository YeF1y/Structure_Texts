#ifndef MYMENU_H
#define MYMENU_H

#include <iostream>
#include <windows.h>
#include <algorithm>
#include "MyHash.h"
#include "MyFile.h"
#include "MySort.h"

using namespace std;

void mainMenu(char&);
void showHashLists(HashList[], vector<vector<string>>&);
void showAHashList(HashList[]);
void showHeapSort(HashList[]);
void showMergeSort();

#endif // !MYMENU_H

