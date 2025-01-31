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

    fp1 = fopen("input.txt", "r");
    fp2 = fopen("optab.txt", "r");
    fp3 = fopen("symtab.txt", "w");
    fp4 = fopen("intermediate.txt", "w");
    fp5 = fopen("length.txt", "w");

    fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);

    if (strcmp(opcode, "START") == 0)
    {
        start = atoi(operand);
        locctr = start;
        fprintf(fp4, "%s\t%s\t%s\n", label, opcode, operand);
        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }

    while (strcmp(opcode, "END") != 0)
    {
        fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);

        if (strcmp(label, "**") != 0)
            fprintf(fp3, "%s\t%d\n", label, locctr);

        fscanf(fp2, "%s\t%s", code, mnemonic);

        while (strcmp(code, "END") != 0)
        {
            if (strcmp(opcode, code) == 0)
            {
                locctr += 3;
                break;
            }
            fscanf(fp2, "%s\t%s", code, mnemonic);
        }

        if (strcmp(opcode, "WORD") == 0)
            locctr += 3;
        else if (strcmp(opcode, "RESW") == 0)
            locctr += 3 * atoi(operand);
        else if (strcmp(opcode, "BYTE") == 0)
        {
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

        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    }

    fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);

    fclose(fp4);
    fclose(fp3);
    fclose(fp2);
    fclose(fp1);

    display();

    length = locctr - start;
    fprintf(fp5, "%d", length);
    fclose(fp5);
    printf("\nThe length of the code: %d\n", length);
}

void display()
{
    FILE *fp1, *fp2, *fp3;
    char c;

    printf("\nThe contents of Input Table:\n\n");
    fp1 = fopen("input.txt", "r");
    while ((c = fgetc(fp1)) != EOF)
        printf("%c", c);
    fclose(fp1);

    printf("\n\nThe contents of Output Table:\n\n");
    fp2 = fopen("intermediate.txt", "r");
    while ((c = fgetc(fp2)) != EOF)
        printf("%c", c);
    fclose(fp2);

    printf("\n\nThe contents of Symbol Table:\n\n");
    fp3 = fopen("symtab.txt", "r");
    while ((c = fgetc(fp3)) != EOF)
        printf("%c", c);
    fclose(fp3);
}

/*

input.txt
**	START	2000
**	LDA	FIVE
**	STA	ALPHA
** 	LDCH 	CHARZ
** 	STCH 	C1
ALPHA 	RESW 	2
FIVE 	WORD 	5
CHARZ 	BYTE 	C'Z'
C1 	RESB 	1
** 	END	**

optab.txt
LDA 03
STA	0f
LDCH    53
STCH	57
END	*


symtab.txt
ALPHA	2012
FIVE	2018
CHARZ	2021
C1	2022



intermediate.txt
**	START	2000
2000	**	LDA	FIVE
2003	**	STA	ALPHA
2006	**	LDCH	CHARZ
2009	**	STCH	C1
2012	ALPHA	RESW	2
2018	FIVE	WORD	5
2021	CHARZ	BYTE	C'Z'
2022	C1	RESB	1
2023	**	END	**

length.txt
23



*/