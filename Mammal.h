///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Mammal.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   22_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Animal.h"
#include "Color.h"



class Mammal : public Animal {
public:
    static const std::string MAMMAL_NAME;

protected:
    Color color = Color::Unknown_Color;

public:
    //create mammal w/min req
    Mammal( const Weight::t_weight newMaxWeight
            ,const std::string&     newSpecies
    ) : Animal( newMaxWeight, MAMMAL_NAME, newSpecies ) {};
    //mammal w/all req
    Mammal( const Color            newColor
            ,const Gender           newGender
            ,const Weight::t_weight newWeight
            ,const Weight::t_weight newMaxWeight
            ,const std::string&     newSpecies
    ) : Animal( newGender, newWeight, newMaxWeight, MAMMAL_NAME, newSpecies ) {
        setColor( newColor );
    };

public:
    Color getColor() const noexcept { return color; }
    void setColor( const Color newColor ) noexcept { color = newColor; }

public:
    void dump() const noexcept override;
};