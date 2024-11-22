#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "entity.h"
#include "combat.h"
#include "skill.h"
#include "drawings.h"

#define PLAYER_S 0
#define PC_S 1

int main()
{   
    // Game Loop
    Entity* Player = initPlayer("Durkheim");
    DrawWelcome(Player);
    DrawEntityInformation(Player);
    
    Entity* currentEnemy = initEnemyBase(&BaseGoblin, 0);
    Combat* currentCombat = initCombat(Player, currentEnemy);

    while(true)
    {
        DrawCombatStart(currentCombat);
        if (currentCombat->currentAttacker == PLAYER_S)
        {
            // Player Round.
        } else
        {
            //PC ROUND.
        }
        getc(stdin);
    }
}