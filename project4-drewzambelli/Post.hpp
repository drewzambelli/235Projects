// Name: Drew Zambelli
// Due Date: Friday, October 28
// Post.hpp
// Project 4 - expanding from Lab 1, 2 and 3, now we are adding LinkedLists and additional functionality 
// We are modifying various files to view Polls and Promotional posts and updating our Network so that we can 
// store any of these types of posts in our feed. In addition, we are creating methods to edit and monitor content
// and remove language that should not be shown

#ifndef POST_H
#define POST_H

#include <iostream>
#include <ctime>
#include <string>

//class declarations for Post class
class Post {

public:

    //default constructor
    //Post() = default;

    //parameterized constructor taking in title and body
    Post(std::string post_title, std::string post_body, std::string post_author);

    //Mutators to set the title, body and author of the post
    void setTitle(const std::string post_title);
    void setBody(const std::string post_body);
    void setUsername(const std::string post_author); //To set the name of the author of the post
    void helperSetTime(); //helper function for updatePost to set the time

    //Accessors to retrieve the title, body, post author and time stamp of the post
    std::string getTitle() const;
    std::string getBody() const;
    std::string getUsername() const; //To retrieve name of post author
    void getTimeStamp() const;

    //Accessor to print the post
    virtual void displayPost() = 0;

private:

    std::string post_title; //The title of the post
    std::string post_body; //The body of the post
    std::time_t time_stamp; //The time that the post was created
    std::string post_author; //String representing the username of the account that created the post

};


#endif