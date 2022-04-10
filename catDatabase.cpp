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

#include <cstring>
#include <stdexcept>
#include <cassert>
#include <iostream>
#include <cstdio>

#include "catDatabase.h"
#include "reportCats.h"
#include "Cat.h"

using namespace std;

int numberCats = 0;

Cat* catDatabaseHeadPointer;

//Checks if database is not negative
extern bool validateDatabase(){
    int validCats = 0;

    for( Cat* iCat = catDatabaseHeadPointer; iCat != nullptr; iCat = iCat->next ){
        if( !iCat->validate() ){
            return false;

        }

        Cat* foundCat = findCatByName( iCat->getName() ) ); //make findCatByName in reportCats
        if( foundCat != iCat ){
            cout << "Animal Farm2: Warning: Found a similar name ["<< iCat->getName() << "]" << endl;

        }
        validCats++;
    }

    if( validCats != numberCats ){
        cout << "Animal Farm2: Error: numberofCats [" << numberCats << "] does not equal [" << validCats << "]" << endl;

        return false;

    }

    return true;

}

//Reset database
void initializeDatabase(){
    if( catDatabaseHeadPointer != nullptr ){
        throw logic_error("Animal Farm2: delete old database first");

    }

    assert( validateDatabase() );

}

bool isCatExist( const Cat* aCat ){
    assert( aCat != nullptr );

    for( Cat* iCat = catDatabaseHeadPointer; iCat != nullptr; iCat = iCat->next ){
        if( iCat == aCat ){
            return true;

        }
    }
    assert( validateDatabase());

    return false; //if cat not found
}



/*bool isFull(){
    validateDatabase();
    if( numCats >= MAX_CATS ){
        return true;
    }
    else{
        return false;
    }
}*/

//Check if index is ok
/*extern bool isIndexValid( const NumCats index ){
    if( index <= 0 ){
        return false;
    }
    if( index >= numCats ) {
        return false;
    }
    return true;

}*/

//Check if name is ok
/*bool isNameValid( const char* name ){
    if( name == NULL ){
        return false;
    }
    if( strlen( name ) > MAX_CAT_NAME - 1 ){
        return false;
    }

    return true;
}*/

//check if weight is ok
/*bool isWeightValid( const Weight weight ){
    if( weight <= 0 ){
        return false;
    }
    else{
        return true;
    }
}*/

//Delete cat info
/*void wipeCat(const NumCats index ){
    assert( isIndexValid( index ) );
    memset( &cats[index], 0, sizeof( struct Cat ) );
}*/

//swap cats' index
/*bool swapCat( const NumCats x, const NumCats y ){
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
}*/