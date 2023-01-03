// Name: Drew Zambelli
// Due Date: Friday, October 28
// Network.hpp
// Project 4 - expanding from Lab 1, 2 and 3, now we are adding LinkedLists and additional functionality 
// We are modifying various files to view Polls and Promotional posts and updating our Network so that we can 
// store any of these types of posts in our feed. In addition, we are creating methods to edit and monitor content
// and remove language that should not be shown

#ifndef NETWORK_H
#define NETWORK_H

#include "Post.hpp"
#include "Account.hpp"
#include "LinkedList.hpp"


#include <vector>

template <typename T>
class Network {
    
    public:
        //default constructor
        Network();

        int getSizeOfNetwork() const; // returns the current size of the network

        bool isEmpty() const; //checks to see if bag is empty

        bool addAccount(T* new_account_entry); //adds account to network

        bool removeAccount(const T* account_entry); //removes account from network

        void clear(); //clear the bag/network by setting variable to 0

        bool containsAccount(const T* target_account) const; //find a specific account

        void populateNetwork(const std::string input_file); //build network from txt file

        void operator-=(const Network& other_network);

        void printFeedForAccount(T& account_feed_to_print) const;

        bool authenticateFollow(T& account, const std::string to_be_followed)const; //make sure account can follow

        bool addToFeed(Post* add_to_feed); //add to the feed

        //Content Striking function for lab 4 - remove if contains function
        int removeIfContains(std::string &to_remove);

        //lab 3 helper function
        bool getUsernameAccount(const std::string input_account) const;

        //lab 4 helper function for removePost function
        void helperRemovePostNet(Post* to_remove);

        //lab 4 helper function for updatePost feed adjustment
        void feedEdit(Post* post);

    private:
        static const int NETWORK_DEFAULT_CAPACITY = 200; //default capacity of array bag
        T* bagArrPointers[NETWORK_DEFAULT_CAPACITY]; //array that stores pointers to items (capacity 200)
        int bagAccountCount; //current number of accounts in network
        //std::vector<Post> all_posts_vector; //vector of all posts posted by account in network
        LinkedList<Post*> NetworkLinkedList; //pointers to Posts in a LinkedList


        //private method
        int getIndexOf(const std::string target) const;    

};

#include "Network.cpp"
#endif