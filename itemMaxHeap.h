#pragma once
#include"user.h"

/*
same logic with userMaxHeap but in here we will not focus on userId but itemId so array will be sorted by itemIds
*/

void itemHeapify(user arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l].getItemId() > arr[largest].getItemId())
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r].getItemId()  > arr[largest].getItemId())
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        itemHeapify(arr, n, largest);
    }
}

// main function to do heap sort
void itemHeapSort(user arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        itemHeapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        itemHeapify(arr, i, 0);
    }
}

//                                                                         using items' ratings in the max heap
void itemRatingHeapify(user arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l].getItem_Number_of_ratings() > arr[largest].getItem_Number_of_ratings())
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r].getItem_Number_of_ratings()  > arr[largest].getItem_Number_of_ratings())
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        itemRatingHeapify(arr, n, largest);
    }
}

// main function to do heap sort
void itemRatingHeapSort(user arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        itemRatingHeapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        itemRatingHeapify(arr, i, 0);
    }
}


void printItem(user arr[], int n)
{
    std::cout << "itemId" << " " << "ratings" << " " << std::endl;

    int i = n - 1;

    int na = 9;

    while (i >= 0)
    {
        if (arr[i].getItemId() != -99)
        {
            if (na >= 0)
            {
                std::cout << arr[i].getItemId() << " " << arr[i].getItem_Number_of_ratings() << " ";
                std::cout << std::endl;
                na--;
            }

            else
            {
                break;
            }
        }
        i--;
    }
}

void itemMostRatings(user arr[])
{
    int const n = 1200000;
    user* arr2 = new user[8000];
    int arr2_i = 0;
    itemHeapSort(arr, n); //  1 to 10000000+ sorting
    int number = 1;
    arr[0].setItem_Number_of_ratings(number);
    for (int i = 0; i < n; i++) // collect same numbers
    {
        if (arr[i].getItemId() == arr[i + 1].getItemId())
        {
            number++;
        }

        else
        {
            arr[i].setItem_Number_of_ratings(number);
            arr2[arr2_i] = arr[i]; // create new data for most item
            if (arr2_i < 8000)
            {
                arr2_i++;
            }
            number = 1;
            arr[i].setItem_Number_of_ratings(number);
        }
    }
    itemRatingHeapSort(arr2, 8000); //  item that most rated by user
    printItem(arr2, 8000);
}

//--------------------------------------------------------------------------------------

/*
this for sort to the arrItem's array by using heap sort.
Aim is each user have array that rated films but this array will be sorted by itemIds
so that we can compare easily
*/
void intItemHeapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r]  > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        intItemHeapify(arr, n, largest);
    }
}

void intItemHeapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        intItemHeapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        intItemHeapify(arr, i, 0);
    }
}
