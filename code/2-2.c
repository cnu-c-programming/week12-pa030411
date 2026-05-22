#include <stdio.h>
#include <string.h>

typedef struct student {
    char name[64];
    int score;
} Student;

int main(int argc, const char* argv[]) {
    const char* filename = argc > 1 ? argv[1] : "student.txt";
    FILE* fp = fopen(filename, "r");
    int count = 0;
    Student students[64];

    if (fp == NULL) {
        fp = fopen("Test/2-2-in-student.txt", "r");
    }

    if (fp == NULL) {
        return 0;
    }

    while (count < 64 && fscanf(fp, "%63s %d", students[count].name, &students[count].score) == 2) {
        count++;
    }

    int max = 0;
    float avg = 0;
    int sum = 0;

    for (int i = 0; i < count; i++) {
        if (i == 0 || students[i].score > max) {
            max = students[i].score;
        }
        sum += students[i].score;
    }

    if (count > 0) {
        avg = (float)sum / count;
    }

    printf("max: %d\n", max);
    printf("avg: %.2f\n", avg);

    fclose(fp);

    return 0;
}

