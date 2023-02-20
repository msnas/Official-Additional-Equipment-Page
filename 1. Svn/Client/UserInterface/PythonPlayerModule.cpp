// Search for:
extern const DWORD c_iSkillIndex_Summon		= 131;

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
extern const DWORD c_iSkillIndex_ExtraPage	= 200;
#endif

// Search for:
	PyModule_AddIntConstant(poModule, "EQUIPMENT_PAGE_COUNT",	c_Equipment_Count);

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	PyModule_AddIntConstant(poModule, "EQUIPMENT_SECOND_SLOT_START", c_Equipment_Second_Start);
#endif

// Search for:
	PyModule_AddIntConstant(poModule, "SKILL_INDEX_SUMMON",			c_iSkillIndex_Summon);

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	PyModule_AddIntConstant(poModule, "SKILL_ADDITIONAL_PAGE",		c_iSkillIndex_ExtraPage);
#endif