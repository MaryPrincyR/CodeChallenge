/*This C program demonstrates the use of structures and dynamic memory allocation.
It defines a `DVD` structure that represents a DVD with fields for the name, release year,
and director.The program then creates an instance of this structure for the movie "The Avengers"
directed by "Joss Whedon" and released in 2012. Memory for the `name` and `director` fields is
dynamically allocated using `malloc`, and the strings are copied into these fields using
`strcpy_s`, a safer version of `strcpy`.The `DVD` instance is then added to a collection
of DVDs, represented as an array of `DVD` structures. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define the DVD struct
typedef struct {
	char* name;
	int year;
	char* director;
}DVD;

void main()
{
	// Create the dvdCollection array to store details of upto 10 DVDs
	DVD dvdCollection[10];

	// Create a DVD object for The Avengers
	DVD avengersDVD;
	avengersDVD.name = malloc(strlen("Avengers") + 1);

	//check the return value of malloc to make sure that memory allocation didn't fail
	if (avengersDVD.name == NULL)
	{
		printf("Memory allocation failed for name\n");
		return 1;
	}
	strcpy_s(avengersDVD.name, strlen("Avengers") + 1, "Avengers");
	//strcpy(avengersDVD.name, "Avengers");
	avengersDVD.year = 2012;
	avengersDVD.director = malloc(strlen("Joss Whedon") + 1);

	//check the return value of malloc to make sure that memory allocation didn't fail
	if (avengersDVD.director == NULL)
	{
		printf("Memory allocation failed for director\n");
		return 1;
	}
	strcpy_s(avengersDVD.director, strlen("Joss Whedon") + 1, "Joss Whedon");
	//strcpy(avengersDVD.director, "Joss Whedon");

	// Put it into the 8th place of the Array.
	dvdCollection[7] = avengersDVD;

	printf("Movie name: %s\tRelease year: %d\tDirector: %s", avengersDVD.name, avengersDVD.year, avengersDVD.director);

	//free the memory
	free(avengersDVD.name);
	free(avengersDVD.director);


	return 0;
}