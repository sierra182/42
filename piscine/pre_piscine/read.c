#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUFFER 256

void printErrorMessage() {
	
	char errorPattern[BUFFER] = "there is an error: ";
	const char* errorMessage = strerror(errno);
	strcat(errorPattern, errorMessage);
	write(STDERR_FILENO, errorPattern, strlen(errorPattern));
}

int main(int argc, char* argv[]) {

	const char* file_path = "./Bonjour.txt";
	char buffer[BUFFER];
	
	int fd = open(file_path, O_RDWR);
	if (fd == -1) {
		
		printErrorMessage();
		return 1;
	}

	ssize_t read_result = read(fd, buffer, sizeof(buffer) - 1);
	if (read_result == -1) {
	
		close(fd);
		printErrorMessage();
		return 1;
	} 
	else {
		buffer[read_result] = '\0';
		ssize_t result = write(STDOUT_FILENO, buffer, strlen(buffer));
		if (result == -1) {

			close(fd);
			printErrorMessage();
			return 1;
		}
		else if (result != strlen(buffer)) {
			
			close(fd);

			const char* errorMessage = "Not all bytes could be written!";
			write(STDERR_FILENO, errorMessage, strlen(errorMessage));

			return 1;
		}
	}

	close(fd);
	return 0;
}
