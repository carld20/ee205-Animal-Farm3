///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Gender.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <iostream>

using namespace std;

enum class Gender{Unknown_Gender=0, Male, Female};

inline ostream& operator<<( ostream& lhs_stream, const Gender& rhs_Gender ){
    switch( rhs_Gender ){
        case Gender::Unknown_Gender:
            lhs_stream << "Unknown Gender";
            break;
        case Gender::Female:
            lhs_stream << "Female";
            break;
        case Gender::Male:
            lhs_stream << "Male";
            break;
        default:
            throw out_of_range( "Animal Farm3: Gender not mapped to a string" );
    }
    return lhs_stream;
}

