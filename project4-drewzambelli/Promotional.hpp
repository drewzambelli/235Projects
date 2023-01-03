// Name: Drew Zambelli
// Due Date: Friday, October 28
// Promotional.hpp
// Project 4 - expanding from Lab 1, 2 and 3, now we are adding LinkedLists and additional functionality 
// We are modifying various files to view Polls and Promotional posts and updating our Network so that we can 
// store any of these types of posts in our feed. In addition, we are creating methods to edit and monitor content
// and remove language that should not be shown

#ifndef PROMOTIONAL_H
#define PROMOTIONAL_H

#include <string>

#include "Post.hpp"

class Promotional : public Post {

    public:
        //default constructor
        Promotional();

        //parameterized constructor
        Promotional(const std::string post_title, const std::string post_body, const std::string post_author, const std::string url);

        //Accessor
        std::string getLink() const;

        //Mutator
        bool setLink(const std::string url);
        virtual void displayPost() override;

    private:
        std::string url = "please work";
};

#endif