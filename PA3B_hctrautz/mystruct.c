/** mystruct.c
 * @author Mike Ciaraldi
 * @author Hunter Trautz
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mystruct.h"

/** Allocates an Employee struct and fills in its fields
 * @param birth Year the employee was born.
 * @param start Year the employee started with the company.
 * @param name String containing employee's name
 * @return Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {
	struct Employee *employee = malloc(sizeof(struct Employee)); //allocates memory to the struct
	strcpy(employee->name, name); //initializes the employee's name in the struct
	employee->start_year = start; //initializes the employee's starting year in the struct
	employee->birth_year = birth; // initializes the employee's year of birth in the struct

	return employee;
}

/** Prints the contents of a given employee
 *	@param e Pointer to the employee to print out.
 */
void printEmployee(struct Employee *e) {
	printf("%s\n", e->name); //prints employee name
	printf("Year of Birth: %d\n", e->birth_year); //prints employee year of birth
	printf("Start Year: %d\n", e->start_year); //prints employee starting year
}

/** Generates a random number ranging from 1 to the maximum number that the user inputed.
 * 	@param maxNUM The maximum number that the random number can be
 *	@return a random number from range 1 to maxNUM
 */
int generateRandomNumber(int maxNUM){
	return 1+(rand()%maxNUM);
}

/** Generates a random string ranging in length from 1 character long to
 *  the max length inputed by the user.
 * 	@param maxLength the maximum length of the random string
 *	@return a random string made up of valid characters
 */
char * generateRandomString(int maxLength){
	/* makes an array of characters that contanis the valid characters that
	 can be used in generating the random string */
	char * characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

	//allocates memory for the randomString based off of the user's maxLength
	char * randomString = malloc(maxLength);
	//loops through the randomString array, setting each element to a random element in the characters array
	for(int i=0;i<maxLength;i++){
		randomString[i] = characters[generateRandomNumber(strlen(characters))];
	}
	return randomString;
}

/** Creates a new employee with randomized data for the fields
 *	@return A new employee struct with random fields.
 */
struct Employee* makeRandomEmployee(){
	//generates a random Birthday
	int birth_year = generateRandomNumber(2018);
	//generates a random Starting Year
	int start_year = generateRandomNumber(2018);
	//generates a random Name
	char * name = generateRandomString(12);

	//make and return an employee with the randomly generated information for it's fields
	return makeEmployee(birth_year, start_year, name);
}

/** Creates an array of random employees
 *	@param totalEmployees The number of employees to generate.
 *  @return an array of pointers to random employees
 */
struct Employee** makeRandomEmployeeArray(int totalEmployees){
	//allocates memory to the array of pointer to employees based off of the total amount of employees that needed to be generated
	struct Employee** employeePointerArray = malloc(totalEmployees * sizeof(struct Employee));

	//loops through the array of employees, setting each element to a randomly genrated employee
	for(int i=0;i<totalEmployees;i++){
		employeePointerArray[i] = makeRandomEmployee();
	}
	//return the array of employees
	return employeePointerArray;
}

/** Duplicates an array of employees pointers using shallow copying.
 *	@param totalEmployees total number of employees in the array
 *  @param employees An array of pointers to employees that need to be duplicated.
 *  @return An array of pointers to employees that have the same pointers as the original array
 */
struct Employee** shallowCopy(int totalEmployees, struct Employee* employees[totalEmployees]){
	//allocates memory to the array of pointers to employees
	struct Employee** employeePointerArray = malloc(totalEmployees*sizeof(struct Employee));

	//loops through the array of pointers, duplicating the pointers, but not the fields of the struct
	for(int i=0;i<totalEmployees;i++){
		employeePointerArray[i] = employees[i];
	}
	return employees;
}

/** Duplicates an array of employees pointers using deep copying.
 *	@param totalEmployees total number of employees in the array
 *  @param employees An array of pointers to employees that need to be duplicated.
 *  @return An array of pointers to employees that were physically copied and duplicated
 */
struct Employee** deepCopy(int totalEmployees, struct Employee* employees[totalEmployees]){
	//allocates memory to the array of pointers to employees
	struct Employee** employeePointerArray = malloc(totalEmployees*sizeof(struct Employee));

	//loops through the array of pointers, duplicating each individual value for each field of each employee
	for(int i=0;i<totalEmployees;i++){
		employeePointerArray[i] = makeEmployee(employees[i]->birth_year, employees[i]->start_year, employees[i]->name);
	}
	return employeePointerArray;
}

/** Frees the array of employees from memory
 *	@param totalEmployees Number of employees in the array
 *  @param employees An array of pointers to employees
 */
void freeEmployees(int totalEmployees, struct Employee* employees[totalEmployees]){
	//loops through the array of employees, freeing each individual employee in memory
	for(int i=0;i<totalEmployees;i++){
		free(employees[i]);
	}
}
