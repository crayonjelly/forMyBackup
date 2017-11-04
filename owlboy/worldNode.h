#pragma once


/*
������ ����... �̭j�µ�? ��Ӵ�... ���� �������������...

���
����
����
-----
����, ��ֹ� ���� ������Ʈ
����
NPC
==========
���ΰ�
-----
����ִ� ������(���Ű���) ��ü
-----
���ΰ� ��
-----
����ִ� ���ſ�(���ڰ���) ��ü
����ִ� ����
==========
���ڰ��� ��ü
-----
������
�Ȱ�

*/

namespace OBJECT
{
	enum Enum
	{
		BACKGROUND,
		CLOUD,
		TERRAIN,
		OTUS,
		GEDDY,
		FRUIT_BLUE,
		END
	};
}

namespace LAYER
{
	enum Enum
	{
		SKY3,
		SKY2,
		SKY1,
		BACK3,
		BACK2,
		BACK1,
		//---
		TERRAIN,
		FRUIT,
		TEAM,
		NPC,
		OTUS,
		GRAB_LIGHT,
		ARM,
		GRAB_HEAVY,
		GRAB_TEAM,
		COINBOX,
		FRONT_TERRAIN,
		//---
		FRONT_GROUND,
		FOG,
		MASK,
		UI,
		END
	};
}
