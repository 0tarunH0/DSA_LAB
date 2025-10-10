#include <stdio.h>
#include <stdlib.h>

void toh(int n,char s,char d,char t)
{
    if (n==1)
        printf("\nMove  disc %d from %c to %c",n,s,d);
    else{
        toh(n-1,s,t,d);
        printf("\nMove disc %d from %c to %c",n,s,d);
        toh(n-1,t,d,s);
    }
}
int main()
{
    int n;
    printf("\nRead no. of discs : ");
    scanf("%d",&n);
    toh(n,'S','D','T');
    return 0;
}
