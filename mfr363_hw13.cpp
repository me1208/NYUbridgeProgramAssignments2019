#include <iostream>
#include <vector>
using namespace std;

const int SIZE_WORLD = 20, MAX_DOODLES = 5, MAX_ANTS = 100;
const char EMPTY = '-', DOODLE_BUG = 'X', ANT = 'o';
namespace predatorPraySim
{
	class World;

	class Organism {
		friend class World;
	public:
		Organism();
		Organism(int x, int y, World *world);
		virtual void Move() = 0;
		virtual void Breed() = 0;
		virtual void Starve() = 0;
		virtual char OrganismSpecies() = 0;

	protected:
		int x, y;
		World *world;
		void initializeGrid(Organism* grid);
	};

	Organism::Organism(){
		this->x = 0;
		this->y = 0;
		this->world = NULL;
	};

	class World{
		friend class Organism;
		friend class DoodleBug;
		friend class Ant;

	public:
		World();

		Organism* getGridOrganism(int x, int y);
		void updateGridOrganism(int x, int y, Organism *organism);
		void emptyGridOrganism(int x, int y);
		void playSimulation();

		void set_timeStep(int step);

	private:
		Organism* grid[SIZE_WORLD][SIZE_WORLD];
		int timeStep;
	};

	Organism::Organism(int x, int y, World *world) {
		this->x = x;
		this->y = y;
		this->world = world;
		world->updateGridOrganism(x, y, this);
	}

	World::World(){
		Organism* newGrid;
	}

	void World::updateGridOrganism(int x, int y, Organism *organism){
		grid[x][y] = NULL;
		grid[x][y] = organism;
	}
	
	void World::emptyGridOrganism(int x, int y){
		grid[x][y] = NULL;
	}

	Organism* World::getGridOrganism(int x, int y){
		if(x >= 0 && x <= 20
		&& y >= 0 && y <= 20 ){
			return grid[x][y];
		} else{
			return NULL;
		}
	}

	void World::set_timeStep(int step){ this->timeStep = step;}

	void World::playSimulation() {
		for (int x = 0; x < SIZE_WORLD; ++x) {
			for (int y = 0; y < SIZE_WORLD; ++y) {
				if (this->getGridOrganism(x, y) != NULL && this->getGridOrganism(x, y)->OrganismSpecies() != EMPTY) {
					this->getGridOrganism(x, y)->Move();
				}
			}
		}

		for (int x = 0; x < SIZE_WORLD; ++x) {
			for (int y = 0; y < SIZE_WORLD; ++y) {
				if (this->getGridOrganism(x, y) != NULL && this->getGridOrganism(x, y)->OrganismSpecies() != EMPTY) {
					this->getGridOrganism(x, y)->Breed();
				}
			}
		}

		for (int x = 0; x < SIZE_WORLD; ++x) {
			for (int y = 0; y < SIZE_WORLD; ++y) {
				if (this->getGridOrganism(x, y) != NULL && this->getGridOrganism(x, y)->OrganismSpecies() == DOODLE_BUG) {
						this->getGridOrganism(x, y)->Starve();
				}
			}
		}

		for (int x = 0; x < SIZE_WORLD; ++x) {
			for (int y = 0; y < SIZE_WORLD; ++y) {

				if(this->getGridOrganism(x,y) == NULL){
					cout << EMPTY;
				} else{
					cout << this->getGridOrganism(x,y)->OrganismSpecies();
				}

				if(y == SIZE_WORLD - 1) {
					cout << endl;
				}
			}
		}
	}

	class DoodleBug: public Organism {
		friend class Organism;
		friend class World;
	public:
		DoodleBug(int x, int y, World *world);
		void Move();
		void Breed();
		void Starve();
		char OrganismSpecies();

	private:
		int timeSinceLastFeed;
		int survivedStepsAmount;
	};

