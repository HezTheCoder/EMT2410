/*******************************************************************************************************

C++ for Embedded Systems (EMT2410) - Lab 4

by Hezron Castaneros
New York City College of Technology

This source code is licensed under the Creative Commons BY-NC-SA (Attribution-NonCommercial-ShareAlike) 
License 3.0: https://creativecommons.org/licenses/by-nc-sa/3.0/

*******************************************************************************************************/

#include "main.h"
#include <string>

int main(int argc, char** argv)
{
	//Stores a linked list of samples.
	//pSamplesList is the pointer to the start of the list, pSamplesListTail is the pointer to
	//the end of the list. Each sample consists of a space to store the entered float and a
	//pointer to the next sample in the list.
	FSample *pSamplesList = NULL, *pSamplesListTail = NULL;

	//Stores the number of samples obtained.
	unsigned int numSamples = 0;

	//Stores the string entered in by the user.
	string strEntry;

	cout << "C++ for Embedded Systems Lab 4 - Statistics for Arbitrary Number of Floats\n\n\n";

	cout << "Keep entering floats (press Enter after each), then enter Q to stop.\n\n";

	for (;1 ; ++numSamples) //Increment the number of samples
	{
		//Take in user input and place it in string.
		cin >> strEntry;

		//If the letter 'Q' was entered, stop intake
		if (strEntry == "Q") { break; }

		//Add the sample we just got to the linked list of samples.

		//This is the case where the list is empty, so we are adding its first entry.
		if (pSamplesList == NULL && pSamplesListTail == NULL)
		{
			//Allocate new space for sample.
			pSamplesList = (FSample*)malloc(sizeof(FSample));

			//Set the tail of the list as the same as the start of the list since there is
			//only one entry.
			pSamplesListTail = pSamplesList;

			//There's only one entry in the list, so this new sample will have no next sample.
			pSamplesList->pNext = NULL;

			//Fill in the gathered sample.
			//the std::string.c_str() method gets a C-style string pointer to the string so we
			//can read it in a C-ish way.
			//the atof() function is a C library function that converts a string to a double,
			//which we'll need to cast to a float.
			pSamplesList->sampleData = (float)atof(strEntry.c_str());
		}
		else //This is the case where the list already has one or more entries.
		{
			//Tack this new sample onto the current tail.
			pSamplesListTail->pNext = (FSample*)malloc(sizeof(FSample));
			pSamplesListTail = pSamplesListTail->pNext;
			pSamplesListTail->pNext = NULL;
			pSamplesListTail->sampleData = (float)atof(strEntry.c_str());
		}

		//Clear the string to prepare for the next input.
		strEntry.clear();
	}

	//If no samples entered, give error string
	if (numSamples == 0)
	{
		cout << "\n\nNo samples were entered...\n\n";
		return 0;
	}

	cout << "\n\nData acquisition is complete (" << numSamples << " samples entered)\n\n";

	//Say what we entered.
	cout << "Dataset: ";
	//for each sample in the list, display the sample, then go to the next sample in the list.
	for (FSample* pCurSample = pSamplesList; pCurSample != NULL; pCurSample = pCurSample->pNext)
	{
		cout << pCurSample->sampleData;

		//display a comma if not the last sample
		if (pCurSample->pNext != NULL)
		{
			cout << ", ";
		}
	}

	//Now compute the average, max, and min and display to user
	cout << "\n\nDataset statistics --> MEAN: " << ComputeDatasetArithMean(pSamplesList) << ", MAX: " << ComputeDatasetMax(pSamplesList) << 
		", MIN: " << ComputeDatasetMin(pSamplesList) << "\n";
	return 0;
}

float ComputeDatasetArithMean(FSample* pList)
{
	//Stores a running sum of the samples collected as we iterate through the list.
	float runningSum = 0.0f;

	//Reject empty list
	if (pList == NULL) { return 0.0f; }

	//If only one number in the list, then that is the mean
	if (pList->pNext == NULL) { return pList->sampleData; }

	//The total number of samples we iterated through
	unsigned int totalSamplesCounted = 0;
	for (FSample* pCurSample = pList; pCurSample != NULL; pCurSample = pCurSample->pNext)
	{
		runningSum += pCurSample->sampleData;
		++totalSamplesCounted;
	}

	//Avg of n numbers is sum of all numbers divided by n
	return (runningSum / totalSamplesCounted);
}
float ComputeDatasetMax(FSample* pList)
{
	//Reject empty list
	if (pList == NULL) { return 0.0f; }

	//If list has only one element, that element is the maximum!
	if (pList->pNext == NULL) { return pList->sampleData; }

	float curMax = pList->sampleData;

	unsigned int totalSamplesCounted = 0;
	for (FSample* pCurSample = pList->pNext; pCurSample != NULL; pCurSample = pCurSample->pNext)
	{
		if (pCurSample->sampleData >= curMax) { curMax = pCurSample->sampleData; }
	}

	return curMax;
}
float ComputeDatasetMin(FSample* pList)
{
	//Reject empty list
	if (pList == NULL) { return 0.0f; }

	//If list has only one element, that element is the minimum!
	if (pList->pNext == NULL) { return pList->sampleData; }

	float curMin = pList->sampleData;

	unsigned int totalSamplesCounted = 0;
	for (FSample* pCurSample = pList->pNext; pCurSample != NULL; pCurSample = pCurSample->pNext)
	{
		if (pCurSample->sampleData < curMin) { curMin = pCurSample->sampleData; }
	}

	return curMin;
}