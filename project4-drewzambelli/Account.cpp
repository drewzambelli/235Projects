// Name: Drew Zambelli
// Due Date: Friday, October 28
// Account.cpp
// Project 4 - expanding from Lab 1, 2 and 3, now we are adding LinkedLists and additional functionality 
// We are modifying various files to view Polls and Promotional posts and updating our Network so that we can 
// store any of these types of posts in our feed. In addition, we are creating methods to edit and monitor content
// and remove language that should not be shown

#include <iostream>

#include <vector>
#include <string>

#include "Account.hpp"

//******PARAMETERIZED CONSTRUCTOR******

   /**
      Parameterized constructor
      @param username  : username of the Account
      @param password  : password of the Account
      Sets the username and password of the Account to what was passed by the user
      Sets the vector of posts to an empty vector
   */

Account::Account(std::string account_username, std::string account_password){
    this->account_username = account_username;
    this->account_password = account_password;
    this->ptrNetwork = nullptr;
}

//******MUTATORS******

   /**
    * Sets Username
    @param a reference to the username of the Account
    */

void Account::setUsername(const std::string account_username){
    this->account_username = account_username;
}

   /**
    * Sets Password
      @param a reference to the password of the Account
   */

void Account::setPassword(const std::string account_password){
    this->account_password = account_password;
}

   /**
      Mutator function to set the Network
      @param            :   a pointer to a Network
      @post             :   the Network pointer private member points to the input Network
   */

void Account::setNetwork(Network<Account>* input_network){
    ptrNetwork = input_network;
}

//************ FOLLOW ACCOUNT FUNCTION ************
   /**
      @param            :   the username of the Account to follow
      @return           :   true if the account was successfully able to follow, false otherwise
      @post             :   adds the username to the vector of following accounts only if
                            it is affiliated to a Network AND it is not already following an account
                            with the same username.
   */

bool Account::followAccount(const std::string usr_to_follow){
    bool result = false;
    
    for (int i = 0; i < following.size(); i++) {
        if (usr_to_follow == following[i]){
            result = true;
            break;
        }
    }
    if(!result && (ptrNetwork != nullptr)){
        following.push_back(usr_to_follow);
        return true;
    }
    
    return false;
}

//******ACCESSORS******

   /**
    * Gets the username
      @return the username of the Account
   */

std::string Account::getUsername() const{
    return account_username;
}

   /**
    * Gets the password
      @return the password of the Account
   */

std::string Account::getPassword() const{
    return account_password;
}

   /**
      Accessor function to get the Network
      @return           :   the pointer to the Network the account is in
   */

Network<Account>* Account::getNetwork() const{
    return ptrNetwork;
}

//******METHOD TO CREATE HISTORY OF POSTS******

/**
 * Method to build vector of post history
      @param title   : A reference to the title used to generate the Post object
      @param body    : A reference to the body used to generate the Post object
      @post         : generates a Post with the given title and body and adds it to it's vector of posts
      @return       : Will return true if the Post does not have an empty title or body and the Post is successfully added to the vector
   */

bool Account::addPost(Post* const new_post){

    AccountLinkedList.insert(new_post, 0);
    if(ptrNetwork != nullptr) {
        ptrNetwork->addToFeed(new_post);
    }
    return true;
}

//******METHOD TO PRINT HISTORY OF POSTS******

   /**
    * Method to print out the history of posts
      @post: Prints the vector of Posts using their display function
   */

void Account::viewPosts(){
    Node<Post*>* curr_item = AccountLinkedList.getHeadPtr();
    while(curr_item != nullptr) {
        curr_item->getItem()->displayPost();
        curr_item = curr_item->getNext();
    }
}

//*********** REMOVE POST FUNCTION *************

/*
    @param            :   A pointer to a Post
    @return           :   If the Post was successfully found and removed

    This function will remove the given Post from its list as well as from the Network's feed.
    Returns True if successfully removed, False if not. Afterwards, tell the Network to remove
    the Post as well from its feed.

    You are encouraged to create your own helper functions for this endevour.
*/
bool Account::removePost(Post* target_post){
    if(AccountLinkedList.getIndexOf(target_post) < 0){
        return false;
    } else {
        AccountLinkedList.remove(AccountLinkedList.getIndexOf(target_post));
        ptrNetwork->helperRemovePostNet(target_post);
        return true;
    }
}


//********** UPDATE POST FUNCTION *************

/*
    @param            :   Pointer to a Post object
    @param            :   The new title of the Post (or an empty string if you do not
                          want to change it)
    @param            :   The new body of the Post (or an empty string if you do not
                          want to change it)

    @post            :   This function will take the Post and given the new title and body,
                         update the Posts title and body as appropriate. It will also update the `timestamp_` to the current time of the update. This function should then
                         update the location of the Post in its list of `posts_` to the front of the list as well as utilizing its Network pointer to do the same in the `feed_`.

    You are encouraged to create your own helper functions for this endevour.
*/

void Account::updatePost(Post* post, std::string new_title, std::string new_body){
    if(new_title != ""){
        post->setTitle(new_title);
    }
    if(new_body != "") {
        post->setBody(new_body);
    }
    post->helperSetTime();
    AccountLinkedList.moveItemToTop(post);

    if(ptrNetwork != nullptr){
        ptrNetwork->feedEdit(post);
    }
    
}


//*********** VIEW FOLLOWING METHOD **********
   /**
      @return           :   the vector of usernames the Account is following
   */

std::vector<std::string> Account::viewFollowing(){
    return following;
}
