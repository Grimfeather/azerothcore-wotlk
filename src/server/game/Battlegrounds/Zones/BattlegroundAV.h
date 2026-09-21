/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __BATTLEGROUNDAV_H
#define __BATTLEGROUNDAV_H

#include "Battleground.h"
#include "BattlegroundScore.h"
#include "WorldStateDefines.h"

#define BG_AV_CAPTIME                   240000  // 4:00
#define BG_AV_SNOWFALL_FIRSTCAP         300000  // 5:00 but i also have seen 4:05

#define BG_AV_SCORE_INITIAL_POINTS      (sWorld->getIntConfig(CONFIG_BATTLEGROUND_ALTERAC_REINFORCEMENTS)) // Blizzlike default is 600
#define SEND_MSG_NEAR_LOSE              120

#define BG_AV_KILL_BOSS                 4

#define BG_AV_KILL_CAPTAIN              3
#define BG_AV_RES_CAPTAIN               100

#define BG_AV_KILL_TOWER                3
#define BG_AV_RES_TOWER                 75

#define BG_AV_GET_COMMANDER             1 // for a safely returned wingcommander
//bonushonor at the end
#define BG_AV_KILL_SURVIVING_TOWER      2

#define BG_AV_KILL_SURVIVING_CAPTAIN    2

#define AV_EVENT_START_BATTLE           9166 // Achievement: The Alterac Blitz

enum BG_AV_BroadcastTexts
{
    BG_AV_TEXT_START_ONE_MINUTE     = 10638,
    BG_AV_TEXT_START_HALF_MINUTE    = 10639,
    BG_AV_TEXT_BATTLE_HAS_BEGUN     = 10640,

    BG_AV_TEXT_ALLIANCE_NEAR_LOSE   = 23210,
    BG_AV_TEXT_HORDE_NEAR_LOSE      = 23211
};


enum BG_AV_Sounds
{
    //TODO: get out if there comes a sound when neutral team captures mine

    /*
    8212:
        alliance grave assault
        alliance tower assault
        drek "mlanzenabschaum! In meiner Burg?! Toetet sie all" - nicht immer der sound
    8333:
        galv "sterbt fuer euch ist kein platz hier"

    8332:
        bal "Verschwinde, dreckiger Abschaum! Die Allianz wird im Alteractal "
    8174:
        horde tower assault
        horde grave assault
        van "es Sturmlanzenklans, euer General wird angegriffen! Ich fordere Unterst"
    8173:
        ally grave capture/defend
        tower destroy
        mine capture
        ally wins
    8192:
        ally tower destroy(only iceblood - found a bug^^)
        ally tower  defend
        horde tower defend
    8213
    horde:
        grave defend/capture
        tower destroy
        mine capture
        horde wins
        */

    AV_SOUND_NEAR_VICTORY                   = 8456, //not confirmed yet

    AV_SOUND_ALLIANCE_ASSAULTS              = 8212, //tower, grave + enemy boss if someone tries to attack him
    AV_SOUND_HORDE_ASSAULTS                 = 8174,
    AV_SOUND_ALLIANCE_GOOD                  = 8173, //if something good happens for the team:  wins(maybe only through killing the boss), captures mine or grave, destroys tower and defends grave
    AV_SOUND_HORDE_GOOD                     = 8213,
    AV_SOUND_BOTH_TOWER_DEFEND              = 8192,

    AV_SOUND_ALLIANCE_CAPTAIN               = 8232, //gets called when someone attacks them and at the beginning after 3min+rand(x)*10sec (maybe buff)
    AV_SOUND_HORDE_CAPTAIN                  = 8333
};

enum BG_AV_OTHER_VALUES
{
    AV_STATICCPLACE_MAX          = 157,
    AV_NORTH_MINE                = 0,
    AV_SOUTH_MINE                = 1,
    AV_MINE_TICK_TIMER           = 45000,
    AV_MINE_RECLAIM_TIMER        = 1200000, // TODO: get the right value.. this is currently 20 minutes
    BG_AV_QUEST_CREDIT_MINE      = 13796,
    BG_AV_QUEST_CREDIT_TOWER     = 13778,
    BG_AV_QUEST_CREDIT_GRAVEYARD = 13756
};

enum BG_AV_ObjectIds
{
    //cause the moongose-system is a bit different, we don't use the right go-ids for every node.. if we want to be 100% like another big server, we must take one object for every node
    //snowfall 4flags as eyecandy 179424 (alliance neutral)
    //Banners - stolen from battleground_AB.h ;-)
    BG_AV_OBJECTID_BANNER_A             = 178925, // can only be used by horde
    BG_AV_OBJECTID_BANNER_H             = 178943, // can only be used by alliance
    BG_AV_OBJECTID_BANNER_CONT_A        = 178940, // can only be used by horde
    BG_AV_OBJECTID_BANNER_CONT_H        = 179435, // can only be used by alliance

    BG_AV_OBJECTID_BANNER_A_B           = 178365,
    BG_AV_OBJECTID_BANNER_H_B           = 178364,
    BG_AV_OBJECTID_BANNER_CONT_A_B      = 179286,
    BG_AV_OBJECTID_BANNER_CONT_H_B      = 179287,
    BG_AV_OBJECTID_BANNER_SNOWFALL_N    = 180418,

    //snowfall eyecandy banner:
    BG_AV_OBJECTID_SNOWFALL_CANDY_A     = 179044,
    BG_AV_OBJECTID_SNOWFALL_CANDY_PA    = 179424,
    BG_AV_OBJECTID_SNOWFALL_CANDY_H     = 179064,
    BG_AV_OBJECTID_SNOWFALL_CANDY_PH    = 179425,

    //banners on top of towers:
    BG_AV_OBJECTID_TOWER_BANNER_A       = 178927, //[PH] Alliance A1 Tower Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_H       = 178955, //[PH] Horde H1 Tower Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_PA      = 179446, //[PH] Alliance H1 Tower Pre-Banner BIG
    BG_AV_OBJECTID_TOWER_BANNER_PH      = 179436, //[PH] Horde A1 Tower Pre-Banner BIG

    //Auras
    BG_AV_OBJECTID_AURA_A               = 180421,
    BG_AV_OBJECTID_AURA_H               = 180422,
    BG_AV_OBJECTID_AURA_N               = 180423,
    BG_AV_OBJECTID_AURA_A_S             = 180100,
    BG_AV_OBJECTID_AURA_H_S             = 180101,
    BG_AV_OBJECTID_AURA_N_S             = 180102,

    BG_AV_OBJECTID_GATE_A               = 180424,
    BG_AV_OBJECTID_GATE_H               = 180424,

    //mine supplies
    BG_AV_OBJECTID_MINE_N               = 178785,
    BG_AV_OBJECTID_MINE_S               = 178784,

    BG_AV_OBJECTID_FIRE                 = 179065,
    BG_AV_OBJECTID_SMOKE                = 179066,

    // Winter Veil Hardpacked Snowdrift
    BG_AV_OBJECTID_HARDPACKED_SNOWDRIFT = 180654,

    BG_AV_OBJECTID_FROSTWOLF_BANNER     = 179025,
    BG_AV_OBJECTID_STORMPIKE_BANNER     = 179024,
};

enum BG_AV_Nodes
{
    BG_AV_NODES_FIRSTAID_STATION        = 0,
    BG_AV_NODES_STORMPIKE_GRAVE         = 1,
    BG_AV_NODES_STONEHEART_GRAVE        = 2,
    BG_AV_NODES_SNOWFALL_GRAVE          = 3,
    BG_AV_NODES_ICEBLOOD_GRAVE          = 4,
    BG_AV_NODES_FROSTWOLF_GRAVE         = 5,
    BG_AV_NODES_FROSTWOLF_HUT           = 6,
    BG_AV_NODES_DUNBALDAR_SOUTH         = 7,
    BG_AV_NODES_DUNBALDAR_NORTH         = 8,
    BG_AV_NODES_ICEWING_BUNKER          = 9,
    BG_AV_NODES_STONEHEART_BUNKER       = 10,
    BG_AV_NODES_ICEBLOOD_TOWER          = 11,
    BG_AV_NODES_TOWER_POINT             = 12,
    BG_AV_NODES_FROSTWOLF_ETOWER        = 13,
    BG_AV_NODES_FROSTWOLF_WTOWER        = 14,

    BG_AV_NODES_MAX                     = 15
};

enum BG_AV_ObjectTypes
{
    BG_AV_OBJECT_FLAG_A_FIRSTAID_STATION    = 0,
    BG_AV_OBJECT_FLAG_A_STORMPIKE_GRAVE     = 1,
    BG_AV_OBJECT_FLAG_A_STONEHEART_GRAVE    = 2,
    BG_AV_OBJECT_FLAG_A_SNOWFALL_GRAVE      = 3,
    BG_AV_OBJECT_FLAG_A_ICEBLOOD_GRAVE      = 4,
    BG_AV_OBJECT_FLAG_A_FROSTWOLF_GRAVE     = 5,
    BG_AV_OBJECT_FLAG_A_FROSTWOLF_HUT       = 6,
    BG_AV_OBJECT_FLAG_A_DUNBALDAR_SOUTH     = 7,
    BG_AV_OBJECT_FLAG_A_DUNBALDAR_NORTH     = 8,
    BG_AV_OBJECT_FLAG_A_ICEWING_BUNKER      = 9,
    BG_AV_OBJECT_FLAG_A_STONEHEART_BUNKER   = 10,

    BG_AV_OBJECT_FLAG_C_A_FIRSTAID_STATION  = 11,
    BG_AV_OBJECT_FLAG_C_A_STORMPIKE_GRAVE   = 12,
    BG_AV_OBJECT_FLAG_C_A_STONEHEART_GRAVE  = 13,
    BG_AV_OBJECT_FLAG_C_A_SNOWFALL_GRAVE    = 14,
    BG_AV_OBJECT_FLAG_C_A_ICEBLOOD_GRAVE    = 15,
    BG_AV_OBJECT_FLAG_C_A_FROSTWOLF_GRAVE   = 16,
    BG_AV_OBJECT_FLAG_C_A_FROSTWOLF_HUT     = 17,
    BG_AV_OBJECT_FLAG_C_A_ICEBLOOD_TOWER    = 18,
    BG_AV_OBJECT_FLAG_C_A_TOWER_POINT       = 19,
    BG_AV_OBJECT_FLAG_C_A_FROSTWOLF_ETOWER  = 20,
    BG_AV_OBJECT_FLAG_C_A_FROSTWOLF_WTOWER  = 21,

    BG_AV_OBJECT_FLAG_C_H_FIRSTAID_STATION  = 22,
    BG_AV_OBJECT_FLAG_C_H_STORMPIKE_GRAVE   = 23,
    BG_AV_OBJECT_FLAG_C_H_STONEHEART_GRAVE  = 24,
    BG_AV_OBJECT_FLAG_C_H_SNOWFALL_GRAVE    = 25,
    BG_AV_OBJECT_FLAG_C_H_ICEBLOOD_GRAVE    = 26,
    BG_AV_OBJECT_FLAG_C_H_FROSTWOLF_GRAVE   = 27,
    BG_AV_OBJECT_FLAG_C_H_FROSTWOLF_HUT     = 28,
    BG_AV_OBJECT_FLAG_C_H_DUNBALDAR_SOUTH   = 29,
    BG_AV_OBJECT_FLAG_C_H_DUNBALDAR_NORTH   = 30,
    BG_AV_OBJECT_FLAG_C_H_ICEWING_BUNKER    = 31,
    BG_AV_OBJECT_FLAG_C_H_STONEHEART_BUNKER = 32,

    BG_AV_OBJECT_FLAG_H_FIRSTAID_STATION    = 33,
    BG_AV_OBJECT_FLAG_H_STORMPIKE_GRAVE     = 34,
    BG_AV_OBJECT_FLAG_H_STONEHEART_GRAVE    = 35,
    BG_AV_OBJECT_FLAG_H_SNOWFALL_GRAVE      = 36,
    BG_AV_OBJECT_FLAG_H_ICEBLOOD_GRAVE      = 37,
    BG_AV_OBJECT_FLAG_H_FROSTWOLF_GRAVE     = 38,
    BG_AV_OBJECT_FLAG_H_FROSTWOLF_HUT       = 39,
    BG_AV_OBJECT_FLAG_H_ICEBLOOD_TOWER      = 40,
    BG_AV_OBJECT_FLAG_H_TOWER_POINT         = 41,
    BG_AV_OBJECT_FLAG_H_FROSTWOLF_ETOWER    = 42,
    BG_AV_OBJECT_FLAG_H_FROSTWOLF_WTOWER    = 43,

    BG_AV_OBJECT_FLAG_N_SNOWFALL_GRAVE      = 44,

    BG_AV_OBJECT_DOOR_H                     = 45,
    BG_AV_OBJECT_DOOR_A                     = 46,

    //auras for graveyards (3auras per graveyard neutral, alliance, horde)
    BG_AV_OBJECT_AURA_N_FIRSTAID_STATION    = 47,
    BG_AV_OBJECT_AURA_A_FIRSTAID_STATION    = 48,
    BG_AV_OBJECT_AURA_H_FIRSTAID_STATION    = 49,
    BG_AV_OBJECT_AURA_N_STORMPIKE_GRAVE     = 50,
    BG_AV_OBJECT_AURA_A_STORMPIKE_GRAVE     = 51,
    BG_AV_OBJECT_AURA_H_STORMPIKE_GRAVE     = 52,
    BG_AV_OBJECT_AURA_N_STONEHEART_GRAVE    = 53,
    BG_AV_OBJECT_AURA_A_STONEHEART_GRAVE    = 54,
    BG_AV_OBJECT_AURA_H_STONEHEART_GRAVE    = 55,
    BG_AV_OBJECT_AURA_N_SNOWFALL_GRAVE      = 56,
    BG_AV_OBJECT_AURA_A_SNOWFALL_GRAVE      = 57,
    BG_AV_OBJECT_AURA_H_SNOWFALL_GRAVE      = 58,
    BG_AV_OBJECT_AURA_N_ICEBLOOD_GRAVE      = 59,
    BG_AV_OBJECT_AURA_A_ICEBLOOD_GRAVE      = 60,
    BG_AV_OBJECT_AURA_H_ICEBLOOD_GRAVE      = 61,
    BG_AV_OBJECT_AURA_N_FROSTWOLF_GRAVE     = 62,
    BG_AV_OBJECT_AURA_A_FROSTWOLF_GRAVE     = 63,
    BG_AV_OBJECT_AURA_H_FROSTWOLF_GRAVE     = 64,
    BG_AV_OBJECT_AURA_N_FROSTWOLF_HUT       = 65,
    BG_AV_OBJECT_AURA_A_FROSTWOLF_HUT       = 66,
    BG_AV_OBJECT_AURA_H_FROSTWOLF_HUT       = 67,

