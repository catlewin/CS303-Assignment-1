#pragma once

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct arrayStruct {
  int Size = 100, Capacity = 100;
  int *arr = new int[Capacity];
};

// PRE:
// POST: Display elements of array
void printArr(arrayStruct arr1);

// PRE: User assign int x, array a initialized
// POST: Search array for int x, return index if number present, else return -1
int findInt(arrayStruct arr1, int x);

// PRE: User assign int r (replace), array initialized, & index of desired int
// to replace POST: Modify value of an integer in array at specific index,
// display old and new value
void replaceInt(arrayStruct arr1, int replace, int i);

// PRE: Array initialized, user assigned int add
// POST: Check if space to add on array, if space then add int a to end of array
arrayStruct addInt(arrayStruct arr1, int a);

// PRE: Array initialized, user assigned delete indx
// POST: Removes value at int i, error message if no value at indx
arrayStruct removeInt(arrayStruct arr1, int i);
