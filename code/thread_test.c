#include <stdio.h>
#include "threads.h"
#include <unistd.h> // for thread.sleep(seconds_to_sleep);

#define true 1
#define false 0
#define SLEEP_TIME 3

int global_var_0 = 0;
int global_var_1 = 0;
int global_var_2 = 0;
int global_var_3 = 0;
int global_var_4 = 0;
int global_var_5 = 0;
int global_var_6 = 0;
int global_var_7 = 0;
int global_var_8 = 0;
int global_var_9 = 0;

void func1();
void func2();
void func3();
void func4();
void func5();

int main()
{
    printf("Creating Queue\n");

    runQ = InitQueue();

    printf("Starting Threads\n");

    start_thread(func1);
    start_thread(func2);
    start_thread(func3);
    start_thread(func4);
    start_thread(func5);

    printf("Start Program\n");
    run();

    printf("Finished\n\n");

    return 0;
}

void func1()
{
    int i = 0;
    while(true)
    {
        printf("Func1 -> i: %d\n", i);
        printf("Func1 -> global_var_0: %d\n", global_var_0);
        printf("Func1 -> global_var_5: %d\n\n", global_var_5);
        i++;
        global_var_0++;
        global_var_5++;
        sleep(SLEEP_TIME); // So we can actually see what's going on step by step
        if(i % 2 == 0)
            yield();
    }
}

void func2()
{
    int j = 0;
    while(true)
    {
        printf("Func2 -> j: %d\n", j);
        printf("Func2 -> global_var_1: %d\n", global_var_1);
        printf("Func2 -> global_var_6: %d\n\n", global_var_6);
        j++;
        global_var_1++;
        global_var_6++;
        sleep(SLEEP_TIME); // So we can actually see what's going on step by step
        if(j % 2 == 0)
            yield();
    }
};

void func3()
{
    int k = 0;
    while(true)
    {
        printf("Func3 -> k: %d\n", k);
        printf("Func3 -> global_var_2: %d\n", global_var_2);
        printf("Func3 -> global_var_7: %d\n\n", global_var_7);
        k++;
        global_var_2++;
        global_var_7++;
        sleep(SLEEP_TIME); // So we can actually see what's going on step by step
        if(k % 2 == 0)
            yield();
    }
};

void func4()
{
    int l = 0;
    while(true)
    {
        printf("Func4 -> l: %d\n", l);
        printf("Func4 -> global_var_3: %d\n", global_var_3);
        printf("Func4 -> global_var_8: %d\n\n", global_var_8);
        l++;
        global_var_3++;
        global_var_8++;
        sleep(SLEEP_TIME); // So we can actually see what's going on step by step
        if(l % 2 == 0)
            yield();
    }
};

void func5()
{
    int m = 0;
    while(true)
    {
        printf("Func5 -> m: %d\n", m);
        printf("Func5 -> global_var_4: %d\n", global_var_4);
        printf("Func5 -> global_var_9: %d\n\n", global_var_9);
        m++;
        global_var_4++;
        global_var_9++;
        sleep(SLEEP_TIME); // So we can actually see what's going on step by step
        if(m % 2 == 0)
            yield();
    }
};
