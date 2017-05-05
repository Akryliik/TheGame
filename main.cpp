#include "Config.h"
#include "Game.h"
#include "Character.h"
#include "Inventory.h"
#include "Fight.h"
#include "Map.h"

int main() {
	Config C;
	//C.editConfig();
	system("clear");

	Game G(C);

	return 0;
}
