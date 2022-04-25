///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file List.cpp
/// @version 1.0
///
/// @author Carl Domingo <carld20@hawaii.edu>
/// @date   23_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <cassert>

#include "List.h"
#include "Node.h"

using namespace std;

Node* List::get_next(const Node *currentNode) {
    if( currentNode == nullptr ){
        throw invalid_argument("AnimalFarm3: currentNode must have a value");
    }

    return currentNode->next;
}
void List::deleteAllNodes() noexcept {
    assert( validate() );
    while( head != nullptr ) {
        pop_front();
    }
#ifdef DEBUG
    cout << "Animal Farm3: All Nodes have been deleted" << endl ;
#endif
    assert( validate() );
}

bool List::empty() const noexcept{
    return (head == nullptr );
}

unsigned int List::size() const noexcept{
    return count;
}

bool List::isIn( Node* aNode ) const {
    if( aNode == nullptr ){
        cout << "AnimalFarm3: aNode needs a value" << endl;
        return false;
    }

    Node* currentNode = head;

    while( currentNode != nullptr ){
        if( aNode == currentNode ){
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}

bool List::isSorted() const noexcept {
    assert( validate() );

    if( count <= 1 ){
        return true;
    }

    for( Node* i = head; i->next != nullptr; i = i->next ){
        if( *i > *i->next ){
            return false;
        }
    }
    return true;
}

Node* List::get_first() const noexcept {
    return head;
}

