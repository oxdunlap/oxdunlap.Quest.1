#pragma once

#include "ObjectFactory.h"
#include "RedLeever.h"

class RedLeeverFactory : public ObjectFactory {

public:
	std::unique_ptr<Object> create();
};