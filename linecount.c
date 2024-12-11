#include<stdio.h> 
int main(){ 
    char fileName[100],ch; 
    FILE *file; 
    int lines=0; 
    printf("Enter the file name: "); 
    scanf("%s",fileName); 
    file=fopen(fileName,"r"); 
    if(!file){ 
        printf("Error opening file.\n"); 
        return 1; 
    } 
    while((ch=fgetc(file))!=EOF){ 
        if(ch=='\n'){ 
            lines++; 
        } 
    } 
    printf("Number of lines: %d\n",lines); 
    fclose(file); 
    return 0; 
} 

