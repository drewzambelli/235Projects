#include <iostream>
#include <iomanip>

#include "Post.hpp"
#include "Account.hpp"
#include "Network.hpp"

using namespace std;


int main () {
    cout << "alsk;dja;kdf;ladhfadg";
    Post post1("in the summer time", "passwordz", "Mungo Jerry");
    cout << endl;
    cout << post1.getTitle() << endl;
    cout << post1.getBody() << endl;
    cout << post1.getUsername() << endl;
    cout << "IS THIS WORKING" << endl;
    Network<Account> network1;

    Account drew1("Billy Joel", "is testing");
    Account drew2("Bruce", "Springsteen");
    Account drew3("Neil", "Young");
    Account drew4("Mitch", "Mitchell");
    Account drew5("Jimi", "Hendrix");
    Account drew6("Drew", "Zambelli");
    cout << drew1.getUsername();
    Account bob1("bob1_okay", "bob1_okay");

    Account* drew1ptr;
    Account* drew2ptr;
    Account* drew3ptr;
    Account* drew4ptr;
    Account* drew5ptr;
    Account* drew6ptr;


    drew1ptr = &drew1;
    drew2ptr = &drew2;
    drew3ptr = &drew3;
    drew4ptr = &drew4;
    drew5ptr = &drew5;
    drew6ptr = &drew6;

    cout << endl;
    cout << "address of drew1ptr: " << drew1ptr << endl;
    cout << endl;
    cout << "address of &drew1: " << &drew1 << endl;
    cout << endl;
    cout << network1.addAccount(drew1ptr) << endl;

    Network<Account> network2;
    network2.addAccount(drew2ptr);
    network2.addAccount(drew3ptr);
    network2.addAccount(drew4ptr);
    network2.addAccount(drew5ptr);

    cout << boolalpha << network2.isEmpty() << endl;

    cout << boolalpha << "Does network2 contain drew3ptr: " << network2.containsAccount(drew3ptr) << endl;
    cout << boolalpha << "Does network2 contain drew2ptr: " << network2.containsAccount(drew2ptr) << endl;

    cout << drew2.getNetwork() << endl;

    cout << drew2.followAccount("Mitch");
    cout << drew2.followAccount("Billy");
    cout << drew2.followAccount("Jimi");
    cout << "this is mitch again: " << drew2.followAccount("Mitch") << endl;

    network2.printFeedForAccount(drew2);  
    Network<Account> network3;
    cout << "CALLING POPULATENETWORK METHOD: " << endl;
    network3.populateNetwork("accounts.txt"); 
    cout << "this is what I get when I populate network with TXT file: " << network3.getSizeOfNetwork() << endl;
    network3.addAccount(drew6ptr);
    cout << "this is what I get when I add an account to that network created from TXT: " << network3.getSizeOfNetwork() << endl;

    cout << boolalpha << network3.containsAccount(drew6ptr) << endl;
    









   
    return 0;
}