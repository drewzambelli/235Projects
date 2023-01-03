
# Project 4: Let's Link Up! - Linked Lists and Polymorphism

![network](./linked_list.png)

_**Finally, we have a social media platform that we can put out to the world, but there are still some kinks. First of all, we cannot view Polls and Promotional posts! We need to update our Network so that we can store any of these types of posts in our feed. In addition, we need to establish a method to monitor content and remove language that should not be shown to the young audience of our application.**_


### Access the assignment in GitHub Classroom:
This is the link to accept this assignment on GitHub Classroom: **https://classroom.github.com/a/8DIHkl81**

---

### Some additional resources on Linked Lists

-   [HackerRank](https://youtu.be/njTh_OwMljA)
-   [CS Dojo](https://youtu.be/WwfhLC16bis)

### Some additional resources on Polymorphism

-   [Code Beauty](https://youtu.be/wK93q-JQUvw)
-   [Simple Snippets](https://youtu.be/uc_Hr10cBBE)

### Some additional resources on finding substrings

- [geeksforgeeks](https://www.geeksforgeeks.org/string-find-in-cpp/)
---

### Implementation:


**Work incrementally!** Work through the tasks sequentially (implement and test). Only move on to a task when you are positive that the previous one has been completed correctly. Remember that the **function prototypes must be exactly as specified in this project specification**. This is a contract, it gives you all the information necessary to complete this assignment correctly. If you don't understand this project specification and its requirements, ask for clarification before you proceed. _Remember to make parameters and functions read-only when appropriate._


# SUBMISSION CHANGE:
## Gradescope will accept 5 submissions per day only!

---

## Task 1: Installing Update
Update the following functions in your `Network`, `Account`, `Post`, and `Post children` classes.

### Project 2 Anew

Currently, we can only store one type of data in our Network's feed. How can we get around that in order to view different kinds of posts? Ta-da! - Polymorphism!!!

#### Storing Posts

* Instead of storing Post objects, the `Network` and `Account` classes should now store POINTERS to Posts in a LINKED LIST (instead of a vector). Use the LinkedList class provided with the starter code for this project. Make the necessary updates in the member functions of `Network` and `Account` to reflect this change.

* Account should now be taking a const POINTER to a Post in its addPost function. In this way, we will be able to harness polymorphism to store different Post subclasses (General, Promotional and Poll). As before, the Post will be added to both the Account's `following_` and the Network's `feed_`.


#### Displaying Posts



* Make the Post class abstract by making the displayPost function virtual, where the implementation only lies within its children classes. Make the necessary updates in the Poll, Promotional, and General classes.



---

## Task 2: A Refresh Button and Censorship
We will now add some functionality to the `LinkedList` class in order to support some new Network and Account operations. Then we will add these new features to our `Network` and `Account` classes.

### LinkedList modifications

#### The Ol' Copy and Paste

Implement the following _public member functions_ in the provided `LinkedList` class:

```
/*
    A copy constructor
    @param            :   Another LinkedList passed by reference

    Initializes this LinkedList with the same items as the provided LinkedList
*/


/*
    A reversed copy function
    @param            :   Another LinkedList passed by reference

    Sets the current LinkedList with the same items as the provided LinkedList
    but in reverse order
*/
reverseCopy

/*
    @param            :   Pointer to an object passed by reference
    @return           :   Return true if item moved to top else false
    This function will take the item from its current position and move it to the front
    of the list.
    For example, given the list 1 -> 3 -> 5 -> 6, moving the item at position 2 to the
    top of the list would result in 5 -> 1 -> 3 -> 6 (recall that positions start at 0
    and end at n-1).

    You are encouraged to create your own helper functions for this endeavour.
*/
moveItemToTop
```

### Network and Account modifications

#### Content Striking

A network is responsible for the content that circulates on its platform. We must implement a mechanism for the Network to monitor such content.
Implement the following _public member function_ in your `Network` class:

```
/*
    @param            :   A string (word or phrase, case-sensitive) passed by reference
    @return           :   The number of items removed from the list

    This function will look through the body and title of all Posts in the Network's feed.
    If a Post contains the provided word or phrase, then it must be removed from the Network's `feed_` as well as the Account's `posts_`.

    You are encouraged to create your own helper functions for this endeavour.
*/
removeIfContains
```

#### Editing Posts

A Network user should have the ability to edit or delete previously posted content. Moreover, whenever a Post is modified, it's `timestamp_` will change, making it the most recent.  

NOTE THAT, now our `feed_` and `posts_` are LinkedLists instead of vectors, therefore the order of insertion has changed. Most recent posts are at the front of the list (instead of the back of the vector). Modifying a Post will result in moving it to the front.

Implement the following _public member functions_ in your `Account` class:

```
/*
    @param            :   Pointer to a Post object
    @param            :   The new title of the Post (or an empty string if you do not
                          want to change it)
    @param            :   The new body of the Post (or an empty string if you do not
                          want to change it)

    @post            :   This function will take the Post and given the new title and body,
                         update the Posts title and body as appropriate. It will also update the `timestamp_` to the current time of the update. This function should then
                         update the location of the Post in its list of `posts_` to the front of the list as well as utilizing its Network pointer to do the same in the `feed_`.

    You are encouraged to create your own helper functions for this endevour.
*/
updatePost


/*
    @param            :   A pointer to a Post
    @return           :   If the Post was successfully found and removed

    This function will remove the given Post from its list as well as from the Network's feed.
    Returns True if successfully removed, False if not. Afterwards, tell the Network to remove
    the Post as well from its feed.

    You are encouraged to create your own helper functions for this endevour.
*/
removePost
```


---

### Submission:
**You will submit the following files ONLY through GitHub Classroom**:  
`Account.hpp Account.cpp Network.hpp Network.cpp LinkedList.hpp LinkedList.cpp`
`Post.hpp Post.cpp General.hpp General.cpp Promotional.hpp Promotional.cpp Poll.hpp Poll.cpp`

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

*Credits: Tiziana Ligorio, Violent Hajdini, Yash Mahtani*
