///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cassert>
#include <glob.h>

#include "addCats.h"
#include "catDatabase.h"
#include "Cat.h"

using namespace std;

//Check if cat exists
/*bool catExist(const char* newName ){
    for( NumCats i = 0; i < numCats; i++ ) {
        if (strncmp(cats[i].name, newName, MAX_CAT_NAME) == 0) {
            return true; //cat exists
        }

        return false;

    }
}located in catDatabase.cpp, isCatExist*/

//Add to database
bool addCat( Cat* newCat ) {
    assert( newCat != nullptr );
    newCat->validate();

    if( isCatExist( newCat ) ){
        throw logic_error("Animal Farm2: Cat already exist in database, try a different name");

    }

    assert( validateDatabase() );

    newCat->next = catDatabaseHeadPointer;
    catDatabaseHeadPointer = newCat;
    totalCats++;

    assert( validateDatabase() );

    return true;//if successful

}