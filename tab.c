#include<stdio.h> 
int main(){ 
char fileName[100],ch; 
FILE *file,*temp; 
printf("Enter the file name: "); 
scanf("%s",fileName); 
file=fopen(fileName,"r"); 
if(!file) return printf("Error opening file.\n"),1; 
temp=fopen("temp.txt","w"); 
while((ch=fgetc(file))!=EOF){ 
fputc(ch=='\n' ? '\t' : ch,temp); 
} 
fclose(file),fclose(temp); 
remove(fileName),rename("temp.txt",fileName); 
printf("Replaced all newlines with tabs.\n"); 
return 0; 
} 
