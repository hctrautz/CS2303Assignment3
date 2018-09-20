/** mystruct.h
 * @author Mike Ciaraldi
 * @author Hunter Trautz
 * Sample structs
*/

// Maximum number of characters in an employee name
#define MAX_NAME (99)

// Struct definition:
struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When employe started with the company.
	char name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee* makeEmployee(int birth, int start, const char *name);
void printEmployee(struct Employee *e);
int generateRandomNumber(int maxNUM);
char * generateRandomString(int max);
struct Employee* makeRandomEmployee();
struct Employee** makeRandomEmployeeArray(int totalEmployees);
struct Employee** shallowCopy(int numberOfEmployees, struct Employee* employees[numberOfEmployees]);
struct Employee** deepCopy(int totalEmployees, struct Employee* employees[totalEmployees]);
void freeEmployees(int totalEmployees, struct Employee* employees[totalEmployees]);
