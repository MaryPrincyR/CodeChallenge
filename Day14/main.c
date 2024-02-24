/*The following program  creates an Array to hold the details of  upto 15 DVDs and also
demonstrates how to write elements to specific locations of the array and how to read from
specific locations.*/

//Header files
#include<stdio.h>
#include<string.h>


//Define a structure for DVD
typedef struct {
	char name[50];
	int releaseYear;
	char director[50];
}DVD;

//Declaring an array to hold DVDs
DVD dvdCollection[15]; //this array can store 15 DVDs



/*--------------------------------------------------------------------------------------------------------*/
//Function to initialize a DVD
/*This block of code defines a function initDVD() that initializes a DVD struct.
* The function takes four arguments: a pointer to a DVD struct (d), a string for the name (name),
* an integer for the release year (releaseYear), and a string for the director (director).
* The strncpy_s() function is used to copy the name and director strings into the DVD struct,
* and the releaseYear is directly assigned.
*-----------------------------------------------------------------------------------------------------------*/

void initDVD(DVD* d, char* name, int releaseYear, char* director) {
	strncpy_s(d->name, sizeof(d->name), name, _TRUNCATE);
	d->releaseYear = releaseYear;
	strncpy_s(d->director, sizeof(d->director), director, _TRUNCATE);
}





/*------------------------------------------------------------------------------------------------------------*/
// Function to print the details of a DVD 
/* This block of code defines a function printDVD() that prints the details of a DVD struct.
 * The function takes one argument: a pointer to a DVD struct (d).
 * The printf() function is used to print the name, director, and releaseYear of the DVD.
 /*------------------------------------------------------------------------------------------------------------*/

void printDVD(DVD* d) {
	printf("Name of movie:%s\t Release year:%d\t Director name:%s\n", d->name, d->releaseYear, d->director);
}




/*-------------------------------------------------------------------------------------------------------------*/
// The main() function, which is the entry point of the program.
 /*-------------------------------------------------------------------------------------------------------------*/
int main() {

	// create a DVD object for The Avengers.
	DVD avengersDVD;
	initDVD(&avengersDVD, "The Avengers", 2012, "Joss Whedon");
	// Put "The Avengers." into index 7.
	dvdCollection[7] = avengersDVD;
	printDVD(&dvdCollection[7]);

	//create a DVD object for The Incredibles.
	DVD incrediblesDVD;
	initDVD(&incrediblesDVD, "The Incredibles", 2004, "Brad Bird");
	// Put "The Incredibles" into index 3.
	dvdCollection[3] = incrediblesDVD;
	printDVD(&dvdCollection[3]);

	// Next,create a DVD object for Finding Dory.
	DVD findingDoryDVD;
	initDVD(&findingDoryDVD, "Finding Dory", 2016, "Andrew Stanton");
	// Put "Finding Dory" into index 9.
	dvdCollection[9] = findingDoryDVD;
	printDVD(&dvdCollection[9]);

	//create a DVD object for The Lion King.
	DVD lionKingDVD;
	initDVD(&lionKingDVD, "The Lion King", 2019, "Jon Favreau");
	// Put "The Lion King" into index 2.
	dvdCollection[2] = lionKingDVD;
	printDVD(&dvdCollection[2]);

	//create a DVD object for Star Wars.
	DVD starWarsDVD;
	initDVD(&starWarsDVD, "Star Wars", 1977, "George Lucas");
	// Put "Starwars" into index 2. Remember, already "The Incredibles"
	// is stored in index 2.So we are actually over-writing it.
	dvdCollection[3] = starWarsDVD;
	printDVD(&dvdCollection[3]);

	//To see that index 3 of the array is actually over-written ,let's print all of it again.
	printDVD(&dvdCollection[7]);
	printDVD(&dvdCollection[3]);//prints "starWars"
	printDVD(&dvdCollection[9]);
	printDVD(&dvdCollection[2]);
	printDVD(&dvdCollection[3]);//prints "starWars"

	return 0;
}

