
class CfgMods {
	class KVC {
		dir = "KVC";
		hideName = 0;
		hidePicture = 0;
		name = "Quest system";
		credits = "SRT";
		author = "SRT";
		authorID = "";
		inputs = "KVC/Assets/Input/modded_Inputs.xml";
		version = "version 1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game", "World", "Mission"};
		
		class defs {
			class gameScriptModule {
				value = "";
				files[] = {"KVC/3_Game"};
			};
			
			class worldScriptModule {
				value = "";
				files[] = {"KVC/4_World"};
			};
			
			class missionScriptModule {
				value = "";
				files[] = {"KVC/5_Mission"};
			};
		};
	};
};
