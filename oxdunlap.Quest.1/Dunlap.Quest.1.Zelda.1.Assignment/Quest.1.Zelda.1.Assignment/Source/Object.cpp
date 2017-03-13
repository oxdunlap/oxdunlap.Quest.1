#include "Object.h"

Object::Object(){
	gDevice = NULL;
	iDevice = NULL;
	texture = NULL;
	position = { 0,0 };
	startPosition = { 0,0 };
	angle = 0.0;
}

Object::~Object(){
	gDevice = NULL;
	//texture->free(); //causes errors on Quit
}

//Should be purely virtual? To be more scalable, but not really *necessary* for this Quest 1?
bool Object::Initialize (std::shared_ptr<Texture> myTexture, GraphicsDevice* myGDevice, InputDevice* myIDevice, GAME_FLT posX, GAME_FLT posY, GAME_FLT ang) {
	//Random setup
	static std::random_device randDev;
	static std::default_random_engine engine(randDev());
	static std::uniform_real_distribution<float> uniDist(10.0, 100.0);
	//Makes randParam unique to each object, but generated with same set of numbers. Maybe not scalable
	randParam = uniDist(engine);

	gDevice = myGDevice;
	iDevice = myIDevice;
	texture = myTexture;
	//Texture is loaded in ArtAssetLibrary

	startPosition = {posX,posY};
	position = startPosition;
	angle = ang;

	return true;
}

//Purely Virtual Method
void Object::Update(GAME_FLT myFLT){
	//Handled in child classes: this is where the objects do their movement by
	//updating angle and position
}

//Should be purely virtual?
void Object::Draw(GAME_FLT myFLT, View* myView){

	GAME_VEC tempPos = { position.x - myView->getPosition().x, position.y + myView->getPosition().y }; //signs can be changed for inverted controls. :)
	texture->render(gDevice->GetRenderer(), tempPos, angle, NULL);
}
