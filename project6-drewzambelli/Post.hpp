/****************************************************************************************************************************
Title         :   Post.hpp
Author        :   Dream Team
Description   :   header/interface for Post class
****************************************************************************************************************************/
// Name: Drew Zambelli
// Due Date: Friday, December 9
// Post.hpp
// Project 6 - expanding from Labs 1, 2, 3, 4, 5 and 6 we are now adding a priority queue and adding additional functionality to allow users
// to sort Posts by Likes and Priority.

#ifndef POST_
#define POST_

#include <iostream>
#include <string>
#include <time.h>
#include <queue>

class Post {
public:

    enum priority {
    LOW,
    MEDIUM,
    HIGH,
    };

  /**
     Parameterized constructor.
     @param      : The title of the post (a string)
     @param      : The body content of the post (a string)
     @param      : The username of the Account that added this post (a string)

     @post         : Sets the title, body and username to the value of the parameters
                     It will also generate the current time and store it
  */
    Post(std::string title, std::string body, std::string username);


    /**
       @return : the title of the Post
    */
    std::string getTitle() const;


    /**
      @param  : a reference to title of the Post
      @post   : sets the private data member to the value of the parameter
    */
    void setTitle(const std::string& title);


    /**
       @return : the body of the Post
    */
    std::string getBody() const;

    /**
       @param  : a reference to body of the Post
       @post   : sets the private data member to the value of the parameter
    */

    void setBody(const std::string& body);

    /*
       Accessor Function
       @return       : username associated with this Post
    */
    std::string getUsername() const;



    /*
       Mutator Function
       @param        : a reference to the username associated with this Post
       @post   : sets the private data member to the value of the parameter
    */
    void setUsername(const std::string& username);

    /**
       @post   : prints the time the Post was created to the standard output as asctime(localtime(&time_stamp_))
    */
    void getTimeStamp() const;

    /*
       Mutator Function
       @post   : sets the private data member to the current time
    */
    void updateTimeStamp();

    //PROJECT 5 METHODS:

    bool operator<(const Post& compOne) const; //method to check if argument is greater than this Post Username
    bool operator>(const Post& compOne) const; //method to check if argument is less than this Post Username
   //END PROJECT 5 METHODS

   //PROJECT 6 METHODS:

   int like(); //method increments the likes_ private member
   int getLikes() const; //returns the value of the likes_ private member
   void setPriority(const priority pVal); //method to set the priority_id_ to the value of the parameter
   priority getPriority() const; //returns the value of the priority_id_ data member

   //END PROJECT 6 METHODS

    void virtual displayPost() = 0;

private:
    std::string post_title_;
    std::string post_body_;
    time_t time_stamp_;
    std::string username_;
    int likes_; //keeps track of the number of likes the post received
    priority priority_id_; // priority of post

};//end Post

#endif
