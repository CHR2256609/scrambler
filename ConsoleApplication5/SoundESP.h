#pragma once
#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include "Structs.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
const int VK_M4 = 5;

CHackProcess fProcess;
OffsetManager offset;
Structure retval;

class SoundESP {
public:
	struct Targets{
		int  _EntityIndex[32];
		void fillEntityIndex() {
			for (int i = 0; i < 32; i++) {
				if (retval.PlayerList[i].teamNum == 2 || retval.PlayerList[i].teamNum == 3)
					_EntityIndex[i] = i;
				else _EntityIndex[i] = 0;
			}
		}

	}TargetList;

	int GetRangeFromCfg() {
		std::ifstream outfile("C:\\Users\\cfg\\range.ini");
		std::string str;
		while (std::getline(outfile, str))
		{

		}

		int range = stoi(str);
		outfile.close();
		return range;
	}
	int GetModeFromCfg() {
		std::ifstream outfile("C:\\Users\\cfg\\mode.ini");
		std::string str;
		while (std::getline(outfile, str))
		{

		}

		int mode = stoi(str);
		outfile.close();
		return mode;
	}

	BOOL F0IWL36N0J(int x) {
		retval.PlayerList[1].P7S0TIA1QP();
		bool xy = false;
		return x;
	}

	float FRCTBS7YYO() {
		return 0;

	}
	double DN92T7WRVI() {
		FRCTBS7YYO();

		return 10;
	}
	//bool checkEntityIndex() {
		//int target = retval.MyPlayer.value;
		//if (target % 2 == 0 && retval.MyPlayer.teamNum == 2)
	//		return true;
		//if (target % 2 != 0 && retval.MyPlayer.teamNum == 3)
			//return true;
		//return false;
	//}



	//t is odd -- false ct is even -- true
	bool checkEntityIndex() {
		for (int i = 0; i < 32; i++) {
			int entityToCheck = TargetList._EntityIndex[i];
			if (retval.MyPlayer.value == entityToCheck && retval.MyPlayer.teamNum != retval.PlayerList[entityToCheck].teamNum)
				return true;
		}
		return false;
	}


	void QuasiWallhack() {
		for (int i = 0; i < 32; i++) {
			retval.PlayerList[i].ReadEntityList(i);
			if (retval.MyPlayer.teamNum != retval.PlayerList[i].teamNum && retval.PlayerList[i].teamNum != 0) {
				float distance = (float)sqrt((pow((retval.PlayerList[i].Coords[0] - retval.MyPlayer.Coords[0]), 2.0f)) + (pow((retval.PlayerList[i].Coords[1] - retval.MyPlayer.Coords[1]), 2.0f)) + (pow((retval.PlayerList[i].Coords[2] - retval.MyPlayer.Coords[2]), 2.0f)));
				if (distance < GetRangeFromCfg() && GetModeFromCfg() == 0) {
					PlaySound("C:\\Users\\beep-03.wav", NULL, SND_FILENAME);
				}
				if (distance < GetRangeFromCfg() && GetModeFromCfg() == 1 && GetAsyncKeyState(VK_M4)) {
					if(distance < 450 && distance > 0)
						PlaySound("C:\\Users\\beep-03 - low.wav", NULL, SND_FILENAME);
					if(distance < 800 && distance > 450)
						PlaySound("C:\\Users\\beep-03.wav", NULL, SND_FILENAME);
					if(distance > 800 && distance < GetRangeFromCfg())
						PlaySound("C:\\Users\\beep-03 - high.wav", NULL, SND_FILENAME);
				}
			}
		}
	}
	
	void DistanceFromPlayer() {
		for (int i = 0; i < 32; i++) {
			retval.PlayerList[i].ReadEntityList(i);
			if (retval.MyPlayer.teamNum != retval.PlayerList[i].teamNum && retval.PlayerList[i].teamNum != 0 && retval.PlayerList[i].health != 0) {
				float distance = (float)sqrt((pow((retval.PlayerList[i].Coords[0] - retval.MyPlayer.Coords[0]), 2.0f)) + (pow((retval.PlayerList[i].Coords[1] - retval.MyPlayer.Coords[1]), 2.0f)) + (pow((retval.PlayerList[i].Coords[2] - retval.MyPlayer.Coords[2]), 2.0f)));
				if (distance < 800) {
					std::cout << " There is an enemy close to you!! " << distance << std::endl;
				}


			}



		}


	}



	int ACH4KS81DA() {
		return 0;

	}
	float GGT68LVY7S(int vSauce) {
		vSauce = 10 + 10;
		return 500;

	}
	double X7BGW35S4I() {
		int x, y = 0;
		if (x = y)
			x = 2 + 2;
		return x;
	}

	void Trigger_Bot() {
		TargetList.fillEntityIndex();

		int randSleepTime = rand() % 55 + 25;
		int randSleepTime2 = rand() % 20 + 5;
		if (retval.MyPlayer.value > 0)
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			Sleep(randSleepTime2);
		}
		
	}
	void RCS() {
		POINT p;
		GetCursorPos(&p);
		HWND window = FindWindow("TaskManagerWindow", "Counter-Strike: Global Offensive");
		if (window)
		{
			RECT rect = { 0 };
			GetWindowRect(window, &rect);

			SetForegroundWindow(window);
			SetActiveWindow(window);
			SetFocus(window);
			Sleep(300);
			SetCursorPos(rect.right - 200, rect.bottom - 200);
		}


	}



};

extern SoundESP s_esp;

