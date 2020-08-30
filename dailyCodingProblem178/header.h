//
//  header.h
//  dailyCodingProblem178
//
//  Created by Denny Caruso on 30/08/2020.
//  Copyright © 2020 Denny Caruso. All rights reserved.
//

#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define DICE_MAX_NUMBER 6
#define newLine() { printf("\n\n"); }

#endif /* header_h */

struct simulation {
    unsigned int totalMembershipDueFirstProbabilisticGame;
    unsigned int totalMembershipDueSecondProbabilisticGame;
    unsigned int firstProbabilisticGameWins;
    unsigned int secondProbabilisticGameWins;
    float averageMembershipDueFirstProbabilisticGame;
    float averageMembershipDueSecondProbabilisticGame;
};

typedef struct simulation simulationResults;

unsigned short int rollsDie(void);

unsigned int simulateProbabilisticGame(unsigned short int, unsigned short int);
simulationResults startSimulation(void);

void printResults(simulationResults);
