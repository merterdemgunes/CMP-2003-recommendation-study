#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include"user.h"
#include"hashTable.h"
#include"userMaxHeap.h"
#include"itemMaxHeap.h"
#include"cosine.h"

using namespace std;

int main()
{
    string line;
    string users;
    string item;
    string rate;
    int userId;
    int itemId;
    double rating;

    ifstream myfile("C:\\Users\\mertg\\OneDrive\\Masaüstü\\PROJECT\\trainim.txt");
    int i = 5000;
    user* arr = new user[1200000];
    user* test = new user[5000];

    if (myfile.is_open())
    {
        getline(myfile, line);
        while (getline(myfile, line))
        {
            if (!line.empty())
            {
                stringstream ss(line);
                getline(ss, users, ',');
                getline(ss, item, ',');
                getline(ss, rate, ',');

                userId = stoi(users);
                itemId = stoi(item);
                rating = stod(rate);

                arr[i].setUserId(userId);
                arr[i].setItemId(itemId);
                arr[i].setRatings(rating);

                //arr[i].print();

                if (i < 1200000)
                {
                    i++;
                }
                else
                {
                    break;
                }
            }
        }
        myfile.close();
    }

    else cout << "Unable to open file";

    //---------------------------------------------

    ifstream myfile2("C:\\Users\\mertg\\OneDrive\\Masaüstü\\PROJECT\\trainim.txt");

    string index;
    int indexx;
    int a = 0;

    //cout << "userId  " << " itemId  " << endl;

    if (myfile2.is_open())
    {
        getline(myfile2, line);
        while (getline(myfile2, line))
        {
            if (!line.empty())
            {
                stringstream ss(line);
                getline(ss, users, ',');
                getline(ss, item, ',');
                getline(ss, rate, ',');

                userId = stoi(users);
                itemId = stoi(item);
                rating = stod(rate);

                test[a].setUserId(userId);
                test[a].setItemId(itemId);
                test[a].setRatings(rating);

                //test[a].print();

                if (a < 5000)
                {
                    a++;
                }
                else
                {
                    break;
                }
            }
        }
        myfile.close();
    }

    else cout << "Unable to open file";



    //-----------------------------------------

    //userMostRatings(arr); // top 10 user
    //itemMostRatings(arr); // top 10 movie

    cosine(arr, test);

    return 0;
}







//#include<iostream>
//#include<fstream>
//#include<string>
//#include <sstream>
//#include"user.h"
//#include"hashTable.h"
//#include"userMaxHeap.h"
//#include"itemMaxHeap.h"
//#include"cosine.h"
//
//using namespace std;
//
//int main()
//{
//    string line;
//    string users;
//    string item;
//    string rate;
//    int userId;
//    int itemId;
//    double rating;
//
//    ifstream myfile("C:\\Users\\mertg\\OneDrive\\Masaüstü\\PROJECT\\trainim.txt");
//    int i = 0;
//    user* arr = new user[1200000];
//    user* test = new user[5000];
// 
//    /*
//    The "trainim.txt" file contains information about users and the items they have rated. Each line in the file consists of 
//    three comma - separated values : a user ID, an item ID, and a rating given by the user to the item.These values are read in and stored in an array of user objects called "arr".
//    */
//
//    if (myfile.is_open())
//    {
//        getline(myfile, line);
//        while (getline(myfile, line))
//        {
//            if (!line.empty())
//            {
//                stringstream ss(line);
//                getline(ss, users, ',');
//                getline(ss, item, ',');
//                getline(ss, rate, ',');
//
//                userId = stoi(users);
//                itemId = stoi(item);
//                rating = stod(rate);
//
//                arr[i].setUserId(userId);
//                arr[i].setItemId(itemId);
//                arr[i].setRatings(rating);
//
//                //arr[i].print();
//
//                if (i < 1200000)
//                {
//                    i++;
//                }
//                else
//                {
//                    break;
//                }
//            }
//        }
//        myfile.close();
//    }
//
//    else cout << "Unable to open file";
//
//    //---------------------------------------------
// 
//    /* 
//    The "testim.txt" file also contains information about users and items, but it only includes the user and item IDs and 
//    not the ratings.This information is stored in an array of user objects called "test".
//    */
//   
//    ifstream myfile2("C:\\Users\\mertg\\OneDrive\\Masaüstü\\PROJECT\\testim.txt");
//
//    string index;
//    int indexx;
//    int a = 0;
//
//    //cout << "userId  " << " itemId  " << endl;
//
//    if (myfile2.is_open())
//    {
//        getline(myfile2, line);
//        while (getline(myfile2, line))
//        {
//            if (!line.empty())
//            {
//                stringstream ss(line);
//                getline(ss, index, ',');
//                getline(ss, users, ',');
//                getline(ss, item, ',');
//
//                indexx = stoi(index);
//                userId = stoi(users);
//                itemId = stoi(item);
//
//                test[a].setUserId(userId);
//                test[a].setItemId(itemId);
//                //test[a].setRatings(rating);
//
//                //test[a].print();
//
//                if (a < 5000)
//                {
//                    a++;
//                }
//                else
//                {
//                    break;
//                }
//            }
//        }
//        myfile.close();
//    }
//
//    else cout << "Unable to open file";
//
//    //-----------------------------------------
//
//    userMostRatings(arr); // top 10 user
//    itemMostRatings(arr); // top 10 movie
//
//    cosine(arr, test);
//
//   /*
//   Finally, the main function writes the recommended ratings to a file called "answer.csv". 
//   The file contains two columns : an ID columnand a Predicted column.The ID column contains the index of the item in the "test" array, and the Predicted column contains the recommended rating for that item.
//   */
// 
//    std::ofstream csv_file("C:\\Users\\mertg\\OneDrive\\Masaüstü\\PROJECT\\answer.csv");
//
//    csv_file << "ID,Predicted\n";
//
//    for (int i = 0; i < 5000; i++) {
//        csv_file << std::to_string(i) << "," << std::to_string(test[i].getRatings()) << "\n";
//    }
//
//    csv_file.close();
//
//
//
//    return 0;
//}





