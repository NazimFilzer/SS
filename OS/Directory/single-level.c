#include <stdio.h>
#include <string.h>

void main()
{
    int numFiles = 0, i = 0, choice;
    char dirName[10], fileNames[10][10], fileName[10];

    printf("Enter the directory name: ");
    scanf("%s", dirName);

    do
    {
        printf("Enter the file name to be created: ");
        scanf("%s", fileName);

        // Check if the file already exists
        for (i = 0; i < numFiles; i++)
        {
            if (!strcmp(fileName, fileNames[i]))
                break;
        }

        // If the file doesn't exist, add it to the directory
        if (i == numFiles)
            strcpy(fileNames[numFiles++], fileName);
        else
            printf("File %s already exists.\n", fileName);

        // Ask if the user wants to enter another file
        printf("Do you want to enter another file? (yes - 1 or no - 0): ");
        scanf("%d", &choice);
    } while (choice == 1);

    // Display directory name
    printf("Directory name is: %s\n", dirName);

    // Display file names
    printf("File names are:\n");
    for (i = 0; i < numFiles; i++)
        printf("%s\n", fileNames[i]);
}
