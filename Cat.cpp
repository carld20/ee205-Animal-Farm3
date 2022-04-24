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

#include <string>

#include "Cat.h"

const string Cat::SPECIES_NAME = "Felis Catus";
const Weight::t_weight MAX_WEIGHT = 40;

Cat::Cat(const string &newName): Mammal( MAX_WEIGHT, SPECIES_NAME ) {

}