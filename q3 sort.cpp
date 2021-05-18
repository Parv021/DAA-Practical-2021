
#include <stdio.h>
#include <iostream>

using namespace std;


int numcount = 0;


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            numcount++;
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            numcount++;
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            numcount++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            numcount++;
            i++;
        }
        else
        {
            arr[k] = R[j];
            numcount++;
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        numcount++;
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void menu()
{
    cout << "\nOPTIONS\n\n";
    cout << "1.Bubble Sort\n";
    cout << "2.Selection Sort\n";
    cout << "3.Insertion Sort\n";
    cout << "4.Merge Sort\n";
    cout << "5.Quick Sort\n";
    cout << "Press 6 to exit\n";
}

int main()
{
    int arr[50];
    int n;
    int choice;
    printf("Enter the size: ");
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter element number " << i+1<< ": ";
        cin >> arr[i];
    }
    menu();
    cout << "Enter your choice: ";
    cin >> choice;
    printf("\nInitial array: ");
    printArray(arr, n);
    switch(choice){
        case 1:
            printf("Bubble Sort\n");
            bubbleSort(arr, n);
            break;
        case 2:
            printf("Selection Sort\n");
            selectionSort(arr,n);
            break;
        case 3:
            printf(" Insertion Sort\n");
            insertionSort(arr,n);
            break;
        case 4:
            printf(" Merge Sort\n");
            mergeSort(arr, 0, n - 1);
            break;
        case 5:
            printf(" Quick Sort\n");
            quickSort(arr, 0, n - 1);
            break;
        default:
            cout<<"error in choice!";
    }
    printf("Sorted array: ");
    printArray(arr, n);
    cout<<"Number of Comparisons: "<<numcount;
    return 0;
}


