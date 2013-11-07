#include "rational_program.h"

using namespace std;

void RationalProgram::showMenu(){
  cout << "\n------------------------------";
  cout << "\n1 - Create a rational number";
  cout << "\n2 - Show rational number";
  cout << "\n3 - Perform rational > another";
  cout << "\n4 - Perform rational < another";
  cout << "\n5 - Perform rational = another";
  cout << "\n6 - Perform rational + another";
  cout << "\n7 - Perform rational - another";
  cout << "\n8 - Perform rational * another";
  cout << "\n9 - Perform rational / another";
  cout << "\n0 - Exit";
  cout << "\n------------------------------";
  cout << "\n";
  cout << "\nEnter a option: ";
}

void RationalProgram::run(){
  RationalManager manager;
  int option;

  do {
    showMenu();

    cin >> option; cout << "\n";

    switch (option){
      case 1:
        manager.create();
        break;

      case 2:
        manager.show();
        break;

      case 3:
        manager.checkIsGreater();
        break;

      case 4:
        manager.checkIsLower();
        break;

      case 5:
        manager.checkIsEqual();
        break;

      case 6:
        manager.sum();
        break;

      case 7:
        manager.subtract();
        break;

      case 8:
        manager.multiply();
        break;

      case 9:
        manager.divide();
        break;

      default:
        Util::clearInvalidOption();

        cout << "\nInvalid option, try again.\n";
    }

    cout << "\n";
  } while (option != 0);

  cin.ignore();
}

