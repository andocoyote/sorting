#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int menu(); //displays the user menu, returns the menu selection
void displayArray(int numbers[], const int size);
void selectionSort(int numbers[], const int size, const bool showSorting);
void resetArray(int numbers[], const int size);

//begin main function
void main()
{
	unsigned int choice; //menu choice from user
	bool exit = false;	//user wants to exit program?
	const int size = 10;
	int numbers[size];
	char selection = 'n';
	bool showSorting = false;
	
	// Fill the array with random numbers between 1 and 100 inclusively
	resetArray(numbers, size);

	do //while (!exit)
	{
		choice = menu(); //display user menu and get selection

		switch(choice) //perform switch on choice from menu
		{
				//user wants to add a name to the list
		case 1: cout << "Here is the array:";
		
				displayArray(numbers, size);

				exit = false; 
				break;
				
		case 2: cout << "Do you want to show the sorting algorithm's work? (y/n): ";
				cin >> selection;
				
				if (selection == 'y')
				{
					showSorting = true;
				}
		
				cout << "Sorting the array with Selection Sort:" << endl;
		
				// Fill the array with random numbers between 0 and 100 inclusively
				resetArray(numbers, size);
				
				cout << "Inititial array:" << endl;
				displayArray(numbers, size);
	
				selectionSort(numbers, size, showSorting);
				
				cout << "Sorted array:" << endl;
				displayArray(numbers, size);

				//user wants to exit the program
		case 0: exit = true;
				break;
				
		default:
				break;
		}

	}while(!exit);//end do while loop for main program

}//end of main program

//-----------------------------------------------------------------------

//beginning of menu()
int menu()
{
	int selection; //holds the user's menu choice

	//display the menu
	cout << "Please choose from the following options" << endl;
	cout << "1.  Display the array" << endl;
	cout << "2.  Sort the array using Selection Sort" << endl;
	cout << "0.  Exit the program" << endl;
	cout << ": ";
	cin >> selection; //get the selection from the menu

	return selection; //return the selection to main program
}//end function menu()

//-----------------------------------------------------------------------

void resetArray(int numbers[], const int size)
{
	srand(unsigned(time(0)));
	
	for(int i = 0; i < size; i++)
	{
		numbers[i] = (rand() % 100) + 1;
	}
}

//-----------------------------------------------------------------------

void displayArray(int numbers[], const int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << numbers[i] << " ";
	}
	
	cout << endl;
}

//-----------------------------------------------------------------------

// Use selection sort to sort the array in descending order.
void selectionSort(int numbers[], const int size, const bool showSorting)
{
	int least = 0;
	int temp = 0;
	
	// Iterate through the array from end to beginning.
	// We're looking for the smallest number in the array to swap at the end of the array.
	// After each iteration, the array gets one number smaller, from our perspective
	// This outer loop (i) just controls the current size of our shrinking array
	for (int i = size-1; i > 0; i--)
	{
		least = 0;
		
		for (int j = 1; j <= i; j++)
		{
			// If the next number is less than our current 'least' number, we have a new 'least' number index
			// Keep iterating over the array until we find the 'least' number in the array
			if (numbers[j] < numbers[least])
			{
				least = j;
			}
		}
		
		// Swap the smallest number with the last number in the ever shortening array
		if (showSorting)
		{
			cout << "Swapping numbers[" << least << "]:" << numbers[least] << 
			" with numbers[" << i << "]:" << numbers[i] << endl;
		}
		
		temp = numbers[least];
		numbers[least] = numbers[i];
		numbers[i] = temp;
		
		// Show the array at each step of the user elected to do so.
		if (showSorting)
		{
			displayArray(numbers, size);
		}
	}
}
