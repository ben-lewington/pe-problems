#ifndef WINDOW_IMPL
#define WINDOW_IMPL

#include <stdint.h>
#include <stdio.h>

#ifndef WINDOW_VIEW_SIZE
#define WINDOW_VIEW_SIZE 4
#endif

typedef struct {
    uint8_t view[WINDOW_VIEW_SIZE];
} Window;

Window window_new() {
    Window w;
    for (int i = 0; i < WINDOW_VIEW_SIZE; ++i) {
        w.view[i] = 10;
    }
    return w;
}

void window_push(Window *w, uint8_t new) {
    for (int i = 0; i < WINDOW_VIEW_SIZE; ++i) {
        uint8_t *c = &w->view[i];
        if (*c == 10) {
            *c = new;
            return;
        }
    }
    for (int i = 0; i < WINDOW_VIEW_SIZE-1; ++i) {
        w->view[i] = w->view[i + 1];
    }
    w->view[WINDOW_VIEW_SIZE - 1] = new;
}

long window_product(Window w) {
    long product = 1;
    for (int i = 0; i < WINDOW_VIEW_SIZE; ++i) {
        uint8_t *c = &w.view[i];
        if (*c == 10) return product;
        product *= *c;
    }
    return product;
}

void window_print(Window w) {
    printf("Window {\n");
    for (int i = 0; i < WINDOW_VIEW_SIZE; ++i) {
        printf("    %d\n", w.view[i]);
    }
    printf("} // Window\n");
}

#else
#endif // WINDOW_IMPL
