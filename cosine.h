#pragma once
#include"userMaxHeap.h"

// hash function for to hashIndex 
int hashFunc(int num)
{
    return num % 35953;
}

//it is a helper function for printUserSearch when it is called user's items that user rated will be printed
void printItem_Rating(user u, int size)
{
    u.printArrItem(size);
}

// first search user in the array if it is true then print the user's items that user rated
void printUserSearch(user arr[], int userId)
{
    int key;
    bool found;
    key = hashFunc(userId);

    searchUserId(arr, key, 36000, arr[key].getUserId(), found);

    if (found)
    {
        std::cout << "userId : " << arr[key].getUserId() << " " << std::endl;
        std::cout << "itemId : " << std::endl;
        printItem_Rating(arr[key], arr[key].getUser_Number_of_ratings());
    }
    else
        std::cout << "Item not in the list." << std::endl;
}


//comparsion function helps compare every test set' user with 36000 user
void comparison(user arr2[], user arr[])
{
    double tempNum = 0; // temp variable for rNum
    double tempDen = 0; // temp variable for rDen

    int ab = 0; // ab is for when rating is 0 it will increased by one

    int sumIndF = 0; // Ind of test's user which is all number of rating without 0
    int sumIndS = 0; // Ind of 36000 array's user which is all number of rating without 0

    double sum_of_RU = 0; // test user's sum of all ratings 
    int isSameUser = 0; // for make the while loop faster because it helps when calculated it will be no calculation untill the next user 
    double r_RU = 0; // test user's mean centered value
    double sum_of_SU = 0;// 36000 array user's sum of all ratings 
    int isSameUser2 = 0; // for make the while loop faster because it helps when calculated it will be no calculation untill the next user 
    double r_SU = 0; // 36000 array user's mean centered value
    double x = 0; // new rating value which is uptaded by mean centered value
    double y = 0; // new rating value which is uptaded by mean centered value

    double multN = 0; //Mean-centered overlapping-item cosine similarity's numerator
    double squF = 0; //Mean-centered overlapping-item cosine similarity's denominator of the test user
    double squS = 0; //Mean-centered overlapping-item cosine similarity's denominator of the 36000 array user
    double result = 0; // result for the cosine

    double result_of_rmse = 0; // result_of_rmse is the predicted rating
    double rNum = 0; // rNum represents the result_of_rmse's numerator
    double rDen = 0; // rDen represents the result_of_rmse's denominator

    int rmseInd = 1; // rmseInd is for denominator for the rmse it will be 5000 in the end
    double rmse = 0; // rmse is the final score
    double den = 0; // den represents for numerator for rmse
    double exact = 0; // I used this for the data that I create to find the rmse and this is true rating
    double predicted = 0; // I used this for the data that I create to find the rmse and it is predicted rating

    int sameItemInd = 0; // sameItemInd helps me to find rating in the item array that user rated
    int tempItemInd = 0; // tempItemInd is will be assigned to the sameItemInd for the rNum
    int itemIndd = 0; // itemIndd is will be assigned to the tempItemInd

    int similarItemNumber = 0; // similarItemNumber will be increased by one when both users have the same item

    int key; // key is the index for the hash table array
    int ind = 0; // for the test set's index
    int arrItemInd = 0; // arrItemInd is the index for the the test set's items array that user's rated
    int arr2ItemInd = 0; // arr2ItemInd is the index for the the test set's items array that user's rated
    int ind2 = 1; // ind2 is index for the 36000 user array that it sorted and used hash table

    int isSameItem = 0; // it checks if the user watch the film or not watch the film as the user that it is trying to predict the rating

    /*
     while loop helps the comparison for every user that in test set with 36000 user array
    */
    while (ind < 5000)
    {
        key = hashFunc(arr[ind].getUserId());

        if (key != arr2[ind2].getUserId())
        {
            if (arr2[ind2].getUserId() != -99)
            {
                if (isSameItem == 0) // for the make timing result faster if already isSameItem is equal to 1 then no need to check again know that user watch that item that want to find user's rating
                {
                    itemIndd = 0;
                    while (itemIndd < arr2[ind2].getUser_Number_of_ratings())
                    {
                        if (arr2[ind2].getArrItem(itemIndd) == arr[ind].getItemId())
                        {
                            isSameItem = 1;
                            tempItemInd = itemIndd;

                            itemIndd = 0;
                            break; // when it is found get out the loop
                        }

                        else
                        {
                            itemIndd++;
                        }
                    }
                }

                if (isSameItem == 1) // if user watch the film know it will go for cosine to check to similarity then take the rating
                {
                    if (isSameUser == 0) // if isSameUser is equal to 0 it means it is not calculated
                    {
                        isSameUser = 1; // when calcualted uptaded value 1 so untill next user it will not calculated again so it will save time

                        for (int i = 0; i < arr2[key].getUser_Number_of_ratings(); i++) // for loop for sum of rating
                        {
                            if (arr2[key].getArrRating(i) == 0) // in Mean-centered overlapping-item cosine similarity it will not count 0 so if every time this statement true ab will be increased by one
                            {
                                ab++;
                            }
                            sum_of_RU = sum_of_RU + arr2[key].getArrRating(i); // sum of rating equation
                        }
                        sumIndF = arr2[key].getUser_Number_of_ratings() - ab; // it will decrease 0s from total number of rating
                        ab = 0; // reset the ab
                    }


                    if (isSameUser2 == 0) // if isSameUser2 is equal to 0 it means it is not calculated
                    {
                        isSameUser2 = 1;// when calcualted uptaded value 1 so untill next user it will not calculated again so it will save time

                        for (int i = 0; i < arr2[ind2].getUser_Number_of_ratings(); i++) // in Mean-centered overlapping-item cosine similarity it will not count 0 so if every time this statement true ab will be increased by one
                        {
                            if (arr2[ind2].getArrRating(i) == 0)
                            {
                                ab++;
                            }
                            sum_of_SU = sum_of_SU + arr2[ind2].getArrRating(i);// sum of rating equation
                        }

                        sumIndS = arr2[ind2].getUser_Number_of_ratings() - ab; // it will decrease 0s from total number of rating
                        ab = 0; // reset the ab
                    }

                    if (arr2[ind2].getArrItem(arr2ItemInd) <= arr2[key].getArrItem(arrItemInd)) // this helps to running time because it has already sorted the array that user rated the items
                    {
                        if (arr2[ind2].getArrItem(arr2ItemInd) != arr2[key].getArrItem(arrItemInd)) // checks if the items are the same
                        {
                            if (arr2ItemInd < arr2[ind2].getUser_Number_of_ratings() - 1) // this is for the arr2ItemInd index for the not exceed the array size which is that user's items array size which user rated 
                            {
                                arr2ItemInd++;
                            }
                            else
                            {
                                if (ind2 < 36000 - 1) // this is for the ind2 index for the not exceed the array size which is 36000
                                {
                                    sameItemInd = tempItemInd; // assign the tempItemInd to sameItemInd

                                    /*
                                     in this if statement don't care the 0 ratings and only look for positive similarity (in Mean-centered overlapping-item cosine similarity it can be negative it means different from the user)
                                     tempNum and tempDen is for when predicted rating (predicted rating calculated with mean weighted by their similarity to me)is exceed the range of rating which is 0 or 5
                                     don't include that because it can be happen in Mean-centered overlapping-item cosine similarity if it is not continue the calculation
                                    */
                                    if (arr2[key].getArrRating(arrItemInd) != 0 && arr2[ind2].getArrRating(arr2ItemInd) != 0 && 0 < result)
                                    {
                                        tempNum = rNum;
                                        tempDen = rDen;

                                        rNum += result * arr2[ind2].getArrRating(sameItemInd);
                                        rDen += result;

                                        if ((0 > rNum / rDen || rNum / rDen > 5))
                                        {
                                            rNum = tempNum;
                                            rDen = tempDen;
                                        }
                                    }

                                    // when it move the next user it will restart the variables
                                    isSameItem = 0;
                                    similarItemNumber = 0;
                                    result = 0;
                                    multN = 0;
                                    squF = 0;
                                    squS = 0;
                                    ind2++;
                                    arr2ItemInd = 0;
                                    arrItemInd = 0;

                                    sumIndS = 0;

                                    sum_of_SU = 0;
                                    isSameUser2 = 0;
                                    x = 0;
                                    y = 0;
                                }
                            }
                        }
                        else // users' items are the same...
                        {
                            // calculation for Mean-centered overlapping-item cosine similarity

                            if (arr2[key].getArrRating(arrItemInd) != 0 && arr2[ind2].getArrRating(arr2ItemInd) != 0) // dont care 0 ratings
                            {
                                x = arr2[key].getArrRating(arrItemInd); // get the rating of the test user
                                y = arr2[ind2].getArrRating(arr2ItemInd); // get the rating of the 36000 array user

                                r_RU = sum_of_RU / sumIndF; // calculated mean center
                                r_SU = sum_of_SU / sumIndS; // calculated mean center

                                x = x - r_RU; // each rating updated by substracting by their mean center value
                                y = y - r_SU; // each rating updated by substracting by their mean center value

                                if (x != 0 && y != 0) // don't care 0 rating which is updated rating
                                {
                                    multN = multN + (x * y); // numerator is sum of the test user's updated rating value multipled by 36000 array user's updated rating value
                                    squF = squF + (x * x); // denominator of test user is sum of the square of updated rating value
                                    squS = squS + (y * y); // denominator of 36000 array user is sum of the square of updated rating value

                                    result = multN / sqrt(squF * squS); // then Mean-centered overlapping-item cosine similarity's result is calculated by numerator divided by square root of denominator's mulptily
                                }
                            }

                            if (arr2ItemInd < arr2[ind2].getUser_Number_of_ratings() - 1 && arrItemInd < arr2[key].getUser_Number_of_ratings() - 1) // this is for the arr2ItemInd and arrItemInd indexes for the not exceed 
                            {                                                                                                                       //the array size which is that user's items array size which user rated 
                                arr2ItemInd++;
                                arrItemInd++;
                            }

                            else
                            {

                                if (ind2 < 36000 - 1)// this is for the ind2 index for the not exceed the array size which is 36000
                                {
                                    sameItemInd = tempItemInd; // assign the tempItemInd to sameItemInd


                                    /*
                                     in this if statement don't care the 0 ratings and only look for positive similarity (in Mean-centered overlapping-item cosine similarity it can be negative it means different from the user)
                                     tempNum and tempDen is for when predicted rating (predicted rating calculated with mean weighted by their similarity to me)is exceed the range of rating which is 0 or 5
                                     don't include that because it can be happen in Mean-centered overlapping-item cosine similarity if it is not continue the calculation
                                    */
                                    if (arr2[key].getArrRating(arrItemInd) != 0 && arr2[ind2].getArrRating(arr2ItemInd) != 0 && 0 < result) // 1.011 geldi
                                    {
                                        tempNum = rNum;
                                        tempDen = rDen;

                                        rNum += result * arr2[ind2].getArrRating(sameItemInd);
                                        rDen += result;

                                        if ((0 > rNum / rDen || rNum / rDen > 5))
                                        {
                                            rNum = tempNum;
                                            rDen = tempDen;
                                        }
                                    }


                                    // when it move the next user it will restart the variables
                                    isSameItem = 0;
                                    similarItemNumber = 0;
                                    result = 0;
                                    multN = 0;
                                    squF = 0;
                                    squS = 0;
                                    ind2++;
                                    arr2ItemInd = 0;
                                    arrItemInd = 0;

                                    sumIndS = 0;

                                    sum_of_SU = 0;
                                    isSameUser2 = 0;
                                    x = 0;
                                    y = 0;
                                }

                            }
                        }
                    }
                    else // second user's itemId is bigger than first user's itemId means that there is no need to go because no chance to find the same itemId after already bigger than present itemId
                    {
                        if (arrItemInd < arr2[key].getUser_Number_of_ratings() - 1) // this is for the arr2ItemInd index for the not exceed the array size which is that user's items array size which user rated
                        {
                            arrItemInd++;
                        }
                        else
                        {
                            if (arr2ItemInd < arr2[ind2].getUser_Number_of_ratings() - 1) // this is for the arr2ItemInd index for the not exceed the array size which is that user's items array size which user rated 
                            {
                                arr2ItemInd++;
                            }

                            if (ind2 < 36000 - 1)
                            {
                                sameItemInd = tempItemInd; // assign the tempItemInd to sameItemInd

                                /*
                                 in this if statement don't care the 0 ratings and only look for positive similarity (in Mean-centered overlapping-item cosine similarity it can be negative it means different from the user)
                                 tempNum and tempDen is for when predicted rating (predicted rating calculated with mean weighted by their similarity to me)is exceed the range of rating which is 0 or 5
                                 don't include that because it can be happen in Mean-centered overlapping-item cosine similarity if it is not continue the calculation
                                */
                                if (arr2[key].getArrRating(arrItemInd) != 0 && arr2[ind2].getArrRating(arr2ItemInd) != 0 && 0 < result) // 1.011 geldi
                                {
                                    tempNum = rNum;
                                    tempDen = rDen;

                                    rNum += result * arr2[ind2].getArrRating(sameItemInd);
                                    rDen += result;

                                    if ((0 > rNum / rDen || rNum / rDen > 5))
                                    {
                                        rNum = tempNum;
                                        rDen = tempDen;
                                    }
                                }

                                // when it move the next user it will restart the variables
                                isSameItem = 0;
                                similarItemNumber = 0;
                                result = 0;
                                multN = 0;
                                squF = 0;
                                squS = 0;
                                ind2++;
                                arr2ItemInd = 0;
                                arrItemInd = 0;

                                sumIndS = 0;

                                sum_of_SU = 0;
                                isSameUser2 = 0;
                                x = 0;
                                y = 0;
                            }
                        }
                    }
                }
                else // isSameItem == 0
                {
                    // when it move the next user it will restart the variables

                    sum_of_SU = 0;
                    isSameUser2 = 0;
                    x = 0;
                    y = 0;

                    sumIndS = 0;

                    isSameItem = 0;
                    similarItemNumber = 0;
                    result = 0;
                    multN = 0;
                    squF = 0;
                    squS = 0;
                    ind2++;
                    arr2ItemInd = 0;
                    arrItemInd = 0;
                }
            }
            else // userId == -99
            {
                if (ind2 < 36000 - 1)
                {
                    // when it move the next user it will restart the variables

                    sum_of_SU = 0;
                    isSameUser2 = 0;
                    x = 0;
                    y = 0;

                    sumIndS = 0;

                    isSameItem = 0;
                    similarItemNumber = 0;
                    result = 0;
                    multN = 0;
                    squF = 0;
                    squS = 0;
                    ind2++;
                    arr2ItemInd = 0;
                    arrItemInd = 0;
                }

                else // if 36000 user have been chekeced than go to other test set user
                {
                    // calculations for the rmse
                    if (rNum == 0 && rDen == 0) // if user rated all films 0 or same rating number we can't say anything in this similarity so fix that ý used this automatically set the rating 3
                    {
                        result_of_rmse = 3;
                    }

                    else
                    {
                        result_of_rmse = rNum / rDen;
                    }

                    exact = arr[ind].getRatings();
                    arr[ind].setRatings(result_of_rmse);
                    predicted = arr[ind].getRatings();
                    den = den + (((exact - predicted) * (exact - predicted)));
                    rmse = sqrt(den / rmseInd);

                    cout << "ind : " << ind << endl;
                    //cout << "exact : " << exact << endl;
                    //cout << "predicted : " << predicted << endl;
                    //cout << "rmse : " <<  rmse << endl;

                    // when it move the next user it will restart the variables 
                    // but here notices ind will be increased this time because all 36000 user have been checked by the user

                    ind++;

                    sum_of_RU = 0;
                    sum_of_SU = 0;
                    isSameUser2 = 0;
                    isSameUser = 0;
                    x = 0;
                    y = 0;

                    sumIndS = 0;
                    sumIndF = 0;

                    ind2 = 0;
                    arr2ItemInd = 0;
                    arrItemInd = 0;

                    rmseInd++;
                    rNum = 0;
                    rDen = 0;
                    result_of_rmse = 0;
                    exact = 0;
                    predicted = 0;
                    isSameItem = 0;
                    similarItemNumber = 0;
                    sameItemInd = 0;
                    multN = 0;
                    squF = 0;
                    squS = 0;
                    result = 0;
                }
            }
        } //key == userId
        else
        {
            // when it move the next user it will restart the variables
            isSameItem = 0;
            similarItemNumber = 0;
            result = 0;
            multN = 0;
            squF = 0;
            squS = 0;
            ind2++;
            arr2ItemInd = 0;
            arrItemInd = 0;

            sumIndS = 0;

            sum_of_SU = 0;
            isSameUser2 = 0;
            x = 0;
            y = 0;
        }
    }

    //it cout the result final score
    if (rmse > 1.5)
    {
        std::cout << "for rmse you should put the true values in test set..." << std::endl;
    }

    else
    {
        std::cout << "rmse : " << rmse << std::endl;
    }
}




