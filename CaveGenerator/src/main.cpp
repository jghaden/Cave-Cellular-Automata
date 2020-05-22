#include "PCH.h"

#include "System.h"
#include "CaveGenerator.h"

int main(void)
{
	ShowConsoleCursor(false);

	/*
	Creates Map object with a
	width of 80 and height 25
	Birth limit of 4 cells
	Death limit of 3 cells
	Chance to start alive at 38%
	*/
	Map cave(140, 40, 4, 3, 0.40f);
	system("mode 142, 42");

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