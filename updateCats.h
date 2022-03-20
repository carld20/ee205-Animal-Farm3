///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Project - EE 205 - Spr 2022
///
/// @file updateCats.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdbool.h>

#include "catDatabase.h"

extern bool updateCatName( const size_t index, const char* name );
extern bool fixCat( const size_t index );
extern bool updateCatWeight( const size_t index,  const float weight );
extern bool updateCatCollar1( const size_t index, const enum Color color );
extern bool updateCatCollar2( const size_t index, const enum Color color );
extern bool updateLicense( const size_t index, const unsigned long long license );
