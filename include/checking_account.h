#include <iostream>
#include <iomanip>
#include "account_holder.h"

#pragma once

class CheckingAccount {
protected:
  AccountHolder *accountHolder;
  int           id;
  double        balance;

public:
  CheckingAccount();
  CheckingAccount(AccountHolder *, int, double);
  ~CheckingAccount();

  const int     getId();
  double        getBalance();
  void          withdraw(double);
  void          deposit(double);

  virtual bool  withdrawExceeds(double);
  virtual void  show();

  AccountHolder *getAccountHolder();
};