    //big flags on top of towers 2 flags on each (contested, (alliance | horde)) + 2 auras
    BG_AV_OBJECT_TFLAG_A_DUNBALDAR_SOUTH    = 67,
    BG_AV_OBJECT_TFLAG_H_DUNBALDAR_SOUTH    = 68,
    BG_AV_OBJECT_TFLAG_A_DUNBALDAR_NORTH    = 69,
    BG_AV_OBJECT_TFLAG_H_DUNBALDAR_NORTH    = 70,
    BG_AV_OBJECT_TFLAG_A_ICEWING_BUNKER     = 71,
    BG_AV_OBJECT_TFLAG_H_ICEWING_BUNKER     = 72,
    BG_AV_OBJECT_TFLAG_A_STONEHEART_BUNKER  = 73,
    BG_AV_OBJECT_TFLAG_H_STONEHEART_BUNKER  = 74,
    BG_AV_OBJECT_TFLAG_A_ICEBLOOD_TOWER     = 75,
    BG_AV_OBJECT_TFLAG_H_ICEBLOOD_TOWER     = 76,
    BG_AV_OBJECT_TFLAG_A_TOWER_POINT        = 77,
    BG_AV_OBJECT_TFLAG_H_TOWER_POINT        = 78,
    BG_AV_OBJECT_TFLAG_A_FROSTWOLF_ETOWER   = 79,
    BG_AV_OBJECT_TFLAG_H_FROSTWOLF_ETOWER   = 80,
    BG_AV_OBJECT_TFLAG_A_FROSTWOLF_WTOWER   = 81,
    BG_AV_OBJECT_TFLAG_H_FROSTWOLF_WTOWER   = 82,
    BG_AV_OBJECT_TAURA_A_DUNBALDAR_SOUTH    = 83,
    BG_AV_OBJECT_TAURA_H_DUNBALDAR_SOUTH    = 84,
    BG_AV_OBJECT_TAURA_A_DUNBALDAR_NORTH    = 85,
    BG_AV_OBJECT_TAURA_H_DUNBALDAR_NORTH    = 86,
    BG_AV_OBJECT_TAURA_A_ICEWING_BUNKER     = 87,
    BG_AV_OBJECT_TAURA_H_ICEWING_BUNKER     = 88,
    BG_AV_OBJECT_TAURA_A_STONEHEART_BUNKER  = 89,
    BG_AV_OBJECT_TAURA_H_STONEHEART_BUNKER  = 90,
    BG_AV_OBJECT_TAURA_A_ICEBLOOD_TOWER     = 91,
    BG_AV_OBJECT_TAURA_H_ICEBLOOD_TOWER     = 92,
    BG_AV_OBJECT_TAURA_A_TOWER_POINT        = 93,
    BG_AV_OBJECT_TAURA_H_TOWER_POINT        = 94,
    BG_AV_OBJECT_TAURA_A_FROSTWOLF_ETOWER   = 95,
    BG_AV_OBJECT_TAURA_H_FROSTWOLF_ETOWER   = 96,
    BG_AV_OBJECT_TAURA_A_FROSTWOLF_WTOWER   = 97,
    BG_AV_OBJECT_TAURA_H_FROSTWOLF_WTOWER   = 98,

    BG_AV_OBJECT_BURN_DUNBALDAR_SOUTH       = 99,
    BG_AV_OBJECT_BURN_DUNBALDAR_NORTH       = 109,
    BG_AV_OBJECT_BURN_ICEWING_BUNKER        = 119,
    BG_AV_OBJECT_BURN_STONEHEART_BUNKER     = 129,
    BG_AV_OBJECT_BURN_ICEBLOOD_TOWER        = 139,
    BG_AV_OBJECT_BURN_TOWER_POINT           = 149,
    BG_AV_OBJECT_BURN_FROSTWOLF_ETWOER      = 159,
    BG_AV_OBJECT_BURN_FROSTWOLF_WTOWER      = 169,
    BG_AV_OBJECT_BURN_BUILDING_ALLIANCE     = 179,
    BG_AV_OBJECT_BURN_BUILDING_HORDE        = 189,
    BG_AV_OBJECT_SNOW_EYECANDY_A            = 199,
    BG_AV_OBJECT_SNOW_EYECANDY_PA           = 203,
    BG_AV_OBJECT_SNOW_EYECANDY_H            = 207,
    BG_AV_OBJECT_SNOW_EYECANDY_PH           = 211,
    BG_AV_OBJECT_MINE_SUPPLY_N_MIN          = 215,
    BG_AV_OBJECT_MINE_SUPPLY_N_MAX          = 224,
    BG_AV_OBJECT_MINE_SUPPLY_S_MIN          = 225,
    BG_AV_OBJECT_MINE_SUPPLY_S_MAX          = 236,
    BG_AV_OBJECT_HANDPACKED_SNOWDRIFT_MIN   = 237,
    BG_AV_OBJECT_HANDPACKED_SNOWDRIFT_MAX   = 246,
    BG_AV_OBJECT_FROSTWOLF_BANNER           = 247,
    BG_AV_OBJECT_STORMPIKE_BANNER           = 248,
    BG_AV_OBJECT_GENERIC_MIN                = 249,
    BG_AV_OBJECT_GENERIC_MAX                = 323,
    BG_AV_OBJECT_HALLOWS_END_MIN            = 324,
    BG_AV_OBJECT_HALLOWS_END_MAX            = 403,

    BG_AV_OBJECT_MAX                        = 404
};

enum BG_AV_OBJECTS
{
    AV_OPLACE_FIRSTAID_STATION              = 0,
    AV_OPLACE_STORMPIKE_GRAVE               = 1,
    AV_OPLACE_STONEHEART_GRAVE              = 2,
    AV_OPLACE_SNOWFALL_GRAVE                = 3,
    AV_OPLACE_ICEBLOOD_GRAVE                = 4,
    AV_OPLACE_FROSTWOLF_GRAVE               = 5,
    AV_OPLACE_FROSTWOLF_HUT                 = 6,
    AV_OPLACE_DUNBALDAR_SOUTH               = 7,
    AV_OPLACE_DUNBALDAR_NORTH               = 8,
    AV_OPLACE_ICEWING_BUNKER                = 9,
    AV_OPLACE_STONEHEART_BUNKER             = 10,
    AV_OPLACE_ICEBLOOD_TOWER                = 11,
    AV_OPLACE_TOWER_POINT                   = 12,
    AV_OPLACE_FROSTWOLF_ETOWER              = 13,
    AV_OPLACE_FROSTWOLF_WTOWER              = 14,
    AV_OPLACE_BIGBANNER_DUNBALDAR_SOUTH     = 15,
    AV_OPLACE_BIGBANNER_DUNBALDAR_NORTH     = 16,
    AV_OPLACE_BIGBANNER_ICEWING_BUNKER      = 17,
    AV_OPLACE_BIGBANNER_STONEHEART_BUNKER   = 18,
    AV_OPLACE_BIGBANNER_ICEBLOOD_TOWER      = 19,
    AV_OPLACE_BIGBANNER_TOWER_POINT         = 20,
    AV_OPLACE_BIGBANNER_FROSTWOLF_ETOWER    = 21,
    AV_OPLACE_BIGBANNER_FROSTWOLF_WTOWER    = 22,

    AV_OPLACE_BURN_DUNBALDAR_SOUTH          = 23,
    AV_OPLACE_BURN_DUNBALDAR_NORTH          = 33,
    AV_OPLACE_BURN_ICEWING_BUNKER           = 43,
    AV_OPLACE_BURN_STONEHEART_BUNKER        = 53,
    AV_OPLACE_BURN_ICEBLOOD_TOWER           = 63,
    AV_OPLACE_BURN_TOWER_POINT              = 73,
    AV_OPLACE_BURN_FROSTWOLF_ETOWER         = 83,
    AV_OPLACE_BURN_FROSTWOLF_WTOWER         = 93,
    AV_OPLACE_BURN_BUILDING_A               = 103,
    AV_OPLACE_BURN_BUILDING_H               = 113,
    AV_OPLACE_SNOW_1                        = 123,
    AV_OPLACE_SNOW_2                        = 124,
    AV_OPLACE_SNOW_3                        = 125,
    AV_OPLACE_SNOW_4                        = 126,
    AV_OPLACE_MINE_SUPPLY_N_MIN             = 127,
    AV_OPLACE_MINE_SUPPLY_N_MAX             = 136,
    AV_OPLACE_MINE_SUPPLY_S_MIN             = 137,
    AV_OPLACE_MINE_SUPPLY_S_MAX             = 148,
    AV_OPLACE_HANDPACKED_SNOWDRIFT_MIN      = 149,
    AV_OPLACE_HANDPACKED_SNOWDRIFT_MAX      = 158,
    AV_OPLACE_FROSTWOLF_BANNER              = 159,
    AV_OPLACE_STORMPIKE_BANNER              = 160,

    AV_OPLACE_MAX                           = 161
};

