#include <stdio.h>

int main(void) {
    FILE* fp = fopen("log.txt", "a");
    if (fp == NULL) {
        return 0;
    }

    fprintf(fp, "success\n");
    fclose(fp);
    return 0;
}
