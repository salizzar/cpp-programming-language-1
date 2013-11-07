#include "rational.h"

using namespace std;

Rational::Rational() : a(1), b(1) {}
Rational::Rational(int numerator, int denominator) : a(numerator), b(denominator) {}

void Rational::display(){
  cout << this->a << "/" << this->b;
}

void Rational::reduced(){
  int mcd = this->mcd(this->a, this->b);

  int a = this->a / mcd;
  int b = this->b / mcd;

  cout << a << "/" << b;
}

bool Rational::operator > (Rational other){
  return this->a / this->b < other.a / other.b;
}

bool Rational::operator >= (Rational other){
  return this->a / this->b <= other.a / other.b;
}

bool Rational::operator < (Rational other){
  return this->a / this->b > other.a / other.b;
}

bool Rational::operator <= (Rational other){
  return this->a / this->b >= other.a / other.b;
}

bool Rational::operator == (Rational other){
  return this->a / this-> b == other.a / other.b;
}

Rational Rational::operator + (Rational other){
  int lcm = this->lcm(this->b, other.b);

  int x = this->factor(lcm, this->a, this->b);
  int y = this->factor(lcm, other.a, other.b);

  return Rational(x + y, lcm);
}

Rational Rational::operator - (Rational other){
  int lcm = this->lcm(this->b, other.b);

  int x = this->factor(lcm, this->a, this->b);
  int y = this->factor(lcm, other.a, other.b);

  return Rational(x - y, lcm);
}

Rational Rational::operator * (Rational other){
  int x = this->a * other.a;
  int y = this->b * other.b;

  return Rational(x, y);
}

Rational Rational::operator / (Rational other){
  int x = this->a * other.b;
  int y = this->b * other.a;

  return Rational(x, y);
}

int Rational::mcd(int a, int b){
  int r = b % a;

  while (r != 0){
    r = a % b;
    a = b;
    b = r;
  }

  return a;
}

int Rational::lcm(int a, int b){
  int i = min(a, b);

  while (i % a != 0 || i % b != 0)
    i++;

  return i;
}

int Rational::factor(int lcm, int a, int b){
  return (lcm / b) * a;
}

