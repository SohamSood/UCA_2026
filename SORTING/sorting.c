#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generateRandom(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        arr[i] = rand();
}

void generateAscending(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        arr[i] = i;
}

void generateDescending(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        arr[i] = n - i;
}
void bubbleSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}
void selectionSort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for(int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void run(void (*sort)(int [], int), int type)
{
    int sizes[] = {8000,12000,16000,20000,24000,28000,32000,36000};

    for(int i = 0; i < 8; i++)
    {
        int n = sizes[i];

        int arr[n];
        int temp[n];

        if(type == 1)
            generateRandom(arr, n);
        else if(type == 2)
            generateAscending(arr, n);
        else
            generateDescending(arr, n);

        memcpy(temp, arr, sizeof(arr));

        clock_t start = clock();

        sort(temp, n);

        clock_t end = clock();

        double t = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

        printf("%d %.2f ms\n", n, t);
    }
}

void run2(void (*sort)(int [], int, int), int type)
{
    int sizes[] = {8000,12000,16000,20000,24000,28000,32000,36000};

    for(int i = 0; i < 8; i++)
    {
        int n = sizes[i];

        int arr[n];
        int temp[n];

        if(type == 1)
            generateRandom(arr, n);
        else if(type == 2)
            generateAscending(arr, n);
        else
            generateDescending(arr, n);

        memcpy(temp, arr, sizeof(arr));

        clock_t start = clock();

        sort(temp, 0, n - 1);

        clock_t end = clock();

        double t = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

        printf("%d %.2f ms\n", n, t);
    }
}

int main()
{
    int ch;

    printf("1. Bubble\n");
    printf("2. Insertion\n");
    printf("3. Selection\n");
    printf("4. Quick\n");
    printf("5. Merge\n");
    printf("6. Heap\n");

    scanf("%d",&ch);

    if(ch==1)
    {
        printf("\nRandom\n");
        run(bubbleSort,1);

        printf("\nAscending\n");
        run(bubbleSort,2);

        printf("\nDescending\n");
        run(bubbleSort,3);
    }

    else if(ch==2)
    {
        printf("\nRandom\n");
        run(insertionSort,1);

        printf("\nAscending\n");
        run(insertionSort,2);

        printf("\nDescending\n");
        run(insertionSort,3);
    }

    else if(ch==3)
    {
        printf("\nRandom\n");
        run(selectionSort,1);

        printf("\nAscending\n");
        run(selectionSort,2);

        printf("\nDescending\n");
        run(selectionSort,3);
    }

    else if(ch==4)
    {
        printf("\nRandom\n");
        run2(quickSort,1);

        printf("\nAscending\n");
        run2(quickSort,2);

        printf("\nDescending\n");
        run2(quickSort,3);
    }

    else if(ch==5)
    {
        printf("\nRandom\n");
        run2(mergeSort,1);

        printf("\nAscending\n");
        run2(mergeSort,2);

        printf("\nDescending\n");
        run2(mergeSort,3);
    }

    else if(ch==6)
    {
        printf("\nRandom\n");
        run(heapSort,1);

        printf("\nAscending\n");
        run(heapSort,2);

        printf("\nDescending\n"); 
	run(heapSort,3);
    }
    return 0;
}
