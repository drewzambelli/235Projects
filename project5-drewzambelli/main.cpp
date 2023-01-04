#include <iostream>
#include <iomanip>

#include "Post.hpp"
#include "Account.hpp"
#include "Network.hpp"
#include "LinkedList.hpp"
#include "General.hpp"
#include "Node.hpp"


using namespace std;


int main () {
   
    // Post* ptrPoll1 = new Poll("Poll1 Title", "Poll1 Body", "Poll1 Author", {"option1", "option2", "option3", "option4"});

    // Post* ptrPromo1 = new Promotional("Promo1 Title", "Promo1 Body", "Promo1 Author", "https://www.drewzambelli.com/");

// TESTING removeIfContains
    // LinkedList<Post*> postList;
    // Post* ptrPost1 = new General("ptrPost1 Title", "ptrPost1 Body", "1");
    // Post* ptrPost2 = new General("ptrPost2 Body Title", "ptrPost2", "2");
    // Post* ptrPost3 = new General("ptrPost3 Title", "ptrPost3", "3");
    // Post* ptrPost4 = new General("ptrPost4 Title", "ptrPost4 Body", "4");
    // Post* ptrPost5 = new General("ptrPost5 Title", "ptrPost5 Body", "5");
    // Post* ptrPost6 = new General("ptrPost6 Title", "ptrPost6 Body", "6");
    // Post* ptrPost7 = new General("ptrPost7 Title", "ptrPost7 Body", "7");

    // postList.insert(ptrPost1, 0);
    // postList.insert(ptrPost4, 0);
    // postList.insert(ptrPost6, 0);
    // postList.insert(ptrPost2, 0);


    // Account* drew1 = new Account("Billy", "pass");
    // Account* drew2 = new Account("Bruce", "silly");
    // Account* drew3 = new Account("Neil", "okay");
    // Account* drew4 = new Account("Mungo", "Jerry");
    // Account* drew5 = new Account("Bob", "Dylan");
    // Account* drew6 = new Account("John", "Lennon");
    // Account* drew7 = new Account("Chuck", "Berry");

    // Network<Account>* network1 = new Network<Account>; 

    // network1->addAccount(drew1);
    // network1->addAccount(drew2);
    // network1->addAccount(drew3);
    // network1->addAccount(drew4);
    // network1->addAccount(drew5);
    // network1->addAccount(drew6);
    // network1->addAccount(drew7);

    // cout << network1->getSizeOfNetwork() << endl;
    // int count = 0;
    // network1->bSortByUsername(std::greater<Post>(), &count);

    // Node<Post*> *head = postList.getHeadPtr(); 
    // while(head!=nullptr) {
    //     cout << head->getItem()->getUsername() << endl;
    //     head = head->getNext();
    // }
   
    // int count = 0;
    // postList.bSorting(std::less<Post>(), &count);
    // cout << "did this work" << endl;
    // head = postList.getHeadPtr();
    // while(head!=nullptr) {
    //     cout << head->getItem()->getUsername() << endl;
    //     head = head->getNext();
    // }
//END OF TESTING PROJECT 5

    // Account* drew1 = new Account("Billy", "pass");
    // Account* drew2 = new Account("Bruce", "silly");
    // Account* drew3 = new Account("Neil", "okay");
    // Account* drew4 = new Account("Mungo", "Jerry");
    // Account* drew5 = new Account("Bob", "Dylan");
    // Account* drew6 = new Account("John", "Lennon");
    // Account* drew7 = new Account("Chuck", "Berry");

    // Network<Account>* network1 = new Network<Account>; 

    // drew1->setNetwork(network1);  
    // drew2->setNetwork(network1);
    // drew3->setNetwork(network1);
    // drew4->setNetwork(network1);
    // drew5->setNetwork(network1);
    // drew6->setNetwork(network1);
    // drew7->setNetwork(network1);


    // network1->addAccount(drew1);
    // network1->addAccount(drew2);
    // network1->addAccount(drew3);
    // network1->addAccount(drew4);
    // network1->addAccount(drew5);
    // network1->addAccount(drew6);
    // network1->addAccount(drew7);

    // drew1->addPost(ptrPost1);
    // drew2->addPost(ptrPost2);
    // drew3->addPost(ptrPost3);
    // drew4->addPost(ptrPost4);
    // drew5->addPost(ptrPost5);
    // drew6->addPost(ptrPost6);
    // drew7->addPost(ptrPost7);

    // cout << network1->getSizeOfNetwork() << " is the size of network1" << endl;

    // drew4->viewPosts();

    // string x = "Body";

    // cout << network1->removeIfContains(x) << " is the number of occurrences removed." << endl;

    // drew4->viewPosts();

//END TESTING removeIfContains

//START TESTING updatePost Function
    // Post* ptrPost1 = new General("ptrPost1 Title", "ptrPost1 Body", "Billy");
    // Account* drew1 = new Account("Billy", "pass");

    // cout << ptrPost1->getTitle() << endl;
    // cout << ptrPost1->getBody() << endl;
    // cout << "DISPLAY POST HERE BEFORE TITLE/BODY CHANGE: " << endl;
    // ptrPost1->displayPost();
    // cout << endl << endl;

    // drew1->updatePost(ptrPost1, "UPDATING TITLE", "UPDATING Body");

    // cout << ptrPost1->getTitle() << endl;
    // cout << ptrPost1->getBody() << endl;
    // cout << endl << endl;
    // cout << "DISPLAY POST HERE AFTER TITLE/BODY CHANGE: " << endl << endl;
    // ptrPost1->displayPost();

//END TESTING updatePost Function

//START TESTING printfeedforAccount
    // Network<Account>* network2 = new Network<Account>;   
   
    // Post* donPost1 = new General("don title 1", "don body 1", "Billy");
    // Post* donPost2 = new General("don title 2", "don body 2", "Bruce");
    // Post* donPost3 = new General("don title 3", "don body 3", "Neil");
    // Post* donPost4 = new General("don title 4", "don body 4", "Mungo");

    // Account* don1 = new Account("Billy", "pass");
    // Account don2("Bruce", "silly");
    // Account* ptrdon2 = &don2;
    // Account* don3 = new Account("Neil", "okay");
    // Account* don4 = new Account("Mungo", "Jerry");

    // network2->addAccount(don1);
    // network2->addAccount(ptrdon2);
    // network2->addAccount(don3);
    // network2->addAccount(don4);

    // don1->addPost(donPost1);
    // ptrdon2->addPost(donPost2);
    // don3->addPost(donPost3);
    // don4->addPost(donPost4);

    // cout << boolalpha << "Is network2 empty?: " << network2->isEmpty() << endl;

    // cout << boolalpha << "Does network2 contain don1: " << network2->containsAccount(don1) << endl;


    // cout << ptrdon2->followAccount("Neil") << endl;
    // cout << ptrdon2->followAccount("Billy") << endl;
    // cout << ptrdon2->followAccount("Mungo") << endl;

    // cout << "this is mitch again: " << ptrdon2->followAccount("Billy") << endl;

    // network2->printFeedForAccount(don2);

//END TESTING printfeedforAccount


    // LinkedList<Account*>* list1 = new LinkedList<Account*>;
    // // LinkedList<Account*>* list2 = new LinkedList<Account*>;
    // // LinkedList<Account*>* list3 = new LinkedList<Account*>; //value not set to anything to test first if statement of copy list constructor

    // list1->insert(drew1, 0);
    // list1->insert(drew2, 0);
    // list1->insert(drew3, 0);
    // list1->insert(drew4, 0);
    // list1->insert(drew5, 0);



    // cout << "Testing General Display Post: " << endl;

    // ptrPost1->displayPost();

    // cout << list1->getSize() << " is this size of list1." << endl;

    // list2->insert(jerry1, 0);
    // list2->insert(jerry1, 0);
    // list2->insert(jerry1, 0);
    // cout << list2->getSize() << " is this size of list2." << endl;

    // cout << "did this work? " << endl;

    // LinkedList<Account*> copyList1 = *list2;

// USE THIS TO TEST COPY, REVERSE AND MOVE ITEM FUNCTIONS

    // cout << "Inserting 4 numbers" << endl;
    // LinkedList<int> list1;
    // list1.insert(5, 0);
    // list1.insert(7, 0);
    // list1.insert(13, 0);
    // list1.insert(54, 0);

    // cout << "I've just inserted a bunch of integers: " << endl;
    // cout << "5: " << list1.getIndexOf(5) << endl;
    // cout << "7: " << list1.getIndexOf(7) << endl;
    // cout << "13: " << list1.getIndexOf(13) << endl;
    // cout << "54: " << list1.getIndexOf(54) << endl;

    // // cout << "Calling list1 in copy constructor now" << endl;
    // LinkedList<int> copyList1(list1);

    // cout << "COPYLIST INDICES: " << endl;
    // cout << "5: " << copyList1.getIndexOf(5) << endl;
    // cout << "7: " << copyList1.getIndexOf(7) << endl;
    // cout << "13: " << copyList1.getIndexOf(13) << endl;
    // cout << "54: " << copyList1.getIndexOf(54) << endl;


    // cout << "Calling REVERSE COPY CONSTRUCTOR HERE" << endl;
    // list1.reverseCopy(list1);
    // cout << "5: " << list1.getIndexOf(5) << endl;
    // cout << "7: " << list1.getIndexOf(7) << endl;
    // cout << "13: " << list1.getIndexOf(13) << endl;
    // cout << "54: " << list1.getIndexOf(54) << endl;
  

    // cout << "playing with move item to top: " << endl;
    // int x = 13;
    // list1.moveItemToTop(x);

    // cout << "5: " << list1.getIndexOf(5) << endl;
    // cout << "7: " << list1.getIndexOf(7) << endl;
    // cout << "13: " << list1.getIndexOf(13) << endl;
    // cout << "54: " << list1.getIndexOf(54) << endl;

// END OF USE THIS TO TEST COPY, REVERSE AND MOVE ITEM FUNCTIONS

    // LinkedList<Account*> list2 = *list1;

    // cout << endl;
    // cout << "address of drew1ptr: " << drew1ptr << endl;
    // cout << endl;
    // cout << "address of &drew1: " << &drew1 << endl;
    // cout << endl;
    // cout << network1.addAccount(drew1ptr) << endl;

    // Network<Account> network2;
    // network2.addAccount(drew2ptr);
    // network2.addAccount(drew3ptr);

    // cout << boolalpha << network2.isEmpty() << endl;

    // cout << boolalpha << "Does network2 contain drew3ptr: " << network2.containsAccount(drew3ptr) << endl;
    // cout << boolalpha << "Does network2 contain drew2ptr: " << network2.containsAccount(drew2ptr) << endl;

    // cout << drew2.getNetwork() << endl;

    return 0;
}