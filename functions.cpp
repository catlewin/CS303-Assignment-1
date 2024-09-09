#include "functions.h"

void printArr(arrayStruct arr1) { // DISPLAY array
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

int findInt(arrayStruct arr1, int x) { // ITERATE over array, if int present, return index, else return -1
  for (int i = 0; i < arr1.Size; i++) {
    if (arr1.arr[i] == x) {
      return i;
    }
  }
  return -1;
}

void replaceInt(arrayStruct arr1, int r, int i) { // REPLACE element at i with r
  cout << "\nReplaced value: " << arr1.arr[i] << endl;
  cout << "\nNew value: " << r << endl << endl;
  arr1.arr[i] = r;
}

arrayStruct addInt(arrayStruct arr1, int a) { // ADD int to array
  int i = 0;
  // int arrays initialized to 0
  while (arr1.arr[i] != 0) { // FIND index of the END of the array
    i++;
  }
  if (i == arr1.Capacity) { // IF array is FULL, CREATE new array & COPY over old
    arrayStruct newArr;
    newArr.Capacity = 2 * arr1.Capacity;
    newArr.Size = arr1.Size;
    for (int j = 0; j < arr1.Size; j++) { // copy over old array
      newArr.arr[j] = arr1.arr[j];
    }
    delete[] arr1.arr;     // DEALLOCATE the old array
    arr1.arr = newArr.arr; // point arr to the new, larger array
  }
  // ADD a to end of array
  arr1.Size++;
  arr1.arr[i] = a;
  return arr1;
}

arrayStruct removeInt(arrayStruct arr1, int i) { // REMOVE element from array
  // CHECK if indx in arr1
  if (i < 0 || i >= arr1.Size) {
    cout << "Error: Invalid index to remove.\n";
    return arr1; // Return the original array if the index is invalid
  }
  // CREATE NEW ARRAY
  arrayStruct newArr;
  newArr.Capacity = arr1.Capacity;
  newArr.Size = arr1.Size - 1;
  int newIndx = 0, oldIndx = 0;
  // COPY old array, without element at index i
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
