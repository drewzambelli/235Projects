// Name: Drew Zambelli
// Due Date: Friday, October 28
// Network.cpp
// Project 4 - expanding from Lab 1, 2 and 3, now we are adding LinkedLists and additional functionality 
// We are modifying various files to view Polls and Promotional posts and updating our Network so that we can 
// store any of these types of posts in our feed. In addition, we are creating methods to edit and monitor content
// and remove language that should not be shown

#include <iostream>
#include <fstream>
#include <string>

#include "Network.hpp"

//**********DEFAULT CONSTRUCTOR*************

   /**
      Default constructor.
      Initializes private variables to default initial values.
   */

template<typename T>
Network<T>::Network(): bagAccountCount(0) {}

//********* GET SIZE OF NETWORK FUNCTION **********

   /**
      Accessor function
      getSizeOfNetwork function
      @return           : int -  the current size of the network (number of items in the array)
   */

template<typename T>
int Network<T>::getSizeOfNetwork() const {
    return bagAccountCount;
}

//******* CHECK IF BAG IS EMPTY FUNCTION ********

   /**
    * isEmpty function to check if the bag is empty.
      @return           : bool -  true if the bag is empty, false otherwise
   */

template<typename T>
bool Network<T>::isEmpty() const { //checks if bag is empty, true is empty, false otherwise
    return bagAccountCount == 0;
}

//********* addAccount FUNCTION ***********
   /**
      @param            : a POINTER to the item that will be added to the Network
      @return           : bool- true  if the item was successfully added, false otherwise
      @post             : stores a pointer to the item, if there is room. This is a network specific function,
                          it has an additional constraint: the item will be added only if no other item in the network
                          has the same username (usernames are considered unique)
                          REMEMBER WE ARE STORING POINTERS TO ITEMS, NOT ITEMS.
                          Finally, the Account being added to the network will update it's private member to point to this network
                          (see Account class modifications below, you may come back and implement this feature after
                          you work on Task 2, but don't forget!!!).
                          NOTE: every object in C++ has access to a pointer to itself called `this`, thus the nework can pass `this` pointer to the account!
   */

template<typename T>
bool Network<T>::addAccount(T* new_account_entry) {
    bool has_room = (bagAccountCount < NETWORK_DEFAULT_CAPACITY);


    if(has_room && (getIndexOf(new_account_entry->getUsername()) < 0) ){
        bagArrPointers[bagAccountCount] = new_account_entry;
        new_account_entry->setNetwork(this);
        bagAccountCount++;
        return true;
    }        
    return false;
    }

//************ REMOVE ACCOUNT **************

 /**
      Function to remove account from bag/network
      @param            :   a POINTER to the item that will be removed from Network
      @return           :   true if if the item was successfully removed, false otherwise
      @post             :   updates the bag/network to remove the pointer, if a pointer to that item was found.
   */

template <typename T>
bool Network<T>::removeAccount(const T* account_entry){ //removes account bag/network
    int found_index = getIndexOf(account_entry->getUsername());
	bool can_remove = !isEmpty() && (found_index > -1);
    if(can_remove){
        bagAccountCount--;
        bagArrPointers[found_index] = bagArrPointers[bagAccountCount];
        return true;
    }
    return false;
}

//*********CLEAR BAG**********

   /**
      Mutator function to clear the bag
      @post  :   Empties the bag/network
   */

template <typename T>
void Network<T>::clear(){
    bagAccountCount = 0;
}


//*********** CONTAINS ACCOUNT FUNCTION ***********
   /**
      @param            :   a POINTER to the item to find
      @return           :   true if the item was successfully found, false otherwise
   */

template <typename T>
bool Network<T>::containsAccount(const T* target_account) const{
    return getIndexOf(target_account->getUsername()) > -1;
}

//************ POPULATE NETWORK FUNCTION **************
   /**
      Mutator function to  build the network from a TXT file
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


template <typename T>
void Network<T>::populateNetwork(const std::string input_file){
    std::string lineInput;
    std::ifstream file;
    file.open(input_file);
    while(getline(file, lineInput) && lineInput != ";"){
        int x = lineInput.find(' ');
        std::string username = lineInput.substr(0, x);
        std::string password = lineInput.substr(x + 1, lineInput.length());
        if(username.empty() || password.empty()){
            std::cout << "Improper Format" << std::endl;
            return;
        } else {
            T* newAccount = new T(username, password);
            addAccount(newAccount);
        }
    }
    file.close();
}


//********** OPERATOR OVERLOAD FUNCTION ***********

   /**
      Mutator function to remove bots from Network
      @param            :   a reference to another Network
      @post             :  Removes from the Network any items that also appear in the other Network.
                           In other words, removes elements from the network on the left of the operator that
                           are also found in the network on the right of the operator.
      Why is this useful? For example, given a network of known bot accounts, remove all bots from this Network.
   */

template <typename T>
void Network<T>::operator-= (const Network& other_network){
    for(int i = 0; i<other_network.getSizeOfNetwork(); i++){
        if(containsAccount(other_network.bagArrPointers[i])){
            removeAccount(other_network.bagArrPointers[i]);
        }
    }
}

