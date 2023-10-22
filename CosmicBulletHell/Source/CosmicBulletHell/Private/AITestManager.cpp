// Fill out your copyright notice in the Description page of Project Settings.


#include "AITestManager.h"

AITestManager::AITestManager()
{
    gridWidth = 10;
    gridHeight = 10;
}

AITestManager::~AITestManager()
{
}

AITestManager* AITestManager::GetInstance()
{
    static AITestManager Instance;
    return &Instance;
}