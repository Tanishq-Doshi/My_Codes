#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}
/* Quick Sort using first element as pivot
int partition_array(int *arr, int low, int high) // Take high as number of elements here
{
  int pivot = arr[low];
  int i = low, j = high;
  while (i < j)
  {
    do
    {
      i++;
    } while (pivot >= arr[i]);
    do
    {
      j--;
    } while (pivot < arr[j]);
    if (i < j)
      swap(&arr[i], &arr[j]);
  }
  swap(&arr[low], &arr[j]);
  return j;
}
void quicksort(int *arr, int low, int high)
{
  if (low < high)
  {
    int j = partition_array(arr, low, high);
    quicksort(arr, low, j);
    quicksort(arr, j + 1, high);
  }
}
*/

// Quick Sort using middle element as pivot
void quicksort(int *arr, int low, int high)
{
  if (low >= high)
    return;
  int pivot = arr[(low + high)/2];
  int i = low-1;
  int j = high+1;
  while (i < j)
  {
    while (arr[++i] < pivot);
    while (arr[--j] > pivot);
    if (i >= j)
      break;
    swap(arr[i], arr[j]);
  }
  quicksort(arr, low, j);
  quicksort(arr, j + 1, high);
}
int main()
{
  int arr[] = {92, 5, 12, 5, 7, 1232, 4, 22, -8, -1};
  int n = sizeof(arr) / sizeof(arr[0]);
  quicksort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  return 0;
}