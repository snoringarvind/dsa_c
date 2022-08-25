#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Array_1
{
  int A[30];
  int length;
};

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

void FindingDuplicatesInUnsortedArray_2(struct Array arr)
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

// using nested loops, unsorted array
void FindingPairOfElementsWithSumK_1(struct Array arr, int k)
{
  for (int i = 0; i < arr.length - 1; i++)
  {
    for (int j = i + 1; j < arr.length; j++)
    {
      if (arr.A[i] + arr.A[j] == k)
      {
        printf("pair of elements are %d, %d\n", arr.A[i], arr.A[j]);
        break;
      }
    }
  }
}

// using hash table, unsorted array
void FindingPairOfElementsWithSumK_2(struct Array arr, int k)
{
  int h = Max(arr);
  int hashArray[h + 1];

  for (int i = 0; i <= h; i++)
  {
    hashArray[i] = 0;
  }

  for (int i = 0; i < arr.length; i++)
  {
    if (arr.A[i] <= k && hashArray[k - arr.A[i]] != 0)
      printf("pair of elements are %d, %d\n", arr.A[i], k - arr.A[i]);
    hashArray[arr.A[i]]++;
  }
}

int Max_1(struct Array_1 arr)
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

int Min_1(struct Array_1 arr)
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
}

// using hash table, unsorted array, for negative numbers
void FindingPairOfElementsWithSumK_3(struct Array arr, int k)
{
  int l = Min(arr);

  if (l < 0)
  {
    for (int i = 0; i < arr.length; i++)
    {
      arr.A[i] = arr.A[i] + (l * -1);
    }
  }

  l = l * -1;

  int h = Max(arr);
  int hashArray[h + 1];

  for (int i = 0; i <= h; i++)
  {
    hashArray[i] = 0;
  }

  for (int i = 0; i < arr.length; i++)
  {
    int a = arr.A[i] - l;
    int b = k - a;
    int hash_index = b + l;

    if (hash_index <= h)
    {
      if (hashArray[hash_index] != 0)
        printf("pair of elements are %d, %d\n", a, b);
    }
    hashArray[arr.A[i]]++;
  }
};

// sorted array
void FindingPairOfElementsWithSumKInSortedArray(struct Array arr, int k)
{
  int i = 0;
  int j = arr.length;
  while (i < j)
  {
    if (arr.A[i] + arr.A[j] > k)
    {
      j--;
    }
    else if (arr.A[i] + arr.A[j] < k)
    {
      i++;
    }
    else
    {
      printf("%d, %d\n", arr.A[i], arr.A[j]);
      i++;
    }
  }
}

void FindingMinMaxInSingleScan(struct Array arr, int *min, int *max)
{
  int temp_min = arr.A[0];
  int temp_max = 0;
  for (int i = 0; i < arr.length; i++)
  {
    if (arr.A[i] < temp_min)
    {
      temp_min = arr.A[i];
    }
    else if (arr.A[i] > temp_max)
    {
      temp_max = arr.A[i];
    }
  }
  *min = temp_min;
  *max = temp_max;
}

int FindLengthOfString(char str[])
{
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    count++;
  }

  return count;
}

void ToLowerCase(char str[])
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] >= 65 && str[i] <= 90)
    {
      str[i] = str[i] + 32;
    }
  }
}

void ToUpperCase(char str[])
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] >= 97 && str[i] <= 122)
    {
      str[i] = str[i] - 32;
    }
  }
}

void ToggleCase(char str[])
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] >= 97 && str[i] <= 122)
    {
      str[i] = str[i] - 32;
    }
    else if (str[i] >= 65 && str[i] <= 90)
    {
      str[i] = str[i] + 32;
    }
  }
}

int CountVoweslAndConsonants(char str[], int *v, int *c)
{
  int c_count = 0;
  int v_count = 0;
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
        str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
      v_count += 1;
    else
      c_count += 1;
  }
  *v = v_count;
  *c = c_count;
}

int CountWords(char str[])
{
  int word = 1;
  for (int i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == ' ' && str[i - 1] != ' ')
    {
      word++;
    }
  }

  return word;
}

void ReverseAString_1(char str[], char rstr[])
{
  int i;
  for (i = 0; str[i] != '\0'; i++)
  {
  }

  i = i - 1;

  for (int j = 0; i >= 0; j++, i--)
  {
    rstr[j] = str[i];
  }
}

void ReverseAString_2(char str[])
{
  int i = 0;
  for (; str[i] != '\0'; i++)
  {
  }
  i -= 1;

  for (int j = 0; i > j; j++, i--)
  {
    char temp = str[j];
    str[j] = str[i];
    str[i] = temp;
  }
}

int ComparingStrings(char str1[], char str2[])
{
  for (int i = 0; str1[i] != '\0'; i++)
  {
    if (str1[i] != str2[i])
    {
      return 0;
    }
  }
  return 1;
}

