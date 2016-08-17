// Check10Numbers_IBMAug.cpp : Defines the entry point for the console application.
//

// Program that, given 10 numbers, checks if any 1, 2, or 3 numbers adds up to any combination of the rest.

#include "stdafx.h"
#include <iostream>
using namespace std;

// Given an array of 10 numbers, check if any 3 of the 10 add up to any of the others.
bool CheckSet(int set[10])
	{
	// 1 number: Check that no two numbers are the same.
	for (int i = 0; i < 9; i++)
		{ 
		for (int j = i + 1; j < 10; j++)
			{ 
			if(set[i] == set[j])
				{
				cout << "Set failed because " << set[i] << " at spot " << i << " is the same number as spot" << j << endl;
				return false;
				}
			}
		}
	
	// 2 numbers: No 2 numbers add up to any other number.
	for (int i = 0; i < 9; i++)
		{ 
		for (int j = i + 1; j < 10; j++)
			{ 
			// i and j are to check every 2 number combo.
			// k is to check every other number.
			for(int k = 0; k < 10; k++)
				{ 
				// We don't need to check it if i or j is equal to k. There are no negative numbers so i+j always > k
				if(i == k || j == k) { continue; }

				// Get the addition if i and j

				// Make sure i+j isn't equal to k
				if(set[i] + set[j] == set[k])
					{ 
					cout << "Set failed because " << set[i] << " and " << set[j] << " add up to " << set[k] << endl;
					return false;
					}

				}
			}
		}

	// 3 numbers: 
	for (int i = 0; i < 10 - 1 - 1; i++)
		{ 
		for (int j = i + 1; j < 10 - 1; j++)
			{ 
			for(int k = j + 1; k < 10; k++)
				{ 
				// i and j and k are to check every 3 number added combo.
				// m is to check every other number.
				for(int m = 0; m < 10; m++)
					{
					// We don't need to check it if i or j or k is equal to m. There are no negative numbers so i+j+k always > m
					if(i == m || j == m || k == m) { continue; }

					// Make sure i+j+k isn't equal to m
					if(set[i] + set[j] + set[k] == set[m])
						{ 
						cout << "Set failed because " << set[i] << " from " << i+1 << " and " << set[j] << " from " << j+1 << " and " << set[k] << " from " << k+1 << " add up to " << set[m] << " from " << m+1 << endl;
						return false;
						}
					}
				}
			}
		}
	return true;
	}

int main()
	{
	// Get 10 numbers from user input
	cout << "Enter your 10 numbers loser: " << endl;
	int set[10] = { 0 };

	for (int i = 0; i < 10; i++)
		{ cin >> set[i]; }

	bool shouldbreak = false;
	// Adjust the set by multiplying 3 numbers by 9 and rest by 10
	for(int i = 0; i < 8; i++) {
		for(int j = i+1; j < 9; j++) {
			for(int k = j+1; k < 10; k++ ) {

				// Adjust the numbers. 
				for(int m = 0; m < 10; m++)
					{ 
					if(m == i || m == j || m == k) { set[m] *= 9; }
					else {set[m] *= 10; }
					}

				// Call function to check if any 1, 2, or 3 of these 10 numbers adds up to any combination of the rest.
				if(CheckSet(set) == false) { shouldbreak = true; };

				// Adjust the numbers back
				for(int m = 0; m < 10; m++)
					{ 
					if(m == i || m == j || m == k) { set[m] /= 9; }
					else {set[m] /= 10; }
					}
				if(shouldbreak == true) {break;}
		} if(shouldbreak == true) {break;} } if(shouldbreak == true) {break;} }

	if(shouldbreak == false)
		{ cout << "This set is a winner!" << endl; }

	cout << "Program ended." << endl;

	char zzz;
	cin >> zzz;
    return 0;
	}

