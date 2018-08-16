#pragma region project include

#include "MainScene.h"
#include "World.h"
#include "ContentManagement.h"
#include "GameWin.h"
#include "Player.h"
#include "Object.h"
#pragma endregion
/// <summary>
/// Komplett Max
/// </summary>
/// 
#pragma region public override function
GGameWin::GGameWin(SVector2 WinPoint)
{
	m_winpoint = WinPoint;
}
// initialize scene
void GGameWin::Init()
{
	 CTexturedObject * pGameWin = new CTexturedObject(
	 	SVector2(m_winpoint.X - SCREEN_WIDTH / 2 + PLAYER_WIDTH / 2, m_winpoint.Y - SCREEN_HEIGHT / 2 + PLAYER_HEIGHT / 2),
	 	SVector2(1280, 720),
	 	CEngine::Get()->GetRenderer(),
	 	"Texture/World/GameWin.png");
	 pGameWin->SetSrcRect(SRect(0, 0, 1280, 720));
	 
	 CEngine::Get()->GetCM()->AddPersistantObject(pGameWin);
	 CEngine::Get()->GetCM()->AddSceneObject(pGameWin);
}

// cleaning up scene
void GGameWin::Clean()
{
	// delete world
	delete m_pGameWin;
}
#pragma endregion