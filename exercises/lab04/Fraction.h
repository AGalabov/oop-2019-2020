#include<iostream>

class Fraction{
  long long num;
  long long denom;

  long long gcd(long long, long long);

  public:
  Fraction();
  Fraction(long long, long long);
  
  void simplify();

  long long getNumerator();
  long long getDenominator();

  void setNumerator(long long);
  void setDenominator(long long);
  
  bool operator> (const Fraction&) const;
  bool operator>= (const Fraction&) const;
  bool operator== (const Fraction&) const;
  bool operator!= (const Fraction&) const;
  bool operator<= (const Fraction&) const;
  bool operator< (const Fraction&) const;
 
  Fraction operator+ (const Fraction&) const;
  Fraction operator- (const Fraction&) const;
  Fraction operator* (const Fraction&) const;
  Fraction operator/ (const Fraction&) const;
 
  friend std::ostream& operator << (std::ostream&, const Fraction&);

  friend Fraction operator*(long long, const Fraction&);
};