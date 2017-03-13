#include "BlueOctorok.h"

BlueOctorok::BlueOctorok(){
}

BlueOctorok::~BlueOctorok(){
}

void BlueOctorok::Update(GAME_FLT myFLT){
	//Spins!
	//randParam = speed. Must be slowed down a bit

	angle += randParam / 20;
}