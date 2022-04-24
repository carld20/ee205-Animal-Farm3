///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Mammal.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   22_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include "Mammal.h"

const string Mammal::MAMMAL_NAME = "Mammilian";

Mammal::Mammal(const Weight::t_weight newMaxWeight, const std::string &newSpecies) : Animal( newMaxWeight, MAMMAL_NAME, newSpecies){
    Animal( newMaxWeight, MAMMAL_NAME, newSpecies );


}