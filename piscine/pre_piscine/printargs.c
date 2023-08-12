#include <string.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER 256

void printErrno() {
						
	const char * errnoMessage = strerror(errno);
	const size_t errnoLenght = strlen(errnoMessage);
	write(STDERR_FILENO, errnoMessage, errnoLenght);		
}

void print(const char* message, int fd) {
	
	const size_t messageLenght = strlen(message);
	const ssize_t result = write(fd, message, messageLenght); 	
	
	if (result == -1) {
		
		printErrno();		
	}
	else if (result < messageLenght) {
			
		const char* errorMessage = "Not all bytes written!\n";
		const size_t errorLenght = strlen(errorMessage);
		write(STDERR_FILENO, errorMessage, errorLenght);		
	}
}

void concatString(char buffer[BUFFER], const char* newString) {
		
	strcat(buffer, newString);
}

int main(int argc, char* argv[]) {
	
	const size_t maxSize = 32;

	if (argc > 1) {
		
		if (argc > 10) {

			const char* errorMessage = "too many arguments, ten max!\n";			
			print(errorMessage, STDERR_FILENO);

			return 1;
		}

		const size_t bufferSize = (maxSize - 1) * argc + 1;
		char buffer[bufferSize];
		
		for (int i = 1; i < argc; i++) {
			
			if (strlen(argv[i]) > maxSize -1) {
								
				const char* firstPart = "the arg: ";
				const char* secondPart = " is too long, 31 chars max!\n";
				const size_t bufferSize =  strlen(firstPart) + 2 + strlen(secondPart) + 1;
				char buffer[bufferSize];
			        concatString(buffer, firstPart);
				concatString(buffer,argv[i]);
				concatString(buffer, secondPart);	
				print(buffer, STDERR_FILENO);
					
				return 1;
			}

			concatString(buffer, argv[i]);			
		}

		print(buffer, STDOUT_FILENO);
		print("\n", STDOUT_FILENO);
	}

	else {

		const char * errorMessage = "no arguments supplied!\n";
		print(errorMessage, STDERR_FILENO);

		return 1;
	}

	return 0;
}
