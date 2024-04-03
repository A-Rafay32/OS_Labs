#include <stdio.h>
void FCFS()
{
    int t[20], n, I, j, tohm[20], tot = 0;
    float avhm;
    clrscr();
    printf("enter the no.of tracks");
    scanf("% d", &n);
    printf("enter the tracks to be traversed");
    for (int i = 2; i < n + 2; i++)
        scanf("% d", &t * i +);
    for (int i = 1; i < n + 1; i++)
    {
        tohm[i] = t[i + 1] - t[i];
        if (tohm[i] < 0)
            tohm[i] = tohm[i] * (-1);
    }
    for (int i = 1; i < n + 1; i++)
        tot += tohm[i];
    avhm = (float)tot / n;
    printf("Tracks traversed\tDifference between tracks\n");
    for (int i = 1; i < n + 1; i++)
        printf("% d\t\t\t % d\n", t * i +, tohm * i +);
    printf("\nAverage header movements:%f", avhm);
    getch();
}

void SCAN()
{
    int tracks[20], difference[20], head, i, j, n, temp, k, atr[20], tot, p,
        sum = 0;
    clrscr();
    printf("enter the no of tracks to be traveresed");
    scanf("%d'", &n);
    printf("enter the position of head");
    scanf("%d", &head);
    tracks[0] = 0;
    tracks[1] = head;
    printf("enter the tracks");
    for (i = 2; i < n + 2; i++)
        scanf("%d", &tracks[i]);

    // sorting {bubble sort}
    for (i = 0; i < n + 2; i++)
    {
        for (j = 0; j < (n + 2) - i - 1; j++)
        {
            if (tracks[j] > tracks[j + 1])
            {
                temp = tracks[j];
                tracks[j] = tracks[j + 1];
                tracks[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n + 2; i++)
        if (tracks[i] == head)
            j = i;
    k = i;
    p = 0;
    while (tracks[j] != 0)
    {
        atr[p] = tracks[j];
        j--;
        p++;
    }
    atr[p] = tracks[j];
    for (p = k + 1; p < n + 2; p++, k++)
        atr[p] = tracks[k + 1];
        
    //calculating sum    
    for (j = 0; j < n + 1; j++)
    {
        if (atr[j] > atr[j + 1])
            difference[j] = atr[j] - atr[j + 1];
        else
            difference[j] = atr[j + 1] - atr[j];
        sum += difference[j];
    }
    printf("\nAverage header movements:%f", (float)sum / n);
    getch();
}

void SSTF()
{
    int RQ[100],
        i, n, TotalHeadMoment = 0, initial, count = 0;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    // logic for sstf disk scheduling /* loop will execute until all process is completed*/
    while (count != n)
    {
        int min = 1000, d, index;
        for (i = 0; i < n; i++)
        {
            d = abs(RQ[i] - initial);
            if (min > d)
            {
                min = d;
                index = i;
            }
        }
        TotalHeadMoment = TotalHeadMoment + min;
        initial = RQ[index];
        // 1000 is for max   // you can use any number
        RQ[index] = 1000;
        count++;
    }
    printf("Total head movement is %d", TotalHeadMoment);
    return 0;
}