#pragma once

#pragma region project include
#include "Animal.h"
#pragma endregion

/// <summary>
/// cat class
/// </summary>
class Dog : public Animal
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	Dog() : Dog("Dog") {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_name">name of cat</param>
	Dog(const char* _name) : Animal(_name)
	{
		m_health = 150;
		m_strength = 25;
		m_defense = 7;
	}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// eat function
	/// </summary>
	void Eat() override;

	/// <summary>
	/// noise of cat
	/// </summary>
	void MakeNoise() override;
#pragma endregion
};