#include "PCH.h"

#include "System.h"
#include "CaveGenerator.h"

int main(void)
{
	ShowConsoleCursor(false);

	Map cave(80, 25, 4, 3, 0.38f);
	cave.Init();

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