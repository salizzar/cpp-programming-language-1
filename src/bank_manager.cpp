#include "bank_manager.h"

using namespace std;

BankManager::BankManager(){
}

void BankManager::createCheckingAccount(){
  if (bank.accountLimitReached()){
    cout << "\nCannot add accounts, bank is full. Skipping.";
    return;
  }

  int accountId;

  accountId = this->promptAccountId();
  if (bank.accountAlreadyExists(accountId)){
    cout << "\nAccount ID already exists. Skipping.";
    return;
  }

  char accountHolderName[30];
  cout << "\nEnter Account Holder name: "; cin.getline(accountHolderName, 30);
  AccountHolder *holder = new AccountHolder(accountHolderName);

  double accountBalance = this->promptAccountBalance();

  CheckingAccount *account;
  bool isSpecialAccount = this->promptSpecialAccount();

  if (isSpecialAccount){
    double limit = this->promptAccountLimit();
    double interestRate = this->promptAccountInterestRate();

    bank.addSpecialCheckingAccount(holder, accountId, accountBalance, limit, interestRate);
  } else {
    bank.addCheckingAccount(holder, accountId, accountBalance);
  }
}

void BankManager::updateAccount(){
  CheckingAccount *account = this->findCheckingAccount();
  if (account == NULL){
    cout << "\nAccount not found. Skipping.";
    return;
  }

  AccountHolder *holder = account->getAccountHolder();

  char holderName[30];
  cout << "\nEnter Account Holder name: "; cin.getline(holderName, 30);

  holder->setName(holderName);

  cout << "\nSuccessfully updated Account Holder.";
}

void BankManager::withdrawAccount(){
  CheckingAccount *account = this->findCheckingAccount();
  if (account == NULL){
    cout << "\nAccount not found. Skipping.";
    return;
  }

  double withdraw;

  cout << "\nEnter withdraw value: "; cin >> withdraw;
  if (account->withdrawExceeds(withdraw)){
    cout << "\nWithdraw exceeds limit, aborting.";
    return;
  }

  account->withdraw(withdraw);

  cout << "\nSuccessfully performed withdraw.";
}

void BankManager::depositAccount(){
  CheckingAccount *account = this->findCheckingAccount();
  if (account == NULL){
    cout << "\nAccount not found. Skipping.";
    return;
  }

  double value;

  cout << "\nEnter deposit value: "; cin >> value;

  if (bank.depositExceedsBacenLimit(account, value)){
    cout << "\nDeposit exceeds BACEN limit. Skipping.";
    return;
  }

  account->deposit(value);

  cout << "\nSuccessfully performed deposit.";
}

void BankManager::checkAccountBalance(){
  int accountId = this->promptAccountId();
  bank.showCheckingAccount(accountId);
}

void BankManager::deleteAccount(){
  CheckingAccount *account = this->findCheckingAccount();
  if (account == NULL){
    cout << "\nAccount not found. Skipping.";
    return;
  }

  int accountId = account->getId();

  if (!bank.deleteCheckingAccountById(accountId)){
    cout << "\nFailed to remove a account! :(";
  } else {
    cout << "\nSuccessfully removed account id " << accountId << ".";
  }
}

void BankManager::setBacenLimit(){
  cout << "\nCurrrent BACEN LIMIT: " << Bank::BACEN_LIMIT;

  double newLimit = -1.0;
  do {
    cout << "\nSet new limit: "; cin >> newLimit;
    if (newLimit < 0.0)
      cout << "\nInvalid limit, try again.";
  } while (newLimit < 0.0);

  cin.ignore();

  Bank::BACEN_LIMIT = newLimit;

  cout << "\nSuccessfully setted BACEN limit.";
}

void BankManager::upgradeAccount(){
  int accountId = this->promptAccountId();

  if (!bank.accountAlreadyExists(accountId)) {
    cout << "\nAccount not found. Skipping.";
    return;
  }

  double limit = this->promptAccountLimit();
  double interestRate = this->promptAccountInterestRate();

  bank.upgradeAccount(accountId, limit, interestRate);

  cout << "\nAccount upgraded.";
}

void BankManager::clearInvalidOption(){
   if (cin.fail()){
     char dummy[255];
     cin.clear();
     cin >> dummy;
   }
}

CheckingAccount *BankManager::findCheckingAccount(){
  int accountId = this->promptAccountId();
  return bank.getCheckingAccountById(accountId);
}

int BankManager::promptAccountId(){
  int accountId;

  do {
    cout << "\nEnter Account Id: "; cin >> accountId;

    if (accountId <= 0)
      cout << "\nInvalid Id, try again.";
  } while (accountId <= 0);

  cin.ignore();

  return accountId;
}

double BankManager::promptAccountBalance(){
  double accountBalance;

  do {
    cout << "\nEnter Account Balance: "; cin >> accountBalance;

    if (accountBalance <= 0.0)
      cout << "\nInvalid Balance, try again.";
  } while (accountBalance <= 0.0);

  cin.ignore();

  return accountBalance;
}

bool BankManager::promptSpecialAccount(){
  char option[1];
  bool yes, no;

  do {
    cout << "\nIs Special Account (y/n): "; cin >> option;
    yes = strcmp(option, "y") == 0;
    no  = strcmp(option, "n") == 0;
  } while (!yes && !no);

  cin.ignore();

  return yes;
}

double BankManager::promptAccountLimit(){
  double value;

  do {
    cout << "\nEnter Account Limit: "; cin >> value;

    if (value <= 0.0)
      cout << "\nInvalid Limit, try again.";
  } while (value <= 0.0);

  return value;
}

double BankManager::promptAccountInterestRate(){
  double value;

  do {
    cout << "\nEnter Account Interest Rate: "; cin >> value;

    if (value <= 0.0)
      cout << "\nInvalid Interest Rate, try again.";
  } while (value <= 0.0);

  return value;
}

