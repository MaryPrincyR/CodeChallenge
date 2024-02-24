/*This C program demonstrates the use of a struct to represent a DVD, which includes fields
for the name, release year, and director of a movie. The program creates an array of 10 DVDs,
and then populates the first 5 with data for specific movies.The names, release years, and
directors for the movies are stored in separate arrays, and the program loops over these
arrays to create each DVD. Memory is dynamically allocated for the name and director fields,
which are character pointers. The strcpy_s function is used to copy the strings from the
arrays into the allocated memory.After each DVD is created, it is added to the DVD collection
array, and its details are printed to the console. The program also includes error checking
for failed memory allocation.In the corrected version of the code, the memory allocated for
the name and director fields is freed at the end of the program, after we're done with the
dvdCollection. This ensures that there are no memory leaks, and the pointers in the
dvdCollection are not pointing to freed memory.*/

//#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* name;
    int year;
    char* director;
}DVD;

int main()
{
    DVD dvdCollection[10];
    char* names[] = { "Avengers", "Incredibles", "Finding Dory", "The Lion King", "Star Wars" };
    int years[] = { 2012, 2004, 2016, 2019, 1977 };
    char* directors[] = { "Joss Whedon", "Brad Bird", "Andrew Stanton", "Jon Favreau", "George Lucas" };

    for (int i = 0; i < 5; i++)
    {
        DVD movie;// Declares a DVD struct to hold the current movie.
        movie.name = malloc(strlen(names[i]) + 1);
        if (movie.name == NULL)
        {
            printf("Memory allocation for %s movie name failed.\n", names[i]);
            return 1;
        }
        strcpy_s(movie.name, strlen(names[i]) + 1, names[i]);
        //strcpy(movie.name, names[i]);

        movie.year = years[i];

        movie.director = malloc(strlen(directors[i]) + 1);
        if (movie.director == NULL)
        {
            printf("Memory allocation for %s director name failed.\n", directors[i]);
            return 1;
        }
        strcpy_s(movie.director, strlen(directors[i]) + 1, directors[i]);
        //strcpy(movie.director, directors[i]);

        dvdCollection[i] = movie;

        printf("Movie name: %s\tRelease year: %d\tDirector name: %s\n", movie.name, movie.year, movie.director);
    }

    // When done with the dvdCollection array, free the memory
    for (int i = 0; i < 5; i++)
    {
        free(dvdCollection[i].name);
        free(dvdCollection[i].director);
    }

    return 0;
}