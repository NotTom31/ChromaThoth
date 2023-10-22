// Fill out your copyright notice in the Description page of Project Settings.


#include "QLearningAgent.h"

QLearningAgent::QLearningAgent()
{
}

QLearningAgent::~QLearningAgent()
{
}

TMap<FString, float> QLearningAgent::GetWeights() {
	return weights;
}

float QLearningAgent::GetQValue(GameState state, GameAction action) {
	TMap<FString, float> featureVector = GetFeatureVector(state, action);
	weights = GetWeights();
	float dotproduct = 0.0f;

	for (const TPair<FString, float>& Item : featureVector) {
		FString key = Item.Key;
		float value = Item.Value;
		dotproduct += weights[key] * value;
	}
	return dotproduct;
}

void QLearningAgent::Update(GameState state, GameAction action, GameState nextState, float reward) {
	float difference = (reward + discount * GetQValue(nextState, ComputeActionFromQValues(nextState))) - GetQValue(state, action);
	TMap<FString, float> featureVector = GetFeatureVector(state, action);
	weights = GetWeights();

	for (const TPair<FString, float>& Item : featureVector) {
		FString key = Item.Key;
		float value = Item.Value;
		weights[key] += alpha * difference * value;
	}
}

GameAction QLearningAgent::GetPolicy(GameState state) {
	return ComputeActionFromQValues(state);
}

float QLearningAgent::GetValue(GameState state) {
	return ComputeValueFromQValue(state);
}

//GameAction QLearningAgent::GetAction(GameState state) {
//	GameAction action;
//	if (FMath::FRand() < epsilon) {
//
//	}
//	else {
//		action = ComputeActionFromQValues(state);
//	}
//	return action;
//}

float QLearningAgent::ComputeValueFromQValue(GameState state) {
	TArray<GameAction> legalActions = GetLegalActions(state);
	if (legalActions.Num() == 0) return 0.0f;
	GameAction bestAction;
	float bestQ = -std::numeric_limits<float>::infinity();
	for each (GameAction action in legalActions)
	{
		float q = GetQValue(state, action);
		if (q > bestQ) {
			bestQ = q;
			bestAction = action;
		}
	}
	return bestQ;
}

GameAction QLearningAgent::ComputeActionFromQValues(GameState state) {
	TArray<GameAction> legalActions = GetLegalActions(state);
	GameAction bestAction;
	float bestQ = -std::numeric_limits<float>::infinity();
	if (legalActions.Num() == 0) return bestAction;
	for each (GameAction action in legalActions)
	{
		float q = GetQValue(state, action);
		if (q > bestQ) {
			bestQ = q;
			bestAction = action;
		}
		else if (q == bestQ) {
			int rand = FMath::RandRange(0, 1);
			if (rand == 1) {
				bestQ = q;
				bestAction = action;
			}
		}
	}
	return bestAction;
}

TArray<GameAction> QLearningAgent::GetLegalActions(GameState state) {
	//spawn
	TArray<GameAction> legalActions;
	for (int i = 0; i < state.numEnemiesLeft; i++) {
		legalActions.Add({ i + state.numEnemiesAlive, "spawn"});
	}
	TArray<FVector> obstacles = state.obstaclePositions;
	TArray<EnemyInfo> enemies = state.enemies;
	for (int i = 0; i < state.numEnemiesAlive; i++) {
		legalActions.Add({ i, "attack" });
		if (!obstacles.Contains(enemies[i].position + FVector::UpVector)) {
			legalActions.Add({ i, "north" });
		}
		if (!obstacles.Contains(enemies[i].position + FVector::LeftVector)) {
			legalActions.Add({ i, "east" });
		}
		if (!obstacles.Contains(enemies[i].position + FVector::RightVector)) {
			legalActions.Add({ i, "west" });
		}
		if (!obstacles.Contains(enemies[i].position + FVector::DownVector)) {
			legalActions.Add({ i, "south" });
		}
	}
	return legalActions;
}

TMap<FString, float> QLearningAgent::GetFeatureVector(GameState state, GameAction action) {
	TMap<FString, float> features;
	features.Add(TEXT("HeroHealth"), state.heroHealth); //hero health
	features.Add(TEXT("HeroPositionX"), state.heroPosition.X);//hero position
	features.Add(TEXT("HeroPositionY"), state.heroPosition.Y);//hero position
	features.Add(TEXT("HeroVelocityX"), state.heroVelocity.X);//hero position
	features.Add(TEXT("HeroVelocityY"), state.heroVelocity.Y);//hero position//hero velocity

	features.Add(TEXT("EnemiesLeft"), state.numEnemiesLeft); //enemies left
	features.Add(TEXT("EnemiesAlive"), state.numEnemiesAlive); //enemies alive
	//enemy positions
	

	features.Add(TEXT("GridX"), state.gridWidth);
	features.Add(TEXT("GridY"), state.gridHeight);//grid size
	//obstacle positions
	//grid density

	//Derived
	features.Add(TEXT("DistToClosestEnemy"), state.distanceToClosestEnemy); //closest enemy
	features.Add(TEXT("GridDensity"), state.numEnemiesAlive / (state.gridHeight * state.gridWidth));

}
