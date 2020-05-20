#include "PCH.h"

#include "System.h"
#include "CaveGenerator.h"

int main(void)
{
	ShowConsoleCursor(false);

	Map cave(60, 20, 4, 3, 0.35f);
	cave.Init();

	while(true)
	{
		cave.Generate();

		for (int i = 0; i < 10; i++)
		{
			cave.ShowMap();

			cave.SimulationStep();
		}

		Sleep(3000);
	}
}