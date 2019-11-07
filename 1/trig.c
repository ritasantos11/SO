// gcc -Wall -g -o trig trig.c -lm
// -g para usar o gdb

#include <stdio.h>
#include <math.h>
#define START 0
#define ONE_TURN 360

double cos_table[ONE_TURN];
double sin_table[ONE_TURN];

void build_tables() {
    int i;
    for(i = START; i < ONE_TURN; i++) {
        sin_table[i] = sin(M_PI * i / 180.0);
        cos_table[i] = cos(M_PI * i / 180.0);
    }
}

double sin_degrees(int angle) {
    return sin_table[angle % ONE_TURN];
}

double cos_degrees(int angle) {
    return cos_table[angle % ONE_TURN];
}

int main() {
    build_tables();
    
    printf("sin(20) = %f\n", sin_degrees(20));
    printf("cos(80) = %f\n", cos_degrees(425));
    printf("tan(90) = %f\n", sin_degrees(90) / cos_degrees(90));
    printf("sin(90) = %.20f\n", sin_degrees(90));
    printf("cos(90) = %.20f\n", cos_degrees(90)); // nao é realmente 0
    
    return 0;
}