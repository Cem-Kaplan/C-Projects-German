#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    srand(time(NULL)); // zufälligen seed durch zeit erstellen. seed ändert sich jede sekunde

    int max_zahl;

    printf("Maximale zahl eingeben, die zufällig erstellt werden soll: ");
    scanf("%i", &max_zahl);

    int zahl = rand() % max_zahl + 1;
    printf("%i\n", zahl);

    return 0;
}