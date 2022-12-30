#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Post.hpp"

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
    
    //Accessors
    std::string getUsername() const;
    std::string getPassword() const;

    //create account post history
    bool addPost(const std::string post_title, const std::string post_body);

    //print account post history
    void viewPosts();

private:

    std::string account_username; //private member for user generated username
    std::string account_password; //private member for user generated password
    std::vector<Post> account_post_history; //private member to hold history of user generated posts

};

#endif