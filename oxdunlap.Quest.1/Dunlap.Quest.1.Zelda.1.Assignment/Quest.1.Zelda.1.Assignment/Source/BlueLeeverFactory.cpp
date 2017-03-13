#include "BlueLeeverFactory.h"

std::unique_ptr<Object> BlueLeeverFactory::create(){
	auto tempPtr = std::unique_ptr<Object>(std::make_unique<BlueLeever>());
	return tempPtr;
}