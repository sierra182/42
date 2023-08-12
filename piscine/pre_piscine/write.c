#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[]) {

	const char* filePath = "./Bonjour.txt";
	int fd = open(filePath, O_RDWR | O_CREAT, 0700);
 	if (fd == -1) {

                const char* errMessage = strerror(errno);
                write(2, errMessage, strlen(errMessage));

                return 1;
        }

	const char* myText = "Bonjour, tout le monde!\n";
	size_t stringLength = strlen(myText);		
	ssize_t resultFile = write(fd, myText, stringLength);
	if (resultFile == -1) {
		
		const char* errMessage = strerror(errno);
		write(2, errMessage, strlen(errMessage));
		
		return 1;
	}

	if (resultFile != stringLength) {
		
		const char* byteError = "Not all bytes could be writen!";
		write(2, byteError, strlen(byteError));

		return 1;
	}

	return 0;
}
