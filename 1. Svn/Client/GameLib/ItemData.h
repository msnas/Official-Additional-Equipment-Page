// Search for:
		enum EWearPositions
		{
			WEAR_BODY,          // 0
			WEAR_HEAD,          // 1
			WEAR_FOOTS,         // 2
			WEAR_WRIST,         // 3
			WEAR_WEAPON,        // 4
			WEAR_NECK,          // 5
			WEAR_EAR,           // 6
			WEAR_UNIQUE1,       // 7
			WEAR_UNIQUE2,       // 8
			WEAR_ARROW,         // 9
			WEAR_SHIELD,        // 10
			WEAR_MAX_NUM,
		};

// Replace for:
		enum EWearPositions
		{
			WEAR_BODY,          // 0
			WEAR_HEAD,          // 1
			WEAR_FOOTS,         // 2
			WEAR_WRIST,         // 3
			WEAR_WEAPON,        // 4
			WEAR_NECK,          // 5
			WEAR_EAR,           // 6
#ifndef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
			WEAR_UNIQUE1,       // 7
			WEAR_UNIQUE2,       // 8
#endif
			WEAR_ARROW,         // 9 (7)
			WEAR_SHIELD,        // 10 (8)
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
			WEAR_BELT,			// 11 (9)
#endif
			WEAR_COSTUME_BODY,
			WEAR_COSTUME_HAIR,
#ifdef ENABLE_ACCE_SYSTEM
			WEAR_COSTUME_ACCE,
#endif
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
			WEAR_UNIQUE1,		// 24 - 23
			WEAR_UNIQUE2,		// 25 - 24
#endif
			WEAR_MAX_NUM,
		};


// By default, this enum isn't used, but let's updated 
// Search for:
		enum EItemWearableFlag
		{
			WEARABLE_BODY       = (1 << 0),
			WEARABLE_HEAD       = (1 << 1),
			WEARABLE_FOOTS      = (1 << 2),
			WEARABLE_WRIST      = (1 << 3),
			WEARABLE_WEAPON     = (1 << 4),
			WEARABLE_NECK       = (1 << 5),
			WEARABLE_EAR        = (1 << 6),
			WEARABLE_UNIQUE     = (1 << 7),
			WEARABLE_SHIELD     = (1 << 8),
			WEARABLE_ARROW      = (1 << 9),
		};

// Replace for:
		enum EItemWearableFlag
		{
			WEARABLE_BODY       = (1 << 0),
			WEARABLE_HEAD       = (1 << 1),
			WEARABLE_FOOTS      = (1 << 2),
			WEARABLE_WRIST      = (1 << 3),
			WEARABLE_WEAPON     = (1 << 4),
			WEARABLE_NECK       = (1 << 5),
			WEARABLE_EAR        = (1 << 6),

#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
			WEARABLE_ARROW = (1 << 7),
			WEARABLE_SHIELD = (1 << 8),
			WEARABLE_BELT = (1 << 9),
			WEARABLE_ABILITY = (1 << 10),
			WEARABLE_COSTUME_BODY = (1 << 11),
			WEARABLE_COSTUME_HAIR = (1 << 12),
#ifdef ENABLE_ACCE_SYSTEM
			WEARABLE_COSTUME_ACCE = (1 << 13),
#endif
			WEARABLE_UNIQUE = (1 << 14),
#else
			WEARABLE_UNIQUE = (1 << 7),
			WEARABLE_SHIELD = (1 << 8),
			WEARABLE_ARROW = (1 << 9),
			WEARABLE_HAIR = (1 << 10),
			WEARABLE_ABILITY = (1 << 11),
			WEARABLE_COSTUME_BODY = (1 << 12),
#ifdef __ACCE_SYSTEM__
			WEARABLE_COSTUME_ACCE = (1 << 13),
#endif
#endif
		};