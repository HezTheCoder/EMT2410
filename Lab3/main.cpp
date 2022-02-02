#include <iostream>

using namespace std;

void GetCommand();

float FindDatasetMaximum();

float FindDatasetMinimum();

float dataset[5];

int main(int argc, char** argv)
{
#ifdef __linux__
	system("clear");
#else
	system("cls");
#endif

	cout << "C++ for Embedded Systems - Lab 3: Maximum or Minimum\n\n\n";

	cout << "Enter a dataset of 5 numbers: \n";

	int j = 0;

	do
	{
		cout << "datapoint " << j << "? > ";
		cin >> dataset[j];
		cout << "\n";
		++j;
	} 
	while (j < 5);

	GetCommand();

	return 0;
}

void GetCommand()
{
	int option;
	cout << "Type 9 to get max, or type 0 to get min, then press Enter.\n\n";

	cout << "0 or 9? > ";
	cin >> option;

	switch (option)
	{
	case 0:
		cout << "\n\nMIN: " << FindDatasetMinimum() << "\n\n";
		break;
	case 9:
		cout << "\n\nMAX: " << FindDatasetMaximum() << "\n\n";
		break;
	default:
		cout << "Invalid command.\n\n";
		break;
	}
}

float FindDatasetMinimum()
{
	float temp = dataset[0];
	for (int i = 1; i < 5; ++i)
	{
		if (dataset[i] < temp) { temp = dataset[i]; }
	}
	return temp;
}

float FindDatasetMaximum()
{
	float temp = dataset[0];
	for (int i = 1; i < 5; ++i)
	{
		if (dataset[i] > temp) { temp = dataset[i]; }
	}
	return temp;
}