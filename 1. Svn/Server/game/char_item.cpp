// Search for:
	if (!item && bCell == WEAR_WEAPON)

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	if (!item && (bCell == WEAR_WEAPON || bCell == WEAR_SECOND_BODY))
#else
	if (!item && bCell == WEAR_WEAPON)
#endif

// Search for:
bool CHARACTER::IsEmptyItemGrid(TItemPos Cell, BYTE bSize, int iExceptionCell) const

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
bool CHARACTER::IsEmptyItemGrid(TItemPos Cell, BYTE bSize, int iExceptionCell)
#else
bool CHARACTER::IsEmptyItemGrid(TItemPos Cell, BYTE bSize, int iExceptionCell) const
#endif

// Search for:
			LPITEM beltItem = GetWear(WEAR_BELT);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
			LPITEM beltItem = GetEquipWear(WEAR_BELT);
#else
			LPITEM beltItem = GetWear(WEAR_BELT);
#endif

// Search for:
int CHARACTER::GetEmptyInventory(BYTE size) const

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
int CHARACTER::GetEmptyInventory(BYTE size)
#else
int CHARACTER::GetEmptyInventory(BYTE size) const
#endif

// Search for:
int CHARACTER::GetEmptyDragonSoulInventory(LPITEM pItem) const

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
int CHARACTER::GetEmptyDragonSoulInventory(LPITEM pItem)
#else
int CHARACTER::GetEmptyDragonSoulInventory(LPITEM pItem) const
#endif

// Search for:
					case USE_SPECIAL:
						
						switch (item->GetVnum())
						{

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
							case ITEM_ADDITIONAL_PAGE_NOT_TRADEABLE:
							case ITEM_ADDITIONAL_PAGE_TRADEABLE:
							{
								if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())
								{
									ChatPacket(CHAT_TYPE_INFO, "You can't change equipment page while you're doing something else.");
									return false;
								}

								if (GetSkillLevel(SKILL_ADDITIONAL_PAGE) > 0)
								{
									ChatPacket(CHAT_TYPE_INFO, "Cannot be used again.");
									return false;
								}

								SetSkillLevel(SKILL_ADDITIONAL_PAGE, 1);
								SkillLevelPacket();

								ChangeEquip(FIRST_TYPE_EQUIPMENT, true);

								ChatPacket(CHAT_TYPE_INFO, "The additional equipment page has been activated. You'll find it in the equipment window.");
								item->SetCount(item->GetCount() - 1);
							}
							break;
#endif

// Search for:
							LPITEM weapon = GetWear(WEAR_WEAPON);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
							LPITEM weapon = GetEquipWear(WEAR_WEAPON);
#else
							LPITEM weapon = GetWear(WEAR_WEAPON);
#endif

// Search for:
	if (iWearCell == WEAR_BODY && IsRiding() && (item->GetVnum() >= 11901 && item->GetVnum() <= 11904))

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	if ((iWearCell == WEAR_BODY || iWearCell == WEAR_SECOND_BODY) && IsRiding() && (item->GetVnum() >= 11901 && item->GetVnum() <= 11904))
#else
	if (iWearCell == WEAR_BODY && IsRiding() && (item->GetVnum() >= 11901 && item->GetVnum() <= 11904))
#endif

// Search for:
	if (iWearCell != WEAR_ARROW && IsPolymorphed())

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	if ((iWearCell != WEAR_ARROW || iWearCell != WEAR_SECOND_ARROW) && IsPolymorphed())
#else
	if (iWearCell != WEAR_ARROW && IsPolymorphed())
#endif

// Search for:
	if (iWearCell != WEAR_ARROW && IsPolymorphed())

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	if ((iWearCell != WEAR_ARROW || iWearCell != WEAR_SECOND_ARROW) && IsPolymorphed())
#else
	if (iWearCell != WEAR_ARROW && IsPolymorphed())
#endif

// Search for:
	if (iWearCell != WEAR_ARROW
		&& (dwCurTime - GetLastAttackTime() <= 1500 || dwCurTime - m_dwLastSkillTime <= 1500))

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	if ((iWearCell != WEAR_ARROW || iWearCell != WEAR_SECOND_ARROW)
		&& (dwCurTime - GetLastAttackTime() <= 1500 || dwCurTime - m_dwLastSkillTime <= 1500))
#else
	if (iWearCell != WEAR_ARROW
		&& (dwCurTime - GetLastAttackTime() <= 1500 || dwCurTime - m_dwLastSkillTime <= 1500))
#endif

// Search for:
			if (item->GetWearFlag() == WEARABLE_ABILITY)
				return false;

// Replace for:
#ifndef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
			// Once this item is stuck, it cannot be changed. swap is completely impossible
			if (item->GetWearFlag() == WEARABLE_ABILITY)
				return false;
#endif

// Search for:
					static BYTE abSlot[] = { WEAR_BODY, WEAR_HEAD, WEAR_FOOTS, WEAR_WRIST, WEAR_WEAPON, WEAR_NECK, WEAR_EAR, WEAR_SHIELD };
					static std::vector <BYTE> vec_slots(abSlot, abSlot + _countof(abSlot));
					pBuff = M2_NEW CBuffOnAttributes(this, bType, &vec_slots);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
					if (GetEquipIndex() == FIRST_TYPE_EQUIPMENT)
					{
						static BYTE abSlot[] = { WEAR_BODY, WEAR_HEAD, WEAR_FOOTS, WEAR_WRIST, WEAR_WEAPON, WEAR_NECK, WEAR_EAR, WEAR_SHIELD };
						static std::vector <BYTE> vec_slots(abSlot, abSlot + _countof(abSlot));
						pBuff = M2_NEW CBuffOnAttributes(this, bType, &vec_slots);
					}
					else
					{
						static BYTE abSlot[] = { WEAR_SECOND_BODY, WEAR_SECOND_HEAD, WEAR_SECOND_FOOTS, WEAR_SECOND_WRIST, WEAR_SECOND_WEAPON,
						WEAR_SECOND_NECK, WEAR_SECOND_EAR, WEAR_SECOND_SHIELD };
						static std::vector <BYTE> vec_slots(abSlot, abSlot + _countof(abSlot));
						pBuff = M2_NEW CBuffOnAttributes(this, bType, &vec_slots);
					}
#else
					static BYTE abSlot[] = { WEAR_BODY, WEAR_HEAD, WEAR_FOOTS, WEAR_WRIST, WEAR_WEAPON, WEAR_NECK, WEAR_EAR, WEAR_SHIELD };
					static std::vector <BYTE> vec_slots(abSlot, abSlot + _countof(abSlot));
					pBuff = M2_NEW CBuffOnAttributes(this, bType, &vec_slots);
#endif