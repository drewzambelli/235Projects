// Name: Drew Zambelli
// Due Date: Friday, October 28
// Account.hpp
// Project 4 - expanding from Lab 1, 2 and 3, now we are adding LinkedLists and additional functionality 
// We are modifying various files to view Polls and Promotional posts and updating our Network so that we can 
// store any of these types of posts in our feed. In addition, we are creating methods to edit and monitor content
// and remove language that should not be shown

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Post.hpp"
#include "Network.hpp"
#include "LinkedList.hpp"

#include <vector>
#include <string>

//Class declaration for Account Class
class Account{

public:
    /**
      Default constructor.
      Sets the username and password of the Account to an empty string
      Sets the vector of posts to an empty vector
   */
    Account() = default;

    //parameterized constructor taking in a user generated username and password
    Account(std::string account_username, std::string account_password);

    //Mutators
    void setUsername(const std::string account_username);
    void setPassword(const std::string account_password);
    void setNetwork(Network<Account>* input_network); //Setter for Lab 3 - Network pointer private member points to the input network

    //method to allow accounts to follow each other
    bool followAccount(const std::string usr_to_follow);
    
    //Accessors
    std::string getUsername() const;
    std::string getPassword() const;
    Network<Account>* getNetwork() const;
    std::vector<std::string> viewFollowing(); //you need to check this


    //create account post history
    bool addPost(Post* const new_post); //modified from Lab 3

    //print account post history
    void viewPosts();

    // remove Post function
    bool removePost(Post* post);

    // to update the post
    void updatePost(Post* post, std::string new_title, std::string new_body);



private:

    std::string account_username; //private member for user generated username
    std::string account_password; //private member for user generated password
    //std::vector<Post> account_post_history; //private member to hold history of user this account's posts
    LinkedList<Post*> AccountLinkedList; //pointers to Posts in a LinkedList
    std::vector<std::string> following; //vector of usernames the Account is following
    Network<Account>* ptrNetwork; //pointer to Network this account is a part of
    
};

#endif