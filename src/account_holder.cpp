#include "account_holder.h"

using namespace std;

AccountHolder::AccountHolder(char name[]){
  strcpy(this->name, name);
}

AccountHolder::AccountHolder(AccountHolder *holder){
  strcpy(this->name, holder->getName());
}

char *AccountHolder::getName(){
  return this->name;
}

void AccountHolder::setName(char name[]){
  strcpy(this->name, name);
}

void AccountHolder::show(){
  cout << "\nAccount Holder Name: " << this->name;
}

