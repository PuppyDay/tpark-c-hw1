#include "gtest/gtest.h"
extern "C" {
#include "../source_lib/logic.h"
}
TEST(ChangeRecords,test_1)//проверка работы функции перестановки записей
{
    aircraft record1 = {"plane", "plane", "cargo", 100, 555.55},
             record2 = {"airplane", "airplane", "passenger", 200, 666.66};
    aircraft record1_help=record1,
             record2_help=record2;
    change(&record1, &record2);
    ASSERT_STREQ(record1.label, record2_help.label);
    ASSERT_STREQ(record1.model, record2_help.model);
    ASSERT_STREQ(record1.purpose, record2_help.purpose);
    ASSERT_EQ(record1.number_of_crew, record2_help.number_of_crew);
    ASSERT_FLOAT_EQ(record1.range_of_flight, record2_help.range_of_flight);

    ASSERT_STREQ(record2.label, record1_help.label);
    ASSERT_STREQ(record2.model, record1_help.model);
    ASSERT_STREQ(record2.purpose, record1_help.purpose);
    ASSERT_EQ(record2.number_of_crew, record1_help.number_of_crew);
    ASSERT_FLOAT_EQ(record2.range_of_flight, record1_help.range_of_flight);
}
#define size_mass 10
TEST(SortRecors, test_2) //проверка функции сортировки массива записей по возрастанию дальности полета
{
    char const DEF[]="def";
    aircraft mass[size_mass];
    for(int i=0; i<size_mass; i++ ) {
        strcpy(mass[i].label, DEF);
        strcpy(mass[i].model, DEF);
        strcpy(mass[i].purpose, DEF);
        mass[i].number_of_crew = 100;
        mass[i].range_of_flight = 100.5 - i;
    }
    sort(0, size_mass, mass);
    for(int i=0; i<size_mass; i++){
        ASSERT_FLOAT_EQ(mass[i].range_of_flight, 91.5+i);
    }
}

TEST(GupingRecords, test_3) //проверка функции группировки массива записей по названию производителя
{
    char const DEF_LABEL_1[]="label1";
    char const DEF_LABEL_2[]="label2";
    char const DEF_LABEL_3[]="label3";
    char const DEF[]="def";
    int const DEF_NUMBER=100;
    aircraft mass[size_mass];
    for(int i=0; i<size_mass; i++ ) {
        switch (i%3) {
            case 0: strcpy(mass[i].label, DEF_LABEL_1); break;
            case 1: strcpy(mass[i].label, DEF_LABEL_2); break;
            case 2: strcpy(mass[i].label, DEF_LABEL_3); break;
        }
        strcpy(mass[i].model, DEF);
        strcpy(mass[i].model, DEF);
        mass[i].number_of_crew = DEF_NUMBER;
        mass[i].range_of_flight = DEF_NUMBER;
    }
    grouping(mass, size_mass);
    for(int i=0; i<size_mass; i++ ) {
        switch (i) {
            case 0 ... 3: ASSERT_STREQ(mass[i].label, DEF_LABEL_1); break;
            case 4 ... 6: ASSERT_STREQ(mass[i].label, DEF_LABEL_2);break;
            case 7 ... 9: ASSERT_STREQ(mass[i].label, DEF_LABEL_3); break;
        }
    }


}
