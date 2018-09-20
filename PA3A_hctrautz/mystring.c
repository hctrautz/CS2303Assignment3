/** mystring.c
 * @author Mike Ciaraldi
 * @author Hunter Trautz
 * My own versions of some of the C-style string functions
 */

#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"

/** Duplicates a C-style string.
 * @param src Pointer to string to be copied
 * @return Pointer to freshly-allocated string containing a duplicate of src
 *         or null if no memory is available
 */
char* mystrdup1(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen1(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/** Duplicates a C-style string.
 * @param src Pointer to string to be copied
 * @return Pointer to freshly-allocated string containing a duplicate of src
 *         or null if no memory is available
 */
char* mystrdup2(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = mystrlen2(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  strcpy(newstr, src);
  return newstr;
}

/** Returns the length (not including the null terminator character) of a C-style string.
 * @param str Pointer to string whose length is to be found
 * @return an unsigned long indicating the length of the inputed C-style string
 */
size_t mystrlen1(const char *str){
	unsigned long length = 0;
	for(int i = 0; str[i] != '\0'; i++){
		length++;
	}
	return length;
}

/** Returns the length (not including the null terminator character) of a C-style string.
 * @param  str Pointer to string whose length is to be found
 * @return unsigned long indicating the length of the inputed C-style string
 */
size_t mystrlen2(const char *str){
	unsigned long length = 0;
	while (*str){
		length++;
		str++; //move to the next element in the array
	}
	return length;
}

/** Copies a string to the destination of another string in memory
 * @param dest the pointer to the destination array where the string is to be copied
 * @param stc the string to be copied
 * @return the destination array where the string was copied
 */
char *mystrcpy(char *dest, const char *stc) {
	int i;
  //loop through the string as long as the current element is not NULL
	for(i = 0; stc[i] != '\0'; i++){
		dest[i] = stc[i];
	}
	dest[i] = '\0';
	return dest;
}

/** Appends the string pointed to by src to the end of the string pointed to by dest
 * @param dest the pointer to the destination array, which should contain a string, and be large enough to contain the result of appending src to it
 * @param stc the string to be appended, should NOT overlap the destination
 * @return a pointer to the resulting string dest
 */
char *mystrcat(char *dest, const char *src){
	int length = strlen(dest);

  //loop through the string as long as the current element is not NULL
	for(int i = 0; src[i] != '\0'; i++){
		dest[length] = src[i];
		length++;
	}
  //after the loop has finished, set the last character in the string to NULL
	dest[length] = '\0';
	return dest;
}

/** Appends the string pointed to by src to the end of the string pointed to by dest, up to n characters long
 * @param dest the pointer to the destination array, which should contain a string, and be large enough
             to contain the result of appending src to it, which includes the additional null character
 * @param stc  the string to be appended, should NOT overlap the destination
 * @param n    the maximum number of characters to be appended
 * @return a pointer to the resulting string dest
 */
char *mystrncat(char *dest, const char *src, size_t n){
	size_t length = strlen(dest);
	size_t i;

  //loop through the string while the current element is not NULl and the index is < the number
  //of characters that the user specified to be copied
	for (i = 0; i < n && src[i] != '\0' ; i++){
		dest[length + i] = src[i];
	}
  //set the last character in the string to NULL
	dest[length + i] = '\0';
	return dest;

}

/** Copies up to a total of n character from the string pointed to by src, to the string pointed to by dest.
 *  If the length of src is less than n, then the remainder of dest will be filled with NULL
 * @param dest the pointer to the destination array,where the content is to be copied
 * @param src  the string to be copied
 * @param n    the number of characters to be copied from src
 * @return a pointer to the resulting string dest
 */
char *mystrncpy(char *dest, const char *src, size_t n){
	size_t i;

  //loop through the string while the current element is not NULl and the index is < the number
  //of characters that the user specified to be copied
	for (i = 0; i < n && src[i] != '\0'; i++){
		dest[i] = src[i];
	}

	for ( ; i < n; i++){
		dest[i] = '\0';
	}
	return dest;
}

/** Copies up to a total of n characters from the string pointed to by src, and returns a pointer to a new
 *  duplicated version of that string.
 * @param src  pointer to the string that needs to be duplicated
 * @param n    the number of characters to be copied from src
 * @return a pointer to the resulting string dest
 */
char *strndup(const char *src, size_t n){
	size_t length = strnlen(src, n);
	char *temp = (char * ) malloc(length + 1);

	if (temp == NULL){
		return NULL;
	}

	temp[length] = '\0';
	return (char *) memcpy (temp, src, length);
}
