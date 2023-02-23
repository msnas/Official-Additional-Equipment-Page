// Search for:
	m_pkMiningEvent = NULL;

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	m_iEquipLoadTime = 0;
#endif

// Search for:
	tab.skill_group	= m_points.skill_group;

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	tab.equip_index = GetEquipIndex();
#endif

// Search for:
	SetGold(t->gold);

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	SetEquipIndex(t->equip_index);
#endif

// Search for:
	for (int i = 0 ; i < WEAR_MAX_NUM; i++) 
	{
		LPITEM pItem = GetWear(i);
		if (pItem)
		{
			pItem->ModifyPoints(true);
			SET_BIT(m_pointsInstant.dwImmuneFlag, GetWear(i)->GetImmuneFlag());
		}
	}

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	int bCellInitial = GetEquipIndex() == FIRST_TYPE_EQUIPMENT ? WEAR_BODY : WEAR_SECOND_BODY;
	int bCellEnd = GetEquipIndex() == FIRST_TYPE_EQUIPMENT ? WEAR_GLOVES : WEAR_SECOND_GLOVES;

	for (int i = bCellInitial; i <= bCellEnd; i++)
	{
		LPITEM pItem = GetWear(i);
		if (pItem)
		{
			pItem->ModifyPoints(true);
			SET_BIT(m_pointsInstant.dwImmuneFlag, GetWear(i)->GetImmuneFlag());
		}
	}

	for (int i = WEAR_COSTUME_BODY; i < WEAR_MAX_NUM; i++)
	{
		LPITEM pItem = GetWear(i);
		if (pItem)
		{
			pItem->ModifyPoints(true);
			SET_BIT(m_pointsInstant.dwImmuneFlag, GetWear(i)->GetImmuneFlag());
		}
	}
#else
	for (int i = 0 ; i < WEAR_MAX_NUM; i++) 
	{
		LPITEM pItem = GetWear(i);
		if (pItem)
		{
			pItem->ModifyPoints(true);
			SET_BIT(m_pointsInstant.dwImmuneFlag, GetWear(i)->GetImmuneFlag());
		}
	}
#endif

// Search for:
DWORD CHARACTER::GetMotionMode() const

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
DWORD CHARACTER::GetMotionMode()
#else
DWORD CHARACTER::GetMotionMode() const
#endif

// Search for:
	if ((pkItem = GetWear(WEAR_WEAPON)))

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	if ((pkItem = GetEquipWear(WEAR_WEAPON)))
#else
	if ((pkItem = GetWear(WEAR_WEAPON)))
#endif

// Search for:
float CHARACTER::GetMoveMotionSpeed() const

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
float CHARACTER::GetMoveMotionSpeed()
#else
float CHARACTER::GetMoveMotionSpeed() const
#endif

// Search for:
float CHARACTER::GetMoveSpeed() const
{
	return GetMoveMotionSpeed() * 10000 / CalculateDuration(GetLimitPoint(POINT_MOV_SPEED), 10000);
}

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
float CHARACTER::GetMoveSpeed()
{
	return GetMoveMotionSpeed() * 10000 / CalculateDuration(GetLimitPoint(POINT_MOV_SPEED), 10000);
}
#else
float CHARACTER::GetMoveSpeed() const
{
	return GetMoveMotionSpeed() * 10000 / CalculateDuration(GetLimitPoint(POINT_MOV_SPEED), 10000);
}
#endif

// Search for:
	LPITEM pick = GetWear(WEAR_WEAPON);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	LPITEM pick = GetEquipWear(WEAR_WEAPON);
#else
	LPITEM pick = GetWear(WEAR_WEAPON);
#endif

// Search for:
	LPITEM rod = GetWear(WEAR_WEAPON);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	LPITEM rod = GetEquipWear(WEAR_WEAPON);
#else
	LPITEM rod = GetWear(WEAR_WEAPON);
#endif

// Search for:
	LPITEM rod = GetWear(WEAR_WEAPON);

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	LPITEM rod = GetEquipWear(WEAR_WEAPON);
#else
	LPITEM rod = GetWear(WEAR_WEAPON);
#endif

// Search for:
		case PART_HAIR:
			return GetPart(PART_HAIR);

// Add after (only if you don't have it):
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
		case PART_WEAPON:
			return GetPart(PART_WEAPON);
#endif

