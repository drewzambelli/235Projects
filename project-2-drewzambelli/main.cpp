#include <iostream>

#include "General.hpp"
#include "Post.hpp"
#include "Poll.hpp"
#include "Promotional.hpp"

int main() {

    General post1("this is the title", "and this will be the body", "John");

    std::cout << post1.getTitle() << std::endl;
    std::cout << post1.getBody() << std::endl;
    post1.reactToPost(LIKE);
    post1.reactToPost(ANGRY);
    post1.reactToPost(LIKE);
    post1.reactToPost(LIKE);
    post1.reactToPost(DISLIKE);
    post1.getReactions();

    post1.displayPost();

    Poll poll1("POLL ONE", "Do you like pizza?", "John", {"Yes", "No", "N/A", "Maybe"});
    
    std::cout << poll1.getTitle() << " ******** " << poll1.getBody() << "*********" << poll1.getUsername() << std::endl;

    poll1.votePoll(3);
    poll1.votePoll(1);
    poll1.votePoll(1);
    poll1.votePoll(1);
    poll1.votePoll(2);
    poll1.getPollOptions();

    poll1.changePollOption("apples", 2);

    poll1.displayPost();

    std::cout << "******* " << poll1.getPollVotes(1) << " *********" << std::endl;

    Promotional promo1("testing promo 1 title", "testing promo 1", "Drew", "solo");

    promo1.displayPost();

    promo1.setLink("solo");

    promo1.displayPost();
}