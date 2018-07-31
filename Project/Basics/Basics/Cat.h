#pragma once

#pragma region project include
#include "Animal.h"
#pragma endregion

/// <summary>
/// cat class
/// </summary>
class Cat : public Animal
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	Cat() : Cat("Cat") {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_name">name of cat</param>
	Cat(const char* _name) : Animal(_name)
	{
		m_health = 250;
		m_strength = 10;
		m_defense = 20;
	}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// eat function
	/// </summary>
	void Eat() override;

	/// <summary>
	/// make noise function
	/// </summary>
	void MakeNoise() override;
#pragma endregion
};