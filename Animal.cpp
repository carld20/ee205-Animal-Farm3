///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cassert>

#include "Animal.h"

using namespace std;

const string Animal::KINGDOM_NAME = "Animalia";

bool Animal::validate() const noexcept {
    try {
        validateClassification(classification);
        validateSpecies(species);
    }
    catch( exception const& e ){
        cout << e.what() << endl;
        return false;
    }
    return true;
}

string Animal::getKingdom() const noexcept{
    assert( validate() );
    return KINGDOM_NAME;
}

void Animal::setGender(const Gender newGender) {
    assert( validate() );
    gender = newGender;
}

string Animal::getClassification() const noexcept {
    assert( validate() );
    return classification;
}

string Animal::getSpecies() const noexcept {
    assert( validate () );
    return species;
}

Gender Animal::getGender() const noexcept {
    assert( validate() );
    return gender;
}

void Animal::setWeight(const Weight::t_weight newWeight) {
    assert( validate() );
    weight = newWeight;

}

Weight::t_weight Animal::getWeight() const noexcept {
    assert( validate() );
    return weight;
}

bool Animal::validateSpecies(const std::string &checkSpecies) noexcept {

}

