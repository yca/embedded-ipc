#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define BOYUT     27

main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    /*
     * shared key
     */
    key = 1000;

    /*
     * Böyle bir yer varmı ?
     */
    if ((shmid = shmget(key, BOYUT, 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }

    /*
     * Adresi alınıyor
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
    {
        perror("shmat");
        exit(1);
    }

    /*
     * Memorydedi alan NULL olana kadar okunuyor
     */
    for (s = shm; *s != NULL; s++)
        putchar(*s);
    putchar('\n');


    exit(0);
}
