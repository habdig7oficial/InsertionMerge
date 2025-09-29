#include "stdio.h"
#include "string.h"
#include "ctype.h"

char *str_lower(char *str){
    for ( ; *str; ++str) *str = tolower(*str);
    return str;
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

int insertion_sort(char **arr, int len) {
  int steps = 0;
  for (int i = 1; i < len; i++) {
    char *key = arr[i];
    int j;
    for (j = i - 1; j >= 0 && strcmp(key, arr[j]) < 0; j--) {
      arr[j + 1] = arr[j];
      steps++;
    }
    arr[j + 1] = key;
  }
  return steps;
}
