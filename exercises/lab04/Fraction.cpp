#include "Fraction.h"

long long Fraction::gcd(long long a, long long b)
{
  long long temp;

  while (b != 0)
  {
    temp = b;
    b = a % b;
    a = temp;
  }

  return a;
}

void Fraction::simplify()
{
  long long gcdNumDenom = gcd(this->num, this->denom);
  this->num /= gcdNumDenom;
  this->denom /= gcdNumDenom;
}

Fraction::Fraction()
{
  this->num = 1;
  this->denom = 1;
}

Fraction::Fraction(long long numerator, long long denominator)
{
  if (denominator == 0)
  {
    std::cout << "Error - attempting to set denominator to 0" << std::endl;
    Fraction();
    return;
  }

  this->num = numerator;
  this->denom = denominator;
  //simplify();
}

long long Fraction::getNumerator()
{
  return this->num;
}

long long Fraction::getDenominator()
{
  return this->denom;
}

void Fraction::setNumerator(long long numerator)
{
  this->num = numerator;
}

void Fraction::setDenominator(long long denominator)
{
  if (denominator == 0)
  {
    std::cout << "Attemption to set denom to 0" << std::endl;
    return;
  }

  this->denom = denominator;
}

bool Fraction::operator==(const Fraction &other) const
{
  return (this->num * other.denom == other.num * this->denom);
}

bool Fraction::operator>=(const Fraction &other) const
{
  return (this->num * other.denom >= other.num * this->denom);
}

bool Fraction::operator<=(const Fraction &other) const
{
  return (this->num * other.denom <= other.num * this->denom);
}

bool Fraction::operator!=(const Fraction &other) const
{
  return !(*this == other);
}

bool Fraction::operator>(const Fraction &other) const
{
  return (*this >= other && *this != other);
}

bool Fraction::operator<(const Fraction &other) const
{
  return (*this <= other && *this != other);
}

Fraction Fraction::operator+(const Fraction &other) const
{
  Fraction result((num * other.denom + other.num * denom), (denom * other.denom));
  result.simplify();

  return result;
}

Fraction Fraction::operator-(const Fraction &other) const
{
  Fraction result((num * other.denom - other.num * denom), (denom * other.denom));
  result.simplify();

  return result;
}

Fraction Fraction::operator*(const Fraction &other) const
{
  Fraction result((num * other.num), (denom * other.denom));
  result.simplify();

  return result;
}

Fraction Fraction::operator/(const Fraction &other) const
{
  Fraction result((num * other.denom), (denom * other.num));
  result.simplify();

  return result;
}

std::ostream &operator<<(std::ostream &os, const Fraction &frac)
{
  if (frac.denom == 1)
  {
    os << frac.num;
  }
  else
  {
    os << frac.num << "/" << frac.denom;
  }

  return os;
}

Fraction operator*(long long multWith, const Fraction &frac)
{
  Fraction result(multWith * frac.num, frac.denom);
  result.simplify();

  return result;
}

void printSeparationLine()
{
  std::cout << "-----------" << std::endl;
}

int main()
{
  Fraction one, oneThird(1, 3), twoSixth(2, 6), threeSeventh(3, 7);

  std::cout << one << " " << oneThird << " " << twoSixth << " " << threeSeventh << std::endl;
  printSeparationLine();

  std::cout << std::boolalpha << oneThird << " equal to " << twoSixth << " : " << (oneThird == twoSixth) << std::endl;
  std::cout << std::boolalpha << one << " equal to " << threeSeventh << " : " << (one == threeSeventh) << std::endl;
  printSeparationLine();

  std::cout << std::boolalpha << oneThird << " greater or equal than " << twoSixth << " : " << (oneThird >= twoSixth) << std::endl;
  std::cout << std::boolalpha << oneThird << " greater than " << threeSeventh << " : " << (oneThird > twoSixth) << std::endl;
  std::cout << std::boolalpha << one << " smaller than " << (oneThird + oneThird) << " : " << (one < (oneThird + oneThird)) << std::endl;
  printSeparationLine();

  std::cout << one << " + "
            << "2 * " << oneThird << " = " << one + 2 * oneThird << std::endl;
  std::cout << "(" << one << " - " << oneThird << " * " << twoSixth << ")"
            << " / " << threeSeventh << " = " << (one - oneThird * twoSixth) / threeSeventh << std::endl;

  return 0;
}