////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////[      FIFO      ]////////////////////////////////////////////////

#include <stdio.h>
#include <conio.h>
void FIFO()
{
    int i, j, k, frames, pf = 0, count = 0, referenceStr[25], m[10], length;
    clrscr();

    printf("\n Enter the length of reference string -- ");
    scanf("%d", &length);

    printf("\n Enter the reference string -- ");
    for (i = 0; i < length; i++)
        scanf("%d", &referenceStr[i]);

    printf("\n Enter no. of frames -- ");
    scanf("%d", &frames);
    for (i = 0; i < frames; i++)
        m[i] = -1;

    printf("\n The Page Replacement Process is -- \n");
    for (i = 0; i < length; i++)
    {
        for (k = 0; k < frames; k++)
        {
            if (m[k] == referenceStr[i])
                break;
        }
        if (k == frames)
        {
            m[count++] = referenceStr[i];
            pf++;
        }
        for (j = 0; j < frames; j++)
            printf("\t%d", m[j]);
        if (k == frames)
            printf("\tPF No. %d", pf);
        printf("\n");
        if (count == frames)
            count = 0;
    }
    printf("\n The number of Page Faults using FIFO are %d", pf);
    getch();
}

//////////////////////////////////////////[         LRU         ]///////////////////////////////////

void LRU()
{
    int i, j, k, min, referenceStr[25], memory[10], count[10], flag[25], length, frames, pf = 0,
                                                                next = 1;
    clrscr();
    printf("Enter the length of reference string -- ");
    scanf("%d", &length);
    printf("Enter the reference string -- ");
    for (i = 0; i < length; i++)
    {
        scanf("%d", &referenceStr[i]);
        flag[i] = 0;
    }
    printf("Enter the number of frames -- ");
    scanf("%d", &frames);
    for (i = 0; i < frames; i++)
    {
        count[i] = 0;
        memory[i] = -1;
    }
    printf("\nThe Page Replacement process is -- \n");
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < frames; j++)
        {
            if (memory[j] == referenceStr[i])
            {
                flag[i] = 1;
                count[j] = next;
                next++;
            }
        }
        if (flag[i] == 0)
        {
            if (i < frames)
            {
                memory[i] = referenceStr[i];
                count[i] = next;
                next++;
            }
            else
            {
                min = 0;
                for (j = 1; j < frames; j++)
                    if (count[min] > count[j])
                        min = j;
                memory[min] = referenceStr[i];
                count[min] = next;
                next++;
            }
            pf++;
        }
        for (j = 0; j < frames; j++)
            printf("%d\t", memory[j]);
        if (flag[i] == 0)
            printf("PF No. -- %d", pf);
        printf("\n");
    }
    printf("\nThe number of page faults using LRU are %d", pf);
    getch();
}

//////////////////////////////////[         Optimal         ]///////////////////////////////////

int Optimal()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], temp[10],
        flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);
    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    printf("Enter page reference string: ");
    for (i = 0; i < no_of_pages; ++i)
    {
        scanf("%d", &pages[i]);
    }
    for (i = 0; i < no_of_frames; ++i)
    {
        frames[i] = -1;
    }
    for (i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;
        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                flag1 = flag2 = 1;
                break;
            }
        }
        if (flag1 == 0)
        {
            for (j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == -1)
                {
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0)
        {
            flag3 = 0;
            for (j = 0; j < no_of_frames; ++j)
            {
                temp[j] = -1;
                for (k = i + 1; k < no_of_pages; ++k)
                {
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }
            for (j = 0; j < no_of_frames; ++j)
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }
            if (flag3 == 0)
            {
                max = temp[0];
                pos = 0;
                for (j = 1; j < no_of_frames; ++j)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }
            frames[pos] = pages[i];
            faults++;
        }
        printf("\n");
        for (j = 0; j < no_of_frames; ++j)
        {
            printf("%d\t", frames[j]);
        }
    }
    printf("\n\nTotal Page Faults = %d", faults);
    return 0;
}
