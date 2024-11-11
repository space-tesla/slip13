Q.2) Write a C program that takes a string as an argument and returns all the files that begin with that name in the current directory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <prefix>\n", argv[0]);
        return 1;
    }

    DIR *dir;
    struct dirent *entry;
    char *prefix = argv[1];

    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    printf("Files starting with '%s':\n", prefix);
    while ((entry = readdir(dir)) != NULL) {
        if (strncmp(entry->d_name, prefix, strlen(prefix)) == 0) {
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
    return 0;
}

Output (assuming files foo.txt, foo_bar.txt, and bar.txt exist in the current directory):

Files starting with 'foo':
foo.txt
foo_bar.txt
