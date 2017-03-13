#include "RedOctorokFactory.h"

std::unique_ptr<Object> RedOctorokFactory::create(){
	auto tempPtr = std::unique_ptr<Object>(std::make_unique<RedOctorok>());
	return tempPtr;
}
