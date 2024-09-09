#include "functions.h"

void printArr(arrayStruct arr1) {
  cout << "ARRAY: \n";
  int counter = 0;
  for (int i = 0; i < arr1.Size; i++) {
    cout << arr1.arr[i] << " ";
    if (counter % 10 == 9) {
      cout << endl;
    }
    counter++;
  }
  cout << endl << endl;
}

// PRE: User assign int x, array a initialized
// POST: Search array for int x, return index if number present, else return -1
int findInt(arrayStruct arr1, int x) {
  for (int i = 0; i < arr1.Size; i++) {
    if (arr1.arr[i] == x) {
      return i;
    }
  }
  return -1;
}

// PRE: User assign int r (replace), array initialized, & index of desired int
// to replace POST: Modify value of an integer in array at specific index
void replaceInt(arrayStruct arr1, int r, int i) {
  // FIXME -- pass array by reference? will it change without?
  cout << "\nReplaced value: " << arr1.arr[i] << endl;
  cout << "\nNew value: " << r << endl << endl;
  arr1.arr[i] = r;
}

// PRE: Array initialized, user assigned int add
// POST: Check if space to add on array, if space then add int a to end of array
arrayStruct addInt(arrayStruct arr1, int a) {
  int i = 0;
  // int arrays initialized to 0
  while (arr1.arr[i] != 0) {
    i++;
  }
  if (i == arr1.Capacity) { // if array is full
    arrayStruct newArr;
    newArr.Capacity = 2 * arr1.Capacity;
    newArr.Size = arr1.Size;
    for (int j = 0; j < arr1.Size; j++) { // copy over old array
      newArr.arr[j] = arr1.arr[j];
    }
    delete[] arr1.arr;     // deallocate the old array
    arr1.arr = newArr.arr; // point arr to the new, larger array
  }
  arr1.Size++;
  arr1.arr[i] = a;
  return arr1;
}

// PRE: Array initialized, user assigned delete indx
// POST: Removes value at int i, error message if no value at indx
arrayStruct removeInt(arrayStruct arr1, int i) {
  // CHECK if indx in arr1
  if (i < 0 || i >= arr1.Size) {
    cout << "Error: Invalid index to remove.\n";
    return arr1; // Return the original array if the index is invalid
  }

  arrayStruct newArr;
  newArr.Capacity = arr1.Capacity;
  newArr.Size = arr1.Size - 1;
  int newIndx = 0, oldIndx = 0;
  while (oldIndx < arr1.Size) {
    // SKIP element at index i
    if (newIndx == i) {
      oldIndx++;
      i = -1;
      continue;
    }
    newArr.arr[newIndx] = arr1.arr[oldIndx];
    newIndx++;
    oldIndx++;
  }
  delete[] arr1.arr;     // deallocate the old array
  arr1.arr = newArr.arr; // point arr to the new, larger array
  arr1.Size--;
  return arr1;
}
