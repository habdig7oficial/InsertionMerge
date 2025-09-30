#include "stdio.h"
#include "string.h"
#include "ctype.h"

char *str_lower(char *str){
    /* Iter and set all chars of string to lowercase */
    for ( ; *str; ++str) *str = tolower(*str);
    return str;
}

void print_vec(char **words, int end){
    /* Iter and Print vector */
    printf("\n[");
    for(int i = 0; i < end; i++){
        printf("%s, ", words[i]);
    }
    printf("]");
}

int insertion_sort(char **arr, int len) {
  int steps = 0;
  for (int i = 1; i < len; i++) {
    char *key = arr[i]; /* Copy key to no be overwrited */
    int j; /* if value >= key then stop */
    for (j = i - 1; j >= 0 && strcmp(key, arr[j]) < 0; j--) {
      arr[j + 1] = arr[j]; /* move all nexts elements fowards until the element arrive in it's position */
      steps++;
    }
    arr[j + 1] = key;
  }
  return steps;
}
