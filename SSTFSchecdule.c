#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int queue[100], visited[100] = {0};
    int head, seek = 0, n;
    int i, j, min_dist, index;
    float avg;

    printf("*** SSTF Disk Scheduling Algorithm ***\n");

    printf("Enter the size of Queue: ");
    scanf("%d", &n);

    printf("Enter the Queue:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    for (i = 0; i < n; i++)
    {
        min_dist = 99999;
        index = -1;

        /* Find closest request */
        for (j = 0; j < n; j++)
        {
            if (!visited[j])
            {
                int dist = abs(head - queue[j]);
                if (dist < min_dist)
                {
                    min_dist = dist;
                    index = j;
                }
            }
        }

        visited[index] = 1;
        seek += min_dist;
        head = queue[index];
    }

    printf("\nTotal Seek Time = %d", seek);
    avg = (float)seek / n;
    printf("\nAverage Seek Time = %.2f\n", avg);

    return 0;
}