const float BG_AV_ObjectPos[AV_OPLACE_MAX][4] =
{
    {638.592f, -32.422f, 46.0608f, -1.62316f }, //firstaid station
    {669.007f, -294.078f, 30.2909f, 2.77507f }, //stormpike
    {77.8013f, -404.7f, 46.7549f, -0.872665f }, //stone grave
    {-202.581f, -112.73f, 78.4876f, -0.715585f }, //snowfall
    {-611.962f, -396.17f, 60.8351f, 2.53682f},  //iceblood grave
    {-1082.45f, -346.823f, 54.9219f, -1.53589f }, //frostwolf grave
    {-1402.21f, -307.431f, 89.4424f, 0.191986f }, //frostwolf hut
    {553.779f, -78.6566f, 51.9378f, -1.22173f }, //dunnbaldar south
    {674.001f, -143.125f, 63.6615f, 0.994838f }, //dunbaldar north
    {203.281f, -360.366f, 56.3869f, -0.925024f }, //icew
    {-152.437f, -441.758f, 40.3982f, -1.95477f }, //stone
    {-571.88f, -262.777f, 75.0087f, -0.802851f }, //ice tower
    {-768.907f, -363.71f, 90.8949f, 1.07991f},  //tower point
    {-1302.9f, -316.981f, 113.867f, 2.00713f }, //frostwolf etower
    {-1297.5f, -266.767f, 114.15f, 3.31044f},   //frostwolf wtower
    //bigbanner:
    {555.848f, -84.4151f, 64.4397f, 3.12414f }, //duns
    {679.339f, -136.468f, 73.9626f, -2.16421f }, //dunn
    {208.973f, -365.971f, 66.7409f, -0.244346f }, //icew
    {-155.832f, -449.401f, 52.7306f, 0.610865f }, //stone
    {-572.329f, -262.476f, 88.6496f, -0.575959f }, //icetower
    {-768.199f, -363.105f, 104.537f, 0.10472f }, //towerp
    {-1302.84f, -316.582f, 127.516f, 0.122173f }, //etower
    {-1297.87f, -266.762f, 127.796f, 0.0698132f }, //wtower
    //burning auras towers have 9*179065 captain-buildings have 5*179066+5*179065
    //dunns
    {562.632f, -88.1815f, 61.993f, 0.383972f },
    {562.523f, -74.5028f, 37.9474f, -0.0523599f },
    {558.097f, -70.9842f, 52.4876f, 0.820305f },
    {578.167f, -71.8191f, 38.1514f, 2.72271f },
    {556.028f, -94.9242f, 44.8191f, 3.05433f },
    {572.451f, -94.3655f, 37.9443f, -1.72788f },
    {549.263f, -79.3645f, 44.8191f, 0.436332f },
    {543.513f, -94.4006f, 52.4819f, 0.0349066f },
    {572.149f, -93.7862f, 52.5726f, 0.541052f },
    {582.162f, -81.2375f, 37.9216f, 0.0872665f },
    //dunn
    {664.797f, -143.65f, 64.1784f, -0.453786f},
    {664.505f, -139.452f, 49.6696f, -0.0349067f},
    {676.067f, -124.319f, 49.6726f, -1.01229f},
    {693.004f, -144.025f, 64.1755f, 2.44346f},
    {661.175f, -117.691f, 49.645f, 1.91986f},
    {684.423f, -146.582f, 63.6662f, 0.994838f},
    {682.791f, -127.769f, 62.4155f, 1.09956f},
    {674.576f, -147.101f, 56.5425f, -1.6057f},
    {655.719f, -126.673f, 49.8138f, 2.80998f},
    {0, 0, 0, 0},
    //icew
    {231.503f, -356.688f, 42.3704f, 0.296706f},
    {224.989f, -348.175f, 42.5607f, 1.50098f},
    {205.782f, -351.335f, 56.8998f, 1.01229f},
    {196.605f, -369.187f, 56.3914f, 2.46091f},
    {210.619f, -376.938f, 49.2677f, 2.86234f},
    {209.647f, -352.632f, 42.3959f, -0.698132f},
    {220.65f, -368.132f, 42.3978f, -0.2618f},
    {224.682f, -374.031f, 57.0679f, 0.541052f},
    {200.26f, -359.968f, 49.2677f, -2.89725f},
    {196.619f, -378.016f, 56.9131f, 1.01229f},
    //stone
    {-155.488f, -437.356f, 33.2796f, 2.60054f},
    {-163.441f, -454.188f, 33.2796f, 1.93732f},
    {-143.977f, -445.148f, 26.4097f, -1.8675f},
    {-135.764f, -464.708f, 26.3823f, 2.25147f},
    {-154.076f, -466.929f, 41.0636f, -1.8675f},
    {-149.908f, -460.332f, 26.4083f, -2.09439f},
    {-151.638f, -439.521f, 40.3797f, 0.436332f},
    {-131.301f, -454.905f, 26.5771f, 2.93215f},
    {-171.291f, -444.684f, 40.9211f, 2.30383f},
    {-143.591f, -439.75f, 40.9275f, -1.72788f},
    //iceblood
    {-572.667f, -267.923f, 56.8542f, 2.35619f},
    {-561.021f, -262.689f, 68.4589f, 1.37881f},
    {-572.538f, -262.649f, 88.6197f, 1.8326f},
    {-574.77f, -251.45f, 74.9422f, -1.18682f},
    {-578.625f, -267.571f, 68.4696f, 0.506145f},
    {-571.476f, -257.234f, 63.3223f, 3.10669f},
    {-566.035f, -273.907f, 52.9582f, -0.890118f},
    {-580.948f, -259.77f, 68.4696f, 1.46608f},
    {-568.318f, -267.1f, 75.0008f, 1.01229f},
    {-559.621f, -268.597f, 52.8986f, 0.0523599f},
    //towerp
    {-776.072f, -368.046f, 84.3558f, 2.63545f},
    {-777.564f, -368.521f, 90.6701f, 1.72788f},
    {-765.461f, -357.711f, 90.888f, 0.314159f},
    {-768.763f, -362.735f, 104.612f, 1.81514f},
    {-760.356f, -358.896f, 84.3558f, 2.1293f},
    {-771.967f, -352.838f, 84.3484f, 1.74533f},
    {-773.333f, -364.653f, 79.2351f, -1.64061f},
    {-764.109f, -366.069f, 70.0934f, 0.383972f},
    {-767.103f, -350.737f, 68.7933f, 2.80998f},
    {-760.115f, -353.845f, 68.8633f, 1.79769f},
    //froste
    {-1304.87f, -304.525f, 91.8366f, -0.680679f},
    {-1301.77f, -310.974f, 95.8252f, 0.907571f},
    {-1305.58f, -320.625f, 102.166f, -0.558505f},
    {-1294.27f, -323.468f, 113.893f, -1.67552f},
    {-1302.65f, -317.192f, 127.487f, 2.30383f},
    {-1293.89f, -313.478f, 107.328f, 1.6057f},
    {-1312.41f, -312.999f, 107.328f, 1.5708f},
    {-1311.57f, -308.08f, 91.7666f, -1.85005f},
    {-1314.7f, -322.131f, 107.36f, 0.645772f},
    {-1304.6f, -310.754f, 113.859f, -0.401426f},
    //frostw
    {-1308.24f, -273.26f, 92.0514f, -0.139626f},
    {-1302.26f, -262.858f, 95.9269f, 0.418879f},
    {-1297.28f, -267.773f, 126.756f, 2.23402f},
    {-1299.08f, -256.89f, 114.108f, -2.44346f},
    {-1303.41f, -268.237f, 114.151f, -1.23918f},
    {-1304.43f, -273.682f, 107.612f, 0.244346f},
    {-1309.53f, -265.951f, 92.1418f, -2.49582f},
    {-1295.55f, -263.865f, 105.033f, 0.925024f},
    {-1294.71f, -281.466f, 107.664f, -1.50098f},
    {-1289.69f, -259.521f, 107.612f, -2.19912f},

    //the two buildings of the captains
    //alliance
    {-64.4987f, -289.33f, 33.4616f, -2.82743f},
    {-5.98025f, -326.144f, 38.8538f, 0},
    {-2.67893f, -306.998f, 33.4165f, 0},
    {-60.25f, -309.232f, 50.2408f, -1.46608f},
    {-48.7941f, -266.533f, 47.7916f, 2.44346f},
    {-3.40929f, -306.288f, 33.34f, 0},
    {-48.619f, -266.917f, 47.8168f, 0},
    {-62.9474f, -286.212f, 66.7288f, 0},
    {-5.05132f, -325.323f, 38.8536f, 0},
    {-64.2677f, -289.412f, 33.469f, 0},
    //horde
    {-524.276f, -199.6f, 82.8733f, -1.46608f},
    {-518.196f, -173.085f, 102.43f, 0},
    {-500.732f, -145.358f, 88.5337f, 2.44346f},
    {-501.084f, -150.784f, 80.8506f, 0},
    {-518.309f, -163.963f, 102.521f, 2.96706f},
    {-517.053f, -200.429f, 80.759f, 0},
    {-514.361f, -163.864f, 104.163f, 0},
    {-568.04f, -188.707f, 81.55f, 0},
    {-501.775f, -151.581f, 81.2027f, 0},
    {-509.975f, -191.652f, 83.2978f, 0},

    //snowfall eyecandy
    {-191.153f, -129.868f, 78.5595f, -1.25664f },
    {-201.282f, -134.319f, 78.6753f, -0.942478f },
    {-215.981f, -91.4101f, 80.8702f, -1.74533f },
    {-200.465f, -96.418f, 79.7587f, 1.36136f },
    //mine supplies
    //irondeep
    {870.899f, -388.434f, 61.6406f, -1.22173f},
    {825.214f, -320.174f, 63.712f, -2.82743f},
    {837.117f, -452.556f, 47.2331f, -3.12414f},
    {869.755f, -448.867f, 52.5448f, -0.855212f},
    {949.877f, -458.198f, 56.4874f, 0.314159f},
    {900.35f, -479.024f, 58.3553f, 0.122173f},
    {854.449f, -442.255f, 50.6589f, 0.401426f},
    {886.685f, -442.358f, 54.6962f, -1.22173f},
    {817.509f, -457.331f, 48.4666f, 2.07694f},
    {793.411f, -326.281f, 63.1117f, -2.79253f},
    //coldtooth
    {-934.212f, -57.3517f, 80.277f, -0.0174535f},
    {-916.281f, -36.8579f, 77.0227f, 0.122173f},
    {-902.73f, -103.868f, 75.4378f, -1.58825f},
    {-900.514f, -143.527f, 75.9686f, 1.8675f},
    {-862.882f, -0.353299f, 72.1526f, -2.51327f},
    {-854.932f, -85.9184f, 68.6056f, -2.04204f},
    {-851.833f, -118.959f, 63.8672f, -0.0698131f},
    {-849.832f, -20.8421f, 70.4672f, -1.81514f},
    {-844.25f, -60.0374f, 72.1031f, -2.19912f},
    {-820.644f, -136.043f, 63.1977f, 2.40855f},
    {-947.642f, -208.807f, 77.0101f, 1.36136f},
    {-951.394f, -193.695f, 67.634f, 0.802851f},
    // hardpacked snowdrift
    {712.1f, -446.49f, 65.74f, 2.13f},
    {696.4f, -276.4f, 28.55f, 3.2f},
    {74.0f, -313.27f, 31.16f, 0.17f},
    {-75.4f, -224.4f, 10.24f, 2.99f},
    {-160.9f, -72.1f, 33.36f, 5.5f},
    {-255.8f, -217.55f, 7.66f, 2.8f},
    {-361.49f, -115.5f, 26.42f, 0.6f},
    {-389.5f, -325.0f, 17.98f, 3.89f},
    {-919.57f, -362.48f, 52.13f, 3.8f},
    {-1259.1f, -500.8f, 50.81f, 1.2f},
    {-1552.55f, -359.738f, 66.948f, 2.8875f},
    {40.0913f, 0.0153897f, -4.0962f, 0.96131f}
};

// GO template ID, Position, rotation0-3, VerifiedBuild
std::tuple<uint32, Position, std::array<float, 4>> const BG_AV_GenericObjectPos[BG_AV_OBJECT_GENERIC_MAX - BG_AV_OBJECT_GENERIC_MIN + 1] =
{
    // Burning Embers
    { 3832,   { -1235.57f, -241.478f, 73.4377f,    1.48353f }, {         0.0f,         0.0f,    0.67559f,  0.737278f } }, // 46248
    { 3833,   { -1248.85f,  -254.06f, 73.4377f,    1.48353f }, {         0.0f,         0.0f,    0.67559f,  0.737278f } }, // 46248
    { 3834,   { -1248.15f, -245.599f, 73.4377f,    6.23083f }, {         0.0f,         0.0f, -0.0261765f,  0.999657f } }, // 46248
    { 3835,   { -1237.21f, -260.168f, 73.4377f,    1.48353f }, {         0.0f,         0.0f,    0.67559f,  0.737278f } }, // 46248
    { 3836,   { -1260.37f, -248.767f, 77.9454f,    1.48353f }, {         0.0f,         0.0f,    0.67559f,  0.737278f } }, // 46248
    { 3837,   { -1249.32f, -244.907f, 92.3372f,   0.401425f }, {         0.0f,         0.0f,   0.199368f,  0.979925f } }, // 46248
    { 3838,   { -1250.09f, -254.604f, 92.3015f,   0.148352f }, {         0.0f,         0.0f,  0.0741081f,   0.99725f } }, // 46248
    // Wooden Chair
    { 28048,  {  41.1672f, -426.866f, 44.6828f,     2.7838f }, {         0.0f,         0.0f,    0.98404f,  0.177946f } }, // 52237
    { 28049,  {  39.0988f, -425.746f,  44.688f,    5.66359f }, {         0.0f,         0.0f,  -0.304864f,  0.952396f } }, // 52237
    { 28605,  {  25.2482f, -433.104f, 47.6369f,    2.38237f }, {         0.0f,         0.0f,   0.928809f,  0.370558f } }, // 52237
    { 28606,  {   25.758f, -425.837f, 47.6369f,    4.30224f }, {         0.0f,         0.0f,  -0.836286f,  0.548294f } }, // 52237
    { 28607,  {  27.6786f,  -427.69f, 47.6369f,    3.60411f }, {         0.0f,         0.0f,  -0.973379f,  0.229201f } }, // 52237
    // Anvil
    { 32571,  { -100.071f, -583.512f, 41.7316f, 0.00872424f }, {         0.0f,         0.0f, 0.00436211f,   0.99999f } }, // 46248
    { 32572,  { -102.733f, -588.775f, 41.7316f,    5.24472f }, {         0.0f,         0.0f,  -0.496216f,  0.868199f } }, // 46248
    { 32573,  { -100.966f, -586.958f, 41.7316f,    5.76831f }, {         0.0f,         0.0f,  -0.254601f,  0.967046f } }, // 46248
    { 32574,  { -106.172f, -589.721f, 41.7316f,    4.72112f }, {         0.0f,         0.0f,  -0.704014f,  0.710186f } }, // 46248
    { 51704,  {  -1245.2f, -307.059f, 63.3199f,     3.0796f }, { -0.00711155f,  -0.0236301f,    0.99922f, 0.0308324f } }, // 46248
    { 51705,  { -1258.23f, -310.977f, 63.2015f,   0.862903f }, {   0.0179744f,  -0.0169086f,   0.418255f,  0.907994f } }, // 46248
    { 161489, {   360.38f, -527.549f, 71.1205f,    4.23242f }, {         0.0f,         0.0f,  -0.854912f,  0.518773f } }, // 46248
    { 178685, {  646.207f, -57.2431f, 41.6587f,    6.12611f }, {         0.0f,         0.0f, -0.0784588f,  0.996917f } }, // 46248
    { 179391, {  548.682f, -100.846f, 44.8191f,    1.46608f }, {         0.0f,         0.0f,    0.66913f,  0.743145f } }, // 46248
    { 179391, { -172.363f, -452.824f, 33.2796f,   0.628319f }, {         0.0f,         0.0f,   0.309017f,  0.951056f } }, // 46248
    { 179392, {  552.429f, -102.764f, 44.8191f,    2.46964f }, {         0.0f,         0.0f,   0.944089f,  0.329691f } }, // 46248
    { 179392, { -171.282f, -456.892f, 33.2796f,    1.63188f }, {         0.0f,         0.0f,   0.728371f,  0.685183f } }, // 46248
    { 179393, {  549.472f, -101.547f, 44.8191f,    1.16064f }, {         0.0f,         0.0f,   0.548293f,  0.836286f } }, // 46248
    { 179393, { -172.356f,  -453.88f, 33.2796f,   0.322884f }, {         0.0f,         0.0f,   0.160742f,  0.986997f } }, // 46248
    { 179394, {  550.347f, -101.698f, 44.8191f,    1.59698f }, {         0.0f,         0.0f,   0.716302f,   0.69779f } }, // 46248
    { 179394, { -171.882f, -454.632f, 33.2796f,   0.759217f }, {         0.0f,         0.0f,   0.370557f,   0.92881f } }, // 46248
    { 179395, {  551.271f, -102.226f, 44.8191f,   0.898843f }, {         0.0f,         0.0f,   0.434444f,  0.900699f } }, // 46248
    { 179395, { -171.656f, -455.671f, 33.2796f,  0.0610847f }, {         0.0f,         0.0f,  0.0305376f,  0.999534f } }, // 46248
    { 179396, { -170.699f,  -458.41f, 33.2796f,    5.25344f }, {         0.0f,         0.0f,  -0.492423f,  0.870356f } }, // 46248
    { 179396, {  553.947f, -103.347f, 44.8191f,     6.0912f }, {         0.0f,         0.0f, -0.0958452f,  0.995396f } }, // 46248
    { 179397, {  -170.14f, -457.609f, 33.2796f,    5.60251f }, {         0.0f,         0.0f,  -0.333806f,  0.942642f } }, // 46248
    { 179397, {  553.725f, -102.396f, 44.8191f,   0.157079f }, {         0.0f,         0.0f,  0.0784588f,  0.996917f } }, // 46248
    // Forge
    { 34571,  { -105.423f, -584.352f, 42.0149f,    2.36492f }, {         0.0f,         0.0f,    0.92554f,   0.37865f } }, // 46248
    { 161487, {  361.097f, -531.693f, 71.1898f,    4.12771f }, {         0.0f,         0.0f,   -0.88089f,  0.473321f } }, // 46248
    { 178684, {  649.264f, -59.1111f, 41.5476f,    3.59538f }, {         0.0f,         0.0f,   -0.97437f,  0.224951f } }, // 46248
    // Bonfire
    { 161488, {  360.915f, -497.099f, 71.3389f,    3.14159f }, {         0.0f,         0.0f,       -1.0f,       0.0f } }, // 46248
    { 177408, { -743.427f, -398.241f, 76.4266f,   0.872664f }, {   0.0173936f, -0.00633049f,   0.422701f,   0.90608f } }, // 46248
    // Brazier
    { 177261, { -1290.27f,  -172.47f, 72.1853f,    3.06302f }, {  0.00871992f, -0.00034237f,    0.99919f, 0.0392748f } }, // 46248
    { 177292, { -1099.21f, -266.231f, 57.8849f,    3.99681f }, {         0.0f,         0.0f,  -0.909961f,  0.414694f } }, // 46248
    { 177293, {  -1082.6f, -266.681f, 57.8575f,    2.40855f }, {         0.0f,         0.0f,   0.933579f,   0.35837f } }, // 46248
    { 177405, { -1140.82f, -343.392f, 50.9077f,    3.49939f }, {         0.0f,         0.0f,   -0.98404f,  0.177946f } }, // 46248
    { 177406, { -1139.68f, -356.288f,  51.264f,    5.57633f }, {         0.0f,         0.0f,  -0.346116f,  0.938192f } }, // 46248
    { 177409, { -1215.59f, -371.946f, 56.5293f,   0.357792f }, {         0.0f,         0.0f,   0.177943f,  0.984041f } }, // 46248
    { 177410, { -1241.25f, -345.115f, 59.6867f,   0.357792f }, {         0.0f,         0.0f,   0.177943f,  0.984041f } }, // 46248
    { 177411, { -1202.81f, -271.599f, 72.5805f,   0.357792f }, {         0.0f,         0.0f,   0.177943f,  0.984041f } }, // 46248
    { 177412, { -1282.21f, -284.083f,  87.256f,     6.2221f }, {         0.0f,         0.0f, -0.0305376f,  0.999534f } }, // 46248
    { 177413, { -1256.55f, -280.278f, 73.9473f,     6.2221f }, {         0.0f,         0.0f, -0.0305376f,  0.999534f } }, // 46248
    { 179419, { -1423.16f, -318.436f, 89.1136f,    2.35619f }, {         0.0f,         0.0f,   0.923879f,  0.382686f } }, // 46248
    // Campfire
    { 177262, { -1286.25f, -184.481f, 71.8334f,    4.23243f }, { -0.00733089f,  -0.0299597f,  -0.854258f,  0.518934f } }, // 46248
    { 177263, { -1280.17f, -220.536f, 72.2686f,    1.62315f }, {         0.0f,         0.0f,   0.725373f,  0.688356f } }, // 46248
    { 177324, { -375.017f,  -523.71f, 84.0771f,    3.14159f }, {         0.0f,         0.0f,       -1.0f,       0.0f } }, // 46248
    { 177325, {  -413.51f, -521.413f, 84.0771f,    2.05948f }, {         0.0f,         0.0f,   0.857166f,   0.51504f } }, // 46248
    { 177326, { -487.401f, -526.486f, 82.5708f,    5.47161f }, {         0.0f,         0.0f,  -0.394743f,  0.918792f } }, // 46248
    { 177327, { -251.556f, -562.061f, 68.1725f,    6.11738f }, {         0.0f,         0.0f, -0.0828075f,  0.996566f } }, // 46248
    { 177425, { -353.118f,  37.0955f, 65.8904f,    3.14159f }, {         0.0f,         0.0f,       -1.0f,       0.0f } }, // 48632
    { 179945, { -1070.53f, -617.908f, 51.3249f,    5.83813f }, {         0.0f,         0.0f,  -0.220697f,  0.975342f } }, // 46248
    // Cauldron
    { 177396, {  12.8247f,  -120.21f, 41.6669f,    3.14159f }, {         0.0f,         0.0f,       -1.0f,       0.0f } }, // 46248
    // Chair
    { 179384, { -145.341f, -444.846f, 26.4163f,    6.23083f }, {         0.0f,         0.0f, -0.0261765f,  0.999657f } }, // 52237
    { 179384, {  560.834f, -75.4266f, 37.9558f,   0.785397f }, {         0.0f,         0.0f,   0.382683f,   0.92388f } }, // 52237
    { 179385, {  550.678f, -79.8234f, 44.8257f,    3.18527f }, {         0.0f,         0.0f,  -0.999762f, 0.0218352f } }, // 52237
    { 179385, { -155.405f,  -440.24f, 33.2862f,    2.34747f }, {         0.0f,         0.0f,   0.922201f,   0.38671f } }, // 52237
    { 179386, {  568.326f, -89.4992f, 37.9558f,    1.39626f }, {         0.0f,         0.0f,   0.642787f,  0.766045f } }, // 52237
    { 179386, { -150.787f, -459.829f, 26.4163f,   0.558504f }, {         0.0f,         0.0f,   0.275637f,  0.961262f } }, // 52237
    { 179387, {  550.597f, -77.5213f, 44.8257f,    4.23242f }, {         0.0f,         0.0f,  -0.854912f,  0.518773f } }, // 52237
    { 179387, { -153.748f, -438.639f, 33.2862f,    3.39467f }, {         0.0f,         0.0f,  -0.992004f,  0.126203f } }, // 52237
    { 179388, {  570.419f, -89.0567f, 37.9558f,    2.22529f }, {         0.0f,         0.0f,   0.896873f,  0.442289f } }, // 52237
    { 179388, { -149.057f, -461.089f, 26.4163f,    1.38754f }, {         0.0f,         0.0f,    0.63944f,  0.768841f } }, // 52237
    { 179389, {  555.517f, -101.589f, 44.8257f,   0.392697f }, {         0.0f,         0.0f,   0.195089f,  0.980785f } }, // 52237
    { 179389, { -168.342f,   -458.4f, 33.2862f,    5.83813f }, {         0.0f,         0.0f,  -0.220697f,  0.975342f } }, // 52237
    { 179390, {  561.851f, -73.1481f, 37.9558f,    4.88692f }, {         0.0f,         0.0f,  -0.642787f,  0.766045f } }, // 52237
    { 179390, { -142.968f, -444.076f, 26.4163f,    4.04917f }, {         0.0f,         0.0f,  -0.898793f,  0.438373f } }, // 52237
    // Wanted: ORCS!
    { 179437, {  618.748f, -52.1126f, 42.1122f,    6.21337f }, {         0.0f,         0.0f, -0.0348988f,  0.999390f } }, // 46248
    // Wanted: DWARVES!
    { 179438, { -1181.10f, -370.747f, 53.6246f,    2.68781f }, {         0.0f,         0.0f,   0.974370f,  0.224951f } }, // 46248
};

