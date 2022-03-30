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

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <glob.h>

#include "addCats.h"
#include "catDatabase.h"

//Check if cat exists
bool catExist(const char* newName ){
    for( NumCats i = 0; i < numCats; i++ ) {
        if (strncmp(cats[i].name, newName, MAX_CAT_NAME) == 0) {
            return true; //cat exists
        }

        return false;

    }
}

//Add to database
unsigned int addCat ( const char* newName, const enum Genders newGender, const enum Breeds newBreed,const bool  newFixed,const Weight newWeight, const enum Color newCollarColor1, const enum Color newCollarColor2, const unsigned long long newLicense ) {

    //Check if ok to add cat to database
    if( isFull() ){
        return 1;
    }

    if( !isNameValid( newName ) ){
        return 1;
    }

    if( catExist ( newName ) ){
        return 1;
    }

    if( !isWeightValid( newWeight ) ){
        return 1;
    }

    assert ( validateDatabase() == true );

    NumCats index = numCats;

    strncpy( cats[index].name, newName, MAX_CAT_NAME );
    cats[index].gender              = newGender;
    cats[index].breed               = newBreed;
    cats[index].isFixed             = newFixed;
    cats[index].weight              = newWeight;
    cats[index].collarColor1        = newCollarColor1;
    cats[index].collarColor2        = newCollarColor2;
    cats[index].license             = newLicense;

    numCats += 1; //Add one to total number of cats in database

    assert( validateDatabase() == true );
    return index;
}