#include <stdio.h>
    // TODO: поміняти значення, на які вказують a і b

void swap(int *a, int *b) {
    int tmp = *a;   // взяти значення за адресою a
    *a = *b;        // записати за адресою a значення з адреси b
    *b = tmp;
}

void swap_wrong(int a, int b) {  // отримує копії — оригінали не зміняться
    int tmp = a;
    a = b;
    b = tmp;
}

int main(void) {
    int x = 5, y = 10;
    printf("before: x=%d y=%d\n", x, y);
    swap_wrong(x, y);
    printf("wrong:  x=%d y=%d\n", x, y);
    swap(&x, &y);                 // передаємо адреси
    printf("after:  x=%d y=%d\n", x, y);
    return 0;
}