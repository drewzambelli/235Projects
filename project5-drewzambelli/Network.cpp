/****************************************************************************************************************************
Title         :   Network.hpp
Author        :   Dream Team
Description   :   Implementation files for Network class
****************************************************************************************************************************/
// Name: Drew Zambelli
// Due Date: Tuesday, November 22
// Network.cpp
// Project 5 - expanding from Labs 1, 2, 3, and 4, we are adding additional functionality to allow users
// to sort the Network's feed by the username of the account that posted each Post in the feed. To do so, we
// are implementing a Bubble Sort.


#include "Network.hpp"

template <typename ItemType>
Network<ItemType>::Network() : account_count_(0), feed_({}){}


template <typename ItemType>
int Network<ItemType>::getSizeOfNetwork() const { return account_count_; }


template <typename ItemType>
bool Network<ItemType>::isEmpty() const { return account_count_ == 0; }


/**
   @param            : a POINTER to the item that will be added to the Network
   @return           : bool- true  if the item was successfully added, false otherwise
   @post             : stores a pointer to the item, if there is room. This is a network specific function,
                       it has an additional constraint: the item will be added only if no other item in the network
                       has the same username (usernames are considered unique)
                       Finally, the Account being added to the network will update it's private member to point to this network
*/
template <typename ItemType>
bool Network<ItemType>::addAccount(ItemType* new_entry) {
    bool has_room = ( account_count_ < DEFAULT_CAPACITY );
    if(has_room && getIndexOf(new_entry->getUsername()) < 0){
        network_[account_count_] = new_entry;
        new_entry->setNetwork(this);
        account_count_++;
        return true;
    }
    return false;
}


/**
   Mutator function
   @param            :   a POINTER to the item that will be removed from Network
   @return           :   true if if the item was successfully removed, false otherwise
   @post             :   updates the bag/network to remove the pointer, if a pointer to that item was found.
*/
template <typename ItemType>
bool Network<ItemType>::removeAccount(ItemType* an_entry) {
    int found_account = getIndexOf(an_entry->getUsername());
    bool can_remove = !isEmpty() && ( found_account > -1 );
    if(can_remove){
        account_count_--;
        if(!(account_count_ == found_account))
            network_[found_account] = network_[account_count_];
    }
    return can_remove;
}


/**
 @post      :removes all accounts from the network
 **/
template <typename ItemType>
void Network<ItemType>::clear(){
    // account_count_ = 0;
    while (account_count_ > 0) {
        removeAccount(*(network_[account_count_-1]));
    }
}


/**
 @return      : true if an_etry is found in network_, false otherwise
 **/
template <typename ItemType>
bool Network<ItemType>::containsAccount(const ItemType &an_entry) const {
    return getIndexOf(an_entry.getUsername()) > -1;
}


/**
   Mutator function
   @param            :   the name of an input file
   @pre              :   The format of the text file is as follows:
                         username password
                         username password
                         ;

                         where ';' signals the end of the file. Check the provided example (accounts.txt).

   @post             :   Reads every line in the input file, creates an Account from that information and
                         adds the Account to the network. If a line of input is missing some required information,
                         it prints out "Improper Format" and terminates.
                         Keep in mind that, although the input will always be an Account, the Network class is
                         a template, thus it will store a pointer to a generic type. It will do so by creating a new
                         dynamic object of type ItemType but passing the account information (username and password)
                         as to the Account constructor. This is a bit hacky, but it will work for our Network.


*/
template <typename ItemType>
void Network<ItemType>::populateNetwork(const std::string input){
    std::fstream fin;
    fin.open(input, std::ios::in);
    std::string usr = "";
    std::string pswd = "";
    std::string line;
    std::string word;
    while (std::getline(fin, line)){
        if(line == ";") {
            break;
        }
        std::stringstream s(line);
        s >> usr;
        s >> pswd;
        if(usr == "" || pswd == "") {
            std::cout << "Improper format" << std::endl;
            break;
        }
        // ItemType new_entry(usr,pswd);
        // addAccount(new_entry);
        ItemType* new_entry = new ItemType(usr,pswd);
        bool is_added = addAccount(*new_entry);
        if(!is_added) {
            std::cout << "Error when adding account" << std::endl;
            break;
        }
        usr = "";
        pswd = "";
    }
    fin.close();
}


/**
   Accessor function
   @param            :   a reference to the item whose feed will be displayed
   @post             :   prints the feed of the given account by checking who they are following
                         and displaying all the posts from the feed that were made by those accounts.
                         Keep in mind that the Network parameters are general template types
                         in this project rather than accounts, although this functionality is
                         specific to accounts.
*/
template <typename ItemType>
void Network<ItemType>::printFeedForAccount(ItemType &an_entry) {

    int location = getIndexOf(an_entry.getUsername());

    if(location > -1) {

        std::vector<std::string> following_list = network_[location]->viewFollowing();
        Node<Post*>* itt = feed_.getHeadPtr();

        while(itt != nullptr) {

            Post* curr_item = itt->getItem();
            std::string curr_user = curr_item->getUsername();

            for(std::string acc_username : following_list) {
                if(acc_username == curr_user) {
                    curr_item->displayPost();
                    break;
                }
            }

            itt = itt->getNext();

        }

    }
}


