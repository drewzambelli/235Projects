#include <iostream>

#include <ctime>
#include <string>

#include "Post.hpp"

//******PARAMETERIZED CONSTRUCTOR******

   /**
      Parameterized constructor.
      @param title  : The title of the post
      @param body   : The body content of the post

      Sets the title and body of the Post to what was passed by the user
      Will also generate the current time and store it
   */

Post::Post(std::string post_title, std::string post_body){ //parameterized constructor taking in post title and post boddy
    this->post_title = post_title;
    this->post_body = post_body;
    this->time_stamp = time(0);
}

//******MUTATORS******

   /**
    * Set Title method
     @param  : a reference to title of the Post
   */

void Post::setTitle(const std::string post_title){ //method to set the title of the post
    this->post_title = post_title;
}

   /**
    * Set Body method
      @param  : a reference to body of the Post
   */

void Post::setBody(const std::string post_body){ //method to set body of post
    this->post_body = post_body;
}

//******ACCESSORS******

   /**
    * Get the Title of the post
      @return : the title of the Post
   */

std::string Post::getTitle() const{ //method to get title of post
    return post_title;
}

   /**
    * Get the body of the post
      @return : the body of the Post
   */

std::string Post::getBody() const{ //method to get body of post
    return post_body;
}

   /**
    * Get the time stamp for the post
      @post   : prints the time the Post was created to the standard output as asctime(localtime(&time_stamp_))
   */

void Post::getTimeStamp() const{ //method to get the time stamp for when the post was created
    std::cout << asctime(localtime(&time_stamp));
}

   /**
    * Method to print the post
      Print the Post in the following format:

      {title} posted at {time}:
      {body}

   */

void Post::displayPost(){ //method to print the post
    std::cout << post_title << " posted at ";
    getTimeStamp();
    std::cout << post_body << std::endl;
}
