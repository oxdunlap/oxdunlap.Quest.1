#pragma once

#include "ObjectFactory.h"
#include "BlueOctorok.h"

class BlueOctorokFactory : public ObjectFactory {

public:
	std::unique_ptr<Object> create();
};