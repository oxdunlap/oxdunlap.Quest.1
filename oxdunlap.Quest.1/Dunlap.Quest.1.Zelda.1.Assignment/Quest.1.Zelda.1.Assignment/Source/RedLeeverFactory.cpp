#include "RedLeeverFactory.h"

std::unique_ptr<Object> RedLeeverFactory::create(){
	auto tempPtr = std::unique_ptr<Object>(std::make_unique<RedLeever>());
	return tempPtr;
}
