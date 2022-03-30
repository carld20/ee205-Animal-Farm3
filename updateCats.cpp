///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Project - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <string.h>

#include "updateCats.h"
#include "reportCats.h"
#include "catDatabase.h"

bool updateCatName( const size_t index, const char* name ){
    isIndexValid( index ); //Check if index is valid (same with others)
    isNameValid( name ); //Check if name is too long


    memset( cats[index].name, 0, MAX_CAT_NAME ); //Remove old cat name
    strncpy( cats[index].name, name, MAX_CAT_NAME - 1 );

    return true;
}
bool fixCat( const size_t index ){
    isIndexValid( index );

    cats[index].isFixed = true;

    return true;
}

bool updateCatWeight( const size_t index, const Weight weight ){
    isIndexValid( index );
    isWeightValid( weight ); //Check if weight is <=0

    cats[index].weight = weight;

    return true;
}

bool updateCatCollar1( const size_t index, const enum Color color ){
    isIndexValid( index );

    cats[index].collarColor1 = color;

    return true;
}

bool updateCatCollar2( const size_t index, const enum Color color ){
    isIndexValid( index );

    cats[index].collarColor2 = color;

    return true;
}

bool updateLicense( const size_t index, const unsigned long long license ){
    isIndexValid( index );

    cats[index].license = license;

    return true;
}