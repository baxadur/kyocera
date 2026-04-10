@echo off
echo [KVS] Собираем PBO...
"C:\Program Files (x86)\DayZ Tools\battleye\bes.exe" -pack="KVS_QuestSystem\4_World" -output="."
ren "4_World.pbo" "KVS_QuestSystem.pbo"
echo [OK] Готово: KVS_QuestSystem.pbo
pause