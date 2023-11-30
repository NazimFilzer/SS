#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void passOne();
void display();

int main()
{
    passOne();
    return 0;
}

void passOne()
{
    int locctr = 0, start, length;

    FILE *fp1, *fp2, *fp3, *fp4, *fp5;
    char label[10], opcode[10], operand[10], code[10], mnemonic[3];

    // Open files for input and output
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("optab.txt", "r");
    fp3 = fopen("symtab.txt", "w");
    fp4 = fopen("intermediate.txt", "w");
    fp5 = fopen("length.txt", "w");

    // Adjusted fscanf statement to read tab-separated fields
    fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);

    if (strcmp(opcode, "START") == 0)
    {
        start = atoi(operand);
        locctr = start;
        fprintf(fp4, "%s\t%s\t%s\n", label, opcode, operand);
        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand); // Adjusted here as well
    }

    while (strcmp(opcode, "END") != 0)
    {
        // Write to the intermediate file
        fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);

        // Check for labels and write to symtab
        if (strcmp(label, "**") != 0)
            fprintf(fp3, "%s\t%d\n", label, locctr);

        // Read from the optab (code and mnemonic)
        fscanf(fp2, "%s\t%s", code, mnemonic);

        // Search for the opcode in the optab
        while (strcmp(code, "END") != 0)
        {
            if (strcmp(opcode, code) == 0)
            {
                locctr += 3;
                break;
            }
            fscanf(fp2, "%s\t%s", code, mnemonic);
        }

        // Handle opcodes and update locctr accordingly
        if (strcmp(opcode, "WORD") == 0)
            locctr += 3;
        else if (strcmp(opcode, "RESW") == 0)
            locctr += 3 * atoi(operand);
        else if (strcmp(opcode, "BYTE") == 0)
        {
            // Check the format of BYTE and calculate the size
            if (operand[0] == 'C')
                locctr += strlen(operand) - 3;
            else if (operand[0] == 'X')
                locctr += (strlen(operand) - 3) / 2;
            else
            {
                printf("Error: Invalid BYTE format: %s\n", operand);
                exit(1);
            }
        }
        else if (strcmp(opcode, "RESB") == 0)
            locctr += atoi(operand);

        // Read the next line from the input
        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }

    // Transfer the last line to the intermediate file
    fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);

    // Close all files
    fclose(fp4);
    fclose(fp3);
    fclose(fp2);
    fclose(fp1);

    // Display outputs
    display();

    // Calculate the length of the program
    length = locctr - start;
    fprintf(fp5, "%d", length);
    fclose(fp5);
    printf("\nThe length of the code: %d\n", length);
}

void display()
{
    FILE *fp1, *fp2, *fp3;
    char c;

    // Display the contents of the Input Table
    printf("\nThe contents of Input Table:\n\n");
    fp1 = fopen("input.txt", "r");
    while ((c = fgetc(fp1)) != EOF)
        printf("%c", c);
    fclose(fp1);

    // Display the contents of the Output Table
    printf("\n\nThe contents of Output Table:\n\n");
    fp2 = fopen("intermediate.txt", "r");
    while ((c = fgetc(fp2)) != EOF)
        printf("%c", c);
    fclose(fp2);

    // Display the contents of the Symbol Table
    printf("\n\nThe contents of Symbol Table:\n\n");
    fp3 = fopen("symtab.txt", "r");
    while ((c = fgetc(fp3)) != EOF)
        printf("%c", c);
    fclose(fp3);
}
