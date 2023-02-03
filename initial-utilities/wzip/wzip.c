#include <stdio.h>
#include <string.h>

#define openFileError "wzip: cannot open file\n"
#define usage "wzip: file1 [file2 ...]\n"

int main(int argc, char *argv[])
{
    int countChar = 1, i = 1;
    char currChar, prevChar;
    if (argc < 2)
    {
        fwrite(usage, sizeof(char), strlen(usage), stdout);
        return 1;
    }
    for (i = 1; i < argc; i++)
    {
        FILE *currInFile;
        if (!(currInFile = fopen(argv[1], "r")))
        {
            fwrite(openFileError, sizeof(char), strlen(openFileError), stdout);
            return 1;
        }
        if (i == 1)
            prevChar = fgetc(currInFile);

        while ((currChar = fgetc(currInFile)) != EOF)
        {
            if (currChar == prevChar)
            {
                countChar++;
            }
            else
            {
                fwrite(&countChar, sizeof(int), 1, stdout);
                fwrite(&prevChar, sizeof(char), 1, stdout);
                prevChar = currChar;
                countChar = 1;
            }
        }
        if (i == argc - 1)
        {
            fwrite(&countChar, sizeof(int), 1, stdout);
            fwrite(&prevChar, sizeof(char), 1, stdout);
        }

        fclose(currInFile);
    }
    return 0;
}