void CheckPalindrome_1(char str[])
{

  int i = 0;
  for (; str[i] != '\0'; i++)
  {
  }
  i -= 1;

  char str2[i];

  ReverseAString_1(str, str2);

  if (ComparingStrings(str, str2) == 0)
    printf("not a palindrome\n");
  else
    printf("string is a palindrome\n");
}

void CheckPalindrome_2(char str[])
{
  int i = 0;
  for (; str[i] != '\0'; i++)
  {
  }
  i -= 1;

  for (int j = 0; i > j; j++, i--)
  {
    if (str[j] != str[i])
    {
      printf("not a palindrome");
      return;
    }
  }

  printf("it is a palindrome");
}

// using nested loops
void FindingDuplicatesInString_1(char str[])
{
  int l = 0;
  int count = 0;
  for (; str[l] != '\0'; l++)
  {
  }

  for (int i = 0; i < l - 1; i++)
  {
    count = 1;
    if (str[i] != -1)
    {
      for (int j = i + 1; j < l; j++)
      {
        if (str[j] != -1 && str[i] == str[j])
        {
          count++;
          str[j] = -1;
        }
      }
      if (count > 1)
      {
        printf("%c is appearing %d times\n", str[i], count);
      }
    }
  }
}

// using hashtablem, also converts to lowercase
void FindingDuplicatesInString_2(char str[])
{
  ToLowerCase(str);
  int l;
  for (; str[l] != '\0'; l++)
  {
  }

  int hashArray[26] = {0};

  for (int i = 0; i < l; i++)
  {
    hashArray[str[i] - 97]++;
  }

  for (int i = 0; i < 26; i++)
  {
    if (hashArray[i] > 1)
    {
      printf("%c is appearing %d times\n", i + 97, hashArray[i]);
    }
  }
}

// using bitwise operations
void FindDuplicatesInString_3(char str[])
{
  int h, x = 0;

  for (int i = 0; str[i] != '\0'; i++)
  {
    x = 1;
    x = x << (str[i] - 97);
    if ((x & h) > 0)
      printf("duplicate found %c\n", str[i]);

    h = x | h;
  }
}

// using nested loops
void CheckAnagram_1(char str1[], char str2[])
{
  int found = 0;
  int str1_length = 0;
  int str2_length = 0;
  for (; str1[str1_length] != '\0'; str1_length++)
  {
  }

  for (; str2[str2_length]; str2_length++)
  {
  }

  if (str1_length != str2_length)
  {
    printf("not anagram\n");
  }
  else
  {
    for (int i = 0; str1[i] != '\0'; i++)
    {
      found = 0;
      for (int j = 0; str2[j] != '\0'; j++)
      {
        if (str2[j] != -1 && str1[i] == str2[j])
        {
          str2[j] = -1;
          found = 1;
          break;
        }
      }
      if (found == 0)
      {
        printf("not anagram\n");
        break;
      }
    }
  }

  if (found == 1)
  {
    printf("it is a anagram\n");
  }
}

// using hashtable, for lowercase letters,else you can convert all letters to lower and then check.
void CheckAnagram_2(char A[], char B[])
{
  int hashArray[26] = {0};
  int A_length = 0;
  int B_length = 0;

  for (; A[A_length] != 0; A_length++)
  {
  }

  for (; B[B_length] != 0; B_length++)
  {
  }

  if (A_length != B_length)
  {
    printf("not anagram");
    return;
  }

  for (int i = 0; i < A_length; i++)
  {
    hashArray[A[i] - 97] += 1;
  }

  for (int i = 0; i < B_length; i++)
  {
    hashArray[B[i] - 97] -= 1;
    if (hashArray[B[i] - 97] < 0)
    {
      printf("not anagram");
      return;
    }
  }

  printf("anagram");
}

// using bitwise operations, cannot use duplicates
void CheckAnagram_3(char A[], char B[])
{
  int H, H_temp, X_temp = 1;

  int A_length = 0;
  int B_length = 0;

  for (; A[A_length] != 0; A_length++)
  {
  }

  for (; B[B_length] != 0; B_length++)
  {
  }

  if (A_length != B_length)
  {
    printf("not anagram");
    return;
  }

  for (int i = 0; i < A_length; i++)
  {
    H_temp = 1;
    H_temp = H_temp << (A[i] - 97);
    H = H | H_temp;
  }

  for (int j = 0; j < B_length; j++)
  {
    X_temp = 1;
    X_temp = X_temp << (B[j] - 97);
    if ((X_temp & H) == 0)
    {
      printf("not anagram");
      return;
    }
  }

  printf("anagram");
}

int main()
{
  struct Array arr;
  arr.size = 20;
  arr.A = (int *)malloc(arr.size * sizeof(int));

  arr.A[0] = 2;
  arr.A[1] = 3;
  arr.A[2] = 4;
  arr.A[3] = 6;
  arr.A[4] = 8;
  arr.A[5] = 10;
  arr.A[6] = 12;
  arr.length = 7;

  char name[] = "bad";
  char name1[] = "abe";

  CheckAnagram_3(name, name1);
  return 0;
}