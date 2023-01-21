#pragma once
#include<iostream>
#include<cassert>

using namespace std;

class user
{
private:
	int userId; //userId: an integer representing the user's ID
	int itemId; //itemId: an integer representing the ID of an item that the user has rated
	double ratings; //ratings: a double representing the rating that the user has given to the item
	int user_number_of_rating; //user_number_of_rating: an integer representing the number of ratings that the user has given
	int item_number_of_rating; //item_number_of_rating: an integer representing the number of ratings that the item has received
	int* arrItem; //arrItem: a pointer to an array of integers representing the IDs of items that the user has rated
	double* arrRating;//arrRating: a pointer to an array of doubles representing the ratings that the user has given to each item

	int mostUserId;//mostUserId: an integer representing the ID of the user who has the most similarity with
public:

	// A constructor, which initializes all data members to a default value
	user()
	{
		userId = -99; itemId = -99; ratings = -99; user_number_of_rating = -99; item_number_of_rating = -99; mostUserId = -99;
		arrItem = NULL; arrRating = NULL;
	}

	// A destructor, which deallocates the memory occupied by arrItem and arrRating
	~user()
	{
		delete[] arrItem;
		delete[] arrRating;
		//deallocate the memory occupied 
	}//end destructor

	// Setter functions for each of the data members, which allow the values of the data members to be set
	void setUserId(int userId) { this->userId = userId; }
	void setItemId(int itemId) { this->itemId = itemId; }
	void setRatings(double ratings) { this->ratings = ratings; }
	void setUser_Number_of_ratings(int user_number_of_rating) { this->user_number_of_rating = user_number_of_rating; }
	void setItem_Number_of_ratings(int item_number_of_rating) { this->item_number_of_rating = item_number_of_rating; }
	void setMostUserId(int mostUserId) { this->mostUserId = mostUserId; }

	
	// Getter functions for each of the data members, which allow the values of the data members to be retrieved
	int getMostUserId() { return mostUserId; }
	int getUserId() { return userId; }
	int getItemId() { return itemId; }
	double getRatings() { return ratings; }
	int getUser_Number_of_ratings() { return user_number_of_rating; }
	int getItem_Number_of_ratings() { return item_number_of_rating; }

	//getArrItem and setArrItem functions for accessing and setting the values in the arrRating array
	int getArrItem(int index) const
	{
		return this->arrItem[index];
	}

	void setArrItem(int* ptr)
	{
		this->arrItem = ptr;
	}

	void setArrItemValue(int index, int value)
	{
		this->arrItem[index] = value;
	}

	//getArrRating and setArrRating functions for accessing and setting the values in the arrRating array
	double getArrRating(int index) const
	{
		return this->arrRating[index];
	}

	void setArrRating(double* ptr)
	{
		this->arrRating = ptr;
	}

	void setArrRatingValue(int index, double value)
	{
		this->arrRating[index] = value;
	}

	//printArrItem function, which prints the values in the arrItem and arrRating arrays
	void printArrItem(int size)
	{
		for (int i = 0; i < size; i++)
		{
			if (this->getUserId() == -99) // 99 du tekrar bak
			{
				continue;
			}

			else
			{
				std::cout << i + 1 << ") " << this->getArrItem(i) << " " << this->getArrRating(i) << " ";
				std::cout << std::endl;
			}
		}
	}

	//print function, which prints the values of userId, itemId, and ratings
	void print() 
	{
		std::cout << this->getUserId() << " " << this->getItemId() << " " << this->getRatings() << std::endl;
	}

	int* getFullItemArray(int size)
	{
		return this->arrItem;
	}


	//copyUser function, which copies the data from one user object to another
	void copyUser(const user& otherUser)
	{
		this->userId = otherUser.userId;
		this->itemId = otherUser.itemId;
		this->ratings = otherUser.ratings;
		this->user_number_of_rating = otherUser.user_number_of_rating;
		this->item_number_of_rating = otherUser.item_number_of_rating;

		this->mostUserId = otherUser.mostUserId;

		this->arrItem = otherUser.arrItem;
		this->arrRating = otherUser.arrRating;
	} //end copyStack


	/* 
	The copyStack function is called by the copy constructor and the assignment operator (operator=) to perform the actual copying of data. 
	The copy constructor and assignment operator are used to create a new user object 
	that is a copy of an existing object, or to assign the values of one user object to another.
	*/
	user(const user& otherUser)
	{
		arrItem = NULL;
		arrRating = NULL;
		copyUser(otherUser);
	}//end copy constructor



	const user& operator=(const user& otherUser)
	{
		if (this != &otherUser) //avoid self-copy
			copyUser(otherUser);
		return *this;
	} //end operator=         


	/*
	The operator== function is the implementation of the equality operator (==) for the user class. 
	It compares two user objects and returns true if they are equal, and false if they are not equal. 
	It compares the values of the data members of the two objects to determine their equality.
	*/
	bool operator==(const user& otherUser) const
	{
		if (this == &otherUser)
			return true;

		else if (this->userId != otherUser.userId || this->itemId != otherUser.itemId || this->ratings != otherUser.ratings
			|| user_number_of_rating != otherUser.user_number_of_rating || this->item_number_of_rating != otherUser.item_number_of_rating || this->mostUserId != otherUser.mostUserId)
			return false;

		else
		{
			if (this->arrItem != otherUser.arrItem)
				return false;

			if (this->arrRating != otherUser.arrRating)
				return false;

			return true;
		}
	}
};

