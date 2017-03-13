#pragma once

#include "Object.h"

class ObjectFactory{

public:
	virtual  std::unique_ptr<Object> create() = 0;

};