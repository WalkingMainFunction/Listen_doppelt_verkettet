#include <stdio.h>
#include <stdlib.h>
#include "display.h"
#include <windows.h>

typedef struct Person
{
    char vorname[30];
    char nachname[30];
    int alter;

    struct Person *prev;
    struct Person *next;

}Person;

void anlegen(int groesse);

void anlegen(int groesse)
{
    int anz = 0;
    Person *p, *h;
    Person *start = NULL;
    Person *ende = NULL;
    do
    {
        p = (Person *) malloc(sizeof(Person));

        if(p == NULL)
        {
            puts("Kein Speicher vorhanden");
        }
        else
        {

                fflush(stdin);
                puts("Vorname: ");
                gets(p->vorname);
                puts("Nachname: ");
                gets(p->nachname);
                puts("Alter: ");
                scanf("%d", &(p->alter));

                p->next = NULL;
                p->prev = NULL;
                ende = p;

                if(start == NULL)
                {
                    start = p;
                }
                else
                {
                    h = start;

                    while(h->next != NULL)
                    {
                        h = h->next;

                    }
                    h->next = p;
                    p->prev = h;


                }
        }
        anz++;

    }while(anz != groesse);

    p = start;

    puts(" ");
    puts(" ");

    do
    {
        textcolor(YELLOW);
        puts("Vorname: ");
        textcolor(LIGHTCYAN);
        puts(p->vorname);

        textcolor(YELLOW);
        puts("Nachname: ");
        textcolor(LIGHTCYAN);
        puts(p->nachname);

        textcolor(YELLOW);
        puts("Alter: ");
        textcolor(LIGHTCYAN);

        printf("%d", p->alter);

        puts(" ");
        puts(" ");


        p = p->next;
    }while(p != NULL);


    p = ende;

    textcolor(YELLOW);
    puts("rückwärts Ausgabe mit prev pointer: ");

    puts(" ");
    puts(" ");

    do
    {
        textcolor(YELLOW);
        puts("Vorname: ");
        textcolor(LIGHTCYAN);
        puts(p->vorname);

        textcolor(YELLOW);
        puts("Nachname: ");
        textcolor(LIGHTCYAN);
        puts(p->nachname);

        textcolor(YELLOW);
        puts("Alter: ");
        textcolor(LIGHTCYAN);

        printf("%d", p->alter);

        puts(" ");
        puts(" ");


        p = p->prev;
    }while(p != NULL);
}



int main()
{

    console_init();

    int anz = 0;
    puts("Größe der Liste: ");
    scanf("%d", &anz);

    anlegen(anz);

    return 0;
}
