#include <iostream>
#include "Object.h"

using namespace std;

class Inventory{ 
	
	int nbPotL; //nb de potion de vie
	int nbPotM; //nb de prton de mana

	public :
		
		Inventory();
		void UseObject(int lPotion , int mPotion, character c);
		void AddObject();

};
