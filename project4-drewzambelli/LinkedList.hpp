// Name: Drew Zambelli
// Due Date: Friday, October 28
// LinkedList.hpp
// Project 4 - expanding from Lab 1, 2 and 3, now we are adding LinkedLists and additional functionality 
// We are modifying various files to view Polls and Promotional posts and updating our Network so that we can 
// store any of these types of posts in our feed. In addition, we are creating methods to edit and monitor content
// and remove language that should not be shown

/*
List class interface for term projects
CSCI 235 Fall 2022
Hunter College
*/


#ifndef LinkedList_
#define LinkedList_

#include <iostream>
#include "Node.hpp"


template<typename ItemType>
class LinkedList {


    public:
        /* Default constructor*/
        LinkedList();

        /*Copy Constructor*/
        LinkedList(const LinkedList<ItemType>& copiedList);

        //reverse copy method
        void reverseCopy(LinkedList<ItemType>& revCopyList);

        //Move specific item to top function
        bool moveItemToTop(ItemType& item);

        //had to comment out destructor because it created issues
        /* Destructor */
        //~LinkedList();

        /*
            @param  item: the item to insert in the list
            @param  position: the position where to inserted
            @pre position is a valid place within the list, otherwise false will be returned
            @return   :  true if the item has been inserted in the caller list,
                        false otherwise
            @post     : Inserts item in  list at  position

        **/
        bool insert(const ItemType &item, const int &position);

        /*
            @param  position:  the position where to remove
            @pre position is a valid place within the list, otherwise false will be returned
            @pre      : returns true if the item at position has been removed from the list,
                        false otherwise
            @post     : removes node at  position
        **/
        bool remove(const int &position);


        /* @return  : the size of the list */
        int getSize() const;


        /* @return  : the head pointer
        This function is for grading purposes*/
        Node<ItemType> *getHeadPtr() const;



        /* @return  : true if the list is empty, false otherwise */
        bool isEmpty() const;


        /*
            @post   : removes all items from the caller list
        **/
        void clear();

        /*
            @param   item : the item to find in the list
            @pre      : takes item object and checks if exist in list and return
            @return   : returns the position (index) of object in the list

        **/
        int getIndexOf(const ItemType &item) const;


    private:
        /*
            @param   pos : the position of the item
            @pre     : pos is a valid place in the list
            @return  : a pointer to the node at pos, if pos is invalid, returns nullptr
        **/
        Node<ItemType> *getAtPos(const int &pos) const;
        Node<ItemType> *head_;
        size_t size_;
};

#include "LinkedList.cpp"
#endif
