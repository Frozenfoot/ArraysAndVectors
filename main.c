#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ARRAY_SIZE 17000


int main()
{
    FILE *fp = fopen("C:\\Games\\DynamicArrayTimer.txt", "a+");
    long start = clock();
    double **table = malloc(ARRAY_SIZE * sizeof(double*));
    if (!table)
    {
        printf("Memory error!\n");
        return -1;
    }
    for(int i = 0; i < ARRAY_SIZE; i ++)
    {
        table[i] = malloc(ARRAY_SIZE * sizeof(double));
        if(!table[i])
        {
            printf("Memory error 2\n");
            while(i--)
                free(table[i]);
            free(table);
            return -1;
        }
    }
    for(int i = 0; i < ARRAY_SIZE; i ++)
    {
        for (int j = 0; j < ARRAY_SIZE; j ++)
            table[i][j] = i;
    }
    long finish = clock();
    fprintf(fp, "%d\t%.2f\n", ARRAY_SIZE,(float)(finish - start) / CLOCKS_PER_SEC * 1000);
    for(int i = 0; i < ARRAY_SIZE; i ++)
        free(table[i]);
    free (table);
    fclose(fp);
    return 0;
}
