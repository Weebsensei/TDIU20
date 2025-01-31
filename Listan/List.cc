#include"List.h"
#include<sstream>

Sorted_List::Sorted_List()                                                //Tom Lista
{
  head = new Node{};                    //head och tail
  tail = new Node{};                    //sentinel nodes
  head->next = tail;
  tail->prev = head;
}
Sorted_List::Sorted_List(std::initializer_list<int> const& list)          //Lista med int inserts
  : Sorted_List()
{
  for (int i : list)
    {
      SortedInsert(i);
    }
}

Sorted_List::~Sorted_List()   //Destructor
{
  empty_list();
  delete head;
  delete tail;
}

Sorted_List::Sorted_List(Sorted_List const& original)   //Copy
  : Sorted_List()
{
  Node*current{original.head->next};
  while ( current != original.tail )
    {
      SortedInsert(current->data);
      current = current->next;
    }

}

Sorted_List::Sorted_List(Sorted_List && rhs)
  : Sorted_List()
{
  std::swap(head, rhs.head);
  std::swap(tail, rhs.tail);
}

Sorted_List& Sorted_List::operator=(Sorted_List const& rhs)
{
  if ( this != &rhs)
    {
      Sorted_List temp(rhs);
      std::swap(head, temp.head);
      std::swap(tail, temp.tail);
    }
  return *this;
}

Sorted_List& Sorted_List::operator=(Sorted_List && rhs)
{
  if ( this != &rhs)
    {
      empty_list();
      std::swap(head, rhs.head);
      std::swap(tail, rhs.tail);
    }
  return *this;
}


void Sorted_List::empty_list()    //Töm listan
{
  Node* current{tail->prev};
  while ( current != head )
    {
      Node* temp{current};
      current = current->prev;
      delete temp;
    }
  head->next = tail;
  tail->prev = head;
}

bool Sorted_List::empty() const
{
  if ( size() == 0 )
    {
      return true;
    }
  else
    {
      return false;
    }
}

void Sorted_List::SortedInsert( int const insert )
{

  Node* current{head->next};
  Node* prev{head};
  
  while ( current != tail && current->data < insert )
    {
      prev = current;
      current = current->next;
    }

  Node* temp = new Node;
  temp->data = insert;
  temp->next = current;
  temp->prev = prev;
  prev->next = temp;
  current->prev = temp;

}

void Sorted_List::remove(int const& index)
{
  Node* pos{head};
  if ( Vaild_Index( index ) == true )
  {
    for ( int i = 0; i < index; i++ )
      {
        pos = pos->next;
      }
    pos->next->prev = pos->prev;
    pos->prev->next = pos->next;
    delete pos;
  }
  else
  {
    Vaild_Index( index );
  }
}

int Sorted_List::get(int const& index) const
{
  Node* pos = head;
  if ( Vaild_Index( index ) == true )
  {
  for ( int i = 0; i < index; i++ )
    {
      pos = pos->next;
    }
  return pos->data;
  }
  else
  {
    return Vaild_Index( index );
  }
}

bool Sorted_List::Vaild_Index(int const& index) const
{
  if ( index > size() || ( index < 1 ) )
  {
    throw std::logic_error{"Utanför listan!"};
  }
  else
  {
    return true;
  }
}

int Sorted_List::size() const
{
  Node* count = head->next;
  int list_size = 0;
  while ( count != tail )
    {
      count = count->next;
      list_size++;
    }
  return list_size;
}

std::string Sorted_List::to_string() const
{
  
  std::stringstream ss;
  Node* current{head->next};
  while (current != tail) 
    {
      ss << current->data << " ";
      current = current->next;
     
    }
  return ss.str();
}
