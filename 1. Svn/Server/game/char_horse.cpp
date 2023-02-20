// Search for:
	LPITEM armor = GetWear(WEAR_BODY);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	LPITEM armor = GetEquipWear(WEAR_BODY);
#else
	LPITEM armor = GetWear(WEAR_BODY);
#endif