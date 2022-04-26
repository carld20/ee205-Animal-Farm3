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

#include <cassert>
#include <iostream>
#include <iomanip>

#include "Mammal.h"

const string Mammal::MAMMAL_NAME = "Mammilian";


void Mammal::dump() const noexcept{
    assert( validate() );
    Animal::dump();

    FORMAT_LINE_DUMP("Mammal", "color") << color << endl;
}