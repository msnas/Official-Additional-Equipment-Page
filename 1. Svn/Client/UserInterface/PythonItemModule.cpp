// Search for:
#ifdef ENABLE_NEW_EQUIPMENT_SYSTEM
	PyModule_AddIntConstant(poModule, "EQUIPMENT_BELT",				c_Equipment_Belt);
#endif

// Replace for:
#ifdef ENABLE_NEW_EQUIPMENT_SYSTEM
#ifndef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	PyModule_AddIntConstant(poModule, "EQUIPMENT_RING1",			c_Equipment_Ring1);
	PyModule_AddIntConstant(poModule, "EQUIPMENT_RING2",			c_Equipment_Ring2);
#endif
	PyModule_AddIntConstant(poModule, "EQUIPMENT_BELT",				c_Equipment_Belt);
#endif