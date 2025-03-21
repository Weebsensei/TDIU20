#include "catch.hpp"
#include "Time.h"

using namespace std;



TEST_CASE ("Constructors and getters")
{
   SECTION("Default")
   {
      Time empty{};
      CHECK( empty.get_hour()   == 0 );
      CHECK( empty.get_minute() == 0 );
      CHECK( empty.get_second() == 0 );
   }



   SECTION("Integer")
   {
      Time t0{0,0,0};
      Time t1{12,30,30};
      Time t2{23,59,59};

      CHECK_THROWS( Time{13,35,60} );
      CHECK_THROWS( Time{13,60,35} );
      CHECK_THROWS( Time{24,35,35} );
             
      CHECK( t0.get_hour()   == 0 );
      CHECK( t0.get_minute() == 0 );
      CHECK( t0.get_second() == 0 );
      CHECK( t1.get_hour()   == 12 );
      CHECK( t1.get_minute() == 30 );
      CHECK( t1.get_second() == 30 );
      CHECK( t2.get_hour()   == 23 );
      CHECK( t2.get_minute() == 59 );
      CHECK( t2.get_second() == 59 );
   }

   
   SECTION("String")
   {
      Time t0{"00:00:00"};
      Time t1{"12:30:30"};
      Time t2{"23:59:59"};

      CHECK_THROWS( Time{"13:35:60"} );
      CHECK_THROWS( Time{"13:60:35"} );
      CHECK_THROWS( Time{"24:35:35"} );

      CHECK( t0.get_hour()   == 0 );
      CHECK( t0.get_minute() == 0 );
      CHECK( t0.get_second() == 0 );
      CHECK( t1.get_hour()   == 12 );
      CHECK( t1.get_minute() == 30 );
      CHECK( t1.get_second() == 30 );
      CHECK( t2.get_hour()   == 23 );
      CHECK( t2.get_minute() == 59 );
      CHECK( t2.get_second() == 59 );  
   }
}
TEST_CASE ("is_am") 
{
   Time t0{"05:00:00"};
   Time t1{"14:00:00"};
   CHECK       ( t0.is_am() );
   CHECK_FALSE ( t1.is_am() );
   Time t2{"11:59:59"};
   Time t3{"12:00:00"};
   CHECK       ( t2.is_am() );
   CHECK_FALSE ( t3.is_am() );
   Time t4{"23:59:59"};
   Time t5{"00:00:00"};
   CHECK_FALSE ( t4.is_am() );
   CHECK       ( t5.is_am() );
   
}

TEST_CASE ("to_string")
{
   Time t0{};
   Time t1{11, 59, 59};
   Time t2{12,  0,  0};
   Time t3{13,  0,  0};
   Time t4{23, 59, 59};
   SECTION("24 hour format no argument")
   {
     CHECK( t0.to_string()       == "00:00:00" );
     CHECK_FALSE( t0.to_string() == "0:0:0"    );
     CHECK_FALSE( t0.to_string() == "0:00:00"  );
     CHECK_FALSE( t0.to_string() == "0:0:00"   );
     CHECK_FALSE( t0.to_string() == "00:00:0"  );
     CHECK_FALSE( t0.to_string() == "00:0:00"  );
     CHECK( t1.to_string()       == "11:59:59" );
     CHECK( t2.to_string()       == "12:00:00" );
     CHECK( t3.to_string()       == "13:00:00" );
     CHECK( t4.to_string()       == "23:59:59" );
   }
   
   SECTION("24 hour format with argument")
   {
      CHECK( t1.to_string(false) == "11:59:59" );
      CHECK( t2.to_string(false) == "12:00:00" );
      CHECK( t3.to_string(false) == "13:00:00" );
      CHECK( t4.to_string(false) == "23:59:59" );
   } 

   SECTION("12 hour format")
   {
     CHECK( t0.to_string(true) == "00:00:00 am" );
     CHECK( t1.to_string(true) == "11:59:59 am" );
     CHECK( t2.to_string(true) == "00:00:00 pm" );
     CHECK( t3.to_string(true) == "01:00:00 pm" );
     CHECK( t4.to_string(true) == "11:59:59 pm" );
   }
}

