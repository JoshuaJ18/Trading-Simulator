#include <iostream>;
using namespace std;
#include <string>;
#include <cstdlib>;


class Trading {
public:
	int day;
	int totalMoney;
	int option;

	int stockOne;
	int stockTwo;
	int stockThree;
	int stockFour;

	int stockOnePast;
	int stockTwoPast;
	int stockThreePast;
	int stockFourPast;

	int stockOneShares;
	int stockTwoShares;
	int stockThreeShares;
	int stockFourShares;

// Functions of the Trading Class:

/* 
* The "Start" function assigns each stock with a random number, sets the day to 0, personal money to $200, and shares to 0.
* This function is meant to be used only once at the start of the program
*/
public:
	void start() {
		totalMoney = 200;
		day = 0;

		srand(time(NULL));
		stockOne = rand()%(600+1)+200;
		stockTwo = rand() % (70 + 1) + 30;
		stockThree = rand() % (100 + 1) + 100;
		stockFour = rand() % (20 + 1) + 1;

		stockOneShares = 0;
		stockTwoShares = 0;
		stockThreeShares = 0;
		stockFourShares = 0;
	}

// The "Header" function will be used throughout the program to display the header
public: 
	void header() {
		cout << "-------------------------------------------------------------------"<< endl;
		cout << "-------------------------------------------------------------------" << endl;
		cout << "			Trading Simulator" << endl;
		cout << "-------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------------------------" << endl;
	}
// The firstDisplay() function will be the first display of the program
public:
	void firstDisplay() {
		system("CLS");
		header();
		cout << "" << endl;
		cout << "	Day: " << day << endl;
		cout << "	Stock 1: $" << stockOne << endl;
		cout << "	Stock 2: $" << stockTwo << endl;
		cout << "	Stock 3: $" << stockThree << endl;
		cout << "	Stock 4: $" << stockFour << endl;
		cout << "" << endl;
		
		cout << "	Your Money: $" << totalMoney << endl;
		cout << "" << endl;
		cout << "" << endl;

		cout << "Choose an option:" << endl;
		cout << "1: Buy a stock" << endl;
		cout << "2: Sell a stock" << endl;
		cout << "3: Hold your current assets and advance to the next day" << endl;
		cout << "4: EXIT PROGRAM" << endl;
		cout << "Enter a number: ";
		cin>>option;

		options(option);


	}
// The dailyDisplay() function replaces the firstDisplay() function after an operation is performed by the user
public:
	void dailyDisplay() {
		system("CLS");
		header();

		cout << "" << endl;
		cout << "Day: " << day << endl;
		cout << "	Stock 1: " << " was: $"<< stockOnePast <<" now: $" << stockOne << endl;
		cout << "	Stock 2: " << " was: $" << stockTwoPast << " now: $" << stockTwo << endl;
		cout << "	Stock 3: " << " was: $" << stockThreePast << " now: $" << stockThree << endl;
		cout << "	Stock 4: " << " was: $" << stockFourPast << " now: $" << stockFour << endl;
		cout << "" << endl;

		cout << "Your Money: $" << totalMoney << endl;
		cout << "	Your Shares:" << endl;
		cout << "		Shares of Stock 1: " << stockOneShares << endl;
		cout << "		Shares of Stock 2: " << stockTwoShares << endl;
		cout << "		Shares of Stock 3: " << stockThreeShares << endl;
		cout << "		Shares of Stock 4: " << stockFourShares << endl;
		cout << "" << endl;
		cout << "" << endl;

		cout << "Choose an option:" << endl;
		cout << "1: Buy a stock" << endl;
		cout << "2: Sell a stock" << endl;
		cout << "3: Hold your current assets and advance to the next day" << endl;
		cout << "4: EXIT PROGRAM" << endl;
		cout << "Enter a number: ";
		cin >> option;

		options(option);
	}
// the optionOne() function allows the user to buy stocks
public:
	void optionOne() {
		int stockChoice;
		cout << "Which stock would you like to buy?" << endl;
		cout << "Enter a number:";
		cin >> stockChoice;
		switch (stockChoice) {
			case 1:
				if (totalMoney > stockOne) {
					totalMoney -= stockOne;
					stockOneShares += 1;
					break;
				}
				else {
					cout << "You do not have enough money to buy that stock...";
					break;
				}
			case 2:
				if (totalMoney > stockTwo) {
					totalMoney -= stockTwo;
					stockTwoShares += 1;
					break;
				}
				else {
					cout << "You do not have enough money to buy that stock...";
					break;
				}
			case 3:
				if (totalMoney > stockThree) {
					totalMoney -= stockThree;
					stockThreeShares += 1;
					break;
				}
				else {
					cout << "You do not have enough money to buy that stock...";
					break;
				}
			case 4:
				if (totalMoney > stockFour) {
					totalMoney -= stockFour;
					stockFourShares += 1;
					break;
				}
				else {
					cout << "You do not have enough money to buy that stock...";
					break;
				}
			default:
				cout << "That is not a valid choice, please enter the number of one of the stocks";
				optionOne();
		}
		system("CLS");
		dailyDisplay();
	}
// the optionTwo() function allows the user to sell stocks
public:
	void optionTwo() {
		int stockChoice;
		cout << "Which stock would you like to sell?" << endl;
		cout << "Enter a number: ";
		cin >> stockChoice;

		switch (stockChoice) {
			case 1:
				if (stockOneShares > 0) {
					totalMoney += stockOne;
					stockOneShares -= 1;
				} else {
					cout << "You do not have enough of that stock to sell..." << endl;
					dailyDisplay();
				}
				break;
			case 2:
				if (stockTwoShares > 0) {
					totalMoney += stockTwo;
					stockTwoShares -= 1;
				}
				else {
					cout << "You do not have enough of that stock to sell..." << endl;
					dailyDisplay();
				}
				break;
			case 3:
				if (stockThreeShares > 0) {
					totalMoney += stockThree;
					stockThreeShares -= 1;
				}
				else {
					cout << "You do not have enough of that stock to sell..." << endl;
					dailyDisplay();
				}
				break;
			case 4:
				if (stockFourShares > 0) {
					totalMoney += stockFour;
					stockFourShares -= 1;
				}
				else {
					cout << "You do not have enough of that stock to sell..." << endl;
					dailyDisplay();
				}
				break;
			default:
				cout << "Sorry, that is not one of the available stock options. Please try again..." << endl;
				optionTwo();
		}
		dailyDisplay();
	}
// the optionThree() function allows the user to advance a day and the stocks will change values
public:
	void optionThree() {
		stockOnePast = stockOne;
		stockTwoPast = stockTwo;
		stockThreePast = stockThree;
		stockFourPast = stockFour;

		srand(time(NULL));
		int rand1 = rand() % (1 + 1) + 1;
		int rand2 = rand() % (1 + 1) + 1;

		if (rand1 == 1 || stockOne < 0 || stockThree < 0) {
			stockOne += rand() % (20 + 1) + 5;
			stockThree += rand() % (5 + 1) + 5;
		}
		else {
			stockOne -= rand() % (25 + 1) + 25;
			stockThree -= rand() % (10 + 1) + 5;
		}

		if (rand2 == 1 || stockTwo < 0 || stockFour < 0) {
			stockTwo += rand() % (9 + 1) + 1;
			stockFour += rand() % (9 + 1) + 1;
		}
		else {
			stockTwo -= rand() % (2 + 1) + 1;
			stockFour -= rand() % (1 + 1) + 1;
		}

		day += 1;
		dailyDisplay();
	}
// the options() function is used to perform the operation that the user selects through a switch statement
public:
	void options(int choice) {
		switch (choice) {
			case 1:
				optionOne();
				break;
			case 2:
				optionTwo();
				break;
			case 3:
				optionThree();
				break;
			case 4:
				cout << "" << endl;
				cout << "The program is now closing..." << endl;
				break;
			default:
				cout << "That is not an option... Please choose another number: ";
				cin >> option;
				options(option);
				break;
		}
	}
};
// the main() function is what the program will run
void main() {
	Trading T;

	T.start();
	T.header();
	T.firstDisplay();
}
