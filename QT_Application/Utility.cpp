#include<cstdlib>
#include "Utility.h"


int Utility::partition(vector<int>& arr, int start, int end)
{
	int high;
	int pivotIndex;

	srand((unsigned int)time(nullptr));
	high = (rand() % (end - start)) + start;
	swap(arr[high], arr[end]);

	pivotIndex = start;
	for (int i = start; i < end; i++)
	{
		if (arr[i] < arr[end])
		{
			swap(arr[i], arr[pivotIndex]);
			pivotIndex++;
		}
	}
	swap(arr[pivotIndex], arr[end]);
	return pivotIndex;
}

void Utility::quick_sort(vector<int>& arr, int start, int end)
{
	if (start >= end)
		return;
	else
	{
		int pivotIndex = partition(arr, start, end);
		quick_sort(arr, start, pivotIndex - 1);
		quick_sort(arr, pivotIndex + 1, end);
	}
}

void Utility::quick_sort(vector<int>& arr)
{
	quick_sort(arr, 0, arr.size() - 1);
}
