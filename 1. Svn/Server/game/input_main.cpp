// Search for:
				 ch->GetWear(WEAR_WEAPON) &&
				 ch->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
				ch->GetEquipWear(WEAR_WEAPON) &&
				ch->GetEquipWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)
#else
				 ch->GetWear(WEAR_WEAPON) &&
				 ch->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_DAGGER)
#endif

// Search for (only if you have WOLFMAN/LYCAN):
		else if (bArg == 21 && idx == 2 && ch->GetComboSequence() == 5 && ch->GetJob() == JOB_WOLFMAN && ch->GetWear(WEAR_WEAPON) && ch->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_CLAW)

// Replace for:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
		else if (bArg == 21 && idx == 2 && ch->GetComboSequence() == 5 && ch->GetJob() == JOB_WOLFMAN && ch->GetEquipWear(WEAR_WEAPON) && ch->GetEquipWear(WEAR_WEAPON)->GetSubType() == WEAPON_CLAW)
#else
		else if (bArg == 21 && idx == 2 && ch->GetComboSequence() == 5 && ch->GetJob() == JOB_WOLFMAN && ch->GetWear(WEAR_WEAPON) && ch->GetWear(WEAR_WEAPON)->GetSubType() == WEAPON_CLAW)
#endif

// Search for:
int CInputMain::Analyze(LPDESC d, BYTE bHeader, const char * c_pData)

// Add before:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
void CInputMain::ChangeEquip(LPCHARACTER ch, const char* c_pData)
{
	const TChangeEquipment* p = reinterpret_cast<const TChangeEquipment*>(c_pData);
	ch->ChangeEquip(p->index);
}
#endif

// Search for:
		case HEADER_CG_CLIENT_VERSION:

// Add before:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
		case HEADER_CG_CHANGE_EQUIP:
			ChangeEquip(ch, c_pData);
			break;
#endif