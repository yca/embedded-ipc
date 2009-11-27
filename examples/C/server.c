#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define BOYUT     27 // shred alan boyutu

main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    /*
     *Shared İd = 1000
     */
    key = 1000;

    /*
     * SharedMemory alanı oluşturuluyor.
     */
    if ((shmid = shmget(key, BOYUT, IPC_CREAT | 0666)) < 0)
    {
        perror("shmget");
        exit(1);
    }

    /*
     * Adress alınmıyor.
     */
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1)
    {
        perror("shmat");
        exit(1);
    }

    /*
     *Shared alanına değer atanıyor
     */
    s = shm;

    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = NULL; // sonunnu NULL yaptı


    exit(0);
}
