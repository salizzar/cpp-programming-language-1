#include <iostream>
#include <cstring>

#pragma once

class AccountHolder {
private:
  char name[];

public:
  AccountHolder(char[]);

  char* getName();
  void setName(char[]);
};

