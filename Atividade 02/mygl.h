#ifndef MYGL_H
#define MYGL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "core.h"

typedef struct color {
    int R, G, B, A;
}TColor;

typedef struct pixel {
    int x;
    int y;
    TColor colors;
}TPixel;

void InitMyGl(void); // Inicializa o frame buffer 
unsigned char* GetFBMemPtr(void); // Retorna o ponteiro do framebuffer buffer
void CloseMyGl(void); // Desaloca a mem�ria do framebuffer
void saveTPixel(TPixel* aux, int x, int y, float R, float G, float B, float A);
void PutPixel(TPixel aux);
void LinearColorInterpolation(TPixel start, TPixel end, TPixel* source);
void lineX(TPixel start, TPixel end);
void lineY(TPixel start, TPixel end);
void DrawLine(TPixel start, TPixel end);
void DrawTriangle(TPixel l1, TPixel l2, TPixel l3);
void MyGlDraw(void);

#endif  // MYGL_H