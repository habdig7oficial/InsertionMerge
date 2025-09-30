#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void merge(char **words, int left, int mid, int right){
}

int merge_sort(char **words, int left, int right){
    if(left >= right)
        return 1;
    
    int mid_value = left + (right - left) / 2;

    int side1 = merge_sort(words, left, mid_value);
    int side2 = merge_sort(words, mid_value + 1, right);

    return side1 + side2;
}