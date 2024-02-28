#include <stdio.h>
#include <time.h>

// Swap two elements
void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quicksort function
void quickSort(int arr[], int low, int high) 
{
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() 
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) 
    {
        //scanf("%d", &arr[i]);
        // BEST case
        arr[i]=i;
        // AVG case
        //arr[i]=rand()%100000;
        // WORST CASE
        //arr[i]=n-1;
    }

    clock_t start = clock(); // Start the clock

    quickSort(arr, 0, n - 1);

    clock_t end = clock(); // Stop the clock
    double runtime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Runtime: %lf seconds\n", runtime);

    return 0;
}