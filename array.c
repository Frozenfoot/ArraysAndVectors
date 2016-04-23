#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Wrong number of command line arguments\n");
        return 1;
    }
    FILE *fp = fopen(argv[1] , "a+");
    if(!fp)
    {
        printf("Cannot open file\n");
        return -1;
    }
    int ARRAY_SIZE = atoi(argv[2]);
    long start = clock();
    double arr[ARRAY_SIZE][ARRAY_SIZE];
    for(int i = 0; i < ARRAY_SIZE; i ++)
    {
        for(int j = 0; j < ARRAY_SIZE; j ++)
        {
            arr[i][j] = i;
        }
    }
    long finish = clock();
    fprintf(fp, "%d\t%.2f\n", ARRAY_SIZE,(float)(finish - start) / CLOCKS_PER_SEC * 1000);
    fclose(fp);
    return 0;
}
