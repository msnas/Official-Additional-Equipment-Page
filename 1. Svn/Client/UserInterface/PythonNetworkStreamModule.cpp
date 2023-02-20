// Search for:
void initnet()

// Add before:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
PyObject* netChangeEquipment(PyObject* poSelf, PyObject* poArgs)
{
	int index;
	if (!PyTuple_GetInteger(poArgs, 0, &index))
		return Py_BuildException();

	CPythonNetworkStream& rkNetStream = CPythonNetworkStream::Instance();
	rkNetStream.ChangeEquipment(index);
	return Py_BuildNone();
}
#endif

// Search for:
		{ NULL,										NULL,										NULL },

// Add before:
#ifdef ENABLE_ADDITIONAL_EQUIPMENT_PAGE
		{ "ChangeEquipment",						netChangeEquipment,							METH_VARARGS },
#endif