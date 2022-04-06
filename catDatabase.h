///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdbool.h>
#include <stddef.h>

#include "Cat.h"

#define MAX_CATS (30)
#define MAX_CAT_NAME (30)




extern NumCats numCats;

enum Genders { Male, Female, Unknown };
enum Breeds { UNKNOWN_BREED, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX };
enum Color { Black, White, Red, Blue, Green, Pink };

struct Cat {
    char                    name[MAX_CAT_NAME];
    enum Genders            gender;
    enum Breeds             breed;
    bool                    isFixed;
    Weight                  weight;
    enum Color              collarColor1;
    enum Color              collarColor2;
    unsigned long long      license;
};

extern struct Cat cats[MAX_CATS];

//Implement initializeDatabase
extern void initializeDatabase();

//Implement isFull
extern bool isFull();

//Implement validateDatabase
extern bool validateDatabase();

//Implement isIndexValid
extern bool isIndexValid( const NumCats index );

//Implement isNameValid
extern bool isNameValid( const char* name );

//Implement isWeightValid
extern bool isWeightValid( const Weight weight );

//Implement wipeCat
extern void wipeCat( const NumCats index );

//Implement swapCat
extern bool swapCat( const NumCats x, const NumCats y);