
#ifndef BUTTON_H
#define BUTTON_H

//definerer structen Button
typedef struct Button Button;

//Definerer funksjonen setLED:
//definerer lyset etter om knapp er presset eller ikke

bool setLED(bool isPressed)

//Definerer funksjonen ifPressed:
//Dersom en knapp har blitt trykket er utverdi True

bool ifPressed(bool isPressed)


#endif