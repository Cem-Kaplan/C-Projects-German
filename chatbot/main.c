#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

//Die Funktionen
void showMenu();
void checkInput();
void showTime();
void print(char input[]);

bool running = true;

//Die Antworten
char hilfe[] = "Folgende commands sind möglich:\nHilfe - zeigt commands an\nZeit - gibt die Zeit an\nPi - gibt die Zahl von Pi zurück";
char PI[] = "3.14159265359";

int main() {
    
    showMenu(); 
    
    while (running) {
        checkInput();
    }

    return 0;
}

void showMenu() {
    showTime();
    print("");
}

// Ich hätte function overloading gemacht aber das geht leider nicht in C
void print(char input[]) {
    printf("%s\n\n", input);
}
//Zeit
void showTime() {
    time_t jetzt_unformatiert = time(NULL);
    char *jetzt = ctime(&jetzt_unformatiert);
    
    printf("%s\n", jetzt);
}

// Diese Funktion überprüft den Input
void checkInput() {
    char aktueller_input[100];
    scanf("%99s", &aktueller_input);
    if (strcmp(aktueller_input, "zeit") == 0 || strcmp(aktueller_input, "Zeit") == 0) {
        showTime();
    } else if (strcmp(aktueller_input, "Hilfe") == 0 || strcmp(aktueller_input, "hilfe") == 0) {
        print(hilfe);
    } else if (strcmp(aktueller_input, "Pi") == 0 || strcmp(aktueller_input, "pi") == 0) {
        print(PI);  
    } else {
        print("Nichts passendes gefunden");
    }
}

