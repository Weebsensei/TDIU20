#ifndef LIST_H
#define LIST_H
#include <initializer_list>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

class Sorted_List //class
{
public:
  
  Sorted_List();
  ~Sorted_List();
  Sorted_List(std::initializer_list<int> const &list);
  Sorted_List(Sorted_List const& rhs);
  Sorted_List(Sorted_List && rhs);


  bool is_empty() const;
  void insert (int const& insert_data);
  int get_size()const;
  int at(int const& i) const;
  void remove(int const& pos);
  Sorted_List& operator =(Sorted_List const& rhs);
  Sorted_List& operator =(Sorted_List && rhs); //FLyttilldelning

private:

  class Element
  {
  public:
    Element(Element* next, Element* prev, int new_data);
    //~Element();

    Element* nextptr{nullptr};
    Element* prevptr{nullptr};
    int data;
  };

  Element* firstptr{nullptr};
  Element* lastptr{nullptr};
  int list_size{};

};

std::ostream& operator << (std::ostream & os, Sorted_List const& rhs);


#endif
