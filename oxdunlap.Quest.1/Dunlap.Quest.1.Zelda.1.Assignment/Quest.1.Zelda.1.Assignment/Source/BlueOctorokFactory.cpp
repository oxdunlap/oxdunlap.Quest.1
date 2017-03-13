#include "BlueOctorokFactory.h"

std::unique_ptr<Object> BlueOctorokFactory::create(){
	auto tempPtr = std::unique_ptr<Object>(std::make_unique<BlueOctorok>());
	return tempPtr;
}
