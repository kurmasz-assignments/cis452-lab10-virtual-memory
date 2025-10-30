/**********************************************************
 *
 * sampleProgram1.c
 * CIS 452 Lab 10
 *
 * !!!NAMES!!!
 *************************************************************/
#include <stdio.h>
#include <stdlib.h>

#ifndef	COEFFICIENT
#define COEFFICIENT 8
#endif	

#ifndef	LOOP
#define LOOP 500
#endif

void print_human_readable_size(const char*, long);

int main()
{
   int count, *intPtr;

   long int i, j, dim = COEFFICIENT * 1024;

   size_t desired_size = dim * dim * sizeof(int);
   print_human_readable_size("About to malloc", desired_size);
   if ((intPtr = malloc (desired_size)) == 0) {
      perror ("totally out of space");
      exit (1);
   }
   for (count=1; count<=LOOP; count++)
      for (i=0; i<dim; i++)
         for (j=0; j<dim; j++)
            intPtr[i * dim + j] = (i + j) % count;

   free (intPtr);
   return 0;
}


void print_human_readable_size(const char* label, long bytes) {
    const double KB = 1024.0;
    const double MB = 1024.0 * KB;
    const double GB = 1024.0 * MB;
    const double TB = 1024.0 * GB;

    double value = bytes;
    const char *unit = "bytes";

    if (bytes >= TB) {
        value = bytes / TB;
        unit = "TB";
    } else if (bytes >= GB) {
        value = bytes / GB;
        unit = "GB";
    } else if (bytes >= MB) {
        value = bytes / MB;
        unit = "MB";
    } else if (bytes >= KB) {
        value = bytes / KB;
        unit = "KB";
    }

    printf("%s %ld (%.2f %s)\n", label, bytes, value, unit);
}