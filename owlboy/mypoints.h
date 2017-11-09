#pragma once

//=============================================================
// PTFLOAT, PTINT ����� ����
//=============================================================

//�Ǽ��� �켱�̶� PTFLOAT ���� �����Ѵ�

//PTFLOAT�� PTINT ����ȯ�� ���� PTINT ����ü ���漱��
struct PTINT;

struct PTFLOAT
{
	float x;
	float y;

	PTFLOAT() : x(0.0f), y(0.0f) {}
	PTFLOAT(float X, float Y) : x(X), y(Y) {}

	//������ �����ε�
	PTFLOAT operator+ (const PTFLOAT &pt)
	{
		return PTFLOAT(x + pt.x, y + pt.y);
	}
	PTFLOAT operator- (const PTFLOAT &pt)
	{
		return PTFLOAT(x - pt.x, y - pt.y);
	}
	PTFLOAT operator* (const int &scalar)
	{
		return PTFLOAT(x * scalar, y * scalar);
	}
	PTFLOAT operator* (const float &scalar)
	{
		return PTFLOAT(x * scalar, y * scalar);
	}
	PTFLOAT operator/ (const int &scalar)
	{
		return PTFLOAT(x / scalar, y / scalar);
	}
	PTFLOAT operator/ (const float &scalar)
	{
		return PTFLOAT(x / scalar, y / scalar);
	}
	bool operator== (const PTFLOAT &pt)
	{
		return (x == pt.x && y == pt.y);
	}
	bool operator!= (const PTFLOAT &pt)
	{
		return !(x == pt.x && y == pt.y);
	}

	PTFLOAT& operator+= (const PTFLOAT &pt)
	{
		x += pt.x;
		y += pt.y;
		return *this;
	}
	PTFLOAT& operator-= (const PTFLOAT &pt)
	{
		x -= pt.x;
		y -= pt.y;
		return *this;
	}

	operator PTINT();

	//��Į�� �� ��ȯ
	float scalar() { return sqrtf(x * x + y * y); }

	PTFLOAT unit()
	{
		float scalar = sqrtf(x * x + y * y);
		if (scalar == 0)
		{
			return PTFLOAT(0, 0);
		}
		else
		{
			return PTFLOAT(x / scalar, y / scalar);
		}
	}
};

struct PTINT
{
	int x;
	int y;

	PTINT() : x(0), y(0) {}
	PTINT(int X, int Y) : x(X), y(Y) {}

	//������ �����ε�
	PTINT operator+ (const PTINT &pt)
	{
		return PTINT(x + pt.x, y + pt.y);
	}
	PTINT operator- (const PTINT &pt)
	{
		return PTINT(x - pt.x, y - pt.y);
	}
	PTINT operator* (const int &scalar)
	{
		return PTINT(x * scalar, y * scalar);
	}
	PTINT operator* (const float &scalar)
	{
		return PTINT(x * scalar, y * scalar);
	}
	PTINT operator/ (const int &scalar)
	{
		return PTINT(x / scalar, y / scalar);
	}
	PTINT operator/ (const float &scalar)
	{
		return PTINT(x / scalar, y / scalar);
	}
	bool operator== (const PTINT &pt)
	{
		return (x == pt.x && y == pt.y);
	}
	bool operator!= (const PTINT &pt)
	{
		return !(x == pt.x && y == pt.y);
	}

	PTINT& operator+= (const PTINT &pt)
	{
		x += pt.x;
		y += pt.y;
		return *this;
	}
	PTINT& operator-= (const PTINT &pt)
	{
		x -= pt.x;
		y -= pt.y;
		return *this;
	}

	operator PTFLOAT();

	//��Į�� �� ��ȯ
	float scalar() { return sqrtf(x * x + y * y); }

	PTFLOAT unit()
	{
		float scalar = sqrtf(x * x + y * y);
		if (scalar == 0)
		{
			return PTFLOAT(0, 0);
		}
		else
		{
			return PTFLOAT(x / scalar, y / scalar);
		}
	}
};
