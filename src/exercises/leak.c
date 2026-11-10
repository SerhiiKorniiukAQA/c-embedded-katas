#include <stdlib.h>
#include <string.h>

int main(void) {
    for (int i = 0; i < 5; i++) {
        char *p = malloc(100);
        if (p == NULL) return 1;
        strcpy(p, "leak");
        free(p);    // без цього рядка — витік 5 × 100 = 500 байт
    }
    return 0;
}