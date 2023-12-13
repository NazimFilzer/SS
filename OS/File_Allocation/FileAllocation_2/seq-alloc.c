
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct files
{
    char name[50];
    int length;
    int startindex;
    int endindex;
} files[50];
int blocks[200];
int delete(char deletefile[], int i)
{
    for (int k = 0; k < i; k++)
    {
        if (strcmp(files[k].name, deletefile) == 0)
        {
            files[k].length = 0;
            for (int j = files[k].startindex; j <= files[k].endindex; j++)
            {
                blocks[j] = -1;
            }
            files[k].startindex = -1;
            files[k].endindex = -1;
            return 1;
        }
    }
    return 0;
}
int allocate(int i, int max)
{
    int space;
    for (int j = 0; j < max; j++)
    {
        space = 1;
        for (int k = j; k < j + files[i].length; k++)
        {
            if (k >= max)
            {
                space = 0;
                return 0;
            }
            if (blocks[k] != -1)
            {
                space = 0;
                break;
            }
        }
        if (space == 1)
        {
            files[i].startindex = j;
            files[i].endindex = j + files[i].length - 1;
            for (int k = j; k <= files[i].endindex; k++)
            {
                blocks[k] = 1;
            }
            return 1;
        }
    }
    return 0;
}
void main()
{
    int max, op, i = 0;
    char deletefile[50];

    printf("Enter the Total number of blocks-:");
    scanf("%d", &max);
    for (int j = 0; j < max; j++)
    {
        blocks[j] = -1;
    }
    printf("Select the operation : 1. Creation 2.Deletion 3. Display 4.Exit");

    while (1)
    {
        scanf("%d", &op);
        getchar();
        switch (op)
        {
        case 1:
            printf("Enter  name and size of file in tewrms of disk blocks");

            gets(files[i].name);

            scanf("%d", &files[i].length);
            int allocation = allocate(i, max);
            if (allocation == 1)
            {
                printf("Successfully allocated");
                i++;
            }
            else
            {
                printf("Failed to allocate");
            }
            break;
        case 2:

            printf("Enter the name of file to be deleted");
            gets(deletefile);
            int status = delete (deletefile, i);
            if (status)
            {
                printf("Deleted file");
            }
            else
            {
                printf("File not found to be deleted");
            }
            break;
        case 3:
            for (int k = 0; k < i; k++)
            {
                if (files[k].length != 0)
                {
                    printf("%s   %d %d  %d   ", files[k].name, files[k].length, files[k].startindex, files[k].endindex);
                }
                else
                {
                    printf("%s is deleted", files[k].name);
                }
            }
            break;
        case 4:
            exit(0);
        }
    }
}
