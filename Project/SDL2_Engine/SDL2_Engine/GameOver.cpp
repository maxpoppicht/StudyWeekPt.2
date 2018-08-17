#pragma region project include
#include "MainScene.h"
#include "World.h"
#include "ContentManagement.h"
#include "GameOver.h"
#pragma endregion
/// <summary>
/// Komplett Max
/// </summary>
/// <param name="DeathPoint"></param>
GGameOver::GGameOver(SVector2 DeathPoint) : CScene()
{
	m_deathpoint = DeathPoint;

	printf("%f, %f \n", m_deathpoint.X, m_deathpoint.Y);

	printf("%d, %d", 13 * WORLD_BLOCK_WIDTH, 27 * WORLD_BLOCK_HEIGHT);

}


#pragma region public override function
// initialize scene
void GGameOver::Init()
{
	CTexturedObject * pGameOver = new CTexturedObject(
		SVector2(m_deathpoint.X - SCREEN_WIDTH / 2 + PLAYER_WIDTH / 2, m_deathpoint.Y - SCREEN_HEIGHT / 2 + PLAYER_HEIGHT / 2),
		SVector2(1280, 720),
		CEngine::Get()->GetRenderer(),
		"Texture/World/Scene/GameOverScreen.png");
	pGameOver->SetSrcRect(SRect(0, 0, 1280, 720));

	CEngine::Get()->GetCM()->AddPersistantObject(pGameOver);
	CEngine::Get()->GetCM()->AddSceneObject(pGameOver);
}

// cleaning up scene
void GGameOver::Clean()
{
	// delete world
	delete m_pGameOver;
}
#pragma endregion