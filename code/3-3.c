#include <stdio.h>

int main(int argc, const char* argv[]) {
    const char* filename = "myfile.txt";
    char buf[256];
    FILE* fp1 = fopen(filename, "r");
    FILE* fp2 = fopen("tmp.txt", "w");
    char* ret1 = NULL;
    char* ret2 = NULL;

    if (fp1 == NULL) {
        fp1 = fopen("code/myfile.txt", "r");
    }

    while (fp1 != NULL && fgets(buf, sizeof(buf), fp1) != NULL) {
    }

    buf[0] = '\0';
    ret1 = fp1 == NULL ? NULL : fgets(buf, sizeof(buf), fp1);
    printf("fp1 %s %p %d %d\n", buf, (void*)ret1, ferror(fp1), feof(fp1));

    buf[0] = '\0';
    ret2 = fp2 == NULL ? NULL : fgets(buf, sizeof(buf), fp2);
    printf("fp2 %s %p %d %d\n", buf, (void*)ret2, ferror(fp2), feof(fp2));
    
    if (fp1 != NULL) {
        fclose(fp1);
    }
    if (fp2 != NULL) {
        fclose(fp2);
    }

    return 0;
}