TEST_CASE ("Change Time")
{
  Time t0{};
  Time t1{11, 59, 59};
  Time t2{12,  0,  0};
  Time t3{13,  0,  0};
  Time t4{23, 59, 59};
  SECTION("Add time")
    {
      CHECK( (t0 + 3600).to_string()    == "01:00:00" );  //00:00:00 + 1 timme
      CHECK( (t1 + 25).to_string()      == "12:00:24" );  //11:59:59 + 25 sekunder
      CHECK( (t2 + (-3600)).to_string() == "11:00:00" );  //12:00:00 - 1 timme
      CHECK( (t3 + 4320001).to_string() == "13:00:01" );  //13:00:00 + 50 dagar och 1 sekund
      CHECK( (t2 + 3600)                == t3         );
      CHECK( (t4 + 1).to_string()       == "00:00:00" );
      CHECK( (t0 + (-1)).to_string()    == "23:59:59" );
      CHECK( (10 + t0).to_string()      == "00:00:10" );
      CHECK( (1  + t4).to_string()      == "00:00:00" );
    }
  SECTION("Sub time")
    {
      CHECK( (t0 - 3600).to_string()        == "23:00:00"    );  //00:00:00 - 1 timme
      CHECK( (t1 - 25).to_string()          == "11:59:34"    );  //11:59:59 - 25 sekunder
      CHECK( (t2 - (-3600)).to_string(true) == "01:00:00 pm" );  //12:00:00 + 1 timme
      CHECK( (t3 - 43200).to_string(true)   == "01:00:00 am" );  //13:00:00 - 12 timmar
      CHECK( (t3 - 3600)                    == t2            );
      CHECK( (t0 - 1).to_string()           == "23:59:59"    );
    }
}

TEST_CASE ("Increment/Decrement")
{
  Time t0{23, 59, 59};
  Time t1{11, 59, 59};
  SECTION ("Post inc")
    {
      CHECK( t0++.to_string()       == "23:59:59" );
      CHECK( t0.to_string()         == "00:00:00" );
      CHECK( t0++.to_string()       == "00:00:00" );
      CHECK( t0.to_string()         == "00:00:01" );
      CHECK( t1++.to_string(true)   == "11:59:59 am" );
      CHECK( t1.to_string(true)     == "00:00:00 pm" );
    }
  SECTION ("Pre inc")
    {
      CHECK( (++t0).to_string()     == "00:00:00"    );
      CHECK( t0.to_string(true)     == "00:00:00 am" );
      CHECK( (++t0).to_string()     == "00:00:01" );
      CHECK( (++t1).to_string(true) == "00:00:00 pm" );
    }
  Time t2{ 0, 0, 0};
  Time t3{12, 0, 0};
  SECTION ("Post dec")
    {
      CHECK( t2--.to_string()       == "00:00:00" );
      CHECK( t2.to_string()         == "23:59:59" );   
    }
  SECTION ("Pre dec")
    {
      CHECK( (--t2).to_string()     == "23:59:59"    );
      CHECK( t3.to_string(true)     == "00:00:00 pm" );
      CHECK( (--t3).to_string(true) == "11:59:59 am" );
    } 
}

TEST_CASE ("Compare operator")
{
  Time t0{23,0,0};
  Time t1{11,59,59};
  SECTION ("Lesser than")
    {
      CHECK_FALSE( (t0 < t1 )   == true);
      CHECK( (t1 < t0 )         == true);
      CHECK_FALSE( (t0 < t0 )   == true);
    }
  SECTION ("Greater than")
    {
      CHECK( (t0 > t1 )         == true);
      CHECK_FALSE( (t1 > t0)    == true);
      CHECK_FALSE( (t0 > t0 )   == true);
    }
  SECTION ("Lesser or equal")
    {
      CHECK( (t1 <= t0 )        == true);
      CHECK( (t0 <= t0)         == true);
    }
  SECTION ("Greater or equal")
    {
      CHECK_FALSE( (t1 >= t0 )  == true);
      CHECK( (t0 >= t1 )        == true);
      CHECK( (t0 >= t0)         == true);
    }
  SECTION ("Equal")
    {
      CHECK_FALSE( (t0 == t1 )  == true);
      CHECK( (t0 == t0)         == true);
    }
  SECTION ("Not equal")
    {
      CHECK( (t0 != t1 )        == true);
      CHECK_FALSE( (t1 != t1)   == true);
    }
}

TEST_CASE ("Output operator" )
{
  stringstream ss;
  SECTION("Single output")
  {
    ss << Time{1,2,3};
    CHECK( ss.str()           == "01:02:03" );
  }
  SECTION("Chained outputs")
  {
    ss << Time{13,37,00} << " pm";
    CHECK( ss.str()           == "13:37:00 pm" );
  }
  SECTION("Const time")
  {
    Time const t0{23,59,59};
    ss << t0;
    CHECK( ss.str()           == "23:59:59" );
  }
}

TEST_CASE("Input operator" )
{
  Time t0{};
  stringstream ss;
  SECTION("in-test")
  {
    ss << "13:33:37";
    ss >> t0;
    CHECK(t0.to_string()      == "13:33:37");
  }

  SECTION("Catch test h")
  {
    ss << "05:20:71";
    ss >> t0;
    CHECK(ss.fail());
  }
}

TEST_CASE ("Conversion to string" )
{
  CHECK( string(Time{2,4,1}.to_string()) == "02:04:01" );
}

TEST_CASE ( "Special cases" )
{
  CHECK_THROWS( Time{-1,  0,  6} );
  CHECK_THROWS( Time{14, -1, 44} );
  CHECK_THROWS( Time{14, 44, -1} );
  CHECK_THROWS( Time{-1, -1, -1} );
}

