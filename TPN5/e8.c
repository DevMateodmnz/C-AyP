#include <stdio.h>

int main() {
    int N;
    float x, y;
    int origin = 0, ex = 0, ey = 0, q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    printf("Ingrese N: ");
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        printf("Ingrese x y: ");
        scanf("%f %f", &x, &y);
        if(x == 0 && y == 0) origin++;
        else if(y == 0) ex++;
        else if(x == 0) ey++;
        else if(x > 0 && y > 0) q1++;
        else if(x < 0 && y > 0) q2++;
        else if(x < 0 && y < 0) q3++;
        else if(x > 0 && y < 0) q4++;
    }
    printf("Origen: %d\nEje x: %d\nEje y: %d\nQ1: %d\nQ2: %d\nQ3: %d\nQ4: %d\n", origin, ex, ey, q1, q2, q3, q4);
    return 0;
}
