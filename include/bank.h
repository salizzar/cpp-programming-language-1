#include <iostream>
#include "checking_account.h"

#pragma once

const int BANK_MAX_ACCOUNTS = 5;

class Bank {
private:
  CheckingAccount *accounts[BANK_MAX_ACCOUNTS];

  int   getFreeSlot();
  void  deleteCheckingAccountByIndex(int);

public:
  Bank();
  ~Bank();

  bool  addCheckingAccount(CheckingAccount *);
  bool  deleteCheckingAccountById(int);
  bool  accountAlreadyExists(int);
  bool  accountLimitReached();
  bool  depositExceedsBacenLimit(CheckingAccount *, double);

  static double BACEN_LIMIT;

  CheckingAccount *getCheckingAccountById(int);
};

