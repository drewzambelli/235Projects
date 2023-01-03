// Name: Drew Zambelli
// Due Date: Friday, October 28
// General.hpp
// Project 4 - expanding from Lab 1, 2 and 3, now we are adding LinkedLists and additional functionality 
// We are modifying various files to view Polls and Promotional posts and updating our Network so that we can 
// store any of these types of posts in our feed. In addition, we are creating methods to edit and monitor content
// and remove language that should not be shown
    
    #ifndef GENERAL_H
    #define GENERAL_H

    #include <string>

    #include "Post.hpp"

//Enum of possible reactions to Post
enum Reactions { LIKE, DISLIKE, LAUGH, WOW, SAD, ANGRY };

// class GENERAL is derived from the POST
class General : public Post {
    
    public:
        //Default Constructor
        General();

        //Parameterized Constructors
        General(const std::string post_title, const std::string post_body, const std::string post_author);

        //Method to record reactions to posts
        bool reactToPost(const Reactions react);

        //Accessors
        void getReactions() const;
        virtual void displayPost() override;
        
    private:
        int arr_reactions[6]; //array of reactions from enum

    };


#endif