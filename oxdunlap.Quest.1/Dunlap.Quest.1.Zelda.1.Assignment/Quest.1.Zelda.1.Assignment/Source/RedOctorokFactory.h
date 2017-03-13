#pragma once

#include "ObjectFactory.h"
#include "RedOctorok.h"

class RedOctorokFactory : public ObjectFactory {

public:
	std::unique_ptr<Object> create();
};