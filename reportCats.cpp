///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Project - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////
#include <string.h>
#include <stdio.h>
#define NULL 0


#include "reportCats.h"
#include "catDatabase.h"

void printAllCats(){
    for( size_t j = 0; j < numCats; j++ ){
        printCat( j );
    }
}
void printCat( const size_t index ){
    if( !isIndexValid( index ) ){
        return;
    }

    printf( "cat index = [%lu]: name = [%s], gender = [%s], breed = [%s], isFixed = [%d], weight = [%f], color1 = [%s], color2 = [%s], license = [%llu]", index, cats[index].name, genderCat( cats[index].gender ), breedCat( cats[index].breed ), cats[index].isFixed, cats[index].weight, colorCat( cats[index].collarColor1 ), colorCat( cats[index].collarColor2 ), cats[index].license );
}

size_t findCat( const char* name ){
    if( name == NULL ){
        return 1;
    }
    for( size_t j = 0; j < numCats; j++ ){
        if( strncmp( name, cats[j].name, MAX_CAT_NAME ) == 0 ){
            return j;
        }
    }
    return 1;

}

const char* genderCat( const enum Genders gender ){
    switch( gender ){
        case Unknown:   return "Unknown";
        case Male:      return "Male";
        case Female:    return "Female";
    }
    return NULL;
}

const char* breedCat( const enum Breeds breed ){
    switch( breed ){
        case UNKNOWN_BREED:     return "Uknown breed";
        case MAINE_COON:        return "Maine Coon";
        case MANX:              return "Manx";
        case SHORTHAIR:         return "Shorthair";
        case PERSIAN:           return "Persian";
        case SPHYNX:            return "Sphynx";
    }
    return NULL;
}

const char* colorCat( const enum Color color ){
    switch( color ){
        case Black:     return "Black";
        case White:     return "White";
        case Red:       return "Red";
        case Blue:      return "Blue";
        case Green:     return "Green";
        case Pink:      return "Pink";
    }
    return NULL;
}