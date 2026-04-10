modded class InputManager {
    override bool OnKeyPress(int key) {
        if (key == KeyCode.KC_J) {
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
            if (player && GetUIManager().GetMenuInstance(KTQuestMenu)) {
                return false;
            }

            if (player) {
                GetUIManager().EnterScriptedMenu(MENU_KT_QUEST, null);
                return true;
            }
        }
        return super.OnKeyPress(key);
    }
}