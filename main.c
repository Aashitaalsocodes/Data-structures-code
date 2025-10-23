#include <stdio.h>
#include <stdlib.h>

int GCD(int a,int b)
{
    if(a==b)
    return 0;
    else if(a>b)
        return GCD(a-b,b);
        return GCD(b,a);
}
int main(int a,int b)
{

    printf("read the value for a and b\n");
    scanf("%d %d",&a,&b);
    printf("GCD of %d and %d is %d",a,b,GCD(a,b));
    return 0;
}
