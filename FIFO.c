#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, k, f, pf = 0, count = 0;
    int rs[25], m[10], n;

    printf("\nEnter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &rs[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    /* Initialize frames */
    for (i = 0; i < f; i++)
        m[i] = -1;

    printf("\nThe Page Replacement Process is:\n");

    for (i = 0; i < n; i++)
    {
        for (k = 0; k < f; k++)
        {
            if (m[k] == rs[i])
                break;
        }

        if (k == f)   /* Page Fault */
        {
            m[count] = rs[i];
            count = (count + 1) % f;
            pf++;
        }

        for (j = 0; j < f; j++)
            printf("\t%d", m[j]);

        if (k == f)
            printf("\tPF No. %d", pf);

        printf("\n");
    }

    printf("\nTotal number of Page Faults using FIFO = %d\n", pf);

    return 0;
}
