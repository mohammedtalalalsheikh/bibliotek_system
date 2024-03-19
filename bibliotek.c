#include <stdio.h>
#include <stdlib.h>
#include <string.h>






// meine erste commit Baker
struct Student 
{
    int id;
    char name[50];
    int alt;
};

struct Buch
{
    int id;
    char title[50];
    char autor[50];
    int price;

};


const int STUDENTS_MAX = 100;
const int BUECHER_MAX = 100;
int student_zaehler = 0;

struct Student studenten[STUDENTS_MAX];
struct Buch buecher[BUECHER_MAX];


void student_einfuegen(int id, char name[50], int alt){
    studenten[student_zaehler].id = id;
    strcpy(studenten[student_zaehler].name, name);
    studenten[student_zaehler].alt = alt;
    student_zaehler++;
}

void alle_studenten_zeigen()
{
    for (int i=0;i<student_zaehler;i++){
        printf("Student: %d %s %d \n", studenten[i].id, studenten[i].name, studenten[i].alt);
    }
}



int main(){


    student_einfuegen(0, "Ahmad", 20);
    student_einfuegen(1, "Baker", 25);
    student_einfuegen(2, "Suzan", 19);

    alle_studenten_zeigen();
    return 0;
}
































