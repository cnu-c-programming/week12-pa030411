#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = argc > 1 ? argv[1] : "code/myfile.txt";
    char line[256];

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    if (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s\n", line);
    }

    fclose(fp);
    return 0;
}
