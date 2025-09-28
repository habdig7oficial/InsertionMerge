#include "stdio.h"
#include "string.h"
#include "ctype.h"

void str_lower(char *str){
    for ( ; *str; ++str) *str = tolower(*str);
}

void pull_vector(char **words, int end){
    printf("--%d--", end);
    char *aux;
    for(int i = 0; i < end; i++){
        aux = words[i + 1];
        words[i + 1] = words[i];
        words[i + 2] = aux;
    }

}

void insertion_sort(char **words, int length){
    for(int i = 0; i < length; i++){
        for(int j = 0; j < i; j++){
            
            str_lower(words[i]);
            str_lower(words[j]);
            printf("%d %s %s %d | ", i, words[i], words[j], strcmp(words[i], words[j]));

            int cmp_num = strcmp(words[i], words[j]);
            
            if(cmp_num <= 0){
                pull_vector(&words[i], i - j); // tem que empurrar pra frente
                break;
            }
        }
        printf("\n----\n");
    }

    

}