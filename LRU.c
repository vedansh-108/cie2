#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, min;
    int rs[25], m[10], count[10], flag[25];
    int n, f, pf = 0, next = 1;

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &rs[i]);
        flag[i] = 0;
    }

    printf("Enter the number of frames: ");
    scanf("%d", &f);

    for (i = 0; i < f; i++)
    {
        count[i] = 0;
        m[i] = -1;
    }

    printf("\nThe Page Replacement process is:\n");

    for (i = 0; i < n; i++)
    {
        flag[i] = 0;

        /* Check if page is already in frame */
        for (j = 0; j < f; j++)
        {
            if (m[j] == rs[i])
            {
                flag[i] = 1;
                count[j] = next++;
                break;
            }
        }

        /* Page Fault */
        if (flag[i] == 0)
        {
            min = 0;
            for (j = 1; j < f; j++)
            {
                if (count[j] < count[min])
                    min = j;
            }

            m[min] = rs[i];
            count[min] = next++;
            pf++;
        }

        /* Display frames */
        for (j = 0; j < f; j++)
            printf("%d\t", m[j]);

        if (flag[i] == 0)
            printf("PF No. -- %d", pf);

        printf("\n");
    }

    printf("\nTotal number of page faults using LRU = %d\n", pf);

    return 0;
}
