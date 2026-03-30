/* Tic tac toe - Cem Kaplan */
/*

bitte im index format 
das gewünschte feld
eingeben:

zb.: 0 = Feld nr 1

*/

#include "stdio.h"
#include "stdbool.h"
#include "stddef.h"
#include "string.h"

char map[9] = {    
    ' ', ' ', ' ',
    ' ', ' ', ' ',
    ' ', ' ', ' ',
};
int map_laenge = sizeof(map) / sizeof(map[9]);

char current_player = 'X';
bool running = true;

void print_map();
void check_on_map(int nr);
void add_to_map(int nr);

int main() {
    printf("tic-tac-toe geladen\nSpieler X ist zuerst drann\n");
    print_map();
    while (running) {
        int aktuelle_auswahl;
        scanf("%i", &aktuelle_auswahl);
        
        if (aktuelle_auswahl > -1 && aktuelle_auswahl < 10) {
            printf("Input Vorhanden\n");
            check_on_map(aktuelle_auswahl);
            print_map();
        } else {
            printf("%iBitte eine zahl\n", aktuelle_auswahl);
        }
    }
    return 0;
}


void print_map() {

    printf("array länge: %i\n", map_laenge); // sollte 9 sein

    for (int feld_nr = 0; feld_nr < map_laenge; ++feld_nr) {
        printf("|%c", map[feld_nr]);
        switch (feld_nr) {
            case 2:
                printf("|\n");
                break;
            case 5:
                printf("|\n");
                break;
            case 8:
                printf("|\n");
                break;
        }
    }
}

void check_on_map(int nr) {
    if (map[nr] == ' ') {
        printf("gültig");
        add_to_map(nr);
    } else if (map[nr] == 'X' || map[nr] == 'O') {
        printf("ungültig, schon belegt\n");
    }
}

void add_to_map(int nr) {
    switch (current_player) {
        case 'X':
            map[nr] = 'X';
            break;
        case 'O':
            map[nr] = 'O';
            break;
    }
}
