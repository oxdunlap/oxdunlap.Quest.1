#include "BlueLeever.h"

BlueLeever::BlueLeever(){
	facingUp = true;
}

BlueLeever::~BlueLeever(){
}

void BlueLeever::Update(GAME_FLT myFLT) {
	//Moves in vertical line until it reaches a certain distance from starting point
	//randParam = distance from starting point

	if (facingUp) {
		position.y += 0.5;
	}
	else {
		position.y -= 0.5;
	}
	if (abs(position.y - startPosition.y) > randParam) facingUp = !facingUp;
}