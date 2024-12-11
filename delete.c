#include<stdio.h> 
#include<string.h> 
int main(){ 
    char fileName[100], word[50], line[256]; 
    FILE *file, *temp; 
    printf("Enter file name and word to delete: "); 
    scanf("%s %s", fileName, word); 
    file = fopen(fileName, "r"); 
    if (!file) return printf("Error opening file.\n"), 1; 
    temp = fopen("temp.txt", "w"); 
    while (fgets(line, sizeof(line), file)) { 
        char *pos; 
        while ((pos = strstr(line, word))) memmove(pos, pos + strlen(word), strlen(pos + strlen(word)) + 1); 
        fputs(line, temp); 
    } 
    fclose(file), fclose(temp); 
    remove(fileName), rename("temp.txt", fileName); 
    printf("Word deleted.\n"); 
    return 0; 
} 
