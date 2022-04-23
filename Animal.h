///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Animal.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Apr_2022
///////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include <iomanip>

#include "Node.h"
#include "Gender.h"
#include "Weight.h"

using namespace std;

#define PRINT_HEADING_DUMP \
    cout << setw(80) << setfill( '=' ) << "" << endl

#define FORMAT_LINE_DUMP( className, member )         \
    cout << setfill( ' ' ) \
              << left \
              << boolalpha \
              << setw( 8) << (className)             \
              << setw(20) << (member)                \
              << setw(52)

class Animal : public Node {
public:
    static const string KINGDOM_NAME;

private:
    string species;
    string classification;
    Gender gender = Gender::Unknown_Gender;
    Weight weight;

public:
    //create animal w/min req fields
    Animal( const Weight::t_weight newMaxWeight
            ,const string&     newClassification
            ,const string&     newSpecies
    );
    //create animal w/all fields
    Animal( const Gender           newGender
            ,const Weight::t_weight newWeight
            ,const Weight::t_weight newMaxWeight
            ,const string&     newClassification
            ,const string&     newSpecies
    );

public:
    string getKingdom() const noexcept;
    string getClassification() const noexcept;
    string getSpecies() const noexcept;

    Gender getGender() const noexcept;

    Weight::t_weight getWeight() const noexcept;
    void setWeight( const Weight::t_weight newWeight );

public:
    static bool validateClassification( const std::string& checkClassification ) noexcept;
    static bool validateSpecies( const std::string& checkSpecies ) noexcept;

protected:
    void setGender( const Gender newGender);

public:
    virtual string speak() const noexcept = 0;

public:
    void dump() const noexcept override;
    bool validate() const noexcept override;
};