# Search for:
import app

# Add after:
if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
	import net
	import constinfo
	import mousemodule
	import chat
	import localeinfo
	import uicommon
	import item
	import uiprivateshopbuilder
	import uiinventory
	import player
	import ime
	import snd
	import wndMgr

	BASE_TAB = -1
	FIRST_EQUIPMENT = 0
	SECOND_EQUIPMENT = 1

# Search for:
	def __init__(self):

# Add BEFORE:
	if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
		wndCostume = None
		isOpenedCostumeWindowWhenClosingInventory = 0
		equipmentPageIndex = None
		windowChanged = None
		windowStart = False

# Search for:
			self.slotWindow = getObject("EquipmentSlot")

# Add after:
			if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
				self.uniqueSlot = getObject("unique_slot")
				self.DSSButton = getObject("dragon_soul_button")
				self.mallButton = getObject("mall_button")
				self.costumeButton = getObject("costume_button")

				self.base_tab = getObject("base_tab")
				self.windowTab = getObject("additional_tab")

				self.equipmentTab = []
				self.equipmentTab.append(self.GetChild("tab_btn_01"))
				self.equipmentTab.append(self.GetChild("tab_btn_02"))

				self.equipmentTabImage = []
				self.equipmentTabImage.append(self.GetChild("tab_img_01"))
				self.equipmentTabImage.append(self.GetChild("tab_img_02"))

# Search for:
		self.slotWindow.SetOverOutItemEvent(ui.__mem_func__(self.OverOutItem))

# Add after:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.board.SetTitleName(localeinfo.EQUIPMENT_TITLE_NAME)

			self.slotWindow.SetSelectItemSlotEvent(ui.__mem_func__(self.SelectItemSlot))
			self.slotWindow.SetUnselectItemSlotEvent(ui.__mem_func__(self.UseItemSlot))
			self.slotWindow.SetUseSlotEvent(ui.__mem_func__(self.UseItemSlot))
			self.slotWindow.SetSelectEmptySlotEvent(ui.__mem_func__(self.SelectEmptySlot))

			self.uniqueSlot.SetOverInItemEvent(ui.__mem_func__(self.OverInItem))
			self.uniqueSlot.SetOverOutItemEvent(ui.__mem_func__(self.OverOutItem))
			self.uniqueSlot.SetSelectItemSlotEvent(ui.__mem_func__(self.SelectItemSlot))
			self.uniqueSlot.SetUnselectItemSlotEvent(ui.__mem_func__(self.UseItemSlot))
			self.uniqueSlot.SetUseSlotEvent(ui.__mem_func__(self.UseItemSlot))
			self.uniqueSlot.SetSelectEmptySlotEvent(ui.__mem_func__(self.SelectEmptySlot))

			# MallButton
			if self.mallButton:
				self.mallButton.SetEvent(ui.__mem_func__(self.ClickMallButton))

			if self.DSSButton:
				self.DSSButton.SetEvent(ui.__mem_func__(self.ClickDSSButton)) 
		
			# Costume Button
			if self.costumeButton:
				self.costumeButton.SetEvent(ui.__mem_func__(self.ClickCostumeButton))

			self.equipmentTab[0].SetEvent(self.SetFirstInventory)
			self.equipmentTab[1].SetEvent(self.SetSecondInventory)

			self.equipmentTabImage[0].SAFE_SetStringEvent("MOUSE_BUTTON_DOWN", self.SetSecondInventory)
			self.equipmentTabImage[1].SAFE_SetStringEvent("MOUSE_BUTTON_DOWN", self.SetFirstInventory)

# Search for:
		self.tooltipItem = None

# Replace for:
		if not app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.tooltipItem = None

# Search for:
		if self.eventClose:
			self.eventClose(self.vid)

# Add after:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			if self.wndCostume:
				self.isOpenedCostumeWindowWhenClosingInventory = self.wndCostume.IsShow() # Was the costume open when the inventory window closed?
				self.wndCostume.Close()

# Search for:
		if None == self.tooltipItem:
			return

		if not slotIndex in self.itemDataDict:
			return

		itemVnum = self.itemDataDict[slotIndex][0]
		if 0 == itemVnum:
			return

		self.tooltipItem.ClearToolTip()
		metinSlot = self.itemDataDict[slotIndex][2]
		attrSlot = self.itemDataDict[slotIndex][3]
		self.tooltipItem.AddItemData(itemVnum, metinSlot, attrSlot)
		self.tooltipItem.ShowToolTip()

# Replace for:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			self.ShowToolTip(slotIndex)
		else:
			if None == self.tooltipItem:
				return

			if not slotIndex in self.itemDataDict:
				return

			itemVnum = self.itemDataDict[slotIndex][0]
			if 0 == itemVnum:
				return

			self.tooltipItem.ClearToolTip()
			metinSlot = self.itemDataDict[slotIndex][2]
			attrSlot = self.itemDataDict[slotIndex][3]
			self.tooltipItem.AddItemData(itemVnum, metinSlot, attrSlot)
			self.tooltipItem.ShowToolTip()

# Search for:
	def OnPressEscapeKey(self):
		self.Close()
		return True

