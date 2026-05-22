#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[], const char* envp[]) {
    (void)argc;
    (void)argv;
    (void)envp;

    FILE* fp = fopen("student.txt", "w");
    char name[64];
    int score;

    if (fp == NULL) {
        return 0;
    }

    while (scanf("%63s", name) == 1) {
        if (strcmp(name, "quit") == 0) {
            break;
        }

        if (scanf("%d", &score) != 1) {
            break;
        }

        fprintf(fp, "%s %d\n", name, score);
    }

    fclose(fp);

    return 0;
}
