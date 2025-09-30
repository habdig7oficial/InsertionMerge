#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "insertion.h"
#include "merge.h"

char **read_file(char fname[], int *length){
    FILE *file_in = fopen(fname, "r");
    if(file_in == NULL){
        fprintf(stderr, "File can not be open");
        exit(1);
    }
    

    int i = 1;
    for(char c = getc(file_in); c != EOF; c = getc(file_in))
        if(c == '\n')
            i++;

    rewind(file_in);

    char **words = (char **) malloc(i * sizeof(char *));

    char *line = NULL;
    size_t line_len;
    
    i = 0;
    ssize_t read = getline(&line, &line_len,file_in);
    while(read != -1){
        int len = strlen(line);
        if(line[len - 1] == '\n')
            line[len - 1] = '\0';
        words[i] = (char *) malloc(line_len - 1);
        strcpy(words[i], line);
        read = getline(&line, &line_len,file_in);
        i++;
    }

    fclose(file_in);

    *length = i;

    return words;
}

void write_file(char fname[], char **arr, int length){
    FILE *file = fopen(fname, "w");

    if(file == NULL){
        fprintf(stderr, "File can not be open");
        exit(1);
    }

    for(int i = 0; i < length; i++){
        fprintf(file, "%s\n", arr[i]);
    }

}


int main (){
    int length;
    char **words1 = read_file("in.csv", &length);

    char **words2 = (char **) malloc(length * sizeof(char *));
    memcpy(words2, words1, length * sizeof(char *));

   int insertion_steps = insertion_sort(words1, length);

  // print_vec(words1, length);

   printf("\nInsertion took %d", insertion_steps);
   write_file("out1.csv", words1,length);

   int merge_steps = merge_sort(words2, 0, length - 1);
    printf("\nMerge took %d", merge_steps);
    write_file("out2.csv", words2,length);

    free(words1);
    free(words2);

    return 0;
}