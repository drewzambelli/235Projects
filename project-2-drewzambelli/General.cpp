#include <iostream>
#include <ctime>
#include <string>

#include "General.hpp"

// ********* PARAMETERIZED CONSTRUCTOR ***********

   /**
        @param    : The name of the General post (a string)
        @param    : The body of the General post (a string)
        @param    : : The username of the Account that added this post (a string)

        @post     : Sets the title, body and username to the value of the parameters.
                    It will also generate the current time and store it
                    and it initializes the array with default values
   */
//parameterized constructor which takes in post title, body, and author. Initializes each index of the array of enums to 0
General::General(const std::string post_title, const std::string post_body, const std::string post_author) : Post(post_title, post_body, post_author) {
    for (int i = 0; i < 6; i++)
        arr_reactions[i] = 0;
}

// ********** MUTATORS *************

   /**
      @param    : A reference to reaction (represented by a value of type Reaction)
      @return   : return True if the react to the post is successful or false
                  if the reaction provided is not within a valid Reaction value.

      @post     : Increments the array at the index corresponding to the input Reaction
   */

bool General::reactToPost(const Reactions react){
    if (react >= 0 && react <= 6){
        arr_reactions[react]++;
        return true;
    }
    return false;
}

// ************* ACCESSORS ***************

   /**
    * 
      A mutator to print out the reactions and the number of votes for each
      @post     : Prints the reaction to the post in this format (example):
                  Like : 2 | Dislike : 0 | Laugh : 4 | Wow : 2 | Sad : 1 |  Angry : 5
   */

void General::getReactions() const{
    for (int i = 0; i < 6; i++){
        switch(i) {
            case 0:
                std::cout << "Like : " << arr_reactions[i] << " | ";
                break;
            case 1:
                std::cout << "DISLIKE : " << arr_reactions[i] << " | ";
                break;
            case 2:
                std::cout << "LAUGH : " << arr_reactions[i] << " | ";
                break;
            case 3:
                std::cout << "WOW : " << arr_reactions[i] << " | ";
                break;
            case 4:
                std::cout << "SAD : " << arr_reactions[i] << " | ";
                break;
            case 5:
                std::cout << "ANGRY : " << arr_reactions[i] << std::endl;
                break;
        }
    }
}

   /**
      A method to display the title, body, time, and reactions to the post
      @post     : Displays the General post (example):
                  \n
                  {post_title_} at {time_stamp_}:
                  {post_body_}
                  \n
                  Like : 2 | Dislike : 0 | Laugh : 4 | Wow : 2 | Sad : 1 |  Angry : 5
                  \n
   */

void General::displayPost() {
    std::cout << getTitle() << " posted at ";
    getTimeStamp();
    std::cout << getBody() << std::endl;
    getReactions();
}

