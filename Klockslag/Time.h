#ifndef TIME_H
#define TIME_H

#include <string>
#include <sstream>


class Time
{
public:
  Time();
  
  Time(int h,
       int m,
       int s);

  Time(std::string const& t);
  
  std::string to_string( bool const& ampm = false ) const;

  Time operator +( int const& rhs ) const;
  Time operator -( int const& rhs ) const;
  Time operator ++( int );
  Time& operator ++();
  Time operator --( int );
  Time& operator --();

  bool operator <(Time const& rhs) const;
  bool operator >(Time const& rhs) const;
  bool operator <=(Time const& rhs) const;
  bool operator >=(Time const& rhs) const;
  bool operator ==(Time const& rhs) const;
  bool operator !=(Time const& rhs) const;
  
  int get_hour() const;
  int get_minute() const;
  int get_second() const;
  bool is_am() const;

private:
  int hour, minute, second;
  void ValidTime() const;
  
};
Time operator +(int const& lhs, Time const& rhs);
std::ostream& operator<<(std::ostream& lhs, Time const& rhs);
std::istream& operator>>(std::istream& lhs, Time& rhs);

#endif
