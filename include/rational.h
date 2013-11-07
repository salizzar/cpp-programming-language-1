#include <iostream>

#pragma once

class Rational {
private:
  int a, b;
  int factor(int, int, int);

public:
  Rational();
  Rational(int, int);

  void display();
  void reduced();

  bool      operator >  (Rational);
  bool      operator >= (Rational);
  bool      operator <  (Rational);
  bool      operator <= (Rational);
  bool      operator == (Rational);

  Rational  operator + (Rational);
  Rational  operator - (Rational);
  Rational  operator * (Rational);
  Rational  operator / (Rational);

  int mcd(int, int);
  int lcm(int, int);
};

