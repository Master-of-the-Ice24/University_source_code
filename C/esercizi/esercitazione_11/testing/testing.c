#include <stdio.h>
#include <string.h>

#define NUM_ALPHA  26
 
int main(void)
{
  FILE * stream;
  int num;       /* number of characters read from stream */
 
  /* Do not forget that the '\0' char occupies one character too! */
  char buffer[NUM_ALPHA + 1];
 
  if (( stream = fopen("myfile", "r"))!= NULL )
  {
    memset(buffer, 0, sizeof(buffer));
    num = fread( buffer, sizeof( char ), NUM_ALPHA, stream );
    if ( num ) {  /* fread success */
      printf( "Number of characters has been read = %i\n", num );
      printf( "buffer = %s\n", buffer );
      fclose( stream );
    }
    else {  /* fread failed */
      if ( ferror(stream) )    /* possibility 1 */
        perror( "Error reading myfile" );
      else if ( feof(stream))  /* possibility 2 */
        perror( "EOF found" );
    }
  }
  else
    perror( "Error opening myfile" );
 
}