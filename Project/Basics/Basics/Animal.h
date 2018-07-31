#ifndef __ANIMAL_h__
#define __ANIMAL_h__

#pragma region system include
#include <iostream>
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

/// <summary>
/// main animal class
/// </summary>
class Animal
{
public:
#pragma region public constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_name">name of animal</param>
	Animal(const char* _name) : m_name(_name) {};
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// attack another animal
	/// </summary>
	/// <param name="_pOther">other animal</param>
	inline void Attack(Animal* _pOther)
	{
		// if strength is higher than defense decrease health from other animal
		if (m_strength > _pOther->GetDefense())
			_pOther->DecreaseHealth(m_strength - _pOther->GetDefense());
	}

	/// <summary>
	/// animal is alive or not
	/// </summary>
	/// <returns>alive or not</returns>
	inline bool GetAlive() { return m_alive; }

	/// <summary>
	/// get health
	/// </summary>
	/// <returns>health</returns>
	inline uint8_t GetHealth() { return m_health; }

	/// <summary>
	/// set health of animal
	/// </summary>
	/// <param name="_health">health to set</param>
	inline void SetHealth(uint8_t _health) { m_health = _health; }

	/// <summary>
	/// decrease health of animal
	/// </summary>
	/// <param name="_damage">damage</param>
	/// <returns></returns>
	inline void DecreaseHealth(uint8_t _damage)
	{
		// !!! auf Datentyp aufpassen
		// uint8_t von 0 bis 255
		if (m_health <= _damage)
		{
			m_alive = false;
			m_health = 0;
		}

		else
		{
			m_health -= _damage;
		}
	}

	/// <summary>
	/// get strength
	/// </summary>
	/// <returns>strength value</returns>
	inline uint8_t GetStrength() { return m_strength; }

	/// <summary>
	/// get defense
	/// </summary>
	/// <returns>defense value</returns>
	inline uint8_t GetDefense() { return m_defense; }

#pragma endregion

#pragma region public function
	/// <summary>
	/// eat function
	/// </summary>
	virtual void Eat() = 0;

	/// <summary>
	/// make noise function
	/// </summary>
	virtual void MakeNoise() = 0;
#pragma endregion

protected:
#pragma region protected primitive variable
	/// <summary>
	/// animal is alive
	/// </summary>
	bool m_alive = true;

	/// <summary>
	/// name of animal
	/// </summary>
	const char* m_name;

	/// <summary>
	/// health of animal
	/// </summary>
	uint8_t m_health = 100;

	/// <summary>
	/// strength of animal
	/// </summary>
	uint8_t m_strength = 10;

	/// <summary>
	/// defense of animal
	/// </summary>
	uint8_t m_defense = 10;
#pragma endregion
};
#endif