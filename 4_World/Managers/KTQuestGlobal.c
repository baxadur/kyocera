ref KTQuestManager g_KTQuestManager;

KTQuestManager GetKTQuestManager() {
    if (!g_KTQuestManager) {
        g_KTQuestManager = new KTQuestManager();
    }
    return g_KTQuestManager;
}

void KTQuestSystem_OnConnect(PlayerBase player) {
    KTQuestSaveData.Load(player);
}

void KTQuestSystem_OnDisconnect(PlayerBase player) {
    KTQuestSaveData.Save(player);
}