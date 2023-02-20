// Search for: 
	LPITEM pWeapon = pkAttacker->GetWear(WEAR_WEAPON);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	LPITEM pWeapon = pkAttacker->GetEquipWear(WEAR_WEAPON);
#else
	LPITEM pWeapon = pkAttacker->GetWear(WEAR_WEAPON);
#endif

// Search for:
	LPITEM pkWeapon = pkAttacker->GetWear(WEAR_WEAPON);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	LPITEM pkWeapon = pkAttacker->GetEquipWear(WEAR_WEAPON);
#else
	LPITEM pkWeapon = pkAttacker->GetWear(WEAR_WEAPON);
#endif

// Search for:
	LPITEM item = ch->GetWear(WEAR_WEAPON);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	LPITEM item = ch->GetEquipWear(WEAR_WEAPON);
#else
	LPITEM item = ch->GetWear(WEAR_WEAPON);
#endif
