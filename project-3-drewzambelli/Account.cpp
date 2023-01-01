
// Name: Drew Zambelli
// Due Date: Tuesday, October 11
// Account.cpp
// Project 3 - expanding from Lab 1 and 2, now we are creating the Network class and 
// modifying the Account class to be able to operate on the Network

#include <iostream>

#include <vector>
#include <string>

#include "Account.hpp"
#include "Post.hpp"

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

bool Account::addPost(const std::string post_title, const std::string post_body){
    if(post_title != "" && post_body != ""){
        Post newPost(post_title, post_body, getUsername());
        account_post_history.push_back(newPost);
        ptrNetwork->addToFeed(newPost);
        return true;
    }
    return false;
}

//******METHOD TO PRINT HISTORY OF POSTS******

   /**
    * Method to print out the history of posts
      @post: Prints the vector of Posts using their display function
   */

void Account::viewPosts(){
    for (size_t i = 0; i < account_post_history.size(); i++){
        account_post_history[i].displayPost();
    }
}

//*********** VIEW FOLLOWING METHOD **********
   /**
      @return           :   the vector of usernames the Account is following
   */

std::vector<std::string> Account::viewFollowing() const{
    return following;
}