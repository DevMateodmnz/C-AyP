#include <stdio.h>

int main() {
    int N;
    float x, y, y_line;
    int on = 0, above = 0, below = 0;
    printf("Ingrese N: ");
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        printf("Ingrese x y: ");
        scanf("%f %f", &x, &y);
        y_line = (2.0 / 3.0) * x - 2;
        if(y == y_line) on++;
        else if(y > y_line) above++;
        else below++;
    }
    printf("En la recta: %d\nArriba: %d\nAbajo: %d\n", on, above, below);
    return 0;
}
