#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = argc > 1 ? argv[1] : "code/myfile.txt";
    char buffer[256];

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);
    return 0;
}
