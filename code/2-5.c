#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* src = argc > 1 ? argv[1] : "code/myfile.txt";
    const char* dst = argc > 2 ? argv[2] : "myfile3.txt";
    char buffer[256];

    FILE* in = fopen(src, "r");
    if (in == NULL) {
        return 0;
    }

    FILE* out = fopen(dst, "w");
    if (out == NULL) {
        fclose(in);
        return 0;
    }

    while (fgets(buffer, sizeof(buffer), in) != NULL) {
        fputs(buffer, out);
    }

    fclose(out);
    fclose(in);
    return 0;
}
