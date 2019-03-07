#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

struct hangman {
    char hangword[100];
    char output[100];
    int tries;

};
typedef struct hangman hangman;

/*Intialises game accepts hangword from user
sets output to dashes corresponding to length of hangword
intialises variables in structure*/
void newGame(hangman * g, char *hangword)
{   g->tries = 5;
    strcpy(g->hangword, hangword);
    int i;
    for (i = 0; i < (strlen(g->hangword)-1); i++) {
	g->output[i] = '-';
    }
    g->output[i]= '\0';
    printf ("Hangman input: %s\n",g->output);
}

/*checks to see if a character user inputs is in hangword
if it is character shows up in output
if its not a character in hangword take away a try
if it is not a character in hangword keep output as a dash*/
void findchar(hangman * g, char *alphabet)
{
char incorrect_letters[100];
int num_letters = 0,
     count = 0,
     cf = 0,
     rf = 0;
num_letters = (strlen(g->hangword));
for(count = 0; count<num_letters; count++){
if (*alphabet == g->output[count] || *alphabet == incorrect_letters[count]){
  rf = 1;
  cf = 1;
  break;
}

if (rf ==0)
for (count = 0; count < num_letters; count++){
  if (*alphabet == g->hangword[count]){
    g->output[count] = *alphabet;
    cf = 1;
  }
}
if (cf ==0){
  incorrect_letters[g->tries] = *alphabet;
  g->tries--;
}
rf = 0;
cf = 0;
printf("hangman\n");
}
     printf("%s\n",g->output);
}
/*check all the characters in output is not a dash if its not the user has won*/
bool won(hangman * g)
{
    for(int i=0;i<(strlen(g->hangword));i++){
      if (g->output[i]== '-')
        return false;
}
    printf("you won !!!\n");
    return true;

}
/*check the tries is not equal to zero if it is the user has lost*/

bool lose(hangman * g)
{
  if (g->tries <= 0){
  printf("You lose!!\n");
	return true;
}
    else
	return false;
}
/*testing
tests testNew*/
void testNew()
{
    hangman gamedata;
    hangman *g = &gamedata;
    char hangword[100];
    strcpy(hangword, "hangword");
    newGame(g, hangword);
    int i;
    for (i = 0; i < (strlen(hangword)-1); i++) {
	assert(g->output[i] == '-');
    }
    assert(g->tries == 5);
}
/*tests find char*/
void testfindchar()
{
    hangman gamedatas;
    hangman *g = &gamedatas;
    char alphabet[2];
    strcpy(alphabet, "g");
    char hangword[100];
    strcpy(hangword, "hangword");
    newGame(g, hangword);
    printf("%s\n",g->output);
    assert(g->output[7]=='\0');
    findchar(g, alphabet);
    assert(g->output[3] == 'g');
    fflush(stdin);
    strcpy(hangword, "hangword");
    newGame(g, hangword);
    strcpy(alphabet, "z");
    findchar(g, alphabet);
    int i;
    for (i = 0; i < (strlen(hangword)-2); i++){
    assert(g->output[i]=='-');}
    assert(g->tries == 4);
}


void test()
{
    hangman *g = malloc(sizeof(hangman));
    testNew(g);
    testfindchar();
    free(g);
    printf("All tests passed.\n");
}

int main(int n, char *args[n])
{
    hangman gamedata;
    hangman *g = &gamedata;
    char alphabet[2];
    if (n == 1)
	   test();
    else if (n == 2) {
	fgets(g->hangword,100, stdin);
	newGame(g, g->hangword);
  lose(g);
  while (!won(g) && !lose(g)) {
    (fflush(stdin));
    fgets(alphabet, 100, stdin);
    findchar(g,alphabet);
    printf("tries remaining:%d\n",g->tries);
    }
  }
  else {
	fprintf(stderr, "Use: ./hangman  OR  ./hangman X\n");
	exit(1);
    }
    return 0;
}
