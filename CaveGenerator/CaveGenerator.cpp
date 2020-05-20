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
}

void Map::Init()
{
	cellMap.clear();
	tmpMap.clear();

	cellMap.resize(height, std::vector<bool>(width, false));
	tmpMap.resize(height, std::vector<bool>(width, false));
}

void Map::Reset() { Init(); }

// Getters
bool Map::GetState(int x, int y) { return cellMap[y][x]; }

int Map::GetWidth() { return width; }
int Map::GetHeight() { return height; }
int Map::GetBirthLimit() { return birthLimit; }
int Map::GetDeathLimit() { return deathLimit; }

float Map::GetChanceToStartAlive() { return chanceToStartAlive; }

std::vector<std::vector<bool>> Map::GetMap() { return cellMap; }

// Setters
void Map::SetState(int x, int y, bool state) { cellMap[y][x] = state; }
void Map::SetMap(Map &map) { this->cellMap = map.cellMap; }

void Map::Generate()
{
	srand(time(NULL));

	for (int y = 0; y < GetHeight(); y++)
	{
		for (int x = 0; x < GetWidth(); x++)
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

	for (int y = 0; y < GetHeight(); y++)
	{
		for (int x = 0; x < GetWidth(); x++)
		{
			neighbors = GetNeighbors(x, y);

			if (GetState(x,y))
			{
				if (neighbors < GetDeathLimit())
				{
					tmpMap[y][x] = false;
				}
				else
				{
					tmpMap[y][x] = true;
				}
			}
			else
			{
				if (neighbors > GetBirthLimit())
				{
					tmpMap[y][x] = true;
				}
				else
				{
					tmpMap[y][x] = false;
				}
			}
		}
	}

	cellMap = tmpMap;
}

int Map::GetNeighbors(int x, int y)
{
	int count = 0;
	for (int j = -1; j < 2; j++)
	{
		for (int i = -1; i < 2; i++)
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
	for (int y = 0; y < GetHeight(); y++)
	{
		for (int x = 0; x < GetWidth(); x++)
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