# Search for:
		self.wndInventory = None

# Add after:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.wndEquip = None

# Search for:
		wndInventory = uiinventory.InventoryWindow()
		wndInventory.BindInterfaceClass(self)

# Add after:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			wndEquip = uiequipmentdialog.EquipmentDialog()
			wndEquip.BindInterfaceClass(self)

# Search for:
		self.wndInventory = wndInventory

# Add after:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.wndEquip = wndEquip

# Search for:
		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			self.wndDragonSoul.SetDragonSoulRefineWindow(self.wndDragonSoulRefine)
			self.wndDragonSoulRefine.SetInventoryWindows(self.wndInventory, self.wndDragonSoul)
			self.wndInventory.SetDragonSoulRefineWindow(self.wndDragonSoulRefine)

# Add after:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.wndEquip.SetInventoryWindow(self.wndInventory)

# Search for:
		self.wndCubeResult.SetItemToolTip(self.tooltipItem)

# Add after:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.wndEquip.SetItemToolTip(self.tooltipItem)

# Search for:
		if self.wndInventory:
			self.wndInventory.Destroy()

# Add after:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			if self.wndEquip:
				self.wndEquip.Destroy()

# Search for:
		del self.wndInventory

# Add after:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			if self.wndEquip:
				del self.wndEquip

# Search for:
		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			self.wndDragonSoul.RefreshItemSlot()

# Add after:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.wndEquip.RefreshItemSlot()

# Search for:
	def RefreshMessenger(self):
		self.wndMessenger.RefreshMessenger()

# Add before:
	if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
		def SetEquipmentPage(self, index):
			if self.wndEquip:
				self.wndEquip.SetEquipmentPage(int(index))

# Search for:
		self.wndInventory.Show()

# Add after:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.wndEquip.Show()

# Search for:
		if self.wndInventory:
			self.wndInventory.Hide()

# Add after:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			if self.wndEquip:
				self.wndEquip.Show()

# Search for:
	def ToggleInventoryWindow(self):
		if False == player.IsObserverMode():
			if False == self.wndInventory.IsShow():
				self.wndInventory.Show()
				self.wndInventory.SetTop()
			else:
				self.wndInventory.OverOutItem()
				self.wndInventory.Close()

# Replace for:
	def ToggleInventoryWindow(self):
		if False == player.IsObserverMode():
			if False == self.wndInventory.IsShow():
				self.wndInventory.Show()
				self.wndInventory.SetTop()

				if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
					self.wndEquip.Show()
					self.wndEquip.SetTop()
			else:
				self.wndInventory.OverOutItem()
				self.wndInventory.Close()
	
				if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
					self.wndEquip.OverOutItem()
					self.wndEquip.Close()

# Search for:
		if app.ENABLE_DRAGON_SOUL_SYSTEM:
			hideWindows += self.wndDragonSoul,\
							self.wndDragonSoulRefine,

# Add after:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			hideWindows += self.wndEquip,
