#include<stdio.h> 
int main(){ 
    char file1[100], file2[100], outFile[100], ch; 
    FILE *f1, *f2, *out; 
    printf("Enter first file name: "); 
    scanf("%s", file1); 
    printf("Enter second file name: "); 
    scanf("%s", file2); 
    printf("Enter output file name: "); 
    scanf("%s", outFile); 
    f1 = fopen(file1, "r"); 
    f2 = fopen(file2, "r"); 
    out = fopen(outFile, "w"); 
    if (!f1 || !f2 || !out) return printf("Error opening files.\n"), 1; 
    while ((ch = fgetc(f1)) != EOF) fputc(ch, out); 
    while ((ch = fgetc(f2)) != EOF) fputc(ch, out); 
    fclose(f1), fclose(f2), fclose(out); 
    printf("Files merged successfully.\n"); 
    return 0; 
}
