#ifndef MYGL_H
#define MYGL_H

#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "core.h"
#include "frame_buffer.h"


typedef struct color {
    int R, G, B, A;
}TColor;

typedef struct pixel {
    int x;
    int y;
    TColor colors;
}TPixel;

void saveTPixel(TPixel* aux, int x, int y, float R, float G, float B, float A);
void PutPixel(TPixel aux);
void LinearColorInterpolation(TPixel start, TPixel end, TPixel* source);
void lineX(TPixel start, TPixel end);
void lineY(TPixel start, TPixel end);
void DrawLine(TPixel start, TPixel end);
void DrawTriangle(TPixel l1, TPixel l2, TPixel l3);
void MyGlDraw(void);

#endif  // MYGL_H