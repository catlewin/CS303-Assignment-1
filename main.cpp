// NAME: Cat Lewin
// CS303 Assignment 1

#include "functions.h"
#include <fstream>
#include <iostream>
#include <limits>

using namespace std;

int main() {
  // OPEN file
  ifstream inFile;
  inFile.open("A1input.txt");
  // IF !OPEN
  if (!inFile.is_open()) {
    cout << "Unable to open \"input.txt\" file\n";
    return 0;
  }
  // READ FILE & LOAD ARRAY
  arrayStruct myArray;
  int x;
  while (inFile.good()) {
    int i = 0;
    while (i < 100) {
      // LOAD ARRAY
      inFile >> x;
      myArray.arr[i] = x;
      i++;
    }
    break;
  }
  // CHECK ARRAY
  printArr(myArray);

  int choice = -1;
  while (choice != 0) {
     // PRINT options
     cout << "ARRAY OPTIONS: \n"
            "1. Check if integer present in array\n"
            "2. Modify integer in array\n"
            "3. Add integer to end of array\n"
            "4. Remove integer from array\n"
            "5. Display current array\n"
            "0. QUIT\n";
     // GET choice
     while (true) {
         try {
            cout << "\nEnter choice: (options 1-5, 0 to QUIT) ";
            cin >> choice;
            if (cin.fail()) {
               throw runtime_error("Invalid option. Must be 0, 1, 2, 3, 4, or 5.\n");
               }
            break;
            }
         catch (const runtime_error& e) {
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
         }
      }
     cout << endl << endl;
     if (choice == 0) {
        break;
     }
     else if (choice == 1) {
        cout << "Enter the integer you would like to check is present in the array: ";
        int num, indx;
        // CHECK input, must be INTEGER
        while (true) {
           try {
              cin >> num;
              if (cin.fail()) {
                 throw runtime_error("Invalid input. Please enter an integer.");
                 }
              break;
              }
           catch (const runtime_error& e) {
              cout << e.what() << endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              continue;
              }
           }
        indx = findInt(myArray, num);
        if (indx == -1) {
           cout << endl << num << " is not present in the array\n";
           }
        else {
           cout << endl << num << " is present in the array at index " << indx << endl << endl;
           }
        }
     else if (choice == 2) {
        cout << "Enter the index of the integer you would like to replace: ";
        int indx, replace;
        while (true) {
             try {
                cin >> indx;
                if (cin.fail() || indx < 0) {
                   throw runtime_error("Invalid input. Please enter a positive integer.");
                   }
                break;
                }
             catch (const runtime_error& e) {
                cout << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
             }
          }
        cout << endl << "Enter the integer you would like to replace it with? ";
        while (true) {
            try {
               cin >> replace;
               if (cin.fail()) {
                  throw runtime_error("Invalid input. Please enter an integer.");
               }
               break;
            }
            catch (const runtime_error& e) {
               cout << e.what() << endl;
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               continue;
            }
         }
        replaceInt(myArray, replace, indx);
     }
     else if (choice == 3) {
        cout << "Enter the integer you would like to add to the array: ";
        int newInt;
        while (true) {
           try {
              cin >> newInt;
              if (cin.fail()) {
                 throw runtime_error("Invalid input. Please enter an integer.");
                 }
              myArray = addInt(myArray, newInt);
              break;
              }
           catch (const runtime_error& e) {
              cout << e.what() << endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              continue;
           }
        }
     }
     else if (choice == 4) {
        cout << "Enter the index of the integer you would like to remove: ";
        int indx;
        while (true) {
            try {
               cin >> indx;
               if (cin.fail() || indx < 0) {
                  throw runtime_error("Invalid input. Please enter a positive integer.");
                  }
               break;
               }
            catch (const runtime_error& e) {
               cout << e.what() << endl;
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n');
               continue;
            }
         }
        cin >> indx;
        myArray = removeInt(myArray, indx);
        }
     else if (choice == 5) {
        printArr(myArray);
        }
     else {
        cout << "Invalid option. Must be 0, 1, 2, 3, 4, or 5.\n\n";
        }
     }

  return 0;
}
