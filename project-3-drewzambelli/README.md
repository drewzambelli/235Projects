# Project 3: Welcome To The Social Network - Array Bag and Template Classes

![network](./network.jpg)

_**Now that Posts can be both monetized and interactive, it is time to establish a Network. As a great man once said, "There is no purpose without followers." Within this Network, people can follow each other and make Posts for their followers to see. But be wary, bots roam about and you must maintain a method that would allow the Network to abolish all robotic fiends from your platform.**_

In this project you will create the `Network` class and modify the `Account` class to be able to operate on the `Network`.  


### Access the assignment in GitHub Classroom:
This is the link to accept this assignment on GitHub Classroom: **https://classroom.github.com/a/TdwDsN4k**

---

### Some additional resources on Array Bag

-   [James Allert](https://youtu.be/l1vDQ-Vyoic)

### Some additional resources on Template Classes

-   [Code Beauty](https://youtu.be/qrJjFN4Igfw)
-   [Cherno](https://youtu.be/I-hZkUa9mIs)

### Some additional resources on reading from files

- [fstream](https://cplusplus.com/reference/fstream/fstream/)
- [reading a file line by line](https://www.delftstack.com/howto/cpp/how-to-read-a-file-line-by-line-cpp/#:~:text=in%20C%2B%2B.-,Use%20std%3A%3Agetline()%20Function%20to%20Read%20a%20File,stores%20them%20in%20a%20string.)

---

### Implementation:


**Work incrementally!** Work through the tasks sequentially (implement and test). Only move on to a task when you are positive that the previous one has been completed correctly. Remember that the **function names, returns, parameters, pre and post conditions must be exactly as specified in this project specification**. This is a contract, it gives you all the information necessary to complete this assignment correctly. If you don't understand this project specification and its requirements, ask for clarification before you proceed. _Remember to make parameters and functions read-only when appropriate._

---

## Task 1: Living on the Internet: the `Network` class
Define and implement the `Network` template class with a header and a source file.
In this project you will design and implement the network as a **"bag of accounts"**. Although the network will only ever hold and manipulate accounts, you will implement it as a template class for pedagogical reasons, i.e. so that you can practice writing a template class.
You can refer to the `Bag` class (provided with the starter files for this project) to implement the bag-like container operations. What we call **Bag functions** below are mostly identical to the corresponding `Bag` operations but implemented for the `Network` class instead. These will vary whenever indicated in order to handle network- or account-specific operations. This may seem counterintuitive at times: you will be calling account-specific functions on an object of type ItemType, but it's ok because we are assuming that our Network will always be instantiated as a Network of Accounts (i.e. `Network<Account>`).

#### Private member variables:

```
   - An array (with a capacity of 200) that stores POINTERS to the template items.

   - A count of the current number of accounts in the network.

   - A vector of Posts: the Network's feed where all posts posted by accounts in the network will be stored.


```

### Private member functions:
```
- A function that returns the index of a given account within the Network.
/**
   private function
   @param            :   string - the username of item we want the index of
   @return           :   int - the index of the item, -1 if the account is not found
*/
getIndexOf


```

### Public member functions:

#### Constructors

```
   /**
      Default constructor.

      Initializes private variables to default initial values.
   */
```

#### Bag functions

```
   /**
      Accessor function
      @return           : int -  the current size of the network (number of items in the array)
   */
   getSizeOfNetwork



   /**
      @return           : bool -  true if the bag is empty, false otherwise
   */
   isEmpty



   /**
      @param            : a POINTER to the item that will be added to the Network
      @return           : bool- true  if the item was successfully added, false otherwise
      @post             : stores a pointer to the item, if there is room. This is a network specific function,
                          it has an additional constraint: the item will be added only if no other item in the network
                          has the same username (usernames are considered unique)
                          REMEMBER WE ARE STORING POINTERS TO ITEMS, NOT ITEMS.
                          Finally, the Account being added to the network will update it's private member to point to this network
                          (see Account class modifications below, you may come back and implement this feature after
                          you work on Task 2, but don't forget!!!).
                          NOTE: every object in C++ has access to a pointer to itself called `this`, thus the nework can pass `this` pointer to the account!
   */
   addAccount



   /**
      Mutator function
      @param            :   a POINTER to the item that will be removed from Network
      @return           :   true if if the item was successfully removed, false otherwise
      @post             :   updates the bag/network to remove the pointer, if a pointer to that item was found.
   */
   removeAccount



   /**
      Mutator function
      @post             :   Empties the bag/network
   */
   clear




   /**
      @param            :   a POINTER to the item to find
      @return           :   true if the item was successfully found, false otherwise
   */
   containsAccount

```

#### Network-specific Functions
These functions are specific to the Network. These are not adapted from the Bag class, instead you must implement these from scratch.

```
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
   populateNetwork



   /**
      Mutator function
      @param            :   a reference to another Network

      @post             :  Removes from the Network any items that also appear in the other Network.
                           In other words, removes elements from the network on the left of the operator that
                           are also found in the network on the right of the operator.
      Why is this useful? For example, given a network of known bot accounts, remove all bots from this Network.
   */
   operator-=


```
### Account class modifications

Now that accounts are part of a Network, you must also **adapt the `Account` class** so that accounts can follow one another.

#### Private member variables:

```
   - A vector of usernames the Account is following  
   - A pointer to the Network this account is part of. Before the Account is added to a Network,
     the pointer is `nullptr`.
```

#### Public member functions:

```
   /**
      Accessor function
      @return           :   the pointer to the Network the account is in
   */
   getNetwork

   /**
      Mutator function
      @param            :   a pointer to a Network
      @post             :   the Network pointer private member points to the input Network
   */
   setNetwork
```

---

## Task 2: You seem like a nice person
We are now ready to **allow accounts in a `Network` to follow one another**.

The `Account` class **must be further modified** to incorporate the following _public member functions_ :

```
   /**
      @param            :   the username of the Account to follow
      @return           :   true if the account was successfully able to follow, false otherwise
      @post             :   adds the username to the vector of following accounts only if
                            it is affiliated to a Network AND it is not already following an account
                            with the same username.
   */
   followAccount



   /**
      @return           :   the vector of usernames the Account is following
   */
   viewFollowing




   /**
      MODIFY this function to also add the Account username to the Post and then add the Post
      to its Networks feed if it is connected to one. NOTE: you will need to add this functionality
      to the network as well (see Network modifications below - you may want to create a STUB for it,
      or implement this functionality after you modified the Network.)

      @param title   : A reference to the title used to generate the Post object
      @param body    : A reference to the body used to generate the Post object
      @post          : generates a Post with the given title and body and adds it to it's vector
                       of posts AND to the Network's feed if it is connected to a Network.
      @return        : Will return true if the Post does not have an empty title or body and the
                       Post is successfully added to the vector
   */
   addPost
```

The `Network` class **must be further modified** to incorporate the following _public member functions_:

```
   /**
      Accessor function
      @param            :   a reference to the item whose feed will be displayed
      @post             :   prints the feed of the given account by checking who they are following
                            and displaying all the posts from the feed that were made by those accounts.
                            Keep in mind that the Network parameters are general template types
                            in this project rather than accounts, although this functionality is
                            specific to accounts.
   */
   printFeedForAccount




   /**
      @param            :   a reference to an item (account) and the username of the account
                            it wants to follow
      @return           :   true if the item was authorized to follow, false otherwise

      @post             :   the referenced Account follows another account with the username
                            specified by the second argument if they both exist in the network
   */
   authenticateFollow



   /**
      Mutator function
      @param            :   a reference to a Post be added to the feed
      @return           :   returns true if the Post was successfully added to the feed, false otherwise
      @post             :   Adds the post to its feed only if the Post was created by an Account
                            in this Network.
   */
   addToFeed
```

---

### Submission:
**You will submit your solution to Gradescope via GitHub Classroom. The autograder will grade the following files only**:   
`Account.hpp Account.cpp Network.hpp Network.cpp`

Your project must be submitted to Gradescope through GitHub Classroom. Although Gradescope allows multiple submissions, it is not a platform for testing and/or debugging and it should not be used for that. You MUST test and debug your program locally. Before submitting to Gradescope you MUST ensure that your program compiles using the provided makefile and runs correctly on the Linux machines in the labs at Hunter (see detailed instructions on how to upload, compile and run your files in the “Programming Guidelines” document). That is your baseline, if it runs correctly there it will run correctly on Gradescope, and if it does not, you will have the necessary feedback (compiler error messages, debugger or program output) to guide you in debugging, which you don’t have through Gradescope. **“But it ran on my machine!” is not a valid argument for a submission that does not compile.** Once you have done all the above you submit it to Gradescope.

---

### Testing
How to compile in your **Makefile**:   
In terminal, in the same directory as your *Makefile and your source files*, use the following command
```
make rebuild
```

This assumes you did not modify or rename the Makefile provided with in the starter code for this project and that it is the only makefile in that directory.

You must always implement and test you programs **INCREMENTALLY!!!**
What does this mean? Implement and test one method at a time.
**For each class**
- Implement one function/method and test it thoroughly (multiple test cases + edge cases if applicable).
- Implement the next function/method and test in the same fashion.
**How do you do this?** Write your own `main()` function to test your classes. In this course you will never submit your test program, but you must always write one to test your classes. Choose the order in which you implement your methods so that you can test incrementally: i.e. implement mutator functions before accessor functions. Sometimes functions depend on one another. If you need to use a function you have not yet implemented, you can use stubs: a dummy implementation that always returns a single value for testing.  Don’t forget to go back and implement the stub!!! If you put the word STUB in a comment, some editors will make it more visible.

### Grading Rubrics
**Correctness 80%** (distributed across unit testing of your submission)  
**Documentation 15%**  
**Style and Design 5%** (proper naming, modularity, and organization)  

---

### Important
You must start working on the projects as soon as they are assigned to detect any problems and to address them with us **well before** the deadline so that we have time to get back to you **before** the deadline.
**There will be no extensions and no negotiation about project grades after the submission deadline.**
