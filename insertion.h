#include "stdio.h"
#include "string.h"
#include "ctype.h"

void str_lower(char *str){
    for ( ; *str; ++str) *str = tolower(*str);
}

void print_vec(char **words, int end){
    printf("\n[");
    for(int i = 0; i < end; i++){
        printf("%s, ", words[i]);
    }
    printf("]");
}

void push_vector(char **words, int end){
    //printf("i: %d", end);
    for(int i = end - 1; i > 0; i--){
       //printf("i: %s i-1: %s", words[i], words[i - 1]);
        words[i] = words[i - 1];
    }
}

void insertion_sort(char **words, int length){
    print_vec(words, length);
    for(int i = 0; i < length; i++){
        for(int j = 0; j < i; j++){
            
            str_lower(words[i]);
            str_lower(words[j]);
            //printf("%d %s %s %d | ", i, words[i], words[j], strcmp(words[i], words[j]));

            int cmp_num = strcmp(words[i], words[j]);
    
            if(cmp_num <= 0){
                char *aux = words[i];
                push_vector(&words[j], i); // tem que empurrar pra frente
                print_vec(words, length);
                printf("-- i: %d j: %d %s %s\n", i, j, words[i], words[j]);
                words[j] = aux; 
                return;
               // print_vec(words, length);
                break;
            }
        }
        printf("\n----\n");
    }

    

}