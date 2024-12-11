#include<stdio.h> 
#include<string.h> 
int main(){ 
    char fileName[100],line[256]; 
    FILE *file; 
    printf("Enter the file name: "); 
    scanf("%s",fileName); 
    getchar(); 
    file=fopen(fileName,"a"); 
    if(!file) return printf("Error opening file.\n"),1; 
    printf("Enter lines to append (type 'STOP' to end):\n"); 
    while(1){ 
        fgets(line,sizeof(line),stdin); 
        if(strcmp(line,"STOP\n")==0) break; 
        fputs(line,file); 
    } 
    fclose(file); 
    printf("Lines appended successfully.\n"); 
    return 0; 
}