// GO template ID, Position, rotation0-3, VerifiedBuild
std::tuple<uint32, Position, std::array<float, 4>> const BG_AV_HallowsEndObjectPos[BG_AV_OBJECT_HALLOWS_END_MAX - BG_AV_OBJECT_HALLOWS_END_MIN + 1] =
{
    // G_Pumpkin_01
    { 180405, { -1158.97f, -357.826f, 52.0172f,  2.02458f }, { 0.0f, 0.0f,   0.848047f,  0.529921f } }, // 46248
    { 180405, { -126.302f, -453.835f,  36.749f,  1.97222f }, { 0.0f, 0.0f,   0.833885f,  0.551938f } }, // 46248
    { 180405, { -1305.91f,  -299.92f, 92.6384f,  3.85718f }, { 0.0f, 0.0f,  -0.936671f,   0.35021f } }, // 46248
    { 180405, { -1357.74f, -283.203f, 95.7139f,    1.309f }, { 0.0f, 0.0f,   0.608761f,  0.793354f } }, // 46248
    { 180405, { -500.524f, -192.561f, 57.4784f,  2.02458f }, { 0.0f, 0.0f,   0.848047f,  0.529921f } }, // 46248
    { 180405, { -766.615f, -343.542f, 67.8594f,  2.32129f }, { 0.0f, 0.0f,    0.91706f,   0.39875f } }, // 46248
    { 180405, {  14.5434f, -288.689f, 18.6031f,    1.309f }, { 0.0f, 0.0f,   0.608761f,  0.793354f } }, // 46248
    { 180405, {  15.1771f, -417.266f, 45.4566f,  4.64258f }, { 0.0f, 0.0f,  -0.731354f,  0.681998f } }, // 46248
    { 180405, {  233.097f, -339.278f, 45.7862f,  1.18682f }, { 0.0f, 0.0f,   0.559193f,  0.829038f } }, // 46248
    { 180405, {   587.37f,  -82.283f, 48.2967f,  2.32129f }, { 0.0f, 0.0f,    0.91706f,   0.39875f } }, // 46248
    { 180405, {  607.686f, -18.3559f,  49.127f, 0.837757f }, { 0.0f, 0.0f,   0.406736f,  0.913546f } }, // 46248
    { 180405, {   615.03f, -192.127f, 41.8927f,  0.59341f }, { 0.0f, 0.0f,   0.292371f,  0.956305f } }, // 46248
    { 180405, {  629.882f,  -153.54f, 42.6296f, 0.558504f }, { 0.0f, 0.0f,   0.275637f,  0.961262f } }, // 46248
    { 180405, {  644.681f, -121.622f, 53.0553f,  3.50812f }, { 0.0f, 0.0f,  -0.983254f,  0.182238f } }, // 46248
    { 180405, {  646.655f, -265.535f, 39.2146f, 0.279252f }, { 0.0f, 0.0f,   0.139173f,  0.990268f } }, // 46248
    { 180405, {  666.656f, -16.0868f, 53.9853f,  5.81195f }, { 0.0f, 0.0f,  -0.233445f,   0.97237f } }, // 46248
    // G_Pumpkin_02
    { 180406, { -115.708f, -559.182f, 46.4159f,   3.3685f }, { 0.0f, 0.0f,  -0.993571f,  0.113208f } }, // 46248
    { 180406, {  -1208.5f,  -248.34f, 73.0666f,   1.6057f }, { 0.0f, 0.0f,   0.719339f,  0.694659f } }, // 46248
    { 180406, { -1227.88f, -372.741f, 57.9504f,  2.51327f }, { 0.0f, 0.0f,   0.951056f,  0.309017f } }, // 46248
    { 180406, { -1315.84f, -266.819f, 91.5945f,  6.14356f }, { 0.0f, 0.0f, -0.0697556f,  0.997564f } }, // 46248
    { 180406, { -132.559f, -469.016f, 36.7525f,  1.53589f }, { 0.0f, 0.0f,   0.694658f,   0.71934f } }, // 46248
    { 180406, {  -1343.9f, -278.906f, 95.8878f, 0.157079f }, { 0.0f, 0.0f,  0.0784588f,  0.996917f } }, // 46248
    { 180406, { -1359.55f, -275.984f, 97.4804f,  1.25664f }, { 0.0f, 0.0f,   0.587785f,  0.809017f } }, // 46248
    { 180406, { -494.535f, -177.293f, 57.4655f, 0.820303f }, { 0.0f, 0.0f,   0.398748f,   0.91706f } }, // 46248
    { 180406, { -563.554f, -277.615f, 51.8459f,  1.25664f }, { 0.0f, 0.0f,   0.587785f,  0.809017f } }, // 46248
    { 180406, {  11.2743f, -309.234f, 18.5687f,  2.02458f }, { 0.0f, 0.0f,   0.848047f,  0.529921f } }, // 46248
    { 180406, {  226.415f, -343.573f, 52.7243f,  2.65289f }, { 0.0f, 0.0f,   0.970295f,  0.241925f } }, // 46248
    { 180406, {    4.625f, -287.089f, 18.9285f,  1.53589f }, { 0.0f, 0.0f,   0.694658f,   0.71934f } }, // 46248
    { 180406, {  580.425f, -67.8611f, 48.2671f,  1.79769f }, { 0.0f, 0.0f,   0.782608f,  0.622515f } }, // 46248
    { 180406, {  602.411f, -20.1337f,  49.127f, 0.523598f }, { 0.0f, 0.0f,   0.258819f,  0.965926f } }, // 46248
    { 180406, {  609.092f, -156.634f,   42.63f, 0.523598f }, { 0.0f, 0.0f,   0.258819f,  0.965926f } }, // 46248
    { 180406, {  626.033f, -268.701f, 39.2121f, 0.471238f }, { 0.0f, 0.0f,   0.233445f,   0.97237f } }, // 46248
    { 180406, {  640.854f, -230.306f, 40.6572f, 0.349065f }, { 0.0f, 0.0f,   0.173648f,  0.984808f } }, // 46248
    { 180406, {  657.406f, -19.0451f, 53.6367f,  5.70723f }, { 0.0f, 0.0f,  -0.284015f,   0.95882f } }, // 46248
    { 180406, {  659.373f, -113.127f, 59.9997f,  4.85202f }, { 0.0f, 0.0f,  -0.656058f,   0.75471f } }, // 46248
    { 180406, {  672.715f, -36.0156f, 53.9853f,  5.00909f }, { 0.0f, 0.0f,  -0.594823f,  0.803857f } }, // 46248
    // G_Pumpkin_03
    { 180407, { -1160.13f, -348.217f, 52.0004f,   1.8675f }, { 0.0f, 0.0f,   0.803857f,  0.594823f } }, // 46248
    { 180407, { -119.587f, -457.271f, 29.7838f,  1.71042f }, { 0.0f, 0.0f,   0.754709f,  0.656059f } }, // 46248
    { 180407, { -1209.86f, -258.707f, 72.7768f,   1.8675f }, { 0.0f, 0.0f,   0.803857f,  0.594823f } }, // 46248
    { 180407, { -1346.58f, -271.594f, 97.4922f, 0.209439f }, { 0.0f, 0.0f,   0.104528f,  0.994522f } }, // 46248
    { 180407, { -1362.37f, -309.545f, 91.7044f,  2.46091f }, { 0.0f, 0.0f,   0.942641f,  0.333808f } }, // 46248
    { 180407, { -556.349f,  -269.62f, 52.3396f,  0.90757f }, { 0.0f, 0.0f,   0.438371f,  0.898794f } }, // 46248
    { 180407, { -756.531f, -349.429f, 67.5058f,  3.47321f }, { 0.0f, 0.0f,  -0.986285f,   0.16505f } }, // 46248
    { 180407, {  1.51215f, -307.455f, 18.9285f,  2.14675f }, { 0.0f, 0.0f,   0.878817f,   0.47716f } }, // 46248
    { 180407, {  236.859f, -356.431f, 52.7499f,  2.26893f }, { 0.0f, 0.0f,   0.906307f,  0.422619f } }, // 46248
    { 180407, {  587.264f,   -64.75f, 41.3224f,  1.71042f }, { 0.0f, 0.0f,   0.754709f,  0.656059f } }, // 46248
    { 180407, {  621.241f, -233.352f, 40.6083f, 0.663223f }, { 0.0f, 0.0f,   0.325567f,  0.945519f } }, // 46248
    { 180407, {  634.472f, -189.106f, 41.8665f, 0.523598f }, { 0.0f, 0.0f,   0.258819f,  0.965926f } }, // 46248
    { 180407, {    650.7f, -126.259f, 59.9983f,  3.94445f }, { 0.0f, 0.0f,  -0.920505f,  0.390732f } }, // 46248
    { 180407, {  663.257f, -38.8993f, 53.6307f,  4.92183f }, { 0.0f, 0.0f,   -0.62932f,  0.777146f } }, // 46248
    // Bat01
    { 180426, { -1329.83f, -300.214f, 107.965f,  2.09439f }, { 0.0f, 0.0f,   0.866025f,  0.500001f } }, // 46248
    { 180426, { -1332.54f, -294.962f, 117.904f,  1.51844f }, { 0.0f, 0.0f,   0.688354f,  0.725374f } }, // 46248
    { 180426, { -1336.12f,  -293.71f,  109.14f,  2.09439f }, { 0.0f, 0.0f,   0.866025f,  0.500001f } }, // 46248
    { 180426, { -1338.41f, -299.877f,   111.3f, 0.767944f }, { 0.0f, 0.0f,   0.374606f,  0.927184f } }, // 46248
    { 180426, { -247.924f, -289.095f, 43.7022f,  2.09439f }, { 0.0f, 0.0f,   0.866025f,  0.500001f } }, // 46248
    { 180426, { -250.307f,  -294.67f, 51.5083f,  1.51844f }, { 0.0f, 0.0f,   0.688354f,  0.725374f } }, // 46248
    { 180426, { -255.208f, -305.076f, 47.9254f,  2.09439f }, { 0.0f, 0.0f,   0.866025f,  0.500001f } }, // 46248
    { 180426, { -263.672f, -294.012f, 66.9219f,   3.4383f }, { 0.0f, 0.0f,  -0.989016f,  0.147811f } }, // 46248
    { 180426, { -268.958f, -286.128f, 65.7266f,  5.28835f }, { 0.0f, 0.0f,  -0.477159f,  0.878817f } }, // 46248
    { 180426, { -269.526f, -278.163f,  65.567f,  2.09439f }, { 0.0f, 0.0f,   0.866025f,  0.500001f } }, // 46248
    { 180426, { -270.384f, -292.399f, 57.8192f,  5.14872f }, { 0.0f, 0.0f,  -0.537299f,  0.843392f } }, // 46248
    { 180426, {  617.543f, -72.4375f, 61.5847f,  2.09439f }, { 0.0f, 0.0f,   0.866025f,  0.500001f } }, // 46248
    { 180426, {  622.451f, -62.4271f, 70.3966f,  2.70526f }, { 0.0f, 0.0f,   0.976295f,  0.216442f } }, // 46248
    { 180426, {  627.418f, -47.6285f, 58.8142f, 0.890117f }, { 0.0f, 0.0f,   0.430511f,  0.902586f } }, // 46248
    { 180426, {  630.523f, -44.9826f,  69.864f,  3.24635f }, { 0.0f, 0.0f,  -0.998629f, 0.0523532f } }, // 46248
    { 180426, {  632.502f, -67.3333f,  65.444f,  3.14159f }, { 0.0f, 0.0f,       -1.0f,       0.0f } }, // 46248
    { 180426, {  635.186f, -45.3333f, 55.8426f,  2.09439f }, { 0.0f, 0.0f,   0.866025f,  0.500001f } }, // 46248
    // Bat02
    { 180427, {  -1336.3f, -295.644f, 116.531f,  3.45576f }, { 0.0f, 0.0f,  -0.987688f,  0.156436f } }, // 46248
    { 180427, { -1338.58f, -296.351f, 117.126f,  4.13643f }, { 0.0f, 0.0f,  -0.878817f,   0.47716f } }, // 46248
    { 180427, { -1341.88f, -298.439f, 119.023f,  4.97419f }, { 0.0f, 0.0f,  -0.608761f,  0.793354f } }, // 46248
    { 180427, { -1347.11f, -291.332f, 110.968f,  3.45576f }, { 0.0f, 0.0f,  -0.987688f,  0.156436f } }, // 46248
    { 180427, { -258.149f, -300.316f, 52.5291f,  2.80998f }, { 0.0f, 0.0f,   0.986285f,   0.16505f } }, // 46248
    { 180427, { -263.734f, -304.363f, 41.6929f,  4.97419f }, { 0.0f, 0.0f,  -0.608761f,  0.793354f } }, // 46248
    { 180427, { -265.972f, -290.925f, 73.3895f,  4.97419f }, { 0.0f, 0.0f,  -0.608761f,  0.793354f } }, // 46248
    { 180427, { -267.002f, -291.997f, 68.8963f,  4.97419f }, { 0.0f, 0.0f,  -0.608761f,  0.793354f } }, // 46248
    { 180427, { -273.811f, -288.575f, 50.9076f,  4.97419f }, { 0.0f, 0.0f,  -0.608761f,  0.793354f } }, // 46248
    { 180427, {   618.34f, -55.8924f, 73.4326f,  2.70526f }, { 0.0f, 0.0f,   0.976295f,  0.216442f } }, // 46248
    { 180427, {   625.45f, -53.5191f, 60.4743f,  2.74016f }, { 0.0f, 0.0f,   0.979924f,   0.19937f } }, // 46248
    { 180427, {  627.179f, -43.5382f, 72.6337f,  2.65289f }, { 0.0f, 0.0f,   0.970295f,  0.241925f } }, // 46248
    { 180427, {   636.71f, -62.2118f, 69.4788f,  2.19911f }, { 0.0f, 0.0f,   0.891006f,  0.453991f } }, // 46248
};

