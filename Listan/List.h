#ifndef List_H
#define List_H
#include<initializer_list>
#include<string>

/*
  Information om komplettering:
  Eventuella siffrorna hänvisar till rättningsprotokollet som finns på: https://www.ida.liu.se/divisions/sas/groups/upp/info/lang/cpp/UPP_correct_guide.pdf

  Kompletteringen kan gälla hela filen och alla filer i labben, så får ni komplettering på en sak, kan samma sak förekomma på fler ställen utan att jag skrivit det.

  Komplettering lämnas in via sendlab efter senast en (1) vecka

  Har ni frågor om kompletteringen kan ni maila mig på:
  simon.ahrenstedt@liu.se
*/

/*
  Vänligen låt nedan meddelanden stå kvar vid inlämningen av kompletteringen.

  Komplettering: Ni har en del includes i er .h fil som inte är nödvändiga och/eller kan flyttas till er .cc fil. Tänk på att alla som inkluderar er .h fil också då kommer få samma includes så försök att minimera antal includes i .h filen.

  Komplettering: print är ett missvisande namn på en funktion som skapar och returnerar en sträng utifrån er datastruktur. Ett rimligare namn hade varit to_string.

  Komplettering: Er remove funktion bör ha liknande funtkionalitet som er get funktion för att hantera index som är utanför listan.
*/

class Sorted_List
{
public:
  Sorted_List();       //Constructor
  Sorted_List(std::initializer_list<int> const& list);
  ~Sorted_List();     //Destructor
  Sorted_List(Sorted_List const&);  //Copy konstruktor
  Sorted_List(Sorted_List && rhs);  //Move konstruktor
  Sorted_List& operator=(Sorted_List const& rhs); //Copy tilldelning
  Sorted_List& operator=(Sorted_List && rhs); //move tilldelning
  bool empty() const;
  bool Vaild_Index(int const& index) const;
  void SortedInsert(int const insert);
  void remove(int const& index);
  int get(int const& index) const;
  int size() const;
  std::string to_string() const;
  void empty_list();

private: 
  class Node
  {
  public:
    Node() = default;
    Node(int data);
    Node* prev{nullptr};
    int data{};
    Node* next{nullptr};
  };

  Node* head{};
  Node* tail{};
};

#endif
