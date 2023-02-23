// Search for:
enum EItemWearableFlag
{
	WEARABLE_BODY	= (1 << 0),
	WEARABLE_HEAD	= (1 << 1),
	WEARABLE_FOOTS	= (1 << 2),
	WEARABLE_WRIST	= (1 << 3),
	WEARABLE_WEAPON	= (1 << 4),
	WEARABLE_NECK	= (1 << 5),
	WEARABLE_EAR	= (1 << 6),
	WEARABLE_UNIQUE			= (1 << 7),
	WEARABLE_SHIELD			= (1 << 8),
	WEARABLE_ARROW			= (1 << 9),
	WEARABLE_HAIR			= (1 << 10),
	WEARABLE_ABILITY		= (1 << 11),
	WEARABLE_COSTUME_BODY	= (1 << 12),
};

// Replace for:
enum EItemWearableFlag
{
	WEARABLE_BODY	= (1 << 0),
	WEARABLE_HEAD	= (1 << 1),
	WEARABLE_FOOTS	= (1 << 2),
	WEARABLE_WRIST	= (1 << 3),
	WEARABLE_WEAPON	= (1 << 4),
	WEARABLE_NECK	= (1 << 5),
	WEARABLE_EAR	= (1 << 6),

#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	WEARABLE_ARROW			= (1 << 7),
	WEARABLE_SHIELD			= (1 << 8),
	WEARABLE_BELT			= (1 << 9),
	WEARABLE_PENDANT		= (1 << 10),
	WEARABLE_GLOVES			= (1 << 11),
	WEARABLE_COSTUME_BODY	= (1 << 12),
	WEARABLE_COSTUME_HAIR	= (1 << 13),
#ifdef __ACCE_SYSTEM__
	WEARABLE_COSTUME_ACCE	= (1 << 14),
#endif
	WEARABLE_UNIQUE			= (1 << 15),
#else
	WEARABLE_UNIQUE			= (1 << 7),
	WEARABLE_SHIELD			= (1 << 8),
	WEARABLE_ARROW			= (1 << 9),
	WEARABLE_HAIR			= (1 << 10),
	WEARABLE_ABILITY		= (1 << 11),
	WEARABLE_COSTUME_BODY	= (1 << 12),
#ifdef __ACCE_SYSTEM__
	WEARABLE_COSTUME_ACCE	= (1 << 13),
#endif
#endif
};

// ATENTION: It's crucial that this needs to be in the same position as ProtoReader.cpp (string arWearrFlag[]) and length.h (EWearPositions)