/*************************************************************************
	> File Name: merge_sort.cpp
	> Author: Tokey
	> Mail: TokeyRoad@163.com 
	> Created Time: 2020年06月10日 星期三 22时33分15秒
 ************************************************************************/

#include <iostream>
#include <vector>

void merge(int arr[], int start, int mid, int end){
	//int* tempArr = new int[end - start + 1];
	std::vector<int> tempArr;
	tempArr.resize(end - start + 1);
	for(int i = start; i <= end; ++i){
		tempArr[i - start] = arr[i];
	}

	int lp = start;
	int rp = mid + 1;
	int index = start;
	while(lp != mid + 1 || rp != end + 1){
		if(lp == mid + 1){
			arr[index++] = tempArr[rp - start];
			++rp;
			continue;
		}

		if(rp == end + 1){
			arr[index++] = tempArr[lp - start];
			++lp;
			continue;
		}

		if(tempArr[lp - start] < tempArr[rp - start]){
			arr[index++] = tempArr[lp - start];
			++lp;
		}else{
			arr[index++] = tempArr[rp - start];
			++rp;
		}
	}
	//delete[] tempArr;
}

void merge_sort(int arr[], int start, int end){
	if(start >= end)
		return;
	int mid = (end - start) / 2 + start;
	std::cout << "mid:" << mid << std::endl;
	merge_sort(arr, start, mid);
	merge_sort(arr, mid+1,end);
	merge(arr, start, mid, end);
}


int main(int argc, char **argv){
	//int* arr = new int[argc];
	//for(int i = 1; i < argc; ++i){
	//	arr[i] = atoi(argv[i]);
	//	std::cout << arr[i] << " ";
	//}
	int arr[] = { 7,5,9,3,8,2,5,0 };
	std::cout << std::endl;
	merge_sort(arr, 0, 7);

	for(int i = 0; i < 8; ++i){
		std::cout << arr[i] << " ";
	}

	return 0;
}



