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


struct Kaufen
{
    struct Student *student;
    struct Buch *buch;
};


struct Ausleihn
{
    struct Student *student;
    struct Buch *buch;
};

const int STUDENTS_MAX = 100;
const int BUECHER_MAX = 100;
int student_zaehler = 0;
int buch_zaehler = 0;
int kauf_zaehler = 0;

struct Student studenten[STUDENTS_MAX];
struct Buch buecher[BUECHER_MAX];
struct Kaufen kauf_list[BUECHER_MAX];
struct Ausleihn ausleihn_list[BUECHER_MAX];


void print_buch(struct Buch buch)
{
    printf("Buch: id: %d, Title: %s, Autor: %s, Price: %d \n", buch.id, buch.title, buch.autor, buch.price);
}

void print_student(struct Student student)
{
    printf("Student: id: %d, name: %s, alt: %d \n", student.id, student.name, student.alt);
}


void werte_von_zeigers_null_stellen()
{
    for (int i = 0; i<BUECHER_MAX; i++)
    {
        ausleihn_list[i].student = 0;
        ausleihn_list[i].buch = 0;
    }
}


int ist_buch_verkauft(struct Buch *buch)
{
    for (int i = 0; i<kauf_zaehler;i++)
        if (kauf_list[i].buch == buch)
            return 1;
    return 0;

}


int student_hat_schon_buch_ausgeliehn(struct Student *student)
{
    for (int i=0;i < BUECHER_MAX;i++)
    {
        if (ausleihn_list[i].student == student)
        {
            return 1;
        }
    }
    return 0;
}


int buch_ist_schon_ausgeliehn(struct Buch *buch)
{
    for (int i=0;i < BUECHER_MAX;i++)
    {
        
        if (ausleihn_list[i].buch == buch)
        {
            return 1;
        }
    }
    return 0;
}



void zu_ausleihn(struct Student *student, struct Buch *buch)
{
    
    if (student_hat_schon_buch_ausgeliehn(student))
    {
        printf("Leider diese Student hat schon ein Buch ausgelien. Er darf nicht mehr als ein Buch ausgelien!\n");
        return;
    }
    
    if (buch_ist_schon_ausgeliehn(buch))
    {
        printf("Leider dies Buch ist schon ausgelien!\n");
        return;
    }
    

    for (int i = 0; i < BUECHER_MAX; i++)
    {
        if(ausleihn_list[i].student == 0) // freie Platz
        {
            ausleihn_list[i].student = student;
            ausleihn_list[i].buch = buch;
        }
    }

}


void zeig_was_student_ausgeliehn(struct Student *student)
{
    for (int i = 0; i < BUECHER_MAX ; i++)
    {
        if(ausleihn_list[i].student == student)
        {
            printf("Dies Student %s hat diesen Buch ausgelien:\n", student->name);
            print_buch(*ausleihn_list[i].buch);
            return;
        }
    }
    printf("Dies Student %s hat kein Buch ausgelien\n", student->name);
}

void rueckgibt_was_student_ausgeliehn(struct Student *student)
{

    for (int i = 0; i < BUECHER_MAX ; i++)
    {
        if(ausleihn_list[i].student == student)
        {
            ausleihn_list[i].student = 0;
            ausleihn_list[i].buch = 0;
            printf("Rueckgabe Prozess wurde erfogreich durschgefuehrt\n");
            return;
        }
    }
    printf("Dies Student %s hat kein Buch ausgelien\n", student->name);


}


void fuehre_kaufprozess_aus(struct Student *student, struct Buch *buch)
{
    if (kauf_zaehler >= BUECHER_MAX)
    {
        printf("Leider gibt es kein Buecher mehr zu verkaufen");
        return;
    }
    if(ist_buch_verkauft(buch))
    {
        printf("Leider dies Buch ist schon gekauft! \n");
        return;
    }
    kauf_list[kauf_zaehler].student = student;
    kauf_list[kauf_zaehler].buch = buch;
    printf("Verkauf prozess wird erfogreich durschgefuehrt \n");
    kauf_zaehler++;
}


void zeig_gekaufte_buecher_von_student(struct Student *student)
{
    printf("Dieser Student %s hat folgende Buecher gekauft:\n", student->name);
    for (int i=0; i<kauf_zaehler;i++)
    {

        if (kauf_list[i].student == student)
        {
            print_buch(*kauf_list[i].buch);
        }
    }
}

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

    werte_von_zeigers_null_stellen();


    student_einfuegen(0, "Ahmad", 20);
    student_einfuegen(1, "Baker", 25);
    student_einfuegen(2, "Suzan", 19);

    buch_einfuegen(0, "Einstein", "Adam", 100);
    buch_einfuegen(1, "See of lions", "Sami", 90);
    buch_einfuegen(2, "Bridge of Fire", "Michel", 120);
    buch_einfuegen(3, "Wolf of the king", "rami", 60);
    
    
    fuehre_kaufprozess_aus(&studenten[0], &buecher[2]);
    fuehre_kaufprozess_aus(&studenten[0], &buecher[1]);
    zeig_gekaufte_buecher_von_student(&studenten[0]);
    
    alle_studenten_zeigen();
    alle_buecher_zeigen();  
    printf("\n\nTEST Ausleihn:\n");
    zu_ausleihn(&studenten[0], &buecher[1]);
    zu_ausleihn(&studenten[0], &buecher[1]);
    
    zeig_was_student_ausgeliehn(&studenten[0]);

    rueckgibt_was_student_ausgeliehn(&studenten[0]);

    zeig_was_student_ausgeliehn(&studenten[0]);

    return 0;
}
































