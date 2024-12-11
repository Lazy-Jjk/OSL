#include<stdio.h> 
int main(){ 
    char fileName[100],ch; 
    FILE *file,*file1,*file2; 
    int count=0; 
    printf("Enter the file name: "); 
    scanf("%s",fileName); 
    file=fopen(fileName,"r"); 
    if(!file) return printf("Error opening file.\n"),1; 
    file1=fopen("file1.txt","w"); 
    file2=fopen("file2.txt","w"); 
    if(!file1||!file2) return printf("Error creating output files.\n"),1; 
    while((ch=fgetc(file))!=EOF){ 
        if(count%2==0) fputc(ch,file1); 
        else fputc(ch,file2); 
        count++; 
    } 
    fclose(file),fclose(file1),fclose(file2); 
    printf("Contents divided into file1.txt and file2.txt.\n"); 
    return 0; 
} 
