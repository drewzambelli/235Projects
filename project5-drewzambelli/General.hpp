/****************************************************************************************************************************
Title         :   General.hpp
Author        :   Dream Team
Description   :   header/interface for the General class
****************************************************************************************************************************/



#ifndef GENERAL_
#define GENERAL_

#include "Post.hpp"
#include <string>
#include <iostream>
#include <vector>

/**
    ENUM used as indexes to reactions_
*/
enum Reactions {
    LIKE = 0,
    DISLIKE = 1,
    LAUGH = 2,
    WOW = 3,
    SAD = 4,
    ANGRY = 5
};

class General : public Post {

    public:
      /**
         Parameterized constructor.
           @param    : The name of the General post (a string)
           @param    : The body of the General post (a string)
           @param    : : The username of the Account that added this post (a string)

           @post     : Sets the title, body and username to the value of the parameters.
                       It will also generate the current time and store it
                       and it initializes the array with default values
      */
        General(std::string name, std::string description, std::string username);

        /**
           Mutator function to add a reaction
           @param    : A reference to reaction (represented by a value of type Reaction)
           @return   : return True if the react to the post is successful or false
                       if the reaction provided is not within a valid Reaction value.

           @post     : Increments the array at the index corresponding to the input Reaction
        */
        bool reactToPost(const Reactions& reaction);



        /**
           @post     : Prints the reaction to the post in this format (example):
                       Like : 2 | Dislike : 0 | Laugh : 4 | Wow : 2 | Sad : 1 |  Angry : 5
        */
        void getReactions() const;


        /**
            @post     : Display Function in the following format:
            \n
            {post_title_} at {time_stamp_}:
            {post_body_}
            \n
            Likes : {reactions_[0]} |  Dislike : {reactions_[1]} | Laugh : {reactions_[0]} | ...
            \n
        */
        virtual void displayPost() override;                //Function used to display Post

    private:
        int reactions_[6];     //Stores the number of reactions for each index as described by the Reactions type
};

#endif