//********* PRINT THE FEED FOR THE ACCOUNT *********

   /**
      Accessor function to print the feed for the account
      @param            :   a reference to the item whose feed will be displayed
      @post             :   prints the feed of the given account by checking who they are following
                            and displaying all the posts from the feed that were made by those accounts.
                            Keep in mind that the Network parameters are general template types
                            in this project rather than accounts, although this functionality is
                            specific to accounts.
   */

template <typename T>
void Network<T>::printFeedForAccount(T& account_feed_to_print) const {
    std::vector<std::string> x = account_feed_to_print.viewFollowing();
        for (int j = 0; j < x.size(); j++){
            if(getIndexOf(x[j]) != -1){
                bagArrPointers[getIndexOf(x[j])]->viewPosts();
            }
        }
    }

//********** AUTHENTICATE FOLLOW FUNCTION ************

   /**
      @param            :   a reference to an item (account) and the username of the account
                            it wants to follow
      @return           :   true if the item was authorized to follow, false otherwise
      @post             :   the referenced Account follows another account with the username
                            specified by the second argument if they both exist in the network
   */

template <typename T>
bool Network<T>::authenticateFollow(T& account, const std::string to_be_followed) const {
    if(getIndexOf(account.getUsername()) >= 0 && getIndexOf(to_be_followed) >= 0){
        account.followAccount(to_be_followed);
        return true;
    }
    return false;
}

//********* addToFeed FUNCTION ***********

   /**
      Mutator function to add a post to a feed of account
      @param            :   a reference to a Post be added to the feed
      @return           :   returns true if the Post was successfully added to the feed, false otherwise
      @post             :   Adds the post to its feed only if the Post was created by an Account
                            in this Network.
   */

template <typename T>
bool Network<T>::addToFeed(Post* add_to_feed){
    //getIndexOf(add_to_feed->getUsername()) > -1)
    bool isTrue = false;
    if(getUsernameAccount(add_to_feed->getUsername())){
        isTrue = true;
    }
    if(isTrue){
        NetworkLinkedList.insert(add_to_feed, 0);
        return true;
    }
    return false;
}   

//********** REMOVE IF CONTAINS FUNCTION ***********

/*
    @param            :   A string (word or phrase, case-sensitive) passed by reference
    @return           :   The number of items removed from the list

    @post              :  Any Post that contains the provided word or phrase in it's title,
                          body or both is removed from the Network's `feed_` as well as
                          the Account's `posts_`.

    You are encouraged to create your own helper functions for this endeavour.
*/

//THIS IS MY removeIfContains and the bane of my existence
template <typename T>
int Network<T>::removeIfContains(std::string& to_remove) {
int to_remove_count = 0;
Node<Post*>* current = NetworkLinkedList.getHeadPtr();
if(current == nullptr){
    return to_remove_count;
}
while(current){
    size_t title_check = current->getItem()->getTitle().find(to_remove);
    size_t body_check = current->getItem()->getBody().find(to_remove);
    if(title_check != std::string::npos || body_check != std::string::npos){
        if(getIndexOf(current->getItem()->getUsername()) > -1){
            int index_post = NetworkLinkedList.getIndexOf(current->getItem());
            NetworkLinkedList.remove(index_post);
            int index_account = getIndexOf(current->getItem()->getUsername());
            bagArrPointers[index_account]->removePost(current->getItem());
        
        to_remove_count++;
        index_post = 0;
        }
    } 
    current = current->getNext();
}
return to_remove_count;
}

//********* HELPER FUNCTIONS *********

//LAB 3 Helper Function to aid addToFeed() function to access Account
template <typename T>
bool Network<T>::getUsernameAccount(const std::string input_account) const{
    if(getIndexOf(input_account) > -1){
        return true;
    }
    return false;
}
//END LAB 3 HELPER FUNCTION

//LAB 4 - HELPER FUNCTION FOR REMOVEPOST FUNCTION
template <typename T>
void Network<T>::helperRemovePostNet(Post* to_remove) {
    Node<Post*>* current = NetworkLinkedList.getHeadPtr();
    int index = 0;

    while(current != nullptr){
        if(current->getItem()->getUsername() == to_remove->getUsername()){
            index = NetworkLinkedList.getIndexOf(current->getItem());
            NetworkLinkedList.remove(index);
            index = 0;
        }
        current = current->getNext();
    }
}

//LAB 4 HELPER FUNCTION FOR UPDATEPOST FUNCTION FEED EDIT
template<typename T>
void Network<T>::feedEdit(Post* editedPost){
    NetworkLinkedList.moveItemToTop(editedPost);
}
// END HELPER FUNCTIONS

//***********getIndexOf - PRIVATE MEMBER FUNCTION *************

/**
   private function
   @param            :   string - the username of item we want the index of
   @return           :   int - the index of the item, -1 if the account is not found
*/

template<typename T>
int Network<T>::getIndexOf(const std::string target) const {
    bool found = false;
    int result = -1;
    int search_index = 0;
    
    //if our bag is empty, this while loop is skipped
    while(!found && (search_index < bagAccountCount)) {

        if(bagArrPointers[search_index]->getUsername() == target) {
        found = true;
        result = search_index;
        return result;
        } else {
            search_index++;
        }
    }
    return result;
}
//END PRIVATE MEMBER FUNCTION
