#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "entity.h"


int LevelUpExperience(int lvl);
int MaxHPIncrease(int lvl);
int DmgIncrease(int lvl);
int DefenseIncrease(int lvl);


Entity* initEntity(char* name, const int level, const float hp, const float dmg, const float defense, const bool isPlayer)
{
    Entity* ent = malloc(sizeof(Entity));
    ent->name = name;
    ent->level = level;
    ent->hp = hp;
    ent->max_hp = hp;
    ent->dmg = dmg;
    ent->defense = defense;
    ent->isPlayer = isPlayer;
    ent->isDead = false;
    ent->exp = 0;

    return ent;
}

Entity* initPlayer(char* name)
{
    return initEntity(name, STD_PLAYER_LVL, STD_PLAYER_HP, STD_PLAYER_DMG, STD_PLAYER_DEF, true);
}

Entity* initEnemy(char* name, int level, float hp, float dmg, float defense)
{
    return initEntity(name, level, hp, dmg, defense, false);
}


Entity* initEnemyBase(Entity* base, int scale)
{   
    int level;
    float hp, dmg, defense;
    if (scale > 0)
    {
        level = base->level * scale;
        hp = base->hp * scale + base->level * scale;
        dmg = scale * scale * base->dmg;
        defense = 1.25 * scale * base->defense;
    } else {
        level = base->level;
        hp = base->hp;
        dmg = base->dmg;
        defense = base->defense;
    }
    
    return initEnemy(base->name, level, hp, dmg, defense);
}



void TakeDamage(Entity* target, int dmg)
{
    if (target->hp <= dmg) {
        Kill(target);
        return;
    }

    target->hp -= dmg;
    return;
}

void Heal(Entity* target, int health)
{   
    float newHealth = target->hp + health;
    if (newHealth >= target->max_hp)
    {
        target->hp = target->max_hp;
        return;
    }
    target->hp = newHealth;
}

void Kill(Entity* target)
{
    target->isDead = true;
    return;
}

void AddExp(Entity* target, int exp)
{
    int newXp = target->exp + exp;
    
    // If the newXp is higher than the required xp subtracts the required xp from the newXp and levels up the target.
    if (newXp >= LevelUpExperience(target->level))
    {
        newXp -= LevelUpExperience(target->level);
        Levelup(target);
    }

    target->exp = newXp;
    return;
}

void Levelup(Entity* target)
{
    target->level += 1;
    target->max_hp += MaxHPIncrease(target->level);
    target->dmg += DmgIncrease(target->level);
    target->defense += DefenseIncrease(target->level);
    Heal(target, target->max_hp);
    return; 
}

int LevelUpExperience(int lvl)
{
    return lvl * log10((double)lvl)/40;
}

int MaxHPIncrease(int lvl)
{
    return 1 + (lvl % 4);
}

int DmgIncrease(int lvl)
{
    return 1 + (lvl % 2);
}

int DefenseIncrease(int lvl)
{
    return 1 + (lvl/10);
}
