#include "bank.h"

using namespace std;

Bank::Bank(){
  for (int i = 0; i < BANK_MAX_ACCOUNTS; i++)
    this->accounts[i] = NULL;
}

Bank::~Bank(){
  for (int i = 0; i < BANK_MAX_ACCOUNTS; i++){
    if (this->accounts[i] != NULL)
      this->deleteCheckingAccountByIndex(i);
  }
}

bool Bank::addCheckingAccount(CheckingAccount *account){
  int slot = getFreeSlot();
  if (slot == -1)
    return false;

  this->accounts[slot] = account;
  return true;
}

CheckingAccount *Bank::getCheckingAccountById(int accountId){
  CheckingAccount *current;

  for (int i = 0; i < BANK_MAX_ACCOUNTS; i++){
    current = this->accounts[i];

    if (current != NULL && current->getId() == accountId)
      return current;
  }

  return NULL;
}

bool Bank::deleteCheckingAccountById(int accountId){
  CheckingAccount *current;

  for (int i = 0; i < BANK_MAX_ACCOUNTS; i++){
    current = this->accounts[i];

    if (current != NULL && current->getId() == accountId)
      this->deleteCheckingAccountByIndex(i);
  }

  return true;
}

bool Bank::accountAlreadyExists(int accountId){
  CheckingAccount *current;

  for (int i = 0; i < BANK_MAX_ACCOUNTS; i++){
    current = this->accounts[i];

    if (current != NULL && current->getId() == accountId)
      return true;
  }

  return false;
}

bool Bank::depositExceedsBacenLimit(CheckingAccount *account, double value){
  return (Bank::BACEN_LIMIT == 0 ? false : account->getBalance() + value > Bank::BACEN_LIMIT);
}

bool Bank::accountLimitReached(){
  for (int i = 0; i < BANK_MAX_ACCOUNTS; i++){
    if (this->accounts[i] == NULL)
      return false;
  }

  return true;
}

int Bank::getFreeSlot(){
  for (int i = 0; i < BANK_MAX_ACCOUNTS; i++){
    if (this->accounts[i] == NULL)
      return i;
  }

  return -1;
}

void Bank::deleteCheckingAccountByIndex(int index){
  CheckingAccount *account = this->accounts[index];

  delete(account);

  this->accounts[index] = NULL;
}

