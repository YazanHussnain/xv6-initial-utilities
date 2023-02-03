#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define openFileError "wgrep: cannot open file\n"
#define usage "wgrep: searchterm [file ...]\n"

int main(int argc, char *argv[])
{
    char *pattern = argv[1];
    if (argc < 2)
    {
        fwrite(usage, 1, strlen(usage), stdout);
        return 1;
    }
    else if (argc == 2)
    {
        char *line = NULL;
        size_t len = 0;
        while (getline(&line, &len, stdin) != -1)
        {
            if (strstr(line, pattern) != NULL)
            {
                fwrite(line, 1, strlen(line), stdout);
            }
        }
        free(line);
    }
    else
    {
        for (int i = 2; i < argc; i++)
        {
            char *file = argv[i];
            FILE *fp = fopen(file, "r");
            if (fp == NULL)
            {
                fwrite(openFileError, 1, strlen(openFileError), stdout);
                return 1;
            }

            char *line = NULL;
            size_t len = 0;
            while (getline(&line, &len, fp) != -1)
            {
                if (strstr(line, pattern) != NULL)
                {
                    fwrite(line, 1, strlen(line), stdout);
                }
            }

            fclose(fp);
            free(line);
        }
    }

    return 0;
}