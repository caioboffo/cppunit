#ifndef MONEY_H__
#define MONEY_H__

#include <string>
#include <iostream>

class IncompatibleMoneyError : public std::runtime_error
{
public:
  IncompatibleMoneyError() : std::runtime_error( "Incompatible moneys" ) {}

};

class Money
{
public:
  Money( double amount, std::string currency )
    : m_amount( amount )
    , m_currency( currency ) {}

  double getAmount() const
  {
    return m_amount;
  }

  std::string getCurrency() const
  {
    return m_currency;
  }

  bool operator ==( const Money &other ) const
  {
    return m_amount == other.m_amount &&
           m_currency == other.m_currency;
  }

  bool operator !=( const Money &other ) const
  {
    return !(*this == other);
  }

  Money &operator +=( const Money &other )
  {
    if ( m_currency != other.m_currency )
      throw IncompatibleMoneyError();

    m_amount += other.m_amount;
    return *this;
  }

private:
  double m_amount;
  std::string m_currency;
};

inline std::ostream &operator <<( std::ostream &os, const Money &value )
{
  return os << "Money< value = " << value.getAmount()
            << "; currency = "  << value.getCurrency() << ">";
}

#endif
