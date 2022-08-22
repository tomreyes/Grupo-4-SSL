#include <ctype.h>
#include "./buffer.h"

#define NUMBER '0' /* signal that a number was found */

int get_token (char s[]) {
    int si, c, i = 0;
    while ((s[0] = getch()) == ' ' || s[0] == '\t');
    s[1] = '\0';
    if(!isdigit(s[0]) && s[0] != '.' && s[0] != '-')
        return s[0]; // Not a number
    if(s[i] == '-')
        if ((c = getch()) == ' ' || c == '\t' || c == '\n') {
            ungetch(c);
            return s[0]; // - operator and not a negative number
        }
        if (isdigit(c))
            s[++i] = c;
        while (isdigit(s[++i] = getch()));
    if(isdigit(s[i]))
        while (isdigit(s[++i] = getch()));
    if(s[i] == '.')
        while (isdigit(s[++i] = getch()));
    s[i] = '\0';
    return NUMBER;
}