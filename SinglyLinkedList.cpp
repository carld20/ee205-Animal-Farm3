///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file SinglyLinkedList.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   22_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>
#include <iostream>

#include "SinglyLinkedList.h"


using namespace std;

#ifdef TRACE
    static void TRACE_OUT( const string operation, const string functionName ){
        cout << "AnimalFarm3: " << operation << " " << functionName << endl;
    }

    #define TRACE_START TRACE_OUT("Start", __FUNCTION__);
    #define TRACE_END TRACE_OUT("End", __FUNCTION__);
#else
    #define TRACE_START
    #define TRACE_END
#endif


SinglyLinkedList::SinglyLinkedList() {
        assert( SinglyLinkedList::validate() );
    }

void SinglyLinkedList::push_front(Node *newNode) {
    TRACE_START

    if( newNode == nullptr ){
        throw invalid_argument("AnimalFarm3: newNode can't be nullptr");
    }

    if( !newNode->validate() ){
        throw domain_error("AnimalFarm3: newNode is not valid");
    }

    if( isIn( newNode ) ){
        throw logic_error("AnimalFarm3: Node is already in container");
    }

    assert( validate() );

    if( head != nullptr ){
        newNode->next = head;
        head = newNode;
    }
    else{
        newNode->next = nullptr;
        head = newNode;
    }

    count++;

    assert( validate() );

    TRACE_END;
}

Node* SinglyLinkedList::pop_front() noexcept {
    TRACE_START

    if( head == nullptr ){
        return nullptr;
    }

    assert( validate() );

    Node* returnValue = head;

    if( head->next != nullptr ){
        head - head->next;
    }
    else{
        head = nullptr;
    }

    returnValue->next = nullptr;

    count--;

    assert( validate() );

    assert( returnValue->validate() );

    TRACE_END

    return returnValue;
}


void SinglyLinkedList::insert_after(Node *currentNode, Node *newNode) {
    TRACE_START

    if( head == nullptr ){
        throw logic_error("AnimalFarm3: List is empty");
    }

    if( currentNode == nullptr ){
        throw invalid_argument("AnimalFarm3: currentNode must have a value");
    }
    if( !isIn( currentNode ) ){
        throw logic_error("AnimalFarm3: currentNode must be in the list");
    }

    if( newNode == nullptr ){
        throw invalid_argument("AnimalFarm3: newNode must have a value");
    }

    if( !newNode->validate() ) {
        throw domain_error( "AnimalFarm3: newNode is not valid" );
    }

    if( isIn( newNode ) ){
        throw logic_error("AnimalFarm3: newNode is already in the list");
    }

    assert( validate() );

    newNode->next = currentNode->next;
    currentNode->next = newNode;

    count++;
    assert( validate() );

    TRACE_END
}

void SinglyLinkedList::dump() const noexcept{
    cout << "SinglyLinkedList: head=[" << head << "]" << endl;
    for( Node* currentNode = head; currentNode != nullptr; currentNode = currentNode->next ){
        currentNode->dump();
    }
}

bool SinglyLinkedList::validate() const noexcept{
    if( head == nullptr ){
        assert( count == 0 );
        assert( empty() );
    }
    else{
        assert( count != 0 );
        assert( !empty() );
    }

    if( head != nullptr ){
        if( head->next == nullptr ){
            assert( count == 1);
        }
    }

    unsigned int nextCount = 0;
    Node* currentNode = head;

    while( currentNode != nullptr ){
        assert( currentNode->validate() );
        nextCount++;
        currentNode = currentNode->next;
    }

    assert( size() == nextCount );

    return true;
}