//______________________________________________________________________________________
// ⚙️ Project      :  Simple txt file editor
// 👤 Author       :  Saif El-Din Muhannad     
// 🌐 LinkedIn Url :  www.linkedin.com/in/saif-el-din-muhannad-310aab40b
//________________________________________________________________________________________



#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
#include "MyLib.h";
#include <cstdlib>;
using namespace std;

enum enUserSelection {
	Exit
	, AddToFile
	, RemoveFromFile
	, Replace
	, ShowFileData
	, clearConsole
};
void FillDataFromFileToVector(string FileName, vector <string>& vFileData)
{
	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string line;

		while (getline(MyFile, line))

		{
			if (line != "") {

				vFileData.push_back(line);
			}
		}
	}
}
void FillDataFromVectorToFile(string FileName, vector <string> vFileData) {

	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (string& vRecord : vFileData)
		{

			if (vRecord != "")
			{
				MyFile << vRecord << endl;
			}

		}

	}

}
void RemoveRecordFromFile(string FileName, string InputRecord)
{
	vector <string> vFileData;
	FillDataFromFileToVector(FileName, vFileData);

	bool isAvailableRecord = false;

	for (string& Record : vFileData)
	{
		if (Record == InputRecord) {

			isAvailableRecord = true;
			Record = "";
		}
	}

	if (isAvailableRecord == false) {
		cout << "\nRecord not found in the file.\n\n";
	}
	else {
		cout << "\nDone.\n";
	}

	FillDataFromVectorToFile(FileName, vFileData);


}
void AddRecordToFile(string FileName, string InputRecord) {

	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{

		MyFile << InputRecord << endl;

		cout << "\nDone.\n";
	}

}
bool CheckAvailableRecord(string RecordName, vector <string>& vFileData) {

	for (string& line : vFileData) {
		if (line == RecordName) {
			return true;
		}
	}
	return false;
}
void ReplaceRecord(string FileName, string InputRecord) {

	fstream MyFile;
	vector <string> vFileData;
	bool isAvailableRecord = false;




	FillDataFromFileToVector(FileName, vFileData);

	if (CheckAvailableRecord(InputRecord, vFileData)) {

		for (string& line : vFileData) {

			if (line == InputRecord) {

				line = MyInput::ReadText("Replace it With");
				cout << "\nDone.\n\n";
			}
		}

	}
	else {
		cout << "\nRecord not found in the file.\n\n";

	}

	FillDataFromVectorToFile(FileName, vFileData);



}
string ReadRecord() {

	return MyInput::ReadText("Enter The Record");

}
void PrintFileData_on_Consol(string FileName)
{

	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string line;
		while (getline(MyFile, line))
		{
			if (line != "") {
				cout << line << endl;

			}

		}
		cout << "_________________________________________\n\n";
	}

}
void ShowSelectionScreen(string FileName) {

	cout << "_______________File Editor_______________\n";
	cout << " [0] Stop File Editor and exit \n";
	cout << " [1] Add records to file \n";
	cout << " [2] Remove records from file \n";
	cout << " [3] Replace record by another one \n";
	cout << " [4] Show file Data \n";
	cout << " [5] Clear console \n";
	cout << "_________________________________________\n";
}
bool Check_Continue() {

	string UserChoose = MyInput::ReadText("\nAre you sure you want to exit? (Y\\N)");

	return (UserChoose == "y" || UserChoose == "Y") ? false : true;
}
void FileEditor(string FileName) {

	ShowSelectionScreen(FileName);

	bool checkContinue = true;


	do {



		int UserChoose = MyInput::ReadLimitedPositiveNumber("\nSelect", 0, 5);

		switch (UserChoose) {
		case enUserSelection::AddToFile:
			AddRecordToFile(FileName, ReadRecord());
			break;
		case enUserSelection::RemoveFromFile:
			RemoveRecordFromFile(FileName, ReadRecord());
			break;
		case enUserSelection::Replace:
			ReplaceRecord(FileName, ReadRecord());
			break;
		case enUserSelection::ShowFileData:
			PrintFileData_on_Consol(FileName);
			break;

		case enUserSelection::Exit:
			checkContinue = Check_Continue();
			break;
		case enUserSelection::clearConsole:
			system("cls");
			ShowSelectionScreen(FileName);
			break;
		}

	} while (checkContinue);






}
int main() {


	FileEditor("MyFile.txt");

}
