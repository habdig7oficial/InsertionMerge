#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int merge(char **words, int left, int mid, int right){
    int s1_size = (mid - left + 1);
    int s2_size = (right - mid);

    /* Create copies of the two sides of the vector */
    char **side1 = (char **) malloc(s1_size * sizeof(char *));
    char **side2 = (char **) malloc(s2_size * sizeof(char *));

    /* Copy memory from original to copy */
    memcpy(side1, &words[left], s1_size * sizeof(char *));
    memcpy(side2, &words[mid + 1], s2_size * sizeof(char *));

    int i = 0;
    int j = 0;
    int k = left;

    /* Continue until one of the sides of the array end */
    while(i < s1_size && j < s2_size){
        /* if string1 <= string2 then copy from side1 else copy from side 2 */
        if(strcmp(side1[i], side2[j]) <= 0){
            words[k] = side1[i];
            i++;
        }
        else{
            words[k] = side2[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining side */
    while(i < s1_size){
        words[k] = side1[i];
        i++;
        k++;
    }

    /* Copy the remaining side */
    while(j < s2_size){
        words[k] = side2[j];
        j++;
        k++;
    }

    /* free used memory */
    free(side1);
    free(side2);

    return k - left;
}

int merge_sort(char **words, int left, int right){
    if(left >= right)
        return 1;
    
    int mid_value = left + (right - left) / 2;

    int side1 = merge_sort(words, left, mid_value);
    int side2 = merge_sort(words, mid_value + 1, right);

    int m_size = merge(words, left, mid_value, right);

    return  side1 + side2 + m_size;
}