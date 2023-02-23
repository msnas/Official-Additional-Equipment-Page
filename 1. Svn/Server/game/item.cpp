// Search for:
	m_dwMaskVnum(0), m_dwSIGVnum (0)

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	, m_bEquipAlreadyStopped(false)
#endif

// Search for:

// Search for:
	else if (GetType() == ITEM_RING)
	{
		if (ch->GetWear(WEAR_RING1))
			return WEAR_RING2;
		else
			return WEAR_RING1;
	}

// Replace for:
#ifndef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	else if (GetType() == ITEM_RING)
	{
		if (ch->GetWear(WEAR_RING1))
			return WEAR_RING2;
		else
			return WEAR_RING1;
	}
#endif

// Search for:
	else if (GetType() == ITEM_BELT)
		return WEAR_BELT;
	else if (GetWearFlag() & WEARABLE_BODY)
		return WEAR_BODY;
	else if (GetWearFlag() & WEARABLE_HEAD)
		return WEAR_HEAD;
	else if (GetWearFlag() & WEARABLE_FOOTS)
		return WEAR_FOOTS;
	else if (GetWearFlag() & WEARABLE_WRIST)
		return WEAR_WRIST;
	else if (GetWearFlag() & WEARABLE_WEAPON)
		return WEAR_WEAPON;
	else if (GetWearFlag() & WEARABLE_SHIELD)
		return WEAR_SHIELD;
	else if (GetWearFlag() & WEARABLE_NECK)
		return WEAR_NECK;
	else if (GetWearFlag() & WEARABLE_EAR)
		return WEAR_EAR;
	else if (GetWearFlag() & WEARABLE_ARROW)
		return WEAR_ARROW;

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	else if (GetType() == ITEM_BELT)
		return ch->GetEquipIndex() == FIRST_TYPE_EQUIPMENT ? WEAR_BELT : WEAR_SECOND_BELT;
	else if (GetWearFlag() & WEARABLE_BODY)
		return ch->GetEquipIndex() == FIRST_TYPE_EQUIPMENT ? WEAR_BODY : WEAR_SECOND_BODY;
	else if (GetWearFlag() & WEARABLE_HEAD)
		return ch->GetEquipIndex() == FIRST_TYPE_EQUIPMENT ? WEAR_HEAD : WEAR_SECOND_HEAD;
	else if (GetWearFlag() & WEARABLE_FOOTS)
		return ch->GetEquipIndex() == FIRST_TYPE_EQUIPMENT ? WEAR_FOOTS : WEAR_SECOND_FOOTS;
	else if (GetWearFlag() & WEARABLE_WRIST)
		return ch->GetEquipIndex() == FIRST_TYPE_EQUIPMENT ? WEAR_WRIST : WEAR_SECOND_WRIST;
	else if (GetWearFlag() & WEARABLE_WEAPON)
		return ch->GetEquipIndex() == FIRST_TYPE_EQUIPMENT ? WEAR_WEAPON : WEAR_SECOND_WEAPON;
	else if (GetWearFlag() & WEARABLE_SHIELD)
		return ch->GetEquipIndex() == FIRST_TYPE_EQUIPMENT ? WEAR_SHIELD : WEAR_SECOND_SHIELD;
	else if (GetWearFlag() & WEARABLE_NECK)
		return ch->GetEquipIndex() == FIRST_TYPE_EQUIPMENT ? WEAR_NECK : WEAR_SECOND_NECK;
	else if (GetWearFlag() & WEARABLE_EAR)
		return ch->GetEquipIndex() == FIRST_TYPE_EQUIPMENT ? WEAR_EAR : WEAR_SECOND_EAR;
	else if (GetWearFlag() & WEARABLE_ARROW)
		return ch->GetEquipIndex() == FIRST_TYPE_EQUIPMENT ? WEAR_ARROW : WEAR_SECOND_ARROW;
