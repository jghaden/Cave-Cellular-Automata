#include "PCH.h"

#include "System.h"
#include "CaveGenerator.h"

int main(void)
{
	SetWindowSize(1160, 700);
	ShowConsoleCursor(false);

	/*
	Creates Map object with a
	width of 140 and height 40
	Birth limit of 4 cells
	Death limit of 3 cells
	Chance to start alive at 40%
	*/
	Map cave(140, 40, 4, 3, 0.4f);

	while(true)
	{
		cave.Generate();

		for (int i = 0; i < 10; i++)
		{
			cave.ShowMap();

			cave.SimulationStep();
		}

		cave.Reset();

		Sleep(3000);
	}
}