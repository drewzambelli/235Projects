// Name: Drew Zambelli
// Due Date: Friday, October 28
// Poll.cpp
// Project 4 - expanding from Lab 1, 2 and 3, now we are adding LinkedLists and additional functionality 
// We are modifying various files to view Polls and Promotional posts and updating our Network so that we can 
// store any of these types of posts in our feed. In addition, we are creating methods to edit and monitor content
// and remove language that should not be shown

#include <iostream>
#include <vector>
#include <string>

#include "Poll.hpp"

// *********** PARAMETERIZED CONSTRUCTOR *************

   /**
      Parameterized constructor for Poll
        @param    : The title (name) of the Poll post (a string)
        @param    : The question (body) of the Poll post (a string)
        @param    : : The username of the Account that added this poll (a string)
        @param    : A vector of options for the Poll post

        @post     :Sets the title, body and username of the Poll post to the value of the parameters.
                   It will also generate the current time and store it and will initialize
                   the vectors of options and their respective number of votes.
   */

Poll::Poll(const std::string post_title, const std::string post_body, const std::string post_author, std::vector<std::string> poll_options) : Post(post_title, post_body, post_author) {
    this->poll_options = poll_options;

    for(int i = 0; i<this->poll_options.size(); i++){
        vote_count.push_back(0);
    }

}

// ************ Vote Poll Function **************

   /**

         @param     : a reference to int between 0 < number of options
         @return    : True if index is within range and we can vote for a poll,
                      false otherwise
         @post      : Increments the poll votes based on the index which
                      will refer to the index in the poll options
   */

bool Poll::votePoll(const int numOptions) {
    if(numOptions >= 0 && numOptions < poll_options.size()) {
        vote_count[numOptions]++;
        return true;
    }
    return false;
}

//********** Change Poll Options Function *************

   /**
      Mutator function used to either add a poll or change one of the poll options
         @param     : A reference to the new poll option
         @param     : A reference to int that can either represent the index of the
                      existing option that will be replaced
                      or if choice_number > current number of options,
                      it will add this new option to the poll.

        @post       : Resets the number of votes for this option.
   */

void Poll::changePollOption(const std::string pollAddition, const int index){
    if(index < poll_options.size()){
        poll_options.at(index) = pollAddition;
        vote_count[index] = 0;
    } else if (index >= poll_options.size()){
        poll_options.push_back(pollAddition);
        vote_count.push_back(0);
    }
}

//*********** Get Poll Options *************

/**
      Accessor function
        @post       : prints the reaction to the post in this format
                    (example where option_n is the string at position n in the poll options vector):
                    0 votes for: option_1
                    5 votes for: option_2
                    2 votes for: option_3
                    ...
   */

void Poll::getPollOptions() const {
    for (int i = 0; i<poll_options.size(); i++){
        std::cout << vote_count[i] << " votes for: " << poll_options[i] << std::endl;
    }
}

//********** Get Poll Votes Function ************

 /**
      Accessor function
      @param      : The index of the option
      @return     : returns the number of votes for a given option
   */

int Poll::getPollVotes(const int numPollVotes) const {
    return vote_count[numPollVotes];
}


//********** displayPost for Poll **********
   /**
      Display the Poll's title, time stamp, body and also prints the options a user can vote for
      @post   : displays the whole Poll post (example):
                \n
                {post_title_} at {time_stamp_}:
                {post_body_}
                \n
                0 votes for: option_1
                5 votes for: option_2
                2 votes for: option_3
                ...
                \n
   */

void Poll::displayPost() {
    std::cout << getTitle() << " at ";
    getTimeStamp();
    std::cout << getBody() << std::endl;
    getPollOptions();
}
