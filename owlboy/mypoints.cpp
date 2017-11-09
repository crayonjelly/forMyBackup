#include "stdafx.h"
#include "mypoints.h"


PTFLOAT::operator PTINT()
{
	return PTINT(x, y);
}

PTINT::operator PTFLOAT()
{
	return PTFLOAT(x, y);
}
