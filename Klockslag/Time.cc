#include "Time.h"
#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include <iostream>

Time::Time()
  : hour{}, minute{}, second{}
{
}

Time::Time(int h,
	   int m,
	   int s)
 : hour{h}, minute{m}, second{s}head
{
  ValidTime();
}

Time::Time(std::string const& t)
  : hour{}, minute{}, second{}
{
  char divide;
  std::stringstream ts {t};  
  ts >> hour >> divide >> minute >> divide >> second;
  ValidTime();
}

void Time::ValidTime() const
{
  if ( hour > 23 || hour < 0 ||
       minute > 59 || minute < 0 ||
       second > 59 || second < 0 )
    {
      throw std::logic_error{"Fel tid!"};
    }
}

bool Time::is_am() const
{
  return ( hour < 12 );
}

std::string Time::to_string( bool const& ampm ) const
{
  
  std::stringstream ss;
  int temp{hour};
  if ( ampm == true && is_am() == false )
    {
      temp = temp - 12;
    }
  ss << std::setw(2) << std::setfill('0') << temp << ":"
     << std::setw(2) << std::setfill('0') << minute << ":"
     << std::setw(2) << std::setfill('0') << second;
  
  if ( ampm ==true )
    {
      if ( is_am() == true )
	{
	  ss << std::setw(3) << std::setfill(' ') << "am";
	}
      else
	{
	  ss << std::setw(3) << std::setfill(' ') << "pm";
	}
    }     
  std::string str = ss.str();
  return str;
}

Time operator +( int const& lhs, Time const& rhs )
{
  
  return rhs + lhs;
}

Time Time::operator +( int const& rhs ) const
{
  if ( rhs < 0 )
    {
      return Time::operator -( -rhs );
    }
  Time temp(*this);
  temp.second += rhs;

  if ( temp.second > 59 )
    {
      temp.minute += ( temp.second / 60 );
      temp.second %= 60;
    }

  if ( temp.minute > 59 )
    {
      temp.hour += ( temp.minute / 60 );
      temp.minute %= 60;
    }

  if ( temp.hour > 23 )
    {
      temp.hour %= 24;
    }
  return temp;
}

Time Time::operator -( int const& rhs ) const
{
  if ( rhs < 0 )
    {
      return Time::operator +( -rhs );
    }
  Time temp(*this);
  temp.second -= rhs;
  
  if ( temp.second < 0 )
    {
      temp.minute += ( temp.second / 60 ) - 1;
      temp.second = 60 + ( temp.second % 60 );
      if ( 60 + ( temp.second % 60 ) == 60 )
	{
	  temp.second = 0;
	  temp.minute += 1;
	}
    }
  
  if ( temp.minute < 0 )
    {
      temp.hour += ( temp.minute / 60 ) - 1;
      temp.minute = 60 + ( temp.minute % 60 );
      if ( 60 + ( temp.minute % 60 ) == 60)
	{
	  temp.minute = 0;
	  temp.hour += 1;
	}
    }
  
  if ( temp.hour < 0 )
    {
      temp.hour = 24 + ( temp.hour % 24 );
    }
  
  return temp;	
}

Time Time::operator ++( int )
{
  Time temp(*this);
  ++*this;
  return temp;
}

Time& Time::operator ++()
{
  *this = *this + 1;
  return (*this);  
}

Time Time::operator --( int )
{
  Time temp(*this);
  --*this;
  return temp;
}

Time& Time::operator --()
{
  *this = *this - 1;
  return (*this); 
}

bool Time::operator <(Time const& rhs) const
{
  return( hour < rhs.hour )
    or ( hour == rhs.hour && minute < rhs.minute )
    or ( hour  == rhs.hour && minute == rhs.minute && second < rhs.second );
}

bool Time::operator >(Time const& rhs) const
{
  return ( rhs < *this);  // if rhs < Time == false
}                         // then Time > rhs == true

bool Time::operator <=(Time const& rhs) const
{
  return !( rhs < *this );
}

bool Time::operator >=(Time const& rhs) const
{
  return !( *this < rhs );
}

bool Time::operator ==(Time const& rhs) const
{
  return !( rhs < *this || *this < rhs );
}

bool Time::operator !=(Time const& rhs) const
{
  return ( rhs < *this || *this < rhs );
}

int Time::get_hour() const
{
  return hour;
}

int Time::get_minute() const
{
  return minute;
}

int Time::get_second() const
{
  return second;
}

std::ostream& operator<<(std::ostream& lhs, Time const& rhs)
{
  return lhs << rhs.to_string();
}

std::istream& operator>>(std::istream& lhs, Time& rhs)
{
  char divide;
  int hour;
  int minute;
  int second;
  lhs >> hour >> divide >> minute >> divide >> second;

  try
  {
    rhs = Time{hour, minute, second};
  }
  catch(std::exception& e)
  {
    lhs.setstate(std::ios::failbit);
  }
  return lhs;
}
