#include<stdio.h> 
#include<string.h> 
int main(){ 
char fileName[100], keyword[100], line[256]; 
FILE *file; 
int found = 0; 
printf("Enter file name: "); 
scanf("%s", fileName); 
printf("Enter keyword: "); 
scanf("%s", keyword); 
f
 ile = fopen(fileName, "r"); 
if (!file) return printf("Error opening file.\n"), 1; 
    while (fgets(line, sizeof(line), file)) { 
        if (strstr(line, keyword)) { 
            found = 1; 
            break; 
        } 
    } 
    fclose(file); 
    printf(found ? "Keyword found.\n" : "Keyword not found.\n"); 
    return 0; 
} 
