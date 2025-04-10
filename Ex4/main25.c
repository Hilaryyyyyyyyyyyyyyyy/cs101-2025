#include <stdio.h>

int print_row(int i, int j) {
    if (j == 1) {
        printf("%d*%d=%2d  ", j, i, j * i);
    } else {
        print_row(i, j - 1);
        printf("%d*%d=%2d  ", j, i, j * i);
    }
    return 0;
}

int multi(int i) {
    if (i == 1) {
        print_row(1, 9);
        printf("\n");
    } else {
        multi(i - 1);
        print_row(i, 9);
        printf("\n");
    }
    return 0;
}

int main() {
    multi(9);
    return 0;
}
