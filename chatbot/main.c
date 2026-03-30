#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <math.h> // Man muss die library beim kompilieren mit -lm hinzufügen, Hä?

//Die Funktionen
void showMenu();
void checkInput();
void showTime();
void print(char input[]);
void calc();

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
    } else if (strcmp(aktueller_input, "Rechner") == 0 || strcmp(aktueller_input, "rechner") == 0) {
        calc();
    } else {
        print("Nichts passendes gefunden");
    }
}

void calc() {
    print("Rechner geladen");
    float input1;
    char symbol;
    float input2;
    float ergebnis;

    scanf("%f", &input1);
    scanf(" %c", &symbol);
    scanf("%f", &input2);

    switch (symbol)
    {
    case '+':
        ergebnis = input1 + input2;
        printf("%f.2 %c %f = %f.2 \n", input1, symbol, input2, ergebnis);
        break;
    case '^':
        ergebnis = pow(input1, input2);
        printf("%f %c %f = %f \n", input1, symbol, input2, ergebnis);
        break;
    
    default:
        printf("Kein Symbol oder Zahl eingegeben");
        break;
    }
}