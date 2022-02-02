#include <iostream>

using namespace std;

const float dataset[5] = {3.67f, 1.2485f, 3.1416f, 0.09f, 2.2292f};

#define NUM_POINTS_IN_DATASET 5

int main(int argc, char** argv)
{
	int option;
	float temp;

	cout << "C++ for Embedded Systems Lab #2: Maximum, Minimum\n\n\n";

	cout << "Dataset contains " << NUM_POINTS_IN_DATASET << " points: ";
	for(int j = 0; j < NUM_POINTS_IN_DATASET; ++j){ cout << dataset[j] << " "; }
	cout << "\n\n";

	cout << "Type 9 to get maximum number, or 0 to get minimum number, then press Enter.\n\n";

	cin >> option;
	temp = dataset[0];
	switch(option)
	{
	case 0:
		for(int i = 0; i < NUM_POINTS_IN_DATASET; ++i)
		{
			if(dataset[i] < temp){ temp = dataset[i]; }
		}
		cout << "MIN is: " << temp;
		break;
	case 9:
		for(int k = 0; k < NUM_POINTS_IN_DATASET; ++k)
		{
			if(dataset[i] > temp){ temp = dataset[i]; }
		}
		break;
	default:
		cout << "Whoa! Invalid command!!\n\n";
		break;
	}

	return 0;
}