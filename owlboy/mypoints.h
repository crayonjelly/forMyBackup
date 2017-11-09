#pragma once

//=============================================================
// PTFLOAT, PTINT 만들어 쓰자
//=============================================================

//실수가 우선이라서 PTFLOAT 먼저 정의한다

//PTFLOAT의 PTINT 형변환을 위한 PTINT 구조체 전방선언
struct PTINT;

struct PTFLOAT
{
	float x;
	float y;

	PTFLOAT() : x(0.0f), y(0.0f) {}
	PTFLOAT(float X, float Y) : x(X), y(Y) {}

	//연산자 오버로딩
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

	//스칼라 값 반환
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

	//연산자 오버로딩
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

	//스칼라 값 반환
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
