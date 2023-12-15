#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convertHexToBinary(char hex[12]);
char relocationBitmask[12];
char binaryRepresentation[12] = {0};

int main()
{
    char programName[6], inputType[10], inputContent[10], binaryCode[12], relocationBit, ch, programNumber[5];
    int programStartAddress, inputAddress, inputLength, i, instructionAddress, opcode, operandAddress, actualAddress, totalLength;
    FILE *inputFile, *outputFile;

    // Get the actual starting address
    printf("\n\n Enter the actual starting address : ");
    scanf("%x", &programStartAddress);

    // Open input and output files
    inputFile = fopen("RLIN.txt", "r");
    outputFile = fopen("RLOUT.txt", "w");

    // Read the first input
    fscanf(inputFile, "%s", inputType);

    // Write header to the output file
    fprintf(outputFile, " ----------------------------\n");
    fprintf(outputFile, " ADDRESS\tCONTENT\n");
    fprintf(outputFile, " ----------------------------\n");

    // Process input until the end of the file is reached
    while (strcmp(inputType, "E") != 0)
    {
        if (strcmp(inputType, "H") == 0)
        {
            // Header record
            fscanf(inputFile, "%s", programNumber);
            fscanf(inputFile, "%x", &programStartAddress);
            fscanf(inputFile, "%x", &inputLength);
            fscanf(inputFile, "%s", inputType);
        }

        if (strcmp(inputType, "T") == 0)
        {
            // Text record
            fscanf(inputFile, "%x", &instructionAddress);
            fscanf(inputFile, "%x", &totalLength);
            fscanf(inputFile, "%s", relocationBitmask);
            instructionAddress += programStartAddress;
            convertHexToBinary(relocationBitmask);
            int length = strlen(binaryRepresentation);
            if (length >= 11)
                length = 10;

            // Process each instruction in the text record
            for (i = 0; i < length; i++)
            {
                fscanf(inputFile, "%x", &opcode);
                fscanf(inputFile, "%x", &operandAddress);
                relocationBit = binaryRepresentation[i];

                if (relocationBit == '0')
                    actualAddress = operandAddress;
                else
                    actualAddress = operandAddress + programStartAddress;

                // Write to the output file
                fprintf(outputFile, "\n  %x\t\t%x%x\n", instructionAddress, opcode, actualAddress);
                instructionAddress += 3;
            }
            fscanf(inputFile, "%s", inputType);
        }
    }

    // Write footer to the output file
    fprintf(outputFile, " ----------------------------\n");
    fclose(outputFile);

    // Display the contents of the output file
    printf("\n\n The contents of the output file (RLOUT.TXT):\n");
    outputFile = fopen("RLOUT.txt", "r");
    ch = fgetc(outputFile);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(outputFile);
    }
    fclose(outputFile);
    fclose(inputFile);

    return 0;
}

void convertHexToBinary(char hex[12])
{
    int i, length;
    strcpy(binaryRepresentation, "");
    length = strlen(hex);

    // Convert each hexadecimal digit to binary
    for (i = 0; i < length; i++)
    {
        switch (hex[i])
        {
        case '0':
            strcat(binaryRepresentation, "0000");
            break;
        case '1':
            strcat(binaryRepresentation, "0001");
            break;
        case '2':
            strcat(binaryRepresentation, "0010");
            break;
        case '3':
            strcat(binaryRepresentation, "0011");
            break;
        case '4':
            strcat(binaryRepresentation, "0100");
            break;
        case '5':
            strcat(binaryRepresentation, "0101");
            break;
        case '6':
            strcat(binaryRepresentation, "0110");
            break;
        case '7':
            strcat(binaryRepresentation, "0111");
            break;
        case '8':
            strcat(binaryRepresentation, "1000");
            break;
        case '9':
            strcat(binaryRepresentation, "1001");
            break;
        case 'A':
            strcat(binaryRepresentation, "1010");
            break;
        case 'B':
            strcat(binaryRepresentation, "1011");
            break;
        case 'C':
            strcat(binaryRepresentation, "1100");
            break;
        case 'D':
            strcat(binaryRepresentation, "1101");
            break;
        case 'E':
            strcat(binaryRepresentation, "1110");
            break;
        case 'F':
            strcat(binaryRepresentation, "1111");
            break;
        }
    }
}
