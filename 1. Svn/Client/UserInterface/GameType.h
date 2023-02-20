// Search for:
const DWORD c_Equipment_Body = c_Equipment_Start + 0;
const DWORD c_Equipment_Head = c_Equipment_Start + 1;
const DWORD c_Equipment_Shoes = c_Equipment_Start + 2;
const DWORD c_Equipment_Wrist = c_Equipment_Start + 3;
const DWORD c_Equipment_Weapon = c_Equipment_Start + 4;
const DWORD c_Equipment_Neck = c_Equipment_Start + 5;
const DWORD c_Equipment_Ear = c_Equipment_Start + 6;
const DWORD c_Equipment_Unique1 = c_Equipment_Start + 7;
const DWORD c_Equipment_Unique2 = c_Equipment_Start + 8;
const DWORD c_Equipment_Arrow = c_Equipment_Start + 9;
const DWORD c_Equipment_Shield = c_Equipment_Start + 10;

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
const DWORD c_Equipment_Body			= c_Equipment_Start + 0;
const DWORD c_Equipment_Head			= c_Equipment_Start + 1;
const DWORD c_Equipment_Shoes			= c_Equipment_Start + 2;
const DWORD c_Equipment_Wrist			= c_Equipment_Start + 3;
const DWORD c_Equipment_Weapon			= c_Equipment_Start + 4;
const DWORD c_Equipment_Neck			= c_Equipment_Start + 5;
const DWORD c_Equipment_Ear				= c_Equipment_Start + 6;
const DWORD c_Equipment_Arrow			= c_Equipment_Start + 7;
const DWORD c_Equipment_Shield			= c_Equipment_Start + 8;
const DWORD c_Equipment_Belt			= c_Equipment_Start + 9;
const DWORD c_Equipment_Pendant			= c_Equipment_Start + 10;
const DWORD c_Equipment_Gloves			= c_Equipment_Start + 11;

const DWORD c_Second_Equipment_Body		= c_Equipment_Start + 12;
const DWORD c_Second_Equipment_Head		= c_Equipment_Start + 13;
const DWORD c_Second_Equipment_Shoes	= c_Equipment_Start + 14;
const DWORD c_Second_Equipment_Wrist	= c_Equipment_Start + 15;
const DWORD c_Second_Equipment_Weapon	= c_Equipment_Start + 16;
const DWORD c_Second_Equipment_Neck		= c_Equipment_Start + 17;
const DWORD c_Second_Equipment_Ear		= c_Equipment_Start + 18;
const DWORD c_Second_Equipment_Arrow	= c_Equipment_Start + 19;
const DWORD c_Second_Equipment_Shield	= c_Equipment_Start + 20;
const DWORD c_Second_Equipment_Belt		= c_Equipment_Start + 21;
const DWORD c_Second_Equipment_Pendant	= c_Equipment_Start + 22;
const DWORD c_Second_Equipment_Gloves	= c_Equipment_Start + 23;

const DWORD c_Equipment_Second_Start	= c_Second_Equipment_Body;
#else
const DWORD c_Equipment_Body = c_Equipment_Start + 0;
const DWORD c_Equipment_Head = c_Equipment_Start + 1;
const DWORD c_Equipment_Shoes = c_Equipment_Start + 2;
const DWORD c_Equipment_Wrist = c_Equipment_Start + 3;
const DWORD c_Equipment_Weapon = c_Equipment_Start + 4;
const DWORD c_Equipment_Neck = c_Equipment_Start + 5;
const DWORD c_Equipment_Ear = c_Equipment_Start + 6;
const DWORD c_Equipment_Unique1 = c_Equipment_Start + 7;
const DWORD c_Equipment_Unique2 = c_Equipment_Start + 8;
const DWORD c_Equipment_Arrow = c_Equipment_Start + 9;
const DWORD c_Equipment_Shield = c_Equipment_Start + 10;
#endif

// Search for:
#ifdef ENABLE_NEW_EQUIPMENT_SYSTEM
	const DWORD c_New_Equipment_Start = c_Equipment_Start + 21;
	const DWORD c_New_Equipment_Count = 3;
	const DWORD c_Equipment_Ring1 = c_New_Equipment_Start + 0;
	const DWORD c_Equipment_Ring2 = c_New_Equipment_Start + 1;
	const DWORD c_Equipment_Belt  = c_New_Equipment_Start + 2;;
#endif

// Replace for:
#ifdef ENABLE_NEW_EQUIPMENT_SYSTEM
	#if defined ENABLE_ADDITIONAL_EQUIPMENT_PAGE && defined(ENABLE_ACCE_SYSTEM)
		const DWORD c_New_Equipment_Start = c_Equipment_Start + 27;
	#elif defined(ENABLE_ACCE_SYSTEM) || defined(ENABLE_ADDITIONAL_EQUIPMENT_PAGE)
		const DWORD c_New_Equipment_Start = c_Equipment_Start + 22;
	#else
		const DWORD c_New_Equipment_Start = c_Equipment_Start + 21;
	#endif

	#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
		const DWORD c_New_Equipment_Count = 2;
		const DWORD c_Equipment_Unique1 = c_New_Equipment_Start + 0;
		const DWORD c_Equipment_Unique2 = c_New_Equipment_Start + 1;
	#else
		const DWORD c_New_Equipment_Start = c_Equipment_Start + 21;
		const DWORD c_New_Equipment_Count = 3;

		const DWORD c_Equipment_Ring1 = c_New_Equipment_Start + 0;
		const DWORD c_Equipment_Ring2 = c_New_Equipment_Start + 1;
		const DWORD c_Equipment_Belt  = c_New_Equipment_Start + 2;
	#endif
#endif

// Search for:
enum EWindows
{
	RESERVED_WINDOW,

// Add before:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
enum SecondEquipment
{
	SECOND_EQUIPMENT_COUNT = 12,
};
#endif