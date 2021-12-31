#include <time.h>
#include <stdio.h>

#define MAX_SIZE (64*1024*1024)

int main() {
    clock_t start, end;
    double cpu_time;

    int *arr = (int*)malloc(MAX_SIZE * sizeof(int));

    start = clock();
    for (int i=0; i<MAX_SIZE; ++i) {
        arr[i] *= 3;
    }
    end = clock();
    cpu_time = ((double)(end - start)) /  CLOCKS_PER_SEC;

    printf("cpu time for loop 1 %.6f secs.\n", cpu_time);

    for (int j=8; j<32; j++) {
        start = clock();
        for (int i=0; i<MAX_SIZE; i+=j) {
            arr[i] *= 3;
        }
        end = clock();
        cpu_time = ((double)(end - start)) /  CLOCKS_PER_SEC;
        printf("cpu time for loop 2 %.6f secs.\n", cpu_time);
    }
    return 0;
}