#ifndef UNTITLED1_LOGIC_H
#define UNTITLED1_LOGIC_H

#define size_buffer 32
typedef struct {
    char label[size_buffer];
    char model[size_buffer];
    char purpose[size_buffer];
    int number_of_crew;
    float range_of_flight;
} aircraft ;

void change(aircraft *, aircraft *);
void sort(int, int, aircraft *);
void grouping(aircraft *, int);

#endif //UNTITLED1_LOGIC_H
