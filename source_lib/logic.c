#include "logic.h"
#include <memory.h>

void grouping(aircraft *my_aircraft, int count){
    if (my_aircraft==NULL)
        return;
    int counter=1;
    for(int i=0; i<count-1; i++){
        for(int j=i+1; j<count; j++){
            if (strcmp(my_aircraft[i].label, my_aircraft[j].label) == 0){
                change(&my_aircraft[i+counter], &my_aircraft[j]);
                counter++;
            }
        }
        sort(i, counter, my_aircraft);
        i+=counter-1;
        counter=1;
    }
}

void change(aircraft *last_struct, aircraft *new_struct){
    aircraft help_struct;
    help_struct=*new_struct;
    *new_struct=*last_struct;
    *last_struct=help_struct;
}

void sort(int start, int finish, aircraft *my_aircraft){
    if (my_aircraft==NULL)
        return;
    int key=1, i=1;
    while (key!=0){
        key=0;
        for(int j=start; j<start+finish-i; j++){
            if (my_aircraft[j].range_of_flight > my_aircraft[j+1].range_of_flight){
                change(&my_aircraft[j], &my_aircraft[j+1]);
                key=1;
            }
        }
        i++;
    }
}
