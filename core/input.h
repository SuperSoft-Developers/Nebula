#pragma once

typedef struct {
    int up;
    int down;
    int left;
    int right;

    int a;
    int b;
    int start;
} NebulaInput;

extern NebulaInput nebulaInput;

void input_init();
void input_update();
void input_reset();
