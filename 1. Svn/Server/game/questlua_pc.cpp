// Search for:
		LPITEM item = CQuestManager::instance().GetCurrentCharacterPtr()->GetWear(WEAR_WEAPON);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
		LPITEM item = CQuestManager::instance().GetCurrentCharacterPtr()->GetEquipWear(WEAR_WEAPON);
#else
		LPITEM item = CQuestManager::instance().GetCurrentCharacterPtr()->GetWear(WEAR_WEAPON);
#endif

// Search for:
		LPITEM item = CQuestManager::instance().GetCurrentCharacterPtr()->GetWear(WEAR_WEAPON);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
		LPITEM item = CQuestManager::instance().GetCurrentCharacterPtr()->GetEquipWear(WEAR_BODY);
#else
		LPITEM item = CQuestManager::instance().GetCurrentCharacterPtr()->GetWear(WEAR_BODY);
#endif