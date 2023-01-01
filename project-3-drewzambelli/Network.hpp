
// Name: Drew Zambelli
// Due Date: Tuesday, October 11
// Network.hpp
// Project 3 - expanding from Lab 1 and 2, now we are creating the Network class and 
// modifying the Account class to be able to operate on the Network

#ifndef NETWORK_H
#define NETWORK_H

#include "Post.hpp"
#include "Account.hpp"

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

        void populateNetwork(const std::string input_file); //to populate the network

        void operator-=(const Network& other_network); //overload the operator

        void printFeedForAccount(T& account_feed_to_print) const; //print the feed of the Account

        bool authenticateFollow(T& account, const std::string to_be_followed); //to make sure the account can follow the other account

        bool addToFeed(const Post& add_to_feed); //to add a post to the feed of an account

        //helper function - not sure if it works
        bool getUsernameAccount(const std::string input_account) const;

    private:
        static const int NETWORK_DEFAULT_CAPACITY = 200; //default capacity of array bag
        T* bagArrPointers[NETWORK_DEFAULT_CAPACITY]; //array that stores pointers to items (capacity 200)
        int bagAccountCount; //current number of accounts in network
        std::vector<Post> all_posts_vector; //vector of all posts posted by account in network

        
        int getIndexOf(const std::string target) const; //private member function

};

#include "Network.cpp"
#endif