const float BG_AV_DoorPositons[2][4] =
{
    {780.487f, -493.024f, 99.9553f, 3.0976f},   //alliance
    {-1375.193f, -538.981f, 55.2824f, 0.72178f} //horde
};

// creature stuff starts here
// is related to BG_AV_CreaturePos
enum BG_AV_CreaturePlace
{
    AV_CPLACE_SPIRIT_STORM_AID      = 0,
    AV_CPLACE_SPIRIT_STORM_GRAVE    = 1,
    AV_CPLACE_SPIRIT_STONE_GRAVE    = 2,
    AV_CPLACE_SPIRIT_SNOWFALL       = 3,
    AV_CPLACE_SPIRIT_ICE_GRAVE      = 4,
    AV_CPLACE_SPIRIT_FROSTWOLF      = 5,
    AV_CPLACE_SPIRIT_FROST_HUT      = 6,
    AV_CPLACE_SPIRIT_MAIN_ALLIANCE  = 7,
    AV_CPLACE_SPIRIT_MAIN_HORDE     = 8,

    AV_CPLACE_DEFENSE_STORM_AID     = 9,
    AV_CPLACE_DEFEMSE_STORM_GRAVE   = 13,
    AV_CPLACE_DEFENSE_STONE_GRAVE   = 17,
    AV_CPLACE_DEFENSE_SNOWFALL      = 21,
    AV_CPLACE_DEFENSE_FROSTWOLF     = 25,
    AV_CPLACE_DEFENSE_ICE_GRAVE     = 29,
    AV_CPLACE_DEFENSE_FROST_HUT     = 33,

    AV_CPLACE_DEFENSE_DUN_S         = 37,
    AV_CPLACE_DEFENSE_DUN_N         = 41,
    AV_CPLACE_DEFENSE_ICEWING       = 45,
    AV_CPLACE_DEFENSE_STONE_TOWER   = 49,
    AV_CPLACE_DEFENSE_ICE_TOWER     = 53,
    AV_CPLACE_DEFENSE_TOWERPOINT    = 57,
    AV_CPLACE_DEFENSE_FROST_E       = 61,
    AV_CPLACE_DEFENSE_FROST_t       = 65,

    AV_CPLACE_A_MARSHAL_SOUTH       = 69,
    AV_CPLACE_A_MARSHAL_NORTH       = 70,
    AV_CPLACE_A_MARSHAL_ICE         = 71,
    AV_CPLACE_A_MARSHAL_STONE       = 72,
    AV_CPLACE_H_MARSHAL_ICE         = 73,
    AV_CPLACE_H_MARSHAL_TOWER       = 74,
    AV_CPLACE_H_MARSHAL_ETOWER      = 75,
    AV_CPLACE_H_MARSHAL_WTOWER      = 76,

    AV_CPLACE_MINE_N_3        = 77, // irondeep boss   
    AV_CPLACE_MINE_S_3        = 78, // coldtooth boss
    AV_CPLACE_HERALD          = 79, // herald

    //node aura triggers
    AV_CPLACE_TRIGGER01       = 80,
    AV_CPLACE_TRIGGER02       = 81,
    AV_CPLACE_TRIGGER03       = 82,
    AV_CPLACE_TRIGGER04       = 83,
    AV_CPLACE_TRIGGER05       = 84,
    AV_CPLACE_TRIGGER06       = 85,
    AV_CPLACE_TRIGGER07       = 86,
    AV_CPLACE_TRIGGER08       = 87,
    AV_CPLACE_TRIGGER09       = 88,
    AV_CPLACE_TRIGGER10       = 89,
    AV_CPLACE_TRIGGER11       = 90,
    AV_CPLACE_TRIGGER12       = 91,
    AV_CPLACE_TRIGGER13       = 92,
    AV_CPLACE_TRIGGER14       = 93,
    AV_CPLACE_TRIGGER15       = 94,

    //boss, captain triggers
    AV_CPLACE_TRIGGER16       = 95,
    AV_CPLACE_TRIGGER17       = 96,
    AV_CPLACE_TRIGGER18       = 97,
    AV_CPLACE_TRIGGER19       = 98,

    AV_CPLACE_A_BOSS          = 96, // used by BattleGroundTactics.cpp
    AV_CPLACE_H_BOSS          = 98,
    AV_CPLACE_MAX             = 321 // used by Battleground.cpp:1615
};

//x, y, z, o
const float BG_AV_CreaturePos[AV_CPLACE_MAX][4] =
{
    //spiritguides
    {643.000000f, 44.000000f, 69.740196f, -0.001854f},
    {676.000000f, -374.000000f, 30.000000f, -0.001854f},
    {73.417755f, -496.433105f, 48.731918f, -0.001854f},
    {-157.409195f, 31.206272f, 77.050598f, -0.001854f},
    {-531.217834f, -405.231384f, 49.551376f, -0.001854f},
    {-1090.476807f, -253.308670f, 57.672371f, -0.001854f},
    {-1496.065063f, -333.338409f, 101.134804f, -0.001854f},
    {873.001770f, -491.283630f, 96.541931f, -0.001854f},
    {-1437.670044f, -610.088989f, 51.161900f, -0.001854f},
    //grave
    //firstaid
    {635.17f, -29.5594f, 46.5056f, 4.81711f},
    {642.488f, -32.9437f, 46.365f, 4.67748f},
    {642.326f, -27.9442f, 46.9211f, 4.59022f},
    {635.945f, -33.6171f, 45.7164f, 4.97419f},
    //stormpike
    {669.272f, -297.304f, 30.291f, 4.66604f},
    {674.08f, -292.328f, 30.4817f, 0.0918785f},
    {667.01f, -288.532f, 29.8809f, 1.81583f},
    {664.153f, -294.042f, 30.2851f, 3.28531f},
    //stone
    {81.7027f, -406.135f, 47.7843f, 0.598464f},
    {78.1431f, -409.215f, 48.0401f, 5.05953f},
    {73.4135f, -407.035f, 46.7527f, 3.34736f},
    {78.2258f, -401.859f, 46.4202f, 2.05852f},
    //snowfall
    {-207.412f, -110.616f, 78.7959f, 2.43251f},
    {-197.95f, -112.205f, 78.5686f, 6.22441f},
    {-202.709f, -116.829f, 78.4358f, 5.13742f},
    {-202.059f, -108.314f, 78.5783f, 5.91968f},
    //ice
    {-615.501f, -393.802f, 60.4299f, 3.06147f},
    {-608.513f, -392.717f, 62.5724f, 2.06323f},
    {-609.769f, -400.072f, 60.7174f, 5.22367f},
    {-616.093f, -398.293f, 60.5628f, 3.73613f},
    //frost
    {-1077.7f, -340.21f, 55.4682f, 6.25569f},
    {-1082.74f, -333.821f, 54.7962f, 2.05459f},
    {-1090.66f, -341.267f, 54.6768f, 3.27746f},
    {-1081.58f, -344.63f, 55.256f, 4.75636f},
    //frost hut
    {-1408.95f, -311.69f, 89.2536f, 4.49954f},
    {-1407.15f, -305.323f, 89.1993f, 2.86827f},
    {-1400.64f, -304.3f, 89.7008f, 1.0595f},
    {-1400.4f, -311.35f, 89.3028f, 4.99434f},

    //towers
    //dun south - OK
    {569.395f, -101.064f, 52.8296f, 2.34974f},
    {574.85f, -92.9842f, 52.5869f, 3.09325f},
    {575.411f, -83.597f, 52.3626f, 6.26573f},
    {571.352f, -75.6582f, 52.479f, 0.523599f},
    //dun north - OK
    {667.69f, -121.761f, 64.1092f, 2.20377f},
    {662.253f, -129.105f, 64.1794f, 2.77507f},
    {661.209f, -138.877f, 64.2251f, 3.38594f},
    {665.481f, -146.857f, 64.1271f, 3.75246f},
    //icewing - OK
    {226.311f, -369.188f, 57.0509f, 5.98648f},
    {191.36f, -369.899f, 57.1524f, 3.24631f},
    {215.518f, -384.019f, 56.9889f, 5.09636f},
    {199.625f, -382.177f, 56.8691f, 4.08407f},
    //stone
    {-173.069f, -452.949f, 40.9205f, 3.56047f},
    {-147.147f, -435.053f, 40.8022f, 0.599238f},
    {-169.456f, -440.325f, 40.985f, 2.59101f},
    {-163.494f, -434.904f, 41.0725f, 1.84174f},
    //ice - OK
    {-573.522f, -271.854f, 75.0078f, 3.9619f},
    {-567.196f, -271.165f, 74.9134f, 5.41924f},
    {-562.825f, -261.087f, 74.9898f, 5.95157f},
    {-569.176f, -254.446f, 74.8771f, 0.820305f},
    //towerpoint
    {-758.104f, -365.919f, 90.8358f, 0.063601f},
    {-760.438f, -356.17f, 90.8438f, 0.957386f},
    {-767.344f, -352.763f, 90.8165f, 1.11133f},
    {-773.643f, -354.978f, 90.8773f, 2.54818f},
    //frost etower
    {-1292.46f, -312.373f, 107.328f, 0.535681f},
    {-1306.5f, -308.105f, 113.767f, 1.78755f},
    {-1293.16f, -320.646f, 113.801f, 6.13792f},
    {-1292.84f, -311.935f, 113.793f, 0.467349f},
    //frost wtower
    {-1304.28f, -275.276f, 114.092f, 4.35111f},
    {-1286.5f, -261.676f, 114.114f, 0.606364f},
    {-1284.87f, -269.481f, 114.13f, 6.11275f},
    {-1296.47f, -277.717f, 114.067f, 5.36427f},

    //alliance marshall
    {721.104f, -7.64155f, 50.7046f, 3.45575f}, // south
    {723.058f, -14.1548f, 50.7046f, 3.40339f}, // north
    {715.691f, -4.72233f, 50.2187f, 3.47321f}, // icewing
    {720.046f, -19.9413f, 50.2187f, 3.36849f}, // stone
    //horde  (coords not 100% ok)
    {-1363.99f, -221.99f, 98.4053f, 4.93012f},
    {-1370.96f, -223.532f, 98.4266f, 4.93012f},
    {-1378.37f, -228.614f, 99.3546f, 5.38565f},
    {-1358.02f, -228.998f, 98.868f, 3.87768f},

    // Morloch
    {865.554f, -438.735f, 50.7333f, 2.12431f}, // 77
    // Snivvle
    {-848.902f, -92.931f, 68.6325f, 3.33350f}, // 78

    // Stormpike herald
    {-48.459f, -288.802f, 55.47f, 1.0f}, // 79

    //triggers
    { 637.083f, -32.6603f, 45.9715f, 1.14353f },     // firstaid_station
    { 669.007f, -294.078f, 30.2909f, 2.77507f },     // stormpike_grave
    { 77.8013f, -404.7f, 46.7549f, -0.872665f },     // stoneheart_grave
    { -202.581f, -112.73f, 78.4876f, -0.715585f },   // snowfall_grave
    { -611.962f, -396.17f, 60.8351f, 2.53682f },     // iceblood_grave
    { -1082.45f, -346.823f, 54.9219f, -1.53589f },   // frostwolf_grave
    { -1402.21f, -307.431f, 89.4424f, 0.191986f },   // frostwolf_hut
    { 553.779f, -78.6566f, 51.9378f, -1.22173f },    // dunbaldar_south
    { 674.001f, -143.125f, 63.6615f, 0.994838f },    // dunbaldar_north
    { 203.281f, -360.366f, 56.3869f, -0.925024f },   // icewing_bunker
    { -152.437f, -441.758f, 40.3982f, -1.95477f },   // stoneheart_bunker
    { -571.88f, -262.777f, 75.0087f, -0.802851f },   // iceblood_tower
    { -768.907f, -363.71f, 90.8949f, 1.07991f },     // tower_point
    { -1302.9f, -316.981f, 113.867f, 2.00713f },     // frostwolf_etower
    { -1297.5f, -266.767f, 114.15f, 3.31044f },      // frostwolf_wtower
    { -57.7891f, -286.597f, 15.6479f, 6.02139f },    // AV_NPC_A_CAPTAIN balinda 95
    { 722.43f, -10.9982f, 50.7046f, 3.42085f },      // AV_NPC_A_BOSS vanndar 96
    { -545.23f, -165.35f, 57.7886f, 5.88342f },      // AV_NPC_H_CAPTAIN galvangar 97
    { -1370.9f, -219.793f, 98.4258f, 5.04381f }      // AV_NPC_H_BOSS drek thar 98
};

