class KTQuestMenu extends UIScriptedMenu {
    private ref Widget m_Root;
    private ref TextWidget m_Title;
    private ref ScrollWidget m_QuestListArea;
    private ref WrapSpacerWidget m_QuestItems;

    private ref array<ref KTQuestBase> m_Quests;

    override Widget Init() {
        m_Root = GetLayoutRoot();
        m_Title = TextWidget.Cast(m_Root.FindAnyWidget("Title"));
        m_QuestListArea = ScrollWidget.Cast(m_Root.FindAnyWidget("QuestScroll"));
        m_QuestItems = WrapSpacerWidget.Cast(m_Root.FindAnyWidget("QuestItems"));

        m_Title.SetText("Ваши квесты");

        RefreshQuests();

        return m_Root;
    }

    void RefreshQuests() {
        ClearList();

        PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
        if (!player) return;

        KTQuestManager manager = GetKTQuestManager();
        if (!manager) return;

        m_Quests = manager.GetActiveQuests();

        foreach (KTQuestBase quest: m_Quests) {
            AddQuestItem(quest);
        }
    }

    void AddQuestItem(KTQuestBase quest) {
        Widget item = GetGame().GetWorkspace().CreateWidgets("$CurrentDir:\\KVS_QuestSystem\\GUI\\layouts\\QuestItem.layout", m_QuestItems);

        TextWidget name = TextWidget.Cast(item.FindAnyWidget("QuestName"));
        TextWidget desc = TextWidget.Cast(item.FindAnyWidget("QuestDesc"));
        TextWidget prog = TextWidget.Cast(item.FindAnyWidget("QuestProgress"));

        name.SetText(quest.GetName());
        desc.SetText(quest.GetDescription());
        prog.SetText(string.Format("Прогресс: %1 / %2", quest.Progress, quest.GetMaxProgress()));

        ButtonWidget completeBtn = ButtonWidget.Cast(item.FindAnyWidget("CompleteBtn"));
        completeBtn.SetUserData(quest);
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        if (button == MouseState.LEFT) {
            if (w && w.GetUserData()) {
                KTQuestBase quest = KTQuestBase.Cast(w.GetUserData());
                if (quest && quest.Completed && !quest.Rewarded) {
                    GetKTQuestManager().CompleteQuest(quest);
                    GetGame().ChatPlayer("Вы получили награду!");
                    SEffectManager.PlaySoundOnObject("KTQuest_RewardReceived_SoundSet", GetGame().GetPlayer());
                    RefreshQuests();
                }
            }
        }
        return super.OnClick(w, x, y, button);
    }

    void ClearList() {
        if (m_QuestItems) {
            m_QuestItems.RemoveAllChildren();
        }
    }
};