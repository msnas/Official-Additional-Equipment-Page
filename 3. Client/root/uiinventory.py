# Search for:
			wndEquip = self.GetChild("EquipmentSlot")

# Replace for:
			if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
				wndEquip = self.GetChild("EquipmentSlot")

# Search for:
			self.mallButton = self.GetChild2("MallButton")
			self.DSSButton = self.GetChild2("DSSButton")
			self.costumeButton = self.GetChild2("CostumeButton")

# Replace for:
			if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
				self.mallButton = self.GetChild2("MallButton")
				self.DSSButton = self.GetChild2("DSSButton")
				self.costumeButton = self.GetChild2("CostumeButton")

# Search for:
			self.equipmentTab = []
			self.equipmentTab.append(self.GetChild("Equipment_Tab_01"))
			self.equipmentTab.append(self.GetChild("Equipment_Tab_02"))

# Replace for:
			if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
				self.equipmentTab = []
				self.equipmentTab.append(self.GetChild("Equipment_Tab_01"))
				self.equipmentTab.append(self.GetChild("Equipment_Tab_02"))

# Search for:
			if self.costumeButton and not app.ENABLE_COSTUME_SYSTEM:
				self.costumeButton.Hide()
				self.costumeButton.Destroy()
				self.costumeButton = 0

# Replace for:
			if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
				if self.costumeButton and not app.ENABLE_COSTUME_SYSTEM:
					self.costumeButton.Hide()
					self.costumeButton.Destroy()
					self.costumeButton = 0

# Search for:
		## Equipment
		wndEquip.SetSelectEmptySlotEvent(ui.__mem_func__(self.SelectEmptySlot))
		wndEquip.SetSelectItemSlotEvent(ui.__mem_func__(self.SelectItemSlot))
		wndEquip.SetUnselectItemSlotEvent(ui.__mem_func__(self.UseItemSlot))
		wndEquip.SetUseSlotEvent(ui.__mem_func__(self.UseItemSlot))
		wndEquip.SetOverInItemEvent(ui.__mem_func__(self.OverInItem))
		wndEquip.SetOverOutItemEvent(ui.__mem_func__(self.OverOutItem))

# Replace for:
		if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			## Equipment
			wndEquip.SetSelectEmptySlotEvent(ui.__mem_func__(self.SelectEmptySlot))
			wndEquip.SetSelectItemSlotEvent(ui.__mem_func__(self.SelectItemSlot))
			wndEquip.SetUnselectItemSlotEvent(ui.__mem_func__(self.UseItemSlot))
			wndEquip.SetUseSlotEvent(ui.__mem_func__(self.UseItemSlot))
			wndEquip.SetOverInItemEvent(ui.__mem_func__(self.OverInItem))
			wndEquip.SetOverOutItemEvent(ui.__mem_func__(self.OverOutItem))

# Search for:
		self.equipmentTab[0].SetEvent(lambda arg=0: self.SetEquipmentPage(arg))
		self.equipmentTab[1].SetEvent(lambda arg=1: self.SetEquipmentPage(arg))
		self.equipmentTab[0].Down()
		self.equipmentTab[0].Hide()
		self.equipmentTab[1].Hide()

# Replace for:
		if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.equipmentTab[0].SetEvent(lambda arg=0: self.SetEquipmentPage(arg))
			self.equipmentTab[1].SetEvent(lambda arg=1: self.SetEquipmentPage(arg))
			self.equipmentTab[0].Down()
			self.equipmentTab[0].Hide()
			self.equipmentTab[1].Hide()

# Search for:
		self.wndEquip = wndEquip

# Replace for:
		if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.wndEquip = wndEquip

# Search for:
		# MallButton
		if self.mallButton:
			self.mallButton.SetEvent(ui.__mem_func__(self.ClickMallButton))

		if self.DSSButton:
			self.DSSButton.SetEvent(ui.__mem_func__(self.ClickDSSButton)) 
	
		# Costume Button
		if self.costumeButton:
			self.costumeButton.SetEvent(ui.__mem_func__(self.ClickCostumeButton))

		self.wndCostume = None

