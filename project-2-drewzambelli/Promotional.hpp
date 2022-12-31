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
        void displayPost();

    private:
        std::string url = "please work";
};

#endif