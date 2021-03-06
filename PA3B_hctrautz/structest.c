#include <stdio.h>
#include "mystruct.h"

int main(int atgc, char *argv[]) {

	printf("Tests for functions makeEmployee and printEmployee with non-random values\n");

	struct Employee *e;
	e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	printEmployee(e);
	printf("\n");

	struct Employee *e2;
	e2 = makeEmployee(1999, 2017, "Hunter Trautz");
	printEmployee(e2);
	printf("\n");

	struct Employee *e3;
	e3 = makeEmployee(1955, 1975, "Bill Gates");
	printEmployee(e3);
	printf("\n");

	printf("Tests for function makeRandomEmployee\n");
	struct Employee *rande1;
	rande1 = makeRandomEmployee();
	printEmployee(rande1);
	printf("\n");

	struct Employee *rande2;
	rande2 = makeRandomEmployee();
	printEmployee(rande2);
	printf("\n");

	struct Employee *rande3;
	rande3 = makeRandomEmployee();
	printEmployee(rande3);
	printf("\n");


	printf("Tests for function makeRandomEmployeeArray\n");

	struct Employee** employeePointerArray1 = makeRandomEmployeeArray(12);

	printf("Index 0\n");
	printf("Pointer: %p\n", employeePointerArray1[0]);
	printEmployee(employeePointerArray1[0]);
	printf("\n");

	printf("Index 1\n");
	printf("Pointer: %p\n", employeePointerArray1[1]);
	printEmployee(employeePointerArray1[1]);
	printf("\n");

	printf("Index 2\n");
	printf("Pointer: %p\n", employeePointerArray1[2]);
	printEmployee(employeePointerArray1[2]);
	printf("\n");

	printf("Tests for function shallowCopy on the previously generated array of random employees\n");
	//sets new array equal to the output of copying employeePointerArray1
	struct Employee** employeePointerArray2 = shallowCopy(10, employeePointerArray1);

	printf("Index 0\n");
	printEmployee(employeePointerArray2[0]);
	printf("Pointer: %p\n", employeePointerArray2[0]);
	printf("\n");

	printf("Index 1\n");
	printEmployee(employeePointerArray2[1]);
	printf("Pointer: %p\n", employeePointerArray2[1]);
	printf("\n");

	printf("Index 2\n");
	printEmployee(employeePointerArray2[2]);
	printf("Pointer: %p\n", employeePointerArray2[2]);
	printf("\n");


	printf("Tests for the function deepCopy\n");

	printf("Randomly generated array of employees to be duplicated by deepCopy\n");
	struct Employee** employeePointerArray3 = makeRandomEmployeeArray(12);

	printf("Index 0\n");
	printf("Pointer: %p\n", employeePointerArray3[0]);
	printEmployee(employeePointerArray3[0]);
	printf("\n");

	printf("Index 1\n");
	printf("Pointer: %p\n", employeePointerArray3[1]);
	printEmployee(employeePointerArray3[1]);
	printf("\n");

	printf("Index 2\n");
	printf("Pointer: %p\n", employeePointerArray3[2]);
	printEmployee(employeePointerArray3[2]);
	printf("\n");

	printf("Array generated by deepCopy\n");
	struct Employee** employeePointerArray4 = deepCopy(12, employeePointerArray3);

	printf("Index 0\n");
	printf("Pointer: %p\n", employeePointerArray4[0]);
	printEmployee(employeePointerArray4[0]);
	printf("\n");

	printf("Index 1\n");
	printf("Pointer: %p\n", employeePointerArray4[1]);
	printEmployee(employeePointerArray4[1]);
	printf("\n");

	printf("Index 2\n");
	printf("Pointer: %p\n", employeePointerArray4[2]);
	printEmployee(employeePointerArray4[2]);
	printf("\n");


	printf("Tests for function freeEmployees\n");
	printf("Freeing employees from employeePointerArray1 from memory..\n");
	freeEmployees(12, employeePointerArray1);
	printf("Sucess.\n");

	return 0;
}
