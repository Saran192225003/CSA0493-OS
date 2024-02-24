#include <stdio.h>
#include <dirent.h>

int main() {
    struct dirent *de;
    DIR *dr = opendir("."); // Open the current directory

    if (dr == NULL) {
        printf("Could not open current directory");
        return 0;
    }

    while ((de = readdir(dr)) != NULL) {
        printf("%s\n", de->d_name);
    }

    closedir(dr);
    return 0;
}

