### Overview:

This is a version control system with three basic functionalities : 


1- making a repository


2- committing changes


3- loading by commit ID

### How to use:

To use this set up the files in the same folder and specify the location of the file to be tracked along with version in the program.

### Functionalities

Menu Service gives the above three options as functionalty.
The first service make a repository including a file "diff.txt" where the differences between commits are to be saved.
Second service Commit creates a file "commit.txt" with author name, and a commit message, along with that a commit ID can be generated through a hash function such as SHA-256.
The third service is a work in progress. It aims to load a commit by traversing a doubly linked list of diff data changes which are taken between commits as "snapshots" of the file.
