
#include "entity.h"
#include "skill.h"

#ifndef COMBAT_H  // Header Guard
#define COMBAT_H
typedef void (*Skill)(Entity* attacker, Entity* defender);

typedef struct _combat {
    Entity* seat0;
    Entity* seat1;
    Skill skills[2][3]; //idx 0 for seat0, idx 1 for seat1. 3 Skills each.
    int currentAttacker;
    Entity* winner;
} Combat;

typedef struct _roundInfo {
    float totalDamage;

} RoundInfo;

// Cria a estrutura de combate que será retornada na main. Sorteia as skills e define quem inicia.
Combat* initCombat(Entity* e1, Entity* e2);

void SimpleAttack(Combat* combat, Entity* attacker, Entity* defender);
void SkillAttack(Combat* combat, Entity* attacker, Entity* defender, int skill);
void UpdateBattleStatus(Combat* combat);


#endif