/****************************************************************************************************************************
Title         :   Account.hpp
Author        :   Dream Team
Description   :   header/interface files for Account class
****************************************************************************************************************************/

#ifndef ACCOUNT_
#define ACCOUNT_

#include <iostream>
#include <string>
#include <vector>
#include "Post.hpp"
#include "Network.hpp"
#include "LinkedList.hpp"
#include "Node.hpp"

class Account {
public:

    //default constructor
    //@post:  set username and password to ""
    //        creates an empty vector of post objects to store into feed_
    Account();


    /**
        Parameterized Constructor
        @param username  : username of the account, stored into username_
        @param password  : password of the account, stored into password_
        @post:             sets the private members to the value of the parameters
    */
    Account(std::string username, std::string password);


    /**
      @return:     the username of the Account
   */
    std::string getUsername() const;

    /**
      @param:     a reference to the username of the Account
      @post:      sets the private member to the value of the parameter
    */
    void setUsername(const std::string& username);


    /**
      @return:     the password of the Account
   */
    std::string getPassword() const;

    /**
      @param a reference to the password of the Account
      @post:      sets the private member to the value of the parameter
   */
    void setPassword(const std::string& password);

    /**
      Accessor function
      @return           :   the pointer to the Network the account is in
   */
    Network<Account>* getNetwork() const;

    /**
      Mutator function
      @param            :   a pointer to a Network
      @post             :   the Network pointer private member points to the input Network
   */
    void setNetwork(Network<Account>* network);

    /**
        @param newPost   : The pointer to the Post object that will be added to its list
        @return          : Will return true if a post gets added sucesfully to the vector

        @post:           " Adds post to posts_ and its Networks feed_
    */
    bool addPost(Post* newPost);



    /*
        @post:      Prints the feed_ that contains the post objects by calling their display function
    */
    void viewPosts() const;

    /**
      @param            :   the username of the Account to follow
      @return           :   true if the account was successfully able to follow, false otherwise
      @post             :   adds the username to the vector of following accounts only if
                            it is affiliated to a Network AND it is not already following an account
                            with the same username.
   */
    bool followAccount(const std::string username);


    /**
      @return           :   the vector of usernames the Account is following
   */
    std::vector<std::string> viewFollowing() const;


    /**
      @return           :  true if account has same private members as parameter,
                           false otherwise
   */
    bool operator==(const Account &acc) const;

    /*
    @param            :   A pointer to a Post
    @return           :   True iff the Post was successfully found and removed,
                          false othewise.
    @post             :   Removes the given Post from its list
                          as well as from the Network's feed.
    */
    bool removePost(Post* post);


    /*
    @param            :   Pointer to a Post object
    @param            :   The new title of the Post (or an empty string if you do not
                          want to change it)
    @param            :   The new body of the Post (or an empty string if you do not
                          want to change it)

    @post            :   This function will take the Post and given the new title and body,
                         update the Posts title and body as appropriate. It will also update
                         the `timestamp_` to the current time of the update. This function should then
                         update the location of the Post in its list of `posts_` to the front of the list
                         as well as utilizing its Network pointer to do the same in the `feed_`.
*/
    bool updatePost(Post* post, std::string new_title, std::string new_body);



private:
    std::string username_;
    std::string password_;
    LinkedList<Post*> posts_;
    std::vector<std::string> following_;
    Network<Account>* net_;
}; // end Account

#endif
