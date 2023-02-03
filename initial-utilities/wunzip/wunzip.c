#include <stdio.h>
#include <string.h>

#define openFileError "wgrep: cannot open file\n"
#define usage "wunzip: file1 [file2 ...]\n"

int main(int argc, char *argv[])
{
    int i, count;
    char currChar;
    if (argc < 2)
    {
        fwrite(usage, sizeof(char), strlen(usage), stdout);
        return 1;
    }
    for (i = 1; i < argc; i++)
    {
        FILE *inFile;
        if (!(inFile = fopen(argv[i], "r")))
        {
            fwrite(openFileError, sizeof(char), strlen(openFileError), stdout);
            return 1;
        }

        while (fread(&count, sizeof(int), 1, inFile) != 0 && fread(&currChar, sizeof(char), 1, inFile) != 0)
        {
            for (int i = 0; i < count; i++)
            {
                fwrite(&currChar, sizeof(char), 1, stdout);
            }
        }

        fclose(inFile);
    }
    return 0;
}
