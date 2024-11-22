#include <stdlib.h>
#include <math.h>
#include "combat.h"

Combat* initCombat(Entity* e1, Entity* e2)
{
    Combat* combat = malloc(sizeof(Combat));

    // Chooses a seat to start.
    int starter = rand() % 2;

    combat->seat0 = e1; // Always the player.
    combat->seat1 = e2;
    combat->currentAttacker = starter;
    combat->winner = NULL;

    // draft the skils

    return combat;
}

void SimpleAttack(Combat* combat, Entity* attacker, Entity* defender)
{
    int attackLevelDifference = attacker->level - defender->level;
    attackLevelDifference = attackLevelDifference > 0 ? attackLevelDifference : 1;

    int defenseLevelDifference =  defender->level - attacker->level;
    defenseLevelDifference = defenseLevelDifference > 0 ? defenseLevelDifference : 1;

                    // Damage should scale with level difference. Has a static factor and a character factor.
    float dmg = rand() % attackLevelDifference + (rand() % 5) + rand() % (int)trunc(attacker->dmg);

                    // Def Scales with level, but can get bypassed.    Base factor also can get bypassed.
    float defFactor = (rand() % defenseLevelDifference) * (rand() % 2) + (rand() % 2) * (rand() % 2) + rand() % (int)trunc(defender->defense * 0.5);

    dmg = (dmg - defFactor) <= 0 ? 1 : dmg - defFactor;
    TakeDamage(defender, dmg);

    UpdateBattleStatus(combat);
}

void SkillAttack(Combat* combat, Entity* attacker, Entity* defender, int skill)
{
    combat->skills[0][skill](attacker, defender);
    UpdateBattleStatus(combat);
}

void UpdateBattleStatus(Combat* combat)
{
    if (combat->seat0->isDead) 
    {
        combat->winner = combat->seat1;
        combat->currentAttacker = -1;
        return;
    } else if (combat->seat1->isDead) 
    {
        combat->winner = combat->seat0;
        combat->currentAttacker = -1;
        return;
    }

    combat->currentAttacker = combat->currentAttacker == 0 ? 1 : 0;
    return;
}