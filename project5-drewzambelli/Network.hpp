/****************************************************************************************************************************
Title         :   Network.hpp
Author        :   Dream Team
Description   :   header/interface files for Network class
****************************************************************************************************************************/
// Name: Drew Zambelli
// Due Date: Tuesday, November 22
// Network.hpp
// Project 5 - expanding from Labs 1, 2, 3, and 4, we are adding additional functionality to allow users
// to sort the Network's feed by the username of the account that posted each Post in the feed. To do so, we
// are implementing a Bubble Sort.

#ifndef NETWORK_
#define NETWORK_

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Post.hpp"
#include "LinkedList.hpp"
#include "Account.hpp"

template <typename ItemType>
class Network
{

public:
    /** default constructor**/
    Network();

    /**
     @return account_count_ : the current size of the bag
    **/
    int getSizeOfNetwork() const;

    /**
     @return true if account_count_ == 0, false otherwise
     **/
    bool isEmpty() const;

    /**
       @param            : a POINTER to the item that will be added to the Network
       @return           : bool- true  if the item was successfully added, false otherwise
       @post             : stores a pointer to the item, if there is room. This is a network specific function,
                           it has an additional constraint: the item will be added only if no other item in the network
                           has the same username (usernames are considered unique)
                           Finally, the Account being added to the network will update it's private member to point to this network
    */
    bool addAccount(ItemType* new_entry);



    /**
       Mutator function
       @param            :   a POINTER to the item that will be removed from Network
       @return           :   true if if the item was successfully removed, false otherwise
       @post             :   updates the bag/network to remove the pointer, if a pointer to that item was found.
    */
    bool removeAccount(ItemType* an_entry);



    /**
     @post      :removes all accounts from the network
     **/
    void clear();


    /**
     @return      : true if an_etry is found in network_, false otherwise
     **/
    bool containsAccount(const ItemType &an_entry) const;


    /**
       Mutator function
       @param            :   the name of an input file
       @pre              :   The format of the text file is as follows:
                             username password
                             username password
                             ;

                             where ';' signals the end of the file. Check the provided example (accounts.txt).

       @post             :   Reads every line in the input file, creates an Account from that information and
                             adds the Account to the network. If a line of input is missing some required information,
                             it prints out "Improper Format" and terminates.
                             Keep in mind that, although the input will always be an Account, the Network class is
                             a template, thus it will store a pointer to a generic type. It will do so by creating a new
                             dynamic object of type ItemType but passing the account information (username and password)
                             as to the Account constructor. This is a bit hacky, but it will work for our Network.


    */
    void populateNetwork(const std::string input);


    /**
       Accessor function
       @param            :   a reference to the item whose feed will be displayed
       @post             :   prints the feed of the given account by checking who they are following
                             and displaying all the posts from the feed that were made by those accounts.
                             Keep in mind that the Network parameters are general template types
                             in this project rather than accounts, although this functionality is
                             specific to accounts.
    */
    void printFeedForAccount(ItemType &an_entry);

    /**
       @param            :   a reference to an item (account) and the username of the account
                             it wants to follow
       @return           :   true if the item was authorized to follow, false otherwise

       @post             :   the referenced Account follows another account with the username
                             specified by the second argument if they both exist in the network
    */
    bool authenticateFollow(ItemType &an_entry, const std::string username) const;


    /**
       @param            :   a pointer to Post

       @post             :  the post is added to the feed if the account username is in the network
    */
    void addToFeed(Post* p);


    /**
       @param            :   a pointer to Post
       @return           :  true if post was removed from feed, false otherwise
       @post             :  the post is removed from to the feed if there
    */
    bool removePostFromFeed(Post* post);

    /**
       @param            :   a pointer to Post
       @return           :  true if post was found and moved to the front of the  feed,
                            false otherwise
       @post             :  The post is moved to the front of the feed
    */
    bool updateFeed(Post* post);

    /**
       Accessor function
       @post             :   prints the feed by displaying all the posts from the feed
    */
    void printFeed();




    /**
    The (set) difference between two sets A and B is the set that
    consists of the elements of A which are not elements of B
    @param  : a_network to be subtracted from the Network Bag calling the function
    @post   : removes all the data from network_ that is also found in a_network
    **/
    void operator-=( Network<ItemType> &a_network);


    /*
        @param            :   A string (word or phrase, case-sensitive) passed by reference
        @return           :   The number of items removed from the list

        @post              :  Any Post that contains the provided word or phrase in it's title,
                              body or both is removed from the Network's `feed_` as well as
                              the Account's `posts_`.

    */
    int removeIfContains(const std::string &postBody);


   //PROJECT 5 METHOD
   template <typename Comparator>
   LinkedList<Post*> bSortByUsername(Comparator compVals, int* counter);
   //END PROJECT 5 METHOD

protected:
    static const int DEFAULT_CAPACITY = 200; //max size of network_
    ItemType* network_[DEFAULT_CAPACITY];       // Array of bag items
    int account_count_;
    LinkedList<Post*> feed_;

    /**
     @param username to be found in network_
     @return either the index target in the array network_ or -1,
     if the array does not containthe target account.
     **/
    int getIndexOf(const std::string username) const;

}; // end Network

#include "Network.cpp"
#endif
