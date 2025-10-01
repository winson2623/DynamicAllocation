#include <iostream>
using namespace std;

//not given in assignment
class Team {};

class Player {
public:
	Player(int nplayers) :num_players(nplayers), team(nullptr) {
		points = new int[num_players];
		for (int i = 0; i < num_players; i++) {
			points[i] = 0;
		}
	}

	//COPY CONSTRUCTOR
	Player(const Player& original) {
		num_players = original.num_players;	//copy num_players
		team = original.team;					//shallow copy of team because no new operator

		points = new int[num_players];
		for (int i = 0; i < num_players; i++) {
			points[i] = original.points[i];	//copies the points into original.points instead of hardcoded int
		}
	}

	//ASSIGNMENT OPERATOR
	Player& operator=(const Player& original) {
		//check for self assign
		if (this == &original)  return *this;

		//check if null
		if (original.points == nullptr) {
			points = nullptr;
		}

		//clean up
		delete[] points;

		//repeat copy constructor
		num_players = original.num_players;	
		team = original.team;					
		points = new int[num_players];
		for (int i = 0; i < num_players; i++) {
			points[i] = original.points[i];	
		}
		
		//return self
		return *this;
	}

	void join(Team* t) {
		team = t;
	}

	//void foo() {
	//	Player p; //does not run because there is no default constructor, it requires int
	//}

	void toe() {
		Player p(10);
	}

	//DESTRUCTOR
	~Player() { 
		delete[] points; 
	}
private:
	int* points;
	int num_players;
	Team * team; //since its a pointer, doesnt need full definition only class declaration
};


int main() {
	int **rows; int *col1; int *col2; int *col3;

	rows = new int*[3]; // Create 3 pointers to columns
	col1 = new int[4]; // Create first row with 4 elements
	col2 = new int[4]; // Create second row with 4 elements
	col3 = new int[4]; // Create third row with 4 elements

	*(rows + 0) = &col1[0]; // Point to first row
	*(rows + 1) = &col2[0]; // Point to second row
	*(rows + 2) = &col3[0]; // Point to third row

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			*(*(rows + i) + j) = 0;// same as rows[i][j] = 0;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << *(*(rows + i) + j) << " ";
		}
		cout << endl;
	}
	return 0;
}
