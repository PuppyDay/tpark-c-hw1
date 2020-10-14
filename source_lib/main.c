#include <stdlib.h>
#include "logic.h"
#include "input_output.h"

/* Создать структуру для хранения информации о воздушных судах: марке (названии производителя),
 * модели, назначении (грузовое, пассажирское и т.д.), численности экипажа и дальности полета.
 * Составить с ее использованием программу вывода информации обо всех известных судах с группировкой
 * по названию производителя и сортировкой по возрастанию дальности полета.   */

int main() {
    aircraft *my_mass;
    int count = input_count();
    my_mass=(aircraft *) calloc(count,sizeof(aircraft));
    if (my_mass==NULL) return -1;
    input_mass(my_mass, count);
    grouping(my_mass, count);
    print(my_mass, count);
    free(my_mass);
    return 0;
}
