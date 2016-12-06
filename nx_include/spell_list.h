#ifndef __SPELL_LIST_H
#define __SPELL_LIST_H

enum target_type_e {
	TARGET_UNSPESCIFIED = 0, // things like pvp trinket which don't require any real checking
	TARGET_GROUND = 1, // aoe mostly
	TARGET_SELF = 2,
	TARGET_FRIENDLY = 3,
	
	TARGET_ENEMY = 10,
	TARGET_ENEMY_NOCOMBAT = 11,	// interaction doesn't cause combat
	TARGET_ENEMY_REQUIRES_FACING = 12, // requires ENEMY facing
	TARGET_ENEMY_REQUIRES_BEHIND = 13,
	TARGET_ENEMY_REQUIRES_DISTANCE = 14,
	TARGET_ENEMY_OUT_OF_COMBAT = 20
};

enum class_id {
	CLASS_NONE = 0,
	CLASS_ROGUE = 1,
	
	// we dont use this
	//CLASS_PET = 255
};

enum buff_id {
	BUFF_NULL = 0,

	BUFF_FREEDOM,
	BUFF_TRUE_SIGHT,
	// match preparation, not the spell.
	BUFF_PREPARATION,
	
	BUFF_DR_INCAPACITATE,
	BUFF_DR_STUN,
	BUFF_DR_OPENER_STUN,
	BUFF_DR_FEAR,
	BUFF_DR_SILENCE,
	BUFF_DR_IMMOBILIZE,
	BUFF_DR_DISORIENT,
	
	//BUFF_DR_BANISH,
};

enum spell_tree {
	TREE_NONE = 0,
	TREE_HOLY = 1,
	TREE_FROST = 2,
	TREE_SHADOW = 3,
	TREE_FIRE = 4,
	TREE_NATURE = 5,
	TREE_ARCANE = 6
};

#define ROGUE_SPELL_START 1000

enum spell_id {
	// all
	SPELL_NONE = 0, // placeholder for no spell/not casting
	SPELL_FREEDOM = 100, // pvp trinket
	SPELL_MOUNT = 101,
	
	// rogue
	RSPELL_KICK = 1000,
	RSPELL_GOUGE = 1001,
	RSPELL_SAP = 1002,
	RSPELL_HEMO = 1003,
	RSPELL_STEALTH = 1004,
	RSPELL_THROW = 1005,
	RSPELL_PREPARATION = 1006,
	RSPELL_SLICE_AND_DICE = 1007,
	RSPELL_SPRINT = 1008,
	RSPELL_DISTRACT = 1009,
	RSPELL_VANISH = 1010,
	RSPELL_BLIND = 1011,
	RSPELL_RUPTURE = 1012,
	RSPELL_EXPLOIT_WEAKNESS = 1013,
	RSPELL_CHEAP_SHOT = 1014,
	RSPELL_KIDNEY_SHOT = 1015,
	RSPELL_EVASION = 1016,
	RSPELL_SHADOW_STEP = 1017,
	RSPELL_GARROTE = 1018,
	RSPELL_CLOAK = 1019,
	RSPELL_PREMEDITATION = 1020,
	RSPELL_EVISCERATE = 1021,
	RSPELL_SNEAK_ATTACK = 1022,
	RSPELL_CRIPPLING_THROW = 1023,
	RSPELL_SHIV = 1024,
    ROGUE_SPELLS_END = 1025,
	
	RBUFF_STEALTH = 1100,
	RBUFF_SLICE_AND_DICE = 1101,
	RBUFF_SPRINT = 1102,
	RBUFF_EXPLOIT_WEAKNESS_ROGUE = 1103, // this applys a buff to the rogue which stores their target id in buff->value
	// this is no longer needed. the target id is stored in the value field of RBUFF_EXPLOIT_WEAKNESS_ROGUE
	//RBUFF_EXPLOIT_WEAKNESS_FRIEND = 1104, // it's possible to split the %damage modifiers this way
	RBUFF_EXPLOIT_WEAKNESS_ROGUE_ACTIVE = 1103,
	RBUFF_EXPLOIT_WEAKNESS_FRIEND_ACTIVE = 1104, 
	RBUFF_SHADOW_STEP_SPEED = 1107,
	RBUFF_SHADOW_STEP_ATTACK = 1108,
	RBUFF_VANISH = 1109, 
	RBUFF_VANISH_INTERNAL = 1110, // avoiding projectiles internal buff - don't send to client
	RBUFF_EVASION = 1111,
	RBUFF_CLOAK = 1112,
	
	
	RDEBUFF_KICKED = 1200,
	RDEBUFF_GOUGE = 1201,
	RDEBUFF_SAP = 1202,
	RDEBUFF_HEMO = 1203,
	RDEBUFF_BLIND = 1204,
	RDEBUFF_RUPTURE = 1205,
	
	RDEBUFF_CHEAP_SHOT = 1207,
	RDEBUFF_GARROTE_BLEED = 1208,
	RDEBUFF_GARROTE_SILENCE = 1209,
	RDEBUFF_CRIPPLE = 1210,
	RDEBUFF_CRIPPLING_POISON = 1211,
	RDEBUFF_DISTRACT_INTERNAL = 1212,
	RDEBUFF_KIDNEY_SHOT = 1213,	
	
	RSPELL_TOTEM_INTERNAL = 1099
};

#endif