	void DoodleBug::Move(){
		/* Move. Every time step, if there is an adjacent ant (up, down, left, or  right), then
		 * the doodlebug will move to that cell and eat the ant. Otherwise, the doodlebug moves
		 * according to the same rules as the ant. Note  that a doodlebug cannot eat other doodlebugs.*/
		bool moved = false;
		survivedStepsAmount += 1;
		if(x > 0 && (world->getGridOrganism(x - 1, y) != NULL && world->getGridOrganism(x - 1, y)->OrganismSpecies() == ANT)){ // move left
			world->updateGridOrganism(x - 1, y, world->getGridOrganism(x,y));
			moved = true;
		} else if(x < SIZE_WORLD - 1 && world->grid[x + 1][y] != NULL && world->grid[x + 1][y]->OrganismSpecies() == ANT){ // move right
			world->updateGridOrganism(x + 1, y, world->getGridOrganism(x,y));
			moved = true;
		} else if(y > 0 && (world->grid[x][y - 1] != NULL && world->grid[x][y - 1]->OrganismSpecies() == ANT)){ // move up
			world->updateGridOrganism(x, y - 1, world->getGridOrganism(x,y));
			moved = true;
		} else if(y < SIZE_WORLD - 1 && world->grid[x][y + 1] != NULL && world->grid[x][y + 1]->OrganismSpecies() == ANT){ // move down
			world->updateGridOrganism(x, y + 1, world->getGridOrganism(x,y));
			moved = true;
		}

		if(moved){
			timeSinceLastFeed = 0;
			world->emptyGridOrganism(x, y);
		} else {
			int randomMove = rand() % 5 + 1;
			timeSinceLastFeed += 1;
			switch(randomMove){
				case 1: // move left
					if(x > 0 && (world->grid[x - 1][y] == NULL || world->grid[x - 1][y]->OrganismSpecies() != DOODLE_BUG)){
						world->updateGridOrganism(x - 1, y, world->getGridOrganism(x,y));
						world->emptyGridOrganism(x, y);
					}
					break;
				case 2: // move right
					if(x < SIZE_WORLD - 1 && (world->grid[x + 1][y] == NULL || world->grid[x + 1][y]->OrganismSpecies() != DOODLE_BUG)){
						world->updateGridOrganism(x + 1, y, world->getGridOrganism(x,y));
						world->emptyGridOrganism(x, y);
					}
					break;
				case 3: // move up
					if(y > 0 && (world->grid[x][y - 1] == NULL || world->grid[x][y - 1]->OrganismSpecies() != DOODLE_BUG)){
						world->updateGridOrganism(x, y - 1, world->getGridOrganism(x,y));
						world->emptyGridOrganism(x, y);
					}
					break;
				case 4: // move down
					if(y < SIZE_WORLD - 1 && (world->grid[x][y + 1] == NULL || world->grid[x][y + 1]->OrganismSpecies() != DOODLE_BUG)){
						world->updateGridOrganism(x, y + 1, world->getGridOrganism(x,y));
						world->emptyGridOrganism(x, y);
					}
					break;
				default:
					break;
			}
		}
	};
	void DoodleBug::Breed(){
		/* Breed. If a doodlebug survives for eight time steps, then at the end of the  time step it will spawn
		 * off a new doodlebug in the same manner as the ant. */

		if(survivedStepsAmount == 8){
			if(x > 0 && (world->grid[x - 1][y] == NULL || world->grid[x - 1][y]->OrganismSpecies() == EMPTY)){ // move left
				world->grid[x - 1][y] = NULL;
				world->grid[x - 1][y] = new DoodleBug(x - 1, y, world);

			} else if(x < SIZE_WORLD - 1 && (world->grid[x + 1][y] == NULL || world->grid[x + 1][y]->OrganismSpecies() == EMPTY)){ // move right
				world->grid[x + 1][y] = NULL;
				world->grid[x + 1][y] = new DoodleBug(x + 1, y, world);

			} else if(y > 0 && (world->grid[x][y - 1] == NULL || world->grid[x][y - 1]->OrganismSpecies() == EMPTY)){ // move up
				world->grid[x][y - 1] = NULL;
				world->grid[x][y - 1] = new DoodleBug(x, y - 1, world);

			} else if(y < SIZE_WORLD - 1 && (world->grid[x][y + 1] == NULL || world->grid[x][y + 1]->OrganismSpecies() == EMPTY)){ // move down
				world->grid[x][y + 1] = NULL;
				world->grid[x][y + 1] = new DoodleBug(x, y + 1, world);
			}
			survivedStepsAmount = 0;
		}
	};
	void DoodleBug::Starve(){
		/*Starve. If a doodlebug has not eaten an ant within the last three time  steps, then at the end of
		 * the third time step it will starve and die. The  doodlebug should then be removed from the grid of cells */
		if(timeSinceLastFeed >= 3){
			world->emptyGridOrganism(x, y);
		}
	};
	DoodleBug::DoodleBug(int x, int y, World *world): Organism(x, y, world){ timeSinceLastFeed = 0;}
	char DoodleBug::OrganismSpecies() { return DOODLE_BUG;}

	class Ant: public Organism {
		friend class World;
		friend class Organism;
	public:
		Ant(int x, int y, World *world);
		void Move();
		void Breed();
		void Starve();
		char OrganismSpecies();

