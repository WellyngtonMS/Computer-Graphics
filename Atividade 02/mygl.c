#include "mygl.h"

// Salva as coordenadas e as cores RGBA em uma struct
void saveTPixel(TPixel* aux, int x, int y, float R, float G, float B, float A) {
    aux->x = x;
    aux->y = y;
    aux->colors.R = R;
    aux->colors.G = G;
    aux->colors.B = B;
    aux->colors.A = A;
}

void PutPixel(TPixel aux) {
    int position = 4 * aux.x + 4 * aux.y * IMAGE_WIDTH;
    fb_ptr[position] = aux.colors.R;
    fb_ptr[position + 1] = aux.colors.G;
    fb_ptr[position + 2] = aux.colors.B;
    fb_ptr[position + 3] = aux.colors.A;
}

// Faz a interpolação linear das cores RGBA entre duas structs
void LinearColorInterpolation(TPixel start, TPixel end, TPixel* source) {
    int x = end.x - start.x;
    int y = end.y - start.y;

    int auxX = end.x - source->x;
    int auxY = end.y - source->y;

    int R = -end.colors.R + start.colors.R;
    int G = -end.colors.G + start.colors.G;
    int B = -end.colors.B + start.colors.B;
    int A = -end.colors.A + start.colors.A;

    double hypo = sqrt(pow(auxX, 2) + pow(auxY, 2)) / sqrt(pow(x, 2) + pow(y, 2));

    source->colors.R = end.colors.R + R * hypo;
    source->colors.G = end.colors.G + G * hypo;
    source->colors.B = end.colors.B + B * hypo;
    source->colors.A = end.colors.A + A * hypo;
}

// Função auxiliar que desenha linha em X
void lineX(TPixel start, TPixel end) {
    TPixel aux = start;
    int x = end.x - start.x;
    int y = end.y - start.y;
    int increment_y = 1;
    int d = 2 * y - x;

    if (y < 0) {
        increment_y = -1;
        y = -y;
    }

    while (aux.x <= end.x) {
        LinearColorInterpolation(start, end, &aux);
        PutPixel(aux);
        if (d > 0) {
            d = d - (2 * x);
            aux.y += increment_y;
        }
        d += 2 * y;
        aux.x++;
    }
}

// Função auxiliar que desenha linha em Y
void lineY(TPixel start, TPixel end) {
    TPixel aux = start;
    int x = end.x - start.x;
    int y = end.y - start.y;
    int increment_x = 1;
    int d = 2 * x - y;

    if (x < 0) {
        increment_x = -1;
        x = -x;
    }

    while (aux.y <= end.y) {
        LinearColorInterpolation(start, end, &aux);
        PutPixel(aux);

        if (d > 0) {
            d = d - (2 * y);
            aux.x += increment_x;
        }
        d += 2 * x;
        aux.y++;
    }
}

void DrawLine(TPixel start, TPixel end) {
    int deltaX = abs(end.x - start.x);
    int deltaY = abs(end.y - start.y);

    if (deltaX > deltaY) {
        if (end.x > start.x) {
            lineX(start, end);
        }
        else {
            lineX(end, start);
        }
    }
    else {
        if (end.y > start.y) {
            lineY(start, end);
        }
        else {
            lineY(end, start);
        }
    }
}

void DrawTriangle(TPixel l1, TPixel l2, TPixel l3) {
    DrawLine(l1, l2);
    DrawLine(l2, l3);
    DrawLine(l3, l1);
}

// Definição da função que chamará as funções implementadas
void MyGlDraw(void) {
    TPixel  line1, line2, line3, line4, line5, line6;
    int i;

    //Teste da função PutPixexl
    /*for (i = 1; i < 5; i++) {
        saveTPixel(&line1, (IMAGE_HEIGHT/5)*i, (IMAGE_WIDTH/5)*i, 255, 0, 0, 0);
        saveTPixel(&line2, IMAGE_WIDTH-((IMAGE_WIDTH/5)*i), (IMAGE_HEIGHT/5)*i, 0, 255, 0, 0);
        saveTPixel(&line3, (IMAGE_HEIGHT/5)*i, IMAGE_WIDTH/2, 0, 0, 255, 0);
        PutPixel(line1);
        PutPixel(line2);
        PutPixel(line3);
    }*/

    //Teste da função DrawLine
    /*saveTPixel(&line1, 100, 300, 255, 0, 0, 0);
    saveTPixel(&line2, 200, 150, 0, 0, 255, 0);
    saveTPixel(&line3, 400, 300, 0, 255, 0, 0);
    saveTPixel(&line4, 300, 150, 0, 0, 255, 0);
    saveTPixel(&line5, 150, 450, 255, 0, 0, 0);
    saveTPixel(&line6, 350, 450, 0, 255, 0, 0);
    DrawLine(line1, line2);
    DrawLine(line3, line4);
    DrawLine(line5, line6);*/

    //Teste da função DrawTriangle
    /*saveTPixel(&line1, 100, 400, 255, 0, 0, 0);
    saveTPixel(&line2, 400, 400, 0, 255, 0, 0);
    saveTPixel(&line3, 250, 150, 0, 0, 255, 0);
    DrawTriangle(line1, line2, line3);*/
}
