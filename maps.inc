/**
 * Function stock to deal with maps and map names.
 */

#if defined __stocksoup_maps_included
	#endinput
#endif

#define __stocksoup_maps_included

/** 
 * Returns the workshop ID for the specified full map path, or 0 if the map does not have a
 * workshop ID.
 */
int GetMapWorkshopID(const char[] fullMapName) {
	EngineVersion currentGame = GetEngineVersion();
	if (StrContains(fullMapName, "workshop/") == 0) {
		if (currentGame == Engine_TF2) {
			if (StrContains(fullMapName, ".ugc") > -1 ) {
				// workshop/some_map_name.ugc123456789
				return StringToInt( fullMapName[ StrContains(fullMapName, ".ugc") + 4 ] );
			} else {
				// workshop/123456789
				return StringToInt( fullMapName[ StrContains(fullMapName, "/") + 1 ] );
			}
		}
		// TODO other formats for workshop map names
		if (currentGame == Engine_CSGO) {
			// workshop/123456789/some_map_name ?
			char mapParts[3][32];
			ExplodeString(fullMapName, "/", mapParts, sizeof(mapParts), sizeof(mapParts[]));
			return StringToInt(mapParts[1]);
		}
	}
	return 0;
}