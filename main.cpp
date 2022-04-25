///////////////////////////////////////////////////////////////////////////////
////          University of Hawaii, College of Engineering
///// @brief  Lab 07d - AnimaL Farm1 - EE 205 - Spr 2022
////
//// Usage:  Animal Farm1
////
//// File: main.c
////
////
////
//// @author Carl Domingo <carld20@hawaii.edu>
//// @date   03/08/2022
/////////////////////////////////////////////////////////////////////////////////

#include <cstdlib>  // For EXIT_SUCCESS / EXIT_FAILURE
#include <iostream>

#include "Cat.h"
#include "SinglyLinkedList.h"

using namespace std ;


int main() {
    SinglyLinkedList catDB ;

    catDB.push_front( new Cat( "Brae",  Color::CREAM,  true, Gender::Male,   13.2) ) ;
    catDB.push_front( new Cat( "Dom",  Color::BLACK,  true, Gender::Male,   7.4 ) ) ;
    catDB.push_front( new Cat( "Kebin", Color::BROWN,  true, Gender::Female, 18.9 ) ) ;
    catDB.push_front( new Cat( "Pol",  Color::CALICO, true, Gender::Female, 1.3 ) ) ;
    catDB.push_front( new Cat( "Dan",  Color::WHITE,  true, Gender::Female, 15.4 ) ) ;
    catDB.push_front( new Cat( "Jacob",  Color::BLACK,  false, Gender::Male, 12.0 ) ) ;
    catDB.push_front( new Cat( "Kurris",  Color::RED,  false, Gender::Female, 4.5 ) ) ;
    catDB.push_front( new Cat( "Izaiah",  Color::CALICO,  true, Gender::Female, 4.3 ) ) ;
    catDB.push_front( new Cat( "Seabass",  Color::CREAM,  false, Gender::Male, 2.2 ) ) ;
    catDB.push_front( new Cat( "Jeriel",  Color::BLACK,  true, Gender::Female, 10.7 ) ) ;


    catDB.insert_after(catDB.get_first(), new Cat( "Chili", Color::GINGER, true, Gender::Female,   1.5 ) );

    for( Animal* pAnimal = (Animal*)catDB.get_first() ; pAnimal != nullptr ; pAnimal = (Animal*)List::get_next( (Node*)pAnimal ) ) {
        cout << pAnimal->speak() << endl;
    }

    cout << "Done with AnimalFarm3" ;
    return( EXIT_SUCCESS ) ;
}



