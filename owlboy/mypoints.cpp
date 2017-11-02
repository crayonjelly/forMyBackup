#include "stdafx.h"
#include "mypoints.h"


PTINT::operator PTFLOAT()
{
	return PTFLOAT(x, y);
}

PTFLOAT::operator PTINT()
{
	return PTINT(x, y);
}
