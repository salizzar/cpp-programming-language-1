#include <iostream>
#include "rational.h"

#pragma once

class RationalManager {
private:
  Rational rational;

  Rational getRational();

public:
  RationalManager();

  void show();
  void show(Rational);

  void create();
  void checkIsGreater();
  void checkIsLower();
  void checkIsEqual();
  void sum();
  void subtract();
  void multiply();
  void divide();
};

