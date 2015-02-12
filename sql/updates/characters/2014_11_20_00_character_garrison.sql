/*
Navicat MySQL Data Transfer

Source Server         : Skyfire6xx
Source Server Version : 50540
Source Host           : localhost:3306
Source Database       : characters

Target Server Type    : MYSQL
Target Server Version : 50540
File Encoding         : 65001

Date: 2014-11-06 04:59:37
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for character_garrison
-- ----------------------------
DROP TABLE IF EXISTS `character_garrison`;
CREATE TABLE `character_garrison` (
  `id` bigint(20) unsigned NOT NULL DEFAULT '0',
  `accountId` int(10) unsigned NOT NULL DEFAULT '0',
  `garrisonId` int(10) unsigned NOT NULL DEFAULT '0',
  `garrisonLevel` smallint(5) NOT NULL DEFAULT '1',
  `currentResources` int(10) unsigned NOT NULL DEFAULT '0',
  `specialization` smallint(5) unsigned NOT NULL DEFAULT '0',
  `buildings` int(10) unsigned NOT NULL DEFAULT '0',
  `followers` int(10) unsigned NOT NULL DEFAULT '0',
  `workOrders` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of character_garrison
-- ----------------------------

-- ----------------------------
-- Table structure for character_garrison_buildings
-- ----------------------------
DROP TABLE IF EXISTS `character_garrison_buildings`;
CREATE TABLE `character_garrison_buildings` (
  `garrisonId` bigint(20) unsigned NOT NULL DEFAULT '0',
  `garrisonLevel` bigint(20) unsigned NOT NULL DEFAULT '0',
  `plotId` bigint(20) unsigned NOT NULL DEFAULT '0',
  `plotSize` bigint(20) unsigned NOT NULL DEFAULT '0',
  `building` bigint(20) unsigned NOT NULL DEFAULT '0',
  `buildingLevel` bigint(20) unsigned NOT NULL DEFAULT '0',
  `buildingSize` bigint(20) unsigned NOT NULL DEFAULT '0',
  `buildingSpec` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`garrisonId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of character_garrison_buildings
-- ----------------------------

-- ----------------------------
-- Table structure for character_garrison_followers
-- ----------------------------
DROP TABLE IF EXISTS `character_garrison_followers`;
CREATE TABLE `character_garrison_followers` (
  `garrisonId` bigint(20) unsigned NOT NULL DEFAULT '0',
  `followerSlot1` bigint(20) unsigned NOT NULL DEFAULT '0',
  `followerSlot2` bigint(20) unsigned NOT NULL DEFAULT '0',
  `followerSlot3` bigint(20) unsigned NOT NULL DEFAULT '0',
  `followerSlot4` bigint(20) unsigned NOT NULL DEFAULT '0',
  `followerSlot5` bigint(20) unsigned NOT NULL DEFAULT '0',
  `slot1Level` bigint(20) unsigned NOT NULL DEFAULT '0',
  `slot2Level` bigint(20) unsigned NOT NULL DEFAULT '0',
  `slot3Level` bigint(20) unsigned NOT NULL DEFAULT '0',
  `slot4Level` bigint(20) unsigned NOT NULL DEFAULT '0',
  `slot5Level` bigint(20) unsigned NOT NULL DEFAULT '0',
  `slot1ExpToLevel` bigint(20) unsigned NOT NULL DEFAULT '0',
  `slot2ExpToLevel` bigint(20) unsigned NOT NULL DEFAULT '0',
  `slot3ExpToLevel` bigint(20) unsigned NOT NULL DEFAULT '0',
  `slot4ExpToLevel` bigint(20) unsigned NOT NULL DEFAULT '0',
  `slot5ExpToLevel` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`garrisonId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of character_garrison_followers
-- ----------------------------

-- ----------------------------
-- Table structure for character_garrison_followers_spec
-- ----------------------------
DROP TABLE IF EXISTS `character_garrison_followers_spec`;
CREATE TABLE `character_garrison_followers_spec` (
  `garrisonId` bigint(20) unsigned NOT NULL DEFAULT '0',
  `followerSlot1` bigint(20) unsigned NOT NULL DEFAULT '0',
  `followerSlot2` bigint(20) unsigned NOT NULL DEFAULT '0',
  `followerSlot3` bigint(20) unsigned NOT NULL DEFAULT '0',
  `followerSlot4` bigint(20) unsigned NOT NULL DEFAULT '0',
  `followerSlot5` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`garrisonId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of character_garrison_followers_spec
-- ----------------------------

-- ----------------------------
-- Table structure for character_garrison_mission
-- ----------------------------
DROP TABLE IF EXISTS `character_garrison_mission`;
CREATE TABLE `character_garrison_mission` (
  `garrisonId` bigint(20) unsigned NOT NULL DEFAULT '0',
  `missionId` bigint(20) unsigned NOT NULL DEFAULT '0',
  `missionLevel` bigint(20) unsigned NOT NULL DEFAULT '0',
  `missionType` bigint(20) unsigned NOT NULL DEFAULT '0',
  `missionTimeLeft` bigint(20) unsigned NOT NULL DEFAULT '0',
  `missionFollowers` bigint(20) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`garrisonId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- ----------------------------
-- Records of character_garrison_mission
-- ----------------------------
