#include <stdio.h>

int main() {
    FILE *file;
    char data[100];

    // Writing to a file
    file = fopen("example.txt", "w");
    fprintf(file, "Hello, File Management!");
    fclose(file);

    // Reading from a file
    file = fopen("example.txt", "r");
    fgets(data, 100, file);
    printf("Data from file: %s\n", data);
    fclose(file);

    return 0;
}

