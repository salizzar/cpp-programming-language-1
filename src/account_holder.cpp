#include "account_holder.h"

using namespace std;

AccountHolder::AccountHolder(char name[]){
  strcpy(this->name, name);
}

char *AccountHolder::getName(){
  return this->name;
}

void AccountHolder::setName(char name[]){
  strcpy(this->name, name);
}

