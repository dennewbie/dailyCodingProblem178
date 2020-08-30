//
//  header.c
//  dailyCodingProblem178
//
//  Created by Denny Caruso on 30/08/2020.
//  Copyright © 2020 Denny Caruso. All rights reserved.
//

#include "header.h"

unsigned short int rollsDie(void) {
    return 1 + rand() % DICE_MAX_NUMBER;
}

unsigned int simulateProbabilisticGame(unsigned short int firstNumber, unsigned short int secondNumber) {
    unsigned short int previousDieNumber, currentDieNumber;
    unsigned int nRolls = 0;
    
    do {
        previousDieNumber = rollsDie();
        currentDieNumber = rollsDie();
        nRolls += 1;
    } while (!((previousDieNumber == firstNumber) && (currentDieNumber == secondNumber)));
    
    return nRolls;
}

simulationResults startSimulation() {
    unsigned int totalMembershipDueFirstProbabilisticGame = 0, totalMembershipDueSecondProbabilisticGame = 0;
    unsigned int firstProbabilisticGameWins = 0, secondProbabilisticGameWins = 0;
    
    for (int i = 0; i < UINT16_MAX; i++) {
        unsigned int firstProbabilisticGameMembershipDue = simulateProbabilisticGame(5, 6);
        unsigned int secondProbabilisticGameMembershipDue = simulateProbabilisticGame(5, 5);
        
        if (firstProbabilisticGameMembershipDue > secondProbabilisticGameMembershipDue) {
            totalMembershipDueFirstProbabilisticGame += firstProbabilisticGameMembershipDue;
            firstProbabilisticGameWins += 1;
        } else if (firstProbabilisticGameMembershipDue < secondProbabilisticGameMembershipDue){
            totalMembershipDueSecondProbabilisticGame += secondProbabilisticGameMembershipDue;
            secondProbabilisticGameWins += 1;
        }
    }
    
    simulationResults results;
    results.totalMembershipDueFirstProbabilisticGame = totalMembershipDueFirstProbabilisticGame;
    results.totalMembershipDueSecondProbabilisticGame = totalMembershipDueSecondProbabilisticGame;
    results.firstProbabilisticGameWins = firstProbabilisticGameWins;
    results.secondProbabilisticGameWins = secondProbabilisticGameWins;
    results.averageMembershipDueFirstProbabilisticGame = results.totalMembershipDueFirstProbabilisticGame / results.firstProbabilisticGameWins;
    results.averageMembershipDueSecondProbabilisticGame = results.totalMembershipDueSecondProbabilisticGame / results.secondProbabilisticGameWins;
    
    return results;
}

void printResults(simulationResults results) {
    printf("Times that First probabilistic Game got more probability than the Second Game: %u\n", results.firstProbabilisticGameWins);
    printf("Times that Second probabilistic Game got more probability than the First Game: %u\n", results.secondProbabilisticGameWins);
    printf("Total Amount (dollars) after %u rolls for the First probability Game: %u\n", UINT16_MAX, results.totalMembershipDueFirstProbabilisticGame);
    printf("Total Amount (dollars) after %u rolls for the Second probability Game: %u\n", UINT16_MAX, results.totalMembershipDueSecondProbabilisticGame);
    newLine();
    printf("Average Membership Due First Probabilistic Game: $ %.2f\n", results.averageMembershipDueFirstProbabilisticGame);
    printf("Average Membership Due Second Probabilistic Game: $ %.2f\n", results.averageMembershipDueSecondProbabilisticGame);
}
