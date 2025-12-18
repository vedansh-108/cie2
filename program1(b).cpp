// Let the contents of the file F1 be “1234567890abcdefghijxxxxxxxx”.
// This means we want the output to be “abcdefghij”.
// Note: the first character ‘1’ is at 0th position

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main()
{
    int n, f, f1;
    char buff[10];
    f = open("seeking", O_RDWR);
    f1 = lseek(f, 10, SEEK_SET);
    printf("Pointer is at %d position\n", f1);
    read(f, buff, 10);
    write(1, buff, 10);

    return 0;
}