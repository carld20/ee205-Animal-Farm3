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



