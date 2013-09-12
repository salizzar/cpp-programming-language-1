#include <iostream>
#include <cstring>

#pragma once

class AccountHolder {
private:
  char name[];

public:
  AccountHolder(char[]);
  AccountHolder(AccountHolder*);

  char* getName();
  void setName(char[]);
  void show();
};

