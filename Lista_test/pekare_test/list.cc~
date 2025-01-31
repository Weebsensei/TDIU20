#include "List.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;


Sorted_List::Sorted_List(): //element* first, element* last
firstptr{nullptr}, lastptr{nullptr}
{}

Sorted_List::~Sorted_List()
{

  if (is_empty() == false)
  {
    Element* tmp = firstptr;
    while(tmp != lastptr){
      tmp = tmp->nextptr;
      delete tmp->prevptr;
    }
    delete tmp;
    firstptr = nullptr;
    lastptr = nullptr;
    list_size = 0;
  }
}

Sorted_List::Sorted_List(std::initializer_list<int> const &list):
Sorted_List()
{
  for (int i : list)
  {
    insert(i);
  }
}

Sorted_List::Element::Element(Element* next, Element* prev, int new_data):
nextptr{next}, prevptr{prev}, data{new_data}
//next{nullptr}, prev{nullptr}, new_data{0}
{}

Sorted_List::Sorted_List(Sorted_List const& rhs):
Sorted_List()
{
   // TODO: Detta �r en mycket ineffektiv l�sning, eftersom vi vet att
   // listan �r sorterad innan kopiering. T�nk igenom hur m�nga g�nger
   // ni kommer att loopa igenom listorna. DONE

    for (int i = rhs.get_size()-1; i >= 0; i-- ){
      insert(rhs.at(i));
  }
}

Sorted_List::Sorted_List(Sorted_List && rhs):
Sorted_List()
{
 *this = std::move(rhs);
}

////////////////////////////////////////////////////////////////////////
bool Sorted_List::is_empty() const
{
  if (firstptr == nullptr && lastptr == nullptr) //inte nödvändigt att kolla lastptr också men idgaf
  {
    return true;
  } else {
    return false;
  }
}

void Sorted_List::insert (int const& insert_data)
{
  if (is_empty() == true)
  {
    firstptr = new Element {nullptr, nullptr, insert_data};
    lastptr = firstptr;
  } else {
    Element* tmp = firstptr;
    if (insert_data < tmp->data)
    {
      firstptr = new Element {tmp, nullptr, insert_data};
      tmp->prevptr = firstptr;
    } else {
      while (insert_data > tmp->data && tmp->nextptr != nullptr)
      {
        tmp = tmp->nextptr;
      }
      if (tmp->data >= insert_data)
      {
        Element* tmp1 = tmp;
        tmp = tmp->prevptr;

        tmp->nextptr = new Element {tmp1, tmp, insert_data};
        tmp1->prevptr = tmp->nextptr;

      } else {
        tmp->nextptr = new Element {nullptr, tmp, insert_data};
        lastptr = tmp->nextptr;
      }
    }
  }
  list_size++;
}

int Sorted_List::get_size()const
{
  return list_size;
}

int Sorted_List::at(int const& position )const
{
  if(position < get_size())
  {
    Element* tmp = firstptr;
    for (int i = 0; i < position; i++)
    {
      tmp = tmp->nextptr;
    }
    return tmp->data;
  }else{
    throw std::logic_error("Input out of range");

  }
}

void Sorted_List::remove(int const& pos)
{
  if (pos < get_size() && pos >= 0)
  {
    Element* tmp = firstptr;
    for (int i = pos; i > 0; i--){
      tmp = tmp->nextptr;
    }

    if (tmp->prevptr == nullptr && tmp->nextptr == nullptr){
      delete tmp;
      firstptr = nullptr;
      lastptr = nullptr;

    } else if (tmp->nextptr == nullptr){
      lastptr = tmp->prevptr;
      lastptr->nextptr = nullptr;
      delete tmp;
    } else if (tmp->prevptr == nullptr) {
      firstptr = tmp->nextptr;
      firstptr->prevptr = nullptr;
      delete tmp;
    } else {
      tmp->prevptr->nextptr = tmp->nextptr;
      delete tmp;
    }
    list_size--;
  } else {
    throw std::logic_error("Input out of range");
  }
}

ostream& operator << (ostream & os, Sorted_List const& rhs)
{

  for (int i {0}; i < rhs.get_size(); i++)
  {
    os << rhs.at(i);

    if (i+1 != rhs.get_size()){
      os << " ";
    }
  }
  return os;
}


 Sorted_List& Sorted_List::operator =(Sorted_List const& rhs)
{
  int tmp = get_size();
  for (int k {tmp}; k > 0; k--)
  {
    remove(0);
  }

  //cout << "Sup boi" << endl;

  // TODO: Samma som i kopieringskonstruktorn. Samt kodupprepning. DONE
  for (int i = rhs.get_size()-1; i >= 0; i-- ){
    insert(rhs.at(i));
}

  list_size = rhs.get_size();

  return *this;
}

Sorted_List& Sorted_List::operator =(Sorted_List && rhs) //FLyttilldelning
{
   // Kommentar: Ni hade kunnat anv�nda std::swap()
  Element* tmp_first = firstptr;
  Element* tmp_last = lastptr;

  int tmp_size = get_size();
  list_size = rhs.get_size();
  rhs.list_size = tmp_size;

  firstptr = rhs.firstptr;
  lastptr = rhs.lastptr;

  rhs.firstptr = tmp_first;
  rhs.lastptr = tmp_last;

  return *this;
}
