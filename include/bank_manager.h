#include <iostream>
#include "bank.h"

#pragma once

class BankManager {
private:
  Bank bank;

  void    showCheckingAccountHeader();
  int     promptAccountId();
  double  promptAccountBalance();
  bool    promptSpecialAccount();
  double  promptAccountLimit();
  double  promptAccountInterestRate();

  CheckingAccount *findCheckingAccount();

public:
  BankManager();

  void createCheckingAccount();
  void updateAccount();
  void withdrawAccount();
  void depositAccount();
  void checkAccountBalance();
  void deleteAccount();
  void upgradeAccount();
  void setBacenLimit();

  void clearInvalidOption();
};

