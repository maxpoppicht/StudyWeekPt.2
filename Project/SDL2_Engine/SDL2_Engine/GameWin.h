#pragma once

#pragma region project include
#include "Scene.h"
#pragma endregion

#pragma region forward decleration
class GWorld;
#pragma endregion

/// <summary>
/// main game scene class
/// </summary>
class GGameWin : public CScene
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	GGameWin() : CScene() {}

	GGameWin(SVector2 WinPoint);

	SVector2 m_winpoint;
#pragma endregion

#pragma region public override function
	/// <summary>
	/// initialize scene
	/// </summary>
	virtual void Init() override;

	/// <summary>
	/// cleaning up scene
	/// </summary>
	virtual void Clean() override;
#pragma endregion

public:
#pragma region private variable
	/// <summary>
	/// world
	/// </summary>
	GWorld* m_pGameWin;
#pragma endregion

};
