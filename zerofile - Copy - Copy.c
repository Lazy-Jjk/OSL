#include<stdio.h> 
int main(){ 
    char fileName[100]; 
    FILE *file; 
    printf("Enter the file name: "); 
    scanf("%s",fileName); 
    file=fopen(fileName,"r"); 
    if(!file){ 
        printf("File does not exist.\n"); 
    }else{ 
        fclose(file); 
        file=fopen(fileName,"w"); 
        fclose(file); 
        printf("File exists. Length set to zero.\n"); 
    } 
    return 0; 
}
