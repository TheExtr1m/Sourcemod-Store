#if defined _store_stocks_included
  #endinput
#endif
#define _store_stocks_included

/*
	Custom stocks that the store modules use, feel free to use these yourself.
*/

//Allows for faster queries while keeping the treading bits. (no callback)
stock void SQL_TFastQuery(Handle database, const char[] query, DBPriority prio = DBPrio_Normal)
{
	SQL_TQuery(database, VoidCallback, query, _, prio);
}

//Callback for the threaded query with no callback required.
public void VoidCallback(Handle owner, Handle hndl, const char[] error, any data)
{
	if (hndl == null)
	{
		LogError("Error on SQL callback: %s", error);
	}
}

//KvGetBool	- Ease of life stock.
stock bool KvGetBool(Handle hKV, const char[] sKey, bool bDefaultValue = false)
{
	return view_as<bool>(KvGetNum(hKV, sKey, view_as<int>(bDefaultValue)));
}

//SQL_FetchBool - Why is this not in the API? I know SQL_FetchInt is a thing but... cmon.
stock bool SQL_FetchBool(Handle query, int field, DBResult &result = DBVal_Error)
{
	return view_as<bool>(SQL_FetchInt(query, field, result));
}