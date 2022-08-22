#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Array
{
  int *A;
  int size;
  int length;
};

void Display(struct Array *arr)
{
  for (int i = 0; i < arr->length; i++)
  {
    printf("%d\n", arr->A[i]);
  }
}

int Append(struct Array *A, int element)
{
  if (A->length < A->size)
  {
    A->A[A->length++] = element;
    return 1;
  }
  else
    return 0;
}

int Insert(struct Array *A, int element, int index)
{
  if (index >= 0 && index <= A->length)
  {
    for (int i = A->length; i > index; i--)
    {
      A->A[i] = A->A[i - 1];
    }
    A->A[index] = element;
    A->length++;
    return 1;
  }
  else
    return 0;
}

int Delete(struct Array *A, int index)
{
  if (index >= 0 && index < A->length)
  {
    for (int i = index; i < A->length - 1; i++)
    {
      A->A[i] = A->A[i + 1];
    }
    A->length--;
    return 1;
  }
  else
    return 0;
}

void Swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

int LinearSearch(struct Array *arr, int element)
{
  for (int i = 0; i < arr->length; i++)
  {
    if (arr->A[i] == element)
    {
      Swap(&arr->A[i], &arr->A[i - 1]);
      return i;
    }
  }

  return -1;
}

int BinarySeach(struct Array *arr, int element)
{
  int l = 0;
  int h = arr->length - 1;
  int mid;

  while (l <= h)
  {
    mid = (l + h) / 2;

    if (arr->A[mid] == element)
    {
      return mid;
    }
    else if (element < arr->A[mid])
    {
      h = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  return -1;
}

int RBinarySeach(struct Array *arr, int element, int h, int l)
{
  int mid;
  if (l <= h)
  {

    mid = (l + h) / 2;

    if (arr->A[mid] == element)
    {
      return mid;
    }
    else if (element < arr->A[mid])
    {
      return RBinarySeach(arr, element, mid - 1, l);
    }
    else
    {
      return RBinarySeach(arr, element, h, mid + 1);
    }
  }
  return -1;
}

int Get(struct Array arr, int index)
{
  return arr.A[index];
}

void Set(struct Array *arr, int index, int element)
{
  arr->A[index] = element;
}

int Max(struct Array arr)
{
  int max = arr.A[0];
  for (int i = 0; i < arr.length; i++)
  {
    if (arr.A[i] > max)
    {
      max = arr.A[i];
    }
  }
  return max;
}

int Min(struct Array arr)
{
  int min = arr.A[0];
  for (int i = 0; i < arr.length; i++)
  {
    if (arr.A[i] < min)
    {
      min = arr.A[i];
    }
  }

  return min;
};

int Sum(struct Array *arr)
{
  int total = 0;
  for (int i = 0; i < arr->length; i++)
  {
    total += arr->A[i];
  }
  return total;
}

int Sum_Recursive(int A[], int n)
{
  if (n < 0)
  {
    return 0;
  }

  return Sum_Recursive(A, n - 1) + A[n];
}

int Average(struct Array *arr)
{
  return Sum(arr) / arr->length;
}

void Reverse(struct Array *arr)
{
  int reverse_count = arr->length;
  int temp = 0;
  for (int i = 0; i < arr->length / 2; i++)
  {
    reverse_count -= 1;
    temp = arr->A[i];

    arr->A[i] = arr->A[reverse_count];
    arr->A[reverse_count] = temp;
  }
}

void LeftShift(struct Array *arr)
{
  for (int i = 0; i < arr->length; i++)
  {
    if (i == arr->length - 1)
    {
      arr->A[i] = 0;
    }
    else
    {
      arr->A[i] = arr->A[i + 1];
    }
  }
}

void RightShift(struct Array *arr)
{
  for (int i = arr->length - 1; i >= 0; i--)
  {
    if (i == 0)
    {
      arr->A[i] = 0;
    }
    else
    {
      arr->A[i] = arr->A[i - 1];
    }
  }
}

void LeftRotate(struct Array *arr)
{
  int temp = arr->A[0];
  LeftShift(arr);
  arr->A[arr->length - 1] = temp;
}

void RightRotate(struct Array *arr)
{
  int temp = arr->A[arr->length - 1];
  RightShift(arr);
  arr->A[0] = temp;
}

void InsertInSortedArray(struct Array *arr, int x)
{
  int i = arr->length - 1;
  while (x < arr->A[i])
  {
    arr->A[i + 1] = arr->A[i];
    i--;
  }
  arr->A[i + 1] = x;
  arr->length++;
}

int isSorted(struct Array arr)
{
  for (int i = 0; i < arr.length - 1; i++)
  {
    if (arr.A[i] > arr.A[i + 1])
    {
      return 0;
    }
  }
  return 1;
}

void NegativeOnLeftSide(struct Array *arr)
{
  int i = 0;
  int j = arr->length - 1;

  while (i < j)
  {
    while (arr->A[i] < 0)
    {
      i++;
    }

    while (arr->A[j] >= 0)
    {
      j--;
    }

    if (i < j)
    {
      Swap(&arr->A[i], &arr->A[j]);
    }
  }
}

struct Array *Merge(struct Array *X, struct Array *Y)
{
  int i = 0;
  int j = 0;
  int k = 0;

  struct Array *Z = (struct Array *)malloc(sizeof(struct Array));

  while (i < X->length && j < Y->length)
  {
    if (X->A[i] < Y->A[j])
    {
      Z->A[k++] = X->A[i++];
    }
    else
    {
      Z->A[k++] = Y->A[j++];
    }
  }

  for (; i < X->length; i++)
  {
    Z->A[k++] = X->A[i];
  }

  for (; j < Y->length; j++)
  {
    Z->A[k++] = Y->A[j];
  }

  Z->length = X->length + Y->length;

  return Z;
};

struct Array *UnionSet(struct Array *X, struct Array *Y)
{
  int i = 0;
  int j = 0;
  int k = 0;
  struct Array *Z = (struct Array *)malloc(sizeof(struct Array));

  while (i < X->length && j < Y->length)
  {
    if (X->A[i] < Y->A[j])
      Z->A[k++] = X->A[i++];
    else if (X->A[i] > Y->A[j])
      Z->A[k++] = Y->A[j++];
    else
    {
      Z->A[k++] = X->A[i++];
      j++;
    }
  }

  for (; i < X->length; i++)
  {
    Z->A[k++] = X->A[i];
  }

  for (; j < Y->length; j++)
  {
    Z->A[k++] = Y->A[j];
  }
  Z->length = k;
  return Z;
}

struct Array *Intersection(struct Array *X, struct Array *Y)
{

  int i = 0;
  int j = 0;
  int k = 0;
  struct Array *Z = (struct Array *)malloc(sizeof(struct Array));

  while (i < X->length && j < Y->length)
  {
    if (X->A[i] < Y->A[j])
    {
      i++;
    }
    else if (X->A[i] > Y->A[j])
    {
      j++;
    }
    else
    {
      Z->A[k++] = X->A[i++];
      j++;
    }
  }

  Z->length = k;
  return Z;
}

struct Array *DifferenceSet(struct Array *X, struct Array *Y)
{

  int i = 0;
  int j = 0;
  int k = 0;
  struct Array *Z = (struct Array *)malloc(sizeof(struct Array));

  while (i < X->length && j < Y->length)
  {
    if (X->A[i] < Y->A[j])
    {
      Z->A[k++] = X->A[i++];
    }
    else if (X->A[i] > Y->A[j])
    {
      j++;
    }
    else
    {
      i++;
      j++;
    }
  }

  for (; i < X->length; i++)
  {
    Z->A[k++] = X->A[i];
  }

  Z->length = k;
  return Z;
}

int MenuDriverProgram()
{
  struct Array arr;
  printf("Enter size of Array");
  scanf("%d", &arr.size);
  arr.A = (int *)malloc(arr.size * sizeof(int));
  arr.length = 0;

  int input = 0;
  int element = 0;
  int index = 0;
  int output = 0;

  do
  {

    printf("Menu Driver program\n");
    printf("1. Append\n");
    printf("2. Insert\n");
    printf("3. Delete\n");
    printf("4. Search\n");
    printf("5. Sum\n");
    printf("6. Display\n");
    printf("7. Exit\n");
    printf("Enter your choice\n");
    scanf("%d", &input);

    switch (input)
    {
    case 1:
      printf("Enter an element to append\n");
      scanf("%d", &element);
      output = Append(&arr, element);
      if (output == 1)
        printf("Element added\n");
      else
        printf("No space in array\n");
      break;
    case 2:
      printf("Enter an element & index\n");
      scanf("%d %d", &element, &index);
      output = Insert(&arr, element, index);
      if (output == 1)
        printf("New element inserted\n");
      else
        printf("Invalid values\n");
      break;
    case 3:
      printf("Enter index to delete element from\n");
      scanf("%d", &index);
      output = Delete(&arr, index);
      if (output == 1)
        printf("Element deleted\n");
      else
        printf("Invalid index value\n");
      break;
    case 4:
      printf("Enter element to search\n");
      scanf("%d", &element);
      output = BinarySeach(&arr, element);
      if (output != -1)
        printf("The element is at index %d\n", output);
      else
        printf("Element not found.");
      break;
    case 5:
      output = Sum(&arr);
      printf("The sum is %d\n", output);
      break;
    case 6:
      printf("The elements in array are:\n");
      Display(&arr);
      break;
    }

  } while (input < 7);

  free(arr.A);
}

// In sorted array, elements starting from 1
void FindSingleMissingElementInSortedArray_1(struct Array *arr)
{
  int n = arr->length;
  int s = (arr->A[arr->length - 1] * (arr->A[arr->length - 1] + 1)) / 2;
  int sum = 0;
  for (int i = 0; i < arr->length; i++)
  {
    sum = sum + arr->A[i];
  }

  printf("Missing element is %d\n", s - sum);
}

// In sorted array, elements not starting from 1;
void FindSingleMissingElementInSortedArray_2(struct Array *arr)
{
  int diff = arr->A[0] - 0;

  for (int i = 0; i < arr->length; i++)
  {
    if (arr->A[i] - i != diff)
    {
      printf("Missing element is %d\n", i + diff);
      diff = arr->A[i] - i;
    }
  }
}

// In sorted Array
int FindingMultipleMissingElementsInSortedArray_1(struct Array *arr)
{
  int diff = arr->A[0] - 0;

  for (int i = 0; i < arr->length; i++)
  {
    if (arr->A[i] - i != diff)
    {
      while (diff < arr->A[i] - i)
      {
        printf("The missing element is %d\n", diff + i);
        diff++;
      }

      diff = arr->A[i] - i;
    }
  }
}

// In sorted array
int FindingMultipleMissingElementsInSortedArray_2(struct Array arr)
{
  int h = Max(arr);
  int l = Min(arr);

  int count = 0;

  for (int i = l; i < h; i++)
  {
    if (arr.A[count] != i)
      printf("The missing element is %d\n", i);
    else
      count++;
  }
}

// unsorted array, using hashtable
int FindingMultipleMissingElementsInUnsortedArray(struct Array arr)
{
  int l = 1;
  int h = Max(arr);

  int hashArray[h];

  hashArray[0] = 0;
  for (int i = 0; i <= h; i++)
  {
    hashArray[i] = 0;
  }

  for (int i = 0; i < arr.length; i++)
  {
    hashArray[arr.A[i]]++;
  }

  for (int i = 0; i <= h; i++)
  {
    if (hashArray[i] == 0)
      printf("%d\n", i);
  }
}

// sorted array, finding duplicated
int FindingDuplicatesInSortedArray(struct Array arr)
{
  // print duplicate only once;
  int lastDuplicate = 0;

  for (int i = 0; i < arr.length - 1; i++)
  {
    if (arr.A[i] == arr.A[i + 1] && arr.A[i] != lastDuplicate)
    {
      printf("Duplicate elements are %d\n", arr.A[i]);
      lastDuplicate = arr.A[i];
    }
  }
}

// sorted array, counting duplicates
int CountingDuplicatesInSortedArray_1(struct Array arr)
{
  int count = 0;
  for (int i = 0; i < arr.length; i++)
  {
    if (arr.A[i] == arr.A[i + 1] && i != arr.length - 1)
      count++;
    else if (count >= 1)
    {
      printf("%d is appearing %d times\n", arr.A[i], count + 1);
      count = 0;
    }
    else
      count = 0;
  }
}

// sorted array, counting duplicates
int CountingDuplicatesInSortedArray_2(struct Array arr)
{
  int j = 0;
  for (int i = 0; i < arr.length - 1; i++)
  {
    if (arr.A[i] == arr.A[i + 1])
    {
      j = i + 1;
      while (arr.A[i] == arr.A[j])
        j++;
      printf("%d is appearing %d times\n", arr.A[i], j - i);
      i = j;
    }
  }
}

// sorted array, finding duplicates, using hash-table
int FindingDuplicatesInSortedArray_3(struct Array arr)
{
  int l = 1;
  int h = Max(arr);
  int hashArray[h + 1]; // create an array from 0-n+1

  for (int i = 0; i <= h; i++)
  {
    hashArray[i] = 0;
  }

  for (int i = 0; i < arr.length; i++)
  {
    hashArray[arr.A[i]]++;
  }

  for (int i = 0; i <= h; i++)
  {
    if (hashArray[i] > 1)
    {
      printf("%d is appearing %d times\n", i, hashArray[i]);
    }
  }
}

// unsorted array, using nested loops
void FindingDuplicatesInUnSortedArray_2(struct Array arr)
{
  int count = 1;
  for (int i = 0; i < arr.length - 1; i++)
  {
    if (arr.A[i] != -1)
    {
      for (int j = i + 1; j < arr.length; j++)
      {
        if (arr.A[i] == arr.A[j])
        {
          count++;
          arr.A[j] = -1;
        }
      }
      if (count > 1)
        printf("%d is appearing %d times\n", arr.A[i], count);
      count = 1;
    }
  }
}

// #126
int FindingDuplicatesInUnsortedArray_2(struct Array arr)
{
  int h = Max(arr);
  int hashArray[h + 1];

  for (int i = 0; i <= h; i++)
  {
    hashArray[i] = 0;
  }

  for (int i = 0; i < arr.length; i++)
  {
    hashArray[arr.A[i]]++;
  }

  for (int i = 0; i <= h; i++)
  {
    if (hashArray[i] > 1)
      printf("%d is appearing %d times", i, hashArray[i]);
  }
}

int main()
{
  struct Array arr;
  arr.size = 20;
  arr.A = (int *)malloc(arr.size * sizeof(int));

  arr.A[0] = 6;
  arr.A[1] = 6;
  arr.A[2] = 20;
  arr.A[3] = 8;
  arr.A[4] = 10;
  arr.A[5] = 15;
  arr.A[6] = 15;
  arr.A[7] = 10;
  arr.A[8] = 20;
  arr.A[9] = 8;

  arr.length = 10;

  FindingDuplicatesInUnSortedArray_2(arr);
  free(arr.A);

  return 0;
}