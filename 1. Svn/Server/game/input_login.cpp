// Search for:
	ch->SendGreetMessage();

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	if (ch->GetSkillLevel(SKILL_ADDITIONAL_PAGE) == 0)
		ch->ChatPacket(CHAT_TYPE_COMMAND, "SetEquipmentPage %d", BASE_TYPE_EQUIPMENT);
	else
		ch->ChatPacket(CHAT_TYPE_COMMAND, "SetEquipmentPage %d", ch->GetEquipIndex());
#endif