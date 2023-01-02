#include <bits/stdc++.h>
using namespace std;
void Merge(int *arr, int low, int mid, int high)
{
  int temp1[mid - low + 1];
  int temp2[high - mid];
  for (int i = low, j = 0; i <= mid; i++, j++)
    temp1[j] = arr[i];
  for (int i = mid + 1, j = 0; i <= high; i++, j++)
    temp2[j] = arr[i];
  int final[high - low + 1];
  int i = 0, j = 0, k = 0;
  while (i < mid - low + 1 && j < high - mid)
  {
    if (temp1[i] >= temp2[j])
    {
      final[k] = temp2[j];
      k++;
      j++;
    }
    else
    {
      final[k] = temp1[i];
      k++;
      i++;
    }
  }
  for (; i < mid - low + 1; i++, k++)
    final[k] = temp1[i];
  for (; j < high - mid; j++, k++)
    final[k] = temp2[j];
  for (int i = low, j = 0; i <= high; i++, j++)
    arr[i] = final[j];
}
void mergesort(int *arr, int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    Merge(arr, low, mid, high);
  }
}
int main()
{
  int arr[] = {92, 5, 12, 5, 7, 1232, 4, 22, -8, -1};
  int n = sizeof(arr) / sizeof(arr[0]);
  mergesort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  return 0;
}