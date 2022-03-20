///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "catDatabase.h"

extern unsigned int addCat (const char* newName,
                            const enum Genders newGender,
                            const enum Breeds newBreed,
                            const bool newFixed,
                            const float newWeight,
                            const enum Color newCollarColor1,
                            const enum Color newColllarColor2,
                            const unsigned long long newLicense
);
