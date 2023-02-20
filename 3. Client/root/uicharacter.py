# Search for:
		SUPPORT_PAGE_SLOT_COUNT = 12

# Replace for:
	if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
		SUPPORT_PAGE_SLOT_COUNT = 18
	else:
		SUPPORT_PAGE_SLOT_COUNT = 12

# Search for:
			skillPage.RefreshSlot()

# Add BEFORE:
			if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
				if player.SKILL_ADDITIONAL_PAGE == skillIndex:
					if skillLevel == 0:
							skillPage.ClearSlot(slotIndex)
					else:
						skillPage.SetSkillSlot(slotIndex, skillIndex, 0)
						skillPage.SetSlotCountNew(slotIndex, skillGrade, 0)
						skillPage.SetCoverButton(slotIndex)

