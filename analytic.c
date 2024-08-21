#include <stdio.h>
#include <stdlib.h>
#include "analytics.h"

int compare(const void* a, const void* b) {
    return (*(unsigned char*)b - *(unsigned char*)a);
}

void analyze_data(unsigned char* data, int size) {
    if (size == 0) return;

    unsigned char max = data[0];
    unsigned char min = data[0];
    int sum = 0;

    for (int i = 0; i < size; i++) {
        if (data[i] > max) max = data[i];
        if (data[i] < min) min = data[i];
        sum += data[i];
    }

    int mean = sum / size;

    qsort(data, size, sizeof(unsigned char), compare);

    int median;
    if (size % 2 == 0) {
        median = (data[size / 2 - 1] + data[size / 2]) / 2;
    } else {
        median = data[size / 2];
    }

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);
    printf("Mean: %d\n", mean);
    printf("Median: %d\n", median);
}

void print_data(unsigned char* data, int size) {
    printf("Data: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}
