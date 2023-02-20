// Search for (2x):
	LPITEM item = ch->GetWear(WEAR_WEAPON);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	LPITEM item = ch->GetEquipWear(WEAR_WEAPON);
#else
	LPITEM item = ch->GetWear(WEAR_WEAPON);
#endif
