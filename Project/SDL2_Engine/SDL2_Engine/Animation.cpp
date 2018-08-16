#include "Animation.h"
// erstellt von Timo

CAnimation::CAnimation(SVector2 _pos, SVector2 _size, CRenderer * _pRenderer, const char * _pFileName, int h, int b, int x, int y, float _frameTime) : CTexturedObject(_pos, _size, _pRenderer, _pFileName)
{
	m_currentFrame = 0;
	m_frameTotal = x * y;
	m_frameX = x;
	m_frameY = y;
	m_currentSRect = SRect(0, 0, b / m_frameX, h / m_frameY);
	m_srcRect = m_currentSRect;
	m_frameTime = _frameTime;
	//m_rect.w = m_currentSRect.w;
	//m_rect.h = m_currentSRect.h;
}

bool CAnimation::Update(float _deltaTime)
{
	m_position = m_parent->GetPosition();
	CTexturedObject::Update(_deltaTime);

	if (!m_animationActive)
	{
		return true;
	}


	if (m_frameTotal == 1)
	{
		return true;
	}
	m_frameTimeLeft -= _deltaTime;
	if (m_frameTimeLeft < 0)
	{
		m_frameTimeLeft += m_frameTime;
		m_currentFrame = (m_currentFrame + 1) % m_frameTotal;
		int x;
		int y;
		x = (m_currentFrame % m_frameX) * m_currentSRect.w;
		y = (m_currentFrame / m_frameX) * m_currentSRect.h;
		m_srcRect.x = x;
		m_srcRect.y = y;
	}
	return true;
}


void CAnimation::Render(CRenderer * _pRenderer)
{

	if (m_animationActive)
	{
		CTexturedObject::Render(_pRenderer);
	}

}

void CAnimation::SetAnimationActive(bool _animationActive)
{
	if (!m_animationActive && _animationActive)
	{
		m_currentFrame = 0;
	}
	m_animationActive = _animationActive;
}


CAnimation::~CAnimation()
{
}
