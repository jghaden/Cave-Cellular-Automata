#include "PCH.h"

#include "System.h"
#include "CaveGenerator.h"

Map::Map(int width, int height, int birthLimit, int deathLimit, float chanceToStartAlive)
{
	this->width = width;
	this->height = height;
	this->birthLimit = birthLimit;
	this->deathLimit = deathLimit;
	this->chanceToStartAlive = chanceToStartAlive;

	Init();
}

void Map::Init()
{
	cellMap.clear();
	tmpMap.clear();

	cellMap.resize(width, std::vector<bool>(height, false));
	tmpMap.resize(width, std::vector<bool>(height, false));
}

void Map::Reset() { Init(); }

// Getters
bool Map::GetState(int x, int y) { return cellMap[x][y]; }
int Map::GetWidth() { return width; }
int Map::GetHeight() { return height; }
int Map::GetBirthLimit() { return birthLimit; }
int Map::GetDeathLimit() { return deathLimit; }
float Map::GetChanceToStartAlive() { return chanceToStartAlive; }

// Setters
void Map::SetState(int x, int y, bool state) { cellMap[x][y] = state; }

void Map::Generate()
{
	srand(time(NULL));

	for (int x = 0; x < GetWidth(); x++)
	{
		for (int y = 0; y < GetHeight(); y++)
		{
			float r = static_cast<float>(rand() / static_cast<float>(RAND_MAX));

			if (r < GetChanceToStartAlive())
			{
				SetState(x, y, true);
			}
		}
	}
}

void Map::SimulationStep()
{
	int neighbors;

	for (int x = 0; x < GetWidth(); x++)
	{
		for (int y = 0; y < GetHeight(); y++)
		{
			neighbors = GetNeighbors(x, y);

			if (GetState(x,y))
			{
				if (neighbors < GetDeathLimit())
				{
					tmpMap[x][y] = false;
				}
				else
				{
					tmpMap[x][y] = true;
				}
			}
			else
			{
				if (neighbors > GetBirthLimit())
				{
					tmpMap[x][y] = true;
				}
				else
				{
					tmpMap[x][y] = false;
				}
			}
		}
	}

	cellMap = tmpMap;
}

int Map::GetNeighbors(int x, int y)
{
	int count = 0;
	for (int i = -1; i < 2; i++)
	{
		for (int j = -1; j < 2; j++)
		{
			int neighbor_x = x + i;
			int neighbor_y = y + j;

			if (i == 0 && j == 0)
			{
				// Skip current cell
			}
			// Edge of the map
			else if (neighbor_x < 0 || neighbor_y < 0 || neighbor_x >= GetWidth() || neighbor_y >= GetHeight())
			{
				count++;
			}
			// Inside of the map
			else if (GetState(neighbor_x, neighbor_y))
			{
				count++;
			}
		}
	}

	return count;
}

void Map::ShowMap()
{
	for (int x = 0; x < GetWidth(); x++)
	{
		for (int y = 0; y < GetHeight(); y++)
		{
			if (GetState(x, y))
			{
				WriteAt(x, y, 'Û');
			}
			else
			{
				WriteAt(x, y, ' ');
			}
		}

		std::cout << std::endl;
	}
}