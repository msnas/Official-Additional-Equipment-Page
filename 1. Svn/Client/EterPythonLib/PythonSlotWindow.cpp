// Search for:
DWORD CSlotWindow::Type()

// Add before:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
void CSlotWindow::SetSlotChange(DWORD oldIndex, DWORD newIndex)
{
	TSlot* pSlot;
	if (!GetSlotPointer(oldIndex, &pSlot))
		return;

	pSlot->dwSlotNumber = newIndex;
}
#endif