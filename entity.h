#include <stdbool.h>

#ifndef ENTITY_H  // Header Guard
#define ENTITY_H

#define STD_PLAYER_LVL 1
#define STD_PLAYER_HP 100.0
#define STD_PLAYER_DMG 2
#define STD_PLAYER_DEF 1

typedef struct _entity {
    char* name;
    int level;
    int exp;
    float hp;
    float max_hp;
    bool isPlayer;
    float dmg;
    float defense;
    bool isDead;
} Entity;

static const Entity BaseGoblin = { // Static bc consts have external linkage by default (Multiple Definitions Error)
    "GOBLIN",
    1,
    0,
    15,
    15,
    false,
    1,
    2,
};

static const Entity BaseBat = {
    "BAT",
    2,
    0,
    30,
    30,
    false,
    3,
    1,
};

static const Entity BaseOrc = {
    "ORC",
    4,
    0,
    25,
    25,
    false,
    4,
    6,
};

static const Entity BaseDragon = {
    "DRAGON",
    7,
    0,
    60,
    60,
    false,
    8,
    10,
};

static const Entity* BaseEnemies[] = {
    &BaseGoblin, 
    &BaseBat, 
    &BaseOrc, 
    &BaseDragon
};

Entity* initEntity(char* name, const int level, const float hp, const float dmg, const float defense, const bool isPlayer);
Entity* initPlayer(char* name);
Entity* initEnemy(char* name, int level, float hp, float dmg, float defense);
Entity* initEnemyBase(Entity* base, int scale);

void TakeDamage(Entity* target, int dmg);
void Heal(Entity* target, int health);
void Kill(Entity* target);
void AddExp(Entity* target, int exp);
void Levelup(Entity* target);


#endif