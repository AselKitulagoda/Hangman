## Hangman in C

### About 
* This is a hangman program in C that takes in a string input which is then converted into a series of '-'s and then allows the user to guess each character in the hidden string. This program makes use of pointers and array data structures extensively. 

### Pre-requisities 
* You need to have ***GCC*** installed from [here](https://gcc.gnu.org/install/)

### How to Run
* Go to the root folder and execute the command : ```make -B```.

### Game Play
* Below is an extract of gameplay taken from the game. 
``` 
Please enter a word you would like to play : 
hello
please state your guess: 
d
----- 

  ___
 |  &
 |
 |
 |
 |
---
lives remaining:1
please state your guess: 
e
-e--- 

  ___
 |  &
 |
 |
 |
 |
---
lives remaining:1
please state your guess: 
l
-ell- 

  ___
 |  &
 |
 |
 |
 |
---
lives remaining:1
please state your guess: 
o
-ello 

  ___
 |  &
 |
 |
 |
 |
---
lives remaining:1
please state your guess: 
h
hello 

  ___
 |  &
 |
 |
 |
 |
---
lives remaining:1
you won !!!
 ```