# Add after:
	if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
		def BindInterfaceClass(self, interface):
			self.interface = interface

		def SetInventoryWindow(self, inventory):
			self.inventory = inventory

		def Show(self):
			ui.ScriptWindow.Show(self)

			if not self.windowStart:
				screen_width = wndMgr.GetScreenWidth()
				screen_height = wndMgr.GetScreenHeight()
	
				if screen_width > 800 and screen_height > 600:
					if self.inventory:
						x, y = self.inventory.GetGlobalPosition()
						self.SetPosition(x, y - 290)

				self.windowStart = True

			# If the costume was open when the inventory was closed, the costume should also be opened when the inventory is opened.
			if self.isOpenedCostumeWindowWhenClosingInventory and self.wndCostume:
				self.wndCostume.Show() 

		def RefreshItemSlot(self):
			self.RefreshEquipSlotWindow()
		
		def SetSecondInventory(self):
			if self.equipmentPageIndex == SECOND_EQUIPMENT:
				return
			
			net.ChangeEquipment(SECOND_EQUIPMENT)

		def SetFirstInventory(self):
			if self.equipmentPageIndex == FIRST_EQUIPMENT:
				return

			net.ChangeEquipment(FIRST_EQUIPMENT)

		def SetEquipmentPage(self, page):
			if page == self.equipmentPageIndex:
				return
			
			for image in self.equipmentTabImage:
				image.Hide()

			self.equipmentPageIndex = page

			if page == BASE_TAB:
				self.base_tab.Show()
				self.windowTab.Hide()
			else:
				self.base_tab.Hide()
				self.windowTab.Show()
				self.equipmentTabImage[self.equipmentPageIndex].Show()

			self.RefreshEquipSlotWindow()

		def RefreshEquipSlotWindow(self):
			getItemVNum=player.GetItemIndex
			getItemCount=player.GetItemCount
			setItemVNum=self.slotWindow.SetItemSlot
			SetSlotChange=self.slotWindow.SetSlotChange
			setUniqueItemVnum=self.uniqueSlot.SetItemSlot
			SetUniqueSlotChange=self.uniqueSlot.SetSlotChange

			if self.equipmentPageIndex == FIRST_EQUIPMENT or self.equipmentPageIndex == BASE_TAB:
				for i in xrange(player.EQUIPMENT_PAGE_COUNT):
					slotNumber = player.EQUIPMENT_SLOT_START + i
					if self.windowChanged == SECOND_EQUIPMENT:
						newSlotNumber = player.EQUIPMENT_SECOND_SLOT_START + i

					itemCount = getItemCount(slotNumber)
					if itemCount <= 1:
						itemCount = 0

					if self.windowChanged == SECOND_EQUIPMENT:
						SetSlotChange(newSlotNumber, slotNumber)
					else:
						SetSlotChange(i, slotNumber)

					setItemVNum(slotNumber, getItemVNum(slotNumber), itemCount)

			elif self.equipmentPageIndex == SECOND_EQUIPMENT:
				for i in xrange(player.EQUIPMENT_PAGE_COUNT):
					newSlotNumber = player.EQUIPMENT_SECOND_SLOT_START + i
					if self.windowChanged == FIRST_EQUIPMENT or self.windowChanged == BASE_TAB:
						slotNumber = player.EQUIPMENT_SLOT_START + i

					itemCount = getItemCount(newSlotNumber)
					if itemCount <= 1:
						itemCount = 0

					if self.windowChanged == FIRST_EQUIPMENT or self.windowChanged == BASE_TAB:
						SetSlotChange(slotNumber, newSlotNumber)
						setItemVNum(newSlotNumber, getItemVNum(newSlotNumber), itemCount)
					else:
						SetSlotChange(i, newSlotNumber)
						setItemVNum(newSlotNumber, getItemVNum(newSlotNumber), itemCount)

			if app.ENABLE_NEW_EQUIPMENT_SYSTEM:
				for i in xrange(player.NEW_EQUIPMENT_SLOT_COUNT):
					slotNumber = player.NEW_EQUIPMENT_SLOT_START + i
					itemCount = getItemCount(slotNumber)
					if itemCount <= 1:
						itemCount = 0

					SetUniqueSlotChange(i, slotNumber)
					setUniqueItemVnum(slotNumber, getItemVNum(slotNumber), itemCount)

			self.windowChanged = self.equipmentPageIndex

			self.slotWindow.RefreshSlot()
			self.uniqueSlot.RefreshSlot()

			if self.wndCostume:
				self.wndCostume.RefreshCostumeSlot()

		def ClickMallButton(self):
			net.SendChatPacket("/click_mall")

		def ClickDSSButton(self):
			self.interface.ToggleDragonSoulWindow()

		def ClickCostumeButton(self):
			if self.wndCostume:
				if self.wndCostume.IsShow(): 
					self.wndCostume.Hide()
				else:
					self.wndCostume.Show()
			else:
				self.wndCostume = uiinventory.CostumeWindow(self)
				self.wndCostume.Show()

				equipX, equipY = self.GetGlobalPosition()
				costumeX, costumeY = self.wndCostume.GetGlobalPosition()

				self.wndCostume.SetPosition(costumeX, equipY)

		def __SendMoveItemPacket(self, srcSlotPos, dstSlotPos, srcItemCount):
			# Prevent items from being used while the personal shop is open
			if uiprivateshopbuilder.IsBuildingPrivateShop():
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeinfo.MOVE_ITEM_FAILURE_PRIVATE_SHOP)
				return

			net.SendItemMovePacket(srcSlotPos, dstSlotPos, srcItemCount)

		def SelectItemSlot(self, itemSlotIndex):
			if constinfo.GET_ITEM_DROP_QUESTION_DIALOG_STATUS() == 1:
				return

			if mousemodule.mouseController.isAttached():
				attachedSlotType = mousemodule.mouseController.GetAttachedType()
				attachedSlotPos = mousemodule.mouseController.GetAttachedSlotNumber()
				attachedItemVID = mousemodule.mouseController.GetAttachedItemIndex()

				if player.SLOT_TYPE_INVENTORY == attachedSlotType:
					self.__DropSrcItemToDestItemInInventory(attachedItemVID, attachedSlotPos, itemSlotIndex)
				mousemodule.mouseController.DeattachObject()
			else:
				curCursorNum = app.GetCursor()
				if app.BUY == curCursorNum:
					chat.AppendChat(chat.CHAT_TYPE_INFO, localeinfo.SHOP_BUY_INFO)

				elif app.IsPressed(app.DIK_LALT):
					link = player.GetItemLink(itemSlotIndex)
					ime.PasteString(link)

				else:
					selectedItemVNum = player.GetItemIndex(itemSlotIndex)
					itemCount = player.GetItemCount(itemSlotIndex)
					mousemodule.mouseController.AttachObject(self, player.SLOT_TYPE_INVENTORY, itemSlotIndex, selectedItemVNum, itemCount)
					snd.PlaySound("sound/ui/pick.wav")
					
		def SelectEmptySlot(self, selectedSlotPos):
			if constinfo.GET_ITEM_DROP_QUESTION_DIALOG_STATUS() == 1:
				return

			if mousemodule.mouseController.isAttached():
				attachedSlotType = mousemodule.mouseController.GetAttachedType()
				attachedSlotPos = mousemodule.mouseController.GetAttachedSlotNumber()

				if player.SLOT_TYPE_INVENTORY == attachedSlotType:
					attachedCount = mousemodule.mouseController.GetAttachedItemCount()
					self.__SendMoveItemPacket(attachedSlotPos, selectedSlotPos, attachedCount)

				mousemodule.mouseController.DeattachObject()

		def __DropSrcItemToDestItemInInventory(self, srcItemVID, srcItemSlotPos, dstItemSlotPos):
			if srcItemSlotPos == dstItemSlotPos:
				return
						
			## If the moved location is an installation slot, use an item to equip it - [levites]
			if player.IsEquipmentSlot(dstItemSlotPos):

				## Only when the item you are holding is an equipment
				if item.IsEquipmentVID(srcItemVID):
					self.__UseItem(srcItemSlotPos)
			else:
				self.__SendMoveItemPacket(srcItemSlotPos, dstItemSlotPos, 0)

		def UseItemSlot(self, slotIndex):
			if constinfo.GET_ITEM_DROP_QUESTION_DIALOG_STATUS():
				return
			
			self.__UseItem(slotIndex)
			mousemodule.mouseController.DeattachObject()
			self.OverOutItem()

		def __UseItem(self, slotIndex):
			ItemVNum = player.GetItemIndex(slotIndex)
			item.SelectItem(ItemVNum)

			if item.IsFlag(item.ITEM_FLAG_CONFIRM_WHEN_USE):
				self.questionDialog = uicommon.QuestionDialog()
				self.questionDialog.SetText(localeinfo.INVENTORY_REALLY_USE_ITEM)
				self.questionDialog.SetAcceptEvent(ui.__mem_func__(self.__UseItemQuestionDialog_OnAccept))
				self.questionDialog.SetCancelEvent(ui.__mem_func__(self.__UseItemQuestionDialog_OnCancel))
				self.questionDialog.Open()
				self.questionDialog.slotIndex = slotIndex
				
			else:
				self.__SendUseItemPacket(slotIndex)

		def OnCloseQuestionDialog(self):
			if self.questionDialog:
				self.questionDialog.Close()

			self.questionDialog = None

		def __UseItemQuestionDialog_OnCancel(self):
			self.OnCloseQuestionDialog()

		def __UseItemQuestionDialog_OnAccept(self):
			self.__SendUseItemPacket(self.questionDialog.slotIndex)

		def __SendUseItemPacket(self, slotPos):
			# Prevent items from being used while the personal shop is open
			if uiprivateshopbuilder.IsBuildingPrivateShop():
				chat.AppendChat(chat.CHAT_TYPE_INFO, localeinfo.USE_ITEM_FAILURE_PRIVATE_SHOP)
				return

			net.SendItemUsePacket(slotPos)

		def ShowToolTip(self, slotIndex):
			if None != self.tooltipItem:
				self.tooltipItem.SetInventoryItem(slotIndex)
