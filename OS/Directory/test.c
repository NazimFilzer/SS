#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
void listContents();
void changeDirectory();
void goToParentDirectory();
void createFile(bool isDirectory);
void deleteFile(bool isDirectory);

struct Node
{
    char name[128];
    bool isDirectory;
    struct Node *parent;
    struct Node *children[100];
    int itemCount;
} *head, *current;

// Function to list contents in the current directory
void listContents()
{
    if (current->itemCount == 0)
    {
        printf("\nEmpty directory!");
        return;
    }

    for (int i = 0; i < current->itemCount; i++)
    {
        if (current->children[i]->isDirectory)
            printf("\n*%s*  ", current->children[i]->name);
        else
            printf("\n%s  ", current->children[i]->name);
    }
}

// Function to change the current directory
void changeDirectory()
{
    printf("\nEnter Directory Name:");
    char directoryName[128];
    scanf("%s", directoryName);

    for (int i = 0; i < current->itemCount; i++)
    {
        if (!strcmp(current->children[i]->name, directoryName) && current->children[i]->isDirectory == true)
        {
            current = current->children[i];
            return;
        }
    }

    printf("\nDirectory Not Found!");
}

// Function to go to the parent directory
void goToParentDirectory()
{
    if (current->parent == NULL)
    {
        printf("\nYou are at the Root Directory");
        return;
    }

    current = current->parent;
}

// Function to create a new file or directory
void createFile(bool isDirectory)
{
    printf("\nEnter Name:");
    char itemName[128];
    scanf("%s", itemName);

    struct Node *newItem = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newItem->name, itemName);
    newItem->isDirectory = isDirectory;
    newItem->parent = current;

    current->children[current->itemCount] = newItem;
    current->itemCount = (current->itemCount) + 1;
}

// Function to delete a file or directory
void deleteFile(bool isDirectory)
{
    printf("\nEnter Name of File or Directory to Delete:");
    char itemName[128];
    scanf("%s", itemName);

    for (int i = 0; i < current->itemCount; i++)
    {
        if (!strcmp(current->children[i]->name, itemName) && ((isDirectory && current->children[i]->isDirectory == true) || (!isDirectory && current->children[i]->isDirectory == false)))
        {
            int temp = i;
            while (temp < (current->itemCount) - 1)
            {
                current->children[temp] = current->children[temp + 1];
                temp++;
            }
            current->itemCount = (current->itemCount) - 1;
            printf("\nSuccessfully Deleted.");
            return;
        }
    }

    printf("\nNot found");
}

int main()
{
    int choice;

    // Initialization
    head = (struct Node *)malloc(sizeof(struct Node));
    strcpy(head->name, "root");
    head->isDirectory = true;
    head->parent = NULL;
    head->itemCount = 0;
    current = head;

    while (true)
    {
        printf("\nYou are in %s directory.\n*****************************************\n1.Show everything in this Directory\n2.Change Directory\n3.Go to Parent Directory\n4.Create New File\n5.Delete File\n6.Create New Directory\n7.Delete Directory\n8.Exit\nEnter your choice:", current->name);

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            listContents();
            break;
        case 2:
            changeDirectory();
            break;
        case 3:
            goToParentDirectory();
            break;
        case 4:
            createFile(false);
            break;
        case 5:
            deleteFile(false);
            break;
        case 6:
            createFile(true);
            break;
        case 7:
            deleteFile(true);
            break;
        default:
            exit(0);
        }
    }

    return 0;
}
