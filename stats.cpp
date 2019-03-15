#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm> 
using namespace std;

//declaring array of floats of a int size so we can calculate statistics 
float stats(float data[], int size);
float sum = 0.0; 

int main() {
	int n = 0;
	// creates the array
	float data[size];
	// allows the user to input size of array
	cout << "Input " << size << " values" << endl;
	// puts each value into the array of choosen size
	for(int i = 0; i < size; ++i) {
		cin >> data[i];
	}
	cout << "Statistics Report: " << endl;
	cout << "Mean = " << calcMean(data) << endl; 
	cout << "Median = " << calcMedian(data) << endl;
	cout << "Mode = " << calcMode(data) << endl; 
	cout << "Standard Deviation = " << calcSTD(data) << endl;
	return 0;
}
float calcMean(float data[], int size)
{
	float total = 0;
	float mean = 0;
	for(int i = 0; i < size; ++i) {
		total += data[i];
	}
	mean = total/size;
	return mean;
}

float calcMode(float data[], int size) {
	float count = 1;
        float max = 0;
        float mode = data[0];
        for (int i = 0; i < size - 1; i++)
        {
           if (data[i] == data[i+1]) //check if first value is same next
           {
              count++;
	   }
           if (count > max) //creates new max
           {
                  max = count;
                  mode = data[i];
           }
           else {
              count = 1; //reset
           }
	}
	return mode; 
}

float calcMedian(float data[], int size)
{
	//Must sort the array first
	sort(data, data+size);
	//if size is even
	if (size % 2 == 0) {
		return double(data[(size-1)/2]+data[size/2])/2.0;
	}
	//else the size is odd
	else {
		return double(data[size/2]);
	}
}

float calcSTD(float data[], int size)
{
	float total = 0;
	float mean = 0;
	float sDev = 0;
	for(int i = 0; i < size; ++i) {
		total += data[i];
	}
	mean = total/size;
	for(int x = 0; x < size; ++x)
	{
        	sDev += pow(data[x] - mean, 2);
	}
	return sqrt(sDev / size);
}
