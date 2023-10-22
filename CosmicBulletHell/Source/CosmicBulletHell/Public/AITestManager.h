// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class COSMICBULLETHELL_API AITestManager
{
public:
	AITestManager();
	~AITestManager();
	static AITestManager* GetInstance();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AITestManager")
	int gridWidth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AITestManager")
	int gridHeight;	
};
