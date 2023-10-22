// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <tuple>


/**
 * 
 */

class COSMICBULLETHELL_API QLearningAgent
{
public:
	QLearningAgent();
	~QLearningAgent();

	float discount;
	float alpha;
	float epsilon;

	TMap<TTuple<GameState, GameAction>, float> qvalues;
	float GetQValue(GameState state, GameAction action);

	TMap<FString, float> weights;
	TMap<FString, float> GetWeights();

	float ComputeValueFromQValue(GameState state);
	GameAction ComputeActionFromQValues(GameState state);
	GameAction GetPolicy(GameState state);
	float GetValue(GameState state);

	//GameAction GetAction(GameState state);
	void Update(GameState state, GameAction action, GameState nextState, float reward);
	TMap<FString, float> GetFeatureVector(GameState state, GameAction action);

private:
	TArray<GameAction> GetLegalActions(GameState state);
};


class GameState {
public:
	//hero info
	FVector heroPosition;
	FVector heroVelocity;
	float heroHealth;
	TArray<ProjectileInfo> heroBullets;

	//map info
	int gridWidth;
	int gridHeight;
	TArray<TArray<int>> gridDensity;
	TArray<FVector> obstaclePositions;

	//enemy info
	int numEnemiesAlive;
	int numEnemiesLeft;
	TArray<EnemyInfo> enemies;
	float distanceToClosestEnemy;
	TArray<ProjectileInfo> enemyBullets;

};
struct ProjectileInfo {
	FVector position;
	FVector velocity;
	int unitID;
};
struct EnemyInfo {
	FVector position;
	FVector velocity;
	int unitID;
	bool isSpawned;
};
struct GameAction {
	int unitID;
	FString action; //spawn, north, east, south, west, attack
};