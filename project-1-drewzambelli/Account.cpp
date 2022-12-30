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
        Post newPost(post_title, post_body);
        account_post_history.push_back(newPost);
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
    for (int i = 0; i < account_post_history.size(); i++){
        account_post_history[i].displayPost();
    }

}



