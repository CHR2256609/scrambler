#pragma once
#include <Windows.h>

class OffsetManager {
public:
	const DWORD Entity_List = 0x4A8C804;
	const DWORD Local_Player = 0xAAFFFC;
	const DWORD dw_Health = 0xFC;//client
	const DWORD dw_Pos = 0x134;//v origins
	const DWORD Team_Num = 0xF0;
	const DWORD _Health = 0x000000FC;
	const DWORD Name = 0x0150;
	const DWORD _CrosshairID = 0xB2B4;
	const DWORD _weapon_id = 0x2EE8;
	const DWORD attributeManager = 0x2D70;
	const DWORD m_item = 0x2DB0;
	const DWORD m_ItemDefinitionIndex = 0x2F88;
	const DWORD dwClientState = 0x5A3334;
	
};

extern OffsetManager offset;