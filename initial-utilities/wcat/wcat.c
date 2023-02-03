#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define openFileError "wcat: cannot open file\n"

int main(int argc, char *argv[])
{
    int i, ch;
    if (argc != 1)
    {
        // Iterate through each currInFile specified on the command line
        for (i = 1; i < argc; i++)
        {
            FILE *inFile;
            if ((inFile = fopen(argv[i], "r")) == NULL)
            {
	        fwrite(openFileError, sizeof(char), strlen(openFileError), stdout);
                return 1;
            }
            while ((ch = fgetc(inFile)) != EOF)
            {
                fwrite(&ch, sizeof(char), 1, stdout);
            }
            fclose(inFile);
        }
    }
    return 0;
}
