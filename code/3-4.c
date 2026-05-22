#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* src = argc > 1 ? argv[1] : "code/myfile.txt";
    const char* dst = argc > 2 ? argv[2] : "myfile3.txt";
    char buffer[256];

    FILE* in = fopen(src, "r");
    if (in == NULL) {
        perror("error: cannot open");
        return 1;
    }

    FILE* out = fopen(dst, "w");
    if (out == NULL) {
        perror("error: cannot open");
        fclose(in);
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), in) != NULL) {
        if (fputs(buffer, out) == EOF) {
            perror("error: cannot write");
            fclose(out);
            fclose(in);
            return 1;
        }
    }

    if (ferror(in)) {
        perror("error: cannot read");
        fclose(out);
        fclose(in);
        return 1;
    }

    fclose(out);
    fclose(in);
    return 0;
}

