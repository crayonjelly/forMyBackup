#pragma once

//=============================================================
// PTINT, PTFLOAT 만들어 쓰자
//=============================================================

struct PTINT
{
	int x;
	int y;

	PTINT() : x(0), y(0) {}
	PTINT(int X, int Y) : x(X), y(Y) {}

	//연산자 오버로딩
	PTINT operator+ (PTINT pt)
	{
		return PTINT(x + pt.x, y + pt.y);
	}
	PTINT operator- (PTINT pt)
	{
		return PTINT(x - pt.x, y - pt.y);
	}
	PTINT operator* (int scalar)
	{
		return PTINT(x * scalar, y * scalar);
	}
	PTINT operator* (float scalar)
	{
		return PTINT(x * scalar, y * scalar);
	}
	PTINT operator/ (int scalar)
	{
		return PTINT(x / scalar, y / scalar);
	}
	PTINT operator/ (float scalar)
	{
		return PTINT(x / scalar, y / scalar);
	}
	bool operator== (PTINT pt)
	{
		return (x == pt.x && y == pt.y);
	}
	bool operator!= (PTINT pt)
	{
		return !(x == pt.x && y == pt.y);
	}
};

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
		this->x -= pt.x;
		this->y -= pt.y;
		return *this;
	}
};
