// Search for:
			void ReserveDestroyCoolTimeFinishEffect(DWORD dwSlotIndex);

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
			void	SetSlotChange(DWORD oldIndex, DWORD newIndex);
#endif