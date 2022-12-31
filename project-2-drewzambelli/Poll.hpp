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
        void displayPost();

    private:
        std::vector<std::string> poll_options; //vector of strings to store each option a voter can vote for
        std::vector<int> vote_count; //a vector of ints to store the number of votes each options has received
};


#endif