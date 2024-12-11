#include<stdio.h> 
int main(){ 
    char fileName[100],ch; 
    FILE *file; 
    int count=0; 
    printf("Enter the file name: "); 
    scanf("%s",fileName); 
    file=fopen(fileName,"r"); 
    if(!file){ 
        printf("Error opening file.\n"); 
        return 1; 
    } 
    while((ch=fgetc(file))!=EOF){ 
        count++; 
    } 
    printf("Number of characters: %d\n",count); 
    fclose(file); 
    return 0; 
} 
