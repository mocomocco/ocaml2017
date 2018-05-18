#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

FILE * open_sesame (char *name)
{
  FILE *stream;
  errno = 0;
  stream = fopen (name, "r+"); 
  printf("errno:%d\n",errno);
  if (stream == NULL)
    {
      fprintf (stderr, "%s: Couldn't open file %s; %s\n",
	       //program_invocation_short_name,
"AAAA",
      name,strerror (errno));
      exit (EXIT_FAILURE);
    }
  else
    return stream;
}

int main(int argc, char* argv[]){
  FILE* fp = open_sesame("./my_text");
  fclose(fp);
  open_sesame("./my_text");
  return EXIT_SUCCESS;
}
