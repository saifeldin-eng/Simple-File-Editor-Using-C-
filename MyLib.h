//______________________________________________________________________________________
// ⚙️ Project      : Saif El-Din Library
// 👤 Author       :  Saif El-Din Muhannad     
// 🌐 LinkedIn Url :  www.linkedin.com/in/saif-el-din-muhannad-310aab40b
//________________________________________________________________________________________



#pragma once

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "MyLib.h";

using namespace std;

namespace MyInput {

	// Function that read positive number from user and return it to call funtion.
	float ReadPositiveNumber(string TitleAppearsOnScreen) {

		float number;

		cout << TitleAppearsOnScreen << ": ";
		cin >> number;
		cout << endl;

		while (cin.fail() || number <= 0) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


			cout << "Invalid number, please try again: ";
			cin >> number;
			cout << endl;
		}

		return number;
	}
	float ReadLimitedPositiveNumber(string TitleAppearsOnScreen, int From, int To) {

		float number;

		cout << TitleAppearsOnScreen << " (" << From << " - " << To << ")" << ": ";
		cin >> number;
		cout << endl;

		while (cin.fail() || number < From || number > To) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


			cout << "Invalid number, please try again: ";
			cin >> number;
			cout << endl;
		}

		return number;
	}

	// Function that read positive number (Include Zero) from user and return it to call funtion.
	float ReadPositiveNumberWithZero(string TitleAppearsOnScreen) {

		float number;

		cout << TitleAppearsOnScreen << ": ";
		cin >> number;
		cout << endl;

		while (cin.fail() || number < 0) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


			cout << "Invalid number, please try again: ";
			cin >> number;
			cout << endl;
		}

		return number;
	}

	// Function that read Text from user and return it to call funtion.
	string ReadText(string TitleAppearsOnScreen) {

		string text;

		cin.ignore(10000, '\n');

		cout << TitleAppearsOnScreen << ": ";
		getline(cin, text);

		return text;
	}

}

namespace MyRandom {


	// Return random number.
	// Need  to write :  srand((unsigned)time(NULL)) in main() body;

	int  RandomNum(int from, int to)
	{
		int randNum = rand() % (to - from + 1) + from;
		return randNum;
	}

}

namespace MyNum {

	// Swap values between tow variables.
	void SwapNum(int& num1, int& num2) {

		int temp = num1;
		num1 = num2;
		num2 = temp;

	}

	//check if passed number is odd.
	bool IsOdd(int number) {

		return (number % 2 == 1);
	}

	//check if passed number is even.
	bool IsEven(int number) {

		return (number % 2 == 0);
	}

	// return length of int.
	int Intlength(int num) {

		int intlength = 0;
		int reminder = 0;

		while (num > 0) {

			num = num / 10;

			intlength++;
		}
		return intlength;
	}

}

namespace MyArray {


	// Pass Empty int type Array and its length to fill it with random int values.
	void FillArrayWithRandomInt(int Arr[], int ArrayLength) {



		for (int i = 0; i < ArrayLength; i++)
		{
			Arr[i] = MyRandom::RandomNum(1, 100);
		}

		cout << endl;
	}

	// Pass int type Array and its length to return its avarage in float type.
	float AvarageOfNumbersInArray(int arr[100], int arrLength) {

		float Sum = 0;
		float avarage = 0;

		for (int i = 0; i < arrLength; i++) {

			Sum += arr[i];
		}

		avarage = Sum / arrLength;

		return avarage;
	}

	//Shuffle int type array.
	void ShuffleArrayElements(int arr[], int arrlength) {

		for (int i = 0; i < arrlength; i++)
		{
			int index1 = MyRandom::RandomNum(1, arrlength) - 1;
			int index2 = MyRandom::RandomNum(1, arrlength) - 1;

			MyNum::SwapNum(arr[index1], arr[index2]);

		}
	}

	//Print int type array .
	void PrintArray(int arr[100], int arrLength) {

		for (int i = 0; i < arrLength; i++)
			cout << arr[i] << " ";

		cout << "\n";
		cout << "\n";
	}

}

namespace MyVector {

	namespace fillPrint {

		void fill_vector_WithInt(vector <int>& vNumber) {

			char CheckContinue = 'y';

			do {
				vNumber.push_back(MyInput::ReadPositiveNumberWithZero("Please add number to vector"));
				cout << "Do you want to add more number? (Y/N) :  ";
				cin >> CheckContinue;
				cout << endl;


			} while (CheckContinue == 'y' || CheckContinue == 'Y');
		}
		void print_vector_OfInt(vector <int>& vNumber) {

			for (int& number : vNumber) {

				cout << number << endl;
			}
		}
	}
	namespace PopGroup {

		void SafePopBack(vector <int>& vInt) {

			if (!vInt.empty()) {

				vInt.pop_back();
			}
		}
		void SafePopBack(vector <string>& vString) {

			if (!vString.empty()) {

				vString.pop_back();
			}
		}
		void SafePopBack(vector <bool>& vBool) {

			if (!vBool.empty()) {

				vBool.pop_back();
			}
		}
		void SafePopBack(vector <float>& vFloat) {

			if (!vFloat.empty()) {

				vFloat.pop_back();
			}
		}

	}

}

namespace MyReadyValues {

	const double PI = 3.141592653589793;
}

namespace MyFormat {

	void PrintCenter(int TotalSpacelength, string text) {

		int TotalSpace = TotalSpacelength - text.length();

		if (MyNum::IsOdd(TotalSpace))
			TotalSpace++;

		int RightSpace = TotalSpace / 2;
		int LeftSpace = TotalSpace / 2;

		cout << setw(LeftSpace) << "" << text << setw(RightSpace) << "" << "|";
	}
	void PrintCenter(int TotalSpacelength, int number) {

		int TotalSpace = TotalSpacelength - MyNum::Intlength(number);

		if (MyNum::IsOdd(TotalSpace))
			TotalSpace++;

		int RightSpace = TotalSpace / 2;
		int LeftSpace = TotalSpace / 2;

		cout << setw(LeftSpace) << "" << number << setw(RightSpace) << "" << "|";
	}


}
