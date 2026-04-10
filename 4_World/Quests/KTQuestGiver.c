class KTQuestGiver extends ZombieMaleBase {
    private ref array<string> m_AvailableQuests = {"KillBandits", "DeliverMedkits"};

    override void EEInit() {
        super.EEInit();
        SetAllowDamage(false);
    }

    override void OnClick(PlayerBase player, float distance) {
        if (distance > 3.0) return;
        DisplayQuestMenu(player);
    }

    void DisplayQuestMenu(PlayerBase player) {
        foreach (string questType: m_AvailableQuests) {
            if (KTQuestConfig.Quests.Contains(questType)) {
                string name = KTQuestConfig.Quests.Get(questType).Name;
                GetGame().ChatPlayer("Квест: " + name);

                if (!HasActiveQuest(player, questType)) {
                    AddQuestToPlayer(player, questType);
                    GetNotificationSystem().CreateNotification(new StringLocaliser("Квест получен"), new StringLocaliser(name), EXPANSION_NOTIFICATION_ICON_GOAL, COLOR_EXPANSION_MAIN_1, 5);
                    SEffectManager.PlaySoundOnObject("KTQuest_QuestReceived_SoundSet", this);
                }
            }
        }
    }

    bool HasActiveQuest(PlayerBase player, string type) {
        KTQuestManager manager = GetKTQuestManager();
        foreach (KTQuestBase quest: manager.GetActiveQuests()) {
            if (quest.Type == type && !quest.Completed) return true;
        }
        return false;
    }

    void AddQuestToPlayer(PlayerBase player, string type) {
        GetKTQuestManager().AddQuest(type);
        GetGame().ChatPlayer("Квест добавлен: " + KTQuestConfig.Quests.Get(type).Name);
    }
};