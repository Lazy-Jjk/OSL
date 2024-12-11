#include<stdio.h> 
#include<string.h> 
int main(){ 
    char fileName[100],line[256],lines[100][256]; 
    FILE *file; 
    int count=0,i,j; 
    printf("Enter the file name: "); 
    scanf("%s",fileName); 
    file=fopen(fileName,"r"); 
    if(!file)return printf("Error opening file.\n"),1; 
    while(fgets(line,sizeof(line),file))strcpy(lines[count++],line); 
    fclose(file); 
    for(i=0;i<count-1;i++) 
        for(j=i+1;j<count;j++) 
            if(strcmp(lines[i],lines[j])>0){ 
                char temp[256]; 
                strcpy(temp,lines[i]); 
                strcpy(lines[i],lines[j]); 
                strcpy(lines[j],temp); 
            } 
    file=fopen(fileName,"w"); 
    for(i=0;i<count;i++)fputs(lines[i],file); 
    fclose(file); 
    printf("File sorted successfully.\n"); 
    return 0; 
} 
