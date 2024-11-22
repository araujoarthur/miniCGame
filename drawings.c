#include <stdlib.h>
#include <stdio.h>
#include "drawings.h"
#include "combat.h"

void DrawWelcome(Entity* p)
{
    printf("Welcome to the Game %s\n", p->name);
}

void DrawEntityInformation(Entity* p)
{
    char* title = p->isPlayer ? "PLAYER" : "ENEMY";
    printf("%s INFORMATION\n\nNAME: %s\nLVL: %d\nEXP: %d\nHP:%.2f/%.2f\nRAW DAMAGE: %.2f\nDEFENSE: %.2f\n\n",
        title,
        p->name,
        p->level,
        p->exp,
        p->hp,
        p->max_hp,
        p->dmg,
        p->defense
    );
}

void DrawCombatStart(Combat* c)
{
    printf(">>> This Combat is Against %s (%d) <<<\n", c->seat1->name, c->seat1->level);
    DrawEntityInformation(c->seat1);
}