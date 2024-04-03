#include <stdio.h>
int main()
{
    int processSize[10];
    int numOfProcess, numOfBlock;
    int blockSize[10]; 
    int choice, c[10], d[10], alloc[10], flag[10];
    int i, j;


    printf("\nEnter the no of process:");
    scanf("%d", &numOfProcess);
    printf("\nEnter the no of blocks:");
    scanf("%d", &numOfBlock);
    printf("\nEnter the size of each process:");
    for (i = 0; i < numOfProcess; i++)
    {
        printf("\nProcess %d:", i);
        scanf("%d", &processSize[i]);
    }
    printf("\nEnter the block sizes:");
    for (j = 0; j < numOfBlock; j++)
    {
        printf("\nBlock %d:", j);
        scanf("%d", &blockSize[j]);
        c[j] = blockSize[j];
        d[j] = blockSize[j];
    }
    if (numOfProcess <= numOfBlock)
    {
        printf("\n1.First fit 2.Best fit 3.Worst fit");
        do
        {
            printf("\nEnter your choice:");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\nFirst Fit\n");
                for (i = 0; i < numOfProcess; i++)
                {
                    for (j = 0; j < numOfBlock; j++)
                    {
                        if (processSize[i] <= blockSize[j])
                        {
                            alloc[j] = processSize[i];
                            printf("\n\n Alloc[%d]", alloc[j]);
                            printf("\n\nProcess %d of size %d is allocated in block:%d of size:%d", i, processSize[i], j, blockSize[j]);
                            flag[i] = 0, blockSize[j] = 0;
                            break;
                        }
                        else
                            flag[i] = 1;
                    }
                }
                for (i = 0; i < numOfProcess; i++)
                {
                    if (flag[i] != 0)
                        printf("\n\nProcess %d of size %d is not allocated", i, processSize[i]);
                }
                break;
            case 2:
                printf("\nBest Fit\n");
                for (i = 0; i < numOfBlock; i++)
                {
                    for (j = i + 1; j < numOfBlock; j++)
                    {
                        if (c[i] > c[j])
                        {
                            int temp = c[i];
                            c[i] = c[j];
                            c[j] = temp;
                        }
                    }
                }
                printf("\nAfter sorting block sizes:");
                for (i = 0; i < numOfBlock; i++)
                    printf("\nBlock %d:%d", i, c[i]);
                for (i = 0; i < numOfProcess; i++)
                {
                    for (j = 0; j < numOfBlock; j++)
                    {
                        if (processSize[i] <= c[j])
                        {
                            alloc[j] = processSize[i];
                            printf("\n\nAlloc[%d]", alloc[j]);
                            printf("\n\nProcess %d of size %d is allocated in block %d of size%d", i, processSize[i], j, c[j]);
                            flag[i] = 0, c[j] = 0;
                            break;
                        }
                        else
                            flag[i] = 1;
                    }
                }
                for (i = 0; i < numOfProcess; i++)
                {
                    if (flag[i] != 0)
                        printf("\n\nProcess %d of size %d is not allocated", i, processSize[i]);
                }
                break;
            case 3:
                printf("\nWorst Fit\n");
                for (i = 0; i < numOfBlock; i++)
                {
                    for (j = i + 1; j < numOfBlock; j++)
                    {
                        if (d[i] < d[j])
                        {
                            int temp = d[i];
                            d[i] = d[j];
                            d[j] = temp;
                        }
                    }
                }
                printf("\nAfter sorting block sizes:");
                for (i = 0; i < numOfBlock; i++)
                    printf("\nBlock %d:%d", i, d[i]);
                for (i = 0; i < numOfProcess; i++)
                {
                    for (j = 0; j < numOfBlock; j++)
                    {
                        if (processSize[i] <= d[j])
                        {
                            alloc[j] = processSize[i];
                            printf("\n\nAlloc[%d]", alloc[j]);
                            printf("\n\nProcess %d of size %d is allocated in block %d of size %d", i, processSize[i], j, c[j]);
                            flag[i] = 0,
                            d[j] = 0;
                            break;
                        }
                        else
                            flag[i] = 1;
                    }
                }
                for (i = 0; i < numOfProcess; i++)
                {
                    if (flag[i] != 0)
                        printf("\n\nProcess %d of size %d is not allocated", i, processSize[i]);
                }
                break;
            default:
                printf("Invalid Choice… !");
                break;
            }
        } while (choice <= 3);
    }
}
