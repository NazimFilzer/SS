#include <stdio.h>
#include <math.h>
#define MAX 200
void main()
{
    int n, head, i, j, temp, a[20], current, dist = 0, seekcount = 0, seek_sequence[MAX], index = 0, left, right, direction;
    printf("Enter the number of elements in request array\n");
    scanf("%d", &n);
    printf("Enter the requested array\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the head position\n");
    scanf("%d", &head);
    printf("Enter the direction : 0 for left and 1 for right\n");
    scanf("%d", &direction);

    // sorting
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
    // finding left and right
    for (i = 0; i < n; i++)
        if (a[i] > head)
        {
            right = i;
            left = i - 1;
            break;
        }
    // CSCAN
    if (direction == 0)
    {
        for (i = left; i >= 0; i--)
        {
            current = a[i];
            seek_sequence[index++] = current;
        }
        for (i = n - 1; i >= right; i--)
        {
            current = a[i];
            seek_sequence[index++] = current;
        }
        dist = abs(head - a[0]) + abs(MAX - 1 - a[right]) + MAX - 1;
    }
    else
    {
        for (i = right; i < n; i++)
        {
            current = a[i];
            seek_sequence[index++] = current;
        }
        for (i = 0; i <= left; i++)
        {
            current = a[i];
            seek_sequence[index++] = current;
        }
        dist = abs(MAX - 1 - head) + a[left] + MAX - 1;
    }
    for (i = 0; i < index; i++)
        printf("%d -> ", seek_sequence[i]);
    printf("Total seek count is %d", dist);
}
