#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {

	if (argc != 3) {
		
		char* errorMessage = "Two arguments needed!\n";
		write(STDERR_FILENO, errorMessage, strlen(errorMessage));
		return 1;
	}

	int srcFile = open(argv[1], O_RDONLY);

	if (srcFile == -1) {
		
		char* errorMessage = "there was an error with the source file!";
		write(STDERR_FILENO, errorMessage, strlen(errorMessage));
		return 1;
	}

	int destFile = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (destFile == -1) {
		
		char* errorMessage = "there was an error with the dest file!";
		write(STDERR_FILENO, errorMessage, strlen(errorMessage));
		close(srcFile);
		return 1;
	}

	char buffer[4096];
	ssize_t readResult, writeResult;

	while((readResult = read(srcFile, buffer, sizeof(buffer))) > 0) { // taille buffer et sizeof ?

		writeResult = write(destFile, buffer, readResult);

		if (writeResult != readResult) {
			
			char* errorMessage = "there was an error with write on destfile...";
			write(STDERR_FILENO, errorMessage, strlen(errorMessage));
			close(srcFile);
			close(destFile);
			return 1;
		}
	}

	if (readResult == -1) {
		
		char* errorMessage = "there was an error with read on sourcefile...";
		write(STDERR_FILENO, errorMessage, strlen(errorMessage));
		close(srcFile);
		close(destFile);
	}

	close(srcFile);
	close(destFile);
	return 0;
}
