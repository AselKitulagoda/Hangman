#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

struct hangman {
  char hangword[100];
  char output[100];
  char tempWord[100];
  int moves;
  int pos ;
  int winner;
  int corlettersloop ;
  int found;
  int lives;

};
typedef struct hangman hangman;


void newGame (hangman *g,char *hangword){
  strcpy(g->hangword,hangword);
  int i;
  for (i=0; i<strlen(g->hangword)-1;i++){
    g->output[i] = '-';
  }
  g->output[i] = '\0';
  g->moves = 0;
  // g->pos = 0;
  g->lives = 0;
  g->found = 0;
  }

void usertext (hangman *g, char *alphabet){
if (*alphabet >= 'a' || *alphabet <='z'){
  for ( g->corlettersloop =0; g->corlettersloop<strlen(g->hangword); g->corlettersloop ++){
  if ( *alphabet == g->hangword[g->corlettersloop]){
  g->pos = g->corlettersloop;
  g->output[g->pos] = *alphabet;
}
}
for ( g->corlettersloop =0; g->corlettersloop<strlen(g->hangword); g->corlettersloop ++){
if ( *alphabet == g->hangword[g->corlettersloop]){
  g->found = 1;
  break;
}
else g->found = -1;
}
if (g->found == -1 ){
  g->lives ++;}
printf("%s \n",g->output);
}
else g->lives ++;
}


bool won(hangman * g)
{
    for(int i=0;i<(strlen(g->hangword)-1);i++){
      if (g->output[i]== '-')
        return false;
}
    printf("you won !!!\n");
    return true;

}

bool lose(hangman *g){
if (g->lives > 4){
  return true;
  printf("you lose :( \n");
}
}

void draw_hangman( int incorrect_tries )
{


   switch( incorrect_tries )
   {
      default:
      {
         puts( "\n  ___" );
         puts( " |" );
         puts( " |" );
         puts( " |" );
         puts( " |" );
         puts( " |" );
         puts( "---" );
         break;
      }

      case 1:
      {
         puts( "\n  ___" );
         puts( " |  &" );
         puts( " |" );
         puts( " |" );
         puts( " |" );
         puts( " |" );
         puts( "---" );
         break;
      }

      case 2:
      {
         puts( "\n  ___" );
         puts( " |  &" );
         puts( " |  O" );
         puts( " |" );
         puts( " |" );
         puts( " |" );
         puts( "---" );
         break;
      }

      case 3:
      {
         puts( "\n  ___" );
         puts( " |  &" );
         puts( " |  O" );
         puts( " | /" );
         puts( " |" );
         puts( " |" );
         puts( "---" );
         break;
      }

      case 4:
      {
         puts( "\n  ___" );
         puts( " |  &" );
         puts( " |  O" );
         puts( " | /|" );
         puts( " |" );
         puts( " |" );
         puts( "---" );
         break;
      }

      case 5:
      {
         puts( "\n  ___" );
         puts( " |  &" );
         puts( " |  O" );
         puts( " | /|\\" );
         puts( " |" );
         puts( " |" );
         puts( "---" );
         break;
      }

      case 6:
      {
         puts( "\n  ___" );
         puts( " |  &" );
         puts( " |  O" );
         puts( " | /|\\" );
         puts( " | /" );
         puts( " |" );
         puts( "---" );
         break;
      }

      case 7:
      {
         puts( "\n  ___" );
         puts( " |  &" );
         puts( " |  O" );
         puts( " | /|\\" );
         puts( " | / \\" );
         puts( " |" );
         puts( "---" );
         break;
      }
   }
}



int main(int n, char *args[n])
{   hangman gamedata;
    hangman *g = &gamedata;
    char alphabet[2];
  if (n == 1) {
  printf("Please enter a word you would like to play : \n");
	fgets(g->hangword,100, stdin);
	newGame(g, g->hangword);
  won(g);
  while (!won(g)) {
    (fflush(stdin));
    printf("please state your guess: \n");
    fgets(alphabet, 100, stdin);
    usertext(g,alphabet);
    if (g->lives > 7){
      printf("you lose !!!");
      break;
    }
    draw_hangman(g->lives);
    printf("lives remaining:%d\n",g->lives);
    }
  }
  else {
	fprintf(stderr, "Use: ./hangman  OR  ./hangman X\n");
	exit(1);
    }
    return 0;
}

