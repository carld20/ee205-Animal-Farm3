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
#include "Weight.h"

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

bool Animal::validateSpecies(const string& checkSpecies) noexcept {
    if( checkSpecies.length() <= 0 ){
        throw invalid_argument("AnimalFarm3: species must be specified");
        return false;
    }
    return true;
}

bool Animal::validateClassification(const string &checkClassification) noexcept {
    if( checkClassification.length() <= 0 ){
        throw invalid_argument("AnimalFarm3: classification must be specified");
        return false;
    }
    return true;
}

Animal::Animal(const Weight::t_weight newMaxWeight, const string &newClassification, const string &newSpecies) {
    Weight::t_weight maxWeight = newMaxWeight;
    assert( validate () );
}

Animal::Animal(const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight,
               const string &newClassification, const string &newSpecies): Animal( newMaxWeight, &newClassification, &newSpecies) {
    setGender( newGender );
    weight = newWeight;
    assert( validate() );

}