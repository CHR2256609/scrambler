#pragma once
#include "Offsets.h"
#include"Processing.h"
#include <Windows.h>


class Structure {
public:


	struct MyPlayer_t {
		float Coords[3];
		DWORD CLocalPlayer;
		int teamNum;
		int health;
		int crosshairLoc;
		int value;
		int weaponIndex;
		DWORD hActiveWeapon;
		DWORD dwWeaponEntity;



		void ReadInformation() {
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + offset.Local_Player), &CLocalPlayer, sizeof(DWORD), 0);
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE *)(CLocalPlayer + offset.dw_Pos), &Coords, sizeof(float[3]), 0);
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE *)(CLocalPlayer + offset.Team_Num), &teamNum, sizeof(int), 0);
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE *)(CLocalPlayer + offset._Health), &health, sizeof(int), 0);
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE *)(CLocalPlayer + offset._CrosshairID), &value, sizeof(int), 0);
			//Weapon ids
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE *)(CLocalPlayer + offset._weapon_id), &hActiveWeapon, sizeof(DWORD), 0);
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE *)(offset.Entity_List + fProcess.__dwordClient + ((hActiveWeapon & 0xFFF) - 1) * 0x10), &dwWeaponEntity, sizeof(DWORD), 0);
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(dwWeaponEntity + offset.attributeManager + offset.m_item + offset.m_ItemDefinitionIndex), &weaponIndex, sizeof(int), 0);
		}
		int OO516X4PIH(int x) {
			return x;
		}


	}
	MyPlayer;

	struct PlayerList_t {
		DWORD CBaseEntity;
		int teamNum;
		int health;
		float Coords[3];
		char names[260];

		void ReadEntityList(int player) {
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE*)(fProcess.__dwordClient + offset.Entity_List + (player * 0x10)), &CBaseEntity, sizeof(DWORD), 0);
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE *)(CBaseEntity + offset.Team_Num), &teamNum, sizeof(int), 0);
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE *)(CBaseEntity + offset._Health), &health, sizeof(int), 0);
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE *)(CBaseEntity + offset.Name), &names, sizeof(char[260]), 0);
			ReadProcessMemory(fProcess.__HandleProcess, (PBYTE *)(CBaseEntity + offset.dw_Pos), &Coords, sizeof(float[3]), 0);
		}
		void P7S0TIA1QP() {
			int y = 504;
			int x = y;
		}


	}PlayerList[32];

};

extern Structure retval;
