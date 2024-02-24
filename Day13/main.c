/*The following program  creates an Array to hold the details of  upto 15 DVDs.*/

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
/* The initDVD() function is called five times to initialize the first three elements of the dvdCollection array,
 * and the printDVD() function is called five times to print the details of these DVDs.The & operator is used to
 * get the address of each DVD in the dvdCollection array, because the initDVD() and printDVD() functions expect
 * pointers to DVD structs.The strings "AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG","HHHH","IIII" and
 * "JJJJ"are placeholders and should be replaced with actual movie names nand directors.The numbers 2020, 2021,
 * 2022,2023 and 2024 are placeholders and should be replaced with actual release years.The return 0; statement
 * indicates that the program has executed successfully.
 /*-------------------------------------------------------------------------------------------------------------*/
int main() {

	initDVD(&dvdCollection[0], "AAAA", 2020, "BBBB");
	printDVD(&dvdCollection[0]);

	initDVD(&dvdCollection[1], "CCCC", 2021, "DDDD");
	printDVD(&dvdCollection[1]);

	initDVD(&dvdCollection[2], "EEEE", 2022, "FFFF");
	printDVD(&dvdCollection[2]);

	initDVD(&dvdCollection[3], "GGGG", 2023, "HHHH");
	printDVD(&dvdCollection[3]);

	initDVD(&dvdCollection[4], "IIII", 2024, "JJJJ");
	printDVD(&dvdCollection[4]);

	return 0;
}
