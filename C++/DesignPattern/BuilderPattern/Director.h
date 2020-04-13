#pragma once
#include "builder.h"

class Director {
public:
	void Create(IBuilder *builder){
		builder->BuildCPU();
		builder->BuildRam();
		builder->BuildMainBoard();
		builder->BuildVideoCard();
	}
};