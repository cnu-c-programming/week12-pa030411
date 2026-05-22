#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = argc > 1 ? argv[1] : "code/myfile.txt";
    int freq[26] = {0};
    int ch;

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            freq[ch - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        printf("%c: %d\n", 'a' + i, freq[i]);
    }

    fclose(fp);
    return 0;
}
