#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    if (a==0)
        return b;
    return gcd(b%a,a);
}
int main(){
int a,b;
printf("\nRead values of a & b.\n");
scanf("%d%d",&a,&b);
printf("\nGCD(%d,%d) = %d\n",a,b,gcd(a,b));
return 0;
}
