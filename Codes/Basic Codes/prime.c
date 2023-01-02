#include <stdio.h>
int main()
{
    int n, i = 1, j = 0;
    printf("Enter number : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
            j++;
    }
    if (j == 1)
        printf("Number is 1.");
    else if (j == 2)
        printf("Number is prime.");
    else
        printf("Number is composite.");
    return 0;
}