#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int shmid;
    void *shared_memory;

    /* Get shared memory */
    shmid = shmget((key_t)2345, 1024, 0666);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    printf("Key of shared memory is %d\n", shmid);

    /* Attach shared memory */
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void *)-1) {
        perror("shmat failed");
        exit(1);
    }

    printf("Process attached at %p\n", shared_memory);

    /* Read data */
    printf("Data read from shared memory is : %s\n",
           (char *)shared_memory);

    /* Detach shared memory */
    if (shmdt(shared_memory) == -1) {
        perror("shmdt failed");
        exit(1);
    }

    return 0;
}
