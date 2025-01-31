#include "catch.hpp"
#include "List.h"
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;


// här lägger ni era testfall.
// Jobba enligt TDD;
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut

TEST_CASE ("b E k A r E constructor")
{

  SECTION ("Empty")
  {
  Sorted_List l;
  CHECK(l.is_empty());
  }


  SECTION ("initialized_list")
  {
  Sorted_List initialized_list{2,5,7};
  CHECK (initialized_list.at(0) == 2);
  CHECK (initialized_list.at(1) == 5);
  CHECK (initialized_list.at(2) == 7);
  }
}

TEST_CASE ("l.get_size")
{
  Sorted_List l;
  l.insert(666);
  CHECK(l.get_size() == 1);

  l.insert(1337);
  l.insert(13);
  l.insert(133);
  l.insert(1);
  CHECK(l.get_size() == 5);
}

TEST_CASE ("l.at(i)")
{
   // TODO: Testa att mata in ett index som inte finns. FIXED
  Sorted_List l;
  l.insert(6);
  CHECK(l.at(0) == 6);
  REQUIRE_THROWS_WITH(l.at(2), "Input out of range");
}

TEST_CASE ("Is sorted?")
{
  SECTION ("Insert flera ggr")
  {
    Sorted_List l{};

    //l.insert(666);
    //l.insert(1337);
    //l.insert(13);
    //l.insert(133);
    //l.insert(1);
    l.insert(1);
    CHECK(l.at(0) == 1);

    l.insert(3);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 3);

    l.insert(2);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 2);
    CHECK(l.at(2) == 3);

    l.insert(7);
    CHECK(l.at(0) == 1);
    CHECK(l.at(1) == 2);
    CHECK(l.at(2) == 3);
    CHECK(l.at(3) == 7);
  }
  SECTION("Konstruktor")
  {
    Sorted_List k{1337,666,999,13,123,666,2048};
    CHECK(k.at(0) == 13);
    CHECK(k.at(1) == 123);
    CHECK(k.at(2) == 666);
    CHECK(k.at(3) == 666);
    CHECK(k.at(4) == 999);
    CHECK(k.at(5) == 1337);
    CHECK(k.at(6) == 2048);
  }
}

TEST_CASE ("<< operator")
{
  stringstream ss;
  Sorted_List l {12, 56, 67, 13};
  ss << l;
  CHECK(ss.str() == "12 13 56 67");
}

TEST_CASE ("Remove function")
{
   // TODO: Testa att ta bort n�got som inte finns. FIXED
  stringstream ss;
  stringstream sk;
  Sorted_List l {1,2,3};
  ss << l;
  CHECK(ss.str() == "1 2 3");

  l.remove(0);
  sk << l;
  CHECK(sk.str() == "2 3");
  REQUIRE_THROWS_WITH(l.remove(3), "Input out of range");

}

TEST_CASE ("= operator")
{
  stringstream ss;
  // TODO: Testa att inte listorna �r samman kopplade efter kopia. DONE
  Sorted_List l1 {1, 2, 3};
  Sorted_List l2 {4, 5, 6};

  l1 = l2;
  ss << l1;
  CHECK(ss.str() == "4 5 6");

  stringstream ks;
  l2.remove(0);
  ks << l1;
  CHECK(ks.str() == "4 5 6");
}

TEST_CASE ("Tilldelning nytt objekt")
{
  stringstream ss;
  // TODO: Samma som ovan. DONE
  Sorted_List l1 {1, 9, 7, 34};
  Sorted_List l2 {l1};

  ss << l2;
  CHECK(ss.str() == "1 7 9 34");

  stringstream ks;
  l2.remove(0);
  ks << l1;
  CHECK(ks.str() == "1 7 9 34");
}

TEST_CASE ("Swap tilldelning")
{
  Sorted_List l1 {1, 2 ,3};
  Sorted_List l2 {4, 5, 6};
  l1 = std::move(l2);

  stringstream ss;
  stringstream sk;

  ss << l1;
  sk << l2;

  CHECK (ss.str() == "4 5 6");
  CHECK (sk.str() == "1 2 3");

  //l1 = std::move(l2);
  //Sorted_List l1{std::move(l2)}
}

TEST_CASE ("Swap Konstruktor")
{

  Sorted_List l2 {4, 5, 6};
  Sorted_List l1{std::move(l2)};

  stringstream ss;

  ss << l1;

  CHECK (ss.str() == "4 5 6"); //L1
  CHECK(l2.is_empty());  //L2
}
