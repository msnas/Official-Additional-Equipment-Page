// Search for:
#ifdef ENABLE_DRAGON_SOUL_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_DRAGON_SOUL_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_DRAGON_SOUL_SYSTEM",	0);
#endif

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	PyModule_AddIntConstant(poModule, "ENABLE_ADDITIONAL_EQUIPMENT_PAGE", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_ADDITIONAL_EQUIPMENT_PAGE", 0);
#endif