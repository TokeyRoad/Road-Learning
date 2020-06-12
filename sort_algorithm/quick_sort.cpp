/*************************************************************************
	> File Name: quick_sort.cpp
	> Author: Tokey
	> Mail: TokeyRoad@163.com 
	> Created Time: 2020年06月12日 星期五 09时28分55秒
 ************************************************************************/

#include <iostream>
#include <vector>


void quick_sort(int arr[], int lp, int rp){
	if(lp >= rp){
		return;
	}
	int cur = arr[lp];
	int left = lp;
	int right = rp;
	int temp = 0;
	int index = lp;
	while(lp != rp){
		while(lp < rp && arr[rp] >= cur){
			--rp;
		}
		if(lp < rp){
			arr[lp] = arr[rp];
			//index = rp;
		}
		while(lp < rp && arr[lp] <= cur){
			++lp;
		}
		if(lp < rp){
			arr[rp] = arr[lp];
		}
	}
	arr[lp] = cur;
	quick_sort(arr, left, lp-1);
	quick_sort(arr, lp+1, right);
}


int main(){
	int arr[] = {6,4,3,2,1,5,7,4};
	quick_sort(arr, 0, 7);
	for(int i = 0; i < 8; ++i){
		std::cout << arr[i] << " ";
	}
	return 0;
}


