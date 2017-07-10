#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define randrange(N) rand() / (RAND_MAX/(N) + 1)

#define MAX 1000        /* Values will be in the range (1 .. MAX) */
int candidates[MAX];

int main (int argc, char **argv)
{
  int vektor[atoi(argv[1])];
  int i;
  int len;


  if (argc != 2)
  {
    printf("enter array length\n");
    return (0);
  }
  len = atoi(argv[1]);
  srand(time(NULL));   /* Seed the random number generator. */

  for (i=0; i<MAX; i++)
    candidates[i] = i;

  for (i = 0; i < MAX-1; i++) {
    int c = randrange(MAX-i);
    int t = candidates[i];
    candidates[i] = candidates[i+c];
    candidates[i+c] = t;
  }

  for (i=0; i<len; i++)
    vektor[i] = candidates[i] + 1;

  for (i=0; i<len; i++)
    printf("%i ", vektor[i]);

  return 0;
}