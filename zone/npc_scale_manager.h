/**
 * EQEmulator: Everquest Server Emulator
 * Copyright (C) 2001-2018 EQEmulator Development Team (https://github.com/EQEmu/Server)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY except by those people which sell it, which
 * are required to give you total support for your newly bought product;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 */

#ifndef EQEMU_NPC_SCALE_MANAGER_H
#define EQEMU_NPC_SCALE_MANAGER_H


#include "npc.h"

class NpcScaleManager {
public:
	struct global_npc_scale {
		int type;
		int level;
		int ac;
		int hp;
		int accuracy;
		int slow_mitigation;
		int attack;
		int strength;
		int stamina;
		int dexterity;
		int agility;
		int intelligence;
		int wisdom;
		int charisma;
		int magic_resist;
		int cold_resist;
		int fire_resist;
		int poison_resist;
		int disease_resist;
		int corruption_resist;
		int physical_resist;
		int min_dmg;
		int max_dmg;
		int hp_regen_rate;
		int attack_delay;

		std::string special_abilities;
	};

	void ScaleMob(Mob *mob);
	bool LoadScaleData();

	global_npc_scale GetGlobalScaleDataForTypeLevel(int8 mob_type, int mob_level);

	std::map<std::pair<int, int>, global_npc_scale> npc_global_base_scaling_data;

	void ListStats(Mob * mob);

	uint32 GetClassLevelDamageMod(uint32 level, uint32 npc_class);
};

extern NpcScaleManager *npc_scale_manager;

#endif //EQEMU_NPC_SCALE_MANAGER_H