
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Define a structure for representing a file
struct File
{
    char name[MAX_NAME_LENGTH];
    int size;
};

// Define a structure for representing a directory
struct Directory
{
    char name[MAX_NAME_LENGTH];
    struct File *files;
    int fileCount;
    struct Directory *subDirectories;
    int subDirectoryCount;
};

// Function to create a file
struct File createFile(const char *name, int size)
{
    struct File newFile;
    strcpy(newFile.name, name);
    newFile.size = size;
    return newFile;
}

// Function to create a directory
struct Directory createDirectory(const char *name)
{
    struct Directory newDirectory;
    strcpy(newDirectory.name, name);
    newDirectory.files = NULL;
    newDirectory.fileCount = 0;
    newDirectory.subDirectories = NULL;
    newDirectory.subDirectoryCount = 0;
    return newDirectory;
}

// Function to add a file to a directory
void addFileToDirectory(struct File file, struct Directory *directory)
{
    directory->fileCount++;
    directory->files = (struct File *)realloc(directory->files, directory->fileCount * sizeof(struct File));
    directory->files[directory->fileCount - 1] = file;
}

// Function to create a subdirectory in a directory
void addSubDirectory(struct Directory subDirectory, struct Directory *parentDirectory)
{
    parentDirectory->subDirectoryCount++;
    parentDirectory->subDirectories = (struct Directory *)realloc(parentDirectory->subDirectories, parentDirectory->subDirectoryCount * sizeof(struct Directory));
    parentDirectory->subDirectories[parentDirectory->subDirectoryCount - 1] = subDirectory;
}

// Function to list the contents of a directory
void listDirectoryContents(struct Directory directory)
{
    printf("Contents of Directory '%s':\n", directory.name);
    for (int i = 0; i < directory.fileCount; i++)
    {
        printf("File: %s, Size: %d bytes\n", directory.files[i].name, directory.files[i].size);
    }
    for (int i = 0; i < directory.subDirectoryCount; i++)
    {
        printf("Subdirectory: %s\n", directory.subDirectories[i].name);
    }
}

// Function to delete a file from a directory
void deleteFileFromDirectory(const char *fileName, struct Directory *directory)
{
    for (int i = 0; i < directory->fileCount; i++)
    {
        if (strcmp(directory->files[i].name, fileName) == 0)
        {
            // Found the file, remove it
            for (int j = i; j < directory->fileCount - 1; j++)
            {
                directory->files[j] = directory->files[j + 1];
            }
            directory->fileCount--;
            directory->files = (struct File *)realloc(directory->files, directory->fileCount * sizeof(struct File));
            printf("File '%s' deleted from directory '%s'\n", fileName, directory->name);
            return;
        }
    }
    printf("File '%s' not found in directory '%s'\n", fileName, directory->name);
}

// Function to delete a subdirectory from a directory
void deleteSubDirectory(const char *subDirName, struct Directory *parentDirectory)
{
    for (int i = 0; i < parentDirectory->subDirectoryCount; i++)
    {
        if (strcmp(parentDirectory->subDirectories[i].name, subDirName) == 0)
        {
            // Found the subdirectory, remove it
            for (int j = i; j < parentDirectory->subDirectoryCount - 1; j++)
            {
                parentDirectory->subDirectories[j] = parentDirectory->subDirectories[j + 1];
            }
            parentDirectory->subDirectoryCount--;
            parentDirectory->subDirectories = (struct Directory *)realloc(parentDirectory->subDirectories, parentDirectory->subDirectoryCount * sizeof(struct Directory));
            printf("Subdirectory '%s' deleted from directory '%s'\n", subDirName, parentDirectory->name);
            return;
        }
    }
    printf("Subdirectory '%s' not found in directory '%s'\n", subDirName, parentDirectory->name);
}

void main()
{

    struct Directory root = createDirectory("Root");

    struct File file1 = createFile("file1.txt", 512);
    struct File file2 = createFile("file2.txt", 512);

    addFileToDirectory(file1, &root);
    addFileToDirectory(file2, &root);

    struct Directory subDir1 = createDirectory("Subdirectory1");
    struct Directory subDir2 = createDirectory("Subdirectory2");
    addSubDirectory(subDir1, &root);
    addSubDirectory(subDir2, &root);

    listDirectoryContents(root);

    // Delete a file and a subdirectory
    deleteFileFromDirectory("file1.txt", &root);
    deleteSubDirectory("Subdirectory1", &root);

    listDirectoryContents(root);

    // Free the allocated memory free(root.files); free(root.subDirectories);
}