// Search for:
int	CHARACTER::GetSkillPowerByLevel(int level, bool bMob) const
{
	return CTableBySkill::instance().GetSkillPowerByLevelFromType(GetJob(), GetSkillGroup(), MINMAX(0, level, SKILL_MAX_LEVEL), bMob); 
}

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
LPITEM CHARACTER::GetEquipWear(int wear)
{
	int bCell = GetEquipIndex() == FIRST_TYPE_EQUIPMENT ? wear : wear + WEAR_SECOND_BODY;

	if (bCell >= WEAR_MAX_NUM + DRAGON_SOUL_DECK_MAX_NUM * DS_SLOT_MAX)
	{
		sys_err("CHARACTER::GetEquipWear: invalid wear cell %d", bCell);
		return NULL;
	}

	return m_pointsInstant.pItems[INVENTORY_MAX_NUM + bCell];
}

int CHARACTER::GetEquipIndexByWear(int wear)
{
	if (wear < WEAR_SECOND_BODY)
		return FIRST_TYPE_EQUIPMENT;
	else if (wear >= WEAR_SECOND_BODY && wear <= WEAR_SECOND_GLOVES)
		return SECOND_TYPE_EQUIPMENT;

	return GetEquipIndex();
}

void CHARACTER::RemoveEquipSlot(int pos)
{
	if (pos < WEAR_SECOND_BODY)
	{
		auto exists = firstEquip.find(pos);
		if (exists != firstEquip.end())
			firstEquip.erase(exists);
	}
	else if (pos >= WEAR_SECOND_BODY && pos <= WEAR_SECOND_GLOVES)
	{
		auto exists = secondEquip.find(pos);
		if (exists != secondEquip.end())
			secondEquip.erase(exists);
	}
}

void CHARACTER::SetEquipSlot(int pos, LPITEM item)
{
	if (pos < WEAR_SECOND_BODY)
	{
		auto exists = firstEquip.find(pos);

		if (exists != firstEquip.end())
			exists->second = item;
		else
			firstEquip[pos] = item;
	}
	else if (pos >= WEAR_SECOND_BODY && pos <= WEAR_SECOND_GLOVES)
	{
		auto exists = secondEquip.find(pos);
		if (exists != secondEquip.end())
			exists->second = item;
		else
			secondEquip[pos] = item;
	}
}

void CHARACTER::ChangeEquip(int index, bool bIgnore)
{
	if (GetSkillLevel(SKILL_ADDITIONAL_PAGE) == 0)
		return;

	if (GetExchange() || GetMyShop() || GetShopOwner() || IsOpenSafebox() || IsCubeOpen())
	{
		ChatPacket(CHAT_TYPE_INFO, "You can't change equipment page while you're doing something else.");
		return;
	}

	if (!bIgnore)
	{
		if (index == GetEquipIndex())
			return;
	}

	int iPulse = thecore_pulse();
	if (iPulse - GetEquipLoadTime() < PASSES_PER_SEC(5))
	{
		ChatPacket(CHAT_TYPE_INFO, "You'll need to wait 5 seconds in order to do that again.");
		return;
	}

	SetEquipIndex(index);

	switch (index)
	{
		case FIRST_TYPE_EQUIPMENT:
		{
			if (secondEquip.size())
			{
				for (auto secondIndex = secondEquip.begin(); secondIndex != secondEquip.end(); ++secondIndex)
					secondIndex->second->StopEquipEvent();
			}

			if (firstEquip.size())
			{
				for (auto firstIndex = firstEquip.begin(); firstIndex != firstEquip.end(); ++firstIndex)
					firstIndex->second->StartEquipEvent();
			}
		}
		break;

		case SECOND_TYPE_EQUIPMENT:
		{
			if (firstEquip.size())
			{
				for (auto firstIndex = firstEquip.begin(); firstIndex != firstEquip.end(); ++firstIndex)
					firstIndex->second->StopEquipEvent();
			}

			if (secondEquip.size())
			{
				for (auto secondIndex = secondEquip.begin(); secondIndex != secondEquip.end(); ++secondIndex)
					secondIndex->second->StartEquipEvent();
			}
		}
		break;
	}

	
	SetEquipLoadTime();

	CheckMaximumPoints();
	ComputeBattlePoints();
	UpdatePacket();

	if (IsAffectFlag(AFF_GWIGUM))
		RemoveAffect(SKILL_GWIGEOM);

	if (IsAffectFlag(AFF_GEOMGYEONG))
		RemoveAffect(SKILL_GEOMKYUNG);

	ChatPacket(CHAT_TYPE_COMMAND, "SetEquipmentPage %d", index);

	if (!bIgnore)
		ChatPacket(CHAT_TYPE_INFO, "The equipment page was changed.");
}
#endif