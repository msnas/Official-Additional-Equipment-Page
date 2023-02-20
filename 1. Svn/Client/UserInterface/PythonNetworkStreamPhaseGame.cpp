// Search for:
bool CPythonNetworkStream::SendDragonSoulRefinePacket(BYTE bRefineType, TItemPos* pos)
{
	TPacketCGDragonSoulRefine pk;
	pk.header = HEADER_CG_DRAGON_SOUL_REFINE;
	pk.bSubType = bRefineType;
	memcpy (pk.ItemGrid, pos, sizeof (TItemPos) * DS_REFINE_WINDOW_MAX_NUM);
	if (!Send(sizeof (pk), &pk))
	{
		return false;
	}
	return true;
}

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
bool CPythonNetworkStream::ChangeEquipment(int index)
{
	if (!__CanActMainInstance())
		return true;

	TChangeEquipment equip;
	equip.header = HEADER_CG_CHANGE_EQUIP;
	equip.index = index;

	if (!Send(sizeof(equip), &equip))
		return false;

	return SendSequence();
}
#endif