enum BG_AV_CreatureIds
{
    AV_NPC_A_GRAVEDEFENSE0  = 0,     // Stormpike defender
    AV_NPC_A_GRAVEDEFENSE1  = 1,     // Seasoned defender
    AV_NPC_A_GRAVEDEFENSE2  = 2,     // Veteran defender
    AV_NPC_A_GRAVEDEFENSE3  = 3,     // Champion defender
    AV_NPC_A_TOWERDEFENSE   = 4,     // Stormpike bowman
    AV_NPC_A_CAPTAIN        = 5,     // Balinda
    AV_NPC_A_BOSS           = 6,     // Vanndar

    AV_NPC_H_GRAVEDEFENSE0  = 7,     // Frostwolf guardian
    AV_NPC_H_GRAVEDEFENSE1  = 8,     // Seasoned guardian
    AV_NPC_H_GRAVEDEFENSE2  = 9,     // Veteran guardian
    AV_NPC_H_GRAVEDEFENSE3  = 10,    // Champion guardian
    AV_NPC_H_TOWERDEFENSE   = 11,    // Frostwolf bowman
    AV_NPC_H_CAPTAIN        = 12,    // Galvangar
    AV_NPC_H_BOSS           = 13,    // Drek thar

    AV_NPC_A_MARSHAL_SOUTH  = 14,
    AV_NPC_MARSHAL_NORTH    = 15,
    AV_NPC_A_MARSHAL_ICE    = 16,
    AV_NPC_A_MARSHAL_STONE  = 17,
    AV_NPC_H_MARSHAL_ICE    = 18,
    AV_NPC_H_MARSHAL_TOWER  = 19,
    AV_NPC_MARSHAL_ETOWER   = 20,
    AV_NPC_H_MARSHAL_WTOWER = 21,

    AV_NPC_N_MINE_N_4       = 22, // boss = Morloch
    AV_NPC_N_MINE_A_4       = 23,
    AV_NPC_N_MINE_H_4       = 24,
    AV_NPC_S_MINE_N_4       = 25, // boss = Snivvle
    AV_NPC_S_MINE_A_4       = 26,
    AV_NPC_S_MINE_H_4       = 27,

    AV_NPC_HERALD           = 28,
    AV_NPC_INFO_MAX         = 30
};

const uint32 BG_AV_CreatureInfo[AV_NPC_INFO_MAX] =
{
    12050, // Stormpike Defender
    13326, // Seasoned Defender
    13331, // Veteran Defender
    13422, // Champion Defender
    13358, // Stormpike Bowman /// @todo: Confirm if this is correct. Author assumpted 60, 61 & 69, 70, but wouldn't work here
    11949, // not spawned with this data, but used for handlekillunit
    11948, // not spawned with this data, but used for handlekillunit
    12053, // Frostwolf Guardian
    13328, // Seasoned Guardian
    13332, // Veteran Guardian
    13421, // Champion Guardian
    13359, // Frostwolf Bowman
    11947, // not spawned with this data, but used for handlekillunit
    11946, // not spawned with this data, but used for handlekillunit

    14763, // Dun Baldar South Marshal 14
    14762, // Dun Baldar North Marshal 15
    14764, // Icewing Marshal 16
    14765, // Stonehearth Marshal 17
    14773, // Iceblood Warmaster 18
    14776, // Tower Point Warmaster 19
    14772, // East Frostwolf Warmaster 20
    14777, // West Frostwolf Warmaster 21

    11657, // Morloch 22
    13078, // Umi Thorson 23
    13079, // Keetar 24
    11677, // Taskmaster Snivvle 25
    13086, // Aggi Rumblestomp 26
    13088, // Masha Swiftcut 27
    14848, // Stormpike Herald 28
    11998  // Frostwolf Herald 29
};

//x, y, z, o, static_creature_info-id
const float BG_AV_StaticCreaturePos[AV_STATICCPLACE_MAX][5] = // 157
{
    //static creatures
    { -1235.31f, -340.777f, 60.5088f, 3.31613f, 0 }, // 2225 - Zora Guthrek
    { -1244.02f, -323.795f, 61.0485f, 5.21853f, 1 }, // 3343 - Grelkor
    { -1235.16f, -332.302f, 60.2985f, 2.96706f, 2 }, // 3625 - Rarck
    { 587.303f, -42.8257f, 37.5615f, 5.23599f, 3 },  // 4255 - Brogus Thunderbrew
    { 643.635f, -58.3987f, 41.7405f, 4.72984f, 4 },  // 4257 - Lana Thunderbrew
    { 591.464f, -44.452f, 37.6166f, 5.65487f, 5 },   // 5134 - Jonivera Farmountain
    { 608.515f, -33.3935f, 42.0003f, 5.41052f, 6 },  // 5135 - Svalbrad Farmountain
    { 617.656f, -32.0701f, 42.7168f, 4.06662f, 7 },  // 5139 - Kurdrum Barleybeard
    { -1183.76f, -268.295f, 72.8233f, 3.28122f, 8 }, // 10364 - Yaelika Farclaw
    { -1187.86f, -275.31f, 73.0481f, 3.63028f, 9 },  // 10367 - Shrye Ragefist

    { -1008.42f, -368.006f, 55.3426f, 5.95647f, 10 }, // 10981 - Frostwolf
    { -1091.92f, -424.28f, 53.0139f, 2.93958f, 10 },
    { -558.455f, -198.768f, 58.1755f, 4.97946f, 10 },
    { -861.247f, -312.51f, 55.1427f, 3.35382f, 10 },
    { -1003.81f, -395.913f, 50.4736f, 2.85631f, 10 },
    { -904.5f, -289.815f, 65.1222f, 5.7847f, 10 },
    { -1064.41f, -438.839f, 51.3614f, 1.88857f, 10 },
    { -1247.43f, -467.047f, 49.968f, 5.74599f, 10 },
    { -857.527f, -463.559f, 47.8953f, 0.262911f, 10 },
    { -426.1f, -132.265f, 24.4058f, 1.58416f, 10 },
    { -1131.61f, -557.472f, 51.605f, 0.126462f, 10 },
    { -964.682f, -472.82f, 43.4782f, 0.554507f, 10 },
    { -1207.55f, -546.59f, 52.184f, 0.663117f, 10 },
    { -380.387f, -123.127f, 25.7814f, 0.329259f, 10 },
    { -1048.64f, -496.647f, 45.477f, 5.87303f, 10 },
    { -1316.4f, -517.62f, 52.4308f, 2.97414f, 10 },
    { -1094.51f, -336.004f, 54.6334f, 3.63206f, 10 },
    { -482.274f, -188.655f, 55.7734f, 0.527763f, 10 },

    { 295.183f, -299.908f, -34.6123f, 0.135851f, 11 }, // 10990 - Alterac Ram
    { 421.08f, -225.006f, -23.73f, 0.166754f, 11 },
    { -55.7766f, -192.498f, 20.4352f, 6.12221f, 11 },
    { 527.887f, -477.223f, 62.3559f, 0.170935f, 11 },
    { 389.144f, -346.508f, -30.334f, 4.14117f, 11 },
    { 108.121f, -322.248f, 37.5655f, 4.46788f, 11 },
    { 507.479f, -67.9403f, 10.3571f, 3.26304f, 11 },
    { 329.071f, -185.016f, -29.1542f, 0.356943f, 11 },
    { 252.449f, -422.313f, 35.1404f, 4.53771f, 11 },
    { 358.882f, -118.061f, -24.9119f, 2.29257f, 11 },
    { 487.151f, -174.229f, 14.7558f, 4.73192f, 11 },
    { 449.652f, -123.561f, 6.14273f, 6.12029f, 11 },
    { 272.419f, -261.802f, -41.8835f, 3.66559f, 11 },
    { 359.021f, -210.954f, -29.3483f, 4.31339f, 11 },
    { 450.598f, -318.048f, -37.7548f, 0.655219f, 11 },
    { 509.333f, -218.2f, 3.05439f, 3.66292f, 11 },
    { 485.771f, -223.613f, -1.53f, 2.04862f, 11 },
    { 486.636f, -452.172f, 39.6592f, 2.3341f, 11 },
    { 702.783f, -257.494f, 25.9777f, 1.68329f, 11 },
    { 460.942f, -199.263f, -6.0149f, 0.380506f, 11 },
    { 483.108f, -115.307f, 10.1056f, 3.69701f, 11 },
    { 471.601f, -154.174f, 14.0702f, 5.5807f, 11 },
    { 213.938f, -420.793f, 41.2549f, 5.71394f, 11 },
    { 289.387f, -294.685f, -33.9073f, 0.555494f, 11 },
    { 155.649f, -402.891f, 43.3915f, 5.94838f, 11 },
    { 517.184f, -295.105f, -9.78195f, 6.05668f, 11 },
    { 102.334f, -332.165f, 38.9812f, 3.31445f, 11 },
    { 320.244f, -107.793f, -42.6357f, -1.00311f, 11 },
    { -117.881f, -382.485f, 13.0603f, 2.36797f, 11 },
    { 712.271f, -260.598f, 32.0573f, 4.07736f, 11 },
    { 451.194f, -27.318f, 2.00197f, 5.04229f, 11 },
    { 660.363f, -237.317f, 1.27207f, 3.36749f, 11 },
    { 324.463f, -39.0641f, -20.374f, 5.82304f, 11 },
    { 520.208f, -206.343f, 4.18313f, 3.44021f, 11 },
    { 478.74f, -119.655f, 10.2513f, 0.571001f, 11 },

    { -545.23f, -165.35f, 57.7886f, 5.88342f, 12 },   // 11947 - Captain Galvangar
    { 722.43f, -10.9982f, 50.7046f, 3.42085f, 13 },   // 11948 - Vanndar Stormpike
    { -57.7891f, -286.597f, 15.6479f, 6.02139f, 14 }, // 11949 - Captain Balinda Stonehearth
    { -1370.9f, -219.793f, 98.4258f, 5.04381f, 15 },  // Drek'Thar

    { -554.933, -174.876, 57.9563, 0.465655, 16 },    // 12051 - Frostwolf Legionnaire
    { -536.28, -182.784, 57.9519, 4.85222, 16 },
    { -524.859, -159.15, 57.9469, 0.461474, 16 },
    { -555.052, -160.853, 57.9569, 5.95878, 16 },
    { -1270.72, -377.97, 59.7391, 2.88398, 16 },
    { -1277.23, -382.593, 59.7737, 1.42314, 16 },
    { -1158.65, -356.721, 51.8624, 0.653446, 16 },
    { -1160.14, -348.657, 51.9633, 5.84885, 16 },
    { -1344.15, -285.235, 91.1315, 4.99109, 16 },
    { -1352.83, -288.236, 91.151, 5.01072, 16 },

    { 587.633f, -45.9816f, 37.5438f, 5.81195f, 17 },  // 12096 - Stormpike Quartermaster
    { -1293.79f, -194.407f, 72.4398f, 5.84685f, 18 }, // 12097 - Frostwolf Quartermaster
    { -1251.5f, -316.327f, 62.6565f, 5.02655f, 20 },  // 13176 - Smith Regzar
    { 569.983f, -94.9992f, 38.0325f, 1.39626f, 21 },  // 13216 - Gaelden Hammersmith
    { -1244.92f, -308.916f, 63.2525f, 1.62316f, 22 }, // 13218 - Grunnda Wolfheart
    { -1319.56f, -342.675f, 60.3404f, 1.20428f, 23 }, // 13236 - Primalist Thurloga
    { 647.61f, -61.1548f, 41.7405f, 4.24115f, 24 },   // 13257 - Murgot Deepforge
    { -1321.64f, -343.73f, 60.4833f, 1.01229f, 25 },  // 13284 - Frostwolf Shaman
    { -1317.61f, -342.853f, 60.3726f, 2.47837f, 25 }, // 13284 - Frostwolf Shaman
    { -1319.31f, -344.475f, 60.3825f, 1.72788f, 25 }, // 13284 - Frostwolf Shaman
    { 729.2f, -78.812f, 51.6335f, 3.97935f, 26 },     // 13442 - Arch Druid Renferal
    { 729.118f, -82.8713f, 51.6335f, 2.53073f, 27 },  // 13443 - Druid of the Grove
    { 725.554f, -79.4973f, 51.6335f, 5.27089f, 27 },  // 13443 - Druid of the Grove
    { 724.768f, -84.1642f, 51.6335f, 0.733038f, 27 }, // 13443 - Druid of the Grove
    { 596.68f, -83.0633f, 39.0051f, 6.24828f, 28 },   // 13447 - Corporal Noreg Stormpike
    { -1212.11, -261.774, 73.4561, 5.79449, 29 },     // 13448 - Sergeant Yazra Bloodsnarl

    { 600.032f, -2.92475f, 42.0788f, 5.00909f, 30 },  // 13577 - Stormpike Ram Rider Commander
    { 610.239f, -21.8454f, 43.272f, 4.90438f, 31 },   // 13617 - Stormpike Stable Master
    { -1250.35f, -633.115f, 52.5533f, 0.8166f, 32 },  // 13441 - Frostwolf Wolf Rider Commander
    { -1245.6f, -638.91f, 52.5509f, 2.20837f, 33 },   // 13616 - Frostwolf Stable Master

    { 613.422f, -150.764f, 33.4517f, 5.55015f, 34 },  // 13797 - Mountaineer Boombellow
    { -1213.91f, -370.619f, 56.4455f, 0.83775f, 35 }, // 13798 - Jotek
    { 704.35f, -22.9071f, 50.2187f, 0.785398f, 36 },  // 13816 - Prospector Stonehewer
    { -1271.24f, -335.766f, 62.3971f, 5.75959f, 37 }, // 14185 - Najak Hexxen
    { -1268.64f, -332.688f, 62.6171f, 5.28835f, 38 }, // 14186 - Ravak Grimtotem
    { 648.363f, -65.2233f, 41.7405f, 3.12414f, 39 },  // 14187 - Athramanis
    { 648.238f, -67.8931f, 41.7405f, 2.60054f, 40 },  // 14188 - Dirk Swindle

    { 947.412f, -509.982f, 95.1098f, 2.82743f, 41 },  // 14284 - Stormpike Battleguard
    { 939.42f, -502.777f, 94.5887f, 5.14872f, 41 },
    { 775.204f, -485.476f, 98.9171f, 3.92814f, 41 },
    { 773.874f, -498.323f, 99.2116f, 2.07412f, 41 },
    { 949.1f, -506.913f, 95.4237f, 3.31613f, 41 },
    { 817.485, -490.792, 100.378, 4.59828, 41 },
    { 866.648, -508.062, 96.5076, 2.27371, 41 },
    { 831.333, -501.877, 99.4178, 1.95956, 41 },
    { 884.38, -498.876, 96.8023, 3.73063, 41 },
    { 934.73, -519.521, 93.7814, 2.04571, 41 },
    { 876.666, -503.852, 96.7068, 0.0349066, 41 },
    { 775.774, -497.052, 99.3424, 2.37663, 41 },

    { -1365.56, -538.226, 53.9421, 1.98592, 42 },     // 14285 - Frostwolf Battleguard
    { -1368.25, -539.219, 54.784, 1.98592, 42 },
    { -1375.4, -532.951, 55.0778, 5.86971, 42 },
    { -1373.95, -530.154, 54.149, 5.76368, 42 },
    { -1399.38, -567.073, 55.5308, 2.43173, 42 },
    { -1414.77, -569.933, 54.5418, 5.5851, 42 },
    { -1424.83, -598.609, 51.5926, 3.05734, 42 },
    { -1424.62, -595.707, 51.6422, 3.2851, 42 },
    { -1443.08, -595.506, 51.1825, 0.363418, 42 },
    { -1445.25, -591.668, 51.2814, 6.27423, 42 },
    { -1448.25, -614.268, 51.3558, 1.13232, 42 },
    { -1448.13, -601.626, 51.2171, 5.00434, 42 },
    { -1486.72, -655.177, 49.0348, 3.65387, 42 },
    { -1496.52, -664.84, 49.5705, 6.23783, 42 },
    { -1491.89, -682.146, 47.7207, 0.553317, 42 },
    { -1481.69, -676.03, 48.8492, 3.27473, 42 },
    { -1501.71, -712.99, 47.723, 1.87672, 42 },
    { -1506.73, -706.163, 47.6816, 5.89403, 42 },
    { -1503.16, -714.369, 48.1781, 1.62146, 42 },
    { -1508.63, -708.495, 48.0974, 5.7825, 42 },

    { 930.498f, -520.755f, 93.7334f, 1.8326f, 43 },   // 11997 - Stormpike Herald
    { -1484.1, -699.444, 47.0265, 2.64916, 44 },      // 11998 - Frostwolf Herald

    { -1332.0f, -331.243f, 91.2631f, 1.50098f, 45 },  // 13179 - Wing Commander Guse
    { -1335.97f, -328.918f, 90.9113f, 1.01474f, 46 }, // 13179 - Wing Commander Jeztor
    { -1339.39f, -326.361f, 90.7439f, 0.85002f, 47 }, // 13179 - Wing Commander Mulverick
    { 571.382f, -52.5525f, 38.1889f, 0.579624f, 48 }, // 13437 - Wing Commander Ichman
    { 572.7764f, -41.2713f, 37.6083f, 4.5694f, 49 },  // 13438 - Wing Commander Slidore
    { 568.903f, -49.0058f, 38.4363f, 0.279571f, 50 }, // 13438 - Wing Commander Vipore
};

