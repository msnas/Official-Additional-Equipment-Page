// Search for:
void initwndMgr()

// Add before:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
PyObject* wndMgrSetSlotChange(PyObject* poSelf, PyObject* poArgs)
{
	UI::CWindow* pWin;
	if (!PyTuple_GetWindow(poArgs, 0, &pWin))
		return Py_BuildException();

	int oldIndex;
	if (!PyTuple_GetInteger(poArgs, 1, &oldIndex))
		return Py_BuildException();

	int newIndex;
	if (!PyTuple_GetInteger(poArgs, 2, &newIndex))
		return Py_BuildException();

	if (!pWin->IsType(UI::CSlotWindow::Type()))
		return Py_BuildException();

	UI::CSlotWindow* pSlotWin = (UI::CSlotWindow*)pWin;
	pSlotWin->SetSlotChange(oldIndex, newIndex);
	return Py_BuildNone();
}
#endif

// Search for:
		{ "ShowOverInWindowName",		wndMgrShowOverInWindowName,			METH_VARARGS },

// Add after:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
		{ "SetSlotChange",				wndMgrSetSlotChange,				METH_VARARGS },
#endif
