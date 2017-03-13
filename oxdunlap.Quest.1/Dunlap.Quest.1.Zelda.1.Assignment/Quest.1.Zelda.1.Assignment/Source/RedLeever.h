#pragma once

#include "Object.h"

class RedLeever : public Object
{
public:
	RedLeever();
	~RedLeever();

	void Update(GAME_FLT);
private:
	bool facingUp;
};