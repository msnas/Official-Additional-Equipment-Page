// Search for (2x):
		LPITEM pick = ch->GetWear(WEAR_WEAPON);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
		LPITEM pick = ch->GetEquipWear(WEAR_WEAPON);
#else
		LPITEM pick = ch->GetWear(WEAR_WEAPON);
#endif