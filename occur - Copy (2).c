#include<stdio.h> 
int main(){ 
    char fileName[100],ch,target; 
    FILE *file; 
    int count=0; 
    printf("Enter file name: "); 
    scanf("%s",fileName); 
    printf("Enter character to search for: "); 
    scanf(" %c",&target); 
    file=fopen(fileName,"r"); 
    if(!file) return printf("Error opening file.\n"),1; 
    while((ch=fgetc(file))!=EOF)  
     if(ch==target)  
           count++; 
    fclose(file); 
    printf("Occurrences of '%c': %d\n",target,count); 
    return 0; 
}
