///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Cat.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   05_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <glob.h>

#include "Mammal.h"

using namespace std;

class Cat : public Mammal {
public:
    static const string SPECIES_NAME;
    static const Weight::t_weight MAX_WEIGHT;

protected:
    string name;
    bool isCatFixed;

public:
    //create cat w/min fields
    explicit Cat( const string& newName ) : Mammal( MAX_WEIGHT, SPECIES_NAME ){
        if ( !validateName( newName )) {
            throw out_of_range("Cat needs a name");
        }
        name = newName;
        isCatFixed = false;

        Cat::validate();
    }

    Cat( const string&              newName,
         const Color                newColor,
         const bool                 newIsFixed,
         const Gender               newGender,
         const Weight::t_weight     newWeight
         ) : Mammal( newColor, newGender, newWeight, MAX_WEIGHT, SPECIES_NAME ){
            if( !validateName( newName ) ){
                throw out_of_range(" Cat needs a name");
            }
            name = newName;
            isCatFixed = newIsFixed;

            Cat::validate();
    }

public:
    string getName() const noexcept;    //get cat name
    void setName( const string& newName );  //Set cat name, can't be empty

    bool isFixed() const noexcept;
    void fixCat() noexcept;

public:
    string speak() const noexcept override; //have cat speak 'meow'
    void dump() const noexcept  override ;  //print cat
    bool validate() const noexcept override;    //check if everything is fine

public:
    static bool validateName( const string& newName );  //check newName is good
};