#else
	else if (GetType() == ITEM_BELT)
		return WEAR_BELT;
	else if (GetWearFlag() & WEARABLE_BODY)
		return WEAR_BODY;
	else if (GetWearFlag() & WEARABLE_HEAD)
		return WEAR_HEAD;
	else if (GetWearFlag() & WEARABLE_FOOTS)
		return WEAR_FOOTS;
	else if (GetWearFlag() & WEARABLE_WRIST)
		return WEAR_WRIST;
	else if (GetWearFlag() & WEARABLE_WEAPON)
		return WEAR_WEAPON;
	else if (GetWearFlag() & WEARABLE_SHIELD)
		return WEAR_SHIELD;
	else if (GetWearFlag() & WEARABLE_NECK)
		return WEAR_NECK;
	else if (GetWearFlag() & WEARABLE_EAR)
		return WEAR_EAR;
	else if (GetWearFlag() & WEARABLE_ARROW)
		return WEAR_ARROW;
#endif

// Search for:
	else if (GetWearFlag() & WEARABLE_ABILITY)
	{
		if (!ch->GetWear(WEAR_ABILITY1))
		{
			return WEAR_ABILITY1;
		}
		else if (!ch->GetWear(WEAR_ABILITY2))
		{
			return WEAR_ABILITY2;
		}
		else if (!ch->GetWear(WEAR_ABILITY3))
		{
			return WEAR_ABILITY3;
		}
		else if (!ch->GetWear(WEAR_ABILITY4))
		{
			return WEAR_ABILITY4;
		}
		else if (!ch->GetWear(WEAR_ABILITY5))
		{
			return WEAR_ABILITY5;
		}
		else if (!ch->GetWear(WEAR_ABILITY6))
		{
			return WEAR_ABILITY6;
		}
		else if (!ch->GetWear(WEAR_ABILITY7))
		{
			return WEAR_ABILITY7;
		}
		else if (!ch->GetWear(WEAR_ABILITY8))
		{
			return WEAR_ABILITY8;
		}
		else
		{
			return -1;
		}
	}

// Replace for:
#ifndef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	else if (GetWearFlag() & WEARABLE_ABILITY)
	{
		if (!ch->GetWear(WEAR_ABILITY1))
		{
			return WEAR_ABILITY1;
		}
		else if (!ch->GetWear(WEAR_ABILITY2))
		{
			return WEAR_ABILITY2;
		}
		else if (!ch->GetWear(WEAR_ABILITY3))
		{
			return WEAR_ABILITY3;
		}
		else if (!ch->GetWear(WEAR_ABILITY4))
		{
			return WEAR_ABILITY4;
		}
		else if (!ch->GetWear(WEAR_ABILITY5))
		{
			return WEAR_ABILITY5;
		}
		else if (!ch->GetWear(WEAR_ABILITY6))
		{
			return WEAR_ABILITY6;
		}
		else if (!ch->GetWear(WEAR_ABILITY7))
		{
			return WEAR_ABILITY7;
		}
		else if (!ch->GetWear(WEAR_ABILITY8))
		{
			return WEAR_ABILITY8;
		}
		else
		{
			return -1;
		}
	}
#endif

// Search for:
		case ITEM_ROD:
			{
				if (bAdd)
				{
					if (m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON)
						m_pOwner->SetPart(PART_WEAPON, GetVnum());
				}
				else
				{
					if (m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON)
						m_pOwner->SetPart(PART_WEAPON, m_pOwner->GetOriginalPart(PART_WEAPON));
				}
			}
			break;

// Replace for:
		case ITEM_ROD:
			{
				if (bAdd)
				{
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
					if ((m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON) || (m_wCell == INVENTORY_MAX_NUM + WEAR_SECOND_WEAPON))
						m_pOwner->SetPart(PART_WEAPON, GetVnum());
#else
					if (m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON)
						m_pOwner->SetPart(PART_WEAPON, GetVnum());
#endif
				}
				else
				{
					
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
					if ((m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON) || (m_wCell == INVENTORY_MAX_NUM + WEAR_SECOND_WEAPON))
						m_pOwner->SetPart(PART_WEAPON, 0);
#else
					if (m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON)
						m_pOwner->SetPart(PART_WEAPON, m_pOwner->GetOriginalPart(PART_WEAPON));
#endif
				}
			}
			break;

