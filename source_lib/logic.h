#ifndef UNTITLED1_LOGIC_H
#define UNTITLED1_LOGIC_H

typedef struct {
    char label[32];
    char model[32];
    char purpose[32];
    int number_of_crew;
    float range_of_flight;
} aircraft ;

void change(aircraft *, aircraft *);
void sort(int, int, aircraft *);
void grouping(aircraft *, int);

#endif //UNTITLED1_LOGIC_H
