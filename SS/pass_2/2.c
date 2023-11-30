#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char label[10], opcode[10], operand[10], symbol[10];
    int finadd, prevadd, address;
    char mnemonic[15][15] = {"LDA", "STA", "LDCH", "STCH"};
    char code[15][15] = {"33", "44", "53", "57"};
    int start;
    FILE *f1 = fopen("output.txt", "w");
    FILE *f2 = fopen("objcode.txt", "w");
    FILE *f3 = fopen("intermediate.txt", "r");
    FILE *f4 = fopen("symtab.txt", "r");

    fscanf(f3, "%s%s%s", label, opcode, operand);
    while (strcmp(opcode, "END") != 0)
    {
        prevadd = address;
        fscanf(f3, "%d%s%s%s", &address, label, opcode, operand);
    }
    finadd = address;
    rewind(f3);
    fscanf(f3, "%s%s%s", label, opcode, operand);
    if (strcmp(opcode, "START") == 0)
    {
        fprintf(f1, "\t%s\t%s\t%s\n", label, opcode, operand);
        fprintf(f2, "H^%s^00%s^00%d\n", label, operand, finadd);
        fscanf(f3, "%d%s%s%s", &address, label, opcode, operand);
        start = address;
        int diff = prevadd - start;
        fprintf(f2, "T^00%d^%d", address, diff);
    }

    while (strcmp(opcode, "END") != 0)
    {
        if (strcmp(opcode, "BYTE") == 0)
        {
            int i;
            fprintf(f1, "%d\t%s\t%s\t%s\t", address, label, opcode, operand);
            fprintf(f2, "^");
            for (i = 2; i < strlen(operand) - 1; i++)
            {
                fprintf(f1, "%X", operand[i]);
                fprintf(f2, "%X", operand[i]);
            }
            fprintf(f1, "\n");
        }
        else if (strcmp(opcode, "WORD") == 0)
        {
            fprintf(f1, "%d\t%s\t%s\t%s\t00000%s\n", address, label, opcode, operand, operand);
            fprintf(f2, "^00000%s", operand);
        }
        else if (strcmp(opcode, "RESB") == 0 || (strcmp(opcode, "RESW") == 0))
        {
            fprintf(f1, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);
        }
        else
        {
            int j = 0;
            while (strcmp(opcode, mnemonic[j]) != 0)
            {
                j++;
            }
            if (strcmp(operand, "COPY") == 0)
            {
                fprintf(f1, "%d\t%s\t%s\t%s\t%s0000\n", address, label, opcode, operand, code[j]);
            }
            else
            {
                rewind(f4);
                int temp;
                fscanf(f4, "%s%d", symbol, &temp);
                while (strcmp(operand, symbol) != 0)
                {
                    fscanf(f4, "%s%d", symbol, &temp);
                }
                fprintf(f1, "%d\t%s\t%s\t%s\t%s%d\n", address, label, opcode, operand, code[j], temp);
                fprintf(f2, "^%s%d\n", code[j], temp);
            }
        }
        fscanf(f3, "%d%s%s%s", &address, label, opcode, operand);
    }
    fprintf(f2, "\nE^00%d", start);
    fprintf(f1, "%d\t%s\t%s\t%s\n", address, label, opcode, operand);

    printf("the content of object code: \n");
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    FILE *f5 = fopen("objcode.txt", "r");
    char ch = fgetc(f5);
    while (ch != EOF)
    {
        printf("%c", ch);
        ch = fgetc(f5);
    }
    fclose(f5);
}