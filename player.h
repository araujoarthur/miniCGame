#include <stdbool.h>

#ifndef PLAYER_H  // Header Guard
#define PLAYER_H

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


Entity* initEntity(char* name, int level, float hp, float dmg, float defense, bool isPlayer);
Entity* initPlayer(char* name);
Entity* initEnemy(char* name, int level, float hp, float dmg, float defense);
void TakeDamage(Entity* target, int dmg);
void Heal(Entity* target, int health);
void Kill(Entity* target);
void AddExp(Entity* target, int exp);
void Levelup(Entity* target);


#endif