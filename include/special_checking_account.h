#include <iostream>
#include "checking_account.h"

class SpecialCheckingAccount : public CheckingAccount {
private:
  double limit, interestRate;

public:
  SpecialCheckingAccount(AccountHolder*, int, double, double, double);
  SpecialCheckingAccount(CheckingAccount*, double, double);

  double getLimit();
  double getInterestRate();

  void widthdraw(double);
  void deposit(double);

  bool withdrawExceeds(double);
  void show();
};
