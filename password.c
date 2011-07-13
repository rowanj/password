/*
  password.c
  Rowan James (Phere Development Pty. Ltd.) 2011
  Simple password generator for C & POSIX environments.

  Free for any use.
*/

#include <stdio.h>
#include <ctype.h>

/*
  Change this if you want less complex passwords, in descending order:
  isprint isalphanum isalpha islower
*/
#define CHARACTER_FUNCTION isprint

/*
  Change this number to the length of password you want to generate...
  Or you could run the program multiple times and paste the output together.
*/
const int length = 12;

int main()
{
  /* stores the number of output characters that have been printed so far */
  int printed = 0;
  /* a handle to a file to be used as a source of randomness.
     /dev/random sholud be used on most systems. */
  FILE* rand = fopen("/dev/random", "r");

  /* if the file could not be opened, exit with an error code
     note that no message (or password) is given. */
  if (0 == rand)
    return 1;
  /* non-zero exit from main() is generally interpreted as an error */

  /* loop until the right number of characters have been printed */
  while (printed < length) {
    /* read one character from the input stream */
    int ch = getc(rand);

    /* determine if it is appropriate for a password */
    if (CHARACTER_FUNCTION(ch)) {
      /* if so, write it out */
      putchar(ch);
      /* and increase our count of written characters */
      ++printed;
    }
  }
  /* when we are done, write a newline to separate the output from the
     command line environment. */
  putchar('\n');

  return 0; /* zero exit from main() is generally interpreted as 'success' */
}
