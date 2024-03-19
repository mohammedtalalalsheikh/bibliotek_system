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
int buch_zaehler = 0;

struct Student studenten[STUDENTS_MAX];
struct Buch buecher[BUECHER_MAX];


void student_einfuegen(int id, char name[50], int alt)
{
    studenten[student_zaehler].id = id;
    strcpy(studenten[student_zaehler].name, name);
    studenten[student_zaehler].alt = alt;
    student_zaehler++;
}

void alle_studenten_zeigen()
{
    for (int i=0;i<student_zaehler;i++)
    {
        printf("Student: %d %s %d \n", studenten[i].id, studenten[i].name, studenten[i].alt);
    }
}


void buch_einfuegen(int id, char title[50], char autor[50], int price)
{
    buecher[buch_zaehler].id = id;
    strcpy(buecher[buch_zaehler].title, title);
    strcpy(buecher[buch_zaehler].autor, autor);
    buecher[buch_zaehler].price = price;
    buch_zaehler++;

}

void alle_buecher_zeigen()
{
    for (int i=0;i<buch_zaehler;i++)
    {
        printf("Buch: id: %d, Title: %s, Autor: %s, Price: %d \n", buecher[i].id, buecher[i].title, buecher[i].autor, buecher[i].price);
    }
}


int main(){


    student_einfuegen(0, "Ahmad", 20);
    student_einfuegen(1, "Baker", 25);
    student_einfuegen(2, "Suzan", 19);

    buch_einfuegen(0, "Einstein", "Adam", 100);
    buch_einfuegen(1, "See of lions", "Sami", 90);
    buch_einfuegen(2, "Bridge of Fire", "Michel", 120);
    buch_einfuegen(3, "Wolf of the king", "rami", 60);


    alle_studenten_zeigen();
    alle_buecher_zeigen();
    return 0;
}
































