#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "player.h"
#include "combat.h"
#include "skill.h"
#include "drawings.h"

int main()
{   
    // Game Loop
    Entity* Player = initPlayer("Durkheim");
    DrawWelcome(Player);
    DrawEntityInformation(Player);
    while(true)
    {

    }
}