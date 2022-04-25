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

#include <stdexcept>
#include <string>
#include <cassert>
#include <iomanip>
#include <iostream>

#include "Cat.h"

using namespace std;

const string Cat::SPECIES_NAME = "Felis Catus";
const Weight::t_weight MAX_WEIGHT = 40;

string Cat::getName() const noexcept{
    assert( validate() );
    return name;
}

void Cat::setName(const string &newName) {
    assert( validateName( newName) );
    name = newName;
}

string Cat::speak() const noexcept{
    return "Meow";
}

void Cat::dump() const noexcept {
    assert( validate() );

    Mammal::dump();
    assert( validateName( getName() ) );

    FORMAT_LINE_DUMP("Cat", "name") << getName() << endl;
    FORMAT_LINE_DUMP("Cat", "isFixed") << isFixed() << endl;
}

bool Cat::validate() const noexcept{
    Mammal::validate();
    assert( validateName( getName() ) );

    return true;
}

bool Cat::isFixed() const noexcept {
    return isCatFixed;
}

void Cat::fixCat() noexcept {
    Cat::isCatFixed = true;
}

bool Cat::validateName( const string& newName ){
    if( !newName.empty() ){
        cout << "AnimalFarm3: Cat needs a name" << endl;    //initially had throw but throw should be better with void functions
        return false;
    }
    return true;
}

