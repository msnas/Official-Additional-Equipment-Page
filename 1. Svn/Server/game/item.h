// Search for:
		WORD		GetCell()				{ return m_wCell;	}

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
		void		StartEquipEvent();
		void		StopEquipEvent();
#endif