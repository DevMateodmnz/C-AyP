#include <stdio.h>

int main() {
    long long total_poor = 30LL * 100;
    long long total_rich = (1LL << 30) - 1;
    long long cum_rich = 0, cum_poor = 0;
    int day = 0;
    for (int d = 1; d <= 30; d++) {
        cum_poor += 100;
        cum_rich += (1LL << (d - 1));
        if (cum_rich > cum_poor && day == 0) {
            day = d;
        }
    }
    printf("Cantidad entregada por el pobre: %lld\n", total_poor);
    printf("Cantidad entregada por el rico: %lld\n", total_rich);
    if (day > 0) {
        printf("A partir del dia %d el rico dio mas dinero al pobre\n", day);
    } else {
        printf("El rico nunca dio mas dinero al pobre\n");
    }
    return 0;
}
