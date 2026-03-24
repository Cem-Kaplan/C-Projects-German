#include <stdio.h>

int option;
FILE *datei;
const char datei_name[] = "datei.txt";

int main() {
    printf("Dateiverwaltung\n");
    while (1) { //1 ist true

        printf("Eine Option wählen\n0 - Datei erstellen\n1 - Datei Beschreiben\n2 - Datei löschen\n");
        scanf("%i", &option);
        printf("Eingabe: %i\n", option);

        switch(option) {
            case 0:
                datei = fopen(datei_name, "w");
                fclose(datei);
                break;
            case 1:
                datei = fopen(datei_name, "w");
                fclose(datei);                
                break;
            case 2:
                remove(datei);
                break;
        }
    }
    return 0;
}