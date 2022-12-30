# Project 1: A Place To Call Your Own -- A Review of Classes and Objects

![vehicle_meme](./social_media_pic1.png)

_**You are a businessperson with billions of dollars worth of assets, but there is one product you wish to own more than anything... a social media platform. Unable to acquire one of the top dogs in the industry, you are left to create your own.**_

In this project you will begin to create the barebones of a social media application. You will create two classes, `Account` and `Post`.   

Before we get started, let's establish some best practices:
* In this course we will use **GitHub Classroom** to get you started working with git version control. All projects in this course will be distributed via GitHub Classroom and submitted to Gradescope via GitHub. We truly hope you will start establishing best practices of version control, you will need it in the near future, so better start now!
* With each project, we will provide a `Makefile` that you will use to compile and link multiple classes into one executable.

### Getting started with GitHub Classroom:
If you don’t already have one, go to https://github.com/ and create a GitHub account. You will likely use your GitHub account professionally in the future, so choose a username you will want to keep.

Next, watch this video to brush-up on, or learn, the basics of git and GitHub: https://www.youtube.com/watch?v=MJUJ4wbFm_A

The following video will guide you through the entire process: from accepting an assignment to submitting your solution. https://www.youtube.com/watch?v=AHDCokfgcSo

Although the video is about a different course, the instructions are the same (with different repo and file names). The only difference is that we will not add a distribution branch, so you can ignore the part where it says to execute the two git commands in the readme file there are not extra instructions in the readme file on our repo).

This is the link to accept this assignment on GitHub Classroom: **https://classroom.github.com/a/mfZSS8nq**

This video will also show you how to submit to Gradescope via GitHub. Make sure to refer back to these instructions when it’s time to submit.



In order to successfully complete this project, you **must** understand the prerequisite material: basic concepts in OOP - Classes and Objects.

---

### Some additional resources if you need to brush up on basic OOP

