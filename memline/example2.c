#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE (64*1024*1024)

void init_data(int* data_ptr, int size) {
    for (int i=0; i<size; ++i) {
        *data_ptr = i;
    }
}
int main() {
    clock_t start, end;
    double cpu_time;

    int *arr = (int*)malloc(MAX_SIZE * sizeof(int));
    init_data(arr, MAX_SIZE);

    volatile int sink;
    start = clock();
    for (int i=0; i<MAX_SIZE; ++i) {
        sink = arr[i];
    }
    end = clock();
    cpu_time = ((double)(end - start)) /  CLOCKS_PER_SEC * 1000;

    printf("cpu time for loop 1 %.6f secs.\n", cpu_time);

    for (int j=1; j<=1024; j*=2) {
        int num = MAX_SIZE / j; 
        start = clock();
        for (int i=0; i<MAX_SIZE; i+=j) {
            arr[i]*=3;
        }
        end = clock();
        cpu_time = ((double)(end - start)) /  CLOCKS_PER_SEC * 1000;
        printf("cpu time for loop 2 - stride-%d %.6f secs.\n", j, cpu_time);
    }
    free(arr);
    return 0;
}