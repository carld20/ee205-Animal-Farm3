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

#include "Animal.h"

using namespace std;

const string Animal::KINGDOM_NAME = "Animalia";


Animal::Animal(const Weight::t_weight newMaxWeight, const string& newClassification, const string& newSpecies) {
    setWeight( newMaxWeight );
    classification = newClassification;
    species = newSpecies;
}

Animal::Animal(const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight,
               const string &newClassification, const string &newSpecies) {
    setGender( newGender );
    //set weight and maxWeight
    classification = newClassification;
    species = newSpecies;
}

string Animal::getKingdom() const noexcept {
    cout << KINGDOM_NAME;
}

string Animal::getSpecies() const noexcept {
    cout <<
}
