///////////////////////////////////////////////////////////////////////////////
////          University of Hawaii, College of Engineering
///// @brief  Lab 07d - AnimaL Farm1 - EE 205 - Spr 2022
////
//// Usage:  Animal Farm1
////
//// File: main.c
////
////
////
//// @author Carl Domingo <carld20@hawaii.edu>
//// @date   03/08/2022
/////////////////////////////////////////////////////////////////////////////////

#include <cstdlib>  // For EXIT_SUCCESS / EXIT_FAILURE
#include <cassert>  // For assert()
#include <cstring>  // For strcmp()
#include <exception>  // For try/catch blocks
#include <iostream>

#include "Cat.h"
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "deleteCats.h"

using namespace std ;

/// @internal Used to test the largest possible name
#define MAX_NAME1    "1234567890123456789012345678901234567890123456789"

/// @internal Used to test an illegal name (because it's too large by
///           one character)
#define ILLEGAL_NAME "12345678901234567890123456789012345678901234567890"


/// The entry point for Animal Farm
int main() {
    cout << "Starting Animal Farm2" << endl ;

    initializeDatabase() ;

#ifdef DEBUG
    {
      // Verify that a cat's default values are set
      Cat testCat = Cat();
      assert(testCat.getName() != nullptr );
      assert(strcmp(testCat.getName(), "") == 0);
      assert(testCat.getGender() == UNKNOWN_GENDER);
      assert(testCat.getBreed() == UNKNOWN_BREED);
      assert(testCat.isFixed() == false);
      assert(testCat.getWeight() == UNKNOWN_WEIGHT);
      assert(!testCat.isFixed());
      assert(!testCat.validate());  // The default cat is invalid

      // Test for NULL name
      try {
         testCat.setName(nullptr);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      // Test for empty name
      try {
         testCat.setName("");
         assert(false); // We should never get here
      } catch (exception const &e) {}

      // Test valid names
      testCat.setName("A");       // A 1 character name is valid
      testCat.setName(MAX_NAME1); // A MAX_NAME1 name is valid

      // Test for name too large
      try {
         testCat.setName(ILLEGAL_NAME);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setGender(FEMALE);

      try {
         testCat.setGender(MALE);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setBreed(MAINE_COON);

      try {
         testCat.setBreed(MANX);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.fixCat();
      assert(testCat.isFixed());

      // Test for Weight <= 0
      try {
         testCat.setWeight(0);
         assert(false); // We should never get here
      } catch (exception const &e) {}

      testCat.setWeight(1.0 / 1024);
      assert(testCat.getWeight() == 1.0 / 1024);

      assert(testCat.validate());  // The cat should now be valid
      testCat.print() ;

      assert(!isCatInDatabase(&testCat)) ;
   }
#endif

    bool result ;
    result = addCat( new Cat( "Dominick", Female, MAINE_COON, 15.0 )) ;
    assert( result ) ;
    if( !result ) throw logic_error ("Animal Farm2: addCat() failed" ) ;
    result = addCat( new Cat( "Seabass", Unknown, UNKNOWN_BREED , 2.3 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Brae", Female, PERSIAN, 19.7 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Kebin", Female, MANX, 25.9 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Kurris", Male, SHORTHAIR, 13.4 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Paul", Male, MAINE_COON, 8.2 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Dan Dan", Female, MANX, 22.3 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Alden", Male, PERSIAN, 32.1 )) ;
    assert( result ) ;
    result = addCat( new Cat( "Jeriel", Female, MAINE_COON, 15.7 )) ;
    assert( result ) ;

#ifdef DEBUG
    {
      // Test finding a cat...
      Cat *bella = findCatByName("Bella");
      assert(bella != nullptr);
      // Test not finding a cat
      assert(findCatByName("Bella's not here") == nullptr);

      // Test deleting a cat...
      assert(deleteCat(bella) == true);
      try {
         deleteCat(bella); // Verify that Bella's not there
      } catch (exception const &e) {}

      bella = nullptr;
   }
#endif

    printAllCats() ;

    deleteAllCats() ;

    printAllCats() ;

    cout << "Done with Animal Farm2" ;

    return( EXIT_SUCCESS ) ;
}



/*#include <cstdlib>
#include <cassert>
#include <cstring>
#include <iostream>

#include "catDatabase.h"
#include "reportCats.h"
#include "deleteCats.h"
#include "addCats.h"
#include "Cat.h"

using namespace std;

#define MAX_NAME1       "1234567890123456789012345678901234567890123456789"
#define MAX_NAME2       "DIFFERENT 123456789012345678901234567890123456789"
#define ILLEGAL_NAME    "12345678901234567890123456789012345678901234567890"

int main() {
    cout << "Starting Animal Farm2" << endl;

    addCat ("Dominick", Female,     MAINE_COON,     false, 15.0, Red,   Black, 101 ) ;
    addCat ("Seabass",  Unknown,    UNKNOWN_BREED,  true,   2.3, Black, Pink,  102 ) ;
    addCat ("Kebin",    Female,     MANX,           false, 25.9, Green, Red,   103 ) ;
    addCat ("Brae",     Female,     PERSIAN,        false, 19.7, Blue,  Red,   104 ) ;
    addCat ("Izaiah",   Unknown,    SHORTHAIR,      true,  10.0, White, Green, 105 ) ;
    addCat ("Kurris",   Male,       UNKNOWN_BREED,  true,  13.0, Pink,  Blue,  106 ) ;
    addCat ("Jacob",    Female,     SHORTHAIR,      false, 22.0, Black, White, 107 ) ;
    addCat ("Alden",    Female,     MAINE_COON,     false, 35.8, White, Black, 108 ) ;
    addCat ("Jeriel",   Unknown,    UNKNOWN_BREED,  true,  28.3, Red,   Blue,  109 ) ;
    addCat ("Dan Dan",  Unknown,    MANX,           true,   2.0, Green, Pink,  110 ) ;
    addCat ("Paul",     Female,     UNKNOWN_BREED,  false,  0.2, Pink,  White, 111 ) ;

#ifdef DEBUG
    //Empty Name
                assert( addCat( " ", UNKNOWN, SHORTHAIR, false, 19.0, Black, White, 101 ) == BAD_CAT );
                //Max char name
                assert( addCat( MAX_NAME1, Male, MANX, false, 22.0, White, Black, 102 ) != BAD_CAT );
                //Too long name
                assert( addCat( ILLEGAL_NAME, Unknown, UNKNOWN_BREED, false, 33.0, Blue, Red, 103 ) == BAD_CAT );
                //Duplicate
                assert( addCat( "Kebin", Female, MANX, true, 55.3, Green, White, 104 ) == BAD_CAT );
                //<= weight
                assert( addCat( "Carl", Male, MANX, false, 0, Blue, Red, 105 ) == BAD_CAT );

                //Print(-1)
                printCat(-1);
                //Too big index
                printCat(9999);

                //Find cat
                assert( findCat( "Brae" ) == 3 );
                //No find cat
                assert( findCat( "Carl" ) == BAD_CAT );

                //Add details
                NumCats testCat = addCat( "Oscar", Unknown, SHORTHAIR, false, 1.1, Red, Black, 111 );
                assert( testCat != BAD_CAT );
                assert( testCat < MAX_CATS );

                //Setting a large name
                assert( updateCatName( testCat, MAX_NAME2 ) == true );
                printCat( testCat );

                //Set a too large of a name
                assert( updateCatName( testCat, ILLEGAL_NAME ) == false );
                printCat( testCat );

                //Test bad weight
                assert( updateCatWeight( testCat, -1 ) == false );
#endif

    printAllCats();

    int paul = findCat( "Paul" );
    assert( updateCatName( paul, "Kebin" ) == false ); //Should fail name already exists
    printCat( paul );
    assert( updateCatName( paul, "Pol" ) == true );
    assert( updateCatWeight( paul, 2.2 ) == true );
    assert( fixCat( paul ) == true );
    assert( updateCatCollar1( paul, Red ) == true );
    assert( updateCatCollar2( paul, Blue ) == true );
    assert( updateLicense( paul, 222 ) == true );

    printCat( paul );

    printAllCats();

    deleteAllCats();
    printAllCats(); //No cats should show up

    printf( "Done with AnimalFarm" );

    return ( EXIT_SUCCESS );

}*/