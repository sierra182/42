#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
      while (**argv) {
        write(1, *argv, 1);
    ++(*argv);
    }

    return 0;
}
