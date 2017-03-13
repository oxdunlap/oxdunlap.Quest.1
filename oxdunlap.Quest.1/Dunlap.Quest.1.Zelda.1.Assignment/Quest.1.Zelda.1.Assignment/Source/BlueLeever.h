#pragma once

#include "Object.h"

class BlueLeever : public Object
{
public:
	BlueLeever();
	~BlueLeever();

	void Update(GAME_FLT);
private:
	bool facingUp;
};