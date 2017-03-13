#include "ObjectFactory.h"

//Purely virtual method
//Returns a pointer to a new object of the correpsonding type. 
//Does NOT Initialize. Happens in Game.Search()
std::unique_ptr<Object> create(){
	return NULL;
}