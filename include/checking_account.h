#include <iostream>
#include "account_holder.h"

#pragma once

class CheckingAccount {
private:
  AccountHolder *accountHolder;
  int           id;
  double        balance;

public:
  CheckingAccount(AccountHolder *, int, double);
  ~CheckingAccount();

  const int getId();
  double    getBalance();
  bool      withdrawExceeds(double);
  void      withdraw(double);
  void      deposit(double);

  AccountHolder *getAccountHolder();
};

