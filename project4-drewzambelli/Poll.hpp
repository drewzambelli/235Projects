// Name: Drew Zambelli
// Due Date: Friday, October 28
// Poll.hpp
// Project 4 - expanding from Lab 1, 2 and 3, now we are adding LinkedLists and additional functionality 
// We are modifying various files to view Polls and Promotional posts and updating our Network so that we can 
// store any of these types of posts in our feed. In addition, we are creating methods to edit and monitor content
// and remove language that should not be shown

#ifndef POLL_H
#define POLL_H

#include <string>
#include <vector>

#include "Post.hpp"

//declarations for POLL class
class Poll : public Post {

    public:
        //Default Constructor
        Poll();
        
        //Parameterized Constructor taking in title, body, post author and vector of poll options
        Poll(const std::string post_title, const std::string post_body, const std::string post_author, std::vector<std::string> poll_options);

        //Mutators
        bool votePoll(const int numOptions);
        void changePollOption(const std::string pollAddition, const int index);

        //Accessors
        void getPollOptions() const;
        int getPollVotes(const int numPollVotes) const;
        virtual void displayPost() override;

    private:
        std::vector<std::string> poll_options; //vector of strings to store each option a voter can vote for
        std::vector<int> vote_count; //a vector of ints to store the number of votes each options has received
};


#endif