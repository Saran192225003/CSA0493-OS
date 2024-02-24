#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char line[100];
    char search[20];

    printf("Enter the string to search: ");
    scanf("%s", search);

    file = fopen("example.txt", "r");

    printf("Lines containing '%s':\n", search);
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, search)) {
            printf("%s", line);
        }
    }

    fclose(file);
    return 0;
}

