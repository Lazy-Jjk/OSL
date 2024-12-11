 #include<stdio.h> 
int main(){ 
    char fileName[100], ch, target; 
    FILE *file, *temp; 
    printf("Enter file name: "); 
    scanf("%s", fileName); 
    printf("Enter character to replace: "); 
    scanf(" %c", &target); 
    file = fopen(fileName, "r"); 
    if (!file) return printf("Error opening file.\n"), 1; 
    temp = fopen("temp.txt", "w"); 
    if (!temp) return printf("Error creating temporary file.\n"), 1; 
    while ((ch = fgetc(file)) != EOF) { 
        if (ch == target) ch = '*'; 
        fputc(ch, temp); 
    } 
    fclose(file); 
    fclose(temp); 
    remove(fileName); 
    rename("temp.txt", fileName); 
    printf("Character replaced successfully.\n"); 
    return 0; 
} 
