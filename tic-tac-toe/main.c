#include "stdio.h"
#include "stdbool.h"
#include "stddef.h"
#include "string.h"

char map[9] = {    
    '.', '.', '.',
    '.', '.', '.',
    '.', '.', '.',
};

int laenge = sizeof(map) / sizeof(map[9]);

void print_map() {

    printf("array länge: %i\n", laenge); // sollte 9 sein

    for (int feld_nr = 0; feld_nr < laenge; ++feld_nr) {
        printf("%c", map[feld_nr]);
        switch (feld_nr) {
            case 2:
                printf("\n");
                break;
            case 5:
                printf("\n");
                break;
            case 8:
                printf("\n");
                break;
        }
    }
}

void check_on_map(int nr) {
    if (!map[nr]) {
        printf("gültig");
    } else {
        printf("ungültig, schon belegt");
    }
}   

int main() {
    printf("tic-tac-toe geladen\n");
    
    bool running = true;

    while (running) {
        int aktuelle_auswahl;
        scanf("%d", &aktuelle_auswahl);
        
        if (!aktuelle_auswahl) {
            printf("Bitte eine zahl\n");
            break;
        } else {
            printf("Input Vorhanden\n");
            print_map();
            check_on_map(1);
        }
    }
    return 0;
}

