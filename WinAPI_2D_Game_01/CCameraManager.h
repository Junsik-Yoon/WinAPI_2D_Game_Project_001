#pragma once

class CGameObject;

class CCameraManager
{
	SINGLETON(CCameraManager);

private:
	Vec2 m_fptLookAt;			// ���� �ִ� ��ġ
	Vec2 m_fptCurLookAt;		// ī�޶� ���� ���� ��ġ
	Vec2 m_fptPrevLookAt;		// ī�޶� ������ ���� ��ġ
	CGameObject* m_pTargetObj;	// Ʈ��ŷ �� ������Ʈ

	Vec2 m_fptDiff;				// �ػ� �߽ɰ� ī�޶� LookAt ������ ����

	float m_fTime = 2;			// Ÿ���� ���󰡴� �ѽð�
	float m_fAccTime;			// Ÿ���� ���� �ҿ�ð�
	float m_fSpeed;				// Ÿ���� ���󰡴� �ӵ�
	float m_fPreSpeed;			// Ÿ���� ���󰡴� �ӵ�
	float m_fAccel;				// Ÿ���� ���󰡴� ��ӵ�
	float m_fAccDir = 1.f;		// ��ӵ��� ����

private:
	void CalDiff();

public:
	void update();

	void SetLookAt(Vec2 lookAt);
	void SetTargetObj(CGameObject* target) { m_pTargetObj = target; }

	Vec2 GetLookAt()				{ return m_fptCurLookAt; }	// ���� ī�޶� ��ġ ��ȯ
	Vec2 GetRenderPos(Vec2 objPos)	{ return objPos - m_fptDiff; }
	Vec2 GetRealPos(Vec2 renderPos) { return renderPos + m_fptDiff; }// ������ ��ǥ���� ���̰���ŭ �����ָ� ���� ��ǥ�� ����.
	
};
