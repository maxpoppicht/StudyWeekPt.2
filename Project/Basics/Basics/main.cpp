#pragma region system inculde
#include <string.h>
#include <list>
#pragma endregion

#pragma region project include
#include "Cat.h"
#include "Dog.h"
#pragma endregion

#pragma region macro
#define MAGIC_NUMBER (42)
#define SQUARE(x) (x * x)
#define PRINT(TEXT) (cout << TEXT << endl)
#define FUNC_TEST(x, y)	\
	int i = 2;			\
	i += x;				\
	PRINT(i, y)
#define CATS_COUNT 10
#define DOGS_COUNT 10
#pragma endregion

/// <summary>
/// attacks animal with animal
/// </summary>
/// <param name="_cats">list of cats</param>
/// <param name="_dogs">list of dogs</param>
/// <param name="_catAttack">if cats are attackers</param>
void AttackAnimal(list<Cat*>* _cats, list<Dog*>* _dogs, bool _catAttack)
{
	// if cats are attackers
	if (_catAttack)
	{
		// if no dogs left return
		if (_dogs->size() <= 0)
			return;

		// cat attack dog
		_cats->front()->Attack(_dogs->front());

		// if dog front not alive kill dog
		if (!_dogs->front()->GetAlive())
		{
			_dogs->pop_front();
		}
	}

	// if dogs are attackers
	else
	{
		// if no cats left return
		if (_cats->size() <= 0)
			return;

		// dog attack cat
		_dogs->front()->Attack(_cats->front());

		// if cat front not alive kill cat
		if (!_cats->front()->GetAlive())
		{
			_cats->pop_front();
		}
	}
}

/// <summary>
/// entry point of application
/// </summary>
/// <returns>code of shut down</returns>
int main() 
{
	// wenn pointer von value types aus klasse (int*) benutzen
	// cout << "Defense Pointer: " << (int)&pCat->m_defense << endl;
	// cout << "Defense Pointer: " << (int*)pCat->m_defense << endl;

	// list of cats
	list<Cat*> pCats;

	// list of dogs
	list<Dog*> pDogs;

	// random bool
	//bool startNumber = rand() % 2;

	// add cats to list
	for (int i = 0; i < CATS_COUNT; i++)
	{
		// name of cat plus number
		string name = "Cat";
		int numberOfCat = CATS_COUNT - i;
		name += numberOfCat;

		// add cat to list
		pCats.push_back(new Cat(name.c_str()));
	}

	// add dogs to list
	for (int i = 0; i < DOGS_COUNT; i++)
	{
		// name of dog plus number
		string name = "Dog";
		int numberOfDog = DOGS_COUNT - i;
		name += numberOfDog;

		// add dog to list
		pDogs.push_back(new Dog(name.c_str()));
	}

	// number of rounds
	int roundNumber = 0;

	// while cat and dogs list not empty
	while (pCats.size() > 0 && pDogs.size() > 0)
	{
		// increase round number
		roundNumber++;

		// output
		cout << "-----Round: " << roundNumber << "-----" << endl;
		cout << "cat count: " << pCats.size() << endl;
		cout << "dog count: " << pDogs.size() << endl;
		cout << "-------------------------" << endl;

		// random cat or dog
		if (rand() % 2)
		{
			// cat attacks dog
			AttackAnimal(&pCats, &pDogs, true);

			// if no list is empty
			if(pCats.size() > 0 && pDogs.size() > 0)
				// dog attack cat
				AttackAnimal(&pCats, &pDogs, false);
		}

		else
		{
			// dog attack cat
			AttackAnimal(&pCats, &pDogs, false);

			// if no list is empty
			if (pCats.size() > 0 && pDogs.size() > 0)
				// cat attacks dog
				AttackAnimal(&pCats, &pDogs, true);
		}

	}

	// increase round number
	roundNumber++;

	// output
	cout << "-----Round: " << roundNumber << "-----" << endl;
	cout << "cat count: " << pCats.size() << endl;
	cout << "dog count: " << pDogs.size() << endl;
	cout << "-------------------------" << endl;

	// char array aneinander hängen
	char* text1 = "123456";
	char* text2 = new char[6];
	char* text3 = new char[12];

	for (int i = 0; i < 6; i++)
		text2[i] = text1[i];

	for (int i = 0; i < 6; i++)
		text3[i] = text1[i];

	for (int i = 0; i < 6; i++)
		text3[i + 6] = text2[i];

	// weil text3 nicht als string erzeugt wurde
	// muss nullterminator am ende angefügt werden
	text3[12] = '\0';

	// cout << text3 << endl;

	// strings
	string s = "Hello World";
	s.append("!");

	// string zu char*
	const char* textFromString = s.c_str();

	int neu;
	cin >> neu;

	// app shut down correctly
	return 0;
}