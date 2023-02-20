# Search for:
	SKILL_INDEX_DICT = {
		JOB_WARRIOR : { 
			1 : (1, 2, 3, 4, 5, 0, 0, 0, 137, 0, 138, 0, 139, 0,), 
			2 : (16, 17, 18, 19, 20, 0, 0, 0, 137, 0, 138, 0, 139, 0,), 
			"SUPPORT" : (121, 134, 133, 129, 130, 131, 123, 124, 122, 132, 246),
		},
		JOB_ASSASSIN : { 
			1 : (31, 32, 33, 34, 35, 0, 0, 0, 137, 0, 138, 0, 139, 0, 140,), 
			2 : (46, 47, 48, 49, 50, 0, 0, 0, 137, 0, 138, 0, 139, 0, 140,), 
			"SUPPORT" : (121, 134, 133, 129, 130, 131, 123, 124, 122, 132, 246),
		},
		JOB_SURA : { 
			1 : (61, 62, 63, 64, 65, 66, 0, 0, 137, 0, 138, 0, 139, 0,),
			2 : (76, 77, 78, 79, 80, 81, 0, 0, 137, 0, 138, 0, 139, 0,),
			"SUPPORT" : (121, 134, 133, 129, 130, 131, 123, 124, 122, 132, 246),
		},
		JOB_SHAMAN : { 
			1 : (91, 92, 93, 94, 95, 96, 0, 0, 137, 0, 138, 0, 139, 0,),
			2 : (106, 107, 108, 109, 110, 111, 0, 0, 137, 0, 138, 0, 139, 0,),
			"SUPPORT" : (121, 134, 133, 129, 130, 131, 123, 124, 122, 132, 246),
		},
	}

# Add after:
	if app.ENABLE_ADDITIONAL_EQUIPMENT_PAGE:
		jobIndex = JOB_SHAMAN
		if app.ENABLE_WOLFMAN_CHARACTER:
			jobIndex = JOB_WOLFMAN

		for job in xrange(jobIndex + 1):
			tmp = list(SKILL_INDEX_DICT[job]["SUPPORT"])
			tmp.append(player.SKILL_ADDITIONAL_PAGE)
			SKILL_INDEX_DICT[job]["SUPPORT"] = tuple(tmp)
