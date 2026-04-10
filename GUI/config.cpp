class CfgPatches {
    class KVS_QuestSystem {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data"};
        version = "1.0";
        fileName = "KVS_QuestSystem.pbo";
    };
};

class CfgMods {
    class KVS_QuestSystem {
        dir = "KVS_QuestSystem";
        name = "KVS - Quest System";
        picture = "picture.paa";
        action = "";
        hideName = false;
        hidePicture = false;
        author = "YourName";
        tooltip = "Система квестов с UI и сохранением";
    };
};