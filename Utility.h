#pragma once

#include <vector>
#include <time.h>
using namespace std;

class Utility
{
public:
	static int partition(vector<int>& arr, int start, int end);
	static void quick_sort(vector<int>& arr, int start, int end);
	static void quick_sort(vector<int>& arr);
};

