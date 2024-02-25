/*This code defines a Person structure with name and age fields.
It creates an array of Person structures, fills it with data using a function,
and then uses another function to print the details of each person.*/

#include <stdio.h>

#define MAX_LENGTH 100

/*The typedef keyword is used to create an alias (Person) for the structure type.*/
typedef struct
{
    char name[MAX_LENGTH];
    int age;
} Person;

/*The copyString function copies a string from the source
to the destination using a loop. This function copies the names
“Hannah” and “Sarrah” into the name field of the Person structures.
*/
void copyString(char* destination, const char* source)
{
    while (*source)
    {
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

/*The printPersonDetails function takes a pointer to a Person structure as an argument.*/
void printPersonDetails(Person* person)
{
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
}

int main()
{
    Person people[2];

    copyString(people[0].name, "Hannah");
    people[0].age = 6;

    copyString(people[1].name, "Sarrah");
    people[1].age = 3;

    for (int i = 0; i < 2; i++)
    {
        printPersonDetails(&people[i]);
    }

    return 0;
}