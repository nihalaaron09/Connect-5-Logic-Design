# Connect-5-Logic-Design
Code in C to win at the popular 'Conncet 5' Game

The working of the game requires additional utility codes to check for a winning 
situation, validate whether moves returned are legal and declare winner/loser
This project contains the following files:
1) proj.c
    This is the main driving code. It makes calls to Student.h and Student2.h
    to enable gameplay
2) Instructor.h
    Set of function prototypes used in proj2.c
3) Instructor.o
    Object file of Instructor.c
4) Student.c
    Working Logic for player. Takes in input arguments as updated board and
    a pointer to player move, and returns an updated pointer to the position
    of the code's returned move
5) Student.h
    Header file for functions that need to be implemented by Student
** Student2.c is Player2's logic. Student.c code may be copied into Student2.c, with
   the appropriate changes made
_______________________________________________________

1. Make a copy of proj2.c, Student.c, Student.h, Student2.c, Student2.c Instructor.o, Instructor.h
2. Compile each Student file separately:
	gcc -c Student.c -o Student.o
3. Generate a.out file:
	gcc proj2.c Student.o Student2.o Instructor.o -o a.out
 
_______________________________________________________

Output:

1) one file containing history of moves returned
2) one file containing 2-D rep of board status after each move

