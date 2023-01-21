## Explanation

In my code, I utilized a **Hash Table** and **Heap Sort**. The running time of my code is approximately 2 minutes and 45 seconds.

In my source code, I used ifstream to read the file and stringstream (from the sstream library) to separate the lines by comma. Then, I created two arrays, one for the training set and the other for the test set, to store the values. For the file writing part, I used ofstream to write the predicted ratings to the file.

I also created a user class, where each user has a userId, itemId, rating, user_number_of_rating, item_number_of_rating, arrItem pointer, arrRating pointer, and the mostUserId.

In my code, I created global variables that are a pointer indexStatusList and length. The hashTableStatus function helps me to initialize an array called indexStatusList to store the status of each index in the hash table. It also initializes a length variable to 0 and takes an integer as input, which represents the size of the hash table. Then, the manuelDeleteHashTableStatus function is a helper function that deallocates the memory occupied by indexStatusList. The insertUserId function takes an array of user objects, an integer representing the index in the hash table where the user object is to be inserted, the size of the hash table, and a constant reference to an integer as input. It attempts to insert the user object into the hash table at the specified index. If the index is already occupied by another user object or if the table is full, it displays an error message. If the insertion is successful, it increments the length variable.

I also created the searchUserId function that searches the hash table for a user object with a userId value that matches the input integer.

In userMaxHeap, the userHeapify function is a helper function for the userHeapSort function. It takes an array of user objects, the size of the array, and an index as input, and rearranges the elements in the array to maintain the max heap property. The userHeapSort function sorts an array of user objects by repeatedly calling the userHeapify function on the array and swapping the root node with the last element in the array. The userRatingHeapify and userRatingHeapSort functions work in a similar way, but they sort the user objects based on the value of the user_number_of_ratings data member instead of the userId data member.

In userMostRatings first I sorted the array that I stored the train set based on their userId then in for loop I created an if statement which looks for the same userId if they are the same then number will be increased by one then when for loop ends we will sort the array based on the number_of_ratings data member then we will print for the top 10 movies is the same but in itemMaxHeap as an extra I created one heapify and one heapsort based on the arrItem that user rated films we will sort that array for make the comparison easy and faster when we look for the similarity user to user.
