#include<stdio.h> 
#define MAX_LINES 100 
#define MAX_LEN 256 
int j;
int main(){ 
    char fileName[100],lines[MAX_LINES][MAX_LEN]; 
    FILE *file; 
    int i=0; 
    printf("Enter the file name: "); 
    scanf("%s",fileName); 
    file=fopen(fileName,"r"); 
    if(!file){ 
        printf("Error opening file.\n"); 
        return 1; 
    } 
    while(fgets(lines[i],MAX_LEN,file) && i<MAX_LINES){ 
        i++; 
    } 
    fclose(file); 
    printf("Lines from the file:\n"); 
    for(j=0;j<i;j++){ 
        printf("Line %d: %s",j+1,lines[j]); 
    } 
    return 0; 
} 
