#include "bank_program.h"

using namespace std;

double Bank::BACEN_LIMIT = 0.0;

void BankProgram::showMenu(){
  cout << "\n-------------------------";
  cout << "\n1 - Create Account";
  cout << "\n2 - Update Account";
  cout << "\n3 - Withdraw from Account";
  cout << "\n4 - Deposit in Account";
  cout << "\n5 - Check Account Balance";
  cout << "\n6 - Delete a Account";
  cout << "\n7 - Set BACEN limit";
  cout << "\n8 - Upgrade Account";
  cout << "\n9 - Exit";
  cout << "\n-------------------------";
  cout << "\n";
  cout << "\nEnter a option: ";
}

void BankProgram::run(){
  BankManager manager;
  int option;

  do {
    showMenu();

    cin >> option; cout << "\n";

    switch (option){
      case 1:
        manager.createCheckingAccount();
        break;

      case 2:
        manager.updateAccount();
        break;

      case 3:
        manager.withdrawAccount();
        break;

      case 4:
        manager.depositAccount();
        break;

      case 5:
        manager.checkAccountBalance();
        break;

      case 6:
        manager.deleteAccount();
        break;

      case 7:
        manager.setBacenLimit();
        break;

      case 8:
        manager.upgradeAccount();

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

