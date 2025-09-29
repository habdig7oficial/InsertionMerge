#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ArrArgs {
    char **arr;
    int len;
};

void merge(char *v1[], int len_left, char *v2[], int len_right, char new_arr[]) {
    int i_left = 0;
    int i_right = 0;
    int i = 0;
    while (i_left < len_left && i_right < len_right) {
        if (strcmp(v1[i_left], v2[i_right]) < 0) {
            new_arr[i] = *v1[i_left];
            i_left++;
        } else {
            new_arr[i] = *v2[i_right];
            i_right++;
        }
        i++;
    }
    while (i_left < len_left) {
        new_arr[i] = *v1[i_left];
        i_left++;
        i++;
    }
    while (i_right < len_right) {
        new_arr[i] = *v2[i_right];
        i_right++;
        i++;
    }
}

void merge_sort(struct ArrArgs *args) {
    if (args->len <= 1)
        return;

    int div = args->len / 2;

    struct ArrArgs args_left = {
        .arr = &args->arr[0],
        .len = div
    };
    struct ArrArgs args_right = {
        .arr = &args->arr[div],
        .len = args->len - div
    };

    // chamada recursiva sem pthread
    merge_sort(&args_left);
    merge_sort(&args_right);

    char *new_arr = malloc(args->len * sizeof(char));
    merge(args_left.arr, args_left.len, args_right.arr, args_right.len, new_arr);

    for (int i = 0; i < args->len; i++) {
        args->arr[i] = &new_arr[i];
    }

    free(new_arr);
}