	protected:
		int survivedStepsAmount;
	};

	Ant::Ant(int x, int y, World *world) : Organism(x, y, world){ survivedStepsAmount = 0; }
	char Ant::OrganismSpecies() {return ANT;}

	void Ant::Move(){
		/*Every time step, randomly try to move up, down, left, or right. If  the neighboring cell in the selected
		 * direction is occupied or would move  the ant off the grid, then the ant stays in the current cell.*/
		int randomMove = rand() % 5 + 1;
		 survivedStepsAmount += 1;
		switch(randomMove){
			case 1: // move left
				if(x > 0 && (world->grid[x - 1][y] == NULL || world->grid[x - 1][y]->OrganismSpecies() == EMPTY)){
					world->updateGridOrganism(x - 1, y, world->getGridOrganism(x,y));
					world->emptyGridOrganism(x, y);
				}
				break;
			case 2: // move right
				if(x < SIZE_WORLD - 1 && (world->grid[x + 1][y] == NULL || world->grid[x + 1][y]->OrganismSpecies() == EMPTY)){
					world->updateGridOrganism(x + 1, y, world->getGridOrganism(x,y));
					world->emptyGridOrganism(x, y);
				}
				break;
			case 3: // move up
				if(y > 0 && (world->grid[x][y - 1] == NULL || world->grid[x][y - 1]->OrganismSpecies() == EMPTY)){
					world->updateGridOrganism(x, y - 1, world->getGridOrganism(x,y));
					world->emptyGridOrganism(x, y);
				}
				break;
			case 4: // move down
				if(y < SIZE_WORLD - 1 && (world->grid[x][y + 1] == NULL || world->grid[x][y + 1]->OrganismSpecies() == EMPTY)){
					world->updateGridOrganism(x, y + 1, world->getGridOrganism(x,y));
					world->emptyGridOrganism(x, y);
				}
				break;
			default:
				break;
		}
	}
	void Ant::Breed(){
		/*If an ant survives for three time steps, then at the end of the time  step (that is; after moving)
		 * the ant will breed. This is simulated by creating a new ant in an adjacent (up, down, left, or right)
		 * cell that is empty.  If there is no empty cell available, then no breeding occurs. Once an offspring is
		 * produced, an ant cannot produce an offspring until three more  time steps have elapsed. */

		if(survivedStepsAmount == 3){
			if(x > 0 && (world->grid[x - 1][y] == NULL || world->grid[x - 1][y]->OrganismSpecies() == EMPTY)){ // move left
				world->grid[x - 1][y] = new Ant(x - 1, y, world);

			} else if(x < SIZE_WORLD - 1 && (world->grid[x + 1][y] == NULL || world->grid[x + 1][y]->OrganismSpecies() == EMPTY)){ // move right
				world->grid[x + 1][y] = new Ant(x + 1, y, world);

			} else if(y > 0 && (world->grid[x][y - 1] == NULL || world->grid[x][y - 1]->OrganismSpecies() == EMPTY)){ // move up
				world->grid[x][y - 1] = new Ant(x, y - 1, world);

			} else if(y < SIZE_WORLD - 1 && (world->grid[x][y + 1] == NULL || world->grid[x][y + 1]->OrganismSpecies() == EMPTY)){  // move down
				world->grid[x][y + 1] = new Ant(x, y + 1, world);

			}
			survivedStepsAmount = 0;
		}
	};
	void Ant::Starve(){/* do nothing */};
}

int main() {
	// initalize the world w/ 5 doodles and 100 ants

	int numberOfAnts = 0, numberOfDoodles = 0;
	predatorPraySim::World* world = new predatorPraySim::World();
	while(numberOfAnts != MAX_ANTS){
		int x = rand() % 21 + 1;
		int y = rand() % 21 + 1;
		if(world->getGridOrganism(x, y) == NULL){
			predatorPraySim::Ant* ant = new predatorPraySim::Ant(x, y, world);
			numberOfAnts += 1;
		}
	}
	while(numberOfDoodles != MAX_DOODLES){
		int x = rand() % 21 + 1;
		int y = rand() % 21 + 1;
		if(world->getGridOrganism(x, y) == NULL){
			predatorPraySim::Organism* doodleBug = new predatorPraySim::DoodleBug(x, y, world);
			numberOfDoodles += 1;
		}
	}
	 cout << "Press 1 and enter to increase the time step." << endl;
	int keepGoing = 1, step = 1;
	
	while(keepGoing == 1){
		cin >> keepGoing;
		world->set_timeStep(step++);
		world->playSimulation();
	}
	return 0;
}

