#pragma once

#include "PCH.h"

class Map
{
private:
	int width, height;
	int birthLimit, deathLimit;

	float chanceToStartAlive;

	std::vector<std::vector<bool>> cellMap;
	std::vector<std::vector<bool>> tmpMap;
public:
	Map(int width, int height, int birthLimit, int deathLimit, float chanceToStartAlive);

	void Init();
	void Generate();
	void SimulationStep();
	void ShowMap();
	
	// Getters
	bool GetState(int x, int y);

	int GetWidth();
	int GetHeight();
	int GetBirthLimit();
	int GetDeathLimit();
	
	float GetChanceToStartAlive();

	std::vector<std::vector<bool>> GetMap();

	int GetNeighbors(int x, int y);

	// Setters
	void SetState(int x, int y, bool state);
	void SetMap(Map &map);
};