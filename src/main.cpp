#include "main.h"

using namespace std;

void showMenu(){
  cout << "\n-------------------------";
  cout << "\n1 - Bank Program";
  cout << "\n2 - Rational Program";
  cout << "\n9 - Exit Program";
  cout << "\n-------------------------";
  cout << "\n";
  cout << "\nEnter a option: ";
}

int main(){
  BankProgram     bank;
  RationalProgram rational;

  int option;

  do {
    showMenu();

    cin >> option; cout << "\n";

    switch (option){
      case 1:
        bank.run();
        break;

      case 2:
        rational.run();
        break;

      case 9:
        break;

      default:
        Util::clearInvalidOption();

        cout << "\nInvalid option, try again.\n";
    }

    cout << "\n";
  } while (option != 9);

  cin.ignore();
}

