// Search for:
	if (!(pkBow = GetWear(WEAR_WEAPON)) || pkBow->GetProto()->bSubType != WEAPON_BOW)

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	if (!(pkBow = GetEquipWear(WEAR_WEAPON)) || pkBow->GetProto()->bSubType != WEAPON_BOW)
#else
	if (!(pkBow = GetWear(WEAR_WEAPON)) || pkBow->GetProto()->bSubType != WEAPON_BOW)
#endif
