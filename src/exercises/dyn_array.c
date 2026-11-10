    // TODO: capacity = 2, data = malloc(...), size = 0
    // TODO: якщо size == capacity -> capacity *= 2 і realloc
    // потім записати value і size++

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int  size;
    int  capacity;
} dyn_array_t;

void da_init(dyn_array_t *a) {
    a->capacity = 2;
    a->size = 0;
    a->data = malloc(a->capacity * sizeof(int));
    if (a->data == NULL) {          // malloc може не дати пам'ять
        printf("malloc failed\n");
        exit(1);
    }
}

void da_push(dyn_array_t *a, int value) {
    if (a->size == a->capacity) {
        int new_cap = a->capacity * 2;
        int *tmp = realloc(a->data, new_cap * sizeof(int));
        if (tmp == NULL) {          // не перезаписуємо data одразу, щоб не втратити старий блок
            printf("realloc failed\n");
            exit(1);
        }
        a->data = tmp;
        a->capacity = new_cap;
    }
    a->data[a->size] = value;
    a->size++;
}

void da_free(dyn_array_t *a) {
    free(a->data);
    a->data = NULL;                 // щоб випадково не використати звільнену пам'ять
    a->size = 0;
    a->capacity = 0;
}

int main(void) {
    dyn_array_t a;
    da_init(&a);
    for (int i = 1; i <= 10; i++) {
        da_push(&a, i * i);
        printf("push %d -> size=%d capacity=%d\n", i * i, a.size, a.capacity);
    }
    da_free(&a);
    return 0;
}