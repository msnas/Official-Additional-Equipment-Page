// Search for:
	SKILL_RESIST_PENETRATE

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	, SKILL_ADDITIONAL_PAGE,
#endif

// Search for:
				if (m_pkChr->GetWear(WEAR_WEAPON) && m_pkChr->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
				if (m_pkChr->GetEquipWear(WEAR_WEAPON) && m_pkChr->GetEquipWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)
#else
				if (m_pkChr->GetWear(WEAR_WEAPON) && m_pkChr->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)
#endif

// Search for:
					if (m_pkChr->GetWear(WEAR_WEAPON) && m_pkChr->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
					if (m_pkChr->GetEquipWear(WEAR_WEAPON) && m_pkChr->GetEquipWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)
#else
					if (m_pkChr->GetWear(WEAR_WEAPON) && m_pkChr->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)
#endif

// Search for:
			if (m_pkChr->GetWear(WEAR_WEAPON) && m_pkChr->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
			if (m_pkChr->GetEquipWear(WEAR_WEAPON) && m_pkChr->GetEquipWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)
#else
			if (m_pkChr->GetWear(WEAR_WEAPON) && m_pkChr->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)
#endif

// Search for:
			if (m_pkChr->GetWear(WEAR_WEAPON) && m_pkChr->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_CLAW)

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
			if (m_pkChr->GetEquipWear(WEAR_WEAPON) && m_pkChr->GetEquipWear(WEAR_WEAPON)->GetSubType() == WEAPON_CLAW)
#else
			if (m_pkChr->GetWear(WEAR_WEAPON) && m_pkChr->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_CLAW)
#endif

// Search for:
					LPITEM pkWeapon = m_pkChr->GetWear(WEAR_WEAPON);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
					LPITEM pkWeapon = m_pkChr->GetEquipWear(WEAR_WEAPON);
#else
					LPITEM pkWeapon = m_pkChr->GetWear(WEAR_WEAPON);
#endif

// Search for (2x):
	LPITEM pkWeapon = GetWear(WEAR_WEAPON);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	LPITEM pkWeapon = GetEquipWear(WEAR_WEAPON);
#else
	LPITEM pkWeapon = GetWear(WEAR_WEAPON);
#endif

// Search for:
	const bool bCanUseHorseSkill = CanUseHorseSkill();

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	if (dwVnum == SKILL_ADDITIONAL_PAGE)
	{
		int index = GetEquipIndex() == FIRST_TYPE_EQUIPMENT ? SECOND_TYPE_EQUIPMENT : FIRST_TYPE_EQUIPMENT;
		ChangeEquip(index);

		return true;
	}
#endif

// Search for:
	if (GetWear(WEAR_WEAPON) && (GetWear(WEAR_WEAPON)->GetType() == ITEM_ROD || GetWear(WEAR_WEAPON)->GetType() == ITEM_PICK))

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	if (GetEquipWear(WEAR_WEAPON) && (GetEquipWear(WEAR_WEAPON)->GetType() == ITEM_ROD || GetEquipWear(WEAR_WEAPON)->GetType() == ITEM_PICK))
#else
	if (GetWear(WEAR_WEAPON) && (GetWear(WEAR_WEAPON)->GetType() == ITEM_ROD || GetWear(WEAR_WEAPON)->GetType() == ITEM_PICK))
#endif

// Search for:
		case 151: case 152: case 153: case 154: case 155: case 156: case 157: case 158: case 159:

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
		case SKILL_ADDITIONAL_PAGE:
#endif