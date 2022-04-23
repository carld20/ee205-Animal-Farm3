///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file Node.h
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   19_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>

#include "Animal.h"

using namespace std;




class Node{
    friend class List;
    friend class SinglyLinkedList;

protected:
    Node* next = nullptr;

    static bool compareByAddress( const Node* node1, const Node* node2 ){
        if( node1 > node2 )
            return true;
        return false;
    }

public:
    virtual void dump() const {
        FORMAT_LINE_DUMP( "Node", "this" ) << this << endl;
        FORMAT_LINE_DUMP( "Node", "this" ) << next << endl;
    }

    virtual bool validate() const noexcept{
        if( next == nullptr ){
            return true;
        }
        if( next == next->next ){
            cout << "Animal Farm3: Recursive loop detected: points to itself";
            return false;
        }
        return true;
    }

    virtual bool operator>( const Node& rightSide ){
        return compareByAddress( this, &(Node&)rightSide );
    }
};

