/****************************************************************************************************************************
Title         :   General.cpp
Author        :   Dream Team
Description   :   Implementation for the General class
****************************************************************************************************************************/




#include "General.hpp"



/**
   Parameterized constructor.
     @param    : The name of the General post (a string)
     @param    : The body of the General post (a string)
     @param    : : The username of the Account that added this post (a string)

     @post     : Sets the title, body and username to the value of the parameters.
                 It will also generate the current time and store it
                 and it initializes the array with default values
*/
General::General(std::string name, std::string description, std::string username):Post(name, description, username){
    for(int i{0} ; i <= 5 ; i++){
        reactions_[i] = 0;
    }
}



/**
   Mutator function to add a reaction
   @param    : A reference to reaction (represented by a value of type Reaction)
   @return   : return True if the react to the post is successful or false
               if the reaction provided is not within a valid Reaction value.

   @post     : Increments the array at the index corresponding to the input Reaction
*/
bool General::reactToPost(const Reactions& reaction){
    if (reaction < 6) {
        reactions_[reaction] += 1;
        return true;
    }
    return false;
}


/**
   @post     : Prints the reaction to the post in this format (example):
               Like : 2 | Dislike : 0 | Laugh : 4 | Wow : 2 | Sad : 1 |  Angry : 5
*/
void General::getReactions() const {
    std::vector<std::string> temp = {"Likes", "Dislike", "Laugh", "Wow", "Sad", "Angry"};
    for(int i = 0; i < 5 ; i++) {
        std::cout << temp[i] << " : " << reactions_[i] << " | ";
    }
    std::cout << temp[5] << " : " << reactions_[5] << std::endl;
}

/**
    @post     : Display Function in the following format:
    \n
    {post_title_} at {time_stamp_}:
    {post_body_}
    \n
    Likes : {reactions_[0]} |  Dislike : {reactions_[1]} | Laugh : {reactions_[0]} | ...
    \n
*/
void General::displayPost(){
    std::cout << '\n' << getTitle() << " at ";
    getTimeStamp();
    std::cout << getBody() << std::endl;
    getReactions();
 }
