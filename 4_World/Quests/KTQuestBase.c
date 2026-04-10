class KTQuestBase {
    string Type;
    int Progress;
    bool Completed;
    bool Rewarded;

    void KTQuestBase(string type) {
        Type = type;
        Progress = 0;
        Completed = false;
        Rewarded = false;
    }

    void UpdateProgress(int amount = 1) {
        if (Completed) return;
        Progress += amount;
        if (Progress >= GetMaxProgress()) {
            Completed = true;
        }
    }

    int GetMaxProgress() {
        if (KTQuestConfig.Quests.Contains(Type)) {
            return KTQuestConfig.Quests.Get(Type).MaxProgress;
        }
        return 1;
    }

    string GetName() { return KTQuestConfig.Quests.Get(Type).Name; }
    string GetDescription() { return KTQuestConfig.Quests.Get(Type).Description; }
    int GetRewardMoney() { return KTQuestConfig.Quests.Get(Type).RewardMoney; }
    array<string> GetRewardItems() { return KTQuestConfig.Quests.Get(Type).RewardItems; }
};