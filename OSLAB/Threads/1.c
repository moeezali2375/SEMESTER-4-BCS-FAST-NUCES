#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
void *PrintHello(void *data)
{
    int my_data = (int)data;
    printf("\nHello from new thread -got %d!\n", my_data);
    pthread_exit(NULL);
}
int main()
{
    int rc;
    pthread_t thread_id;
    int t = 11;
    rc = pthread_create(&thread_id, NULL, PrintHello, (void *)t);
    sleep(5);
    if (rc)
    {
        printf("ERROR: pthread_create failed %d return code from pthread create!\n", rc);
        exit(1);
    }
    printf("Created new thread!: %u... is\n", thread_id);
    pthread_exit(NULL);
}