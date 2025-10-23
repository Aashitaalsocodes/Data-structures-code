#include <stdio.h>
#include <stdlib.h>

void toh(int n, char s, char d, char t)
{
    if (n > 1)
    {
        toh(n - 1, s, t, d);
        printf("\n Move disc %d from %c to %c", n, s, d);
        toh(n - 1, t, d, s);
    }
    else
    {
        printf("\n Move disc %d from %c to %c", n, s, d);
    }
}

int main()
{
    int n;
    char s = 'A', d = 'C', t = 'B';
    printf("\n Read number of discs: ");
    scanf("%d", &n);
    toh(n, s, d, t);
    return 0;
}
