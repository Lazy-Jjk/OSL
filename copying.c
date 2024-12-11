#include<stdio.h> 
int main(){ 
    char sourceFile[100],destFile[100],ch; 
    FILE *source,*dest; 
    printf("Enter the source file name:"); 
    scanf("%s",sourceFile); 
    printf("Enter the destination file name:"); 
    scanf("%s",destFile); 
    source=fopen(sourceFile,"r"); 
    if(!source){ 
        printf("Error:Could not open source file.\n"); 
        return 1; 
    } 
    dest=fopen(destFile,"w"); 
    if(!dest){ 
        printf("Error:Could not open destination file.\n"); 
        fclose(source); 
        return 1; 
    } 
    while((ch=fgetc(source))!=EOF){ 
        fputc(ch,dest); 
    } 
    printf("File copied successfully!\n"); 
    fclose(source); 
    fclose(dest); 
    return 0; 
} 
