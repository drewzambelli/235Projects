#include <iostream>
#include <string>
#include <regex>

#include "Promotional.hpp"

// *********** PARAMETERIZED CONSTRUCTOR *************

   /**
      Parameterized constructor.
         @param       : The name of the Promotional post (a string)
         @param       : The body of the Promotional post (a string)
         @param    : : The username of the Account that added this post (a string)
         @param       : The link of the Promotional post (a string)

        @post         : Sets the title, body, username and link (if it's a proper link otherwise "Broken Link")
                       of the Promotional to the value
                       of the parameters.
                       It will also generate the current time and store it.
   */

Promotional::Promotional(const std::string post_title, const std::string post_body, const std::string post_author, const std::string url) : Post(post_title, post_body, post_author) {
        const std::regex pattern("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)"); // THIS IS FROM GEEKS FOR GEEKS URL: https://www.geeksforgeeks.org/check-if-an-url-is-valid-or-not-using-regular-expression/
        
        if (url == ""){
            this->url = "Broken Link";
        } else if (std::regex_match(url, pattern)) {
            this->url = url;
        } else {
            this->url = "Broken Link";
        }
}

// *********** ACCESSORS *************

   /**
      Accessor function to retrive link
      @return         : Returns the post link
   */

std::string Promotional::getLink() const{
    return url;
}

// ************ MUTATORS *************

   /**
      @param    : A reference to the link that is in the format 'https://www.something.something'
                  or 'http://www.something.something' with the last 'something' being at least 2 characters
      @return   : true if the link is correctly formatted, false otherwise

      @post     : If the link is not correctly formatted, store "Broken Link"
                  in the link member variable, otherwise store the value of the
                  parameter (Hint: see <regex>)
   */

bool Promotional::setLink(const std::string url){
    const std::regex pattern("((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)"); // THIS IS FROM GEEKS FOR GEEKS URL: https://www.geeksforgeeks.org/check-if-an-url-is-valid-or-not-using-regular-expression/
        if (std::regex_match(url, pattern)) {
            this->url = url;
            return true;
        } else {
            this->url = "Broken Link";
        }
        return false;
}


   /**
      @post      : displays the entire Promotional post (example):
                  \n
                  {post_title_} at {time_stamp_}:
                  {post_body_}
                  \n
                  {link}
                  \n
   */

void Promotional::displayPost() {
    std::cout << getTitle() << " at ";
    getTimeStamp();
    std::cout << getBody() << std::endl;
    std::cout << getLink() << std::endl;
}