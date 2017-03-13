#pragma once

#include "Object.h"

class RedOctorok : public Object
{
public:
	RedOctorok();
	~RedOctorok();

	void Update(GAME_FLT);

private:
	float theta = 0.0;
};