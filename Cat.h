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


#define MAX_CAT_NAME (30)

typedef float Weight;

typedef size_t NumCats;

class Cat {
protected:
    char            name[MAX_CAT_NAME];
    enum Genders    gender;
    enum Breeds     breed;
    bool            isFixed;
    Weight          weight;

public:
    Cat*            next;   //Next pointer

private:
    void zeroOutMember();

public:
    Cat();
    Cat( const char *newName, const Genders newGender, const Breeds newBreed, const Weight newWeight );
    virtual ~Cat();

public:
    const char *getName();
    void setName( const char* newName );
    Genders getGender();
    Breeds getBreed();
    bool isFixed();
    void fixCat();
    Weight getWeight();
    void setWeight( Weight newWeight );


protected:
public:
    void setGender( Genders newGender );
    void setBreed( Breeds newBreed );

public:
    bool pront();
    bool validate();

public:
    static bool validateName( const char* newName );
    static bool validateGender( const Genders newGender );
    static bool validateBreed( const Breeds newBreed );
    static bool validateWeight( const Weight newWeight );

};
