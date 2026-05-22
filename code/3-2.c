#include <stdio.h>

int main(int argc, const char* argv[]) {
    
    const char* filename = argc > 1 ? argv[1] : "code/myfile.txt";
    char buffer[10] = {0};

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    int idx = 0;
    int ch;

    while (idx < 9 && (ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r') {
            continue;
        }
        buffer[idx++] = (char)ch;
    }
    buffer[idx] = '\0';

    printf("%s\n", buffer);

    fclose(fp);

    return 0;
}
