#pragma once

#include "common.h"
#include "trainbase.h"

class ClassicalTrainingParameters
{
public:
    InputFormats InputFormat;
    std::string InputPath;
};

class ClassicalTrainer
{
public:
    static void Run(const ClassicalTrainingParameters& parameters);
};