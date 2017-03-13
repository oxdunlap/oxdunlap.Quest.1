#pragma once

#include "ObjectFactory.h"
#include "BlueLeever.h"

class BlueLeeverFactory : public ObjectFactory{

public:
	std::unique_ptr<Object> create();
};