# Replace for:
		if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			# MallButton
			if self.mallButton:
				self.mallButton.SetEvent(ui.__mem_func__(self.ClickMallButton))

			if self.DSSButton:
				self.DSSButton.SetEvent(ui.__mem_func__(self.ClickDSSButton)) 
		
			# Costume Button
			if self.costumeButton:
				self.costumeButton.SetEvent(ui.__mem_func__(self.ClickCostumeButton))

			self.wndCostume = None

# Search for:
		self.SetEquipmentPage(0)

# Replace for:
		if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.SetEquipmentPage(0)

# Search for:
		self.wndEquip = 0

# Replace for:
		if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.wndEquip = 0

# Search for:
		if self.wndCostume:
			self.wndCostume.Destroy()
			self.wndCostume = 0

# Replace for:
		if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			if self.wndCostume:
				self.wndCostume.Destroy()
				self.wndCostume = 0

# Search for:
		self.inventoryTab = []

# Replace for:
		if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.inventoryTab = []

# Search for:
	def SetEquipmentPage(self, page):
		self.equipmentPageIndex = page
		self.equipmentTab[1-page].SetUp()
		self.RefreshEquipSlotWindow()

# Replace for:
	if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
		def SetEquipmentPage(self, page):
			self.equipmentPageIndex = page
			self.equipmentTab[1-page].SetUp()
			self.RefreshEquipSlotWindow()

# Search for:
		def RefreshEquipSlotWindow(self):
			getItemVNum=player.GetItemIndex
			getItemCount=player.GetItemCount
			setItemVNum=self.wndEquip.SetItemSlot
			for i in xrange(player.EQUIPMENT_PAGE_COUNT):
				slotNumber = player.EQUIPMENT_SLOT_START + i
				itemCount = getItemCount(slotNumber)
				if itemCount <= 1:
					itemCount = 0
				setItemVNum(slotNumber, getItemVNum(slotNumber), itemCount)

			if app.ENABLE_NEW_EQUIPMENT_SYSTEM:
				for i in xrange(player.NEW_EQUIPMENT_SLOT_COUNT):
					slotNumber = player.NEW_EQUIPMENT_SLOT_START + i
					itemCount = getItemCount(slotNumber)
					if itemCount <= 1:
						itemCount = 0
					setItemVNum(slotNumber, getItemVNum(slotNumber), itemCount)
					print "ENABLE_NEW_EQUIPMENT_SYSTEM", slotNumber, itemCount, getItemVNum(slotNumber)
					


			self.wndEquip.RefreshSlot()
			
			if self.wndCostume:
				self.wndCostume.RefreshCostumeSlot()

# Replace for:
	if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
		def RefreshEquipSlotWindow(self):
			getItemVNum=player.GetItemIndex
			getItemCount=player.GetItemCount
			setItemVNum=self.wndEquip.SetItemSlot
			for i in xrange(player.EQUIPMENT_PAGE_COUNT):
				slotNumber = player.EQUIPMENT_SLOT_START + i
				itemCount = getItemCount(slotNumber)
				if itemCount <= 1:
					itemCount = 0
				setItemVNum(slotNumber, getItemVNum(slotNumber), itemCount)

			if app.ENABLE_NEW_EQUIPMENT_SYSTEM:
				for i in xrange(player.NEW_EQUIPMENT_SLOT_COUNT):
					slotNumber = player.NEW_EQUIPMENT_SLOT_START + i
					itemCount = getItemCount(slotNumber)
					if itemCount <= 1:
						itemCount = 0
					setItemVNum(slotNumber, getItemVNum(slotNumber), itemCount)
					print "ENABLE_NEW_EQUIPMENT_SYSTEM", slotNumber, itemCount, getItemVNum(slotNumber)
					


			self.wndEquip.RefreshSlot()
			
			if self.wndCostume:
				self.wndCostume.RefreshCostumeSlot()

# Search for:
		self.RefreshEquipSlotWindow()

# Replace for:
		if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.RefreshEquipSlotWindow()