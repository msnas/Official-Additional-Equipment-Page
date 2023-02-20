// Search for (3x):
	LPITEM rod = ch->GetWear(WEAR_WEAPON);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	LPITEM rod = ch->GetEquipWear(WEAR_WEAPON);
#else
	LPITEM rod = ch->GetWear(WEAR_WEAPON);
#endif