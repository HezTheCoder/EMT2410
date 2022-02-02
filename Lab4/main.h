#pragma once

/*******************************************************************************************************

C++ for Embedded Systems - Lab 3

by Hezron Castaneros
New York City College of Technology

This source code is licensed under the Creative Commons BY-NC-SA (Attribution-NonCommercial-ShareAlike)
License 3.0: https://creativecommons.org/licenses/by-nc-sa/3.0/

*******************************************************************************************************/

#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv);

//Structure that stores a float sample collected by the user and a pointer to the next sample.
//We use a linked list to store all the samples.
struct FSample
{
	float sampleData;
	FSample* pNext;
};

//Computes the mean of a linked list of samples.
float ComputeDatasetArithMean(FSample* pList);

//Computes the maximum out of a linked list of samples.
float ComputeDatasetMax(FSample* pList);

//Computes the minimum out of a linked list of samples.
float ComputeDatasetMin(FSample* pList);