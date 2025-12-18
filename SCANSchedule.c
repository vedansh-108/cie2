#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t[20], d[20], atr[20];
    int h, i, j, n, temp, k, p;
    int sum = 0;

    printf("Enter the number of tracks to be traversed: ");
    scanf("%d", &n);

    printf("Enter the initial head position: ");
    scanf("%d", &h);

    /* Add start (0) and head position */
    t[0] = 0;
    t[1] = h;

    printf("Enter the tracks:\n");
    for (i = 2; i < n + 2; i++)
        scanf("%d", &t[i]);

    /* Sort the tracks */
    for (i = 0; i < n + 2; i++)
    {
        for (j = 0; j < n + 1 - i; j++)
        {
            if (t[j] > t[j + 1])
            {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    /* Find head position index */
    for (i = 0; i < n + 2; i++)
    {
        if (t[i] == h)
        {
            j = i;
            break;
        }
    }

    /* SCAN movement (towards 0 first) */
    p = 0;
    for (k = j; k >= 0; k--)
        atr[p++] = t[k];

    for (k = j + 1; k < n + 2; k++)
        atr[p++] = t[k];

    /* Calculate total head movement */
    for (i = 0; i < p - 1; i++)
    {
        d[i] = abs(atr[i] - atr[i + 1]);
        sum += d[i];
    }

    printf("\nTotal head movement = %d", sum);
    printf("\nAverage head movement = %.2f\n", (float)sum / n);

    return 0;
}
