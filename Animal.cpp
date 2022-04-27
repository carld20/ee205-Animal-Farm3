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
#include "Node.h"

using namespace std;

const string Animal::KINGDOM_NAME = "Animalia";

bool Animal::validate() const noexcept {
    assert( Node::validate() );
    assert( !getKingdom().empty() );
    assert( validateClassification(getClassification() ) );
    assert( validateSpecies( getSpecies() ) );
    assert( weight.validate() );

    return true;
}


string Animal::getKingdom() const noexcept{
    return KINGDOM_NAME;
}

void Animal::setGender(const Gender newGender) {
    if( gender != Gender::Unknown_Gender ){
        throw invalid_argument("AnimalFarm3: Gender can't be changed");
    }
    assert( gender == Gender::Unknown_Gender );
    validate();
    gender = newGender;
}

string Animal::getClassification() const noexcept {
    return classification;
}

string Animal::getSpecies() const noexcept {
    return species;
}

Gender Animal::getGender() const noexcept {
    return gender;
}

void Animal::setWeight(const Weight::t_weight newWeight) {
    validate();
    weight.setWeight( newWeight );
    validate();

}

Weight::t_weight Animal::getWeight() const noexcept {
    return weight.getWeight();
}

bool Animal::validateSpecies(const string& checkSpecies) noexcept {
    if( checkSpecies.length() <= 0 ){
        cout << "AnimalFarm3: species must be specified" << endl;
        return false;
    }
    return true;
}

bool Animal::validateClassification(const string &checkClassification) noexcept {
    if( checkClassification.length() <= 0 ){
        cout << "AnimalFarm3: classification must be specified" << endl;
        return false;
    }
    return true;
}

Animal::Animal(const Weight::t_weight newMaxWeight, const string& newClassification, const string& newSpecies) : Node(), weight(Weight::POUND, newMaxWeight) {
    if( !validateClassification( newClassification ) ){
        throw invalid_argument("AnimalFarm3: Classification of animal is not valid");
    }
    classification = newClassification;
    if( !validateSpecies( newSpecies ) ){
        throw invalid_argument("AnimalFarm3: Species of animla is not valid");
    }
    species = newSpecies;
    Animal::validate();
}

Animal::Animal(const Gender newGender, const Weight::t_weight newWeight, const Weight::t_weight newMaxWeight,
               const string& newClassification, const string& newSpecies) : Node(), weight( newWeight, newMaxWeight){
    if( !validateClassification( newClassification ) ){
        throw invalid_argument("AnimalFarm3: Classification of animal is not valid");
    }
    classification = newClassification;

    if( !validateSpecies( newSpecies ) ){
        throw invalid_argument("AnimalFarm3: Species of animal is not valid");
    }
    species = newSpecies;
    setGender( newGender );
    Animal::validate();
}

void Animal::dump() const noexcept{
    assert( validate() );
    PRINT_HEADING_DUMP;
    Node::dump();

    FORMAT_LINE_DUMP("Animal", "this")              << this << endl;
    FORMAT_LINE_DUMP("Animal", "kingdom")           << getKingdom() << endl;
    FORMAT_LINE_DUMP("Animal", "classification")    << getClassification() << endl;
    FORMAT_LINE_DUMP("Animal", "species")           << getSpecies() << endl;
    FORMAT_LINE_DUMP("Animal", "gender")            << getGender() << endl;
    FORMAT_LINE_DUMP("Animal", "weight")            << getWeight() << endl;
}