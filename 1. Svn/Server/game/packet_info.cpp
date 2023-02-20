// Search for:
	Set(HEADER_CG_STATE_CHECKER, sizeof(BYTE), "ServerStateCheck", false);

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	Set(HEADER_CG_CHANGE_EQUIP, sizeof(TChangeEquipment), "ChangeEquipment", true);
#endif