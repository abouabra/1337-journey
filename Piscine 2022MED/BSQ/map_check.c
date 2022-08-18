#include <stdio.h>
#include <stdlib.h>

int main (int ac,char **av) {
	FILE * file;
	char *line1;
	int i;
	i=ac;
	line1="";
   file = fopen (av[1], "r");
   fscanf(file, "%s",line1);
   printf("%s",line1);
   
   fclose(file);
   
   return(0);
}
