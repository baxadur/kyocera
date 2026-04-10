class KTQuestManager {
    private ref array<ref KTQuestBase> m_Quests;

    void KTQuestManager() {
        m_Quests = new array<ref KTQuestBase>;
        KTQuestConfig.Init();
    }

    void AddQuest(string type) {
        if (!KTQuestConfig.Quests.Contains(type)) return;
        m_Quests.Insert(new KTQuestBase(type));
    }

    array<ref KTQuestBase> GetActiveQuests() {
        return m_Quests;
    }

    void CompleteQuest(KTQuestBase quest) {
        if (quest && !quest.Rewarded) {
            PlayerBase player = GetGame().GetPlayer();
            if (!player) return;

            foreach (string itemClass: quest.GetRewardItems()) {
                player.GetInventory().CreateInInventory(itemClass);
            }

            quest.Rewarded = true;
        }
    }
};