template <typename ItemType>
int Network<ItemType>::getIndexOf(const std::string username) const {
    bool found = false;
    int result = -1;
    int index = 0;

    while(!found && (index < account_count_)){
        if (network_[index]->getUsername() == username) {
            found = true;
            result = index;
        }
        else { index++; }
    }

    return result;
}



/**
   @param            :   a reference to an item (account) and the username of the account
                         it wants to follow
   @return           :   true if the item was authorized to follow, false otherwise

   @post             :   the referenced Account follows another account with the username
                         specified by the second argument if they both exist in the network
*/
template <typename ItemType>
bool Network<ItemType>::authenticateFollow(ItemType &an_entry, const std::string username) const {

    int index_user = getIndexOf(an_entry.getUsername());

    if(index_user > -1){
        int index = getIndexOf(username);

        if(index > -1) {
            an_entry.followAccount(username);
            return true;
        }
    }

    return false;

}


/**
   @param            :   a pointer to Post

   @post             :  the post is added to the feed if the account username is in the network
*/
template <typename ItemType>
void Network<ItemType>::addToFeed(Post* p) {
    if(getIndexOf(p->getUsername()) > -1)
        feed_.insert(p, 0);
}


/**
The (set) difference between two sets A and B is the set that
consists of the elements of A which are not elements of B
@param  : a_network to be subtracted from the Network Bag calling the function
@post   : removes all the data from network_ that is also found in a_network
**/
template <typename ItemType>
void Network<ItemType>::operator-=(Network<ItemType> &a_network){
    int index = 0;
    int this_index = 0;
    int accounts_left = a_network.account_count_;

    while (accounts_left > 0){
        if(this->account_count_ == 0){
            break;
        }
        this_index = this->getIndexOf(a_network.network_[index]->getUsername());
        if(this_index > -1){
            this->removeAccount(*(this->network_[this_index]));
        }
        index++;
        accounts_left--;
    }
}


/**
   @param            :   a pointer to Post
   @return           :  true if post was removed from feed, false otherwise
   @post             :  the post is removed from to the feed if there
*/
template <typename ItemType>
bool Network<ItemType>::removePostFromFeed(Post* post){
    int postPosition = feed_.getIndexOf(post);

    if (postPosition > -1) {
        feed_.remove(postPosition);
        return true;
    }
    return false;
}


/*
    @param            :   A string (word or phrase, case-sensitive) passed by reference
    @return           :   The number of items removed from the list

    @post              :  Any Post that contains the provided word or phrase in it's title,
                          body or both is removed from the Network's `feed_` as well as
                          the Account's `posts_`.

    You are encouraged to create your own helper functions for this endeavour.
*/
template <typename ItemType>
int Network<ItemType>::removeIfContains(const std::string &postBody){
    int occurrences{0};
    if(feed_.getSize() == 0) { return occurrences; }
    else {
        Node<Post*>* curr = feed_.getHeadPtr();
        while(curr != nullptr){
            Post* curr_post = curr->getItem();
            curr = curr->getNext();
            if (curr_post->getTitle().find(postBody) != std::string::npos ||
                curr_post->getBody().find(postBody) != std::string::npos
            ){
                int acc_index = getIndexOf(curr_post->getUsername());
                if(acc_index > -1) {
                    network_[acc_index]->removePost(curr_post);
                }
                occurrences++;
            }
        }
    }
    return occurrences;
}



/**
   @param            :   a pointer to Post
   @return           :  true if post was found and moved to the front of the  feed,
                        false otherwise
   @post             :  The post is moved to the front of the feed
*/
template <typename ItemType>
bool Network<ItemType>::updateFeed(Post* post) {
    return feed_.moveItemToTop(post);
}




/**
   Accessor function
   @post             :   prints the feed by displaying all the posts from the feed
*/
template <typename ItemType>
void Network<ItemType>::printFeed(){
    Node<Post*> *header = feed_.getHeadPtr();

    while(header != nullptr) {
        std::cout << header->getItem() << '\n';
        header = header->getNext();
    }
}

// *************** PROJECT 5 FUNCTION ***************
/*

    THIS FUNCTION SHOULD NOT MODIFY THE ORIGINAL FEED. INSTEAD IT SHOULD RETURN A COPY OF
    THE ORIGINAL FEED SORTED BY USERNAME.

    @param            :   The Comparator to sort with
    @param            :   A POINTER to an integer counter that gets incremented every time a SWAP between two Nodes occurs
                          (this is for testing purposes).
                          IT IS IMPORTANT TO PASS OUR GRADESCOPE TESTS TAHT EACH
                          TIME BUBBLE SORT MAKES A SWAP YOU INCREMENT THIS COUNTER.

    @return           :   A COPY of the feed_ sorted by username using bubble sort
                          based on Comparator ( std::less or std::greater ),
                          from least to greatest or greatest to least.
*/
//bSortByUsername

template <typename ItemType>
template <typename Comparator>
LinkedList<Post*> Network<ItemType>::bSortByUsername(Comparator compVals, int* counter){
    LinkedList<Post*> copyOne = feed_;
    copyOne.bSorting(compVals, counter);
    return copyOne;
}
//END PROJECT 5 FUNCTION