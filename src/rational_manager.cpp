#include "rational_manager.h"

using namespace std;

RationalManager::RationalManager(){
  this->rational = Rational();
}

void RationalManager::create(){
  this->rational = this->getRational();
}

void RationalManager::show() { this->show(this->rational); }
void RationalManager::show(Rational number){
  cout << "\n";
  cout << "\nnormal:  " ; number.display();
  cout << "\nreduced: " ; number.reduced();
}

void RationalManager::checkIsGreater(){
  Rational other = this->getRational();
  bool greater = this->rational > other;

  this->show(this->rational) ; this->show(other);
  cout << "\n" << (greater ? "is greater than " : "is not greater than ");
}

void RationalManager::checkIsLower(){
  Rational other = this->getRational();
  bool greater = this->rational < other;

  this->show(this->rational) ; this->show(other);
  cout << "\n" << (greater ? "is lower than " : "is not lower than ");
}

void RationalManager::checkIsEqual(){
  Rational other = this->getRational();
  bool greater = this->rational == other;

  this->show(this->rational) ; this->show(other);
  cout << "\n" << (greater ? "is equal to " : "is not equal to ");
}

void RationalManager::sum(){
  Rational other = this->getRational();
  Rational result = this->rational + other;

  this->show(this->rational) ; this->show(other) ; this->show(result);
}

void RationalManager::subtract(){
  Rational other = this->getRational();
  Rational result = this->rational - other;

  this->show(this->rational) ; this->show(other) ; this->show(result);
}

void RationalManager::multiply(){
  Rational other = this->getRational();
  Rational result = this->rational * other;

  this->show(this->rational) ; this->show(other) ; this->show(result);
}

void RationalManager::divide(){
  Rational other = this->getRational();
  Rational result = this->rational / other;

  this->show(this->rational) ; this->show(other) ; this->show(result);
}

Rational RationalManager::getRational(){
  int a, b;

  cout << "\nDigit numerator:   "; cin >> a;
  cout << "\nDigit denominator: "; cin >> b;

  return Rational(a, b);
}

