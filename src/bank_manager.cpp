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
  double  accountBalance;

  accountId = this->promptAccountId();
  if (bank.accountAlreadyExists(accountId)){
    cout << "\nAccount ID already exists. Skipping.";
    return;
  }

  accountBalance = this->promptAccountBalance();

  char accountHolderName[30];
  cout << "\nEnter Account Holder name: "; cin.getline(accountHolderName, 30);

  AccountHolder   *holder   = new AccountHolder(accountHolderName);
  CheckingAccount *account  = new CheckingAccount(holder, accountId, accountBalance);

  bank.addCheckingAccount(account);
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
    cout << "\nWithdraw exceeds balance, aborting.";
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
  CheckingAccount *account = this->findCheckingAccount();
  if (account == NULL){
    cout << "\nAccount not found. Skipping.";
    return;
  }

  this->showCheckingAccountHeader();
  this->showCheckingAccountDetails(account);
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

void BankManager::showCheckingAccountHeader(){
  cout << "\n"
        << "| Account ID "
        << "|             Account Holder Name "
        << "|     Balance "
        << "|";
}

void BankManager::showCheckingAccountDetails(CheckingAccount *account){
  cout << "\n" <<
    "|" << setw(11) << account->getId()                           << " " <<
    "|" << setw(32) << account->getAccountHolder()->getName()     << " " <<
    "|" << setw(12) << account->getBalance()                      << " " <<
    "|";
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

