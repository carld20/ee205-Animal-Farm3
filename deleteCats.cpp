///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <assert.h>
#include <glob.h>

#include "deleteCats.h"
#include "catDatabase.h"

bool deleteCat( const NumCats index ){
    if( !isIndexValid( index ) ){
        return false;
    }
    if( numCats == 0 ) {
        return true;
    }

    assert ( validateDatabase() == true );


    swapCat( index, numCats - 1 ); //Swap last cat with delete cat
    wipeCat( numCats - 1 );

    numCats -= 1;

    assert( validateDatabase() == true );

    return true;

}

bool deleteAllCats(){
    while( numCats != 0 ){
        deleteCat( 0 );
    }

    numCats = 0;
    return true;
}