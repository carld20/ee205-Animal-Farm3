///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <string.h>
#include <assert.h>
#include <stdio.h>

#include <glob.h>


#include "catDatabase.h"
#include "reportCats.h"


struct Cat cats[MAX_CATS];

size_t numCats = 0;

//Reset database
void initializeDatabase(){
    numCats = 0;

    memset( &cats, 0, sizeof( cats ) );
}

//Checks if database is not negative
bool validateDatabase(){
#pragma GCC diagnostic push
#pragma GCC diagnostinc ignored "-Wtype-limits"
    assert( numCats >= 0 );
#pragma GCC diagnostic pop

    return true;

}

bool isFull(){
    validateDatabase();
    if( numCats >= MAX_CATS ){
        return true;
    }
    else{
        return false;
    }
}

//Check if index is ok
extern bool isIndexValid( const size_t index ){
    if( index <= 0 ){
        return false;
    }
    if( index >= numCats ) {
        return false;
    }
    return true;

}

//Check if name is ok
bool isNameValid( const char* name ){
    if( name == NULL ){
        return false;
    }
    if( strlen( name ) > MAX_CAT_NAME - 1 ){
        return false;
    }

    return true;
}

//check if weight is ok
bool isWeightValid( const Weight weight ){
    if( weight <= 0 ){
        return false;
    }
    else{
        return true;
    }
}

//Delete cat info
void wipeCat(const size_t index ){
    assert( isIndexValid( index ) );
    memset( &cats[index], 0, sizeof( struct Cat ) );
}

//swap cats' index
bool swapCat( const size_t x, const size_t y ){
    if ( !isIndexValid( x ) ){
        return false;
    }
    if( !isIndexValid( y ) ){
        return false;
    }
    if( x == y ){
        return true;
    }

    struct Cat oldCat;

    memcpy( &oldCat, &cats[x], sizeof( struct Cat ) );
    memcpy( &cats[x], &cats[y], sizeof( struct Cat ) );
    memcpy( &cats[y], &oldCat, sizeof( struct Cat ) );

    return true;
}