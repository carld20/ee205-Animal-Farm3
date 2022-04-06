///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   05_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cstring>
#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cassert>

#include "Cat.h"
#include "reportCats.h"

using namespace std;

void Cat::zeroOutMember() {
    memset(name, 0, MAX_CAT_NAME);
    gender = Unknown;
    breed = UNKNOWN_BREED;
    isCatFixed = false;
    weight = UNKNOWN_WEIGHT;
    next = nullptr;

}

Cat::Cat(){
    zeroOutMember();

}

Cat::Cat( const char *newName, const Genders newGender, const Breeds newBreed, const Weight newWeight ) : Cat(){
    setName( newName );
    setWeight( newWeight );
    setBreed( newBreed );
    setGender( newGender );

    assert(validate());

}

Cat::~Cat(){
    zeroOutMember();

}

const char *Cat::getName(){
    return name;

}

void Cat::setname( const char *newName ){
    validateName( newName );
    memset( name, 0 , MAX_CAT_NAME );
    strcpy( name, newName );

}

Genders Cat::setGender(){
    return gender;

}

Breeds Cat::setBreed() {
    return breed;

}

bool Cat::isFixed(){
    return isCatFixed;

}

