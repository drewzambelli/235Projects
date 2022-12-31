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
        void displayPost();
        
    private:
        int arr_reactions[6]; //array of reactions from enum

    };


#endif