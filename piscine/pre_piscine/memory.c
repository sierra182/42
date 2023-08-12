#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void reverse (char* out, const int lenght) {
	
	int start = 0;
	int end = lenght - 1;
	while (start < end) {
		
		char temp = out[start];
		out[start] = out[end];
		out[end] = temp;
		start++;
		end--;
	}	
}

void itoa(int num, char* out, const int base) {
	
	int i = 0;
	bool isNegative = false;
	
	if (num == 0) {
		
		out[i++] = '0';
		out[i] = '\0';
		return;
	}
	
	if (num < 0 && base == 10) {
		
		isNegative = true;
		num  = -num;
	}
	
	while (num != 0) {

		int rem = num % base;
		out[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	if (isNegative == true) {

		out[i++] = '-';
	}

	out[i] = '\0';

	reverse(out, i);
}

int main(int argc, char* argv[]) {
	
	size_t arraySize = 10;
	int* array = (int*) malloc(sizeof(int) * arraySize);
	
	if (array == NULL) {
	
		write(2, "Memory allocation error!\n", 27);
		return 1;
	}
	
	for (int i = 0; i < arraySize; i++) {

		array[i] = i;    	
	}

	for (int i = 0; i < arraySize; i++) {
		
		char number[12];
		itoa(array[i], number, 10);
		write(1, number, strlen(number));
	}

	write(1, "\n", 1);
	
	int* temp = (int*) realloc(array, sizeof(int) * arraySize * 2);
	
	if (temp == NULL) {
		
		write(2, "Memory reallocation error!\n", 28);
		free(array);
		return 1;
	}

	array = temp;

	for (int i = arraySize; i < arraySize * 2; i++) {

		array[i] = i;    	
	}

	for (int i = 0; i < arraySize * 2; i++) {
		
		char number[12]; 		
		itoa(array[i], number, 10);
		write(1, number, strlen(number));
	}
	write(1, "\n", 1);

	free(array);

return 0;
}
