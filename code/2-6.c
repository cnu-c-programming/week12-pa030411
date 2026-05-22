#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {
    const char* filename = argc > 1 ? argv[1] : "code/myfile.txt";
    const char* target_str = argc > 2 ? argv[2] : "out";
    char line[512];

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, target_str) != NULL) {
            printf("%s", line);
        }
    }
    
    fclose(fp);
    return 0;
}
