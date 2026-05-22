#include <stdio.h>

int main(int argc, const char* argv[]) {
    char line[256];

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            FILE* fp = fopen(argv[i], "r");
            if (fp == NULL) {
                continue;
            }

            if (fgets(line, sizeof(line), fp) != NULL) {
                printf("%s\n", line);
            }
            fclose(fp);
        }
    } else {
        const char* filenames[] = { "code/myfile.txt", "code/myfile2.txt" };

        for (int i = 0; i < 2; i++) {
            FILE* fp = fopen(filenames[i], "r");
            if (fp == NULL) {
                continue;
            }

            if (fgets(line, sizeof(line), fp) != NULL) {
                printf("%s\n", line);
            }
            fclose(fp);
        }
    }

    return 0;
}
