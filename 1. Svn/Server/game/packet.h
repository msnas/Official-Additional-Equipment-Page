// Search for:
	HEADER_CG_STATE_CHECKER							= 206,

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	HEADER_CG_CHANGE_EQUIP							= 208,
#endif

// Search for:
typedef struct SPacketGCHybridCryptKeys

// Add before:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
typedef struct SChangeEquipment
{
	BYTE			header;
	int				index;
} TChangeEquipment;
#endif
