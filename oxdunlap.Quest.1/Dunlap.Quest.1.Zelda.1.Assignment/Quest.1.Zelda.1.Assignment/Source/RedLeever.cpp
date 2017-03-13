#include "RedLeever.h"

RedLeever::RedLeever(){
}

RedLeever::~RedLeever(){
}

void RedLeever::Update(GAME_FLT myFLT){
	//Moves in horizontal line until it reaches a certain distance from starting point
	//randParam = distance from starting point

	if (facingUp) {
		position.x += 0.5;
	}
	else {
		position.x -= 0.5;
	}
	if (abs(position.x - startPosition.x) > randParam) facingUp = !facingUp;
}
