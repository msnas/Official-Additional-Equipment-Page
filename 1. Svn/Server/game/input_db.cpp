// Search for:
	ch->CheckMaximumPoints();
	ch->PointsPacket();

	ch->SetItemLoaded();

// Add BEFORE:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	ch->ChangeEquip(ch->GetEquipIndex(), true);
#endif