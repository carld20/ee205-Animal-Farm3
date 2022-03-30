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
#include <glob.h>

#include "catDatabase.h"

extern bool updateCatName( const NumCats index, const char* name );
extern bool fixCat( const NumCats index );
extern bool updateCatWeight( const NumCats index,  const Weight weight );
extern bool updateCatCollar1( const NumCats index, const enum Color color );
extern bool updateCatCollar2( const NumCats index, const enum Color color );
extern bool updateLicense( const NumCats index, const unsigned long long license );
