/****************************************************************************************************************************
Title         :   Post.hpp
Author        :   Dream Team
Description   :   header/interface for Post class
****************************************************************************************************************************/
// Name: Drew Zambelli
// Due Date: Friday, December 9
// Account.cpp
// Project 6 - expanding from Labs 1, 2, 3, 4, 5 and 6 we are now adding a priority queue and adding additional functionality to allow users
// to sort Posts by likes and priority.

#include "Account.hpp"

//default constructor
//@post:  set username and password to ""
//        creates an empty vector of post objects to store into feed_
Account::Account()
{
    username_ = "";
    password_ = "";
    posts_ = LinkedList<Post*>();
    following_ = {};
}


/**
    Parameterized Constructor
    @param username  : username of the account, stored into username_
    @param password  : password of the account, stored into password_
    @post:             sets the private members to the value of the parameters
*/
Account::Account(std::string username, std::string password) : username_(username), password_(password), posts_(LinkedList<Post*>()), following_({}), net_(nullptr) { }

/**
  @return:     the username of the Account
*/
std::string Account::getUsername() const { return username_; }


/**
  @param:     a reference to the username of the Account
  @psot:      sets the parameter to the value of the private member
*/
void Account::setUsername(const std::string& username) { username_ = username; }


/**
  @return:     the password of the Account
*/
std::string Account::getPassword() const { return password_; }


/**
  @param a reference to the password of the Account
  @post:      sets the private member to the value of the parameter
*/
void Account::setPassword(const std::string& password) { password_ = password; }


/**
      Accessor function
      @return           :   the pointer to the Network the account is in
   */
Network<Account>* Account::getNetwork() const { return net_; }


/**
      Mutator function
      @param            :   a pointer to a Network
      @post             :   the Network pointer private member points to the input Network
   */
void Account::setNetwork(Network<Account>* network) { net_ = network; }


/**
    @param newPost   : The pointer to the Post object that will be added to its list
    @return          : Will return true if a post gets added sucesfully to the vector

    @post:           Adds post to posts_ and its Networks feed_.
    As of project 6, the addPost method has been updated to also add the post to the private member 
    variable vectors postLikes_ and priorityPost_. Additionally, depending on the post's priority, it is 
    added to one of three priority vectors (low_priority_, med_priority_, and high_priority_) for use in other functions.
*/
bool Account::addPost(Post* newPost){
    posts_.insert(newPost, 0);
    net_->addToFeed(newPost);
 
    //new for project 6

    if(newPost->getPriority() == Post::LOW){
        low_priority_.push_back(newPost);
    } else if (newPost->getPriority() == Post::MEDIUM){
        med_priority_.push_back(newPost);
    } else if (newPost->getPriority() == Post::HIGH){
        high_priority_.push_back(newPost);
    }

    int i = 0;
    bool finish = false;
    while(i < postLikes_.size() && !finish) {
        if(postLikes_[i]->getLikes() < newPost->getLikes()) {
            i++;
        } else {
            finish = true;
        }
    }
    postLikes_.insert(postLikes_.begin() + i, newPost);

    int j = 0;
    bool done = false;
    while(j < priorityPost_.size() && !done){
        if(priorityPost_[j]->getPriority() < newPost->getPriority()){
            j++;
        } else {
            done = true;
        }
    }
    priorityPost_.insert(priorityPost_.begin() + j, newPost);

    return true;
}


/*
    @post:      Prints the feed_ that contains the post objects by calling their display function
*/
void Account::viewPosts() const {

    Node<Post*>* itt = posts_.getHeadPtr();

    while (itt != nullptr) {
        itt->getItem()->displayPost();
        itt = itt->getNext();
    }

}



/**
      @param            :   the username of the Account to follow
      @return           :   true if the account was successfully able to follow, false otherwise
      @post             :   adds the username to the vector of following accounts only if
                            it is affiliated to a Network AND it is not already following an account
                            with the same username.
   */
bool Account::followAccount(const std::string username){

    bool exists = false;

    for(std::string un : following_) {
        if(un == username) {
            exists = true;
        }
    }

    if(!exists && net_ != nullptr) {
        following_.push_back(username);
        return true;
    }

    return false;
}


/**
      @return           :   the vector of usernames the Account is following
   */
std::vector<std::string> Account::viewFollowing() const {
    return following_;
}