const uint32 BG_AV_StaticCreatureInfo[51] =
{
    2225,  // Zora Guthrek
    3343,  // Grelkor
    3625,  // Rarck
    4255,  // Brogus Thunderbrew
    4257,  // Lana Thunderbrew
    5134,  // Jonivera Farmountain
    5135,  // Svalbrad Farmountain
    5139,  // Kurdrum Barleybeard
    10364, // Yaelika Farclaw
    10367, // Shrye Ragefist
    10981, // Frostwolf
    10990, // Alterac Ram
    11947, // Captain Galvangar
    11948, // Vanndar Stormpike
    11949, // Captain Balinda Stonehearth
    11946, // Drek'Thar
    12051, // Frostwolf Legionnaire
    12096, // Stormpike Quartermaster
    12097, // Frostwolf Quartermaster
    12127, // Stormpike Guardsman
    13176, // Smith Regzar
    13216, // Gaelden Hammersmith
    13218, // Grunnda Wolfheart
    13236, // Primalist Thurloga
    13257, // Murgot Deepforge
    13284, // Frostwolf Shaman
    13442, // Arch Druid Renferal
    13443, // Druid of the Grove
    13447, // Corporal Noreg Stormpike
    13448, // Sergeant Yazra Bloodsnarl
    13577, // Stormpike Ram Rider Commander
    13617, // Stormpike Stable Master
    13441, // Frostwolf Wolf Rider Commander
    13616, // Frostwolf Stable Master
    13797, // Mountaineer Boombellow
    13798, // Jotek
    13816, // Prospector Stonehewer
    14185, // Najak Hexxen
    14186, // Ravak Grimtotem
    14187, // Athramanis
    14188, // Dirk Swindle
    14284, // Stormpike Battleguard
    14285, // Frostwolf Battleguard
    11997, // Stormpike Herald
    11998, // Frostwolf Herald
    13179, // Wing Commander Guse
    13180, // Wing Commander Jeztor
    13181, // Wing Commander Mulverick
    13437, // Wing Commander Ichman
    13438, // Wing Commander Slidore
    13439, // Wing Commander Vipore
};

enum BG_AV_Graveyards
{
    AV_GRAVE_STORM_AID         = 751,
    AV_GRAVE_STORM_GRAVE       = 689,
    AV_GRAVE_STONE_GRAVE       = 729,
    AV_GRAVE_SNOWFALL          = 169,
    AV_GRAVE_ICE_GRAVE         = 749,
    AV_GRAVE_FROSTWOLF         = 690,
    AV_GRAVE_FROST_HUT         = 750,
    AV_GRAVE_MAIN_ALLIANCE     = 611,
    AV_GRAVE_MAIN_HORDE        = 610
};

const uint32 BG_AV_GraveyardIds[9] =
{
    AV_GRAVE_STORM_AID,
    AV_GRAVE_STORM_GRAVE,
    AV_GRAVE_STONE_GRAVE,
    AV_GRAVE_SNOWFALL,
    AV_GRAVE_ICE_GRAVE,
    AV_GRAVE_FROSTWOLF,
    AV_GRAVE_FROST_HUT,
    AV_GRAVE_MAIN_ALLIANCE,
    AV_GRAVE_MAIN_HORDE
};

enum BG_AV_BUFF
{
    //TODO add all other buffs here
    AV_BUFF_ARMOR     = 21163,
    AV_BUFF_A_CAPTAIN = 23693, // the buff which the alliance captain does
    AV_BUFF_H_CAPTAIN = 22751  // the buff which the horde captain does
};

enum BG_AV_States
{
    POINT_NEUTRAL              =  0,
    POINT_ASSAULTED            =  1,
    POINT_DESTROYED            =  2,
    POINT_CONTROLLED           =  3
};

//alliance_control neutral_control horde_control
const uint32 BG_AV_MineWorldStates[2][3] =
{
    { WORLD_STATE_BATTLEGROUND_AV_N_MINE_A, WORLD_STATE_BATTLEGROUND_AV_N_MINE_N, WORLD_STATE_BATTLEGROUND_AV_N_MINE_H },
    { WORLD_STATE_BATTLEGROUND_AV_S_MINE_A, WORLD_STATE_BATTLEGROUND_AV_S_MINE_N, WORLD_STATE_BATTLEGROUND_AV_S_MINE_H }
};

//alliance_control alliance_assault h_control h_assault
const uint32 BG_AV_NodeWorldStates[16][4] =
{
    //Stormpike first aid station
    {WORLD_STATE_BATTLEGROUND_AV_AID_A_C, WORLD_STATE_BATTLEGROUND_AV_AID_A_A, WORLD_STATE_BATTLEGROUND_AV_AID_H_C, WORLD_STATE_BATTLEGROUND_AV_AID_H_A},
    //Stormpike Graveyard
    {WORLD_STATE_BATTLEGROUND_AV_PIKEGRAVE_A_C, WORLD_STATE_BATTLEGROUND_AV_PIKEGRAVE_A_A, WORLD_STATE_BATTLEGROUND_AV_PIKEGRAVE_H_C, WORLD_STATE_BATTLEGROUND_AV_PIKEGRAVE_H_A},
    //Stoneheart Grave
    {WORLD_STATE_BATTLEGROUND_AV_STONEHEART_A_C, WORLD_STATE_BATTLEGROUND_AV_STONEHEART_A_A, WORLD_STATE_BATTLEGROUND_AV_STONEHEART_H_C, WORLD_STATE_BATTLEGROUND_AV_STONEHEART_H_A},
    //Snowfall Grave
    {WORLD_STATE_BATTLEGROUND_AV_SNOWFALL_A_C, WORLD_STATE_BATTLEGROUND_AV_SNOWFALL_A_A, WORLD_STATE_BATTLEGROUND_AV_SNOWFALL_H_C, WORLD_STATE_BATTLEGROUND_AV_SNOWFALL_H_A},
    //Iceblood grave
    {WORLD_STATE_BATTLEGROUND_AV_ICEBLOOD_A_C, WORLD_STATE_BATTLEGROUND_AV_ICEBLOOD_A_A, WORLD_STATE_BATTLEGROUND_AV_ICEBLOOD_H_C, WORLD_STATE_BATTLEGROUND_AV_ICEBLOOD_H_A},
    //Frostwolf Grave
    {WORLD_STATE_BATTLEGROUND_AV_FROSTWOLF_A_C, WORLD_STATE_BATTLEGROUND_AV_FROSTWOLF_A_A, WORLD_STATE_BATTLEGROUND_AV_FROSTWOLF_H_C, WORLD_STATE_BATTLEGROUND_AV_FROSTWOLF_H_A},
    //Frostwolf Hut
    {WORLD_STATE_BATTLEGROUND_AV_FROSTWOLFHUT_A_C, WORLD_STATE_BATTLEGROUND_AV_FROSTWOLFHUT_A_A, WORLD_STATE_BATTLEGROUND_AV_FROSTWOLFHUT_H_C, WORLD_STATE_BATTLEGROUND_AV_FROSTWOLFHUT_H_A},
    //Dunbaldar South Bunker
    {WORLD_STATE_BATTLEGROUND_AV_DUNS_CONTROLLED, WORLD_STATE_BATTLEGROUND_AV_DUNS_UNUSED, WORLD_STATE_BATTLEGROUND_AV_DUNS_DESTROYED, WORLD_STATE_BATTLEGROUND_AV_DUNS_ASSAULTED},
    //Dunbaldar North Bunker
    {WORLD_STATE_BATTLEGROUND_AV_DUNN_CONTROLLED, WORLD_STATE_BATTLEGROUND_AV_DUNN_UNUSED, WORLD_STATE_BATTLEGROUND_AV_DUNN_DESTROYED, WORLD_STATE_BATTLEGROUND_AV_DUNN_ASSAULTED},
    //Icewing Bunker
    {WORLD_STATE_BATTLEGROUND_AV_ICEWING_CONTROLLED, WORLD_STATE_BATTLEGROUND_AV_ICEWING_UNUSED, WORLD_STATE_BATTLEGROUND_AV_ICEWING_DESTROYED, WORLD_STATE_BATTLEGROUND_AV_ICEWING_ASSAULTED},
    //Stoneheart Bunker
    {WORLD_STATE_BATTLEGROUND_AV_STONEH_CONTROLLED, WORLD_STATE_BATTLEGROUND_AV_STONEH_UNUSED, WORLD_STATE_BATTLEGROUND_AV_STONEH_DESTROYED, WORLD_STATE_BATTLEGROUND_AV_STONEH_ASSAULTED},
    //Iceblood Tower
    {WORLD_STATE_BATTLEGROUND_AV_ICEBLOOD_DESTROYED, WORLD_STATE_BATTLEGROUND_AV_ICEBLOOD_ASSAULTED, WORLD_STATE_BATTLEGROUND_AV_ICEBLOOD_CONTROLLED, WORLD_STATE_BATTLEGROUND_AV_ICEBLOOD_UNUSED},
    //Tower Point
    {WORLD_STATE_BATTLEGROUND_AV_TOWERPOINT_DESTROYED, WORLD_STATE_BATTLEGROUND_AV_TOWERPOINT_ASSAULTED, WORLD_STATE_BATTLEGROUND_AV_TOWERPOINT_CONTROLLED, WORLD_STATE_BATTLEGROUND_AV_TOWERPOINT_UNUSED},
    //Frostwolf East
    {WORLD_STATE_BATTLEGROUND_AV_FROSTWOLFE_DESTROYED, WORLD_STATE_BATTLEGROUND_AV_FROSTWOLFE_ASSAULTED, WORLD_STATE_BATTLEGROUND_AV_FROSTWOLFE_CONTROLLED, WORLD_STATE_BATTLEGROUND_AV_FROSTWOLFE_UNUSED},
    //Frostwolf West
    {WORLD_STATE_BATTLEGROUND_AV_FROSTWOLFW_DESTROYED, WORLD_STATE_BATTLEGROUND_AV_FROSTWOLFW_ASSAULTED, WORLD_STATE_BATTLEGROUND_AV_FROSTWOLFW_CONTROLLED, WORLD_STATE_BATTLEGROUND_AV_FROSTWOLFW_UNUSED},
};

