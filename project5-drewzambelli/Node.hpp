// Name: Drew Zambelli
// Due Date: Friday, October 28
// Node.hpp
// Project 4 - expanding from Lab 1, 2 and 3, now we are adding LinkedLists and additional functionality 
// We are modifying various files to view Polls and Promotional posts and updating our Network so that we can 
// store any of these types of posts in our feed. In addition, we are creating methods to edit and monitor content
// and remove language that should not be shown

/*
Node class interface for term projects
CSCI 235 Fall 2022
Hunter College
*/


#ifndef Node_
#define Node_

#include <iostream>

template<typename ItemType>
class Node {

    public:
        /*
            Default Constructor
        */
        Node();

        /*
            Parametarized Constructor
            @param item - the item to be constructed
            @param next_node - the next node to point to
         */
        Node(const ItemType& item, Node<ItemType> *next_node = nullptr);

        /*
            Setter function for node item
            @param anItem - the item to be set in item_
        */
        void setItem(const ItemType &anItem);

        /*
            Setter function for pointer to next node in chain
            @param nextNodePtr - the nextNodePtr to be set in next_
        */
        void setNext(Node<ItemType> *nextNodePtr);

        /*
            @return returns the value for item_
        */
        ItemType getItem() const;

        /*
            @return returns the value for next_
        */
        Node<ItemType> *getNext() const;


    private:
        ItemType item_;
        Node<ItemType> *next_;
};

#include "Node.cpp"
#endif