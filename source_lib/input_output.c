#include "input_output.h"
#include "logic.h"
#include <stdio.h>
#include <stdlib.h>

void print(aircraft *my_aircraft, int count){
    printf("information about the %d aircraft:\n", count);
    for(int i=0; i<count; i++){
        printf("%d)  ", i+1);
        printf("label: %s\t", my_aircraft[i].label);
        printf("model: %s\t", my_aircraft[i].model);
        printf("purpose: %s\t", my_aircraft[i].purpose);
        printf("number of crew: %d,\t", my_aircraft[i].number_of_crew);
        printf("range of flight: %.3f\n", my_aircraft[i].range_of_flight);
    }
}

int input_count(){
    char help[10];
    int count;
    puts("Enter the number of aircraft:");
    fgets(help, 4, stdin);

    //проверка на корректность введенных данных
    count = atoi(help);
    while (!count){
        fgets(help, 4, stdin);
        count = atoi(help);
    }
    if (count<0){
        count*=-1;
        puts("I'll count the number module");
    }
    return count;
}

void input_mass(aircraft *my_mass, int count){
    char help[10];
    for(int i = 0; i < count; i++){
        printf("Enter information about the %d aircraft:\n", i+1);
        fputs("Input label: ", stdout);
        fgets(my_mass[i].label, 31, stdin);
        fputs("Input model: ", stdout);
        fgets(my_mass[i].model, 31, stdin);
        fputs("Input purpose: ", stdout);
        fgets(my_mass[i].purpose, 31, stdin);
        fputs("Input number of crew(enter before the correct result): ", stdout);
        fgets(help, 11, stdin);

        //проверка на корректность введенных данных
        my_mass[i].number_of_crew = atoi(help);
        while (!my_mass[i].number_of_crew){
            fgets(help, 11, stdin);
            my_mass[i].number_of_crew = atoi(help);
        }
        if (my_mass[i].number_of_crew<0){
            my_mass[i].number_of_crew*=-1;
            puts("I'll count the number module");
        }

        fputs("Input range of flight(enter before the correct result): ", stdout);
        fgets(help, 11, stdin);

        my_mass[i].range_of_flight = atof(help);
        while (!my_mass[i].range_of_flight){
            fgets(help, 11, stdin);
            my_mass[i].range_of_flight = atof(help);

        }
        if (my_mass[i].range_of_flight<0){
            my_mass[i].range_of_flight*=-1;
            puts("I'll count the number module");
        }

    }
}