enum BG_AV_QuestIds
{
    AV_QUEST_A_SCRAPS1      = 7223,
    AV_QUEST_A_SCRAPS2      = 6781,
    AV_QUEST_H_SCRAPS1      = 7224,
    AV_QUEST_H_SCRAPS2      = 6741,
    AV_QUEST_A_COMMANDER1   = 6942, // soldier
    AV_QUEST_H_COMMANDER1   = 6825,
    AV_QUEST_A_COMMANDER2   = 6941, // lieutenant
    AV_QUEST_H_COMMANDER2   = 6826,
    AV_QUEST_A_COMMANDER3   = 6943, // commander
    AV_QUEST_H_COMMANDER3   = 6827,
    AV_QUEST_A_BOSS1        = 7386, // 5 cristal/blood
    AV_QUEST_H_BOSS1        = 7385,
    AV_QUEST_A_BOSS2        = 6881, // 1
    AV_QUEST_H_BOSS2        = 6801,
    AV_QUEST_A_NEAR_MINE    = 5892, // the mine near start location of team
    AV_QUEST_H_NEAR_MINE    = 5893,
    AV_QUEST_A_OTHER_MINE   = 6982, // the other mine ;)
    AV_QUEST_H_OTHER_MINE   = 6985,
    AV_QUEST_A_RIDER_HIDE   = 7026,
    AV_QUEST_H_RIDER_HIDE   = 7002,
    AV_QUEST_A_RIDER_TAME   = 7027,
    AV_QUEST_H_RIDER_TAME   = 7001
};

enum BG_AV_Objectives
{
    AV_OBJECTIVE_ASSAULT_TOWER      = 61,
    AV_OBJECTIVE_ASSAULT_GRAVEYARD  = 63,
    AV_OBJECTIVE_DEFEND_TOWER       = 64,
    AV_OBJECTIVE_DEFEND_GRAVEYARD   = 65
};

enum BG_AV_HERALD
{
    AV_TEXT_A_HERALD_STORMPIKE_GRAVEYARD_TAKEN    = 1,
    AV_TEXT_A_HERALD_STORMPIKE_GRAVEYARD_ATTACK   = 2,
    AV_TEXT_H_HERALD_STORMPIKE_GRAVEYARD_TAKEN    = 3,
    AV_TEXT_H_HERALD_STORMPIKE_GRAVEYARD_ATTACK   = 4,
    AV_TEXT_A_HERALD_SNOWFALL_GRAVEYARD_TAKEN     = 5,
    AV_TEXT_A_HERALD_SNOWFALL_GRAVEYARD_ATTACK    = 6,
    AV_TEXT_H_HERALD_SNOWFALL_GRAVEYARD_TAKEN     = 7,
    AV_TEXT_H_HERALD_SNOWFALL_GRAVEYARD_ATTACK    = 8,
    AV_TEXT_A_HERALD_FROSTWOLF_GRAVEYARD_TAKEN    = 9,
    AV_TEXT_A_HERALD_FROSTWOLF_GRAVEYARD_ATTACK   = 10,
    AV_TEXT_H_HERALD_FROSTWOLF_GRAVEYARD_TAKEN    = 11,
    AV_TEXT_H_HERALD_FROSTWOLF_GRAVEYARD_ATTACK   = 12,
    AV_TEXT_H_HERALD_DUN_BALDAR_SOUTH_ATTACK      = 13,
    AV_TEXT_H_HERALD_DUN_BALDAR_SOUTH_TAKEN       = 14,
    AV_TEXT_A_HERALD_DUN_BALDAR_SOUTH_ATTACK      = 15,
    AV_TEXT_A_HERALD_DUN_BALDAR_SOUTH_TAKEN       = 16,
    AV_TEXT_H_HERALD_DUN_BALDAR_NORTH_ATTACK      = 17,
    AV_TEXT_H_HERALD_DUN_BALDAR_NORTH_TAKEN       = 18,
    AV_TEXT_A_HERALD_DUN_BALDAR_NORTH_ATTACK      = 19,
    AV_TEXT_A_HERALD_DUN_BALDAR_NORTH_TAKEN       = 20,
    AV_TEXT_H_HERALD_ICEWING_BUNKER_ATTACK        = 21,
    AV_TEXT_H_HERALD_ICEWING_BUNKER_TAKEN         = 22,
    AV_TEXT_A_HERALD_ICEWING_BUNKER_ATTACK        = 23,
    AV_TEXT_A_HERALD_ICEWING_BUNKER_TAKEN         = 24,
    AV_TEXT_H_HERALD_STONEHEARTH_BUNKER_ATTACK    = 25,
    AV_TEXT_H_HERALD_STONEHEARTH_BUNKER_TAKEN     = 26,
    AV_TEXT_A_HERALD_STONEHEARTH_BUNKER_ATTACK    = 27,
    AV_TEXT_A_HERALD_STONEHEARTH_BUNKER_TAKEN     = 28,
    AV_TEXT_H_HERALD_WEST_FROSTWOLF_TOWER_ATTACK  = 29,
    AV_TEXT_H_HERALD_WEST_FROSTWOLF_TOWER_TAKEN   = 30,
    AV_TEXT_A_HERALD_WEST_FROSTWOLF_TOWER_ATTACK  = 31,
    AV_TEXT_A_HERALD_WEST_FROSTWOLF_TOWER_TAKEN   = 32,
    AV_TEXT_H_HERALD_EAST_FROSTWOLF_TOWER_ATTACK  = 33,
    AV_TEXT_H_HERALD_EAST_FROSTWOLF_TOWER_TAKEN   = 34,
    AV_TEXT_A_HERALD_EAST_FROSTWOLF_TOWER_ATTACK  = 35,
    AV_TEXT_A_HERALD_EAST_FROSTWOLF_TOWER_TAKEN   = 36,
    AV_TEXT_H_HERALD_TOWER_POINT_ATTACK           = 37,
    AV_TEXT_H_HERALD_TOWER_POINT_TAKEN            = 38,
    AV_TEXT_A_HERALD_TOWER_POINT_ATTACK           = 39,
    AV_TEXT_A_HERALD_TOWER_POINT_TAKEN            = 40,
    AV_TEXT_H_HERALD_ICEBLOOD_TOWER_ATTACK        = 41,
    AV_TEXT_H_HERALD_ICEBLOOD_TOWER_TAKEN         = 42,
    AV_TEXT_A_HERALD_ICEBLOOD_TOWER_ATTACK        = 43,
    AV_TEXT_A_HERALD_ICEBLOOD_TOWER_TAKEN         = 44,
    AV_TEXT_H_HERALD_STORMPIKE_AID_STATION_TAKEN  = 45,
    AV_TEXT_H_HERALD_STORMPIKE_AID_STATION_ATTACK = 46,
    AV_TEXT_A_HERALD_STORMPIKE_AID_STATION_TAKEN  = 47,
    AV_TEXT_A_HERALD_STORMPIKE_AID_STATION_ATTACK = 48,
    AV_TEXT_H_HERALD_FROSTWOLF_RELIEF_HUT_TAKEN   = 49,
    AV_TEXT_H_HERALD_FROSTWOLF_RELIEF_HUT_ATTACK  = 50,
    AV_TEXT_A_HERALD_FROSTWOLF_RELIEF_HUT_TAKEN   = 51,
    AV_TEXT_A_HERALD_FROSTWOLF_RELIEF_HUT_ATTACK  = 52,
    AV_TEXT_H_HERALD_STONEHEARTH_GRAVEYARD_TAKEN  = 53,
    AV_TEXT_H_HERALD_STONEHEARTH_GRAVEYARD_ATTACK = 54,
    AV_TEXT_A_HERALD_STONEHEARTH_GRAVEYARD_TAKEN  = 55,
    AV_TEXT_A_HERALD_STONEHEARTH_GRAVEYARD_ATTACK = 56,
    AV_TEXT_H_HERALD_ICEBLOOD_GRAVEYARD_TAKEN     = 57,
    AV_TEXT_H_HERALD_ICEBLOOD_GRAVEYARD_ATTACK    = 58,
    AV_TEXT_A_HERALD_ICEBLOOD_GRAVEYARD_TAKEN     = 59,
    AV_TEXT_A_HERALD_ICEBLOOD_GRAVEYARD_ATTACK    = 60,
    AV_TEXT_A_HERALD_COLDTOOTH_MINE_TAKEN         = 61,
    AV_TEXT_A_HERALD_IRONDEEP_MINE_TAKEN          = 62,
    AV_TEXT_H_HERALD_COLDTOOTH_MINE_TAKEN         = 63,
    AV_TEXT_H_HERALD_IRONDEEP_MINE_TAKEN          = 64,
    AV_TEXT_HERALD_FROSTWOLF_GENERAL_DEAD         = 65, // fix!
    AV_TEXT_HERALD_STORMPIKE_GENERAL_DEAD         = 66, // fix!
    AV_TEXT_A_HERALD_WIN                          = 67,
    AV_TEXT_H_HERALD_WIN                          = 68
};

struct BG_AV_NodeInfo
{
    BG_AV_States State;
    BG_AV_States PrevState;
    uint32       Timer;
    TeamId       TotalOwnerId;
    TeamId       OwnerId;
    TeamId       PrevOwnerId;
    bool         Tower;
};

inline BG_AV_Nodes& operator++(BG_AV_Nodes& i) { return i = BG_AV_Nodes(i + 1); }

struct BattlegroundAVScore final : public BattlegroundScore
{
    friend class BattlegroundAV;

protected:
    explicit BattlegroundAVScore(ObjectGuid playerGuid) : BattlegroundScore(playerGuid) { }

    void UpdateScore(uint32 type, uint32 value) override
    {
        switch (type)
        {
        case SCORE_GRAVEYARDS_ASSAULTED:
            GraveyardsAssaulted += value;
            break;
        case SCORE_GRAVEYARDS_DEFENDED:
            GraveyardsDefended += value;
            break;
        case SCORE_TOWERS_ASSAULTED:
            TowersAssaulted += value;
            break;
        case SCORE_TOWERS_DEFENDED:
            TowersDefended += value;
            break;
        case SCORE_MINES_CAPTURED:
            MinesCaptured += value;
            break;
        default:
            BattlegroundScore::UpdateScore(type, value);
            break;
        }
    }

    void BuildObjectivesBlock(WorldPacket& data) final;

    uint32 GraveyardsAssaulted = 0;
    uint32 GraveyardsDefended = 0;
    uint32 TowersAssaulted = 0;
    uint32 TowersDefended = 0;
    uint32 MinesCaptured = 0;
    //uint32 LeadersKilled;
    //uint32 SecondaryObjectives;

    uint32 GetAttr1() const final { return GraveyardsAssaulted; }
    uint32 GetAttr2() const final { return GraveyardsDefended; }
    uint32 GetAttr3() const final { return TowersAssaulted; }
    uint32 GetAttr4() const final { return TowersDefended; }
    uint32 GetAttr5() const final { return MinesCaptured; }
};

class AC_GAME_API BattlegroundAV : public Battleground
{
public:
    BattlegroundAV();
    ~BattlegroundAV() override = default;

    /* inherited from BattlegroundClass */
    void AddPlayer(Player* player) override;
    void StartingEventCloseDoors() override;
    void StartingEventOpenDoors() override;

    void RemovePlayer(Player* player) override;
    void HandleAreaTrigger(Player* player, uint32 trigger) override;
    bool SetupBattleground() override;
    void ResetBGSubclass() override;

    /*general stuff*/
    void UpdateScore(TeamId teamId, int16 points);
    bool UpdatePlayerScore(Player* player, uint32 type, uint32 value, bool doAddHonor = true) override;

    /*handlestuff*/ //these are functions which get called from extern
    void EventPlayerClickedOnFlag(Player* source, GameObject* gameObject) override;
    void HandleKillPlayer(Player* player, Player* killer) override;
    void HandleKillUnit(Creature* unit, Player* killer) override;
    void HandleQuestComplete(uint32 questid, Player* player);
    bool PlayerCanDoMineQuest(int32 GOId, TeamId teamId);

    void EndBattleground(TeamId winnerTeamId) override;

    GraveyardStruct const* GetClosestGraveyard(Player* player) override;

    /* achievement req. */
    bool IsBothMinesControlledByTeam(TeamId teamId) const;
    bool IsAllTowersControlledAndCaptainAlive(TeamId teamId) const;

    TeamId GetPrematureWinner() override;

    [[nodiscard]] BG_AV_NodeInfo const& GetAVNodeInfo(uint32 node) const { return m_Nodes[node]; }
    [[nodiscard]] bool IsCaptainAlive(uint8 index) const { return m_CaptainAlive[index]; }
    [[nodiscard]] TeamId GetMineOwner(uint8 index) const { return m_Mine_Owner[index]; }

private:
    void PostUpdateImpl(uint32 diff) override;

    /* Nodes occupying */
    void EventPlayerAssaultsPoint(Player* player, uint32 object);
    void EventPlayerDefendsPoint(Player* player, uint32 object);
    void EventPlayerDestroyedPoint(BG_AV_Nodes node);

    void AssaultNode(BG_AV_Nodes node, TeamId teamId);
    void DestroyNode(BG_AV_Nodes node);
    void InitNode(BG_AV_Nodes node, TeamId teamId, bool tower);
    void DefendNode(BG_AV_Nodes node, TeamId teamId);

    void PopulateNode(BG_AV_Nodes node);
    void DePopulateNode(BG_AV_Nodes node, bool ignoreSpiritGuid = false);

    BG_AV_Nodes GetNodeThroughObject(uint32 object);
    uint32 GetObjectThroughNode(BG_AV_Nodes node);
    bool IsTower(BG_AV_Nodes node) { return m_Nodes[node].Tower; }

    uint8 GetAttackString(BG_AV_Nodes node, TeamId teamId);
    uint8 GetDefendString(BG_AV_Nodes node, TeamId teamId);
    uint8 GetMineString(uint8 mine, TeamId teamId);

    /*mine*/
    void ChangeMineOwner(uint8 mine, TeamId teamId, bool initial = false);

    /*worldstates*/
    void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override;
    uint8 GetWorldStateType(uint8 state, TeamId teamId);
    void SendMineWorldStates(uint32 mine);
    void UpdateNodeWorldState(BG_AV_Nodes node);

    /*general */
    Creature* AddAVCreature(uint16 cinfoid, uint16 type);
    Creature* GetStaticCreatureByEntry(uint32 entry);

    /*variables */
    int32 m_Team_Scores[2] {};
    uint32 m_Team_QuestStatus[2][9] {}; //[x][y] x=team y=questcounter

    BG_AV_NodeInfo m_Nodes[BG_AV_NODES_MAX] {};

    TeamId m_Mine_Owner[2] {};
    int32 m_Mine_Timer; //ticks for both teams
    uint32 m_Mine_Reclaim_Timer[2] {};
    uint32 m_CaptainBuffTimer[2] {};
    bool m_CaptainAlive[2] {};

    uint32 _reputationTower = 0; // 12, 18
    uint32 _reputationCaptain = 0; // 125, 185
    uint32 _reputationBoss = 0; // 350, 525
    uint32 _reputationPerOwnedGraveyard = 0; // 12, 18
    uint32 _reputationSurvivingCaptain = 0; // 125, 175
    uint32 _reputationSurvivingTower = 0; // 12, 18
    uint32 _reputationPerOwnedMine = 0; // 24, 36
    float _avReputationRate;

    bool m_IsInformedNearVictory[2] {};
};

#endif