/**
  @return           :  true if account has same private members as parameter,
                       false otherwise
*/
bool Account::operator==(const Account &acc) const {
    if(acc.getUsername() == this->username_ && acc.getPassword() == this->password_) {
        return true;
    }

    return false;
}

//helper function to help the removePost method actually remove the target post from 
// the new private member vectors created to do Project 6. Had to create this helper function
// because all of my attempts to remove the target post from the new vectors were in vain
// in the removePost method
int helpIndex(std::vector<Post*> &myVec, Post* post){
    for (int i = 0; i < myVec.size(); i++){
        if(post == myVec[i]){
            myVec.erase(myVec.begin() + i);
            return i;
        }
    }
    return -1;
}

/*
@param            :   A pointer to a Post
@return           :   True iff the Post was successfully found and removed,
                      false othewise.
@post             :   Removes the given Post from its list
                      as well as from the Network's feed.
*/
bool Account::removePost(Post* post){
    int postPosition = posts_.getIndexOf(post);
    bool finish = false;
    if (postPosition > -1) {
        posts_.remove(postPosition);
        net_->removePostFromFeed(post);
        finish = true;
    }

    helpIndex(postLikes_, post);
    helpIndex(priorityPost_, post);
    helpIndex(low_priority_, post);
    helpIndex(med_priority_, post);
    helpIndex(high_priority_, post);
    //postLikes_.erase(std::find(postLikes_.begin(), postLikes_.end(), post));
    //priorityPost_.erase(std::find(priorityPost_.begin(), priorityPost_.end(), post));
    //low_priority_.erase(std::find(low_priority_.begin(), low_priority_.end(), post));
    //med_priority_.erase(std::find(med_priority_.begin(), med_priority_.end(), post));
    //high_priority_.erase(std::find(high_priority_.begin(), high_priority_.end(), post));

    // std::vector<int>::iterator it = std::find(postLikes_.begin(), postLikes_.end(), post);
    // if(it != postLikes_.end()){
    //     postLikes_.erase(std::find(postLikes_.begin(), postLikes_.end(), post));
    // }

    // it = std::find(priorityPost_.begin(), priorityPost_.end(), post);
    // if(it != prioritPost_.end()){
    //     priorityPost_.erase(std::find(priorityPost_.begin(), priorityPost_.end(), post));
    // }

    // it = std::find(low_priority_.begin(), low_priority_.end(), post);
    // if(it != low_priority_.end()){
    //     low_priority_.erase(std::find(low_priority_.begin(), low_priority_.end(), post));

    // }

    // it = std::find(med_priority_.begin(), med_priority_.end(), post);
    // if(it != med_priority_.end()){
    //     med_priority_.erase(std::find(med_priority_.begin(), med_priority_.end(), post));

    // }

    // it = std::find(high_priority_.begin(), high_priority_.end(), post);
    // if(it != high_priority_.end()){
    //     high_priority_.erase(std::find(high_priority_.begin(), high_priority_.end(), post));

    // }

    // int priorPost = priorityPost_.find(priorityPost_.begin(), priorityPost_.end(), post);
    // if(priorPost > -1){
    //    priorityPost_.erase(priorPost);
    // }

    // int postLowPrior = low_priority_.find(low_priority_.begin(), low_priority_.end(), post)
    // if(postLowPrior > -1){
    //     low_priority_.erase(postLowPrior);
    // }

    //std::remove(postLikes_.begin(), postLikes_.end(), post);
    //std::remove(priorityPost_.begin(), priorityPost_.end(), post);
    //std::remove(low_priority_.begin(), low_priority_.end(), post);
    //std::remove(med_priority_.begin(), med_priority_.end(), post);
    //std::remove(high_priority_.begin(), high_priority_.end(), post);

    return finish;
}


/*
@param            :   Pointer to a Post object
@param            :   The new title of the Post (or an empty string if you do not
                      want to change it)
@param            :   The new body of the Post (or an empty string if you do not
                      want to change it)

@post            :   This function will take the Post and given the new title and body,
                     update the Posts title and body as appropriate. It will also update
                     the `timestamp_` to the current time of the update. This function should then
                     update the location of the Post in its list of `posts_` to the front of the list
                     as well as utilizing its Network pointer to do the same in the `feed_`.

                     As of project 6, the updatePost method has been updated to also update a post's position
                     in several of the private member variables created for project 6.
*/
bool Account::updatePost(Post* post, std::string new_title, std::string new_body) {
    if(new_title != "") { post->setTitle(new_title); }

    if(new_body != "") { post->setBody(new_body); }

    this->removePost(post);
    this->addPost(post);

    post->updateTimeStamp();

    return net_->updateFeed(post);
}

