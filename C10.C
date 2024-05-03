#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>

void doSomeThing(void *arg)
{
    unsigned long i = 0;
    int id = *((int *)arg);
    
    if(id == 0)
    {
        printf("\n First thread processing\n");
    }
    else
    {
        printf("\n Second thread processing\n");
    }
    
    for(i = 0; i < 0xFFFFFFFF; i++);
}

int main(void)
{
    int i;
    int pid[2];
    
    for(i = 0; i < 2; i++)
    {
	pid[i] = spawnl( "doSomeThing", "doSomeThing", (void *)&i, NULL);
        if(pid[i] == -1)
            printf("\ncan't create thread\n");
        else
            printf("\n Thread created successfully\n");
    }
    
    delay(5000);
    return 0;
}
