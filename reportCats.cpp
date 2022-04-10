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

#include <cstring>
#include <stdexcept>
#include <iostream>
#include <cassert>

#include "reportCats.h"
#include "catDatabase.h"
#include "Cat.h"

using namespace std;

bool printAllCats(){
    int numCats = 0;
    assert( validateDatabase() );

    for( Cat* iCat = catDatabaseHeadPointer; iCat != nullptr; iCat = iCat->next ){
        iCat->print();
        numCats++;

    }

    assert( validateDatabase() );
    return true;  //true if successfull

}
/*void printCat( const NumCats index ){
    if( !isIndexValid( index ) ){
        return;
    }

    printf( "cat index = [%lu]: name = [%s], gender = [%s], breed = [%s], isFixed = [%d], weight = [%f], color1 = [%s], color2 = [%s], license = [%llu] \n", index, cats[index].name, genderCat( cats[index].gender ), breedCat( cats[index].breed ), cats[index].isFixed, cats[index].weight, colorCat( cats[index].collarColor1 ), colorCat( cats[index].collarColor2 ), cats[index].license );
}*/

Cat* findCatByName( const char* name ){
    assert( Cat().validateName( name ) );

    for(Cat* iCat = catDatabaseHeadPointer; iCat != nullptr; iCat = iCat->next){
        if( strcmp(name, iCat->getName() ) == 0 ){
            return iCat;

        }
    }

    return nullptr; //return if name does not match existing names
}

const char* genderCat( const enum Genders gender ){
    switch( gender ) {
        case Unknown:
            return "Unknown";
        case Male:
            return "Male";
        case Female:
            return "Female";
    }
    throw logic_error("Animal Farm2: gender name not mapped to string value");

}

const char* breedCat( const enum Breeds breed ){
    switch( breed ) {
        case UNKNOWN_BREED:
            return "Uknown breed";
        case MAINE_COON:
            return "Maine Coon";
        case MANX:
            return "Manx";
        case SHORTHAIR:
            return "Shorthair";
        case PERSIAN:
            return "Persian";
        case SPHYNX:
            return "Sphynx";
    }
    throw logic_error("Animal Farm2: breed name not mapped to string value");

}

const char* colorCat( const enum Color color ){
    switch( color ) {
        case Black:
            return "Black";
        case White:
            return "White";
        case Red:
            return "Red";
        case Blue:
            return "Blue";
        case Green:
            return "Green";
        case Pink:
            return "Pink";
    }
    throw logic_error("Animal Farm2: color name not mapped to string value");

}