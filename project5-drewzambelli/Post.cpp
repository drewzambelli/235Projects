/****************************************************************************************************************************
Title         :   Post.cpp
Author        :   Dream Team
Description   :   Implementation for Post class
****************************************************************************************************************************/
// Name: Drew Zambelli
// Due Date: Tuesday, November 22
// Post.cpp
// Project 5 - expanding from Labs 1, 2, 3, and 4, we are adding additional functionality to allow users
// to sort the Network's feed by the username of the account that posted each Post in the feed. To do so, we
// are implementing a Bubble Sort.

#include "Post.hpp"


/**
   Parameterized constructor.
   @param      : The title of the post (a string)
   @param      : The body content of the post (a string)
   @param      : The username of the Account that added this post (a string)

   @post         : Sets the title, body and username to the value of the parameters
                   It will also generate the current time and store it
*/
Post::Post(std::string title, std::string body, std::string username) {
    post_title_ = title;
    post_body_ = body;
    time_stamp_ = time(NULL);
    username_ = username;
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


/*
   Mutator Function
   @post   : sets the private data member to the current time
*/
void Post::updateTimeStamp() {
    time_stamp_ = time(0);
}
