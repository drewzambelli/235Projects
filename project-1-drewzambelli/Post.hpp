#ifndef POST_H
#define POST_H

#include <ctime>
#include <string>

//class declarations for Post class
class Post {

public:

    //default constructor
    Post() = default;

    //parameterized constructor taking in title and body
    Post(std::string post_title, std::string post_body);

    //Mutators to set the title and body of the post
    void setTitle(const std::string post_title);
    void setBody(const std::string post_body);

    //Accessors to retrieve the title, body, and time stamp of the post
    std::string getTitle() const;
    std::string getBody() const;
    void getTimeStamp() const;

    //Accessor to print the post
    void displayPost();

private:

    std::string post_title; //The title of the post
    std::string post_body; //The body of the post
    std::time_t time_stamp; //The time that the post was created

};



#endif