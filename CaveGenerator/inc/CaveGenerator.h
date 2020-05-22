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
	void Reset();
	void Generate();
	void SimulationStep();
	void ShowMap();
	void InvertMap();
	
	// Getters
	bool GetState(int x, int y);
	int GetWidth();
	int GetHeight();
	int GetBirthLimit();
	int GetDeathLimit();
	int GetNeighbors(int x, int y);
	float GetChanceToStartAlive();

	// Setters
	void SetState(int x, int y, bool state);
};