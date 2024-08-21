#include <stdio.h>
#include "analytics.h"

int main() {
    unsigned char data[] = {5, 3, 9, 1, 6, 7, 8, 2, 4, 0};
    int size = sizeof(data) / sizeof(data[0]);

    analyze_data(data, size);
    print_data(data, size);

    return 0;
}