-   [Code Beauty on constructors and class methods](https://youtu.be/1LGJSRFrxqQ)
-   [thenewboston on classes and objects](https://youtu.be/ABRP_5RYhqU)
-   [McProgramming on .hpp and .cpp files](https://youtu.be/plCegnf2h5g)

---
### Implementation:



**Work incrementally!** Work through the tasks sequentially (implement and test). Only move on to a task when you are positive that the previous one has been completed correctly. Remember that the function prototypes must be exactly as specified in this project specification. This is a contract, it gives you all the information necessary to complete this assignment correctly. If you don't understand this project specification and its requirements, ask for clarification before you proceed. _Remember to make functions and parameters read-only (i.e. const) when appropriate._

For this first project ONLY, we will provide a `main.cpp` that you can use to test your code. This is a sample. After this project, you will need to come up with your own tests. The `Makefiles`, as distributed, will expect `main.cpp`, but after this first project you will need to write your own tests.

---

## Task 1: For The Content (the `Post` class)
Define and implement the `Post` class with a header and a source file (this will be the assumption from now on: when you implement a class, you will have two files .hpp and .cpp).

The `Post` class **must** have the following _private member variables_:

```
   The title of the post (a string)
   The body of the post (a string)
   The time that the post was created (a time_t object, using the time.h library)
```

The `Post` class **must** contain _public member functions_ that do the following:

### Constructors

```
   /**
      Parameterized constructor.
      @param title  : The title of the post
      @param body   : The body content of the post

      Sets the title and body of the Post to what was passed by the user
      Will also generate the current time and store it
   */
```

### Accessors (get) and Mutators (set)
```
   /**
     @param  : a reference to title of the Post
   */
   setTitle

   /**
      @return : the title of the Post
   */
   getTitle

   /**
      @param  : a reference to body of the Post
   */
   setBody

   /**
      @return : the body of the Post
   */
   getBody

   /**
      @post   : prints the time the Post was created to the standard output as asctime(localtime(&time_stamp_))
   */
   getTimeStamp
```

### Displaying

```
   /**
      Print the Post in the following format:

      {title} posted at {time}:
      {body}

   */
   displayPost
```


---

## Task 2: Accounting 101 (the `Account` class)
After implementing and thoroughly testing the `Post` class, define, implement and test the `Account` class with a header and a source file (again, after this first project, it will no longer be explicitly stated and we will assume that every class has a header and implementation file).

The `Account` class **must** have the following _private member variables_:

```
   The account username (a string)
   The account password (a string)
   A vector of Post objects that stores all the Posts posted by this account
```

The `Account` class **must** contain _public member functions_ that do the following:

### Constructors

```
   /**
      Default constructor.
      Sets the username and password of the Account to an empty string
      Sets the vector of posts to an empty vector
   */


   /**
      Parameterized constructor.
      @param username  : username of the Account
      @param password  : password of the Account

      Sets the username and password of the Account to what was passed by the user
      Sets the vector of posts to an empty vector
   */

```
### Accessors (get) and Mutators (set)
```

   /**
    @param a reference to the username of the Account
    */
   setUsername

   /**
      @return the username of the Account
   */
   getUsername

   /**
      @param a reference to the password of the Account
   */
   setPassword

   /**
      @return the password of the Account
   */
   getPassword



```

### Posting
```
   /**
      @param title   : A reference to the title used to generate the Post object
      @param body    : A reference to the body used to generate the Post object
      @post         : generates a Post with the given title and body and adds it to it's vector of posts
      @return       : Will return true if the Post does not have an empty title or body and the Post is successfully added to the vector
   */
   addPost

   /*
      @post         : Prints the vector of Posts using their display function
   */
   viewPosts
```

---

### Submission:
**You will submit the following files ONLY to Gradescope via GitHub Classroom (see video linked above)**:  
`Account.cpp Account.hpp Post.cpp Post.hpp`

Your project must be submitted to Gradescope through GitHub Classroom. Although Gradescope allows multiple submissions, it is not a platform for testing and/or debugging and it should not be used for that. You MUST test and debug your program locally. Before submitting to Gradescope you MUST ensure that your program compiles using the provided `Makefile` and runs correctly on the Linux machines in the labs at Hunter (see detailed instructions on how to upload, compile and run your files in the “Programming Guidelines” document). That is your baseline, if it runs correctly there it will run correctly on Gradescope, and if it does not, you will have the necessary feedback (compiler error messages, debugger or program output) to guide you in debugging, which you don’t have through Gradescope. **“But it ran on my machine!” is not a valid argument for a submission that does not compile.** Once you have done all the above you submit it to Gradescope.

---

### Testing
How to compile in your **Makefile**:   
In terminal, in the same directory as your *Makefile and your source files*, use the following command
```
make rebuild
```

This assumes you did not rename the `Makefile` and that it is the only one in the current directory.

You must always implement and test you programs **INCREMENTALLY!!!**
What does this mean? Implement and test one method at a time.
**For each class**
- Implement one function/method and test it thoroughly (multiple test cases + edge cases if applicable).
- Implement the next function/method and test in the same fashion.
**How do you do this?** Write your own `main()` function to test your classes (we will provide one with this project, but you can always add to it). In this course you will never submit your test program, but you must always write one to test your classes. Choose the order in which you implement your methods so that you can test incrementally: i.e. implement constructors then accessor functions, then mutator function. Sometimes functions depend on one another. If you need to use a function you have not yet implemented, you can use stubs: a dummy implementation that always returns a single value for testing.  Don’t forget to go back and implement the stub!!! If you put the word STUB in a comment, some editors will make it more visible.

### Grading Rubrics
**Correctness 80%** (distributed across unit testing of your submission)  
**Documentation 10%**  
**Style and Design 10%** (proper naming, modularity, and organization)  

---

### Due date:

This project is **due 9/13 at 11pm**   
No late submissions will be accepted.


### Important
You must start working on the projects as soon as they are assigned to detect any problems and to address them with us **well before** the deadline so that we have time to get back to you **before** the deadline.
**There will be no extensions and no negotiation about project grades after the submission deadline.**  



*Credits: Tiziana Ligorio, Violent Hajdini, Yash Mahtani*
