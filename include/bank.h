#include <iostream>
#include "checking_account.h"
#include "special_checking_account.h"
#include "util.h"

#pragma once

const int BANK_MAX_ACCOUNTS = 5;

class Bank {
private:
  CheckingAccount **accounts;

  int   getFreeSlot();
  void  deleteCheckingAccountByIndex(int);

public:
  Bank();
  ~Bank();

  bool  addCheckingAccount(AccountHolder*, int, double);
  bool  addSpecialCheckingAccount(AccountHolder*, int, double, double, double);
  bool  deleteCheckingAccountById(int);
  bool  accountAlreadyExists(int);
  bool  accountLimitReached();
  bool  depositExceedsBacenLimit(CheckingAccount *, double);
  void  showCheckingAccount(int);
  void  upgradeAccount(int, double, double);

  static double BACEN_LIMIT;

  CheckingAccount *getCheckingAccountById(int);
};

