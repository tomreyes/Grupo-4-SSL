#include <ctype.h> /* for isdigit() */
#include <stdio.h> /* for getchar && ungetc */
#include <stdlib.h> /* for atof() */
#include "./scanner.h" /* GetNextToken() declaration */

#define MAXOP 100 /* max size of lexeme */

/* Returns true if is possible to read another token, the read token is stored in t. */
bool GetNextToken (struct Token *t) {
    int i = 0;
    char lexeme[MAXOP];
    while ((lexeme[i] = getchar()) == ' ' || lexeme[i] == '\t');
    switch (lexeme[i]) {
        case EOF:
            return false;
        case Addition:
            t -> type = Addition;
            break;
        case Multiplication:
            t -> type = Multiplication;
            break;
        case Division:
            t -> type = Division;
            break;
        case Modulus:
            t -> type = Modulus;
            break;
        case PopResult:
            t -> type= PopResult;
            break;
        case Substraction:
            if (!isdigit(lexeme[++i] = getchar())) {
                t -> type = Substraction;
                ungetc(lexeme[i], stdin);
                break;
            }
        default:
            if(isdigit(lexeme[i])) {
                while (isdigit(lexeme[++i] = getchar()));
                if(lexeme[i] == '.')
                    while (isdigit(lexeme[++i] = getchar()));
                ungetc(lexeme[i], stdin);
                lexeme[i] = '\0';
                t -> type = Number;
                t -> data.val = atof(lexeme);
                break;
            }
            t -> type = LexError;
            lexeme[1] = '\0';
            t -> data.lexeme = lexeme;
            break;
    }
    return true;
}
