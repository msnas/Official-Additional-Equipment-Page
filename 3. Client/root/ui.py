# Search for:
	def SetSlotCountNew(self, slotNumber, grade, count):
		wndMgr.SetSlotCountNew(self.hWnd, slotNumber, grade, count)

# Add after:
	if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
		def SetSlotChange(self, oldSlotNumber, newSlotNumber):
			wndMgr.SetSlotChange(self.hWnd, oldSlotNumber, newSlotNumber)