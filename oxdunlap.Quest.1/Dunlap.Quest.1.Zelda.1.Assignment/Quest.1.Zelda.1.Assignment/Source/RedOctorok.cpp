#include "RedOctorok.h"

RedOctorok::RedOctorok(){
}

RedOctorok::~RedOctorok(){
}

void RedOctorok::Update(GAME_FLT myFLT){
	//Moves in a circle.
	//randParam = radius

	theta += 0.02;//increments angle from center. Bigger number = faster movement
	theta = fmod(theta,360); //modulus to prevent it from incrementing infinitely
	angle = atan2(startPosition.y - position.y, startPosition.x - position.x) * (180/PI);	//rotates facing

	position.x = startPosition.x + cos(theta) * randParam;
	position.y = startPosition.y + sin(theta) * randParam;
}