// Search for:
	long			gold;

// Add after:
#ifdef  ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	int				equip_index;
#endif

// Search for:
		DWORD			GetMotionMode() const;
		float			GetMoveMotionSpeed() const;
		float			GetMoveSpeed() const;

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
		DWORD			GetMotionMode();
		float			GetMoveMotionSpeed();
		float			GetMoveSpeed();
#else
		DWORD			GetMotionMode() const;
		float			GetMoveMotionSpeed() const;
		float			GetMoveSpeed() const;
#endif

// Search for:
		bool			IsEmptyItemGrid(TItemPos Cell, BYTE size, int iExceptionCell = -1) const;

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
		bool			IsEmptyItemGrid(TItemPos Cell, BYTE size, int iExceptionCell = -1);
#else
		bool			IsEmptyItemGrid(TItemPos Cell, BYTE size, int iExceptionCell = -1) const;
#endif

// Search for:
		int				GetEmptyInventory(BYTE size) const;
		int				GetEmptyDragonSoulInventory(LPITEM pItem) const;

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
		int				GetEmptyInventory(BYTE size);
		int				GetEmptyDragonSoulInventory(LPITEM pItem);
#else
		int				GetEmptyInventory(BYTE size) const;
		int				GetEmptyDragonSoulInventory(LPITEM pItem) const;
#endif

// Search for:
	public:
		void			SetLastSyncTime(const timeval &tv) { memcpy(&m_tvLastSyncTime, &tv, sizeof(timeval)); }
		const timeval&	GetLastSyncTime() { return m_tvLastSyncTime; }
		void			SetSyncHackCount(int iCount) { m_iSyncHackCount = iCount;}
		int				GetSyncHackCount() { return m_iSyncHackCount; }

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
	protected:
		int						m_iEquipLoadTime;
		std::map<int, LPITEM>	firstEquip;
		std::map<int, LPITEM>	secondEquip;

	public:
		void			ChangeEquip(int index, bool bSkipUpdate = false);

		void			SetEquipIndex(int index) { m_points.equip_index = index; };
		int				GetEquipIndex() { return m_points.equip_index; };
		int				GetEquipLoadTime() const { return m_iEquipLoadTime; }
		void			SetEquipLoadTime() { m_iEquipLoadTime = thecore_pulse(); }
		void			RemoveEquipSlot(int pos);
		void			SetEquipSlot(int pos, LPITEM item);
		LPITEM			GetEquipWear(int wear);
#endif