
// Name: Drew Zambelli
// Due Date: Tuesday, October 11
// Account.hpp
// Project 3 - expanding from Lab 1 and 2, now we are creating the Network class and 
// modifying the Account class to be able to operate on the Network

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Post.hpp"
#include "Network.hpp"

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
    bool addPost(const std::string post_title, const std::string post_body); //create account post history

    //method to allow accounts to follow each other
    bool followAccount(const std::string usr_to_follow);
    
    //Accessors
    std::string getUsername() const;
    std::string getPassword() const;
    Network<Account>* getNetwork() const; //returns the network
    std::vector<std::string> viewFollowing() const; //returns the followers
    void viewPosts(); //print account post history


private:

    std::string account_username; //private member for user generated username
    std::string account_password; //private member for user generated password
    std::vector<Post> account_post_history; //private member to hold history of user this account's posts
    std::vector<std::string> following; //vector of usernames the Account is following
    Network<Account>* ptrNetwork; //pointer to Network this account is a part of
    
};

#endif