// Search for:
		case ITEM_WEAPON:
			{
				if (bAdd)
				{
					if (m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON)
						m_pOwner->SetPart(PART_WEAPON, GetVnum());
				}
				else
				{
					if (m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON)
						m_pOwner->SetPart(PART_WEAPON, m_pOwner->GetOriginalPart(PART_WEAPON));		
				}
			}
			break;

// Replace for:
		case ITEM_WEAPON:
			{
				if (bAdd)
				{
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
					if ((m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON) || (m_wCell == INVENTORY_MAX_NUM + WEAR_SECOND_WEAPON))
#else
					if (m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON)
#endif
						m_pOwner->SetPart(PART_WEAPON, GetVnum());
				}
				else
				{
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
					if ((m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON) || (m_wCell == INVENTORY_MAX_NUM + WEAR_SECOND_WEAPON))
						m_pOwner->SetPart(PART_WEAPON, 0);
#else
					if (m_wCell == INVENTORY_MAX_NUM + WEAR_WEAPON)
						m_pOwner->SetPart(PART_WEAPON, m_pOwner->GetOriginalPart(PART_WEAPON));
						
#endif
						
				}
			}
			break;

// Search for:
						const CItem* pArmor = m_pOwner->GetWear(WEAR_BODY);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
						const CItem* pArmor = m_pOwner->GetEquipWear(WEAR_BODY);
#else
						const CItem* pArmor = m_pOwner->GetWear(WEAR_BODY);
#endif

// Search for:
	ch->SetWear(bWearCell, this);

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	ch->SetEquipSlot(bWearCell, this);
#endif

// Search for:
	m_wCell = INVENTORY_MAX_NUM + bWearCell;

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	if (ch->GetEquipIndexByWear(bWearCell) != ch->GetEquipIndex())
	{
		m_bEquipAlreadyStopped = true;
		Save();
		return true;
	}

	m_bEquipAlreadyStopped = false;
#endif


// Search for:
bool CItem::Unequip()

// Add before:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
void CItem::StartEquipEvent()
{
	m_bEquipAlreadyStopped = false;
	ModifyPoints(true);
	StartUniqueExpireEvent();
	if (-1 != GetProto()->cLimitTimerBasedOnWearIndex)
		StartTimerBasedOnWearExpireEvent();

	// ACCESSORY_REFINE
	StartAccessorySocketExpireEvent();
	// END_OF_ACCESSORY_REFINE

	m_pOwner->BuffOnAttr_AddBuffsFromItem(this);
	Save();
}

void CItem::StopEquipEvent()
{
	if (m_bEquipAlreadyStopped)
		return;

	if (!m_pOwner || GetCell() < INVENTORY_MAX_NUM)
	{
		sys_err("%s %u m_pOwner %p, GetCell %d",GetName(), GetID(), get_pointer(m_pOwner), GetCell());
		return;
	}

	if (this != m_pOwner->GetWear(GetCell() - INVENTORY_MAX_NUM))
	{
		sys_err("m_pOwner->GetWear() != this");
		return;
	}

	if (IsRideItem())
		ClearMountAttributeAndAffect();

	ModifyPoints(false);
	StopUniqueExpireEvent();

	if (-1 != GetProto()->cLimitTimerBasedOnWearIndex)
		StopTimerBasedOnWearExpireEvent();

	StopAccessorySocketExpireEvent();

	m_pOwner->BuffOnAttr_RemoveBuffsFromItem(this);
	Save();
}
#endif

// Search for (in ::Unequip):
	StopUniqueExpireEvent();

	if (-1 != GetProto()->cLimitTimerBasedOnWearIndex)
		StopTimerBasedOnWearExpireEvent();

// Add before:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	m_pOwner->RemoveEquipSlot(GetCell() - INVENTORY_MAX_NUM);
	m_bEquipAlreadyStopped = false;
#endif
