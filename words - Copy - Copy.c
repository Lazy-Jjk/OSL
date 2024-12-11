#include<stdio.h> 
#include<ctype.h> 
int main(){ 
    char filename[100],ch; 
    FILE *file; 
    int wordCount=0,inWord=0; 
    printf("Enter the file name:"); 
    scanf("%s",filename); 
    file=fopen(filename,"r"); 
    if(!file){ 
        printf("Error:Could not open file.\n"); 
        return 1; 
    } 
    while((ch=fgetc(file))!=EOF){ 
        if(isspace(ch)){ 
            inWord=0; 
        }else if(!inWord){ 
            inWord=1; 
            wordCount++; 
        } 
    } 
    printf("Number of words:%d\n",wordCount); 
    fclose(file); 
    return 0; 
} 
3
