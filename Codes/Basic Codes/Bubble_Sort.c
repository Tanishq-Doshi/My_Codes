#include <stdio.h>
void bubble_sort(int *arr, int n);
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
int main()
{
    printf("Enter size of array: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d of array: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Original array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    bubble_sort(arr, n);
    printf("Sorted array is: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
void bubble_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag=0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag=1;
            }
        }
        if(flag==0)
             break;
    }
    return;
}