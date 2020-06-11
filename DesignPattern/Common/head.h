#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <ctime>
#include <windows.h>

using namespace std;

#define DEL(x) {if(x){delete x; x=NULL;}}
#define CountArray(arr)	(sizeof(arr)/ sizeof(arr[0]))

namespace define {
	enum Type {
		circle,
		square,
	};
}
