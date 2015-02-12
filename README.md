Revision:  Fixed build        116f5677c8efdb4dc3641da979943fcf199b0557


## Boost Path :
C:\boost\libs;C:\boost\lib32-msvc-12.0;C:\boost\boost;C:\boost;%(AdditionalLibraryDirectories)


## Requirements
+ Platform: Linux, Windows or Mac
+ Processor with SSE2 support
+ Boost ≥ 1.49
+ MySQL ≥ 5.1.0
+ CMake ≥ 2.8.11.2 / 2.8.9 (Windows / Linux)
+ OpenSSL ≥ 1.0.0
+ GCC ≥ 4.7.2 (Linux only)
+ MS Visual Studio ≥ 12 (2013 Update 3) (Windows only)

## Install
Detailed installation guides are available in the [wiki](http://collab.kpsn.org/display/tc/Installation+Guide) for
Windows, Linux and Mac OSX.


## Links
[Site](http://www.trinitycore.org)
[Wiki](http://trinitycore.info)
[Documentation](http://www.trinitycore.net) (powered by Doxygen)
[Forums](http://www.trinitycore.org/f/)
[TrinityCore.org](http://www.trinitycore.org).
[Repository](https://github.com/TrinityCore/TrinityCore)

#####################################################################################

.go 1168 -4405 22 1136		Siege Of Orgrimmar (@Outside Gates) (Zone 6738)
go 1440 751 246 1136		Siege Of Orgrimmar (@Outside) (Zone 6738)
.go 767 1015 357 1136		Siege Of Orgrimmar (@Norushen) (Zone 6738)
.go 748 1113 357 1136		Siege Of Orgrimmar (@ShaOfPride) (Zone 6738)
.go 1049 -5637 -317 1136	Siege Of Orgrimmar (@Garrosh) (Zone 6738)

### OgRaid Doors & Levers : #################################
.gobject add 126088     ograid lever 4  2.0
.gobject add 230848     ograid LARGEDOOR01
.gobject add 230849     ograid SMALL_DOOR_01
.gobject add 231933     ograid TREXDOOR01
.gobject add 231932     ograid CAGEDOOR01

UPDATE creature SET spawnMask=16384 WHERE map=1136; -- (diff 14 Raid)
UPDATE gameobject SET spawnMask=16384 WHERE map=1136; -- (diff 14 Raid)

#####################################################################################

.gobject add 126091     lever

.gobject add 225945     WoodGate1
.gobject add 225944     WoodGate2
.gobject add 233920     stone door
.gobject add 227851     blue flame wall
.gobject add 233921     big stone door
.gobject add 231938     big wood door
.gobject add 236211     blue flame wall 2
.gobject add 236212     blue flame wall 3
.gobject add 236213     yellow flame wall 1
.gobject add 236214     yellow flame wall 2
.gobject add 236033     purple flame wall 1

#####################################################################################
