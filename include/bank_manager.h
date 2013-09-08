#include <iostream>
#include <iomanip>
#include "bank.h"

#pragma once

class BankManager {
private:
  Bank bank;

  void    showCheckingAccountHeader();
  void    showCheckingAccountDetails(CheckingAccount*);
  int     promptAccountId();
  double  promptAccountBalance();

  CheckingAccount *findCheckingAccount();

public:
  BankManager();

  void createCheckingAccount();
  void updateAccount();
  void withdrawAccount();
  void depositAccount();
  void checkAccountBalance();
  void deleteAccount();
  void setBacenLimit();

  void clearInvalidOption();
};

