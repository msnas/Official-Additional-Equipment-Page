# Search for:
		self.serverCommander=stringcommander.Analyzer()
		for serverCommandItem in serverCommandList.items():
			self.serverCommander.SAFE_RegisterCallBack(
				serverCommandItem[0], serverCommandItem[1]
			)

# Add BEFORE:
		if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
			serverCommandList["SetEquipmentPage"] = self.__SetEquipmentPage

# Search for:
	def __PlayMusic(self, flag, filename):
		flag = int(flag)
		if flag:
			snd.FadeOutAllMusic()
			musicinfo.SaveLastPlayFieldMusic()
			snd.FadeInMusic("BGM/" + filename)
		else:
			snd.FadeOutAllMusic()
			musicinfo.LoadLastPlayFieldMusic()
			snd.FadeInMusic("BGM/" + musicinfo.fieldMusic)
	# END_OF_WEDDING

# Add after:
	if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
		def __SetEquipmentPage(self, index):
			if self.interface:
				self.interface.SetEquipmentPage(index)