//PROJECT 6 FUNCTIONS

//**************** METHOD TO GET MINIMUM NUMBER OF LIKES *********************
/*
    @return           :  a pointer to the Post with least likes

    NOTE: YOU MUST DO THIS IN O(1) TIME. Use stack and or queue and add as
    many private members as you need and modify the necessary functions
    and/or add helper functions to do this in O(1) time.

    Note: If multiple Posts have the same amount of likes then it should be sorted from Newest to Oldest
          Where in this case it would be the Newest Post with the least amount of likes returned.
*/

Post* Account::getMinLikes() const {
    if(postLikes_.size() == 0) {
        return nullptr;
    }
    return postLikes_.front();
}

//****************** METHOD TO GET MAXIMUM NUMBER OF LIKES ********************
/*
    @return           :  a pointer to the Post with most likes

    NOTE: YOU MUST DO THIS IN O(1) TIME. Use stack and or queue and add as
    many private members as you need and modify the necessary functions
    and/or add helper functions to do this in O(1) time.

    Note: If multiple Posts have the same amount of likes then it should be sorted from Newest to Oldest
          Where in this case it would be the Oldest Post with the most amount of likes returned.
*/

Post* Account::getMaxLikes() const {
    if(postLikes_.size() == 0) {
        return nullptr;
    }
    return postLikes_.back();
}

//************* METHODS TO SORT VECTORS **************

/*
    @return           :  a vector of pointers to Post
    @post             :  the order of the Posts in the vector is by increasing
                         priority, and within each priority class, from oldest
                         to newest

    NOTE: use stacks and queues to do this in O(n) time

*/

std::vector<Post*> Account::increasingPriorityOldestToNewest() {
    std::vector<Post*> newToOld;
    newToOld.insert(newToOld.end(), low_priority_.begin(), low_priority_.end());
    newToOld.insert(newToOld.end(), med_priority_.begin(), med_priority_.end());
    newToOld.insert(newToOld.end(), high_priority_.begin(), high_priority_.end());
    return newToOld;
}

/*
@return           :  a vector of pointers to Post
@post             :  the order of the Posts in the vector is by increasing
                     priority, and within each priority class, from newest
                     to oldest

NOTE: use stacks and queues to do this in O(n) time
*/

std::vector<Post*> Account::increasingPriorityNewestToOldest(){
    return priorityPost_;
}

/*
    @return           :  a vector of pointers to Post
    @post             :  the order of the Posts in the vector is by decreasing
                         priority, and within each priority class, from oldest
                         to newest

    NOTE: use stacks and queues to do this in O(n) time

*/

std::vector<Post*> Account::decreasingPriorityOldestToNewest(){
    std::vector<Post*> oldToNew;
    oldToNew.insert(oldToNew.end(), high_priority_.begin(), high_priority_.end());
    oldToNew.insert(oldToNew.end(), med_priority_.begin(), med_priority_.end());
    oldToNew.insert(oldToNew.end(), low_priority_.begin(), low_priority_.end());
    return oldToNew;
}

/*
@return           :  a vector of pointers to Post
@post             :  the order of the Posts in the vector is by decreasing
                     priority, and within each priority class, from newest
                     to oldest

NOTE: use stacks and queues to do this in O(n) time

*/

std::vector<Post*> Account::decreasingPriorityNewestToOldest(){
    std::vector<Post*> newToOld;

    std::vector<Post*> newLow = low_priority_;
    std::vector<Post*> newMed = med_priority_;
    std::vector<Post*> newHigh = high_priority_;
    
    std::reverse(newLow.begin(), newLow.end());
    std::reverse(newMed.begin(), newMed.end());
    std::reverse(newHigh.begin(), newHigh.end());

    newToOld.insert(newToOld.end(), newHigh.begin(), newHigh.end());
    newToOld.insert(newToOld.end(), newMed.begin(), newMed.end());
    newToOld.insert(newToOld.end(), newLow.begin(), newLow.end());
    // newToOld.insert(newToOld.end(), high_priority_.begin(), high_priority_.end());
    // newToOld.insert(newToOld.end(), med_priority_.begin(), med_priority_.end());
    // newToOld.insert(newToOld.end(), low_priority_.begin(), low_priority_.end());
    return newToOld;
}

//END PROJECT 6 FUNCTIONS