-- Fixes
UPDATE creature_template SET npcflag=16384, type_flags=2, type_flags2=0 WHERE entry IN (65183, 39660, 29259, 6491); 
UPDATE creature_template SET npcflag=32769, type_flags=2, type_flags2=0 WHERE entry IN (32004, 31920, 22558, 22526, 13117, 13116, 45078, 72676, 45076, 45075, 45074, 45073, 45068, 45067, 45066, 31842, 31841); 
UPDATE creature_template SET minlevel=90, maxlevel=90, exp=4, faction=35 WHERE entry=72676; 





