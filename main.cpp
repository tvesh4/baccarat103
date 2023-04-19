#include iostream
#include <string>
using namespace std;

class Card
{
	private:
		short int cardValue;
		string suit;
		short int face;

	public:
		//constructors
		Card();
		Card(short int, string);

		//member functions
		short int value();
		short int getFace();
		string getSuit();
