UPDATE `creature_template` SET `npcflag`=32769 WHERE `entry`=37236;
UPDATE `creature_template` SET `npcflag`=32769 WHERE `entry`=37323;


UPDATE creature_template set ScriptName = '' where entry = 58632;
UPDATE creature_template set ScriptName = '' where entry = 59150;
UPDATE creature_template set ScriptName = '' where entry = 59303;
UPDATE creature_template set ScriptName = '' where entry = 59223;
UPDATE creature_template set ScriptName = '' where entry = 3977;
UPDATE creature_template set ScriptName = '' where entry = 59789;
UPDATE creature_template set ScriptName = '' where entry = 59080;
UPDATE creature_template set ScriptName = '' where entry = 58633;
UPDATE creature_template set ScriptName = '' where entry = 59184;
UPDATE creature_template set ScriptName = '' where entry = 58722;
UPDATE creature_template set ScriptName = '' where entry = 59153;

DELETE FROM smart_scripts WHERE entryorguid=37826 AND id=1;
DELETE FROM smart_scripts WHERE entryorguid=25335 AND id=7;
DELETE FROM smart_scripts WHERE entryorguid=25335 AND id=10;
