#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 1000


int main()
{
    FILE *fp = fopen("C:\\Games\\StaticArrayTimer.txt", "a+");
    long start = clock();
    static double arr[ARRAY_SIZE][ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i ++)
    {
        for(int j = 0; j < ARRAY_SIZE; j ++)
        {
            arr[i][j] = i;
        }
    }
    long finish = clock();
    printf("%d\t%.2f\n", ARRAY_SIZE,(float)(finish - start) / CLOCKS_PER_SEC * 1000);
    fclose(fp);
    return 0;
}