void cosine(user* arr, user* test)
{
    int const n = 1200000;
    int number;
    userHeapSort(arr, n); //  1 to 10000000 sorting
    user* arr2 = new user[36000]; // I create size of 36000 user array for users
    user* temp = new user[36000]; // I create temp array for the synchronization of the arrItem and arrRating
    int* itemArray = new int[NULL]; // this pointer helps me to create item array that user rated for each user
    double* ratingArray = new double[NULL]; // this pointer helps me to create rating array for each user
    int index; // index is for hash table index to determine hashIndex

    //-----------------------------------------------------------

    //I used hash table for arr2 array by looking user's userId
    hashTableStatus(36000); // index status array will be created for hash table
    for (int i = 0; i < n; i++) // set to hash table for userId
    {
        if (arr[i].getUserId() != -99)
        {
            if (arr[i].getUserId() != arr[i + 1].getUserId())
            {
                index = hashFunc(arr[i].getUserId());
                insertUserId(arr2, index, 36000, arr[i].getUserId());
            }
        }
    }
    manuelDeleteHashTableStatus();// index status array manually destoryed

    number = 1;

    for (int i = 0; i < n; i++) // for loop for the set the number of rating for each user
    {
        if (arr[i].getUserId() != -99)
        {
            if (arr[i].getUserId() == arr[i + 1].getUserId())
            {
                number++;
            }

            else
            {
                index = hashFunc(arr[i].getUserId());
                arr[i].setUser_Number_of_ratings(number);
                arr2[index] = arr[i]; 
                //arr2[index].print();

                number = 1;
                arr[i].setUser_Number_of_ratings(number);
            }
        }
    }

    for (int i = 0; i < n; i++) // initialization of the item array that user rated and rating array for user's items
    {
        if (arr[i].getUserId() != -99)
        {
            if (arr[i].getUserId() != arr[i + 1].getUserId())
            {
                index = hashFunc(arr[i].getUserId());
                itemArray = new int[arr2[index].getUser_Number_of_ratings()]; // array size will be assign by user's number of rating
                ratingArray = new double[arr2[index].getUser_Number_of_ratings()]; // array size will be assign by user's number of rating

                arr2[index].setArrItem(itemArray);
                arr2[index].setArrRating(ratingArray);

                itemArray = nullptr; //stops to point to the array and then only the user's arrýtem pointer points to that array
                ratingArray = nullptr; //stops to point to the array and then only the user's arrRating pointer points to that array
            }
        }
    }

    number = 0;

    for (int i = 0; i < n; i++) // we set the items and items' ratings in these two array arrItem and arrRating 
    {
        if (arr[i].getUserId() != -99)
        {
            if (arr[i].getUserId() == arr[i + 1].getUserId())
            {
                index = hashFunc(arr[i].getUserId());
                arr2[index].setArrItemValue(number, arr[i].getItemId());
                arr2[index].setArrRatingValue(number, arr[i].getRatings());
                number++;
            }

            else
            {
                index = hashFunc(arr[i].getUserId());
                arr2[index].setArrItemValue(number, arr[i].getItemId());
                arr2[index].setArrRatingValue(number, arr[i].getRatings());
                intItemHeapSort(arr2[index].getFullItemArray(arr2[index].getUser_Number_of_ratings()), arr2[index].getUser_Number_of_ratings()); // item array that user rated will be sorted
                number = 0;
            }
        }
    }

    //-----------------------------------------------------------------------------------------------------------

    //I used hash table for temp array by looking user's userId I did this because synchronization was not match with arrItem with arrRating
    hashTableStatus(36000); // index status array will be created for hash table
    for (int i = 0; i < n; i++) // set to hash table for userId
    {
        if (arr[i].getUserId() != -99)
        {
            if (arr[i].getUserId() != arr[i + 1].getUserId())
            {
                index = hashFunc(arr[i].getUserId());
                insertUserId(temp, index, 36000, arr[i].getUserId());
            }
        }
    }
    manuelDeleteHashTableStatus();// index status array manually destoryed

    for (int i = 0; i < n; i++) // for the temp array initialization of the item array that user rated and rating array for user's items
    {
        if (arr[i].getUserId() != -99)
        {
            if (arr[i].getUserId() != arr[i + 1].getUserId())
            {
                index = hashFunc(arr[i].getUserId());
                itemArray = new int[arr2[index].getUser_Number_of_ratings()];
                ratingArray = new double[arr2[index].getUser_Number_of_ratings()];

                temp[index].setArrItem(itemArray);
                temp[index].setArrRating(ratingArray);

                itemArray = nullptr;
                ratingArray = nullptr;
            }
        }
    }


    number = 0; // set the values in the array

    for (int i = 0; i < n; i++) // for the temp item array set the items and items' ratings in these two array arrItem and arrRating 
    {
        if (arr[i].getUserId() != -99)
        {
            if (arr[i].getUserId() == arr[i + 1].getUserId())
            {
                index = hashFunc(arr[i].getUserId());
                temp[index].setArrItemValue(number, arr[i].getItemId());
                temp[index].setArrRatingValue(number, arr[i].getRatings());
                number++;
            }

            else
            {
                index = hashFunc(arr[i].getUserId());
                temp[index].setArrItemValue(number, arr[i].getItemId());
                temp[index].setArrRatingValue(number, arr[i].getRatings());
                number = 0;
            }
        }
    }
    //--------------------------------------------------------------------------------------------------------------

    int ind = 0;
    int tempItemInd = 0;
    int arr2ItemInd = 0;

    // while loop for the match the item and item's rating
    while (ind < 36000)
    {
        if (arr2[ind].getUserId() != -99)
        {
            if (arr2[ind].getArrItem(arr2ItemInd) != temp[ind].getArrItem(tempItemInd)) // checks if items are the same
            {
                if (tempItemInd <= arr2[ind].getUser_Number_of_ratings())  // this is for the tempItemInd index for the not exceed the array size which is that user's items array size which user rated
                {
                    tempItemInd++;
                }
            }

            else // if the items are the same
            {
                arr2[ind].setArrRatingValue(arr2ItemInd, temp[ind].getArrRating(tempItemInd)); // set the rating that index for the synchronization

                if (arr2ItemInd <= arr2[ind].getUser_Number_of_ratings())  // this is for the arr2ItemInd index for the not exceed the array size which is that user's items array size which user rated
                {
                    arr2ItemInd++;
                }

                if (arr2ItemInd == arr2[ind].getUser_Number_of_ratings() - 1)  // if arr2ItemInd reaches the maximum size of the array than go next to item
                {
                    ind++;
                    arr2ItemInd = 0;
                }

                tempItemInd = 0; // reset the variable
            }
        }

        else // userId == -99 means that there is no user there so skip that part go to the next one
        {
            ind++;
        }
    }

    //----------------------------------------------------------------------------
    comparison(arr2, test); // we called comparison function to compare 36000 user which is arr2 and test array which is array that stored test set


    // I used these two(for loop and printUserSearch function) for the see my mistakes while coding
   
    //printUserSearch(arr2, 225);
        
    //for (int i = 0; i < n; i++) // print the array
    //{
    //    if (arr[i].getUserId() != -99)
    //    {
    //        if (arr[i].getUserId() != arr[i + 1].getUserId())
    //        {
    //            index = hashFunc(arr[i].getUserId());
    //            if (arr2[index].getUserId() != -99)
    //            {
    //                cout << index << ") userId :                            " << arr2[index].getUserId() << " " << endl;
    //                cout << "itemId : " << endl;

    //                printItem_Rating(arr2[index], arr2[index].getUser_Number_of_ratings());
    //            }
    //        }
    //    }
    //}
}