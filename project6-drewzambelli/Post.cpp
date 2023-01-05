/****************************************************************************************************************************
Title         :   Post.hpp
Author        :   Dream Team
Description   :   header/interface for Post class
****************************************************************************************************************************/
// Name: Drew Zambelli
// Due Date: Friday, December 9
// Post.cpp
// Project 6 - expanding from Labs 1, 2, 3, 4, 5 and 6 we are now adding a priority queue and adding additional functionality to allow users
// to sort Posts by Likes and Priority.

#include "Post.hpp"


/**
   Parameterized constructor.
   @param      : The title of the post (a string)
   @param      : The body content of the post (a string)
   @param      : The username of the Account that added this post (a string)

   @post         : Sets the title, body and username to the value of the parameters
                   It will also generate the current time and store it
                   It will also set priority_id_ to default value of Medium
                   It will also set likes_ to default value of 0
*/
Post::Post(std::string title, std::string body, std::string username) {
    post_title_ = title;
    post_body_ = body;
    time_stamp_ = time(NULL);
    username_ = username;
    priority_id_ = MEDIUM;
    likes_ = 0;
}


/**
   @return : the title of the Post
*/
std::string Post::getTitle() const {
    return post_title_;
}


/**
  @param  : a reference to title of the Post
  @post   : sets the private data member to the value of the parameter
*/
void Post::setTitle(const std::string& title) {
    post_title_ = title;
}


/**
   @return : the body of the Post
*/
std::string Post::getBody() const {
    return post_body_;
}


/**
   @param  : a reference to body of the Post
   @post   : sets the private data member to the value of the parameter
*/
void Post::setBody(const std::string& body) {
    post_body_ = body;
}


/*
   Accessor Function
   @return       : username associated with this Post
*/
std::string Post::getUsername() const {
    return username_;
}


/*
   Mutator Function
   @param        : a reference to the username associated with this Post
   @post   : sets the private data member to the value of the parameter
*/
void Post::setUsername(const std::string& username) {
    username_ = username;
}


/**
    @post:  prints out the post in the following format:
    \n
    {post_title_} at {time_stamp_}:
    {post_body_}
    \n
*/
void Post::getTimeStamp() const {
    std::cout << asctime(localtime(&time_stamp_));
}

//************* PROJECT 5 METHODS **************


// *************** OPERATOR OVERLOADS ****************

/*
    @param            :   The Post object to compare

    @return           :   true if this Post's username is less than the parameter
                          Post username, false otherwise
*/
//operator<;

bool Post::operator<(const Post& compOne) const{
        if(this->getUsername() < compOne.getUsername()) {
            return true;
        }
    return false;
}

/*
    @param            :   The Post object to compare

    @return           :   true if this Post's username is greater than the
                          parameter Post username, false otherwise
*/
//operator>

bool Post::operator>(const Post& compOne) const{
        if(this->getUsername() > compOne.getUsername()) {
            return true;
        }
    return false;
}

// END PROJECT 5 METHODS

// PROJECT 6 METHODS

// ********* LIKE INCREMENT FUNCTION ************

/*
  @post             :  increments the likes_ private member

*/

   int Post::like() {
    return likes_++;
   }

// *********** LIKE ACCESSOR FUNCTION ************

/*
  @return             : the value of the likes_ private member

*/

   int Post::getLikes() const{
    return likes_;
   }

// ************ PRIORITY MUTATOR FUNCTION *************

/*
  Function to set priority_id_ data member
  @param           :  a priority value
  @post             :  sets the priority_id_ to the value of the parameter

*/

void Post::setPriority(const priority value){
    priority_id_ = value;
}

// *********** PRIORITY ACCESSOR FUNCTION *************

/*
Function to return the value of the priority_id_ member
@return             :  the value of the priority_id_ data member

*/

   Post::priority Post::getPriority() const{
    return priority_id_;
   }

// END PROJECT 6 METHODS

/*
   Mutator Function
   @post   : sets the private data member to the current time
*/
void Post::updateTimeStamp() {
    time_stamp_ = time(0);
}
