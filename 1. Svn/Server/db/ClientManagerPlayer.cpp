// Search for:
			"horse_skill_point = %d, "

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
			"equip_index = %d, "
#endif

// Search for:
			"hp, mp, random_hp, random_sp, stat_point, stamina, part_base, part_main, part_hair, gold, playtime, "

// Replace for (attention: if you have acce system or other system that has different values, don't replace it, just add `equip_index` AFTER gold):
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
			"hp, mp, random_hp, random_sp, stat_point, stamina, part_base, part_main, part_hair, gold, equip_index, playtime, "
#else
			"hp, mp, random_hp, random_sp, stat_point, stamina, part_base, part_main, part_hair, gold, playtime, "
#endif

// Search for:
			packet->player_table.hp, packet->player_table.sp, packet->player_table.sRandomHP, packet->player_table.sRandomSP, packet->player_table.stat_point, packet->player_table.stamina, packet->player_table.part_base, packet->player_table.part_base, packet->player_table.part_base, packet->player_table.gold, packet->player_table.extend_inv, packet->player_table.equip_index);

// Replace for (attention: if you have acce system or other system that has different values, don't replace it, just add `packet->player_table.equip_index` AFTER packet->player_table.gold):
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
			packet->player_table.hp, packet->player_table.sp, packet->player_table.sRandomHP, packet->player_table.sRandomSP, packet->player_table.stat_point, packet->player_table.stamina, packet->player_table.part_base, packet->player_table.part_base, packet->player_table.gold, packet->player_table.equip_index);
#else
			packet->player_table.hp, packet->player_table.sp, packet->player_table.sRandomHP, packet->player_table.sRandomSP, packet->player_table.stat_point, packet->player_table.stamina, packet->player_table.part_base, packet->player_table.part_base, packet->player_table.gold);
#endif
