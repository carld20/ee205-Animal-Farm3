///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Weight.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   22_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ostream>
#include <string>

using namespace std;

class Weight {
public:
    enum UnitOfWeight {POUND, KILO, SLUG};
    typedef float t_weight;

public:
    Weight() noexcept;
    Weight( t_weight newWeight );
    Weight( UnitOfWeight newUnitOfWeight ) noexcept;
    Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight );
    Weight( t_weight newWeight, t_weight maxWeight );
    Weight( UnitOfWeight newUnitOfWeight, t_weight newMaxWeight );
    Weight( t_weight newWeight, UnitOfWeight newUnitOfWeight, t_weight newMaxWeight );

public:
    bool isWeightKnown() const noexcept;
    bool hasMaxWeight() const noexcept;
    t_weight getWeight() const noexcept;
    t_weight getWeight( UnitOfWeight weightUnits ) const noexcept;
    t_weight getMaxWeight() const noexcept;

public:
    UnitOfWeight getWeightUnit() const noexcept;

public:
    void setWeight( t_weight newWeight );
    void setWeight( t_weight newWeight, UnitOfWeight weightUnits );

    bool isWeightValid( t_weight checkWeight ) const noexcept;
    void dump() const noexcept;
    bool validate() const noexcept;
    bool operator==(const Weight &rhs_Weight ) const;
    bool operator<( const Weight &rhs_Weight ) const;
    Weight &operator+=( float rhs_addToWeight );

public:
    static float fromKiloToPound(float kilogram ) noexcept; //kg to lb conv
    static float fromPoundToKilo( float pound ) noexcept; //lb to kg conv
    static float fromSlugToPound( float slug ) noexcept; //slug to lb conv
    static float fromPoundToSlug( float pound ) noexcept; //lb to slug conv
    static float convertWeight( float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit );

public:
    static const t_weight UNKNOWN_WEIGHT;
    static const t_weight KILOS_IN_POUND; //kg to pound constant
    static const t_weight SLUGS_IN_POUND;  //slug to pound constant
    static const string POUND_LABEL; //lb label
    static const string KILO_LABEL; //kg label
    static const string SLUG_LABEL; //slug label

private:
    void setMaxWeight( float newMaxWeight );

    bool bIsKnown = false;
    bool bHasMax = false;
    enum UnitOfWeight unitOfWeight = POUND;
    t_weight weight{};
    t_weight maxWeight {};

};
