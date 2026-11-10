    // TODO: копіювати src у dst до '\0' включно
    // TODO: порахувати символи до '\0'
#include <stdio.h>

void my_strcpy(char *dst, const char *src) {
    while (*src != '\0') {   // поки не кінець рядка
        *dst = *src;         // скопіювати символ
        dst++;               // зсунути обидва вказівники
        src++;
    }
    *dst = '\0';             // обов'язково завершити рядок нулем
}

int my_strlen(const char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int main(void) {
    char buf[32];
    my_strcpy(buf, "Hello, embedded");
    printf("%s (len=%d)\n", buf, my_strlen(buf));
    return 0;
}
