#pragma once
#include"user.h"

/*
The userHeapify function is a helper function for the userHeapSort function. It takes an array of user objects, the size of the array, and an index as input,
and rearranges the elements in the array to maintain the max heap property (i.e., the value of each parent node is greater than or equal to the values of its children).
The max heap property is maintained by swapping the values of the root node and the largest of its children if the value of the largest child is greater than the value of the root.
*/
void userHeapify(user arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l].getUserId() > arr[largest].getUserId())
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r].getUserId()  > arr[largest].getUserId())
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        userHeapify(arr, n, largest);
    }
}

/*
The userHeapSort function sorts an array of user objects by repeatedly calling the userHeapify function on the array and swapping the root
node with the last element in the array. This results in the largest element in the array being moved to the end, and the process is repeated on the remaining elements
until the array is sorted in descending order.
*/

// main function to do heap sort
void userHeapSort(user arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        userHeapify(arr, n, i);
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        userHeapify(arr, i, 0);
    }
}


/*
The userRatingHeapify and userRatingHeapSort functions work in a similar way, but they sort the user objects based on the value
of the user_number_of_ratings data member instead of the userId data member.
*/
//                                                                         using users' ratings in the max heap
void userRatingHeapify(user arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l].getUser_Number_of_ratings() > arr[largest].getUser_Number_of_ratings())
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r].getUser_Number_of_ratings()  > arr[largest].getUser_Number_of_ratings())
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        userRatingHeapify(arr, n, largest);
    }
}

// main function to do heap sort
void userRatingHeapSort(user arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        userRatingHeapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        userRatingHeapify(arr, i, 0);
    }
}


/*
The printUser function takes an array of user objects and the size of the array as input and prints the userId and
user_number_of_ratings values for the first 10 user objects in the array.
*/
void printUser(user arr[], int n)
{
    std::cout << "userId" << " " << "ratings" << " " << std::endl;

    int i = n - 1;

    int na = 9;

    while (i >= 0)
    {
        if (arr[i].getUserId() != -99)
        {
            if (na >= 0)
            {
                std::cout << arr[i].getUserId() << " " << arr[i].getUser_Number_of_ratings() << " ";
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

/*
the userMostRatings function takes an array of user as input and that array will be sorted by using Heap sort. In sorted array it will check for same ID's (for example : 0 0 0 0 1 1 1) 
and number (number in here represent the number of item that user rate) will be increase by one and it will goes til the next item is not equal.
*/
void userMostRatings(user arr[])
{
    int const n = 1200000;
    user* arr2 = new user[36000];
    int arr2_i = 0;
    userHeapSort(arr, n); //  1 to 10000000+ sorting

    int number = 1;
    arr[0].setUser_Number_of_ratings(number);
    for (int i = 0; i < n; i++) // collect same numbers
    {
        if (arr[i].getUserId() == arr[i + 1].getUserId())
        {
            number++;
        }

        else
        {
            arr[i].setUser_Number_of_ratings(number);
            arr2[arr2_i] = arr[i]; // create new data for most user
            //arr2[arr2_i].print(); 
            if (arr2_i < 36000)
            {
                arr2_i++;
            }
            number = 1;
            arr[i].setUser_Number_of_ratings(number);
        }
    }

    userRatingHeapSort(arr2, 36000); //  user that most rated films

    printUser(arr2, 36000);
}
