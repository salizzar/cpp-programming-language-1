#include "special_checking_account.h"

using namespace std;

SpecialCheckingAccount::SpecialCheckingAccount(
    AccountHolder *accountHolder, int id,
    double balance, double limit, double interestRate)
    :CheckingAccount::CheckingAccount(accountHolder, id, balance)
{
  this->limit = limit;
  this->interestRate = interestRate;
}

SpecialCheckingAccount::SpecialCheckingAccount(
    CheckingAccount *account,
    double limit,
    double interestRate)
{
  // dirty clone
  this->accountHolder = new AccountHolder(account->getAccountHolder());
  this->id = account->getId();
  this->balance = account->getBalance();
  this->limit = limit;
  this->interestRate = interestRate;
}


double SpecialCheckingAccount::getLimit(){ return this->limit; }
double SpecialCheckingAccount::getInterestRate(){ return this->interestRate; }

void SpecialCheckingAccount::show(){
  CheckingAccount::show();

  cout << "\nLimit:               " << this->limit;
  cout << "\nInterest Rate:       " << this->interestRate;
  cout << "\nAvailable:           " << this->balance + this->limit;
}

bool SpecialCheckingAccount::withdrawExceeds(double value){
  return this->balance + this->limit - value < 0.0;
}

