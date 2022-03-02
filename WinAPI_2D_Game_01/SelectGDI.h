#pragma once

class SelectGDI
{
private:
	HDC m_hDC;
	HPEN m_hOldPen;
	HBRUSH m_hOldBrush;
public:

	SelectGDI(HDC hDC, TYPE_PEN type)
	{
		m_hDC = hDC;
		HPEN hPen = CCore::getInst()->GetPen(type);
		m_hOldPen = (HPEN)SelectObject(hDC, hPen);
	}
	SelectGDI(HDC hDC, TYPE_BRUSH type)
	{
		m_hDC = hDC;
		HBRUSH hBrush = CCore::getInst()->GetBrush(type);
		m_hOldBrush = (HBRUSH)SelectObject(hDC, hBrush);
	}
	~SelectGDI()
	{
		SelectObject(m_hDC, m_hOldBrush);
		SelectObject(m_hDC, m_hOldPen);
	}
};

