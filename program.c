#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main (){
    FILE *file = fopen("in.csv", "r");

    if(file == NULL){
        fprintf(stderr, "File can not be open");
        return 1;
    }
    

    int i = 1;
    for(char c = getc(file); c != EOF; c = getc(file))
        if(c == '\n')
            i++;

    rewind(file);

    char *words[i];

    char *line = NULL;
    size_t line_len;
    
    i = 0;
    ssize_t read = getline(&line, &line_len,file);
    while(read != -1){
        words[i] = (char *) malloc(line_len + 1);
        strcpy(words[i], line);
        read = getline(&line, &line_len,file);
        i++;
    }

    for(int j = 0; j < i; j++)
        printf("%s", words[j]);

    fclose(file);

    return 0;
}