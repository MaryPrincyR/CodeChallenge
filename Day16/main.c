/*This code creates five DVD objects for storing the details of five movies and writes it to an array and then reads from it.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char* name;
	int year;
	char* director;
}DVD;

void main()
{
	//declare an array to store the DVDs
	DVD dvdCollection[10];

	//Create a DVD object for avengers
	DVD avengersDVD;

	//Allocate memory to store the string "Avengers" plus 1 for the null terminator
	avengersDVD.name = malloc(strlen("Avengers") + 1);

	//check whether memory allocation failed
	if (avengersDVD.name == NULL)
	{
		printf("Memory allocation for Avengers movie name failed.\n");
		return 1;
	}

	//copy the string "Avengers" to name field of avengersDVD
	strcpy_s(avengersDVD.name, strlen("Avengers") + 1, "Avengers");

	//store the release year to year field of avengersDVD
	avengersDVD.year = 2012;

	//allocate memory for the string 'Joss Whedon' plus 1 for the null terminator 
	avengersDVD.director = malloc(strlen("Joss Whedon") + 1);

	// check whether memory allocation failed
	if (avengersDVD.director == NULL)
	{
		printf("Memory allocation for Avengers director name failed.\n");
		return 1;
	}

	//copy the string "Joss Whedon" to director field of avengersDVD
	strcpy_s(avengersDVD.director, strlen("Joss Whedon") + 1, "Joss Whedon");

	//store avengersDVD to index0 of dvdCollection array
	dvdCollection[0] = avengersDVD;

	printf("Movie name: %s\tRelease year: %d\tDirector name: %s\n", avengersDVD.name, avengersDVD.year, avengersDVD.director);

	//free the memory allocated for name field and director field of avengersDVD
	free(avengersDVD.name);
	free(avengersDVD.director);


	//Create a DVD object for Incredibles
	DVD incrediblesDVD;

	//allocate memory for the string "Incredibles" plus 1 for the null terminator
	incrediblesDVD.name = malloc(strlen("Incredibles") + 1);
	//check whether memory allocation failed
	if (incrediblesDVD.name == NULL)
	{
		printf("Memory allocation for name field of incredibles DVD failed.\n");
		return 1;
	}
	//copy "Incredibles" to name field of the incrediblesDVD
	strcpy_s(incrediblesDVD.name, strlen("Incredibles") + 1, "Incredibles");

	//store 2004 to the year field of incrediblesDVD
	incrediblesDVD.year = 2004;

	//allocate memory for the string "Brad Bird" plus 1 for the null terminator
	incrediblesDVD.director = malloc(strlen("Brad Bird") + 1);
	//check whether memory allocation failed
	if (incrediblesDVD.director == NULL)
	{
		printf("Memory allocation for director field of incredibles DVD failed.\n");
		return 1;
	}
	//copy "Brad Bird" to director field of the incrediblesDVD
	strcpy_s(incrediblesDVD.director, strlen("Brad Bird") + 1, "Brad Bird");

	//store incrediblesDVD to index0 of dvdCollection array
	dvdCollection[1] = incrediblesDVD;

	printf("Movie name: %s\tRelease year: %d\tDirector name: %s\n", incrediblesDVD.name, incrediblesDVD.year, incrediblesDVD.director);

	//free the memory allocated for name field and director field of incrediblesDVD
	free(incrediblesDVD.name);
	free(incrediblesDVD.director);


	//Create a DVD object for FindingDory
	DVD findingDoryDVD;

	//allocate memory for the string "Finding Dory" plus 1 for the null terminator
	findingDoryDVD.name = malloc(strlen("Finding Dory") + 1);
	//check whether memory allocation failed
	if (findingDoryDVD.name == NULL)
	{
		printf("Memory allocation for the name field of Finding Dory DVD failed\n");
		return 1;
	}
	//copy "Finding Dory" to name field of the findingDoryDVD
	strcpy_s(findingDoryDVD.name, strlen("Finding Dory") + 1, "Finding Dory");

	//store 2016 to the year field of findingDoryDVD
	findingDoryDVD.year = 2016;

	//allocate memory for the string "Andrew Stanton" plus 1 for the null terminator
	findingDoryDVD.director = malloc(strlen("Andrew Stanton") + 1);
	//check whether memory allocation failed
	if (findingDoryDVD.director == NULL)
	{
		printf("Memory allocation for the director field of Finding Dory DVD failed\n");
		return 1;
	}
	//copy "Andrew Stanton" to director field of the findingDoryDVD
	strcpy_s(findingDoryDVD.director, strlen("Andrew Stanton") + 1, "Andrew Stanton");

	//store findingDory DVD to index 2 of dvdCollection array
	dvdCollection[2] = findingDoryDVD;

	printf("Movie name: %s\tRelease year: %d\tDirector name: %s\n", findingDoryDVD.name, findingDoryDVD.year, findingDoryDVD.director);

	//free the memory
	free(findingDoryDVD.name);
	free(findingDoryDVD.director);


	//Create a DVD object for The Lion KIng
	DVD lionKingDVD;

	lionKingDVD.name = malloc(strlen("The Lion King") + 1);
	if (lionKingDVD.name == NULL)
	{
		printf("Memory allocation for the name field of The Lion King DVD failed\n");
		return 1;
	}
	strcpy_s(lionKingDVD.name, strlen("The Lion King") + 1, "The Lion King");

	lionKingDVD.year = 2019;

	lionKingDVD.director = malloc(strlen("Jon Favreau") + 1);
	if (lionKingDVD.director == NULL)
	{
		printf("Memory allocation for the director field of The Lion King DVD failed\n");
		return 1;
	}
	strcpy_s(lionKingDVD.director, strlen("Jon Favreau") + 1, "Jon Favreau");

	dvdCollection[2] = lionKingDVD;

	printf("Movie name: %s\tRelease year: %d\tDirector name: %s\n", lionKingDVD.name, lionKingDVD.year, lionKingDVD.director);

	free(lionKingDVD.name);
	free(lionKingDVD.director);



	//Create a DVD object for Star Wars
	DVD starWarsDVD;

	starWarsDVD.name = malloc(strlen("Star Wars") + 1);
	if (starWarsDVD.name == NULL)
	{
		printf("Memory allocation for the name field of Star Wars DVD failed\n");
		return 1;
	}
	strcpy_s(starWarsDVD.name, strlen("Star Wars") + 1, "Star Wars");

	starWarsDVD.year = 1977;

	starWarsDVD.director = malloc(strlen("George Lucas") + 1);
	if (starWarsDVD.director == NULL)
	{
		printf("Memory allocation for the director field of Star Wars DVD failed\n");
		return 1;
	}
	strcpy_s(starWarsDVD.director, strlen("George Lucas") + 1, "George Lucas");

	dvdCollection[9] = starWarsDVD;

	printf("Movie name: %s\tRelease year: %d\tDirector name: %s\n", starWarsDVD.name, starWarsDVD.year, starWarsDVD.director);

	free(starWarsDVD.name);
	free(starWarsDVD.director);

	return 0;
}
