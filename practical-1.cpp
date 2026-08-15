#include <iostream>
using namespace std;

// Bubble Sort
void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }

        swap(a[i], a[min]);
    }
}

// Merge function
void merge(int a[], int left, int mid, int right) {
    int temp[100];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= right)
        temp[k++] = a[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        a[i] = temp[k];
}

// Merge Sort
void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

// Quick Sort
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// Display array
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int a[100], n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nChoose Sorting Algorithm:\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Insertion Sort\n";
    cout << "3. Selection Sort\n";
    cout << "4. Merge Sort\n";
    cout << "5. Quick Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            bubbleSort(a, n);
            break;

        case 2:
            insertionSort(a, n);
            break;

        case 3:
            selectionSort(a, n);
            break;

        case 4:
            mergeSort(a, 0, n - 1);
            break;

        case 5:
            quickSort(a, 0, n - 1);
            break;

        default:
            cout << "Invalid choice!";
            return 0;
    }

    cout << "\nSorted Array: ";
    display(a, n);

    return 0;
}
