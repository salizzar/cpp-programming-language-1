#include "checking_account.h"

using namespace std;

CheckingAccount::CheckingAccount(AccountHolder *accountHolder, int id, double balance){
  this->accountHolder = accountHolder;
  this->id = id;
  this->balance = balance;
}

CheckingAccount::~CheckingAccount(){
  delete(accountHolder);
}

const int CheckingAccount::getId() {
  return this->id;
}

double CheckingAccount::getBalance(){
  return this->balance;
}

bool CheckingAccount::withdrawExceeds(double value){
  return this->balance - value < 0.0;
}

void CheckingAccount::withdraw(double value){
  this->balance -= value;
}

void CheckingAccount::deposit(double value){
  this->balance += value;
}

AccountHolder *CheckingAccount::getAccountHolder(){
  return this->accountHolder;
}
