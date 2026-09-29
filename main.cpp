// Includes
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>

#include <windows.h>

#include "steam_api.h"
#include "LeaderboardManager.h"
#include "resource.h"

// Namespaces
using namespace std;
using namespace sf;

// Constants
const float PI = 3.141592f;
const float targetWidth = 1920.f;
const float targetHeight = 1080.f;
const float SCRWIDTH = VideoMode::getDesktopMode().width;
const float SCRHEIGHT = VideoMode::getDesktopMode().height;
// Init variables
const uint32_t AvatarWidth = 184;
const uint32_t AvatarHeight = 184;
bool menu = true;
bool gameOver = false;
bool rotateRight = false;
bool rotateLeft = false;
float timer = 0.f;
int frames = 0;
int page = 1;
float playerSpeed = timer / 90.f + 1.f;
float bombSpeed = (timer / 25.f + 2.f) / 2.f + 6.f;
float planeSpeed = (timer / 25 + 2) / 2;
float planeSpeed2;
float bombRadians;
float x;
float y;
bool shoot = false;
float bombRotation;
bool pickable = false;
bool switchTo = false;
bool MP1pickable = false;
bool MP1switchTo = false;
bool MP2pickable = false;
bool MP2switchTo = false;
bool bombShoot = true;
bool altFont = false;
// vvv CHANGE IN BUGFIX vvv
bool checkFullscreen = false;
// ^^^ CHANGE IN BUGFIX ^^^
bool checkFrames = true;
bool checkVsync = true;
VideoMode desktopMode = VideoMode::getDesktopMode();
int shots = 0;
int MP1shots = 0;
int MP2shots = 0;
int MP1SteamID;
int MP2SteamID;
bool showHitboxes = false;
bool showFPS = false;
float framerate;
float currentTime;
float framerateLimit = 60.0f;
int wave = 0;
int wave5 = 0;
int corner1 = 1.f;
int corner2 = 0.f;
int plane1corner;
int plane2corner;
int plane3corner;
int plane4corner;
int plane5corner;
int plane6corner;
float timerInt;
float waveTimer;
int score = 0;
int sessionCount;
int MP1score = 0;
int MP2score = 0;
int MP1wins = 0;
int MP2wins = 0;
String waveString = to_string(wave);
String scoreString = to_string(score);
String MP1scoreString = to_string(MP1score);
String MP2scoreString = to_string(MP2score);
String chatBoxInput;
String textBoxInput;
String frameBoxInput;
int year;
int month;
int day;
bool explosionBool = false;
bool MP1explosionBool = false;
bool MP2explosionBool = false;
bool MP1bombShoot = true;
bool MP2bombShoot = true;
float expTimer = 5;
float MP1expTimer = 5;
float MP2expTimer = 5;
int lastCorner1;
int lastCorner2;
int MP1lastCorner1;
int MP1lastCorner2;
int MP2lastCorner1;
int MP2lastCorner2;
Vector2i mousePosWindow;
Vector2f mousePosView;
float mPosX;
float mPosY;
bool pause = false;
bool pausable = false;
bool unpausable = false;
bool leaderboard = false;
int musicVolume;
int SFXVolume;
int highScore = 0;
int highWave = 0;
int treasure = 0;
int treasureTemp;
bool exitable = true;
bool enterable = false;
bool exitbuttonable = false;
bool playable = true;
bool leaderboardable = false;
bool shop = false;
bool shoppable = false;
bool seasonalShop = false;
bool seasonalShoppable = false;
bool skins = false;
bool skinnable = false;
bool versus = false;
bool versusable = false;
bool claimTreasure;
bool claimPeashooterCannon;
bool claimYippeeCannon;
bool claimSugarCannon;
bool claimFireCannon;
bool claimYippeeBomb;
bool claimFireBomb;
bool claimYoshiBomb;
bool claimBirdoBomb;
bool claimLogicalBomb;
bool claimCandyCaneCannon = true;
bool claimFestivePlane = true;
bool claimIcyBomb;
bool claimSnowyExplosion;
bool claimGoldenCannon;
bool claimChocolateGrenade;
bool claimOrangeBomb;
bool claimCookiePlane;
bool claimGingerbreadExplosion;
bool claimFestiveExplosion;
bool claimPeppermintBomb;
bool claimFireGrenade;
bool claimYippeeGrenade;
bool claimLogicalGrenade;
bool claimDynamiteGrenade;
bool claimNukeGrenade;
bool claimSmokeGrenade;
bool claimHolyHandGrenade;
bool claimLogicalCannon;
bool claimApocCannon;
bool claimApocBomb;
bool claimApocGrenade;
bool claimApocExplosion;
bool claimApocPlane;
bool claimFlameCannon;
bool claimYippeeExplosion;
bool claimLogicalExplosion;
bool claimMushroomExplosion;
bool claimSmokeExplosion;
bool claimYippeePlane;
bool claimFirePlane;
bool claimLogicalPlane;
bool claimFighterPlane;
bool claimSnowmanCannon;
bool claimGingerbreadCannon;
bool claimPresentCannon;
bool claimBellBomb;
bool claimSantasBomb;
bool claimElfExplosion;
bool claimSnowExplosion;
bool claimGarlandGrenade;
bool claimIceGrenade;
bool claimSantaGrenade;
bool claimRudolphPlane;
bool claimSantasPlane;
bool claimTreePlane;
bool claimChristmasGrenade;
bool claimDeadpoolCannon;
bool claimShockCannon;
bool claimBirdoCannon;
bool claimHeartsCannon;
int equippedCannon = 0;
int equippedBomb = 0;
int equippedPlane = 0;
int equippedGrenade = 0;
int equippedExplosion = 0;
bool equippable;
bool unequippable;
float logoScale = 1.2;
float logoRotation = 0;
bool loading;
float bombx;
float bomby;
float grenadex;
float grenadey;
float explosionx;
float explosiony;
float grenadeRotation;
float playerRotation;
float plane1x;
float plane1y;
float plane2x;
float plane2y;
float plane3x;
float plane3y;
float plane4x;
float plane4y;
float plane5x;
float plane5y;
float plane6x;
float plane6y;
bool credit;
bool slidable = false;
bool slidable2 = false;
bool slidable3 = false;
bool slidable4 = false;
bool setting;
bool audio = true;
bool display = false;
bool fade;
bool hoverable1;
bool hoverable2;
bool hoverable3;
bool hoverable4;
bool hoverable5;
bool hoverable6;
bool hoverable7;
bool hoverable8;
bool hoverable9;
bool hoverable10;
bool hoverable11;
bool hoverable12;
bool hoverable13;
bool hoverable14;
bool hoverable15;
bool hoverable16;
bool hoverable17;
bool hoverable18;
bool hoverable19;
bool hoverable20;
bool hoverable21;
bool hoverable22;
bool hoverable23;
bool hoverable24;
bool hoverable25;
bool hoverable26;
bool hoverable27;
bool hoverable28;
bool hoverable29;
bool hoverable30;
bool hoverable31;
bool hoverable32;
bool hoverable33;
bool hoverable34;
bool hoverable35;
bool hoverable36;
bool hoverable37;
bool hoverable38;
bool hoverable39;
bool hoverable40;
bool hoverable41;
bool hoverable42;
bool hoverable43;
bool hoverable44;
bool hoverable45;
bool hoverable46;
bool hoverable47;
bool hoverable48;
bool hoverable49;
bool hoverable50;
bool hoverable51;
bool hoverable52;
bool creditable = false;
bool settingable = false;
bool eventActive = false;
bool day1Claimed;
bool day2Claimed;
bool day3Claimed;
bool day4Claimed;
bool day5Claimed;
bool day6Claimed;
bool day7Claimed;
bool day8Claimed;
bool day9Claimed;
bool day10Claimed;
bool day11Claimed;
bool day12Claimed;
bool cannonSkin = true;
bool bombSkin = false;
bool grenadeSkin = false;
bool explosionSkin = false;
bool planeSkin = false;
int storeVolumeM;
int storeVolumeS;
bool focused = true;
bool exiting = false;
bool resetting = false;
bool firstStrike;
bool wave10;
bool cannonShop;
bool bombShop;
bool grenadeShop;
bool explosionShop;
bool planeShop;
bool shrinking = false;
bool stretching = true;
bool rotatingLeft = false;
bool rotatingRight = true;
bool plane1Death = false;
bool plane2Death = false;
bool plane3Death = false;
bool plane4Death = false;
bool plane5Death = false;
bool plane6Death = false;
bool MP1plane1Death = false;
bool MP1plane2Death = false;
bool MP1plane3Death = false;
bool MP1plane4Death = false;
bool MP1plane5Death = false;
bool MP1plane6Death = false;
bool MP2plane1Death = false;
bool MP2plane2Death = false;
bool MP2plane3Death = false;
bool MP2plane4Death = false;
bool MP2plane5Death = false;
bool MP2plane6Death = false;
bool d = false;
bool e = false;
bool v = false;
bool t = false;
bool o = false;
bool l = false;
bool s = false;
bool vault = true;
bool showMPWarning = true;
bool MPWarning = false;
bool lobby = false;
bool player2Joined = false;
bool player2Remote = false;
bool player2Local = false;
string leaderboardString;
int ranksss = 1;
int rankss = 1;

// Versus
bool MP1rotateRight = false;
bool MP1rotateLeft = false;
bool MP2rotateRight = false;
bool MP2rotateLeft = false;
bool MP1shoot = false;
float MP1bombRotation = 0;
bool  MP2shoot = false;
float MP2bombRotation = 0;
float MP1bombRadians;
float MP1x;
float MP1y;
float MP2bombRadians;
float MP2x;
float MP2y;
int MP1plane1corner;
int MP1plane2corner;
int MP1plane3corner;
int MP1plane4corner;
int MP1plane5corner;
int MP1plane6corner;
int MP2plane1corner;
int MP2plane2corner;
int MP2plane3corner;
int MP2plane4corner;
int MP2plane5corner;
int MP2plane6corner;
int MP1corner1 = 1;
int MP1corner2 = 0;
int MP2corner1 = 1;
int MP2corner2 = 0;
float bulgeStrength = 1.25f;
float saturation = 1.0f;
float contrast = 1.0f;
bool scanlines = true;
CSteamID hostSteamID;
string hostName;
Texture hostAvatar;
CSteamID remoteSteamID;
string remoteName;
Texture remoteAvatar;
RemotePlaySessionID_t sessionID;
Text chatText;
Text typeText;
bool player1Typing = false;
bool player2Typing = false;
bool fullscreen = false;
bool unlimitedFPS = false;
bool vsync = false;
float fadeHeight = 100.f;
float scrollOffset = 0.f;

// Vectors
Vector2f bombPos;
Vector2f explosionPos;
Vector2f grenadePos;
Vector2f plane1Pos;
Vector2f plane2Pos;
Vector2f plane3Pos;
Vector2f plane4Pos;
Vector2f plane5Pos;
Vector2f plane6Pos;
Vector2f dotPos;
Vector2f dot2Pos;
String storeChat;

void logError(const string& message) {
	ofstream logFile;
	logFile.open("logs/error_log.txt");
	logFile << message;
	logFile.close();
}

int loadSkins() {
	ifstream skinsin;
	skinsin.open("saves/skins.txt");
	skinsin >> claimPeashooterCannon;
	skinsin >> claimYippeeCannon;
	skinsin >> claimSugarCannon;
	skinsin >> claimFireCannon;
	skinsin >> claimYippeeBomb;
	skinsin >> claimFireBomb;
	skinsin >> claimCandyCaneCannon;
	skinsin >> claimFestivePlane;
	skinsin >> claimIcyBomb;
	skinsin >> claimSnowyExplosion;
	skinsin >> claimGoldenCannon;
	skinsin >> claimChocolateGrenade;
	skinsin >> claimOrangeBomb;
	skinsin >> claimCookiePlane;
	skinsin >> claimGingerbreadExplosion;
	skinsin >> claimFestiveExplosion;
	skinsin >> claimPeppermintBomb;
	skinsin >> claimLogicalCannon;
	skinsin >> equippedCannon;
	skinsin >> equippedBomb;
	skinsin >> equippedPlane;
	skinsin >> equippedGrenade;
	skinsin >> equippedExplosion;
	skinsin >> claimFlameCannon;
	skinsin >> claimFireGrenade;
	skinsin >> claimYippeeGrenade;
	skinsin >> claimLogicalGrenade;
	skinsin >> claimYippeeExplosion;
	skinsin >> claimYippeePlane;
	skinsin >> claimFirePlane;
	skinsin >> claimLogicalPlane;
	skinsin >> claimSnowmanCannon;
	skinsin >> claimGingerbreadCannon;
	skinsin >> claimPresentCannon;
	skinsin >> claimBellBomb;
	skinsin >> claimSantasBomb;
	skinsin >> claimElfExplosion;
	skinsin >> claimSnowExplosion;
	skinsin >> claimGarlandGrenade;
	skinsin >> claimIceGrenade;
	skinsin >> claimSantaGrenade;
	skinsin >> claimRudolphPlane;
	skinsin >> claimSantasPlane;
	skinsin >> claimTreePlane;
	skinsin >> claimChristmasGrenade;
	skinsin >> claimDeadpoolCannon;
	skinsin >> claimShockCannon;
	skinsin >> claimBirdoCannon;
	skinsin >> claimHeartsCannon;
	skinsin >> claimYoshiBomb;
	skinsin >> claimBirdoBomb;
	skinsin >> claimDynamiteGrenade;
	skinsin >> claimNukeGrenade;
	skinsin >> claimSmokeGrenade;
	skinsin >> claimHolyHandGrenade;
	skinsin >> claimLogicalBomb;
	skinsin >> claimLogicalExplosion;
	skinsin >> claimMushroomExplosion;
	skinsin >> claimSmokeExplosion;
	skinsin >> claimFighterPlane;
	skinsin >> claimApocCannon;
	skinsin >> claimApocBomb;
	skinsin >> claimApocGrenade;
	skinsin >> claimApocExplosion;
	skinsin >> claimApocPlane;
	skinsin.close();
	return 1;
}
int saveSkins() {
	ofstream skinsout;
	skinsout.open("saves/skins.txt");
	skinsout << claimPeashooterCannon << '\n';
	skinsout << claimYippeeCannon << '\n';
	skinsout << claimSugarCannon << '\n';
	skinsout << claimFireCannon << '\n';
	skinsout << claimYippeeBomb << '\n';
	skinsout << claimFireBomb << '\n';
	skinsout << claimCandyCaneCannon << '\n';
	skinsout << claimFestivePlane << '\n';
	skinsout << claimIcyBomb << '\n';
	skinsout << claimSnowyExplosion << '\n';
	skinsout << claimGoldenCannon << '\n';
	skinsout << claimChocolateGrenade << '\n';
	skinsout << claimOrangeBomb << '\n';
	skinsout << claimCookiePlane << '\n';
	skinsout << claimGingerbreadExplosion << '\n';
	skinsout << claimFestiveExplosion << '\n';
	skinsout << claimPeppermintBomb << '\n';
	skinsout << claimLogicalCannon << '\n';
	skinsout << equippedCannon << '\n';
	skinsout << equippedBomb << '\n';
	skinsout << equippedPlane << '\n';
	skinsout << equippedGrenade << '\n';
	skinsout << equippedExplosion << '\n';
	skinsout << claimFlameCannon << '\n';
	skinsout << claimFireGrenade << '\n';
	skinsout << claimYippeeGrenade << '\n';
	skinsout << claimLogicalGrenade << '\n';
	skinsout << claimYippeeExplosion << '\n';
	skinsout << claimYippeePlane << '\n';
	skinsout << claimFirePlane << '\n';
	skinsout << claimLogicalPlane << '\n';
	skinsout << claimSnowmanCannon << '\n';
	skinsout << claimGingerbreadCannon << '\n';
	skinsout << claimPresentCannon << '\n';
	skinsout << claimBellBomb << '\n';
	skinsout << claimSantasBomb << '\n';
	skinsout << claimElfExplosion << '\n';
	skinsout << claimSnowExplosion << '\n';
	skinsout << claimGarlandGrenade << '\n';
	skinsout << claimIceGrenade << '\n';
	skinsout << claimSantaGrenade << '\n';
	skinsout << claimRudolphPlane << '\n';
	skinsout << claimSantasPlane << '\n';
	skinsout << claimTreePlane << '\n';
	skinsout << claimChristmasGrenade << '\n';
	skinsout << claimDeadpoolCannon << '\n';
	skinsout << claimShockCannon << '\n';
	skinsout << claimBirdoCannon << '\n';
	skinsout << claimHeartsCannon << '\n';
	skinsout << claimYoshiBomb << '\n';
	skinsout << claimBirdoBomb << '\n';
	skinsout << claimDynamiteGrenade << '\n';
	skinsout << claimNukeGrenade << '\n';
	skinsout << claimSmokeGrenade << '\n';
	skinsout << claimHolyHandGrenade << '\n';
	skinsout << claimLogicalBomb << '\n';
	skinsout << claimLogicalExplosion << '\n';
	skinsout << claimMushroomExplosion << '\n';
	skinsout << claimSmokeExplosion << '\n';
	skinsout << claimFighterPlane << '\n';
	skinsout << claimApocCannon << '\n';
	skinsout << claimApocBomb << '\n';
	skinsout << claimApocGrenade << '\n';
	skinsout << claimApocExplosion << '\n';
	skinsout << claimApocPlane << '\n';
	skinsout.close();
	return 1;
}
int loadSettings() {
	ifstream settingsin;
	settingsin.open("saves/settings/settings.txt");
	settingsin >> musicVolume;
	settingsin >> SFXVolume;
	settingsin >> saturation;
	settingsin >> contrast;
	settingsin >> scanlines;
	settingsin >> altFont;
	settingsin >> fullscreen;
	settingsin >> framerateLimit;
	settingsin >> vsync;
	settingsin >> unlimitedFPS;
	settingsin.close();
	return 1;
}
int saveSettings() {
	ofstream settingsout;
	settingsout.open("saves/settings/settings.txt");
	settingsout << musicVolume << '\n';
	settingsout << SFXVolume << '\n';
	settingsout << saturation << '\n';
	settingsout << contrast << '\n';
	settingsout << scanlines << '\n';
	settingsout << altFont << '\n';
	settingsout << fullscreen << '\n';
	settingsout << framerateLimit << '\n';
	settingsout << vsync << '\n';
	settingsout << unlimitedFPS << '\n';
	settingsout.close();
	return 1;
}
int loadOther() {
	ifstream otherin;
	otherin.open("saves/other.txt");
	otherin >> highScore;
	otherin >> highWave;
	otherin >> treasure;
	otherin >> claimTreasure;
	otherin >> day1Claimed;
	otherin >> day2Claimed;
	otherin >> day3Claimed;
	otherin >> day4Claimed;
	otherin >> day5Claimed;
	otherin >> day6Claimed;
	otherin >> day7Claimed;
	otherin >> day8Claimed;
	otherin >> day9Claimed;
	otherin >> day10Claimed;
	otherin >> day11Claimed;
	otherin >> day12Claimed;
	otherin >> wave10;
	otherin >> firstStrike;
	otherin >> showMPWarning;
	otherin.close();
	return 1;
}
int saveOther() {
	ofstream otherout;
	otherout.open("saves/other.txt");
	otherout << highScore << '\n';
	otherout << highWave << '\n';
	otherout << treasure << '\n';
	otherout << claimTreasure << '\n';
	otherout << day1Claimed << '\n';
	otherout << day2Claimed << '\n';
	otherout << day3Claimed << '\n';
	otherout << day4Claimed << '\n';
	otherout << day5Claimed << '\n';
	otherout << day6Claimed << '\n';
	otherout << day7Claimed << '\n';
	otherout << day8Claimed << '\n';
	otherout << day9Claimed << '\n';
	otherout << day10Claimed << '\n';
	otherout << day11Claimed << '\n';
	otherout << day12Claimed << '\n';
	otherout << wave10 << '\n';
	otherout << firstStrike << '\n';
	otherout << showMPWarning << '\n';
	otherout.close();
	return 1;
}
int saveGame() {
	ofstream gameout;
	gameout.open("saves/gameState.txt");
	gameout << corner1 << '\n';
	gameout << corner2 << '\n';
	gameout << frames << '\n';
	gameout << plane1corner << '\n';
	gameout << plane2corner << '\n';
	gameout << plane3corner << '\n';
	gameout << plane4corner << '\n';
	gameout << plane5corner << '\n';
	gameout << plane6corner << '\n';
	gameout << score << '\n';
	gameout << timer << '\n';
	gameout << wave << '\n';
	gameout << wave5 << '\n';
	gameout << waveTimer << '\n';
	gameout.close();
	return 1;
}
int loadGame() {
	ifstream gamein;
	gamein.open("saves/gameState.txt");
	gamein >> corner1;
	gamein >> corner2;
	gamein >> frames;
	gamein >> plane1corner;
	gamein >> plane2corner;
	gamein >> plane3corner;
	gamein >> plane4corner;
	gamein >> plane5corner;
	gamein >> plane6corner;
	gamein >> score;
	gamein >> timer;
	gamein >> wave;
	gamein >> wave5;
	gamein >> waveTimer;
	gamein.close();
	return 1;
}
void saveStats() {
	if (SteamUserStats()) {
		SteamUserStats()->StoreStats();
	}
}
void setCAN_TREASURE() {
	if (SteamUserStats()) {
		SteamUserStats()->SetAchievement("CAN_TREASURE");
	}
}
void setCAN_FIRSTSTRIKE() {
	if (SteamUserStats()) {
		SteamUserStats()->SetAchievement("CAN_FIRSTSTRIKE");
	}
}
void setCAN_WAVE10() {
	if (SteamUserStats()) {
		SteamUserStats()->SetAchievement("CAN_WAVE10");
	}
}
void resetAchievements() {
	if (SteamUserStats()) {
		SteamUserStats()->ClearAchievement("CAN_TREASURE");
		SteamUserStats()->ClearAchievement("CAN_FIRSTSTRIKE");
		SteamUserStats()->ClearAchievement("CAN_WAVE10");
	}
}
LeaderboardManager leaderboardManager;
LeaderboardManager::LeaderboardManager()
	: scoreLeaderboard(0), waveLeaderboard(0), scoreLeaderboardReady(false), waveLeaderboardReady(false) {
}

void LeaderboardManager::FindLeaderboards() {
	SteamAPICall_t hSteamAPICall1 = SteamUserStats()->FindLeaderboard("SCORE_LEADERBOARD");
	SteamAPICall_t hSteamAPICall2 = SteamUserStats()->FindLeaderboard("WAVE_LEADERBOARD");

	m_callResultFindScore.Set(hSteamAPICall1, this, &LeaderboardManager::OnFindScoreLeaderboard);
	m_callResultFindWave.Set(hSteamAPICall2, this, &LeaderboardManager::OnFindWaveLeaderboard);
}

void LeaderboardManager::OnFindScoreLeaderboard(LeaderboardFindResult_t* pResult, bool bIOFailure) {
	if (bIOFailure || !pResult->m_bLeaderboardFound) {
		logError("SCORE_LEADERBOARD not found!");
		return;
	}
	scoreLeaderboard = pResult->m_hSteamLeaderboard;
	scoreLeaderboardReady = true;
	CheckIfBothLeaderboardsReady();
}

void LeaderboardManager::OnFindWaveLeaderboard(LeaderboardFindResult_t* pResult, bool bIOFailure) {
	if (bIOFailure || !pResult->m_bLeaderboardFound) {
		logError("WAVE_LEADERBOARD not found!");
		return;
	}
	waveLeaderboard = pResult->m_hSteamLeaderboard;
	waveLeaderboardReady = true;
	CheckIfBothLeaderboardsReady();
}

void LeaderboardManager::UploadScore(int score) {
	if (!scoreLeaderboardReady) {
		logError("Cannot upload score! SCORE_LEADERBOARD not found.");
		return;
	}

	SteamAPICall_t hSteamAPICall = SteamUserStats()->UploadLeaderboardScore(
		scoreLeaderboard, k_ELeaderboardUploadScoreMethodKeepBest, score, nullptr, 0);

	m_callResultUploadScore.Set(hSteamAPICall, this, &LeaderboardManager::OnScoreUploaded);
}

void LeaderboardManager::UploadWave(int waveNumber) {
	if (!waveLeaderboardReady) {
		logError("Cannot upload wave! WAVE_LEADERBOARD not found.");
		return;
	}

	SteamAPICall_t hSteamAPICall = SteamUserStats()->UploadLeaderboardScore(
		waveLeaderboard, k_ELeaderboardUploadScoreMethodKeepBest, waveNumber, nullptr, 0);

	m_callResultUploadWave.Set(hSteamAPICall, this, &LeaderboardManager::OnWaveUploaded);
}

void LeaderboardManager::OnScoreUploaded(LeaderboardScoreUploaded_t* pResult, bool bIOFailure) {
	if (bIOFailure) {
		logError("Score upload failed!");
		return;
	}
	logError("Score uploaded successfully.");
}

void LeaderboardManager::OnWaveUploaded(LeaderboardScoreUploaded_t* pResult, bool bIOFailure) {
	if (bIOFailure) {
		logError("Wave upload failed!");
		return;
	}
	logError("Wave uploaded successfully.");
}

void LeaderboardManager::FetchTopScores() {
	if (!scoreLeaderboardReady || !waveLeaderboardReady) {
		logError("Cannot fetch scores! One or both leaderboards not found.");
		return;
	}

	SteamAPICall_t hSteamAPICall1 = SteamUserStats()->DownloadLeaderboardEntries(
		scoreLeaderboard, k_ELeaderboardDataRequestGlobal, 0, 99);
	SteamAPICall_t hSteamAPICall2 = SteamUserStats()->DownloadLeaderboardEntries(
		waveLeaderboard, k_ELeaderboardDataRequestGlobal, 0, 99);

	m_callResultFetchScores.Set(hSteamAPICall1, this, &LeaderboardManager::OnScoresFetched);
	m_callResultFetchWaveScores.Set(hSteamAPICall2, this, &LeaderboardManager::OnWaveScoresFetched);
}

void LeaderboardManager::OnScoresFetched(LeaderboardScoresDownloaded_t* pResult, bool bIOFailure) {
	if (bIOFailure) {
		logError("Failed to download SCORE_LEADERBOARD scores.");
		return;
	}

	topScores.clear();
	for (int i = 0; i < pResult->m_cEntryCount; i++) {
		LeaderboardEntry_t entry;
		SteamUserStats()->GetDownloadedLeaderboardEntry(pResult->m_hSteamLeaderboardEntries, i, &entry, nullptr, 0);

		string playerName = SteamFriends()->GetFriendPersonaName(entry.m_steamIDUser);
		topScores.emplace_back(playerName, entry.m_nScore);
	}
	UpdateStoredLeaderboardText();
	logError("Top 100 scores fetched successfully.");
}

void LeaderboardManager::OnWaveScoresFetched(LeaderboardScoresDownloaded_t* pResult, bool bIOFailure) {
	if (bIOFailure) {
		logError("Failed to download WAVE_LEADERBOARD scores.");
		return;
	}

	topWaves.clear();
	for (int i = 0; i < pResult->m_cEntryCount; i++) {
		LeaderboardEntry_t entry;
		SteamUserStats()->GetDownloadedLeaderboardEntry(pResult->m_hSteamLeaderboardEntries, i, &entry, nullptr, 0);

		string playerName = SteamFriends()->GetFriendPersonaName(entry.m_steamIDUser);
		topWaves.emplace_back(playerName, entry.m_nScore);
	}
	UpdateStoredLeaderboardText();
	logError("Top 100 wave scores fetched successfully.");
}

void LeaderboardManager::UpdateStoredLeaderboardText() {
	storedLeaderboardTextScore.clear();
	storedLeaderboardTextWave.clear();
	ranksss = 1;
	for (const auto& entry : topScores) {
		storedLeaderboardTextScore += to_string(ranksss) + ". " + entry.first + " - " + to_string(entry.second) + "\n";
		ranksss++;
	}

	rankss = 1;
	for (const auto& entry : topWaves) {
		storedLeaderboardTextWave += to_string(rankss) + ". " + entry.first + " - " + to_string(entry.second) + "\n";
		rankss++;
	}
}

void LeaderboardManager::CheckIfBothLeaderboardsReady() {
	if (scoreLeaderboardReady && waveLeaderboardReady) {
		logError("Both leaderboards found successfully!");
	}
}
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	srand(time(NULL));
	Clock clock; 
	Clock backspaceTimer;
	Clock updateFPSText;
	const Time backspaceDelay = milliseconds(20);
	// Steam API
	SteamAPI_RestartAppIfNecessary(3357860);
	if (!SteamAPI_Init()) {
		logError("Steam initialization failed!");
	}
	RenderWindow window(VideoMode(SCRWIDTH, SCRHEIGHT), "Cannoneer", Style::Titlebar | Style::Close | Style::Default | Style::Fullscreen);
	window.setFramerateLimit(framerateLimit);
	View view(Vector2f(960, 540), Vector2f(1920.0f, 1080.0f));

	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = DefWindowProc; // Or your custom window procedure
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APP_ICON));

	loadSettings();
	loadSkins();
	loadOther();
	if (!SteamAPI_Init()) {
		logError("ERROR: SteamAPI failed to initialize!");
		return -1;
	}

	if (!SteamUserStats() || !SteamUser()) {
		logError("ERROR: SteamUserStats or SteamUser not available!");
		return -1;
	}
	leaderboardManager.FindLeaderboards();
	SteamUserStats()->StoreStats();
	// Gift Skins!
	if (time(NULL) >= 1734411600 && time(NULL) < 1735448399) {
		claimCandyCaneCannon = true;
	    claimFestivePlane = true;
	}

	RenderTexture renderTexture;
	renderTexture.create(SCRWIDTH, SCRHEIGHT);

	Shader shader;
	shader.loadFromFile("shaders/crt_shader.frag", Shader::Fragment);
	shader.setUniform("bulgeStrength", bulgeStrength);
	shader.setUniform("saturation", saturation);
	shader.setUniform("contrast", contrast);
	shader.setUniform("scanlines", scanlines);
	shader.setUniform("resolution", Vector2f(window.getSize().x, window.getSize().y));
	shader.setUniform("texture", renderTexture.getTexture());

	Shader creditsFadeShader;
	creditsFadeShader.loadFromFile("shaders/credits_fade.frag", Shader::Fragment);
	creditsFadeShader.setUniform("fadeInStart", 850.f);
	creditsFadeShader.setUniform("fadeOutStart", 150.f);

	// Load select SFX
	SoundBuffer selectBuffer;
	selectBuffer.loadFromFile("sounds/select.wav");
	Sound select;
	select.setBuffer(selectBuffer);

	// Load credits SFX
	SoundBuffer creditsMusicBuffer;
	creditsMusicBuffer.loadFromFile("sounds/A Journey Completed.mp3");
	Sound creditsMusic;
	creditsMusic.setBuffer(creditsMusicBuffer);

	// Load new wave SFX
	SoundBuffer newWaveBuffer;
	newWaveBuffer.loadFromFile("sounds/newWave.wav");
	Sound newWave;
	newWave.setBuffer(newWaveBuffer);

	// Load grenade SFX
	SoundBuffer grenadeExplosionBuffer;
	grenadeExplosionBuffer.loadFromFile("sounds/explosion.ogg");
	Sound grenadeExplosion;
	grenadeExplosion.setBuffer(grenadeExplosionBuffer);

	// Load powerup SFX
	SoundBuffer powerupBuffer;
	powerupBuffer.loadFromFile("sounds/powerup.ogg");
	Sound powerup;
	powerup.setBuffer(powerupBuffer);

	// Load appear SFX
	SoundBuffer appearBuffer;
	appearBuffer.loadFromFile("sounds/appear.ogg");
	Sound appear;
	appear.setBuffer(appearBuffer);

	// Load bomb explosion SFX
	SoundBuffer bombExplosionBuffer;
	bombExplosionBuffer.loadFromFile("sounds/bomb.ogg");
	Sound bombExplosion;
	bombExplosion.setBuffer(bombExplosionBuffer);

	// Load shoot SFX
	SoundBuffer shootBuffer;
	shootBuffer.loadFromFile("sounds/shoot.ogg");
	Sound shootSound;
	shootSound.setBuffer(shootBuffer);

	// Load death SFX
	SoundBuffer deathBuffer;
	deathBuffer.loadFromFile("sounds/death.ogg");
	Sound death;
	death.setBuffer(deathBuffer);

	// Load Main Menu Music
	SoundBuffer menuMusicBuffer;
	menuMusicBuffer.loadFromFile("sounds/menu.mp3");
	Sound menuMusic;
	menuMusic.setBuffer(menuMusicBuffer);
	// Load Generation Retro
	SoundBuffer genretBuffer;
	genretBuffer.loadFromFile("sounds/Generation Retro.mp3");
	Sound genret;
	genret.setBuffer(genretBuffer);
	// Load March of the Spoons
	SoundBuffer marchBuffer;
	marchBuffer.loadFromFile("sounds/March of the Spoons.mp3");
	Sound march;
	march.setBuffer(marchBuffer);

	// Load fonts
	Font Cannon;
	Cannon.loadFromFile("fonts/cannon.ttf");
	Font alt;
	alt.loadFromFile("fonts/C&C Red Alert.ttf");

	// Initialize text
	Text titleText;
	titleText.setFont(Cannon);
	titleText.setCharacterSize(100.f);
	titleText.setStyle(Text::Bold);
	titleText.setFillColor(Color(0, 0, 0, 255));

	Text scoreText;
	scoreText.setFont(Cannon);
	scoreText.setCharacterSize(50.f);
	scoreText.setStyle(Text::Bold);
	scoreText.setFillColor(Color(0, 0, 0, 255));

	Text waveText;
	waveText.setFont(Cannon);
	waveText.setCharacterSize(50.f);
	waveText.setStyle(Text::Bold);
	waveText.setFillColor(Color(0, 0, 0, 255));

	Text bestScoreText;
	bestScoreText.setFont(Cannon);
	bestScoreText.setCharacterSize(70.f);
	bestScoreText.setStyle(Text::Bold);
	bestScoreText.setFillColor(Color(0, 0, 0, 255));

	Text scoreTitleText;
	scoreTitleText.setFont(Cannon);
	scoreTitleText.setCharacterSize(70.f);
	scoreTitleText.setStyle(Text::Bold);
	scoreTitleText.setFillColor(Color(0, 0, 0, 255));

	Text waveTitleText;
	waveTitleText.setFont(Cannon);
	waveTitleText.setCharacterSize(70.f);
	waveTitleText.setStyle(Text::Bold);
	waveTitleText.setFillColor(Color(0, 0, 0, 255));

	Text MP1scoreText;
	MP1scoreText.setFont(Cannon);
	MP1scoreText.setCharacterSize(50.f);
	MP1scoreText.setStyle(Text::Bold);
	MP1scoreText.setFillColor(Color(0, 0, 0, 255));

	Text MPText1;
	MPText1.setFont(Cannon);
	MPText1.setCharacterSize(40.f);
	MPText1.setStyle(Text::Bold);
	MPText1.setFillColor(Color(0, 0, 0, 255));

	Text MPText2;
	MPText2.setFont(Cannon);
	MPText2.setCharacterSize(40.f);
	MPText2.setStyle(Text::Bold);
	MPText2.setFillColor(Color(0, 0, 0, 255));
	
	Text MPWinsText;
	MPWinsText.setFont(Cannon);
	MPWinsText.setCharacterSize(120.f);
	MPWinsText.setStyle(Text::Bold);
	MPWinsText.setFillColor(Color(0, 0, 0, 255));

	Text MP1waveText;
	MP1waveText.setFont(Cannon);
	MP1waveText.setCharacterSize(50.f);
	MP1waveText.setStyle(Text::Bold);
	MP1waveText.setFillColor(Color(0, 0, 0, 255));

	Text MP2scoreText;
	MP2scoreText.setFont(Cannon);
	MP2scoreText.setCharacterSize(50.f);
	MP2scoreText.setStyle(Text::Bold);
	MP2scoreText.setFillColor(Color(0, 0, 0, 255));

	Text MP2waveText;
	MP2waveText.setFont(Cannon);
	MP2waveText.setCharacterSize(50.f);
	MP2waveText.setStyle(Text::Bold);
	MP2waveText.setFillColor(Color(0, 0, 0, 255));

	Text pauseText;
	pauseText.setFont(Cannon);
	pauseText.setCharacterSize(100.f);
	pauseText.setStyle(Text::Bold);
	pauseText.setFillColor(Color(0, 0, 0, 255));

	Text lastScoreText;
	lastScoreText.setFont(Cannon);
	lastScoreText.setCharacterSize(70.f);
	lastScoreText.setStyle(Text::Bold);
	lastScoreText.setFillColor(Color(0, 0, 0, 255));

	Text waveRecordText;
	waveRecordText.setFont(Cannon);
	waveRecordText.setCharacterSize(100.0f);
	waveRecordText.setStyle(Text::Bold);
	waveRecordText.setFillColor(Color(0, 0, 0, 255));

	Text scoreLeaderboardText;
	scoreLeaderboardText.setFont(Cannon);
	scoreLeaderboardText.setCharacterSize(50.0f);
	scoreLeaderboardText.setStyle(Text::Bold);
	scoreLeaderboardText.setFillColor(Color(0, 0, 0, 255));

	Text waveLeaderboardText;
	waveLeaderboardText.setFont(Cannon);
	waveLeaderboardText.setCharacterSize(50.0f);
	waveLeaderboardText.setStyle(Text::Bold);
	waveLeaderboardText.setFillColor(Color(0, 0, 0, 255));

	Text musicText;
	musicText.setFont(Cannon);
	musicText.setCharacterSize(70);
	musicText.setStyle(Text::Bold);
	musicText.setFillColor(Color(0, 0, 0, 255));

	Text SFXText;
	SFXText.setFont(Cannon);
	SFXText.setCharacterSize(70);
	SFXText.setStyle(Text::Bold);
	SFXText.setFillColor(Color(0, 0, 0, 255));

	Text satText;
	satText.setFont(Cannon);
	satText.setCharacterSize(70);
	satText.setStyle(Text::Bold);
	satText.setFillColor(Color(0, 0, 0, 255));
	Text conText;
	conText.setFont(Cannon);
	conText.setCharacterSize(70);
	conText.setStyle(Text::Bold);
	conText.setFillColor(Color(0, 0, 0, 255));

	Text frameText;
	frameText.setFont(Cannon);
	frameText.setCharacterSize(70);
	frameText.setStyle(Text::Bold);
	frameText.setFillColor(Color(0, 0, 0, 255));

	Text FPSText;
	FPSText.setFont(Cannon);
	FPSText.setCharacterSize(100);
	FPSText.setStyle(Text::Bold);
	FPSText.setFillColor(Color(255, 255, 0, 255));

	Text saturationText;
	saturationText.setFont(Cannon);
	saturationText.setCharacterSize(55);
	saturationText.setStyle(Text::Bold);
	saturationText.setFillColor(Color(0, 0, 0, 255));
	Text contrastText;
	contrastText.setFont(Cannon);
	contrastText.setCharacterSize(55);
	contrastText.setStyle(Text::Bold);
	contrastText.setFillColor(Color(0, 0, 0, 255));

	Text scanText;
	scanText.setFont(Cannon);
	scanText.setCharacterSize(55);
	scanText.setStyle(Text::Bold);
	scanText.setFillColor(Color(0, 0, 0, 255));

	Text fontText;
	fontText.setFont(Cannon);
	fontText.setCharacterSize(55);
	fontText.setStyle(Text::Bold);
	fontText.setFillColor(Color(0, 0, 0, 255));

	Text fullscreenText;
	fullscreenText.setFont(Cannon);
	fullscreenText.setCharacterSize(55);
	fullscreenText.setStyle(Text::Bold);
	fullscreenText.setFillColor(Color(0, 0, 0, 255));

	Text vsyncText;
	vsyncText.setFont(Cannon);
	vsyncText.setCharacterSize(55);
	vsyncText.setStyle(Text::Bold);
	vsyncText.setFillColor(Color(0, 0, 0, 255));

	Text unlimitedText;
	unlimitedText.setFont(Cannon);
	unlimitedText.setCharacterSize(55);
	unlimitedText.setStyle(Text::Bold);
	unlimitedText.setFillColor(Color(0, 0, 0, 255));

	Text MPWarningBoxText;
	MPWarningBoxText.setFont(Cannon);
	MPWarningBoxText.setCharacterSize(55);
	MPWarningBoxText.setStyle(Text::Bold);
	MPWarningBoxText.setFillColor(Color(0, 0, 0, 255));

	Text treasureText;
	treasureText.setFont(Cannon);
	treasureText.setCharacterSize(70);
	treasureText.setStyle(Text::Bold);
	treasureText.setFillColor(Color(0, 0, 0, 255));

	Text treasureText1;
	treasureText1.setFont(Cannon);
	treasureText1.setCharacterSize(70);
	treasureText1.setStyle(Text::Bold);
	treasureText1.setFillColor(Color(0, 0, 0, 255));

	Text eventText;
	eventText.setFont(Cannon);
	eventText.setCharacterSize(50);
	eventText.setLineSpacing(1.4);
	eventText.setStyle(Text::Bold);
	eventText.setFillColor(Color(0, 0, 0, 255));

	Text textboxText;
	textboxText.setFont(Cannon);
	textboxText.setCharacterSize(60);
	textboxText.setStyle(Text::Bold);
	textboxText.setFillColor(Color(0, 0, 0, 255));

	Text frameBoxText;
	frameBoxText.setFont(Cannon);
	frameBoxText.setCharacterSize(60);
	frameBoxText.setStyle(Text::Bold);
	frameBoxText.setFillColor(Color(0, 0, 0, 255));

	Text chatBoxText;
	chatBoxText.setFont(Cannon);
	chatBoxText.setCharacterSize(30);
	chatBoxText.setStyle(Text::Bold);
	chatBoxText.setFillColor(Color(0, 0, 0, 255));

	Text chatText;
	chatText.setFont(Cannon);
	chatText.setCharacterSize(40);
	chatText.setStyle(Text::Bold);
	chatText.setFillColor(Color(0, 0, 0, 255));

	Text rewardText;
	rewardText.setFont(Cannon);
	rewardText.setCharacterSize(70);
	rewardText.setStyle(Text::Bold);
	rewardText.setFillColor(Color(0, 0, 0, 255));

	Text versionText;
	versionText.setFont(Cannon);
	versionText.setCharacterSize(40);
	versionText.setStyle(Text::Bold);
	versionText.setFillColor(Color(0, 0, 0, 255));

	Text MPWarningText;
	MPWarningText.setFont(Cannon);
	MPWarningText.setCharacterSize(60);
	MPWarningText.setStyle(Text::Bold);
	MPWarningText.setFillColor(Color(0, 0, 0, 255));

	Text MP1Text;
	MP1Text.setFont(Cannon);
	MP1Text.setCharacterSize(45);
	MP1Text.setStyle(Text::Bold);
	MP1Text.setFillColor(Color(0, 0, 0, 255));

	Text MP2Text;
	MP2Text.setFont(Cannon);
	MP2Text.setCharacterSize(45);
	MP2Text.setStyle(Text::Bold);
	MP2Text.setFillColor(Color(0, 0, 0, 255));

	Text joinText;
	joinText.setFont(Cannon);
	joinText.setCharacterSize(35);
	joinText.setStyle(Text::Bold);
	joinText.setFillColor(Color(0, 0, 0, 255));

	Text steamText;
	steamText.setFont(Cannon);
	steamText.setCharacterSize(35);
	steamText.setStyle(Text::Bold);
	steamText.setFillColor(Color(0, 0, 0, 255));
	steamText.setString("");

	Text rulesText;
	rulesText.setFont(Cannon);
	rulesText.setCharacterSize(40);
	rulesText.setStyle(Text::Bold);
	rulesText.setFillColor(Color(0, 0, 0, 255));

	Text devText;
	devText.setFont(Cannon);
	devText.setCharacterSize(90);
	devText.setStyle(Text::Bold);
	devText.setFillColor(Color(0, 0, 0, 255));

	Text newYearsText;
	newYearsText.setFont(Cannon);
	newYearsText.setCharacterSize(90);
	newYearsText.setStyle(Text::Bold);
	newYearsText.setFillColor(Color(0, 0, 0, 255));

	Text easterText;
	easterText.setFont(Cannon);
	easterText.setCharacterSize(40);
	easterText.setStyle(Text::Bold);
	easterText.setFillColor(Color(0, 0, 0, 255));

	Text patrickText;
	patrickText.setFont(Cannon);
	patrickText.setCharacterSize(40);
	patrickText.setStyle(Text::Bold);
	patrickText.setFillColor(Color(0, 0, 0, 255));

	Text julyText;
	julyText.setFont(Cannon);
	julyText.setCharacterSize(40);
	julyText.setStyle(Text::Bold);
	julyText.setFillColor(Color(0, 0, 0, 255));

	Text halloweenText;
	halloweenText.setFont(Cannon);
	halloweenText.setCharacterSize(40);
	halloweenText.setStyle(Text::Bold);
	halloweenText.setFillColor(Color(0, 0, 0, 255));

	Text thanksgivingText;
	thanksgivingText.setFont(Cannon);
	thanksgivingText.setCharacterSize(40);
	thanksgivingText.setStyle(Text::Bold);
	thanksgivingText.setFillColor(Color(0, 0, 0, 255));

	Text winterText;
	winterText.setFont(Cannon);
	winterText.setCharacterSize(40);
	winterText.setStyle(Text::Bold);
	winterText.setFillColor(Color(0, 0, 0, 255));

	// Alternate Textures
	Texture buyButtonAltTexture;
	buyButtonAltTexture.loadFromFile("assets/buttons/alternate/buyButton_alt.png");
	Texture claimButtonAltTexture;
	claimButtonAltTexture.loadFromFile("assets/buttons/alternate/claimButton_alt.png");
	Texture claimedButtonAltTexture;
	claimedButtonAltTexture.loadFromFile("assets/buttons/alternate/claimedButton_alt.png");
	Texture exitButtonAltTexture;
	exitButtonAltTexture.loadFromFile("assets/buttons/alternate/exitButton_alt.png");
	Texture okButtonAltTexture;
	okButtonAltTexture.loadFromFile("assets/buttons/alternate/okButton_alt.png");
	Texture resetDataButtonAltTexture;
	resetDataButtonAltTexture.loadFromFile("assets/buttons/alternate/resetDataButton_alt.png");
	Texture returnButtonAltTexture;
	returnButtonAltTexture.loadFromFile("assets/buttons/alternate/returnButton_alt.png");
	Texture saveButtonAltTexture;
	saveButtonAltTexture.loadFromFile("assets/buttons/alternate/saveButton_alt.png");
	Texture playButtonAltTexture;
	playButtonAltTexture.loadFromFile("assets/buttons/alternate/playButton_alt.png");
	Texture leaderboardButtonAltTexture;
	leaderboardButtonAltTexture.loadFromFile("assets/buttons/alternate/leaderboardButton_alt.png");
	Texture creditsButtonAltTexture;
	creditsButtonAltTexture.loadFromFile("assets/buttons/alternate/creditsButton_alt.png");
	Texture settingsButtonAltTexture;
	settingsButtonAltTexture.loadFromFile("assets/buttons/alternate/settingsButton_alt.png");
	Texture shopButtonAltTexture;
	shopButtonAltTexture.loadFromFile("assets/buttons/alternate/shopButton_alt.png");
	Texture skinsButtonAltTexture;
	skinsButtonAltTexture.loadFromFile("assets/buttons/alternate/skinsButton_alt.png");
	Texture versusButtonAltTexture;
	versusButtonAltTexture.loadFromFile("assets/buttons/alternate/versusButton_alt.png");
	Texture seasonalShopButtonAltTexture;
	seasonalShopButtonAltTexture.loadFromFile("assets/buttons/alternate/seasonalShopButton_alt.png");

	Texture price1AltTexture;
	price1AltTexture.loadFromFile("assets/other/alternate/price500_alt.png");
	Texture price11AltTexture;
	price11AltTexture.loadFromFile("assets/other/alternate/price5001_alt.png");
	Texture price2AltTexture;
	price2AltTexture.loadFromFile("assets/other/alternate/price750_alt.png");
	Texture price22AltTexture;
	price22AltTexture.loadFromFile("assets/other/alternate/price7501_alt.png");
	Texture price3AltTexture;
	price3AltTexture.loadFromFile("assets/other/alternate/price1000_alt.png");
	Texture price33AltTexture;
	price33AltTexture.loadFromFile("assets/other/alternate/price10001_alt.png");
	Texture price4AltTexture;
	price4AltTexture.loadFromFile("assets/other/alternate/price1500_alt.png");
	Texture price44AltTexture;
	price44AltTexture.loadFromFile("assets/other/alternate/price15001_alt.png");
	Texture price55AltTexture;
	price55AltTexture.loadFromFile("assets/other/alternate/price100001_alt.png");
	Texture price6AltTexture;
	price6AltTexture.loadFromFile("assets/other/alternate/price15000_alt.png");
	Texture price66AltTexture;
	price66AltTexture.loadFromFile("assets/other/alternate/price150001_alt.png");

	Texture cannoneerTexture;
	cannoneerTexture.loadFromFile("assets/other/cannoneer.png");
	Texture cannoneerAltTexture;
	cannoneerAltTexture.loadFromFile("assets/other/alternate/cannoneer_alt.png");
	Sprite cannoneer;
	cannoneer.setTexture(cannoneerTexture);
	cannoneer.setOrigin(227, 127.5);
	cannoneer.setScale(1.1, 1.1);
	cannoneer.setPosition(960, 150);

	Texture wasdTexture;
	wasdTexture.loadFromFile("assets/other/WASD.png");
	Sprite wasd;
	wasd.setTexture(wasdTexture);
	wasd.setOrigin(227, 127.5);
	wasd.setScale(1.1, 1.1);
	wasd.setPosition(960, 150);

	Texture santaTexture;
	santaTexture.loadFromFile("assets/other/vaultSanta.png");
	Sprite santa;
	santa.setTexture(santaTexture);
	santa.setOrigin(9.5f, 27.5f);
	santa.setScale(9, 9);
	santa.setPosition(960, 400);

	RectangleShape textbox;
	textbox.setPosition(960, 750);
	textbox.setSize(Vector2f(100, 40));
	textbox.setScale(2, 2);
	textbox.setOrigin(50, 20);
	textbox.setFillColor(Color(78, 78, 78));
	textbox.setOutlineColor(Color(58, 58, 58));
	textbox.setOutlineThickness(5);

	RectangleShape frameBox;
	frameBox.setPosition(480, 340);
	frameBox.setSize(Vector2f(100, 40));
	frameBox.setScale(2, 2);
	frameBox.setOrigin(50, 20);
	frameBox.setFillColor(Color(78, 78, 78));
	frameBox.setOutlineColor(Color(58, 58, 58));
	frameBox.setOutlineThickness(5);

	RectangleShape scanlinesBox;
	scanlinesBox.setPosition(870, 700);
	scanlinesBox.setSize(Vector2f(20, 20));
	scanlinesBox.setScale(2, 2);
	scanlinesBox.setOrigin(50, 20);
	scanlinesBox.setOutlineColor(Color(0, 0, 0));
	scanlinesBox.setOutlineThickness(5);

	RectangleShape fontBox;
	fontBox.setPosition(870, 785);
	fontBox.setSize(Vector2f(20, 20));
	fontBox.setScale(2, 2);
	fontBox.setOrigin(50, 20);
	fontBox.setOutlineColor(Color(0, 0, 0));
	fontBox.setOutlineThickness(5);

	RectangleShape fullscreenBox;
	fullscreenBox.setPosition(870, 870);
	fullscreenBox.setSize(Vector2f(20, 20));
	fullscreenBox.setScale(2, 2);
	fullscreenBox.setOrigin(50, 20);
	fullscreenBox.setOutlineColor(Color(0, 0, 0));
	fullscreenBox.setOutlineThickness(5);

	RectangleShape vsyncBox;
	vsyncBox.setPosition(380, 450);
	vsyncBox.setSize(Vector2f(20, 20));
	vsyncBox.setScale(2, 2);
	vsyncBox.setOrigin(50, 20);
	vsyncBox.setOutlineColor(Color(0, 0, 0));
	vsyncBox.setOutlineThickness(5);

	RectangleShape unlimitedBox;
	unlimitedBox.setPosition(380, 535);
	unlimitedBox.setSize(Vector2f(20, 20));
	unlimitedBox.setScale(2, 2);
	unlimitedBox.setOrigin(50, 20);
	unlimitedBox.setOutlineColor(Color(0, 0, 0));
	unlimitedBox.setOutlineThickness(5);

	RectangleShape MPWarningBox;
	MPWarningBox.setPosition(840, 650);
	MPWarningBox.setSize(Vector2f(20, 20));
	MPWarningBox.setScale(2, 2);
	MPWarningBox.setOrigin(50, 20);
	MPWarningBox.setOutlineColor(Color(0, 0, 0));
	MPWarningBox.setOutlineThickness(5);

	RectangleShape chatBox;
	chatBox.setPosition(300.0f, 600.0f);
	chatBox.setSize(Vector2f(100, 40));
	chatBox.setScale(2, 2);
	chatBox.setOrigin(50, 20);
	chatBox.setFillColor(Color(78, 78, 78));
	chatBox.setOutlineColor(Color(58, 58, 58));
	chatBox.setOutlineThickness(5);

	if (scanlines) {
		scanlinesBox.setFillColor(Color(0, 0, 0, 255));
	} else {
		scanlinesBox.setFillColor(Color(38, 38, 38, 255));
	}

	if (altFont) {
		fontBox.setFillColor(Color(0, 0, 0, 255));
	} else {
		fontBox.setFillColor(Color(38, 38, 38, 255));
	}

	if (fullscreen) {
		fullscreenBox.setFillColor(Color(0, 0, 0, 255));
	}
	else {
		fullscreenBox.setFillColor(Color(38, 38, 38, 255));
	}

	if (!showMPWarning) {
		MPWarningBox.setFillColor(Color(0, 0, 0, 255));
	} else {
		MPWarningBox.setFillColor(Color(38, 38, 38, 255));
	}

	// Create player
	Texture playerTexture;
	playerTexture.loadFromFile("assets/cannons/cannon.png");
	Texture peashooterCannonTexture;
	peashooterCannonTexture.loadFromFile("assets/cannons/peashooterCannon.png");
	Texture yippeeCannonTexture;
	yippeeCannonTexture.loadFromFile("assets/cannons/yippeeCannon.png");
	Texture sugarCannonTexture;
	sugarCannonTexture.loadFromFile("assets/cannons/sugarCannon.png");
	Texture fireCannonTexture;
	fireCannonTexture.loadFromFile("assets/cannons/fireCannon.png");
	Texture christmasCannonTexture;
	christmasCannonTexture.loadFromFile("assets/cannons/christmasCannon.png");
	Texture flameCannonTexture;
	flameCannonTexture.loadFromFile("assets/cannons/flameCannon.png");
	Texture goldenCannonTexture;
	goldenCannonTexture.loadFromFile("assets/cannons/goldenCannon.png");
	Texture logicalCannonTexture;
	logicalCannonTexture.loadFromFile("assets/cannons/logicalCannon.png");
	Texture gingerbreadCannonTexture;
	gingerbreadCannonTexture.loadFromFile("assets/cannons/gingerbreadCannon.png");
	Texture snowmanCannonTexture;
	snowmanCannonTexture.loadFromFile("assets/cannons/snowmanCannon.png");
	Texture presentCannonTexture;
	presentCannonTexture.loadFromFile("assets/cannons/presentCannon.png");
	Texture deadpoolCannonTexture;
	deadpoolCannonTexture.loadFromFile("assets/cannons/deadpoolCannon.png");
	Texture shockCannonTexture;
	shockCannonTexture.loadFromFile("assets/cannons/shockCannon.png");
	Texture birdoCannonTexture;
	birdoCannonTexture.loadFromFile("assets/cannons/birdoCannon.png");
	Texture heartsCannonTexture;
	heartsCannonTexture.loadFromFile("assets/cannons/heartsCannon.png");
	Texture apocCannonTexture;
	apocCannonTexture.loadFromFile("assets/cannons/apocCannon.png");
	Sprite player;
	if (equippedCannon == 0) {
		player.setTexture(playerTexture);
	}
	if (equippedCannon == 1) {
		player.setTexture(christmasCannonTexture);
	}
	if (equippedCannon == 2) {
		player.setTexture(fireCannonTexture);
	}
	if (equippedCannon == 3) {
		player.setTexture(yippeeCannonTexture);
	}
	if (equippedCannon == 4) {
		player.setTexture(goldenCannonTexture);
	}
	if (equippedCannon == 5) {
		player.setTexture(logicalCannonTexture);
	}
	if (equippedCannon == 6) {
		player.setTexture(peashooterCannonTexture);
	}
	if (equippedCannon == 7) {
		player.setTexture(sugarCannonTexture);
	}
	if (equippedCannon == 8) {
		player.setTexture(flameCannonTexture);
	}
	if (equippedCannon == 9) {
		player.setTexture(gingerbreadCannonTexture);
	}
	if (equippedCannon == 10) {
		player.setTexture(snowmanCannonTexture);
	}
	if (equippedCannon == 11) {
		player.setTexture(presentCannonTexture);
	}
	if (equippedCannon == 12) {
		player.setTexture(deadpoolCannonTexture);
	}
	if (equippedCannon == 13) {
		player.setTexture(shockCannonTexture);
	}
	if (equippedCannon == 14) {
		player.setTexture(birdoCannonTexture);
	}
	if (equippedCannon == 15) {
		player.setTexture(heartsCannonTexture);
	}
	if (equippedCannon == 16) {
		player.setTexture(apocCannonTexture);
	}
	player.setOrigin(20.f, 42.f);
	player.setScale(3.f, 3.f);
	player.setPosition(960.f, 540.f);

	RectangleShape playerHitbox1(Vector2f(10, 52));
	playerHitbox1.setOrigin(5, 39);
	playerHitbox1.setScale(2, 2);
	playerHitbox1.setPosition(player.getPosition());
	playerHitbox1.setRotation(player.getRotation());
	playerHitbox1.setFillColor(Color(0, 255, 0, 0));
	playerHitbox1.setOutlineThickness(1.5);
	playerHitbox1.setOutlineColor(Color(0, 255, 0, 255));

	// Create bomb
	Texture bombTexture;
	bombTexture.loadFromFile("assets/cannonballs/cannonball.png");
	Texture yippeeBombTexture;
	yippeeBombTexture.loadFromFile("assets/cannonballs/yippeeCannonball.png");
	Texture fireBombTexture;
	fireBombTexture.loadFromFile("assets/cannonballs/fireCannonball.png");
	Texture icyBombTexture;
	icyBombTexture.loadFromFile("assets/cannonballs/icyCannonball.png");
	Texture orangeBombTexture;
	orangeBombTexture.loadFromFile("assets/cannonballs/orangeCannonball.png");
	Texture peppermintBombTexture;
	peppermintBombTexture.loadFromFile("assets/cannonballs/peppermintCannonball.png");
	Texture santasBombTexture;
	santasBombTexture.loadFromFile("assets/cannonballs/santasCannonball.png");
	Texture bellBombTexture;
	bellBombTexture.loadFromFile("assets/cannonballs/bellCannonball.png");
	Texture yoshiBombTexture;
	yoshiBombTexture.loadFromFile("assets/cannonballs/yoshiCannonball.png");
	Texture birdoBombTexture;
	birdoBombTexture.loadFromFile("assets/cannonballs/birdoCannonball.png");
	Texture logicalBombTexture;
	logicalBombTexture.loadFromFile("assets/cannonballs/logicalCannonball.png");
	Texture apocBombTexture;
	apocBombTexture.loadFromFile("assets/cannonballs/apocCannonball.png");
	Sprite bomb;
	if (equippedBomb == 0) {
		bomb.setTexture(bombTexture);
	}
	if (equippedBomb == 1) {
		bomb.setTexture(fireBombTexture);
	}
	if (equippedBomb == 2) {
		bomb.setTexture(icyBombTexture);
	}
	if (equippedBomb == 3) {
		bomb.setTexture(orangeBombTexture);
	}
	if (equippedBomb == 4) {
		bomb.setTexture(peppermintBombTexture);
	}
	if (equippedBomb == 5) {
		bomb.setTexture(yippeeBombTexture);
	}
	if (equippedBomb == 6) {
		bomb.setTexture(santasBombTexture);
	}
	if (equippedBomb == 7) {
		bomb.setTexture(bellBombTexture);
	}
	if (equippedBomb == 8) {
		bomb.setTexture(yoshiBombTexture);
	}
	if (equippedBomb == 9) {
		bomb.setTexture(birdoBombTexture);
	}
	if (equippedBomb == 10) {
		bomb.setTexture(logicalBombTexture);
	}
	if (equippedBomb == 11) {
		bomb.setTexture(apocBombTexture);
	}
	bomb.setScale(Vector2f(3.f, 3.f));
	bomb.setPosition(960.f, 540.f);
	bomb.setOrigin(8.f, 58.f);

	// Create bomb hitbox
	RectangleShape bombHitbox(Vector2f(6, 6));
	bombHitbox.setOrigin(3.5, 47.5);
	bombHitbox.setScale(3.f, 3.f);
	bombHitbox.setPosition(bomb.getPosition());
	bombHitbox.setRotation(bomb.getRotation());
	bombHitbox.setFillColor(Color(0, 255, 0, 0));
	bombHitbox.setOutlineThickness(1);
	bombHitbox.setOutlineColor(Color(0, 255, 0, 255));

	Texture pauseMenuTexture;
	pauseMenuTexture.loadFromFile("assets/backgrounds/pauseMenu.png");
	Sprite pauseMenu;
	pauseMenu.setTexture(pauseMenuTexture);
	pauseMenu.setOrigin(960.f, 540.f);
	pauseMenu.setPosition(960.f, 540.f);

	Texture gameOverScreenTexture;
	gameOverScreenTexture.loadFromFile("assets/backgrounds/gameOverScreen.png");
	Texture gameOverScreenAltTexture;
	gameOverScreenAltTexture.loadFromFile("assets/backgrounds/gameOverScreen_alt.png");
	Sprite gameOverScreen;
	gameOverScreen.setTexture(gameOverScreenTexture);
	gameOverScreen.setOrigin(960.f, 540.f);
	gameOverScreen.setPosition(960.f, 540.f);

	// Create grenade
	Texture grenadeTexture;
	grenadeTexture.loadFromFile("assets/grenades/grenade.png");
	Texture yippeeGrenadeTexture;
	yippeeGrenadeTexture.loadFromFile("assets/grenades/yippeeGrenade.png");
	Texture fireGrenadeTexture;
	fireGrenadeTexture.loadFromFile("assets/grenades/fireGrenade.png");
	Texture chocolateGrenadeTexture;
	chocolateGrenadeTexture.loadFromFile("assets/grenades/chocolateGrenade.png");
	Texture logicalGrenadeTexture;
	logicalGrenadeTexture.loadFromFile("assets/grenades/logicalGrenade.png");
	Texture christmasGrenadeTexture;
	christmasGrenadeTexture.loadFromFile("assets/grenades/christmasGrenade.png");
	Texture garlandGrenadeTexture;
	garlandGrenadeTexture.loadFromFile("assets/grenades/garlandGrenade.png");
	Texture iceGrenadeTexture;
	iceGrenadeTexture.loadFromFile("assets/grenades/iceGrenade.png");
	Texture santaGrenadeTexture;
	santaGrenadeTexture.loadFromFile("assets/grenades/santaGrenade.png");
	Texture dynamiteGrenadeTexture;
	dynamiteGrenadeTexture.loadFromFile("assets/grenades/dynamiteGrenade.png");
	Texture nukeGrenadeTexture;
	nukeGrenadeTexture.loadFromFile("assets/grenades/nukeGrenade.png");
	Texture smokeGrenadeTexture;
	smokeGrenadeTexture.loadFromFile("assets/grenades/smokeGrenade.png");
	Texture holyHandGrenadeTexture;
	holyHandGrenadeTexture.loadFromFile("assets/grenades/holyHandGrenade.png");
	Texture apocGrenadeTexture;
	apocGrenadeTexture.loadFromFile("assets/grenades/apocGrenade.png");
	Sprite grenade;
	if (equippedGrenade == 0) {
		grenade.setTexture(grenadeTexture);
	}
	if (equippedGrenade == 1) {
		grenade.setTexture(fireGrenadeTexture);
	}
	if (equippedGrenade == 2) {
		grenade.setTexture(yippeeGrenadeTexture);
	}
	if (equippedGrenade == 3) {
		grenade.setTexture(logicalGrenadeTexture);
	}
	if (equippedGrenade == 4) {
		grenade.setTexture(chocolateGrenadeTexture);
	}
	if (equippedGrenade == 5) {
		grenade.setTexture(christmasGrenadeTexture);
	}
	if (equippedGrenade == 6) {
		grenade.setTexture(garlandGrenadeTexture);
	}
	if (equippedGrenade == 7) {
		grenade.setTexture(iceGrenadeTexture);
	}
	if (equippedGrenade == 8) {
		grenade.setTexture(santaGrenadeTexture);
	}
	if (equippedGrenade == 9) {
		grenade.setTexture(dynamiteGrenadeTexture);
	}
	if (equippedGrenade == 10) {
		grenade.setTexture(nukeGrenadeTexture);
	}
	if (equippedGrenade == 11) {
		grenade.setTexture(smokeGrenadeTexture);
	}
	if (equippedGrenade == 12) {
		grenade.setTexture(holyHandGrenadeTexture);
	}
	if (equippedGrenade == 13) {
		grenade.setTexture(apocGrenadeTexture);
	}
	grenade.setScale(3.f, 3.f);
	grenade.setPosition(3840.f, 2160.f);
	grenade.setOrigin(8.f, 58.f);

	// Create grenade hitbox
	RectangleShape grenadeHitbox(Vector2f(6, 6));
	grenadeHitbox.setOrigin(3.5, 47.5);
	grenadeHitbox.setScale(3.f, 3.f);
	grenadeHitbox.setPosition(grenade.getPosition());
	grenadeHitbox.setRotation(grenade.getRotation());
	grenadeHitbox.setFillColor(Color(0, 255, 0, 0));
	grenadeHitbox.setOutlineThickness(1.f);
	grenadeHitbox.setOutlineColor(Color(0, 255, 0, 255));

	// Create explosion
	Texture explosionTexture;
	explosionTexture.loadFromFile("assets/explosions/explosion.png");
	Texture yippeeExplosionTexture;
	yippeeExplosionTexture.loadFromFile("assets/explosions/yippeeExplosion.png");
	Texture festiveExplosionTexture;
	festiveExplosionTexture.loadFromFile("assets/explosions/festiveExplosion.png");
	Texture gingerbreadExplosionTexture;
	gingerbreadExplosionTexture.loadFromFile("assets/explosions/gingerbreadExplosion.png");
	Texture snowyExplosionTexture;
	snowyExplosionTexture.loadFromFile("assets/explosions/snowyExplosion.png");
	Texture elfExplosionTexture;
	elfExplosionTexture.loadFromFile("assets/explosions/elfExplosion.png");
	Texture snowExplosionTexture;
	snowExplosionTexture.loadFromFile("assets/explosions/snowExplosion.png");
	Texture logicalExplosionTexture;
	logicalExplosionTexture.loadFromFile("assets/explosions/logicalExplosion.png");
	Texture mushroomExplosionTexture;
	mushroomExplosionTexture.loadFromFile("assets/explosions/mushroomExplosion.png");
	Texture smokeExplosionTexture;
	smokeExplosionTexture.loadFromFile("assets/explosions/smokeExplosion.png");
	Texture apocExplosionTexture;
	apocExplosionTexture.loadFromFile("assets/explosions/apocExplosion.png");
	Sprite explosion;
	if (equippedExplosion == 0) {
		explosion.setTexture(explosionTexture);
	}
	if (equippedExplosion == 1) {
		explosion.setTexture(yippeeExplosionTexture);
	}
	if (equippedExplosion == 2) {
		explosion.setTexture(festiveExplosionTexture);
	}
	if (equippedExplosion == 3) {
		explosion.setTexture(snowyExplosionTexture);
	}
	if (equippedExplosion == 4) {
		explosion.setTexture(gingerbreadExplosionTexture);
	}
	if (equippedExplosion == 5) {
		explosion.setTexture(elfExplosionTexture);
	}
	if (equippedExplosion == 6) {
		explosion.setTexture(snowExplosionTexture);
	}
	if (equippedExplosion == 7) {
		explosion.setTexture(logicalExplosionTexture);
	}
	if (equippedExplosion == 8) {
		explosion.setTexture(mushroomExplosionTexture);
	}
	if (equippedExplosion == 9) {
		explosion.setTexture(smokeExplosionTexture);
	}
	if (equippedExplosion == 10) {
		explosion.setTexture(apocExplosionTexture);
	}
	explosion.setScale(10.f, 10.f);
	explosion.setOrigin(17.f, 18.f);
	explosion.setPosition(5760.f, 3240.f);

	// Create planes
	Texture planeTexture;
	planeTexture.loadFromFile("assets/planes/plane.png");
	Texture yippeePlaneTexture;
	yippeePlaneTexture.loadFromFile("assets/planes/yippeePlane.png");
	Texture firePlaneTexture;
	firePlaneTexture.loadFromFile("assets/planes/firePlane.png");
	Texture logicalPlaneTexture;
	logicalPlaneTexture.loadFromFile("assets/planes/logicalPlane.png");
	Texture cookiePlaneTexture;
	cookiePlaneTexture.loadFromFile("assets/planes/cookiePlane.png");
	Texture festivePlaneTexture;
	festivePlaneTexture.loadFromFile("assets/planes/festivePlane.png");
	Texture rudolphPlaneTexture;
	rudolphPlaneTexture.loadFromFile("assets/planes/rudolphPlane.png");
	Texture santasPlaneTexture;
	santasPlaneTexture.loadFromFile("assets/planes/santasPlane.png");
	Texture treePlaneTexture;
	treePlaneTexture.loadFromFile("assets/planes/treePlane.png");
	Texture fighterPlaneTexture;
	fighterPlaneTexture.loadFromFile("assets/planes/fighterPlane.png");
	Texture apocPlaneTexture;
	apocPlaneTexture.loadFromFile("assets/planes/apocPlane.png");
	Sprite plane1;
	plane1.setScale(3.f, 3.f);
	plane1.setOrigin(16.f, 16.f);
	Sprite plane2;
	plane2.setScale(3.f, 3.f);
	plane2.setOrigin(16.f, 16.f);
	Sprite plane3;
	plane3.setScale(3.f, 3.f);
	plane3.setOrigin(16.f, 16.f);
	Sprite plane4;
	plane4.setScale(3.f, 3.f);
	plane4.setOrigin(16.f, 16.f);
	Sprite plane5;
	plane5.setScale(3.f, 3.f);
	plane5.setOrigin(16.f, 16.f);
	Sprite plane6;
	plane6.setScale(3.f, 3.f);
	plane6.setOrigin(16.f, 16.f);

	if (equippedPlane == 0) {
		plane1.setTexture(planeTexture);
		plane2.setTexture(planeTexture);
		plane3.setTexture(planeTexture);
		plane4.setTexture(planeTexture);
		plane5.setTexture(planeTexture);
		plane6.setTexture(planeTexture);
	}
	if (equippedPlane == 1) {
		plane1.setTexture(yippeePlaneTexture);
		plane2.setTexture(yippeePlaneTexture);
		plane3.setTexture(yippeePlaneTexture);
		plane4.setTexture(yippeePlaneTexture);
		plane5.setTexture(yippeePlaneTexture);
		plane6.setTexture(yippeePlaneTexture);
	}
	if (equippedPlane == 2) {
		plane1.setTexture(firePlaneTexture);
		plane2.setTexture(firePlaneTexture);
		plane3.setTexture(firePlaneTexture);
		plane4.setTexture(firePlaneTexture);
		plane5.setTexture(firePlaneTexture);
		plane6.setTexture(firePlaneTexture);
	}
	if (equippedPlane == 3) {
		plane1.setTexture(logicalPlaneTexture);
		plane2.setTexture(logicalPlaneTexture);
		plane3.setTexture(logicalPlaneTexture);
		plane4.setTexture(logicalPlaneTexture);
		plane5.setTexture(logicalPlaneTexture);
		plane6.setTexture(logicalPlaneTexture);
	}
	if (equippedPlane == 4) {
		plane1.setTexture(festivePlaneTexture);
		plane2.setTexture(festivePlaneTexture);
		plane3.setTexture(festivePlaneTexture);
		plane4.setTexture(festivePlaneTexture);
		plane5.setTexture(festivePlaneTexture);
		plane6.setTexture(festivePlaneTexture);
	}
	if (equippedPlane == 5) {
		plane1.setTexture(cookiePlaneTexture);
		plane2.setTexture(cookiePlaneTexture);
		plane3.setTexture(cookiePlaneTexture);
		plane4.setTexture(cookiePlaneTexture);
		plane5.setTexture(cookiePlaneTexture);
		plane6.setTexture(cookiePlaneTexture);
	}
	if (equippedPlane == 6) {
		plane1.setTexture(rudolphPlaneTexture);
		plane2.setTexture(rudolphPlaneTexture);
		plane3.setTexture(rudolphPlaneTexture);
		plane4.setTexture(rudolphPlaneTexture);
		plane5.setTexture(rudolphPlaneTexture);
		plane6.setTexture(rudolphPlaneTexture);
	}
	if (equippedPlane == 7) {
		plane1.setTexture(santasPlaneTexture);
		plane2.setTexture(santasPlaneTexture);
		plane3.setTexture(santasPlaneTexture);
		plane4.setTexture(santasPlaneTexture);
		plane5.setTexture(santasPlaneTexture);
		plane6.setTexture(santasPlaneTexture);
	}
	if (equippedPlane == 8) {
		plane1.setTexture(treePlaneTexture);
		plane2.setTexture(treePlaneTexture);
		plane3.setTexture(treePlaneTexture);
		plane4.setTexture(treePlaneTexture);
		plane5.setTexture(treePlaneTexture);
		plane6.setTexture(treePlaneTexture);
	}
	if (equippedPlane == 9) {
		plane1.setTexture(fighterPlaneTexture);
		plane2.setTexture(fighterPlaneTexture);
		plane3.setTexture(fighterPlaneTexture);
		plane4.setTexture(fighterPlaneTexture);
		plane5.setTexture(fighterPlaneTexture);
		plane6.setTexture(fighterPlaneTexture);
	}
	if (equippedPlane == 10) {
		plane1.setTexture(apocPlaneTexture);
		plane2.setTexture(apocPlaneTexture);
		plane3.setTexture(apocPlaneTexture);
		plane4.setTexture(apocPlaneTexture);
		plane5.setTexture(apocPlaneTexture);
		plane6.setTexture(apocPlaneTexture);
	}

	RectangleShape plane1Hitbox(Vector2f(26.f, 26.f));
	plane1Hitbox.setOrigin(13.f, 13.f);
	plane1Hitbox.setScale(3.f, 3.f);
	plane1Hitbox.setPosition(plane1.getPosition());
	plane1Hitbox.setFillColor(Color(0, 255, 0, 0));
	plane1Hitbox.setOutlineThickness(1.f);
	plane1Hitbox.setOutlineColor(Color(255, 0, 0, 255));
	RectangleShape plane2Hitbox(Vector2f(26.f, 26.f));
	plane2Hitbox.setOrigin(13.f, 13.f);
	plane2Hitbox.setScale(3.f, 3.f);
	plane2Hitbox.setPosition(plane2.getPosition());
	plane2Hitbox.setFillColor(Color(0, 255, 0, 0));
	plane2Hitbox.setOutlineThickness(1.f);
	plane2Hitbox.setOutlineColor(Color(0, 255, 0, 255));
	RectangleShape plane3Hitbox(Vector2f(26.f, 26.f));
	plane3Hitbox.setOrigin(13.f, 13.f);
	plane3Hitbox.setScale(3.f, 3.f);
	plane3Hitbox.setPosition(plane3.getPosition());
	plane3Hitbox.setFillColor(Color(0, 255, 0, 0));
	plane3Hitbox.setOutlineThickness(1.f);
	plane3Hitbox.setOutlineColor(Color(0, 0, 255, 255));
	RectangleShape plane4Hitbox(Vector2f(26.f, 26.f));
	plane4Hitbox.setOrigin(13.f, 13.f);
	plane4Hitbox.setScale(3.f, 3.f);
	plane4Hitbox.setPosition(plane4.getPosition());
	plane4Hitbox.setFillColor(Color(0, 255, 0, 0));
	plane4Hitbox.setOutlineThickness(1.f);
	plane4Hitbox.setOutlineColor(Color(0, 255, 255, 255));
	RectangleShape plane5Hitbox(Vector2f(26.f, 26.f));
	plane5Hitbox.setOrigin(13.f, 13.f);
	plane5Hitbox.setScale(3.f, 3.f);
	plane5Hitbox.setPosition(plane5.getPosition());
	plane5Hitbox.setFillColor(Color(0, 255, 0, 0));
	plane5Hitbox.setOutlineThickness(1.f);
	plane5Hitbox.setOutlineColor(Color(255, 255, 0, 255));
	RectangleShape plane6Hitbox(Vector2f(26.f, 26.f));
	plane6Hitbox.setOrigin(13.f, 13.f);
	plane6Hitbox.setScale(3.f, 3.f);
	plane6Hitbox.setPosition(plane6.getPosition());
	plane6Hitbox.setFillColor(Color(0, 255, 0, 0));
	plane6Hitbox.setOutlineThickness(1.f);
	plane6Hitbox.setOutlineColor(Color(255, 255, 255, 255));

	// Create death effect
	Texture deathEffectTexture;
	deathEffectTexture.loadFromFile("assets/other/deathEffect.png");
	IntRect frame1(0, 0, 512, 512);
	IntRect frame2(0, 0, 512, 512);
	IntRect frame3(0, 0, 512, 512);
	IntRect frame4(0, 0, 512, 512);
	IntRect frame5(0, 0, 512, 512);
	IntRect frame6(0, 0, 512, 512);
	Sprite deathEffect1(deathEffectTexture, frame1);
	deathEffect1.setOrigin(256.f, 256.f);
	deathEffect1.setScale(0.2f, 0.2f);
	Sprite deathEffect2(deathEffectTexture, frame2);
	deathEffect2.setOrigin(256.f, 256.f);
	deathEffect2.setScale(0.2f, 0.2f);
	Sprite deathEffect3(deathEffectTexture, frame3);
	deathEffect3.setOrigin(256.f, 256.f);
	deathEffect3.setScale(0.2f, 0.2f);
	Sprite deathEffect4(deathEffectTexture, frame4);
	deathEffect4.setOrigin(256.f, 256.f);
	deathEffect4.setScale(0.2f, 0.2f);
	Sprite deathEffect5(deathEffectTexture, frame5);
	deathEffect5.setOrigin(256.f, 256.f);
	deathEffect5.setScale(0.2f, 0.2f);
	Sprite deathEffect6(deathEffectTexture, frame6);
	deathEffect6.setOrigin(256.f, 256.f);
	deathEffect6.setScale(0.2f, 0.2f);

	Sprite MP1deathEffect1(deathEffectTexture, frame1);
	MP1deathEffect1.setOrigin(256.f, 256.f);
	MP1deathEffect1.setScale(0.2f, 0.2f);
	Sprite MP1deathEffect2(deathEffectTexture, frame2);
	MP1deathEffect2.setOrigin(256.f, 256.f);
	MP1deathEffect2.setScale(0.2f, 0.2f);
	Sprite MP1deathEffect3(deathEffectTexture, frame3);
	MP1deathEffect3.setOrigin(256.f, 256.f);
	MP1deathEffect3.setScale(0.2f, 0.2f);
	Sprite MP1deathEffect4(deathEffectTexture, frame4);
	MP1deathEffect4.setOrigin(256.f, 256.f);
	MP1deathEffect4.setScale(0.2f, 0.2f);
	Sprite MP1deathEffect5(deathEffectTexture, frame5);
	MP1deathEffect5.setOrigin(256.f, 256.f);
	MP1deathEffect5.setScale(0.2f, 0.2f);
	Sprite MP1deathEffect6(deathEffectTexture, frame6);
	MP1deathEffect6.setOrigin(256.f, 256.f);
	MP1deathEffect6.setScale(0.2f, 0.2f);

	Sprite MP2deathEffect1(deathEffectTexture, frame1);
	MP2deathEffect1.setOrigin(256.f, 256.f);
	MP2deathEffect1.setScale(0.2f, 0.2f);
	Sprite MP2deathEffect2(deathEffectTexture, frame2);
	MP2deathEffect2.setOrigin(256.f, 256.f);
	MP2deathEffect2.setScale(0.2f, 0.2f);
	Sprite MP2deathEffect3(deathEffectTexture, frame3);
	MP2deathEffect3.setOrigin(256.f, 256.f);
	MP2deathEffect3.setScale(0.2f, 0.2f);
	Sprite MP2deathEffect4(deathEffectTexture, frame4);
	MP2deathEffect4.setOrigin(256.f, 256.f);
	MP2deathEffect4.setScale(0.2f, 0.2f);
	Sprite MP2deathEffect5(deathEffectTexture, frame5);
	MP2deathEffect5.setOrigin(256.f, 256.f);
	MP2deathEffect5.setScale(0.2f, 0.2f);
	Sprite MP2deathEffect6(deathEffectTexture, frame6);
	MP2deathEffect6.setOrigin(256.f, 256.f);
	MP2deathEffect6.setScale(0.2f, 0.2f);

	Clock anim;
	Clock MP1anim;
	Clock MP2anim;

	// Create mouse hitbox
	RectangleShape mouseHitbox(Vector2f(8.f, 8.f));
	mouseHitbox.setOrigin(2.f, 2.f);
	mouseHitbox.setFillColor(Color(0, 0, 0, 0));
	mouseHitbox.setOutlineThickness(1.5f);
	mouseHitbox.setOutlineColor(Color(0, 255, 0, 255));

	// Create buttons
	Texture playButtonTexture;
	playButtonTexture.loadFromFile("assets/buttons/playButton.png");
	Sprite playButton;
	playButton.setTexture(playButtonTexture);
	playButton.setScale(3.f, 3.f);
	playButton.setOrigin(64.f, 32.f);
	playButton.setPosition(744.f, 420.f);
	Texture leaderboardButtonTexture;
	leaderboardButtonTexture.loadFromFile("assets/buttons/leaderboardButton.png");
	Sprite leaderboardButton;
	leaderboardButton.setTexture(leaderboardButtonTexture);
	leaderboardButton.setScale(3.f, 3.f);
	leaderboardButton.setOrigin(64.f, 32.f);
	leaderboardButton.setPosition(1608.f, 420.f);
	Texture creditsButtonTexture;
	creditsButtonTexture.loadFromFile("assets/buttons/creditsButton.png");
	Sprite creditsButton;
	creditsButton.setTexture(creditsButtonTexture);
	creditsButton.setScale(3.f, 3.f);
	creditsButton.setOrigin(64.f, 32.f);
	creditsButton.setPosition(1176.f, 660.f);
	Texture settingsButtonTexture;
	settingsButtonTexture.loadFromFile("assets/buttons/settingsButton.png");
	Sprite settingsButton;
	settingsButton.setTexture(settingsButtonTexture);
	settingsButton.setScale(3.f, 3.f);
	settingsButton.setOrigin(64.f, 32.f);
	settingsButton.setPosition(1608.f, 660.f);
	Texture shopButtonTexture;
	shopButtonTexture.loadFromFile("assets/buttons/shopButton.png");
	Sprite shopButton;
	shopButton.setTexture(shopButtonTexture);
	shopButton.setScale(3.f, 3.f);
	shopButton.setOrigin(64.f, 32.f);
	shopButton.setPosition(312.f, 420.f);
	Texture skinsButtonTexture;
	skinsButtonTexture.loadFromFile("assets/buttons/skinsButton.png");
	Sprite skinsButton;
	skinsButton.setTexture(skinsButtonTexture);
	skinsButton.setScale(3.f, 3.f);
	skinsButton.setOrigin(64.f, 32.f);
	skinsButton.setPosition(744.f, 660.f);
	Texture versusButtonTexture;
	versusButtonTexture.loadFromFile("assets/buttons/versusButton.png");
	Sprite versusButton;
	versusButton.setTexture(versusButtonTexture);
	versusButton.setScale(3.f, 3.f);
	versusButton.setOrigin(64.f, 32.f);
	versusButton.setPosition(1176.f, 420.f);
	Texture seasonalShopButtonTexture;
	seasonalShopButtonTexture.loadFromFile("assets/buttons/seasonalShopButton.png");
	Sprite seasonalShopButton;
	seasonalShopButton.setTexture(seasonalShopButtonTexture);
	seasonalShopButton.setScale(3.f, 3.f);
	seasonalShopButton.setOrigin(64.f, 32.f);
	seasonalShopButton.setPosition(312.f, 660.0f);

	Texture comingSoonOverlayTexture;
	comingSoonOverlayTexture.loadFromFile("assets/other/comingSoonOverlay.png");
	Texture comingSoonOverlayAltTexture;
	comingSoonOverlayAltTexture.loadFromFile("assets/other/alternate/comingSoonOverlay_alt.png");
	Sprite comingSoonOverlay;
	comingSoonOverlay.setTexture(comingSoonOverlayTexture);
	comingSoonOverlay.setScale(3.f, 3.f);
	comingSoonOverlay.setOrigin(64.f, 32.f);
	comingSoonOverlay.setPosition(1176.f, 420.f);

	Texture menuButtonTexture;
	menuButtonTexture.loadFromFile("assets/buttons/menuButton.png");
	Texture menuButtonAltTexture;
	menuButtonAltTexture.loadFromFile("assets/buttons/alternate/menuButton_alt.png");
	Sprite menuButton;
	menuButton.setTexture(menuButtonTexture);
	menuButton.setScale(2.0f, 2.0f);
	menuButton.setOrigin(64.f, 32.f);
	menuButton.setPosition(1050.f, 670.f);

	Texture restartButtonTexture;
	restartButtonTexture.loadFromFile("assets/buttons/restartButton.png");
	Texture restartButtonAltTexture;
	restartButtonAltTexture.loadFromFile("assets/buttons/alternate/restartButton_alt.png");
	Sprite restartButton;
	restartButton.setTexture(restartButtonTexture);
	restartButton.setScale(2.0f, 2.0f);
	restartButton.setOrigin(64.f, 32.f);
	restartButton.setPosition(1050.f, 520.f);

	Texture returnButtonTexture;
	returnButtonTexture.loadFromFile("assets/buttons/returnButton.png");
	Texture claimButtonTexture;
	claimButtonTexture.loadFromFile("assets/buttons/claimButton.png");
	Texture okButtonTexture;
	okButtonTexture.loadFromFile("assets/buttons/okButton.png");
	Sprite returnButton;
	if (!altFont) {
		returnButton.setTexture(claimButtonTexture);
	} else {
		returnButton.setTexture(claimButtonAltTexture);
	}
	returnButton.setScale(3.f, 3.f);
	returnButton.setOrigin(64.f, 32.f);
	returnButton.setPosition(960.f, 440.f);
	Texture exitButtonTexture;
	exitButtonTexture.loadFromFile("assets/buttons/exitButton.png");
	Sprite exitButton;
	exitButton.setTexture(exitButtonTexture);
	exitButton.setScale(3.f, 3.f);
	exitButton.setOrigin(64.f, 32.f);
	exitButton.setPosition(960.f, 640.f);
	Texture saveButtonTexture;
	saveButtonTexture.loadFromFile("assets/buttons/saveButton.png");
	Sprite saveButton;
	saveButton.setTexture(saveButtonTexture);
	saveButton.setScale(3.f, 3.f);
	saveButton.setOrigin(64.f, 32.f);
	saveButton.setPosition(960.f, 840.f);

	Texture selectedTexture;
	selectedTexture.loadFromFile("assets/other/select.png");
	Sprite selected;
	selected.setTexture(selectedTexture);
	selected.setOrigin(16.f, 16.f);
	selected.setScale(2.f, 2.f);

	Texture cannonButtonTexture;
	cannonButtonTexture.loadFromFile("assets/buttons/cannonButton.png");
	Sprite cannonButton;
	cannonButton.setTexture(cannonButtonTexture);
	cannonButton.setOrigin(16.f, 16.f);
	cannonButton.setScale(2.f, 2.f);
	cannonButton.setPosition(500 + 92, 650);

	Texture bombButtonTexture;
	bombButtonTexture.loadFromFile("assets/buttons/cannonballButton.png");
	Sprite bombButton;
	bombButton.setTexture(bombButtonTexture);
	bombButton.setOrigin(16.f, 16.f);
	bombButton.setScale(2.f, 2.f);
	bombButton.setPosition(500 + 184 + 92, 650);

	Texture grenadeButtonTexture;
	grenadeButtonTexture.loadFromFile("assets/buttons/grenadeButton.png");
	Sprite grenadeButton;
	grenadeButton.setTexture(grenadeButtonTexture);
	grenadeButton.setOrigin(16.f, 16.f);
	grenadeButton.setScale(2.f, 2.f);
	grenadeButton.setPosition(500 + 184 + 184 + 92, 650);

	Texture explosionButtonTexture;
	explosionButtonTexture.loadFromFile("assets/buttons/explosionButton.png");
	Sprite explosionButton;
	explosionButton.setTexture(explosionButtonTexture);
	explosionButton.setOrigin(16.f, 16.f);
	explosionButton.setScale(2.f, 2.f);
	explosionButton.setPosition(500 + 184 + 184 + 184 + 92, 650);

	Texture planeButtonTexture;
	planeButtonTexture.loadFromFile("assets/buttons/planeButton.png");
	Sprite planeButton;
	planeButton.setTexture(planeButtonTexture);
	planeButton.setOrigin(16.f, 16.f);
	planeButton.setScale(2.f, 2.f);
	planeButton.setPosition(500 + 184 + 184 + 184 + 184 + 92, 650);

	Texture resetDataButtonTexture;
	resetDataButtonTexture.loadFromFile("assets/buttons/resetDataButton.png");
	Sprite resetDataButton;
	resetDataButton.setTexture(resetDataButtonTexture);
	resetDataButton.setScale(3.f, 3.f);
	resetDataButton.setOrigin(64, 32);
	resetDataButton.setPosition(960.f, 700.f);

	Texture unlockAllSkinsButtonTexture;
	unlockAllSkinsButtonTexture.loadFromFile("assets/buttons/unlockAllSkinsButton.png");
	Sprite unlockAllSkinsButton;
	unlockAllSkinsButton.setTexture(unlockAllSkinsButtonTexture);
	unlockAllSkinsButton.setScale(2.0f, 2.0f);
	unlockAllSkinsButton.setOrigin(64.f, 32.f);
	unlockAllSkinsButton.setPosition(400.0f, 100.0f);

	Texture buyButtonTexture;
	buyButtonTexture.loadFromFile("assets/buttons/buyButton.png");
	Texture claimedTexture;
	claimedTexture.loadFromFile("assets/buttons/claimedButton.png");
	Sprite buyButton;
	buyButton.setTexture(buyButtonTexture);
	buyButton.setOrigin(64.f, 32.f);
	buyButton.setPosition(250.f, 500.f);
	Sprite buyButton2;
	buyButton2.setTexture(buyButtonTexture);
	buyButton2.setOrigin(64.f, 32.f);
	buyButton2.setPosition(500.f, 500.f);
	Sprite buyButton3;
	buyButton3.setTexture(buyButtonTexture);
	buyButton3.setOrigin(64.f, 32.f);
	buyButton3.setPosition(750.f, 500.f);
	Sprite buyButton4;
	buyButton4.setTexture(buyButtonTexture);
	buyButton4.setOrigin(64.f, 32.f);
	buyButton4.setPosition(1000.f, 500.f);
	Sprite buyButton7;
	buyButton7.setTexture(buyButtonTexture);
	buyButton7.setOrigin(64.f, 32.f);
	buyButton7.setPosition(1250.f, 500.f);
	Sprite buyButton15;
	buyButton15.setTexture(buyButtonTexture);
	buyButton15.setOrigin(64.f, 32.f);
	buyButton15.setPosition(1500.f, 500.f);
	Sprite buyButton16;
	buyButton16.setTexture(buyButtonTexture);
	buyButton16.setOrigin(64.f, 32.f);
	buyButton16.setPosition(1750.f, 500.f);
	Sprite buyButton17;
	buyButton17.setTexture(buyButtonTexture);
	buyButton17.setOrigin(64.f, 32.f);
	buyButton17.setPosition(250.f, 850.f);
	Sprite buyButton18;
	buyButton18.setTexture(buyButtonTexture);
	buyButton18.setOrigin(64.f, 32.f);
	buyButton18.setPosition(500.f, 850.f);
	Sprite buyButton19;
	buyButton19.setTexture(buyButtonTexture);
	buyButton19.setOrigin(64.f, 32.f);
	buyButton19.setPosition(750.f, 850.f);
	Sprite buyButton31;
	buyButton31.setTexture(buyButtonTexture);
	buyButton31.setOrigin(64.f, 32.f);
	buyButton31.setPosition(1000.0f, 850.f);
	Sprite buyButton5;
	buyButton5.setTexture(buyButtonTexture);
	buyButton5.setOrigin(64.f, 32.f);
	buyButton5.setPosition(250.f, 500.0f);
	Sprite buyButton6;
	buyButton6.setTexture(buyButtonTexture);
	buyButton6.setOrigin(64.f, 32.f);
	buyButton6.setPosition(500.f, 500.0f);
	Sprite buyButton20;
	buyButton20.setTexture(buyButtonTexture);
	buyButton20.setOrigin(64.f, 32.f);
	buyButton20.setPosition(750.f, 500.0f);
	Sprite buyButton21;
	buyButton21.setTexture(buyButtonTexture);
	buyButton21.setOrigin(64.f, 32.f);
	buyButton21.setPosition(1000.0f, 500.0f);
	Sprite buyButton26;
	buyButton26.setTexture(buyButtonTexture);
	buyButton26.setOrigin(64.f, 32.f);
	buyButton26.setPosition(1250.0f, 500.0f);
	Sprite buyButton32;
	buyButton32.setTexture(buyButtonTexture);
	buyButton32.setOrigin(64.f, 32.f);
	buyButton32.setPosition(1500.0f, 500.0f);
	Sprite buyButton8;
	buyButton8.setTexture(buyButtonTexture);
	buyButton8.setOrigin(64.f, 32.f);
	buyButton8.setPosition(250, 500.f);
	Sprite buyButton9;
	buyButton9.setTexture(buyButtonTexture);
	buyButton9.setOrigin(64.f, 32.f);
	buyButton9.setPosition(500.f, 500.f);
	Sprite buyButton10;
	buyButton10.setTexture(buyButtonTexture);
	buyButton10.setOrigin(64.f, 32.f);
	buyButton10.setPosition(750, 500.f);
	Sprite buyButton22;
	buyButton22.setTexture(buyButtonTexture);
	buyButton22.setOrigin(64.f, 32.f);
	buyButton22.setPosition(1000.0f, 500.f);
	Sprite buyButton23;
	buyButton23.setTexture(buyButtonTexture);
	buyButton23.setOrigin(64.f, 32.f);
	buyButton23.setPosition(1250.0f, 500.f);
	Sprite buyButton24;
	buyButton24.setTexture(buyButtonTexture);
	buyButton24.setOrigin(64.f, 32.f);
	buyButton24.setPosition(1500.0f, 500.f);
	Sprite buyButton25;
	buyButton25.setTexture(buyButtonTexture);
	buyButton25.setOrigin(64.f, 32.f);
	buyButton25.setPosition(1750.0f, 500.f);
	Sprite buyButton33;
	buyButton33.setTexture(buyButtonTexture);
	buyButton33.setOrigin(64.f, 32.f);
	buyButton33.setPosition(250.0f, 850.f);
	Sprite buyButton11;
	buyButton11.setTexture(buyButtonTexture);
	buyButton11.setOrigin(64.f, 32.f);
	buyButton11.setPosition(250, 500.f);
	Sprite buyButton27;
	buyButton27.setTexture(buyButtonTexture);
	buyButton27.setOrigin(64.f, 32.f);
	buyButton27.setPosition(500.0f, 500.f);
	Sprite buyButton28;
	buyButton28.setTexture(buyButtonTexture);
	buyButton28.setOrigin(64.f, 32.f);
	buyButton28.setPosition(750.0f, 500.f);
	Sprite buyButton29;
	buyButton29.setTexture(buyButtonTexture);
	buyButton29.setOrigin(64.f, 32.f);
	buyButton29.setPosition(1000.0f, 500.f);
	Sprite buyButton34;
	buyButton34.setTexture(buyButtonTexture);
	buyButton34.setOrigin(64.f, 32.f);
	buyButton34.setPosition(1250.0f, 500.f);
	Sprite buyButton12;
	buyButton12.setTexture(buyButtonTexture);
	buyButton12.setOrigin(64.f, 32.f);
	buyButton12.setPosition(250, 500.f);
	Sprite buyButton13;
	buyButton13.setTexture(buyButtonTexture);
	buyButton13.setOrigin(64.f, 32.f);
	buyButton13.setPosition(500, 500.f);
	Sprite buyButton14;
	buyButton14.setTexture(buyButtonTexture);
	buyButton14.setOrigin(64.f, 32.f);
	buyButton14.setPosition(750, 500.f);
	Sprite buyButton30;
	buyButton30.setTexture(buyButtonTexture);
	buyButton30.setOrigin(64.f, 32.f);
	buyButton30.setPosition(1000.0f, 500.f);
	Sprite buyButton35;
	buyButton35.setTexture(buyButtonTexture);
	buyButton35.setOrigin(64.f, 32.f);
	buyButton35.setPosition(1250.0f, 500.f);

	Sprite playerModel;
	playerModel.setTexture(peashooterCannonTexture);
	playerModel.setOrigin(20.f, 42.f);
	playerModel.setScale(3.f, 3.f);
	playerModel.setPosition(250.f, 400.f);

	Sprite playerModel2;
	playerModel2.setTexture(yippeeCannonTexture);
	playerModel2.setOrigin(20.f, 42.f);
	playerModel2.setScale(3.f, 3.f);
	playerModel2.setPosition(500.f, 400.f);

	Sprite playerModel3;
	playerModel3.setTexture(sugarCannonTexture);
	playerModel3.setOrigin(20.f, 42.f);
	playerModel3.setScale(3.f, 3.f);
	playerModel3.setPosition(750.f, 400.f);

	Sprite playerModel4;
	playerModel4.setTexture(fireCannonTexture);
	playerModel4.setOrigin(20.f, 42.f);
	playerModel4.setScale(3.f, 3.f);
	playerModel4.setPosition(1000.f, 400.f);

	Sprite playerModel5;
	playerModel5.setTexture(flameCannonTexture);
	playerModel5.setOrigin(20.f, 42.f);
	playerModel5.setScale(3.f, 3.f);
	playerModel5.setPosition(1250.f, 400.f);

	Sprite playerModel6;
	playerModel6.setTexture(deadpoolCannonTexture);
	playerModel6.setOrigin(20.f, 42.f);
	playerModel6.setScale(3.f, 3.f);
	playerModel6.setPosition(1500.f, 400.f);

	Sprite playerModel7;
	playerModel7.setTexture(shockCannonTexture);
	playerModel7.setOrigin(20.f, 42.f);
	playerModel7.setScale(3.f, 3.f);
	playerModel7.setPosition(1750.f, 400.f);

	Sprite playerModel8;
	playerModel8.setTexture(birdoCannonTexture);
	playerModel8.setOrigin(20.f, 42.f);
	playerModel8.setScale(3.f, 3.f);
	playerModel8.setPosition(250.f, 750.f);

	Sprite playerModel9;
	playerModel9.setTexture(heartsCannonTexture);
	playerModel9.setOrigin(20.f, 42.f);
	playerModel9.setScale(3.f, 3.f);
	playerModel9.setPosition(500.f, 750.f);

	Sprite playerModel10;
	playerModel10.setTexture(logicalCannonTexture);
	playerModel10.setOrigin(20.f, 42.f);
	playerModel10.setScale(3.f, 3.f);
	playerModel10.setPosition(750.0f, 750.f);

	Sprite playerModel11;
	playerModel11.setTexture(apocCannonTexture);
	playerModel11.setOrigin(20.f, 42.f);
	playerModel11.setScale(3.f, 3.f);
	playerModel11.setPosition(1000.0f, 750.f);

	Sprite bombModel;
	bombModel.setTexture(yippeeBombTexture);
	bombModel.setOrigin(8.f, 9.f);
	bombModel.setScale(4.f, 4.f);
	bombModel.setPosition(250.f, 400.f);

	Sprite bombModel2;
	bombModel2.setTexture(fireBombTexture);
	bombModel2.setOrigin(8.f, 9.f);
	bombModel2.setScale(4.f, 4.f);
	bombModel2.setPosition(500.f, 400.f);

	Sprite bombModel3;
	bombModel3.setTexture(yoshiBombTexture);
	bombModel3.setOrigin(8.f, 9.f);
	bombModel3.setScale(4.f, 4.f);
	bombModel3.setPosition(750.0f, 400.f);

	Sprite bombModel4;
	bombModel4.setTexture(birdoBombTexture);
	bombModel4.setOrigin(8.f, 9.f);
	bombModel4.setScale(4.f, 4.f);
	bombModel4.setPosition(1000.0f, 400.f);

	Sprite bombModel5;
	bombModel5.setTexture(logicalBombTexture);
	bombModel5.setOrigin(8.f, 9.f);
	bombModel5.setScale(4.f, 4.f);
	bombModel5.setPosition(1250.0f, 400.f);

	Sprite bombModel6;
	bombModel6.setTexture(apocBombTexture);
	bombModel6.setOrigin(8.f, 9.f);
	bombModel6.setScale(4.f, 4.f);
	bombModel6.setPosition(1500.0f, 400.f);

	Sprite grenadeModel;
	grenadeModel.setTexture(fireGrenadeTexture);
	grenadeModel.setOrigin(8.f, 12.f);
	grenadeModel.setScale(4.f, 4.f);
	grenadeModel.setPosition(250, 400);

	Sprite grenadeModel2;
	grenadeModel2.setTexture(yippeeGrenadeTexture);
	grenadeModel2.setOrigin(8.f, 12.f);
	grenadeModel2.setScale(4.f, 4.f);
	grenadeModel2.setPosition(500, 400);

	Sprite grenadeModel3;
	grenadeModel3.setTexture(logicalGrenadeTexture);
	grenadeModel3.setOrigin(8.f, 12.f);
	grenadeModel3.setScale(4.f, 4.f);
	grenadeModel3.setPosition(750, 400);

	Sprite grenadeModel4;
	grenadeModel4.setTexture(dynamiteGrenadeTexture);
	grenadeModel4.setOrigin(8.f, 12.f);
	grenadeModel4.setScale(4.f, 4.f);
	grenadeModel4.setPosition(1000.0f, 400);

	Sprite grenadeModel5;
	grenadeModel5.setTexture(nukeGrenadeTexture);
	grenadeModel5.setOrigin(8.f, 12.f);
	grenadeModel5.setScale(4.f, 4.f);
	grenadeModel5.setPosition(1250.0f, 400);

	Sprite grenadeModel6;
	grenadeModel6.setTexture(smokeGrenadeTexture);
	grenadeModel6.setOrigin(8.f, 12.f);
	grenadeModel6.setScale(4.f, 4.f);
	grenadeModel6.setPosition(1500.0f, 400);

	Sprite grenadeModel7;
	grenadeModel7.setTexture(holyHandGrenadeTexture);
	grenadeModel7.setOrigin(8.f, 12.f);
	grenadeModel7.setScale(4.f, 4.f);
	grenadeModel7.setPosition(1750.0f, 400);

	Sprite grenadeModel8;
	grenadeModel8.setTexture(apocGrenadeTexture);
	grenadeModel8.setOrigin(8.f, 12.f);
	grenadeModel8.setScale(4.f, 4.f);
	grenadeModel8.setPosition(250.0f, 750.0f);

	Sprite explosionModel;
	explosionModel.setTexture(yippeeExplosionTexture);
	explosionModel.setOrigin(18, 23.25f);
	explosionModel.setScale(4.f, 4.f);
	explosionModel.setPosition(250, 400);

	Sprite explosionModel2;
	explosionModel2.setTexture(logicalExplosionTexture);
	explosionModel2.setOrigin(18, 23.25f);
	explosionModel2.setScale(4.f, 4.f);
	explosionModel2.setPosition(500, 400);

	Sprite explosionModel3;
	explosionModel3.setTexture(mushroomExplosionTexture);
	explosionModel3.setOrigin(18, 23.25f);
	explosionModel3.setScale(4.f, 4.f);
	explosionModel3.setPosition(750, 400);

	Sprite explosionModel4;
	explosionModel4.setTexture(smokeExplosionTexture);
	explosionModel4.setOrigin(18, 23.25f);
	explosionModel4.setScale(4.f, 4.f);
	explosionModel4.setPosition(1000, 400);

	Sprite explosionModel5;
	explosionModel5.setTexture(apocExplosionTexture);
	explosionModel5.setOrigin(18, 23.25f);
	explosionModel5.setScale(4.f, 4.f);
	explosionModel5.setPosition(1250.0f, 400);

	Sprite planeModel;
	planeModel.setTexture(yippeePlaneTexture);
	planeModel.setOrigin(24.f, 32.f);
	planeModel.setScale(4, 4);
	planeModel.setPosition(250, 400);
	planeModel.setRotation(45.f);
	Sprite planeModel2;
	planeModel2.setTexture(firePlaneTexture);
	planeModel2.setOrigin(24.f, 32.f);
	planeModel2.setScale(4, 4);
	planeModel2.setPosition(500, 400);
	planeModel2.setRotation(45.f);
	Sprite planeModel3;
	planeModel3.setTexture(logicalPlaneTexture);
	planeModel3.setOrigin(24.f, 32.f);
	planeModel3.setScale(4, 4);
	planeModel3.setPosition(750, 400);
	planeModel3.setRotation(45.f);
	Sprite planeModel4;
	planeModel4.setTexture(fighterPlaneTexture);
	planeModel4.setOrigin(24.f, 32.f);
	planeModel4.setScale(4, 4);
	planeModel4.setPosition(1000.0f, 400);
	planeModel4.setRotation(45.f);
	Sprite planeModel5;
	planeModel5.setTexture(apocPlaneTexture);
	planeModel5.setOrigin(24.f, 32.f);
	planeModel5.setScale(4, 4);
	planeModel5.setPosition(1250.0f, 400);
	planeModel5.setRotation(45.f);

	Sprite cannonShopButton;
	cannonShopButton.setTexture(cannonButtonTexture);
	cannonShopButton.setOrigin(16.f, 16.f);
	cannonShopButton.setScale(2.f, 2.f);
	cannonShopButton.setPosition(500 + 92, 950);
	Sprite bombShopButton;
	bombShopButton.setTexture(bombButtonTexture);
	bombShopButton.setOrigin(16.f, 16.f);
	bombShopButton.setScale(2.f, 2.f);
	bombShopButton.setPosition(500 + 184 + 92, 950);
	Sprite grenadeShopButton;
	grenadeShopButton.setTexture(grenadeButtonTexture);
	grenadeShopButton.setOrigin(16.f, 16.f);
	grenadeShopButton.setScale(2.f, 2.f);
	grenadeShopButton.setPosition(500 + 184 + 184 + 92, 950);
	Sprite explosionShopButton;
	explosionShopButton.setTexture(explosionButtonTexture);
	explosionShopButton.setOrigin(16.f, 16.f);
	explosionShopButton.setScale(2.f, 2.f);
	explosionShopButton.setPosition(500 + 184 + 184 + 184 + 92, 950);
	Sprite planeShopButton;
	planeShopButton.setTexture(planeButtonTexture);
	planeShopButton.setOrigin(16.f, 16.f);
	planeShopButton.setScale(2.f, 2.f);
	planeShopButton.setPosition(500 + 184 + 184 + 184 + 184 + 92, 950);

	Sprite eventPlayerModel;
	eventPlayerModel.setOrigin(20.f, 27.f);
	eventPlayerModel.setScale(4.f, 4.f);
	eventPlayerModel.setPosition(960.f, 440.f);

	Sprite eventBombModel;
	eventBombModel.setOrigin(8.f, 9.f);
	eventBombModel.setScale(8.f, 8.f);
	eventBombModel.setPosition(960.f, 400.f);

	Sprite eventGrenadeModel;
	eventGrenadeModel.setOrigin(8.f, 16.f);
	eventGrenadeModel.setScale(8, 8);
	eventGrenadeModel.setPosition(960.f, 440.f);

	Sprite eventExplosionModel;
	eventExplosionModel.setOrigin(18.f, 17.f);
	eventExplosionModel.setScale(8.f, 8.f);
	eventExplosionModel.setPosition(960.f, 440.f);

	Sprite eventPlaneModel;
	eventPlaneModel.setOrigin(16.f, 16.f);
	eventPlaneModel.setScale(5.f, 5.f);
	eventPlaneModel.setPosition(960.f, 440.f);
	eventPlaneModel.setRotation(45.f);

	Texture treasureChestTexture;
	treasureChestTexture.loadFromFile("assets/other/treasureChest.png");
	Sprite treasureChest;
	treasureChest.setTexture(treasureChestTexture);
	treasureChest.setScale(4.f, 4.f);
	treasureChest.setOrigin(5.5f, 7.f);
	Texture price1Texture;
	price1Texture.loadFromFile("assets/other/price500.png");
	Texture price11Texture;
	price11Texture.loadFromFile("assets/other/price5001.png");
	Texture price2Texture;
	price2Texture.loadFromFile("assets/other/price750.png");
	Texture price22Texture;
	price22Texture.loadFromFile("assets/other/price7501.png");
	Texture price3Texture;
	price3Texture.loadFromFile("assets/other/price1000.png");
	Texture price33Texture;
	price33Texture.loadFromFile("assets/other/price10001.png");
	Texture price4Texture;
	price4Texture.loadFromFile("assets/other/price1500.png");
	Texture price44Texture;
	price44Texture.loadFromFile("assets/other/price15001.png");
	Texture price5Texture;
	price5Texture.loadFromFile("assets/other/price10000.png");
	Texture price55Texture;
	price55Texture.loadFromFile("assets/other/price100001.png");
	Texture price6Texture;
	price6Texture.loadFromFile("assets/other/price15000.png");
	Texture price66Texture;
	price66Texture.loadFromFile("assets/other/price150001.png");
	Sprite price1;
	price1.setScale(0.5f, 0.5f);
	price1.setPosition(250, 250);
	Sprite price2;
	price2.setScale(0.5f, 0.5f);
	price2.setPosition(500.f, 250.f);
	Sprite price3;
	price3.setScale(0.5f, 0.5f);
	price3.setPosition(750.f, 250.f);
	Sprite price4;
	price4.setScale(0.5f, 0.5f);
	price4.setPosition(1000.f, 250.f);
	Sprite price5;
	price5.setScale(0.5f, 0.5f);
	price5.setPosition(1250.f, 250.f);
	Sprite price6;
	price6.setScale(0.5f, 0.5f);
	price6.setPosition(1500.f, 250.f);
	Sprite price7;
	price7.setScale(0.5f, 0.5f);
	price7.setPosition(1750.f, 250.f);
	Sprite price8;
	price8.setScale(0.5f, 0.5f);
	price8.setPosition(250.f, 600.f);
	Sprite price9;
	price9.setScale(0.5f, 0.5f);
	price9.setPosition(500.f, 600.f);
	Sprite price10;
	price10.setScale(0.5f, 0.5f);
	price10.setPosition(750.0f, 600.f);
	Sprite price11;
	price11.setScale(0.5f, 0.5f);
	price11.setPosition(1000.0f, 600.f);
	Sprite price12;
	price12.setScale(0.5f, 0.5f);
	price12.setPosition(1250.0f, 600.f);
	Sprite price13;
	price13.setScale(0.5f, 0.5f);
	price13.setPosition(1500.0f, 600.f);
	Sprite seasonPrice1;
	seasonPrice1.setScale(0.5f, 0.5f);
	seasonPrice1.setPosition(1500.0f, 600.f);

	Texture creditsTextTexture;
	creditsTextTexture.loadFromFile("assets/other/creditsText.png");
	Texture creditsTextAltTexture;
	creditsTextAltTexture.loadFromFile("assets/other/alternate/creditsText_alt.png");
	Sprite creditsText;
	creditsText.setOrigin(320.f, 1068.f);
	creditsText.setScale(1.f, 1.f);
	if (!altFont) {
		creditsText.setOrigin(320.f, 1068.f);
		creditsText.setPosition(960.f, 2190.f);
	}
	else {
		creditsText.setTextureRect(IntRect(0, 0, creditsTextAltTexture.getSize().x, creditsTextAltTexture.getSize().y));
		creditsText.setOrigin(268.f, 1064.f);
		creditsText.setPosition(960.f, 2186.f);
	}

	Texture creditsThanksTextTexture;
	creditsThanksTextTexture.loadFromFile("assets/other/creditsThanksText.png");
	Texture creditsThanksTextAltTexture;
	creditsThanksTextAltTexture.loadFromFile("assets/other/alternate/creditsThanksText_alt.png");
	Sprite creditsThanksText;
	creditsThanksText.setScale(1.f, 1.f);

	if (!altFont) {
		creditsThanksText.setOrigin(660.f, 124.5f);
		creditsThanksText.setPosition(960.f, 3568.f);
	} else {
		creditsThanksText.setOrigin(663.5f, 131.5f);
		creditsThanksText.setPosition(960.f, 3575.f);
	}

	Texture barTexture;
	barTexture.loadFromFile("assets/other/bar.png");
	Sprite bar;
	bar.setTexture(barTexture);
	bar.setOrigin(200.f, 4.f);
	bar.setPosition(960.f, 360.f);
	Sprite bar2;
	bar2.setTexture(barTexture);
	bar2.setOrigin(200.f, 4.f);
	bar2.setPosition(960.f, 720.f);

	Sprite bar3;
	bar3.setTexture(barTexture);
	bar3.setOrigin(200.f, 4.f);
	bar3.setPosition(960.f, 360.f);
	Sprite bar4;
	bar4.setTexture(barTexture);
	bar4.setOrigin(200.f, 4.f);
	bar4.setPosition(960.f, 720 -150.f);

	Texture dotTexture;
	dotTexture.loadFromFile("assets/other/dot.png");
	Sprite dot;
	dot.setTexture(dotTexture);
	dot.setOrigin(8.f, 8.f);
	dot.setPosition(760.f + (4.f * musicVolume), 360.f);
	Sprite dot2;
	dot2.setTexture(dotTexture);
	dot2.setOrigin(8.f, 8.f);
	dot2.setPosition(((1920 / 2) - (200 * (1920 / 1920))) + (SFXVolume * (7920 / 1920)), (1080 / 3) * 2);
	
	Sprite dot3;
	dot3.setTexture(dotTexture);
	dot3.setOrigin(8.f, 8.f);
	dot3.setPosition(760.f + (200.f * saturation), 360.f);
	Sprite dot4;
	dot4.setTexture(dotTexture);
	dot4.setOrigin(8.f, 8.f);
	dot4.setPosition(760.f + (200.f * contrast), 720 - 150.0f);

	Texture background1Texture;
	background1Texture.loadFromFile("assets/backgrounds/background1.png");
	Sprite background1;
	background1.setTexture(background1Texture);
	background1.setOrigin(128.f, 72.f);
	background1.setScale(7.5f, 7.5f);
	background1.setPosition(960.f, 540.f);

	Texture background1OverlayTexture;
	background1OverlayTexture.loadFromFile("assets/backgrounds/background1Overlay.png");
	Sprite background1Overlay;
	background1Overlay.setTexture(background1OverlayTexture);
	background1Overlay.setScale(7.5f, 7.5f);
	background1Overlay.setPosition(0.f, 0.f);

	Sprite icon1;
	icon1.setTexture(playerTexture);
	icon1.setOrigin(20.f, 27.f);
	icon1.setRotation(45.f);
	icon1.setPosition(288 + 192, 780);
	Sprite icon47;
	icon47.setTexture(deadpoolCannonTexture);
	icon47.setOrigin(20.f, 27.f);
	icon47.setRotation(45.f);
	icon47.setPosition(288 + 192, 780);
	Sprite icon2;
	icon2.setTexture(christmasCannonTexture);
	icon2.setOrigin(20.f, 27.f);
	icon2.setRotation(45.f);
	icon2.setPosition(288 + 384, 780);
	Sprite icon48;
	icon48.setTexture(shockCannonTexture);
	icon48.setOrigin(20.f, 27.f);
	icon48.setRotation(45.f);
	icon48.setPosition(288 + 384, 780);
	Sprite icon3;
	icon3.setTexture(fireCannonTexture);
	icon3.setOrigin(20.f, 27.f);
	icon3.setRotation(45.f);
	icon3.setPosition(288 + 576, 780);
	Sprite icon49;
	icon49.setTexture(birdoCannonTexture);
	icon49.setOrigin(20.f, 27.f);
	icon49.setRotation(45.f);
	icon49.setPosition(288 + 576, 780);
	Sprite icon4;
	icon4.setTexture(yippeeCannonTexture);
	icon4.setOrigin(20.f, 27.f);
	icon4.setRotation(45.f);
	icon4.setPosition(288 + 768, 780);
	Sprite icon50;
	icon50.setTexture(heartsCannonTexture);
	icon50.setOrigin(20.f, 27.f);
	icon50.setRotation(45.f);
	icon50.setPosition(288 + 768, 780);
	Sprite icon62;
	icon62.setTexture(apocCannonTexture);
	icon62.setOrigin(20.f, 27.f);
	icon62.setRotation(45.f);
	icon62.setPosition(288 + 960, 780);
	Sprite icon5;
	icon5.setTexture(goldenCannonTexture);
	icon5.setOrigin(20.f, 27.f);
	icon5.setRotation(45.f);
	icon5.setPosition(288 + 960, 780);
	Sprite icon6;
	icon6.setTexture(logicalCannonTexture);
	icon6.setOrigin(20.f, 27.f);
	icon6.setRotation(45.f);
	icon6.setPosition(288 + 1152, 780);
	Sprite icon7;
	icon7.setTexture(peashooterCannonTexture);
	icon7.setOrigin(20.f, 27.f);
	icon7.setRotation(45.f);
	icon7.setPosition(288 + 192, 972);
	Sprite icon8;
	icon8.setTexture(sugarCannonTexture);
	icon8.setOrigin(20.f, 27.f);
	icon8.setRotation(45.f);
	icon8.setPosition(288 + 384, 972);
	Sprite icon21;
	icon21.setTexture(flameCannonTexture);
	icon21.setOrigin(20.f, 27.f);
	icon21.setRotation(45.f);
	icon21.setPosition(288 + 576, 972);
	Sprite icon38;
	icon38.setTexture(gingerbreadCannonTexture);
	icon38.setOrigin(20.f, 27.f);
	icon38.setRotation(45.f);
	icon38.setPosition(288 + 768, 972);
	Sprite icon39;
	icon39.setTexture(snowmanCannonTexture);
	icon39.setOrigin(20.f, 27.f);
	icon39.setRotation(45.f);
	icon39.setPosition(288 + 960, 972);
	Sprite icon40;
	icon40.setTexture(presentCannonTexture);
	icon40.setOrigin(20.f, 27.f);
	icon40.setRotation(45.f);
	icon40.setPosition(288 + 1152, 972);

	Sprite icon9;
	icon9.setTexture(bombTexture);
	icon9.setOrigin(8.f, 11.f);
	icon9.setScale(3.f, 3.f);
	icon9.setPosition(288 + 192, 780);
	Sprite icon10;
	icon10.setTexture(fireBombTexture);
	icon10.setOrigin(8.f, 11.f);
	icon10.setScale(3.f, 3.f);
	icon10.setPosition(288 + 384, 780);
	Sprite icon11;
	icon11.setTexture(icyBombTexture);
	icon11.setOrigin(8.f, 11.f);
	icon11.setScale(3.f, 3.f);
	icon11.setPosition(288 + 576, 780);
	Sprite icon12;
	icon12.setTexture(orangeBombTexture);
	icon12.setOrigin(8.f, 11.f);
	icon12.setScale(3.f, 3.f);
	icon12.setPosition(288 + 768, 780);
	Sprite icon13;
	icon13.setTexture(peppermintBombTexture);
	icon13.setOrigin(8.f, 11.f);
	icon13.setScale(3.f, 3.f);
	icon13.setPosition(288 + 960, 780);
	Sprite icon14;
	icon14.setTexture(yippeeBombTexture);
	icon14.setOrigin(8.f, 11.f);
	icon14.setScale(3.f, 3.f);
	icon14.setPosition(288 + 1152, 780);
	Sprite icon41;
	icon41.setTexture(santasBombTexture);
	icon41.setOrigin(8.f, 11.f);
	icon41.setScale(3.f, 3.f);
	icon41.setPosition(288 + 192, 972);
	Sprite icon42;
	icon42.setTexture(bellBombTexture);
	icon42.setOrigin(8.f, 11.f);
	icon42.setScale(3.f, 3.f);
	icon42.setPosition(288 + 384, 972);
	Sprite icon51;
	icon51.setTexture(yoshiBombTexture);
	icon51.setOrigin(8.f, 11.f);
	icon51.setScale(3.f, 3.f);
	icon51.setPosition(288 + 576, 972);
	Sprite icon52;
	icon52.setTexture(birdoBombTexture);
	icon52.setOrigin(8.f, 11.f);
	icon52.setScale(3.f, 3.f);
	icon52.setPosition(288 + 768, 972);
	Sprite icon57;
	icon57.setTexture(logicalBombTexture);
	icon57.setOrigin(8.f, 11.f);
	icon57.setScale(3.f, 3.f);
	icon57.setPosition(288 + 960, 972);
	Sprite icon63;
	icon63.setTexture(apocBombTexture);
	icon63.setOrigin(8.f, 11.f);
	icon63.setScale(3.f, 3.f);
	icon63.setPosition(288 + 1152, 972);

	Sprite icon22;
	icon22.setTexture(grenadeTexture);
	icon22.setOrigin(8, 12);
	icon22.setScale(3.f, 3.f);
	icon22.setPosition(288 + 192, 780);
	Sprite icon23;
	icon23.setTexture(fireGrenadeTexture);
	icon23.setOrigin(8, 12);
	icon23.setScale(3.f, 3.f);
	icon23.setPosition(288 + 384, 780);
	Sprite icon24;
	icon24.setTexture(yippeeGrenadeTexture);
	icon24.setOrigin(8, 12);
	icon24.setScale(3.f, 3.f);
	icon24.setPosition(288 + 576, 780);
	Sprite icon25;
	icon25.setTexture(logicalGrenadeTexture);
	icon25.setOrigin(8, 12);
	icon25.setScale(3.f, 3.f);
	icon25.setPosition(288 + 768, 780);
	Sprite icon26;
	icon26.setTexture(chocolateGrenadeTexture);
	icon26.setOrigin(8, 12);
	icon26.setScale(3.f, 3.f);
	icon26.setPosition(288 + 960, 780);
	Sprite icon15;
	icon15.setTexture(christmasGrenadeTexture);
	icon15.setOrigin(8, 12);
	icon15.setScale(3.f, 3.f);
	icon15.setPosition(288 + 1152, 780);
	Sprite icon16;
	icon16.setTexture(garlandGrenadeTexture);
	icon16.setOrigin(8, 12);
	icon16.setScale(3.f, 3.f);
	icon16.setPosition(288 + 192, 972);
	Sprite icon17;
	icon17.setTexture(iceGrenadeTexture);
	icon17.setOrigin(8, 12);
	icon17.setScale(3.f, 3.f);
	icon17.setPosition(288 + 384, 972);
	Sprite icon18;
	icon18.setTexture(santaGrenadeTexture);
	icon18.setOrigin(8, 12);
	icon18.setScale(3.f, 3.f);
	icon18.setPosition(288 + 576, 972);
	Sprite icon53;
	icon53.setTexture(dynamiteGrenadeTexture);
	icon53.setOrigin(8, 12);
	icon53.setScale(3.f, 3.f);
	icon53.setPosition(288 + 768, 972);
	Sprite icon54;
	icon54.setTexture(nukeGrenadeTexture);
	icon54.setOrigin(8, 12);
	icon54.setScale(3.f, 3.f);
	icon54.setPosition(288 + 960, 972);
	Sprite icon55;
	icon55.setTexture(smokeGrenadeTexture);
	icon55.setOrigin(8, 12);
	icon55.setScale(3.f, 3.f);
	icon55.setPosition(288 + 1152, 972);
	Sprite icon56;
	icon56.setTexture(holyHandGrenadeTexture);
	icon56.setOrigin(8, 12);
	icon56.setScale(3.f, 3.f);
	icon56.setPosition(288 + 192, 780);
	Sprite icon64;
	icon64.setTexture(apocGrenadeTexture);
	icon64.setOrigin(8.f, 11.f);
	icon64.setScale(3.f, 3.f);
	icon64.setPosition(288 + 384, 780);

	Sprite icon27;
	icon27.setTexture(explosionTexture);
	icon27.setOrigin(18, 17);
	icon27.setScale(2, 2);
	icon27.setPosition(288 + 192, 780);
	Sprite icon28;
	icon28.setTexture(yippeeExplosionTexture);
	icon28.setOrigin(18, 17);
	icon28.setScale(2, 2);
	icon28.setPosition(288 + 384, 780);
	Sprite icon29;
	icon29.setTexture(festiveExplosionTexture);
	icon29.setOrigin(18, 17);
	icon29.setScale(2, 2);
	icon29.setPosition(288 + 576, 780);
	Sprite icon30;
	icon30.setTexture(snowyExplosionTexture);
	icon30.setOrigin(18, 17);
	icon30.setScale(2, 2);
	icon30.setPosition(288 + 768, 780);
	Sprite icon31;
	icon31.setTexture(gingerbreadExplosionTexture);
	icon31.setOrigin(18, 17);
	icon31.setScale(2, 2);
	icon31.setPosition(288 + 960, 780);
	Sprite icon19;
	icon19.setTexture(elfExplosionTexture);
	icon19.setOrigin(18, 17);
	icon19.setScale(2, 2);
	icon19.setPosition(288 + 1152, 780);
	Sprite icon43;
	icon43.setTexture(snowExplosionTexture);
	icon43.setOrigin(18, 17);
	icon43.setScale(2, 2);
	icon43.setPosition(288 + 192, 972);
	Sprite icon58;
	icon58.setTexture(logicalExplosionTexture);
	icon58.setOrigin(18, 17);
	icon58.setScale(2, 2);
	icon58.setPosition(288 + 384, 972);
	Sprite icon59;
	icon59.setTexture(mushroomExplosionTexture);
	icon59.setOrigin(18, 17);
	icon59.setScale(2, 2);
	icon59.setPosition(288 + 576, 972);
	Sprite icon60;
	icon60.setTexture(smokeExplosionTexture);
	icon60.setOrigin(18, 17);
	icon60.setScale(2, 2);
	icon60.setPosition(288 + 768, 972);
	Sprite icon65;
	icon65.setTexture(apocExplosionTexture);
	icon65.setOrigin(18, 17);
	icon65.setScale(2, 2);
	icon65.setPosition(288 + 960, 972);

	Sprite icon32;
	icon32.setTexture(planeTexture);
	icon32.setOrigin(16, 16);
	icon32.setRotation(45);
	icon32.setScale(2, 2);
	icon32.setPosition(288 + 192, 780);
	Sprite icon33;
	icon33.setTexture(yippeePlaneTexture);
	icon33.setOrigin(16, 16);
	icon33.setRotation(45);
	icon33.setScale(2, 2);
	icon33.setPosition(288 + 384, 780);
	Sprite icon34;
	icon34.setTexture(firePlaneTexture);
	icon34.setOrigin(16, 16);
	icon34.setRotation(45);
	icon34.setScale(2, 2);
	icon34.setPosition(288 + 576, 780);
	Sprite icon35;
	icon35.setTexture(logicalPlaneTexture);
	icon35.setOrigin(16, 16);
	icon35.setRotation(45);
	icon35.setScale(2, 2);
	icon35.setPosition(288 + 768, 780);
	Sprite icon36;
	icon36.setTexture(festivePlaneTexture);
	icon36.setOrigin(16, 16);
	icon36.setRotation(45);
	icon36.setScale(2, 2);
	icon36.setPosition(288 + 960, 780);
	Sprite icon37;
	icon37.setTexture(cookiePlaneTexture);
	icon37.setOrigin(16, 16);
	icon37.setRotation(45);
	icon37.setScale(2, 2);
	icon37.setPosition(288 + 1152, 780);
	Sprite icon44;
	icon44.setTexture(rudolphPlaneTexture);
	icon44.setOrigin(16, 16);
	icon44.setRotation(45);
	icon44.setScale(2, 2);
	icon44.setPosition(288 + 192, 972);
	Sprite icon45;
	icon45.setTexture(santasPlaneTexture);
	icon45.setOrigin(16, 16);
	icon45.setRotation(45);
	icon45.setScale(2, 2);
	icon45.setPosition(288 + 384, 972);
	Sprite icon46;
	icon46.setTexture(treePlaneTexture);
	icon46.setOrigin(16, 16);
	icon46.setRotation(45);
	icon46.setScale(2, 2);
	icon46.setPosition(288 + 576, 972);
	Sprite icon61;
	icon61.setTexture(fighterPlaneTexture);
	icon61.setOrigin(16, 16);
	icon61.setRotation(45);
	icon61.setScale(2, 2);
	icon61.setPosition(288 + 768, 972);
	Sprite icon66;
	icon66.setTexture(apocPlaneTexture);
	icon66.setOrigin(16, 16);
	icon66.setRotation(45);
	icon66.setScale(2, 2);
	icon66.setPosition(288 + 960, 972);

	Texture lockTexture;
	lockTexture.loadFromFile("assets/other/lock.png");
	
	Sprite lock;
	lock.setTexture(lockTexture);
	lock.setOrigin(6, 9);
	lock.setScale(3.f, 3.f);
	lock.setPosition(288 + 192, 780);
	Sprite lock2;
	lock2.setTexture(lockTexture);
	lock2.setOrigin(6, 9);
	lock2.setScale(3.f, 3.f);
	lock2.setPosition(288 + 384, 780);
	Sprite lock3;
	lock3.setTexture(lockTexture);
	lock3.setOrigin(6, 9);
	lock3.setScale(3.f, 3.f);
	lock3.setPosition(288 + 576, 780);
	Sprite lock4;
	lock4.setTexture(lockTexture);
	lock4.setOrigin(6, 9);
	lock4.setScale(3.f, 3.f);
	lock4.setPosition(288 + 768, 780);
	Sprite lock5;
	lock5.setTexture(lockTexture);
	lock5.setOrigin(6, 9);
	lock5.setScale(3.f, 3.f);
	lock5.setPosition(288 + 960, 780);
	Sprite lock6;
	lock6.setTexture(lockTexture);
	lock6.setOrigin(6, 9);
	lock6.setScale(3.f, 3.f);
	lock6.setPosition(288 + 1152, 780);
	Sprite lock7;
	lock7.setTexture(lockTexture);
	lock7.setOrigin(6, 9);
	lock7.setScale(3.f, 3.f);
	lock7.setPosition(288 + 192, 972);
	Sprite lock8;
	lock8.setTexture(lockTexture);
	lock8.setOrigin(6, 9);
	lock8.setScale(3.f, 3.f);
	lock8.setPosition(288 + 384, 972);
	Sprite lock9;
	lock9.setTexture(lockTexture);
	lock9.setOrigin(6, 9);
	lock9.setScale(3.f, 3.f);
	lock9.setPosition(288 + 576, 972);
	Sprite lock10;
	lock10.setTexture(lockTexture);
	lock10.setOrigin(6, 9);
	lock10.setScale(3.f, 3.f);
	lock10.setPosition(288 + 768, 972);
	Sprite lock11;
	lock11.setTexture(lockTexture);
	lock11.setOrigin(6, 9);
	lock11.setScale(3.f, 3.f);
	lock11.setPosition(288 + 960, 972);
	Sprite lock12;
	lock12.setTexture(lockTexture);
	lock12.setOrigin(6, 9);
	lock12.setScale(3.f, 3.f);
	lock12.setPosition(288 + 1152, 972);

	Texture ornamentTexture;
	ornamentTexture.loadFromFile("assets/other/ornament.png");
	Sprite ornament;
	ornament.setTexture(ornamentTexture);
	ornament.setOrigin(16.f, 16.f);
	ornament.setScale(3.f, 3.f);
	ornament.setPosition(1840.f, 1000.f);

	Texture backButtonTexture;
	backButtonTexture.loadFromFile("assets/buttons/backButton.png");
	Texture exitWindowButtonTexture;
	exitWindowButtonTexture.loadFromFile("assets/buttons/exitWindowButton.png");
	Sprite backButton;
	backButton.setOrigin(16.f, 16.f);
	backButton.setScale(3.f, 3.f);
	backButton.setPosition(85, 85);

	RectangleShape divider(Vector2f(4.0f, 1080.0f));
	divider.setOrigin(2.0f, 540.0f);
	divider.setPosition(960.0f, 540.0f);
	divider.setOutlineThickness(5);
	divider.setOutlineColor(Color(0, 0, 0));
	divider.setFillColor(Color(0, 0, 0));

	Sprite MP1player;
	MP1player.setTexture(playerTexture);
	MP1player.setOrigin(20.f, 42.f);
	MP1player.setScale(3.f, 3.f);
	MP1player.setPosition(480.f, 540.f);
	RectangleShape MP1playerHitbox(Vector2f(10, 52));
	MP1playerHitbox.setOrigin(5, 39);
	MP1playerHitbox.setScale(2, 2);
	MP1playerHitbox.setPosition(MP1player.getPosition());
	MP1playerHitbox.setRotation(MP1player.getRotation());
	MP1playerHitbox.setFillColor(Color(0, 255, 0, 0));
	MP1playerHitbox.setOutlineThickness(1.5);
	MP1playerHitbox.setOutlineColor(Color(0, 255, 0, 255));

	Sprite MP2player;
	MP2player.setTexture(playerTexture);
	MP2player.setOrigin(20.f, 42.f);
	MP2player.setScale(3.f, 3.f);
	MP2player.setPosition(1440.f, 540.f);
	RectangleShape MP2playerHitbox(Vector2f(10, 52));
	MP2playerHitbox.setOrigin(5, 39);
	MP2playerHitbox.setScale(2, 2);
	MP2playerHitbox.setPosition(MP2player.getPosition());
	MP2playerHitbox.setRotation(MP2player.getRotation());
	MP2playerHitbox.setFillColor(Color(0, 255, 0, 0));
	MP2playerHitbox.setOutlineThickness(1.5);
	MP2playerHitbox.setOutlineColor(Color(0, 255, 0, 255));

	Sprite MP1bomb;
	MP1bomb.setTexture(bombTexture);
	MP1bomb.setScale(3.f, 3.f);
	MP1bomb.setPosition(480.f, 540.f);
	MP1bomb.setOrigin(8.f, 58.f);
	RectangleShape MP1bombHitbox(Vector2f(6, 6));
	MP1bombHitbox.setOrigin(3.5, 47.5);
	MP1bombHitbox.setScale(3.f, 3.f);
	MP1bombHitbox.setPosition(MP1bomb.getPosition());
	MP1bombHitbox.setRotation(MP1bomb.getRotation());
	MP1bombHitbox.setFillColor(Color(0, 255, 0, 0));
	MP1bombHitbox.setOutlineThickness(1);
	MP1bombHitbox.setOutlineColor(Color(0, 255, 0, 255));

	Sprite MP2bomb;
	MP2bomb.setTexture(bombTexture);
	MP2bomb.setScale(3.f, 3.f);
	MP2bomb.setPosition(1440.f, 540.f);
	MP2bomb.setOrigin(8.f, 58.f);
	RectangleShape MP2bombHitbox(Vector2f(6, 6));
	MP2bombHitbox.setOrigin(3.5, 47.5);
	MP2bombHitbox.setScale(3.f, 3.f);
	MP2bombHitbox.setPosition(MP2bomb.getPosition());
	MP2bombHitbox.setRotation(MP2bomb.getRotation());
	MP2bombHitbox.setFillColor(Color(0, 255, 0, 0));
	MP2bombHitbox.setOutlineThickness(1);
	MP2bombHitbox.setOutlineColor(Color(0, 255, 0, 255));

	Sprite MP1grenade;
	MP1grenade.setTexture(grenadeTexture);
	MP1grenade.setScale(3.f, 3.f);
	MP1grenade.setPosition(3840.f, 2160.f);
	MP1grenade.setOrigin(8.f, 58.f);
	RectangleShape MP1grenadeHitbox(Vector2f(6, 6));
	MP1grenadeHitbox.setOrigin(3.5, 47.5);
	MP1grenadeHitbox.setScale(3.f, 3.f);
	MP1grenadeHitbox.setPosition(MP1grenade.getPosition());
	MP1grenadeHitbox.setRotation(MP1grenade.getRotation());
	MP1grenadeHitbox.setFillColor(Color(0, 255, 0, 0));
	MP1grenadeHitbox.setOutlineThickness(1.f);
	MP1grenadeHitbox.setOutlineColor(Color(0, 255, 0, 255));

	Sprite MP2grenade;
	MP2grenade.setTexture(grenadeTexture);
	MP2grenade.setScale(3.f, 3.f);
	MP2grenade.setPosition(3840.f, 2160.f);
	MP2grenade.setOrigin(8.f, 58.f);
	RectangleShape MP2grenadeHitbox(Vector2f(6, 6));
	MP2grenadeHitbox.setOrigin(3.5, 47.5);
	MP2grenadeHitbox.setScale(3.f, 3.f);
	MP2grenadeHitbox.setPosition(MP2grenade.getPosition());
	MP2grenadeHitbox.setRotation(MP2grenade.getRotation());
	MP2grenadeHitbox.setFillColor(Color(0, 255, 0, 0));
	MP2grenadeHitbox.setOutlineThickness(1.f);
	MP2grenadeHitbox.setOutlineColor(Color(0, 255, 0, 255));

	Sprite MP1explosion;
	MP1explosion.setTexture(explosionTexture);
	MP1explosion.setScale(10.f, 10.f);
	MP1explosion.setOrigin(17.f, 18.f);
	MP1explosion.setPosition(5760.f, 3240.f);
	Sprite MP2explosion;
	MP2explosion.setTexture(explosionTexture);
	MP2explosion.setScale(10.f, 10.f);
	MP2explosion.setOrigin(17.f, 18.f);
	MP2explosion.setPosition(5760.f, 3240.f);

	Sprite MP1plane1;
	MP1plane1.setTexture(planeTexture);
	MP1plane1.setScale(3.f, 3.f);
	MP1plane1.setOrigin(16.f, 16.f);
	Sprite MP1plane2;
	MP1plane2.setTexture(planeTexture);
	MP1plane2.setScale(3.f, 3.f);
	MP1plane2.setOrigin(16.f, 16.f);
	Sprite MP1plane3;
	MP1plane3.setTexture(planeTexture);
	MP1plane3.setScale(3.f, 3.f);
	MP1plane3.setOrigin(16.f, 16.f);
	Sprite MP1plane4;
	MP1plane4.setTexture(planeTexture);
	MP1plane4.setScale(3.f, 3.f);
	MP1plane4.setOrigin(16.f, 16.f);
	Sprite MP1plane5;
	MP1plane5.setTexture(planeTexture);
	MP1plane5.setScale(3.f, 3.f);
	MP1plane5.setOrigin(16.f, 16.f);
	Sprite MP1plane6;
	MP1plane6.setTexture(planeTexture);
	MP1plane6.setScale(3.f, 3.f);
	MP1plane6.setOrigin(16.f, 16.f);
	RectangleShape MP1plane1Hitbox(Vector2f(26.f, 26.f));
	MP1plane1Hitbox.setOrigin(13.f, 13.f);
	MP1plane1Hitbox.setScale(3.f, 3.f);
	MP1plane1Hitbox.setPosition(MP1plane1.getPosition());
	MP1plane1Hitbox.setFillColor(Color(0, 255, 0, 0));
	MP1plane1Hitbox.setOutlineThickness(1.f);
	MP1plane1Hitbox.setOutlineColor(Color(255, 0, 0, 255));
	RectangleShape MP1plane2Hitbox(Vector2f(26.f, 26.f));
	MP1plane2Hitbox.setOrigin(13.f, 13.f);
	MP1plane2Hitbox.setScale(3.f, 3.f);
	MP1plane2Hitbox.setPosition(MP1plane2.getPosition());
	MP1plane2Hitbox.setFillColor(Color(0, 255, 0, 0));
	MP1plane2Hitbox.setOutlineThickness(1.f);
	MP1plane2Hitbox.setOutlineColor(Color(0, 255, 0, 255));
	RectangleShape MP1plane3Hitbox(Vector2f(26.f, 26.f));
	MP1plane3Hitbox.setOrigin(13.f, 13.f);
	MP1plane3Hitbox.setScale(3.f, 3.f);
	MP1plane3Hitbox.setPosition(MP1plane3.getPosition());
	MP1plane3Hitbox.setFillColor(Color(0, 255, 0, 0));
	MP1plane3Hitbox.setOutlineThickness(1.f);
	MP1plane3Hitbox.setOutlineColor(Color(0, 0, 255, 255));
	RectangleShape MP1plane4Hitbox(Vector2f(26.f, 26.f));
	MP1plane4Hitbox.setOrigin(13.f, 13.f);
	MP1plane4Hitbox.setScale(3.f, 3.f);
	MP1plane4Hitbox.setPosition(MP1plane4.getPosition());
	MP1plane4Hitbox.setFillColor(Color(0, 255, 0, 0));
	MP1plane4Hitbox.setOutlineThickness(1.f);
	MP1plane4Hitbox.setOutlineColor(Color(0, 255, 255, 255));
	RectangleShape MP1plane5Hitbox(Vector2f(26.f, 26.f));
	MP1plane5Hitbox.setOrigin(13.f, 13.f);
	MP1plane5Hitbox.setScale(3.f, 3.f);
	MP1plane5Hitbox.setPosition(MP1plane5.getPosition());
	MP1plane5Hitbox.setFillColor(Color(0, 255, 0, 0));
	MP1plane5Hitbox.setOutlineThickness(1.f);
	MP1plane5Hitbox.setOutlineColor(Color(255, 255, 0, 255));
	RectangleShape MP1plane6Hitbox(Vector2f(26.f, 26.f));
	MP1plane6Hitbox.setOrigin(13.f, 13.f);
	MP1plane6Hitbox.setScale(3.f, 3.f);
	MP1plane6Hitbox.setPosition(MP1plane6.getPosition());
	MP1plane6Hitbox.setFillColor(Color(0, 255, 0, 0));
	MP1plane6Hitbox.setOutlineThickness(1.f);
	MP1plane6Hitbox.setOutlineColor(Color(255, 255, 255, 255));

	Sprite MP2plane1;
	MP2plane1.setTexture(planeTexture);
	MP2plane1.setScale(3.f, 3.f);
	MP2plane1.setOrigin(16.f, 16.f);
	Sprite MP2plane2;
	MP2plane2.setTexture(planeTexture);
	MP2plane2.setScale(3.f, 3.f);
	MP2plane2.setOrigin(16.f, 16.f);
	Sprite MP2plane3;
	MP2plane3.setTexture(planeTexture);
	MP2plane3.setScale(3.f, 3.f);
	MP2plane3.setOrigin(16.f, 16.f);
	Sprite MP2plane4;
	MP2plane4.setTexture(planeTexture);
	MP2plane4.setScale(3.f, 3.f);
	MP2plane4.setOrigin(16.f, 16.f);
	Sprite MP2plane5;
	MP2plane5.setTexture(planeTexture);
	MP2plane5.setScale(3.f, 3.f);
	MP2plane5.setOrigin(16.f, 16.f);
	Sprite MP2plane6;
	MP2plane6.setTexture(planeTexture);
	MP2plane6.setScale(3.f, 3.f);
	MP2plane6.setOrigin(16.f, 16.f);
	RectangleShape MP2plane1Hitbox(Vector2f(26.f, 26.f));
	MP2plane1Hitbox.setOrigin(13.f, 13.f);
	MP2plane1Hitbox.setScale(3.f, 3.f);
	MP2plane1Hitbox.setPosition(MP2plane1.getPosition());
	MP2plane1Hitbox.setFillColor(Color(0, 255, 0, 0));
	MP2plane1Hitbox.setOutlineThickness(1.f);
	MP2plane1Hitbox.setOutlineColor(Color(255, 0, 0, 255));
	RectangleShape MP2plane2Hitbox(Vector2f(26.f, 26.f));
	MP2plane2Hitbox.setOrigin(13.f, 13.f);
	MP2plane2Hitbox.setScale(3.f, 3.f);
	MP2plane2Hitbox.setPosition(MP2plane2.getPosition());
	MP2plane2Hitbox.setFillColor(Color(0, 255, 0, 0));
	MP2plane2Hitbox.setOutlineThickness(1.f);
	MP2plane2Hitbox.setOutlineColor(Color(0, 255, 0, 255));
	RectangleShape MP2plane3Hitbox(Vector2f(26.f, 26.f));
	MP2plane3Hitbox.setOrigin(13.f, 13.f);
	MP2plane3Hitbox.setScale(3.f, 3.f);
	MP2plane3Hitbox.setPosition(MP2plane3.getPosition());
	MP2plane3Hitbox.setFillColor(Color(0, 255, 0, 0));
	MP2plane3Hitbox.setOutlineThickness(1.f);
	MP2plane3Hitbox.setOutlineColor(Color(0, 0, 255, 255));
	RectangleShape MP2plane4Hitbox(Vector2f(26.f, 26.f));
	MP2plane4Hitbox.setOrigin(13.f, 13.f);
	MP2plane4Hitbox.setScale(3.f, 3.f);
	MP2plane4Hitbox.setPosition(MP2plane4.getPosition());
	MP2plane4Hitbox.setFillColor(Color(0, 255, 0, 0));
	MP2plane4Hitbox.setOutlineThickness(1.f);
	MP2plane4Hitbox.setOutlineColor(Color(0, 255, 255, 255));
	RectangleShape MP2plane5Hitbox(Vector2f(26.f, 26.f));
	MP2plane5Hitbox.setOrigin(13.f, 13.f);
	MP2plane5Hitbox.setScale(3.f, 3.f);
	MP2plane5Hitbox.setPosition(MP2plane5.getPosition());
	MP2plane5Hitbox.setFillColor(Color(0, 255, 0, 0));
	MP2plane5Hitbox.setOutlineThickness(1.f);
	MP2plane5Hitbox.setOutlineColor(Color(255, 255, 0, 255));
	RectangleShape MP2plane6Hitbox(Vector2f(26.f, 26.f));
	MP2plane6Hitbox.setOrigin(13.f, 13.f);
	MP2plane6Hitbox.setScale(3.f, 3.f);
	MP2plane6Hitbox.setPosition(MP2plane6.getPosition());
	MP2plane6Hitbox.setFillColor(Color(0, 255, 0, 0));
	MP2plane6Hitbox.setOutlineThickness(1.f);
	MP2plane6Hitbox.setOutlineColor(Color(255, 255, 255, 255));

	Texture audioButtonTexture;
	audioButtonTexture.loadFromFile("assets/buttons/audioButton.png");
	Sprite audioButton;
	audioButton.setTexture(audioButtonTexture);
	audioButton.setOrigin(16.f, 16.f);
	audioButton.setScale(3.0f, 3.0f);
	audioButton.setPosition(684 + 184, 1000);

	Texture displayButtonTexture;
	displayButtonTexture.loadFromFile("assets/buttons/displayButton.png");
	Sprite displayButton;
	displayButton.setTexture(displayButtonTexture);
	displayButton.setOrigin(16.f, 16.f);
	displayButton.setScale(3.0f, 3.0f);
	displayButton.setPosition(684 + 184 + 184, 1000);

	Texture discordTexture;
	discordTexture.loadFromFile("assets/other/discord.png");
	Texture youtubeTexture;
	youtubeTexture.loadFromFile("assets/other/youtube.png");
	Texture steamTexture;
	steamTexture.loadFromFile("assets/other/steam.png");
	Sprite discord;
	discord.setTexture(discordTexture);
	discord.setOrigin(400.0f, 400.0f);
	discord.setScale(0.05f, 0.05f);
	discord.setPosition(50, 1050);
	Sprite youtube;
	youtube.setTexture(youtubeTexture);
	youtube.setOrigin(400.0f, 400.0f);
	youtube.setScale(0.05f, 0.05f);
	youtube.setPosition(110, 1050);
	Sprite steam;
	steam.setTexture(steamTexture);
	steam.setOrigin(400.0f, 400.0f);
	steam.setScale(0.05f, 0.05f);
	steam.setPosition(170, 1050);

	Texture rightArrowTexture;
	rightArrowTexture.loadFromFile("assets/other/rightArrow.png");
	Sprite rightArrow;
	rightArrow.setTexture(rightArrowTexture);
	rightArrow.setOrigin(6, 11);
	rightArrow.setPosition(1570, 876);
	rightArrow.setScale(4, 4);

	Texture leftArrowTexture;
	leftArrowTexture.loadFromFile("assets/other/leftArrow.png");
	Sprite leftArrow;
	leftArrow.setTexture(leftArrowTexture);
	leftArrow.setOrigin(6, 11);
	leftArrow.setPosition(350, 876);
	leftArrow.setScale(4, 4);

	Texture defaultAvatarTexture;
	defaultAvatarTexture.loadFromFile("assets/other/questionMarkAvatar.jpg");
	Texture MP1AvatarTexture;
	Sprite MP1Avatar;
	Texture MP2AvatarTexture;
	Sprite MP2Avatar;

	Event event;

	menuMusic.setLoop(true);
	menuMusic.play();
	while (window.isOpen()) {
		SteamAPI_RunCallbacks();
		if (treasure < 0) {
			treasure = 0;
		}
		if (checkFrames) {
			if (unlimitedFPS) {
				framerateLimit = 0;
				frameBoxInput = "Unlimited";
			} else {
				if (!frameBoxInput.isEmpty() && frameBoxInput != "Unlimited") {
					framerateLimit = stoi(frameBoxInput.toAnsiString());
				} else {
					framerateLimit = 60;
					frameBoxInput = "60";
				}
			}
			checkFrames = false;
		}
		if (checkVsync) {
			if (vsync) {
				window.setVerticalSyncEnabled(true);
				#ifdef _WIN32  // Windows specific API call
					DEVMODE devMode = {};
					devMode.dmSize = sizeof(devMode);
					if (EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode)) {
						frameBoxInput = to_string(devMode.dmDisplayFrequency);
						framerateLimit = devMode.dmDisplayFrequency;
					}
				#endif
			} else {
				window.setVerticalSyncEnabled(false);
				framerateLimit = 60;
				frameBoxInput = "60";
			}
			checkVsync = false;
		}
		if (updateFPSText.getElapsedTime().asMilliseconds() > 500.0f) {
			FPSText.setString(to_string(static_cast<int>(framerate)));
			updateFPSText.restart();
		}
		window.setFramerateLimit(framerateLimit);
		shader.setUniform("bulgeStrength", bulgeStrength);
		shader.setUniform("saturation", saturation);
		shader.setUniform("contrast", contrast);
		shader.setUniform("scanlines", scanlines);
		shader.setUniform("resolution", Vector2f(window.getSize().x, window.getSize().y));
		if (checkFullscreen) {
			if (!fullscreen) {
				window.create(VideoMode(SCRWIDTH, SCRHEIGHT), "Cannoneer", Style::Titlebar | Style::Close | Style::Default | Style::Resize);
				window.setFramerateLimit(framerateLimit);
				checkFullscreen = false;
			}
			else {
				window.create(VideoMode(SCRWIDTH, SCRHEIGHT), "Cannoneer", Style::Titlebar | Style::Close | Style::Default | Style::Fullscreen);
				window.setFramerateLimit(framerateLimit);
				checkFullscreen = false;
			}
		}
		if (!altFont) {
			vsyncText.setFont(Cannon);
			unlimitedText.setFont(Cannon);
			gameOverScreen.setTexture(gameOverScreenTexture);
			cannoneer.setTexture(cannoneerTexture);
			resetDataButton.setTexture(resetDataButtonTexture);
			saveButton.setTexture(saveButtonTexture);
			restartButton.setTexture(restartButtonTexture);
			menuButton.setTexture(menuButtonTexture);
			playButton.setTexture(playButtonTexture);
			leaderboardButton.setTexture(leaderboardButtonTexture);
			creditsButton.setTexture(creditsButtonTexture);
			settingsButton.setTexture(settingsButtonTexture);
			shopButton.setTexture(shopButtonTexture);
			skinsButton.setTexture(skinsButtonTexture);
			versusButton.setTexture(versusButtonTexture);
			seasonalShopButton.setTexture(seasonalShopButtonTexture);
			comingSoonOverlay.setTexture(comingSoonOverlayTexture);
			creditsText.setTexture(creditsTextTexture);
			creditsThanksText.setTexture(creditsThanksTextTexture);
			titleText.setFont(Cannon);
			scoreText.setFont(Cannon);
			fullscreenText.setFont(Cannon);
			waveText.setFont(Cannon);
			MP1scoreText.setFont(Cannon);
			MP1waveText.setFont(Cannon);
			MP2scoreText.setFont(Cannon);
			MP2waveText.setFont(Cannon);
			pauseText.setFont(Cannon);
			lastScoreText.setFont(Cannon);
			bestScoreText.setFont(Cannon);
			scoreLeaderboardText.setFont(Cannon);
			waveLeaderboardText.setFont(Cannon);
			scoreTitleText.setFont(Cannon);
			waveTitleText.setFont(Cannon);
			waveRecordText.setFont(Cannon);
			musicText.setFont(Cannon);
			SFXText.setFont(Cannon);
			satText.setFont(Cannon);
			frameText.setFont(Cannon);
			conText.setFont(Cannon);
			saturationText.setFont(Cannon);
			contrastText.setFont(Cannon);
			scanText.setFont(Cannon);
			fontText.setFont(Cannon);
			treasureText.setFont(Cannon);
			treasureText1.setFont(Cannon);
			eventText.setFont(Cannon);
			textboxText.setFont(Cannon);
			frameBoxText.setFont(Cannon);
			rewardText.setFont(Cannon);
			versionText.setFont(Cannon);
			MPWarningText.setFont(Cannon);
			MPWarningBoxText.setFont(Cannon);
			MP1Text.setFont(Cannon);
			MP2Text.setFont(Cannon);
			steamText.setFont(Cannon);
			joinText.setFont(Cannon);
			MPText1.setFont(Cannon);
			MPText2.setFont(Cannon);
			MPWinsText.setFont(Cannon);
			rulesText.setFont(Cannon);
			chatBoxText.setFont(Cannon);
			chatText.setFont(Cannon);
			devText.setFont(Cannon);
			newYearsText.setFont(Cannon);
			easterText.setFont(Cannon);
			patrickText.setFont(Cannon);
			julyText.setFont(Cannon);
			halloweenText.setFont(Cannon);
			thanksgivingText.setFont(Cannon);
			winterText.setFont(Cannon);
		} else {
			vsyncText.setFont(alt);
			unlimitedText.setFont(alt);
			gameOverScreen.setTexture(gameOverScreenAltTexture);
			cannoneer.setTexture(cannoneerAltTexture);
			resetDataButton.setTexture(resetDataButtonAltTexture);
			saveButton.setTexture(saveButtonAltTexture);
			restartButton.setTexture(restartButtonAltTexture);
			menuButton.setTexture(menuButtonAltTexture);
			playButton.setTexture(playButtonAltTexture);
			leaderboardButton.setTexture(leaderboardButtonAltTexture);
			creditsButton.setTexture(creditsButtonAltTexture);
			settingsButton.setTexture(settingsButtonAltTexture);
			shopButton.setTexture(shopButtonAltTexture);
			skinsButton.setTexture(skinsButtonAltTexture);
			versusButton.setTexture(versusButtonAltTexture);
			seasonalShopButton.setTexture(seasonalShopButtonAltTexture);
			comingSoonOverlay.setTexture(comingSoonOverlayAltTexture);
			creditsText.setTexture(creditsTextAltTexture);
			creditsThanksText.setTexture(creditsThanksTextAltTexture);
			titleText.setFont(alt);
			scoreText.setFont(alt);
			fullscreenText.setFont(alt);
			waveText.setFont(alt);
			MP1scoreText.setFont(alt);
			MP1waveText.setFont(alt);
			MP2scoreText.setFont(alt);
			MP2waveText.setFont(alt);
			pauseText.setFont(alt);
			lastScoreText.setFont(alt);
			bestScoreText.setFont(alt);
			scoreLeaderboardText.setFont(alt);
			waveLeaderboardText.setFont(alt);
			scoreTitleText.setFont(alt);
			waveTitleText.setFont(alt);
			lastScoreText.setFont(alt);
			waveRecordText.setFont(alt);
			musicText.setFont(alt);
			SFXText.setFont(alt);
			satText.setFont(alt);
			frameText.setFont(alt);
			conText.setFont(alt);
			saturationText.setFont(alt);
			contrastText.setFont(alt);
			scanText.setFont(alt);
			fontText.setFont(alt);
			treasureText.setFont(alt);
			treasureText1.setFont(alt);
			eventText.setFont(alt);
			textboxText.setFont(alt);
			frameBoxText.setFont(alt);
			rewardText.setFont(alt);
			versionText.setFont(alt);
			MPWarningText.setFont(alt);
			MPWarningBoxText.setFont(alt);
			MP1Text.setFont(alt);
			MP2Text.setFont(alt);
			steamText.setFont(alt);
			joinText.setFont(alt);
			MPText1.setFont(alt);
			MPText2.setFont(alt);
			MPWinsText.setFont(alt);
			rulesText.setFont(alt);
			chatBoxText.setFont(alt);
			chatText.setFont(alt);
			devText.setFont(alt);
			newYearsText.setFont(alt);
			easterText.setFont(alt);
			patrickText.setFont(alt);
			julyText.setFont(alt);
			halloweenText.setFont(alt);
			thanksgivingText.setFont(alt);
			winterText.setFont(alt);
		}
		if (scanlines) {
			scanlinesBox.setFillColor(Color(0, 0, 0, 255));
		} else {
			scanlinesBox.setFillColor(Color(38, 38, 38, 255));
		}

		if (fullscreen) {
			fullscreenBox.setFillColor(Color(0, 0, 0, 255));
		} else {
			fullscreenBox.setFillColor(Color(38, 38, 38, 255));
		}

		if (altFont) {
			fontBox.setFillColor(Color(0, 0, 0, 255));
		} else {
			fontBox.setFillColor(Color(38, 38, 38, 255));
		}

		if (vsync) {
			vsyncBox.setFillColor(Color(0, 0, 0, 255));
		} else {
			vsyncBox.setFillColor(Color(38, 38, 38, 255));
		}

		if (unlimitedFPS) {
			unlimitedBox.setFillColor(Color(0, 0, 0, 255));
		}
		else {
			unlimitedBox.setFillColor(Color(38, 38, 38, 255));
		}
		if (anim.getElapsedTime().asMilliseconds() > 20.0f) {
			if (plane1Death) {
				if (frame1.left == 0 && frame1.top == 1024) {
					frame1.left = 0;
					frame1.top = 0;
					plane1Death = false;
				}
				if (frame1.left == 512 && frame1.top == 512) {
					frame1.left = 0;
					frame1.top = 1024;
				}
				if (frame1.left == 0 && frame1.top == 512) {
					frame1.left = 512;
					frame1.top = 512;
				}
				if (frame1.left == 512 && frame1.top == 0) {
					frame1.left = 0;
					frame1.top = 512;
				}
				if (frame1.left == 0 && frame1.top == 0) {
					frame1.left = 512;
					frame1.top = 0;
				}
			}
			if (plane2Death) {
				if (frame2.left == 0 && frame2.top == 1024) {
					frame2.left = 0;
					frame2.top = 0;
					plane2Death = false;
				}
				if (frame2.left == 512 && frame2.top == 512) {
					frame2.left = 0;
					frame2.top = 1024;
				}
				if (frame2.left == 0 && frame2.top == 512) {
					frame2.left = 512;
					frame2.top = 512;
				}
				if (frame2.left == 512 && frame2.top == 0) {
					frame2.left = 0;
					frame2.top = 512;
				}
				if (frame2.left == 0 && frame2.top == 0) {
					frame2.left = 512;
					frame2.top = 0;
				}
			}
			if (plane3Death) {
				if (frame3.left == 0 && frame3.top == 1024) {
					frame3.left = 0;
					frame3.top = 0;
					plane3Death = false;
				}
				if (frame3.left == 512 && frame3.top == 512) {
					frame3.left = 0;
					frame3.top = 1024;
				}
				if (frame3.left == 0 && frame3.top == 512) {
					frame3.left = 512;
					frame3.top = 512;
				}
				if (frame3.left == 512 && frame3.top == 0) {
					frame3.left = 0;
					frame3.top = 512;
				}
				if (frame3.left == 0 && frame3.top == 0) {
					frame3.left = 512;
					frame3.top = 0;
				}
			}
			if (plane4Death) {
				if (frame4.left == 0 && frame4.top == 1024) {
					frame4.left = 0;
					frame4.top = 0;
					plane4Death = false;
				}
				if (frame4.left == 512 && frame4.top == 512) {
					frame4.left = 0;
					frame4.top = 1024;
				}
				if (frame4.left == 0 && frame4.top == 512) {
					frame4.left = 512;
					frame4.top = 512;
				}
				if (frame4.left == 512 && frame4.top == 0) {
					frame4.left = 0;
					frame4.top = 512;
				}
				if (frame4.left == 0 && frame4.top == 0) {
					frame4.left = 512;
					frame4.top = 0;
				}
			}
			if (plane5Death) {
				if (frame5.left == 0 && frame5.top == 1024) {
					frame5.left = 0;
					frame5.top = 0;
					plane5Death = false;
				}
				if (frame5.left == 512 && frame5.top == 512) {
					frame5.left = 0;
					frame5.top = 1024;
				}
				if (frame5.left == 0 && frame5.top == 512) {
					frame5.left = 512;
					frame5.top = 512;
				}
				if (frame5.left == 512 && frame5.top == 0) {
					frame5.left = 0;
					frame5.top = 512;
				}
				if (frame5.left == 0 && frame5.top == 0) {
					frame5.left = 512;
					frame5.top = 0;
				}
			}
			if (plane6Death) {
				if (frame6.left == 0 && frame6.top == 1024) {
					frame6.left = 0;
					frame6.top = 0;
					plane6Death = false;
				}
				if (frame6.left == 512 && frame6.top == 512) {
					frame6.left = 0;
					frame6.top = 1024;
				}
				if (frame6.left == 0 && frame6.top == 512) {
					frame6.left = 512;
					frame6.top = 512;
				}
				if (frame6.left == 512 && frame6.top == 0) {
					frame6.left = 0;
					frame6.top = 512;
				}
				if (frame6.left == 0 && frame6.top == 0) {
					frame6.left = 512;
					frame6.top = 0;
				}
			}
			deathEffect1.setTextureRect(frame1);
			deathEffect2.setTextureRect(frame2);
			deathEffect3.setTextureRect(frame3);
			deathEffect4.setTextureRect(frame4);
			deathEffect5.setTextureRect(frame5);
			deathEffect6.setTextureRect(frame6);
			anim.restart();
		}
		if (MP1anim.getElapsedTime().asMilliseconds() > 20.0f) {
			if (MP1plane1Death) {
				if (frame1.left == 0 && frame1.top == 1024) {
					frame1.left = 0;
					frame1.top = 0;
					MP1plane1Death = false;
				}
				if (frame1.left == 512 && frame1.top == 512) {
					frame1.left = 0;
					frame1.top = 1024;
				}
				if (frame1.left == 0 && frame1.top == 512) {
					frame1.left = 512;
					frame1.top = 512;
				}
				if (frame1.left == 512 && frame1.top == 0) {
					frame1.left = 0;
					frame1.top = 512;
				}
				if (frame1.left == 0 && frame1.top == 0) {
					frame1.left = 512;
					frame1.top = 0;
				}
			}
			if (MP1plane2Death) {
				if (frame2.left == 0 && frame2.top == 1024) {
					frame2.left = 0;
					frame2.top = 0;
					MP1plane2Death = false;
				}
				if (frame2.left == 512 && frame2.top == 512) {
					frame2.left = 0;
					frame2.top = 1024;
				}
				if (frame2.left == 0 && frame2.top == 512) {
					frame2.left = 512;
					frame2.top = 512;
				}
				if (frame2.left == 512 && frame2.top == 0) {
					frame2.left = 0;
					frame2.top = 512;
				}
				if (frame2.left == 0 && frame2.top == 0) {
					frame2.left = 512;
					frame2.top = 0;
				}
			}
			if (MP1plane3Death) {
				if (frame3.left == 0 && frame3.top == 1024) {
					frame3.left = 0;
					frame3.top = 0;
					MP1plane3Death = false;
				}
				if (frame3.left == 512 && frame3.top == 512) {
					frame3.left = 0;
					frame3.top = 1024;
				}
				if (frame3.left == 0 && frame3.top == 512) {
					frame3.left = 512;
					frame3.top = 512;
				}
				if (frame3.left == 512 && frame3.top == 0) {
					frame3.left = 0;
					frame3.top = 512;
				}
				if (frame3.left == 0 && frame3.top == 0) {
					frame3.left = 512;
					frame3.top = 0;
				}
			}
			if (MP1plane4Death) {
				if (frame4.left == 0 && frame4.top == 1024) {
					frame4.left = 0;
					frame4.top = 0;
					MP1plane4Death = false;
				}
				if (frame4.left == 512 && frame4.top == 512) {
					frame4.left = 0;
					frame4.top = 1024;
				}
				if (frame4.left == 0 && frame4.top == 512) {
					frame4.left = 512;
					frame4.top = 512;
				}
				if (frame4.left == 512 && frame4.top == 0) {
					frame4.left = 0;
					frame4.top = 512;
				}
				if (frame4.left == 0 && frame4.top == 0) {
					frame4.left = 512;
					frame4.top = 0;
				}
			}
			if (MP1plane5Death) {
				if (frame5.left == 0 && frame5.top == 1024) {
					frame5.left = 0;
					frame5.top = 0;
					MP1plane5Death = false;
				}
				if (frame5.left == 512 && frame5.top == 512) {
					frame5.left = 0;
					frame5.top = 1024;
				}
				if (frame5.left == 0 && frame5.top == 512) {
					frame5.left = 512;
					frame5.top = 512;
				}
				if (frame5.left == 512 && frame5.top == 0) {
					frame5.left = 0;
					frame5.top = 512;
				}
				if (frame5.left == 0 && frame5.top == 0) {
					frame5.left = 512;
					frame5.top = 0;
				}
			}
			if (MP1plane6Death) {
				if (frame6.left == 0 && frame6.top == 1024) {
					frame6.left = 0;
					frame6.top = 0;
					MP1plane6Death = false;
				}
				if (frame6.left == 512 && frame6.top == 512) {
					frame6.left = 0;
					frame6.top = 1024;
				}
				if (frame6.left == 0 && frame6.top == 512) {
					frame6.left = 512;
					frame6.top = 512;
				}
				if (frame6.left == 512 && frame6.top == 0) {
					frame6.left = 0;
					frame6.top = 512;
				}
				if (frame6.left == 0 && frame6.top == 0) {
					frame6.left = 512;
					frame6.top = 0;
				}
			}
			MP1deathEffect1.setTextureRect(frame1);
			MP1deathEffect2.setTextureRect(frame2);
			MP1deathEffect3.setTextureRect(frame3);
			MP1deathEffect4.setTextureRect(frame4);
			MP1deathEffect5.setTextureRect(frame5);
			MP1deathEffect6.setTextureRect(frame6);
			MP1anim.restart();
		}
		if (MP2anim.getElapsedTime().asMilliseconds() > 20.0f) {
			if (MP2plane1Death) {
				if (frame1.left == 0 && frame1.top == 1024) {
					frame1.left = 0;
					frame1.top = 0;
					MP2plane1Death = false;
				}
				if (frame1.left == 512 && frame1.top == 512) {
					frame1.left = 0;
					frame1.top = 1024;
				}
				if (frame1.left == 0 && frame1.top == 512) {
					frame1.left = 512;
					frame1.top = 512;
				}
				if (frame1.left == 512 && frame1.top == 0) {
					frame1.left = 0;
					frame1.top = 512;
				}
				if (frame1.left == 0 && frame1.top == 0) {
					frame1.left = 512;
					frame1.top = 0;
				}
			}
			if (MP2plane2Death) {
				if (frame2.left == 0 && frame2.top == 1024) {
					frame2.left = 0;
					frame2.top = 0;
					MP2plane2Death = false;
				}
				if (frame2.left == 512 && frame2.top == 512) {
					frame2.left = 0;
					frame2.top = 1024;
				}
				if (frame2.left == 0 && frame2.top == 512) {
					frame2.left = 512;
					frame2.top = 512;
				}
				if (frame2.left == 512 && frame2.top == 0) {
					frame2.left = 0;
					frame2.top = 512;
				}
				if (frame2.left == 0 && frame2.top == 0) {
					frame2.left = 512;
					frame2.top = 0;
				}
			}
			if (MP2plane3Death) {
				if (frame3.left == 0 && frame3.top == 1024) {
					frame3.left = 0;
					frame3.top = 0;
					MP2plane3Death = false;
				}
				if (frame3.left == 512 && frame3.top == 512) {
					frame3.left = 0;
					frame3.top = 1024;
				}
				if (frame3.left == 0 && frame3.top == 512) {
					frame3.left = 512;
					frame3.top = 512;
				}
				if (frame3.left == 512 && frame3.top == 0) {
					frame3.left = 0;
					frame3.top = 512;
				}
				if (frame3.left == 0 && frame3.top == 0) {
					frame3.left = 512;
					frame3.top = 0;
				}
			}
			if (MP2plane4Death) {
				if (frame4.left == 0 && frame4.top == 1024) {
					frame4.left = 0;
					frame4.top = 0;
					MP2plane4Death = false;
				}
				if (frame4.left == 512 && frame4.top == 512) {
					frame4.left = 0;
					frame4.top = 1024;
				}
				if (frame4.left == 0 && frame4.top == 512) {
					frame4.left = 512;
					frame4.top = 512;
				}
				if (frame4.left == 512 && frame4.top == 0) {
					frame4.left = 0;
					frame4.top = 512;
				}
				if (frame4.left == 0 && frame4.top == 0) {
					frame4.left = 512;
					frame4.top = 0;
				}
			}
			if (MP2plane5Death) {
				if (frame5.left == 0 && frame5.top == 1024) {
					frame5.left = 0;
					frame5.top = 0;
					MP2plane5Death = false;
				}
				if (frame5.left == 512 && frame5.top == 512) {
					frame5.left = 0;
					frame5.top = 1024;
				}
				if (frame5.left == 0 && frame5.top == 512) {
					frame5.left = 512;
					frame5.top = 512;
				}
				if (frame5.left == 512 && frame5.top == 0) {
					frame5.left = 0;
					frame5.top = 512;
				}
				if (frame5.left == 0 && frame5.top == 0) {
					frame5.left = 512;
					frame5.top = 0;
				}
			}
			if (MP2plane6Death) {
				if (frame6.left == 0 && frame6.top == 1024) {
					frame6.left = 0;
					frame6.top = 0;
					MP2plane6Death = false;
				}
				if (frame6.left == 512 && frame6.top == 512) {
					frame6.left = 0;
					frame6.top = 1024;
				}
				if (frame6.left == 0 && frame6.top == 512) {
					frame6.left = 512;
					frame6.top = 512;
				}
				if (frame6.left == 512 && frame6.top == 0) {
					frame6.left = 0;
					frame6.top = 512;
				}
				if (frame6.left == 0 && frame6.top == 0) {
					frame6.left = 512;
					frame6.top = 0;
				}
			}
			MP2deathEffect1.setTextureRect(frame1);
			MP2deathEffect2.setTextureRect(frame2);
			MP2deathEffect3.setTextureRect(frame3);
			MP2deathEffect4.setTextureRect(frame4);
			MP2deathEffect5.setTextureRect(frame5);
			MP2deathEffect6.setTextureRect(frame6);
			MP2anim.restart();
		}
		view.setCenter(Vector2f(960, 540));
		view.setSize(Vector2f(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height));
		mousePosWindow = Mouse::getPosition(window);
		mousePosView = window.mapPixelToCoords(mousePosWindow);
		mPosX = mousePosView.x;
		mPosY = mousePosView.y;
		mouseHitbox.setPosition(mPosX, mPosY);
		// Focus Window
		if (!window.hasFocus() && focused) {
			window.setMouseCursorGrabbed(false);
			storeVolumeM = musicVolume;
			storeVolumeS = SFXVolume;
			musicVolume = 0;
			SFXVolume = 0;
			if (!menu && !versus && !gameOver) {
				pause = true;
			}
			focused = false;
		}
		if (window.hasFocus() && !focused) {
			window.setMouseCursorGrabbed(false);
			musicVolume = storeVolumeM;
			SFXVolume = storeVolumeS;
			focused = true;
		}
		// Update Data
		if (score > highScore) {
			highScore = score;
		}
		if (wave > highWave) {
			highWave = wave;
		}
		// Calculate framerate
		currentTime = clock.restart().asSeconds();
		framerate = 1.f / (currentTime);
		// Update volume
		grenadeExplosion.setVolume(SFXVolume);
		newWave.setVolume(SFXVolume);
		select.setVolume(SFXVolume);
		powerup.setVolume(SFXVolume);
		appear.setVolume(SFXVolume);
		bombExplosion.setVolume(SFXVolume);
		shootSound.setVolume(SFXVolume);
		death.setVolume(SFXVolume);
		creditsMusic.setVolume(musicVolume);
		menuMusic.setVolume(musicVolume);
		genret.setVolume(musicVolume);
		march.setVolume(musicVolume);
		// Event loop
		while (window.pollEvent(event)) {
			// Close window
			if (menu && exitable && !seasonalShop && !shop && !leaderboard && !setting && !credit && !skins && !vault && !lobby && !eventActive && Keyboard::isKeyPressed(Keyboard::Escape)) {
				exiting = true;
			}
			if (menu && !seasonalShop && !shop && !leaderboard && !setting && !credit && !skins && !vault && !lobby && !eventActive && event.type == Event::MouseButtonPressed && mouseHitbox.getGlobalBounds().intersects(backButton.getGlobalBounds())) {
				exitbuttonable = true;
			}
			if (menu && exitbuttonable && !seasonalShop && !shop && !leaderboard && !setting && !credit && !skins && !vault && !lobby && !eventActive && event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(backButton.getGlobalBounds())) {
				select.play();
				exiting = true;
			}
			if (event.type == Event::Closed || (Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::F4))) {
				saveOther();
				saveSkins();
				saveSettings();
				SteamAPI_Shutdown();
				window.close();
				return 0;
			}
			if (gameOver) {
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(menuButton.getGlobalBounds())) {
					select.play();
					genret.stop();
					menuMusic.setLoop(true);
					menuMusic.play();
					gameOver = false;
					menu = true;
					playable = false;
					leaderboardable = false;
					shoppable = false;
					seasonalShoppable = false;
					creditable = false;
					skinnable = false;
					settingable = false;
					versusable = false;
				}
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(restartButton.getGlobalBounds())) {
					rotateRight = false;
					rotateLeft = false;
					timer = 0.f;
					frames = 0;
					wave = 0;
					wave5 = 0;
					playerSpeed = ((15.f * wave) + 180.f) / (3.f * framerate);
					bombSpeed = ((90.f * wave) + 2100.f) / (5.f * framerate);
					planeSpeed = ((90.f * wave) + 300.f) / (5.f * framerate);
					shoot = false;
					pickable = false;
					switchTo = false;
					bombShoot = true;
					shots = 0;
					corner1 = 1.f;
					corner2 = 0.f;
					score = 0;
					waveString = to_string(wave);
					scoreString = to_string(score);
					explosionBool = false;
					expTimer = 5;
					pause = false;
					player.setRotation(0);
					playerHitbox1.setRotation(player.getRotation());
					bomb.setPosition(960.f, 540.f);
					bombRotation = 0;
					bomb.setRotation(0);
					bombHitbox.setPosition(bomb.getPosition());
					bombHitbox.setRotation(bomb.getRotation());
					grenade.setPosition(3840.f, 2160.f);
					grenadeHitbox.setPosition(grenade.getPosition());
					plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					plane1Hitbox.setPosition(plane1.getPosition());
					plane2Hitbox.setPosition(plane2.getPosition());
					plane3Hitbox.setPosition(plane3.getPosition());
					plane4Hitbox.setPosition(plane4.getPosition());
					plane5Hitbox.setPosition(plane5.getPosition());
					plane6Hitbox.setPosition(plane6.getPosition());
					explosion.setPosition(5760.f, 3240.f);
					select.play();
					menuMusic.stop();
					genret.setLoop(1);
					genret.play();
					menu = false;
					gameOver = false;
				}
			}
			if (!menu && !versus && !gameOver) {
				// Player rotation (detection)
				if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A) && !pause) {
					rotateLeft = true;
					rotateRight = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D) && !pause) {
					rotateRight = true;
					rotateLeft = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Escape) && !pause) {
					pausable = true;
				}
				if (Keyboard::isKeyPressed(Keyboard::Escape) && pause) {
					unpausable = true;
				}
				if (event.type == Event::KeyReleased) {
					if (event.key.scancode == Keyboard::Scan::Left || event.key.scancode == Keyboard::Scan::A) {
						rotateLeft = false;
					}
					if (event.key.scancode == Keyboard::Scan::Right || event.key.scancode == Keyboard::Scan::D) {
						rotateRight = false;
					}
					if (event.key.scancode == Keyboard::Scan::Escape && pausable) {
						pause = true;
						pausable = false;
						genret.pause();
					}
					if (event.key.scancode == Keyboard::Scan::Escape && unpausable) {
						pause = false;
						unpausable = false;
						genret.play();
					}
				}
				if ((Keyboard::isKeyPressed(Keyboard::Space) || Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)) && !shoot && !pause) {
					shoot = true;
					bombRotation = bomb.getRotation();
					if (shots == 14 && bombShoot) {
						appear.play();
					}
					shootSound.play();
					if (bombShoot) {
						shots++;
					}
				}
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(exitButton.getGlobalBounds())) {
					select.play();
					genret.stop();
					menuMusic.setLoop(true);
					menuMusic.play();
					pause = false;
					menu = true;
					playable = false;
					leaderboardable = false;
					shoppable = false;
					seasonalShoppable = false;
					creditable = false;
					skinnable = false;
					settingable = false;
					versusable = false;
				}
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(returnButton.getGlobalBounds()) && pause) {
					select.play();
					pause = false;
					unpausable = false;
					genret.play();
				}
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(saveButton.getGlobalBounds())) {
					select.play();
					genret.stop();
					menuMusic.setLoop(true);
					menuMusic.play();
					pause = false;
					menu = true;
					playable = false;
					leaderboardable = false;
					seasonalShoppable = false;
					shoppable = false;
					loading = true;
					ofstream loadingout("data/playerState/loading.txt");
					loadingout << loading;
					loadingout.close();
					saveGame();
				}
			}
			if (MPWarning) {
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(MPWarningBox.getGlobalBounds())) {
					select.play();
					showMPWarning = !showMPWarning;
				}
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(returnButton.getGlobalBounds())) {
					select.play();
					MPWarning = false;
					lobby = true;
					exitable = false;
					titleText.setString("Lobby");
				}
			}
			if (lobby) {
				if (Keyboard::isKeyPressed(Keyboard::Up) && !player2Joined) {
					player2Joined = true;
					if (!player2Local) {
						storeChat = chatText.getString();
						chatText.setString(storeChat + "\n<System> A Local Player has joined the lobby!");
					}
					player2Local = true;
				}
				if (Keyboard::isKeyPressed(Keyboard::Tab) && player2Joined && sessionCount <= 1 && !player1Typing && !player2Typing) {
					lobby = false;
					versus = true;
					menu = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Enter) && player1Typing) {
					enterable = false;
					storeChat = chatText.getString();
					chatText.setString(storeChat + "\n<" + hostName + "> " + chatBoxInput);
					chatBoxInput = "";
					chatBoxText.setString("");
					player1Typing = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Enter) && player2Typing) {
					enterable = false;
					storeChat = chatText.getString();
					chatText.setString(storeChat + "\n<" + remoteName + "> " + chatBoxInput);
					chatBoxInput = "";
					chatBoxText.setString("");
					player2Typing = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::LControl) && Keyboard::isKeyPressed(Keyboard::Num1)) {
					player1Typing = true;
				}
				if (Keyboard::isKeyPressed(Keyboard::LControl) && Keyboard::isKeyPressed(Keyboard::Num2) && remoteName != "Invite Player") {
					player2Typing = true;
				}
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(MP2Avatar.getGlobalBounds())) {
					SteamFriends()->ActivateGameOverlay("RemotePlayTogether");
				}
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(backButton.getGlobalBounds())) {
					lobby = false;
					player2Joined = false;
					player2Local = false;
					player2Remote = false;
					exitable = false;
					titleText.setString("");
					select.play();
				}
				if (Keyboard::isKeyPressed(Keyboard::Escape)) {
					lobby = false;
					player2Joined = false;
					player2Local = false;
					player2Remote = false;
					titleText.setString("");
				}
				if (event.type == Event::TextEntered && (player1Typing || player2Typing)) {
					if (event.text.unicode >= 32 && event.text.unicode != 127) {
						chatBoxInput += event.text.unicode;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Backspace) && !chatBoxInput.isEmpty() && (player1Typing || player2Typing)) {
					if (backspaceTimer.getElapsedTime() >= backspaceDelay) {
						chatBoxInput.erase(chatBoxInput.getSize() - 1);
						backspaceTimer.restart();
					}
				}
			} 
			if (menu) {
				s = true;
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(discord.getGlobalBounds())) {
					select.play(); 
					#ifdef _WIN32
					system("start https://discord.com/invite/aBgThJZWHN");
					#elif __APPLE__
					system("open https://discord.com/invite/aBgThJZWHN");
					#else
					system("xdg-open https://discord.com/invite/aBgThJZWHN");
					#endif
				}
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(youtube.getGlobalBounds())) {
					select.play();
					#ifdef _WIN32
					system("start https://youtube.com/@logical7787");
					#elif __APPLE__
					system("open https://youtube.com/@logical7787");
					#else
					system("xdg-open https://youtube.com/@logical7787");
					#endif
				}
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(steam.getGlobalBounds())) {
					select.play();
					#ifdef _WIN32
					system("start https://store.steampowered.com/app/3357860/Cannoneer/");
					#elif __APPLE__
					system("open https://store.steampowered.com/app/3357860/Cannoneer/");
					#else
					system("xdg-open https://store.steampowered.com/app/3357860/Cannoneer/");
					#endif
				}
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(ornament.getGlobalBounds())) {
					select.play();
					exitable = false;
					vault = true;
					textboxText.setString("");
					titleText.setString("Santa's Secret Safe");
				}
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(returnButton.getGlobalBounds()) && eventActive) {
					select.play();
					eventActive = false;
					if (time(NULL) >= 1734411600 && time(NULL) <= 1735362000 && !day1Claimed) {
						day1Claimed = true;
						claimCandyCaneCannon = true;
					}
					if (time(NULL) >= 1734498000 && time(NULL) <= 1734584399 && !day2Claimed) {
						day2Claimed = true;
						claimFestivePlane = true;
					}
					if (time(NULL) >= 1734584400 && time(NULL) <= 1734670799 && !day3Claimed) {
						day3Claimed = true;
						claimIcyBomb = true;
					}
					if (time(NULL) >= 1734670800 && time(NULL) <= 1734757199 && !day4Claimed) {
						day4Claimed = true;
						claimCookiePlane = true;
					}
					if (time(NULL) >= 1734757200 && time(NULL) <= 1734843599 && !day5Claimed) {
						day5Claimed = true;
						claimGoldenCannon = true;
					}
					if (time(NULL) >= 1734843600 && time(NULL) <= 1734929999 && !day6Claimed) {
						day6Claimed = true;
						claimChocolateGrenade = true;
					}
					if (time(NULL) >= 1734930000 && time(NULL) <= 1735016399 && !day7Claimed) {
						day7Claimed = true;
						claimPeppermintBomb = true;
					}
					if (time(NULL) >= 1735016400 && time(NULL) <= 1735102799 && !day8Claimed) {
						day8Claimed = true;
						claimFestiveExplosion = true;
					}
					if (time(NULL) >= 1735102800 && time(NULL) <= 1735189199 && !day9Claimed) {
						day9Claimed = true;
						claimLogicalCannon = true;
					}
					if (time(NULL) >= 1735189200 && time(NULL) <= 1735275599 && !day10Claimed) {
						day10Claimed = true;
						claimSnowyExplosion = true;
					}
					if (time(NULL) >= 1735275600 && time(NULL) <= 1735361999 && !day11Claimed) {
						day11Claimed = true;
						claimOrangeBomb = true;
					}
					if (time(NULL) >= 1735362000 && time(NULL) <= 1735448399 && !day12Claimed) {
						day12Claimed = true;
						claimGingerbreadExplosion = true;
					}
				}
				if (lobby) {
					MP1pickable = false;
					MP1switchTo = false;
					MP2pickable = false;
					MP2switchTo = false;
					MP1explosionBool = false;
					MP2explosionBool = false;
					MP1bombShoot = true;
					MP2bombShoot = true;
					MP1plane1Death = false;
					MP1plane2Death = false;
					MP1plane3Death = false;
					MP1plane4Death = false;
					MP1plane5Death = false;
					MP1plane6Death = false;
					MP2plane1Death = false;
					MP2plane2Death = false;
					MP2plane3Death = false;
					MP2plane4Death = false;
					MP2plane5Death = false;
					MP2plane6Death = false;
					MP1rotateRight = false;
					MP1rotateLeft = false;
					MP2rotateRight = false;
					MP2rotateLeft = false;
					MP1shoot = false;
					MP1plane1corner;
					MP1plane2corner;
					MP1plane3corner;
					MP1plane4corner;
					MP1plane5corner;
					MP1plane6corner;
					MP2plane1corner;
					MP2plane2corner;
					MP2plane3corner;
					MP2plane4corner;
					MP2plane5corner;
					MP2plane6corner;
					MP1corner1 = 1;
					MP1corner2 = 0;
					MP2corner1 = 1;
					MP2corner2 = 0;
					MP1shots = 0;
					MP2shots = 0;
					MP1score = 0;
					MP2score = 0;
					MP1lastCorner1;
					MP1lastCorner2;
					MP2lastCorner1;
					MP2lastCorner2;
					MP1bombRotation = 0;
					MP2bombRotation = 0;
					MP1bombRadians;
					MP1x;
					MP1y;
					MP2bombRadians;
					MP2x;
					MP2y;
					MP1expTimer = 5;
					MP2expTimer = 5;
					MP1plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					MP1plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					MP1plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					MP1plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					MP1plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					MP1plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					MP2plane1.setPosition(960 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					MP2plane2.setPosition(960 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					MP2plane3.setPosition(960 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					MP2plane4.setPosition(960 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					MP2plane5.setPosition(960 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					MP2plane6.setPosition(960 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					hostSteamID = SteamUser()->GetSteamID();
					hostName = SteamFriends()->GetPersonaName();
					int MP1avatarHandle = SteamFriends()->GetLargeFriendAvatar(hostSteamID);
					uint32 MP1width, MP1height;
					SteamUtils()->GetImageSize(MP1avatarHandle, &MP1width, &MP1height);
					vector<uint8_t> MP1imageData(AvatarWidth * AvatarHeight * 4);
					SteamUtils()->GetImageRGBA(MP1avatarHandle, MP1imageData.data(), MP1imageData.size());
					MP1AvatarTexture.create(AvatarWidth, AvatarHeight);
					MP1AvatarTexture.update(MP1imageData.data());
					MP1Avatar.setTexture(MP1AvatarTexture);
					sessionCount = SteamRemotePlay()->GetSessionCount();
					if (sessionCount > 0) {
						sessionID = SteamRemotePlay()->GetSessionID(0);
						remoteSteamID = SteamRemotePlay()->GetSessionSteamID(sessionID);
						if (remoteSteamID.IsValid()) {
							remoteName = SteamFriends()->GetFriendPersonaName(remoteSteamID);
							if (!player2Remote) {
								storeChat = chatText.getString();
								chatText.setString(storeChat + "\n<System> " + remoteName + " has joined the lobby!");
							}
							player2Remote = true;
							int MP2avatarHandle = SteamFriends()->GetLargeFriendAvatar(remoteSteamID);
							uint32 MP2width, MP2height;
							SteamUtils()->GetImageSize(MP2avatarHandle, &MP2width, &MP2height);
							vector<uint8_t> MP2imageData(AvatarWidth * AvatarHeight * 4);
							SteamUtils()->GetImageRGBA(MP2avatarHandle, MP2imageData.data(), MP2imageData.size());
							MP2AvatarTexture.create(AvatarWidth, AvatarHeight);
							MP2AvatarTexture.update(MP2imageData.data());
							MP2Avatar.setTexture(MP2AvatarTexture);
						}
					} else {
						if (player2Local) {
							remoteName = "Local Player";
						}
						else if (!player2Joined) {
							remoteName = "Invite Player";
						}
						MP2Avatar.setTexture(defaultAvatarTexture);
					}
					MP1Avatar.setOrigin(92, 92);
					MP1Avatar.setPosition(1350, 900);
					MP1Avatar.setScale(0.6, 0.6);

					MP2Avatar.setOrigin(92, 92);
					MP2Avatar.setPosition(1750, 900);
					MP2Avatar.setScale(0.6, 0.6);
					
					FloatRect chatBoxRect = chatBoxText.getLocalBounds();
					chatBoxText.setOrigin(chatBoxRect.left + chatBoxRect.width / 2.f, chatBoxRect.top + chatBoxRect.height / 2.f);
					chatBoxText.setPosition(Vector2f(300.0f, 600.0f));
					FloatRect chatRect = chatText.getLocalBounds();
					chatText.setOrigin(chatRect.left, chatRect.top + chatRect.height);
					chatText.setPosition(Vector2f(190.0f, 520.0f));
					if (textboxText.getString() == "") {
						chatBox.setSize(Vector2f(100, 20));
						chatBox.setOrigin(50, 10);
					}
					else {
						chatBox.setSize(Vector2f((chatBoxRect.getSize().x + 20) / 2, 20));
						chatBox.setOrigin((chatBoxRect.getSize().x + 20) / 4, 10);
					}

					FloatRect MP1Rect = MP1Text.getLocalBounds();
					MP1Text.setOrigin(MP1Rect.left + MP1Rect.width / 2.f, MP1Rect.top + MP1Rect.height / 2.f);
					MP1Text.setPosition(Vector2f(1350, 800));
					MP1Text.setString(hostName);

					FloatRect MP2Rect = MP2Text.getLocalBounds();
					MP2Text.setOrigin(MP2Rect.left + MP2Rect.width / 2.f, MP2Rect.top + MP2Rect.height / 2.f);
					MP2Text.setPosition(Vector2f(1750, 800));
					MP2Text.setString(remoteName);

					FloatRect joinRect = joinText.getLocalBounds();
					joinText.setOrigin(joinRect.left + joinRect.width / 2.f, joinRect.top + joinRect.height / 2.f);
					joinText.setPosition(Vector2f(1550, 700));

					FloatRect MPRect1 = MPText1.getLocalBounds();
					MPText1.setOrigin(MPRect1.left + MPRect1.width / 2.f, MPRect1.top + MPRect1.height / 2.f);
					MPText1.setPosition(Vector2f(1450, 100));
					MPText1.setString("Player 1");

					FloatRect MPRect2 = MPText2.getLocalBounds();
					MPText2.setOrigin(MPRect2.left + MPRect2.width / 2.f, MPRect2.top + MPRect2.height / 2.f);
					MPText2.setPosition(Vector2f(1650, 100));
					MPText2.setString("Player 2");

					FloatRect MPWinsRect = MPWinsText.getLocalBounds();
					MPWinsText.setOrigin(MPWinsRect.left + MPWinsRect.width / 2.f, MPWinsRect.top + MPWinsRect.height / 2.f);
					MPWinsText.setPosition(Vector2f(1550, 200));
					MPWinsText.setString(to_string(MP1wins) + " - " + to_string(MP2wins));

					FloatRect rulesRect = rulesText.getLocalBounds();
					rulesText.setOrigin(rulesRect.left + rulesRect.width / 2.f, rulesRect.top + rulesRect.height / 2.f);
					rulesText.setPosition(Vector2f(1550, 500));
					if (!altFont) {
						rulesText.setString("Multiplayer does not support:\n                Achievements,\n                    Treasure,\n            Seperate Settings,\n                      or Skins.");
					} else {
						rulesText.setString("Multiplayer does not support:\n           Achievements,\n             Treasure,\n        Seperate Settings,\n              or Skins.");
					}

					if (!player2Joined) {
						joinText.setString("Player 2, press up arrow to join locally.");
					} else {
						if (sessionCount <= 1) {
							joinText.setString("Press Tab to start game!");
						} else {
							joinText.setString("Too many remote players!");
						}
					}
					chatBoxText.setString(chatBoxInput);
				}
				if (seasonalShop) {
					if (event.type == sf::Event::MouseWheelScrolled) {
						if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
							if (event.mouseWheelScroll.delta > 0) {
								scrollOffset -= 30;
							}
							else if (event.mouseWheelScroll.delta < 0) {
								scrollOffset += 30;
							}
						}
					}

					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(backButton.getGlobalBounds()) || Keyboard::isKeyPressed(Keyboard::Escape)) {
						seasonalShop = false;
						exitable = false;
						titleText.setString("");
						select.play();
					}
				}
				if (shop) {
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(treasureChest.getGlobalBounds()) && !claimTreasure) {
						select.play();
						claimTreasure = true;
						treasure += 100;
						setCAN_TREASURE();
						saveStats();
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(cannonShopButton.getGlobalBounds())) {
						select.play();
						cannonShop = true;
						bombShop = false;
						grenadeShop = false;
						explosionShop = false;
						planeShop = false;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(bombShopButton.getGlobalBounds())) {
						select.play();
						cannonShop = false;
						bombShop = true;
						grenadeShop = false;
						explosionShop = false;
						planeShop = false;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(grenadeShopButton.getGlobalBounds())) {
						select.play();
						cannonShop = false;
						bombShop = false;
						grenadeShop = true;
						explosionShop = false;
						planeShop = false;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(explosionShopButton.getGlobalBounds())) {
						select.play();
						cannonShop = false;
						bombShop = false;
						grenadeShop = false;
						explosionShop = true;
						planeShop = false;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(planeShopButton.getGlobalBounds())) {
						select.play();
						cannonShop = false;
						bombShop = false;
						grenadeShop = false;
						explosionShop = false;
						planeShop = true;
					}
					if (cannonShop) {
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton.getGlobalBounds()) && !claimPeashooterCannon && treasure >= 1000) {
							select.play();
							claimPeashooterCannon = true;
							treasure -= 1000;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton2.getGlobalBounds()) && !claimYippeeCannon && treasure >= 750) {
							select.play();
							claimYippeeCannon = true;
							treasure -= 750;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton3.getGlobalBounds()) && !claimSugarCannon && treasure >= 1000) {
							claimSugarCannon = true;
							treasure -= 1000;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton4.getGlobalBounds()) && !claimFireCannon && treasure >= 1000) {
							select.play();
							claimFireCannon = true;
							treasure -= 1000;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton7.getGlobalBounds()) && !claimFlameCannon && treasure >= 1500) {
							select.play();
							claimFlameCannon = true;
							treasure -= 1500;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton15.getGlobalBounds()) && !claimDeadpoolCannon && treasure >= 1000) {
							select.play();
							claimDeadpoolCannon = true;
							treasure -= 1000;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton16.getGlobalBounds()) && !claimShockCannon && treasure >= 1000) {
							select.play();
							claimShockCannon = true;
							treasure -= 1000;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton17.getGlobalBounds()) && !claimBirdoCannon && treasure >= 1000) {
							select.play();
							claimBirdoCannon = true;
							treasure -= 1500;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton18.getGlobalBounds()) && !claimHeartsCannon && treasure >= 1500) {
							select.play();
							claimHeartsCannon = true;
							treasure -= 1500;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton19.getGlobalBounds()) && !claimLogicalCannon && treasure >= 1500) {
							select.play();
							claimLogicalCannon = true;
							treasure -= 1500;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton31.getGlobalBounds()) && !claimApocCannon && treasure >= 1500) {
							select.play();
							claimApocCannon = true;
							treasure -= 1500;
						}
					}
					if (bombShop) {
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton5.getGlobalBounds()) && !claimYippeeBomb && treasure >= 500) {
							select.play();
							claimYippeeBomb = true;
							treasure -= 500;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton6.getGlobalBounds()) && !claimFireBomb && treasure >= 500) {
							select.play();
							claimFireBomb = true;
							treasure -= 500;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton20.getGlobalBounds()) && !claimYoshiBomb && treasure >= 750) {
							select.play();
							claimYoshiBomb = true;
							treasure -= 750;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton21.getGlobalBounds()) && !claimBirdoBomb && treasure >= 750) {
							select.play();
							claimBirdoBomb = true;
							treasure -= 750;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton26.getGlobalBounds()) && !claimLogicalBomb && treasure >= 750) {
							select.play();
							claimLogicalBomb = true;
							treasure -= 750;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton32.getGlobalBounds()) && !claimApocBomb && treasure >= 750) {
							select.play();
							claimApocBomb = true;
							treasure -= 750;
						}
					}
					if (grenadeShop) {
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton8.getGlobalBounds()) && !claimFireGrenade && treasure >= 500) {
							select.play();
							claimFireGrenade = true;
							treasure -= 500;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton9.getGlobalBounds()) && !claimYippeeGrenade && treasure >= 500) {
							select.play();
							claimYippeeGrenade = true;
							treasure -= 500;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton10.getGlobalBounds()) && !claimLogicalGrenade && treasure >= 750) {
							select.play();
							claimLogicalGrenade = true;
							treasure -= 750;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton22.getGlobalBounds()) && !claimDynamiteGrenade && treasure >= 750) {
							select.play();
							claimDynamiteGrenade = true;
							treasure -= 750;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton23.getGlobalBounds()) && !claimNukeGrenade && treasure >= 500) {
							select.play();
							claimNukeGrenade = true;
							treasure -= 500;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton24.getGlobalBounds()) && !claimSmokeGrenade && treasure >= 750) {
							select.play();
							claimSmokeGrenade = true;
							treasure -= 750;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton25.getGlobalBounds()) && !claimHolyHandGrenade && treasure >= 1000) {
							select.play();
							claimHolyHandGrenade = true;
							treasure -= 1000;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton33.getGlobalBounds()) && !claimApocGrenade && treasure >= 750) {
							select.play();
							claimApocGrenade = true;
							treasure -= 750;
						}
					}
					if (explosionShop) {
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton11.getGlobalBounds()) && !claimYippeeExplosion && treasure >= 750) {
							select.play();
							claimYippeeExplosion = true;
							treasure -= 750;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton27.getGlobalBounds()) && !claimLogicalExplosion && treasure >= 1000) {
							select.play();
							claimLogicalExplosion = true;
							treasure -= 1000;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton28.getGlobalBounds()) && !claimMushroomExplosion && treasure >= 1000) {
							select.play();
							claimMushroomExplosion = true;
							treasure -= 1000;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton29.getGlobalBounds()) && !claimSmokeExplosion && treasure >= 750) {
							select.play();
							claimSmokeExplosion = true;
							treasure -= 750;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton34.getGlobalBounds()) && !claimApocExplosion && treasure >= 1000) {
							select.play();
							claimApocExplosion = true;
							treasure -= 750;
						}
					}
					if (planeShop) {
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton12.getGlobalBounds()) && !claimYippeePlane && treasure >= 750) {
							select.play();
							claimYippeePlane = true;
							treasure -= 750;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton13.getGlobalBounds()) && !claimFirePlane && treasure >= 750) {
							select.play();
							claimFirePlane = true;
							treasure -= 750;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton14.getGlobalBounds()) && !claimLogicalPlane && treasure >= 750) {
							select.play();
							claimLogicalPlane = true;
							treasure -= 750;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton30.getGlobalBounds()) && !claimFighterPlane && treasure >= 1000) {
							select.play();
							claimFighterPlane = true;
							treasure -= 1000;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(buyButton35.getGlobalBounds()) && !claimApocPlane && treasure >= 750) {
							select.play();
							claimApocPlane = true;
							treasure -= 750;
						}
					}
					if (Keyboard::isKeyPressed(Keyboard::Escape)) {
						shop = false;
						titleText.setString("");
						march.stop();
						menuMusic.setLoop(true);
						menuMusic.play();
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(backButton.getGlobalBounds())) {
						shop = false;
						exitable = false;
						titleText.setString("");
						march.stop();
						menuMusic.setLoop(true);
						menuMusic.play();
						select.play();
					}
				}
				if (skins) {
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(cannonButton.getGlobalBounds())) {
						select.play();
						cannonSkin = true;
						bombSkin = false;
						grenadeSkin = false;
						explosionSkin = false;
						planeSkin = false;
						page = 1;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(bombButton.getGlobalBounds())) {
						select.play();
						cannonSkin = false;
						bombSkin = true;
						grenadeSkin = false;
						explosionSkin = false;
						planeSkin = false;
						page = 1;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(grenadeButton.getGlobalBounds())) {
						select.play();
						cannonSkin = false;
						bombSkin = false;
						grenadeSkin = true;
						explosionSkin = false;
						planeSkin = false;
						page = 1;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(explosionButton.getGlobalBounds())) {
						select.play();
						cannonSkin = false;
						bombSkin = false;
						grenadeSkin = false;
						explosionSkin = true;
						planeSkin = false;
						page = 1;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(planeButton.getGlobalBounds())) {
						select.play();
						cannonSkin = false;
						bombSkin = false;
						grenadeSkin = false;
						explosionSkin = false;
						planeSkin = true;
						page = 1;
					}
					if (cannonSkin) {
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon1.getGlobalBounds())) {
							select.play();
							equippedCannon = 0;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon2.getGlobalBounds()) && claimCandyCaneCannon) {
							select.play();
							equippedCannon = 1;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon3.getGlobalBounds()) && claimFireCannon) {
							select.play();
							equippedCannon = 2;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon4.getGlobalBounds()) && claimYippeeCannon) {
							select.play();
							equippedCannon = 3;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon5.getGlobalBounds()) && claimGoldenCannon) {
							select.play();
							equippedCannon = 4;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon6.getGlobalBounds()) && claimLogicalCannon) {
							select.play();
							equippedCannon = 5;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon7.getGlobalBounds()) && claimPeashooterCannon) {
							select.play();
							equippedCannon = 6;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon8.getGlobalBounds()) && claimSugarCannon) {
							select.play();
							equippedCannon = 7;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon21.getGlobalBounds()) && claimFlameCannon) {
							select.play();
							equippedCannon = 8;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon38.getGlobalBounds()) && claimGingerbreadCannon) {
							select.play();
							equippedCannon = 9;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon39.getGlobalBounds()) && claimSnowmanCannon) {
							select.play();
							equippedCannon = 10;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon40.getGlobalBounds()) && claimPresentCannon) {
							select.play();
							equippedCannon = 11;
						}
						if (page == 2) {
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon47.getGlobalBounds()) && claimDeadpoolCannon) {
								select.play();
								equippedCannon = 12;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon48.getGlobalBounds()) && claimShockCannon) {
								select.play();
								equippedCannon = 13;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon49.getGlobalBounds()) && claimBirdoCannon) {
								select.play();
								equippedCannon = 14;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon50.getGlobalBounds()) && claimHeartsCannon) {
								select.play();
								equippedCannon = 15;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon62.getGlobalBounds()) && claimApocCannon) {
								select.play();
								equippedCannon = 16;
							}
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(rightArrow.getGlobalBounds()) && page <= 1) {
							select.play();
							page++;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(leftArrow.getGlobalBounds()) && page >= 2) {
							select.play();
							page--;
						}
					}
					if (bombSkin) {
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon9.getGlobalBounds())) {
							select.play();
							equippedBomb = 0;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon10.getGlobalBounds()) && claimFireBomb) {
							select.play();
							equippedBomb = 1;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon11.getGlobalBounds()) && claimIcyBomb) {
							select.play();
							equippedBomb = 2;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon12.getGlobalBounds()) && claimOrangeBomb) {
							select.play();
							equippedBomb = 3;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon13.getGlobalBounds()) && claimPeppermintBomb) {
							select.play();
							equippedBomb = 4;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon14.getGlobalBounds()) && claimYippeeBomb) {
							select.play();
							equippedBomb = 5;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon41.getGlobalBounds()) && claimSantasBomb) {
							select.play();
							equippedBomb = 6;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon42.getGlobalBounds()) && claimBellBomb) {
							select.play();
							equippedBomb = 7;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon51.getGlobalBounds()) && claimYoshiBomb) {
							select.play();
							equippedBomb = 8;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon52.getGlobalBounds()) && claimBirdoBomb) {
							select.play();
							equippedBomb = 9;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon57.getGlobalBounds()) && claimLogicalBomb) {
							select.play();
							equippedBomb = 10;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon63.getGlobalBounds()) && claimApocBomb) {
							select.play();
							equippedBomb = 11;
						}
					}
					if (grenadeSkin) {
						if (page == 1) {
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon22.getGlobalBounds())) {
								select.play();
								equippedGrenade = 0;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon23.getGlobalBounds()) && claimFireGrenade) {
								select.play();
								equippedGrenade = 1;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon24.getGlobalBounds()) && claimYippeeGrenade) {
								select.play();
								equippedGrenade = 2;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon25.getGlobalBounds()) && claimLogicalGrenade) {
								select.play();
								equippedGrenade = 3;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon26.getGlobalBounds()) && claimChocolateGrenade) {
								select.play();
								equippedGrenade = 4;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon15.getGlobalBounds()) && claimChristmasGrenade) {
								select.play();
								equippedGrenade = 5;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon16.getGlobalBounds()) && claimGarlandGrenade) {
								select.play();
								equippedGrenade = 6;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon17.getGlobalBounds()) && claimIceGrenade) {
								select.play();
								equippedGrenade = 7;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon18.getGlobalBounds()) && claimSantaGrenade) {
								select.play();
								equippedGrenade = 8;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon53.getGlobalBounds()) && claimDynamiteGrenade) {
								select.play();
								equippedGrenade = 9;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon54.getGlobalBounds()) && claimNukeGrenade) {
								select.play();
								equippedGrenade = 10;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon55.getGlobalBounds()) && claimSmokeGrenade) {
								select.play();
								equippedGrenade = 11;
							}
						}
						if (page == 2) {
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon56.getGlobalBounds()) && claimHolyHandGrenade) {
								select.play();
								equippedGrenade = 12;
							}
							if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon64.getGlobalBounds()) && claimApocGrenade) {
								select.play();
								equippedGrenade = 13;
							}
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(rightArrow.getGlobalBounds()) && page <= 1) {
							select.play();
							page++;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(leftArrow.getGlobalBounds()) && page >= 2) {
							select.play();
							page--;
						}
					}
					if (explosionSkin) {
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon27.getGlobalBounds())) {
							select.play();
							equippedExplosion = 0;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon28.getGlobalBounds()) && claimYippeeExplosion) {
							select.play();
							equippedExplosion = 1;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon29.getGlobalBounds()) && claimFestiveExplosion) {
							select.play();
							equippedExplosion = 2;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon30.getGlobalBounds()) && claimSnowyExplosion) {
							select.play();
							equippedExplosion = 3;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon31.getGlobalBounds()) && claimGingerbreadExplosion) {
							select.play();
							equippedExplosion = 4;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon19.getGlobalBounds()) && claimElfExplosion) {
							select.play();
							equippedExplosion = 5;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon43.getGlobalBounds()) && claimSnowExplosion) {
							select.play();
							equippedExplosion = 6;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon58.getGlobalBounds()) && claimLogicalExplosion) {
							select.play();
							equippedExplosion = 7;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon59.getGlobalBounds()) && claimMushroomExplosion) {
							select.play();
							equippedExplosion = 8;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon60.getGlobalBounds()) && claimSmokeExplosion) {
							select.play();
							equippedExplosion = 9;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon65.getGlobalBounds()) && claimApocExplosion) {
							select.play();
							equippedExplosion = 10;
						}
					}
					if (planeSkin) {
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon32.getGlobalBounds())) {
							select.play();
							equippedPlane = 0;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon33.getGlobalBounds()) && claimYippeePlane) {
							select.play();
							equippedPlane = 1;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon34.getGlobalBounds()) && claimFirePlane) {
							select.play();
							equippedPlane = 2;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon35.getGlobalBounds()) && claimLogicalPlane) {
							select.play();
							equippedPlane = 3;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon36.getGlobalBounds()) && claimFestivePlane) {
							select.play();
							equippedPlane = 4;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon37.getGlobalBounds()) && claimCookiePlane) {
							select.play();
							equippedPlane = 5;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon44.getGlobalBounds()) && claimRudolphPlane) {
							select.play();
							equippedPlane = 6;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon45.getGlobalBounds()) && claimSantasPlane) {
							select.play();
							equippedPlane = 7;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon46.getGlobalBounds()) && claimTreePlane) {
							select.play();
							equippedPlane = 8;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon61.getGlobalBounds()) && claimFighterPlane) {
							select.play();
							equippedPlane = 9;
						}
						if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(icon66.getGlobalBounds()) && claimApocPlane) {
							select.play();
							equippedPlane = 10;
						}
					}
					if (Keyboard::isKeyPressed(Keyboard::Escape)) {
						skins = false;
						titleText.setString("");
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(backButton.getGlobalBounds())) {
						skins = false;
						exitable = false;
						titleText.setString("");
						select.play();
					}
				}
				if (!leaderboard && !seasonalShop && !shop && !credit && !setting && !skins && !exiting && !vault && !MPWarning && !lobby && menu) {
					if (event.type == Event::MouseButtonPressed && mouseHitbox.getGlobalBounds().intersects(leaderboardButton.getGlobalBounds()) && !eventActive) {
						leaderboardable = true;
					}
					if (event.type == Event::MouseButtonPressed && mouseHitbox.getGlobalBounds().intersects(playButton.getGlobalBounds()) && !eventActive) {
						playable = true;
					}
					if (event.type == Event::MouseButtonPressed && mouseHitbox.getGlobalBounds().intersects(shopButton.getGlobalBounds()) && !eventActive) {
						shoppable = true;
					}
					if (event.type == Event::MouseButtonPressed && mouseHitbox.getGlobalBounds().intersects(seasonalShopButton.getGlobalBounds()) && !eventActive) {
						seasonalShoppable = true;
					}
					if (event.type == Event::MouseButtonPressed && mouseHitbox.getGlobalBounds().intersects(creditsButton.getGlobalBounds()) && !eventActive) {
						creditable = true;
					}
					if (event.type == Event::MouseButtonPressed && mouseHitbox.getGlobalBounds().intersects(settingsButton.getGlobalBounds()) && !eventActive) {
						settingable = true;
					}
					if (event.type == Event::MouseButtonPressed && mouseHitbox.getGlobalBounds().intersects(skinsButton.getGlobalBounds()) && !eventActive) {
						skinnable = true;
					}
					/*if (event.type == Event::MouseButtonPressed && mouseHitbox.getGlobalBounds().intersects(versusButton.getGlobalBounds()) && !eventActive && s) {
						versusable = true;
					}*/
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(creditsButton.getGlobalBounds()) && creditable && !eventActive) {
						menuMusic.stop();
						select.play();
						credit = true;
						titleText.setString("Credits");
						exitable = false;
						creditsMusic.play();
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(skinsButton.getGlobalBounds()) && skinnable && !eventActive) {
						cannonSkin = true;
						bombSkin = false;
						grenadeSkin = false;
						explosionSkin = false;
						planeSkin = false;
						select.play();
						skins = true;
						titleText.setString("Skins");
						exitable = false;
					}
					/*if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(versusButton.getGlobalBounds()) && versusable && !eventActive && s) {
						select.play();
						if (SteamAPI_Init()) {
							if (showMPWarning) {
								MPWarning = true;
								exitable = false;
							}
							else {
								menuMusic.stop();
								lobby = true;
								exitable = false;
								titleText.setString("Lobby");
							}
							steamText.setString("");
						} else {
							steamText.setString("Steam API is not working, try again later.");
						}
					}*/
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(settingsButton.getGlobalBounds()) && settingable && !eventActive) {
						select.play();
						setting = true;
						titleText.setString("Settings");
						exitable = false;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(leaderboardButton.getGlobalBounds()) && leaderboardable && !eventActive) {
						select.play();
						leaderboardManager.FetchTopScores();
						leaderboard = true;
						titleText.setString("Scores");
						exitable = false;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(shopButton.getGlobalBounds()) && shoppable && !eventActive) {
						select.play();
						menuMusic.pause();
						march.setLoop(1);
						march.play();
						cannonShop = true;
						bombShop = false;
						grenadeShop = false;
						explosionShop = false;
						planeShop = false;
						shop = true;
						titleText.setString("Shop");
						exitable = false;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(seasonalShopButton.getGlobalBounds()) && seasonalShoppable && !eventActive) {
						select.play();
						menuMusic.pause();
						march.setLoop(1);
						march.play();
						scrollOffset = 0;
						seasonalShop = true;
						titleText.setString("Seasonal Shop");
						exitable = false;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(playButton.getGlobalBounds()) && playable && !eventActive) {
						select.play();
						menuMusic.stop();
						genret.setLoop(1);
						genret.play();
						menu = false;
						ifstream loadingin("data/playerState/loading.txt");
						loadingin >> loading;
						loadingin.close();
						if (loading) {
							loadGame();
							loading = false;
							ofstream loadingout("data/playerState/loading.txt");
							loadingout << loading;
							loadingout.close();
						}
					}
				}
				if (vault) {
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(backButton.getGlobalBounds())) {
						vault = false;
						exitable = false;
						titleText.setString("");
						select.play();
					}
					if (Keyboard::isKeyPressed(Keyboard::Escape)) {
						vault = false;
						titleText.setString("");
						select.play();
					}
					if (event.type == Event::TextEntered) {
						if (event.text.unicode >= 32 && event.text.unicode != 127) {
							textBoxInput += event.text.unicode;
						}
					}
					if (Keyboard::isKeyPressed(Keyboard::Backspace) && !textBoxInput.isEmpty()) {
						if (backspaceTimer.getElapsedTime() >= backspaceDelay) {
							textBoxInput.erase(textBoxInput.getSize() - 1);
							backspaceTimer.restart();
						}
					}
					textboxText.setString(textBoxInput);
					if (event.type == Event::MouseButtonPressed && mouseHitbox.getGlobalBounds().intersects(santa.getGlobalBounds())) {
						santa.setScale(10, 10);
					} else {
						santa.setScale(9, 9);
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(santa.getGlobalBounds()) || (event.type == Event::KeyPressed && event.key.scancode == sf::Keyboard::Scan::Enter)) {
						select.play();
						textBoxInput = textboxText.getString();
						if (textBoxInput != "whitechristmas" && textBoxInput != "ginger" && textBoxInput != "present" && textBoxInput != "runrunrudolph" && textBoxInput != "nuclearwinter" && textBoxInput != "rizzmas" && textBoxInput != "santassleigh" && textBoxInput != "santashelper" && textBoxInput != "freezenova" && textBoxInput != "jinglebells" && textBoxInput != "merrychristmas" && textBoxInput != "seasonsgreetings" && textBoxInput != "letitsnow" && textBoxInput != "candycane") {
							rewardText.setString("Nothing...");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "whitechristmas" && !claimSnowmanCannon) {
							claimSnowmanCannon = true;
							rewardText.setString("Claimed Snowman Cannon");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "whitechristmas" && claimSnowmanCannon) {
							rewardText.setString("Already Claimed");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "ginger" && !claimGingerbreadCannon) {
							claimGingerbreadCannon = true;
							rewardText.setString("Claimed Gingerbread Cannon");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "ginger" && claimGingerbreadCannon) {
							rewardText.setString("Already Claimed");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "present" && !claimPresentCannon) {
							claimPresentCannon = true;
							rewardText.setString("Claimed Present Cannon");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "present" && claimPresentCannon) {
							rewardText.setString("Already Claimed");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "nuclearwinter" && !claimSantasBomb) {
							claimSantasBomb = true;
							rewardText.setString("Claimed Santa's Bomb");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "nuclearwinter" && claimSantasBomb) {
							rewardText.setString("Already Claimed");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "jinglebells" && !claimBellBomb) {
							claimBellBomb = true;
							rewardText.setString("Claimed Jingle Bell Bomb");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "jinglebells" && claimBellBomb) {
							rewardText.setString("Already Claimed");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "candycane" && !claimChristmasGrenade) {
							claimChristmasGrenade = true;
							rewardText.setString("Claimed Candy Cane Grenade");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "candycane" && claimChristmasGrenade) {
							rewardText.setString("Already Claimed");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "rizzmas" && !claimSantaGrenade) {
							claimSantaGrenade = true;
							rewardText.setString("Claimed Santa Grenade");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "rizzmas" && claimSantaGrenade) {
							rewardText.setString("Already Claimed");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "freezenova" && !claimIceGrenade) {
							claimIceGrenade = true;
							rewardText.setString("Claimed Ice Grenade");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "freezenova" && claimIceGrenade) {
							rewardText.setString("Already Claimed");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "merrychristmas" && !claimGarlandGrenade) {
							claimGarlandGrenade = true;
							rewardText.setString("Claimed Garland Grenade");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "merrychristmas" && claimGarlandGrenade) {
							rewardText.setString("Already Claimed");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "santashelper" && !claimElfExplosion) {
							claimElfExplosion = true;
							rewardText.setString("Claimed Elf Explosion");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "santashelper" && claimElfExplosion) {
							rewardText.setString("Already Claimed");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "letitsnow" && !claimSnowExplosion) {
							claimSnowExplosion = true;
							rewardText.setString("Claimed Snow Explosion");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "letitsnow" && claimSnowExplosion) {
							rewardText.setString("Already Claimed");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "runrunrudolph" && !claimRudolphPlane) {
							claimRudolphPlane = true;
							rewardText.setString("Claimed Rudolph Plane");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "runrunrudolph" && claimRudolphPlane) {
							rewardText.setString("Already Claimed");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "santassleigh" && !claimSantasPlane) {
							claimSantasPlane = true;
							rewardText.setString("Claimed Santa's Plane");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "santassleigh" && claimSantasPlane) {
							rewardText.setString("Already Claimed");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "seasonsgreetings" && !claimTreePlane) {
							claimTreePlane = true;
							rewardText.setString("Claimed Tree Plane");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
						if (textBoxInput == "seasonsgreetings" && claimTreePlane) {
							rewardText.setString("Already Claimed");
							textBoxInput = "";
							textboxText.setString(textBoxInput);
						}
					}
				}
				if (leaderboard) {
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(resetDataButton.getGlobalBounds())) {
						resetting = true;
						select.play();
					}
					if (Keyboard::isKeyPressed(Keyboard::Escape)) {
						leaderboard = false;
						titleText.setString("");
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(backButton.getGlobalBounds())) {
						leaderboard = false;
						exitable = false;
						titleText.setString("");
						select.play();
					}
				}
				if (credit) {
					if (Keyboard::isKeyPressed(Keyboard::Escape)) {
						creditsMusic.stop();
						titleText.setString("");
						credit = false;
						menuMusic.play();
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(backButton.getGlobalBounds())) {
						creditsMusic.stop();
						titleText.setString("");
						credit = false;
						exitable = false;
						menuMusic.play();
						select.play();
					}
				}
				if (setting) {
					if (!unlimitedFPS && !vsync) {
						if (event.type == Event::TextEntered) {
							if (Keyboard::isKeyPressed(Keyboard::Num0)) {
								frameBoxInput += "0";
							}
							if (Keyboard::isKeyPressed(Keyboard::Num1)) {
								frameBoxInput += "1";
							}
							if (Keyboard::isKeyPressed(Keyboard::Num2)) {
								frameBoxInput += "2";
							}
							if (Keyboard::isKeyPressed(Keyboard::Num3)) {
								frameBoxInput += "3";
							}
							if (Keyboard::isKeyPressed(Keyboard::Num4)) {
								frameBoxInput += "4";
							}
							if (Keyboard::isKeyPressed(Keyboard::Num5)) {
								frameBoxInput += "5";
							}
							if (Keyboard::isKeyPressed(Keyboard::Num6)) {
								frameBoxInput += "6";
							}
							if (Keyboard::isKeyPressed(Keyboard::Num7)) {
								frameBoxInput += "7";
							}
							if (Keyboard::isKeyPressed(Keyboard::Num8)) {
								frameBoxInput += "8";
							}
							if (Keyboard::isKeyPressed(Keyboard::Num9)) {
								frameBoxInput += "9";
							}
						}
						if (Keyboard::isKeyPressed(Keyboard::Return)) {
							if (!frameBoxInput.isEmpty()) {
								if (stoi(frameBoxInput.toAnsiString()) > 9999) {
									frameBoxInput = "9999";
								}
							}
							if (!frameBoxInput.isEmpty()) {
								if (stoi(frameBoxInput.toAnsiString()) < 30) {
									frameBoxInput = "30";
								}
							}
							checkFrames = true;
						}
					}
					if (Keyboard::isKeyPressed(Keyboard::Backspace) && !frameBoxInput.isEmpty()) {
						if (backspaceTimer.getElapsedTime() >= backspaceDelay) {
							frameBoxInput.erase(frameBoxInput.getSize() - 1);
							backspaceTimer.restart();
						}
					}
					frameBoxText.setString(frameBoxInput);
					if (Keyboard::isKeyPressed(Keyboard::Escape)) {
						leaderboard = false;
						titleText.setString("");
						setting = false;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(backButton.getGlobalBounds())) {
						leaderboard = false;
						titleText.setString("");
						setting = false;
						exitable = false;
						select.play();
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(audioButton.getGlobalBounds())) {
						audio = true;
						display = false;
						select.play();
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(displayButton.getGlobalBounds())) {
						audio = false;
						display = true;
						select.play();
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(scanlinesBox.getGlobalBounds())) {
						scanlines = !scanlines;
						select.play();
					}
					/*if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(fullscreenBox.getGlobalBounds())) {
						fullscreen = !fullscreen;
						checkFullscreen = true;
						select.play();
					}*/
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(vsyncBox.getGlobalBounds())) {
						if (unlimitedFPS) {
							unlimitedFPS = false;
							checkFrames = true;
						}
						vsync = !vsync;
						checkVsync = true;
						select.play();
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(unlimitedBox.getGlobalBounds())) {
						if (vsync) {
							vsync = false;
							checkVsync = true;
						}
						unlimitedFPS = !unlimitedFPS;
						checkFrames = true;
						select.play();
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(fontBox.getGlobalBounds())) {
						altFont = !altFont;
						select.play();
					}
					if (audio) {
						if (event.type == Event::MouseButtonPressed && mouseHitbox.getGlobalBounds().intersects(bar.getGlobalBounds())) {
							slidable = true;
						}
						if (event.type == Event::MouseButtonPressed && mouseHitbox.getGlobalBounds().intersects(bar2.getGlobalBounds())) {
							slidable2 = true;
						}
					}
					if (display) {
						if (event.type == Event::MouseButtonPressed && mouseHitbox.getGlobalBounds().intersects(bar3.getGlobalBounds())) {
							slidable3 = true;
						}
						if (event.type == Event::MouseButtonPressed && mouseHitbox.getGlobalBounds().intersects(bar4.getGlobalBounds())) {
							slidable4 = true;
						}
					}
					if (Event::MouseButtonPressed && mPosX >= 760.f && mPosX <= 1160.f && slidable) {
						dot.setPosition(mPosX, 360.f);
					}
					if (Event::MouseButtonPressed && mPosX >= 760.f && mPosX <= 1160.f && slidable2) {
						dot2.setPosition(mPosX, 720.f);
					}
					if (Event::MouseButtonPressed && mPosX >= 760.f && mPosX <= 1160.f && slidable3) {
						dot3.setPosition(mPosX, 360.f);
					}
					if (Event::MouseButtonPressed && mPosX >= 760.f && mPosX <= 1160.f && slidable4) {
						dot4.setPosition(mPosX, 720 - 150.0f);
					}
					if (event.type == Event::MouseButtonReleased && (slidable || slidable2 || slidable3 || slidable4)) {
						select.play();
					}
					if (event.type == Event::MouseButtonReleased) {
						slidable = false;
						slidable2 = false;
						slidable3 = false;
						slidable4 = false;
					}
				}
			}
			if (event.type == Event::KeyReleased) {
				if (event.key.scancode == Keyboard::Scan::Escape) {
					exitable = true;
				}
			}
			if (!menu && versus) {
				// Player Rotation
				if (Keyboard::isKeyPressed(Keyboard::A)) {
					MP1rotateLeft = true;
					MP1rotateRight = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::D)) {
					MP1rotateLeft = false;
					MP1rotateRight = true;
				}
				if (Keyboard::isKeyPressed(Keyboard::W) && !MP1shoot) {
					MP1shoot = true;
					MP1bombRotation = MP1bomb.getRotation();
					if (MP1shots == 14 && MP1bombShoot) {
						appear.play();
					}
					shootSound.play();
					if (MP1bombShoot) {
						MP1shots++;
					}
				}
				if (Keyboard::isKeyPressed(Keyboard::Left)) {
					MP2rotateLeft = true;
					MP2rotateRight = false;
				}
				if (Keyboard::isKeyPressed(Keyboard::Right)) {
					MP2rotateLeft = false;
					MP2rotateRight = true;
				}
				if (Keyboard::isKeyPressed(Keyboard::Up) && !MP2shoot) {
					MP2shoot = true;
					MP2bombRotation = MP2bomb.getRotation();
					if (MP2shots == 14 && MP2bombShoot) {
						appear.play();
					}
					shootSound.play();
					if (MP2bombShoot) {
						MP2shots++;
					}
				}
				if (event.type == Event::KeyReleased) {
					if (event.key.scancode == Keyboard::Scan::A) {
						MP1rotateLeft = false;
					}
					if (event.key.scancode == Keyboard::Scan::D) {
						MP1rotateRight = false;
					}
					if (event.key.scancode == Keyboard::Scan::Left) {
						MP2rotateLeft = false;
					}
					if (event.key.scancode == Keyboard::Scan::Right) {
						MP2rotateRight = false;
					}
				}
			}
		}
		if (leaderboard || seasonalShop || shop || skins || setting || credit || vault || lobby) {
			backButton.setTexture(backButtonTexture);
		}
		else {
			backButton.setTexture(exitWindowButtonTexture);
		}
		if (pause) {
			window.setMouseCursorVisible(true);
			returnButton.setPosition(960.f, 440.f);
			exitButton.setPosition(960.f, 640.f);
			if (mouseHitbox.getGlobalBounds().intersects(exitButton.getGlobalBounds())) {
				exitButton.setScale(3.2f, 3.2f);
				if (hoverable1) {
					hoverable1 = false;
				}
			}
			else {
				exitButton.setScale(3.f, 3.f);
				hoverable1 = true;
			}
			if (mouseHitbox.getGlobalBounds().intersects(returnButton.getGlobalBounds())) {
				returnButton.setScale(3.2f, 3.2f);
				if (hoverable2) {
					hoverable2 = false;
				}
			}
			else {
				returnButton.setScale(3.f, 3.f);
				hoverable2 = true;
			}
			if (mouseHitbox.getGlobalBounds().intersects(saveButton.getGlobalBounds())) {
				saveButton.setScale(3.2f, 3.2f);
				if (hoverable3) {
					hoverable3 = false;
				}
			}
			else {
				saveButton.setScale(3.f, 3.f);
				hoverable3 = true;
			}
			FloatRect pauseRect = pauseText.getLocalBounds();
			pauseText.setOrigin(pauseRect.left + pauseRect.width / 2.f, pauseRect.top + pauseRect.height / 2.f);
			pauseText.setPosition(Vector2f(960.f, 200.f));
			pauseText.setString("PAUSED");
		}
		if (menu) {
			window.setMouseCursorVisible(true);
			FloatRect versionRect = versionText.getLocalBounds();
			versionText.setOrigin(versionRect.left + versionRect.width / 2.f, versionRect.top + versionRect.height / 2.f);
			versionText.setPosition(Vector2f(1850, 1050));
			versionText.setString("v1.41");
			FloatRect MPWarningRect = MPWarningText.getLocalBounds();
			MPWarningText.setOrigin(MPWarningRect.left + MPWarningRect.width / 2.f, MPWarningRect.top + MPWarningRect.height / 2.f);
			MPWarningText.setPosition(Vector2f(960, 400));
			FloatRect devRect = devText.getLocalBounds();
			devText.setOrigin(devRect.left + devRect.width / 2.f, devRect.top + devRect.height / 2.f);
			devText.setPosition(Vector2f(960, 870));
			devText.setString("A Game by Logical7787");
			FloatRect FPSRect = FPSText.getLocalBounds();
			FPSText.setOrigin(FPSRect.left, FPSRect.top);
			FPSText.setPosition(Vector2f(0, 0));
			if (!altFont) {
				MPWarningText.setString("                Warning:\nMultiplayer is an\nexperimental feature\nthat may contain\nbugs.");
			} else {
				MPWarningText.setString("         Warning:\nMultiplayer is an\nexperimental feature\nthat may contain\nbugs.");
			}
			FloatRect MPWarningBoxRect = MPWarningBoxText.getLocalBounds();
			MPWarningBoxText.setOrigin(MPWarningBoxRect.left + MPWarningBoxRect.width / 2.f, MPWarningBoxRect.top + MPWarningBoxRect.height / 2.f);
			MPWarningBoxText.setPosition(Vector2f(1040, 640));
			MPWarningBoxText.setString("Don't show again");
			FloatRect steamRect = steamText.getLocalBounds();
			steamText.setOrigin(steamRect.left + steamRect.width / 2.f, steamRect.top + steamRect.height / 2.f);
			steamText.setPosition(Vector2f(1608.0f, 640.0f));
			steamText.setString("");
			if (eventActive) {
				if (!altFont) {
					returnButton.setTexture(claimButtonTexture);
				} else {
					returnButton.setTexture(claimButtonAltTexture);
				}
			}
			if (stretching) {
				cannoneer.setScale(logoScale, logoScale);
				logoScale += 0.0005f * (60 / framerate);
				if (logoScale >= 1.2f) {
					shrinking = true;
					stretching = false;
				}
			}
			if (shrinking) {
				cannoneer.setScale(logoScale, logoScale);
				logoScale -= 0.0005f * (60 / framerate);
				if (logoScale <= 0.9f) {
					shrinking = false;
					stretching = true;
				}
			}
			if (rotatingRight) {
				cannoneer.setRotation(logoRotation);
				logoRotation += 0.02f * (60 / framerate);
				if (logoRotation >= 10) {
					rotatingLeft = true;
					rotatingRight = false;
				}
			}
			if (rotatingLeft) {
				cannoneer.setRotation(logoRotation);
				logoRotation -= 0.02f * (60 / framerate);
				if (logoRotation <= -10) {
					rotatingLeft = false;
					rotatingRight = true;
				}
			}
			if (exiting) {
				FloatRect pauseRect = pauseText.getLocalBounds();
				pauseText.setOrigin(pauseRect.left + pauseRect.width / 2.f, pauseRect.top + pauseRect.height / 2.f);
				pauseText.setPosition(Vector2f(960.f, 200.f));
				pauseText.setString("Exit?");
				returnButton.setPosition(960.f, 880.f);
				if (!altFont) {
					returnButton.setTexture(returnButtonTexture);
				} else {
					returnButton.setTexture(returnButtonAltTexture);
				}
				if (!altFont) {
					exitButton.setTexture(exitButtonTexture);
				} else {
					exitButton.setTexture(exitButtonAltTexture);
				}
				exitButton.setPosition(960.f, 440.f);
				if (mouseHitbox.getGlobalBounds().intersects(exitButton.getGlobalBounds())) {
					exitButton.setScale(3.2f, 3.2f);
					if (hoverable1) {
						hoverable1 = false;
					}
				}
				else {
					exitButton.setScale(3.f, 3.f);
					hoverable1 = true;
				}
				if (mouseHitbox.getGlobalBounds().intersects(returnButton.getGlobalBounds())) {
					returnButton.setScale(3.2f, 3.2f);
					if (hoverable2) {
						hoverable2 = false;
					}
				}
				else {
					returnButton.setScale(3.f, 3.f);
					hoverable2 = true;
				}
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(exitButton.getGlobalBounds())) {
					saveOther();
					saveSkins();
					saveSettings();
					SteamAPI_Shutdown();
					window.close();
					return 0;
				}
				if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(returnButton.getGlobalBounds())) {
					exiting = false;
					select.play();
				}
			}
			if (time(NULL) >= 1734411600 && time(NULL) <= 1735362000 && !day1Claimed) {
				eventActive = true;
			}
			if (time(NULL) >= 1734498000 && time(NULL) <= 1734584399 && !day2Claimed) {
				eventActive = true;
			}
			if (time(NULL) >= 1734584400 && time(NULL) <= 1734670799 && !day3Claimed) {
				eventActive = true;
			}
			if (time(NULL) >= 1734670800 && time(NULL) <= 1734757199 && !day4Claimed) {
				eventActive = true;
			}
			if (time(NULL) >= 1734757200 && time(NULL) <= 1734843599 && !day5Claimed) {
				eventActive = true;
			}
			if (time(NULL) >= 1734843600 && time(NULL) <= 1734929999 && !day6Claimed) {
				eventActive = true;
			}
			if (time(NULL) >= 1734930000 && time(NULL) <= 1735016399 && !day7Claimed) {
				eventActive = true;
			}
			if (time(NULL) >= 1735016400 && time(NULL) <= 1735102799 && !day8Claimed) {
				eventActive = true;
			}
			if (time(NULL) >= 1735102800 && time(NULL) <= 1735189199 && !day9Claimed) {
				eventActive = true;
			}
			if (time(NULL) >= 1735189200 && time(NULL) <= 1735275599 && !day10Claimed) {
				eventActive = true;
			}
			if (time(NULL) >= 1735275600 && time(NULL) <= 1735361999 && !day11Claimed) {
				eventActive = true;
			}
			if (time(NULL) >= 1735362000 && time(NULL) <= 1735448399 && !day12Claimed) {
				eventActive = true;
			}
			if (!eventActive) {
				if (cannonSkin) {
					if (equippedCannon == 0) {
						eventPlayerModel.setTexture(playerTexture);
						selected.setPosition(icon1.getPosition());
					}
					if (equippedCannon == 1) {
						eventPlayerModel.setTexture(christmasCannonTexture);
						selected.setPosition(icon2.getPosition());
					}
					if (equippedCannon == 2) {
						eventPlayerModel.setTexture(fireCannonTexture);
						selected.setPosition(icon3.getPosition());
					}
					if (equippedCannon == 3) {
						eventPlayerModel.setTexture(yippeeCannonTexture);
						selected.setPosition(icon4.getPosition());
					}
					if (equippedCannon == 4) {
						eventPlayerModel.setTexture(goldenCannonTexture);
						selected.setPosition(icon5.getPosition());
					}
					if (equippedCannon == 5) {
						eventPlayerModel.setTexture(logicalCannonTexture);
						selected.setPosition(icon6.getPosition());
					}
					if (equippedCannon == 6) {
						eventPlayerModel.setTexture(peashooterCannonTexture);
						selected.setPosition(icon7.getPosition());
					}
					if (equippedCannon == 7) {
						eventPlayerModel.setTexture(sugarCannonTexture);
						selected.setPosition(icon8.getPosition());
					}
					if (equippedCannon == 8) {
						eventPlayerModel.setTexture(flameCannonTexture);
						selected.setPosition(icon21.getPosition());
					}
					if (equippedCannon == 9) {
						eventPlayerModel.setTexture(gingerbreadCannonTexture);
						selected.setPosition(icon38.getPosition());
					}
					if (equippedCannon == 10) {
						eventPlayerModel.setTexture(snowmanCannonTexture);
						selected.setPosition(icon39.getPosition());
					}
					if (equippedCannon == 11) {
						eventPlayerModel.setTexture(presentCannonTexture);
						selected.setPosition(icon40.getPosition());
					}
					if (equippedCannon == 12) {
						eventPlayerModel.setTexture(deadpoolCannonTexture);
						selected.setPosition(icon47.getPosition());
					}
					if (equippedCannon == 13) {
						eventPlayerModel.setTexture(shockCannonTexture);
						selected.setPosition(icon48.getPosition());
					}
					if (equippedCannon == 14) {
						eventPlayerModel.setTexture(birdoCannonTexture);
						selected.setPosition(icon49.getPosition());
					}
					if (equippedCannon == 15) {
						eventPlayerModel.setTexture(heartsCannonTexture);
						selected.setPosition(icon50.getPosition());
					}
					if (equippedCannon == 16) {
						eventPlayerModel.setTexture(apocCannonTexture);
						selected.setPosition(icon62.getPosition());
					}
				}
				if (bombSkin) {
					if (equippedBomb == 0) {
						eventBombModel.setTexture(bombTexture);
						selected.setPosition(icon1.getPosition());
					}
					if (equippedBomb == 1) {
						eventBombModel.setTexture(fireBombTexture);
						selected.setPosition(icon2.getPosition());
					}
					if (equippedBomb == 2) {
						eventBombModel.setTexture(icyBombTexture);
						selected.setPosition(icon3.getPosition());
					}
					if (equippedBomb == 3) {
						eventBombModel.setTexture(orangeBombTexture);
						selected.setPosition(icon4.getPosition());
					}
					if (equippedBomb == 4) {
						eventBombModel.setTexture(peppermintBombTexture);
						selected.setPosition(icon5.getPosition());
					}
					if (equippedBomb == 5) {
						eventBombModel.setTexture(yippeeBombTexture);
						selected.setPosition(icon6.getPosition());
					}
					if (equippedBomb == 6) {
						eventBombModel.setTexture(santasBombTexture);
						selected.setPosition(icon41.getPosition());
					}
					if (equippedBomb == 7) {
						eventBombModel.setTexture(bellBombTexture);
						selected.setPosition(icon42.getPosition());
					}
					if (equippedBomb == 8) {
						eventBombModel.setTexture(yoshiBombTexture);
						selected.setPosition(icon51.getPosition());
					}
					if (equippedBomb == 9) {
						eventBombModel.setTexture(birdoBombTexture);
						selected.setPosition(icon52.getPosition());
					}
					if (equippedBomb == 10) {
						eventBombModel.setTexture(logicalBombTexture);
						selected.setPosition(icon57.getPosition());
					}
					if (equippedBomb == 11) {
						eventBombModel.setTexture(apocBombTexture);
						selected.setPosition(icon63.getPosition());
					}
				}
					if (equippedCannon == 7) {
						eventPlayerModel.setTexture(sugarCannonTexture);
						selected.setPosition(icon8.getPosition());
					}
					if (equippedCannon == 8) {
						eventPlayerModel.setTexture(flameCannonTexture);
						selected.setPosition(icon21.getPosition());
					}
					if (equippedCannon == 9) {
						eventPlayerModel.setTexture(gingerbreadCannonTexture);
						selected.setPosition(icon38.getPosition());
					}
					if (equippedCannon == 10) {
						eventPlayerModel.setTexture(snowmanCannonTexture);
						selected.setPosition(icon39.getPosition());
					}
					if (equippedCannon == 11) {
				}
				if (grenadeSkin) {
					if (equippedGrenade == 0) {
						eventGrenadeModel.setTexture(grenadeTexture);
						selected.setPosition(icon22.getPosition());
					}
					if (equippedGrenade == 1) {
						eventGrenadeModel.setTexture(fireGrenadeTexture);
						selected.setPosition(icon23.getPosition());
					}
					if (equippedGrenade == 2) {
						eventGrenadeModel.setTexture(yippeeGrenadeTexture);
						selected.setPosition(icon24.getPosition());
					}
					if (equippedGrenade == 3) {
						eventGrenadeModel.setTexture(logicalGrenadeTexture);
						selected.setPosition(icon25.getPosition());
					}
					if (equippedGrenade == 4) {
						eventGrenadeModel.setTexture(chocolateGrenadeTexture);
						selected.setPosition(icon26.getPosition());
					}
					if (equippedGrenade == 5) {
						eventGrenadeModel.setTexture(christmasGrenadeTexture);
						selected.setPosition(icon15.getPosition());
					}
					if (equippedGrenade == 6) {
						eventGrenadeModel.setTexture(garlandGrenadeTexture);
						selected.setPosition(icon16.getPosition());
					}
					if (equippedGrenade == 7) {
						eventGrenadeModel.setTexture(iceGrenadeTexture);
						selected.setPosition(icon17.getPosition());
					}
					if (equippedGrenade == 8) {
						eventGrenadeModel.setTexture(santaGrenadeTexture);
						selected.setPosition(icon18.getPosition());
					}
					if (equippedGrenade == 9) {
						eventGrenadeModel.setTexture(dynamiteGrenadeTexture);
						selected.setPosition(icon53.getPosition());
					}
					if (equippedGrenade == 10) {
						eventGrenadeModel.setTexture(nukeGrenadeTexture);
						selected.setPosition(icon54.getPosition());
					}
					if (equippedGrenade == 11) {
						eventGrenadeModel.setTexture(smokeGrenadeTexture);
						selected.setPosition(icon55.getPosition());
					}
					if (equippedGrenade == 12) {
						eventGrenadeModel.setTexture(holyHandGrenadeTexture);
						selected.setPosition(icon56.getPosition());
					}
					if (equippedGrenade == 13) {
						eventGrenadeModel.setTexture(apocGrenadeTexture);
						selected.setPosition(icon64.getPosition());
					}
				}
				if (explosionSkin) {
					if (equippedExplosion == 0) {
						eventExplosionModel.setTexture(explosionTexture);
						selected.setPosition(icon27.getPosition());
					}
					if (equippedExplosion == 1) {
						eventExplosionModel.setTexture(yippeeExplosionTexture);
						selected.setPosition(icon28.getPosition());
					}
					if (equippedExplosion == 2) {
						eventExplosionModel.setTexture(festiveExplosionTexture);
						selected.setPosition(icon29.getPosition());
					}
					if (equippedExplosion == 3) {
						eventExplosionModel.setTexture(snowyExplosionTexture);
						selected.setPosition(icon30.getPosition());
					}
					if (equippedExplosion == 4) {
						eventExplosionModel.setTexture(gingerbreadExplosionTexture);
						selected.setPosition(icon31.getPosition());
					}
					if (equippedExplosion == 5) {
						eventExplosionModel.setTexture(elfExplosionTexture);
						selected.setPosition(icon19.getPosition());
					}
					if (equippedExplosion == 6) {
						eventExplosionModel.setTexture(snowExplosionTexture);
						selected.setPosition(icon43.getPosition());
					}
					if (equippedExplosion == 7) {
						eventExplosionModel.setTexture(logicalExplosionTexture);
						selected.setPosition(icon58.getPosition());
					}
					if (equippedExplosion == 8) {
						eventExplosionModel.setTexture(mushroomExplosionTexture);
						selected.setPosition(icon59.getPosition());
					}
					if (equippedExplosion == 9) {
						eventExplosionModel.setTexture(smokeExplosionTexture);
						selected.setPosition(icon60.getPosition());
					}
					if (equippedExplosion == 10) {
						eventExplosionModel.setTexture(apocExplosionTexture);
						selected.setPosition(icon65.getPosition());
					}
				}
				if (planeSkin) {
					if (equippedPlane == 0) {
						eventPlaneModel.setTexture(planeTexture);
						selected.setPosition(icon32.getPosition());
					}
					if (equippedPlane == 1) {
						eventPlaneModel.setTexture(yippeePlaneTexture);
						selected.setPosition(icon33.getPosition());
					}
					if (equippedPlane == 2) {
						eventPlaneModel.setTexture(firePlaneTexture);
						selected.setPosition(icon34.getPosition());
					}
					if (equippedPlane == 3) {
						eventPlaneModel.setTexture(logicalPlaneTexture);
						selected.setPosition(icon35.getPosition());
					}
					if (equippedPlane == 4) {
						eventPlaneModel.setTexture(festivePlaneTexture);
						selected.setPosition(icon36.getPosition());
					}
					if (equippedPlane == 5) {
						eventPlaneModel.setTexture(cookiePlaneTexture);
						selected.setPosition(icon37.getPosition());
					}
					if (equippedPlane == 6) {
						eventPlaneModel.setTexture(rudolphPlaneTexture);
						selected.setPosition(icon44.getPosition());
					}
					if (equippedPlane == 7) {
						eventPlaneModel.setTexture(santasPlaneTexture);
						selected.setPosition(icon45.getPosition());
					}
					if (equippedPlane == 8) {
						eventPlaneModel.setTexture(treePlaneTexture);
						selected.setPosition(icon46.getPosition());
					}
					if (equippedPlane == 9) {
						eventPlaneModel.setTexture(fighterPlaneTexture);
						selected.setPosition(icon61.getPosition());
					}
					if (equippedPlane == 10) {
						eventPlaneModel.setTexture(apocPlaneTexture);
						selected.setPosition(icon66.getPosition());
					}
				}
			}
			if (equippedCannon == 0) {
				player.setTexture(playerTexture);
			}
			if (equippedCannon == 1) {
				player.setTexture(christmasCannonTexture);
			}
			if (equippedCannon == 2) {
				player.setTexture(fireCannonTexture);
			}
			if (equippedCannon == 3) {
				player.setTexture(yippeeCannonTexture);
			}
			if (equippedCannon == 4) {
				player.setTexture(goldenCannonTexture);
			}
			if (equippedCannon == 5) {
				player.setTexture(logicalCannonTexture);
			}
			if (equippedCannon == 6) {
				player.setTexture(peashooterCannonTexture);
			}
			if (equippedCannon == 7) {
				player.setTexture(sugarCannonTexture);
			}
			if (equippedCannon == 8) {
				player.setTexture(flameCannonTexture);
			}
			if (equippedCannon == 9) {
				player.setTexture(gingerbreadCannonTexture);
			}
			if (equippedCannon == 10) {
				player.setTexture(snowmanCannonTexture);
			}
			if (equippedCannon == 11) {
				player.setTexture(presentCannonTexture);
			}
			if (equippedCannon == 12) {
				player.setTexture(deadpoolCannonTexture);
			}
			if (equippedCannon == 13) {
				player.setTexture(shockCannonTexture);
			}
			if (equippedCannon == 14) {
				player.setTexture(birdoCannonTexture);
			}
			if (equippedCannon == 15) {
				player.setTexture(heartsCannonTexture);
			}
			if (equippedCannon == 16) {
				player.setTexture(apocCannonTexture);
			}
			if (equippedBomb == 0) {
				bomb.setTexture(bombTexture);
			}
			if (equippedBomb == 1) {
				bomb.setTexture(fireBombTexture);
			}
			if (equippedBomb == 2) {
				bomb.setTexture(icyBombTexture);
			}
			if (equippedBomb == 3) {
				bomb.setTexture(orangeBombTexture);
			}
			if (equippedBomb == 4) {
				bomb.setTexture(peppermintBombTexture);
			}
			if (equippedBomb == 5) {
				bomb.setTexture(yippeeBombTexture);
			}
			if (equippedBomb == 6) {
				bomb.setTexture(santasBombTexture);
			}
			if (equippedBomb == 7) {
				bomb.setTexture(bellBombTexture);
			}
			if (equippedBomb == 8) {
				bomb.setTexture(yoshiBombTexture);
			}
			if (equippedBomb == 9) {
				bomb.setTexture(birdoBombTexture);
			}
			if (equippedBomb == 10) {
				bomb.setTexture(logicalBombTexture);
			}
			if (equippedBomb == 11) {
				bomb.setTexture(apocBombTexture);
			}
			if (equippedGrenade == 0) {
				grenade.setTexture(grenadeTexture);
			}
			if (equippedGrenade == 1) {
				grenade.setTexture(fireGrenadeTexture);
			}
			if (equippedGrenade == 2) {
				grenade.setTexture(yippeeGrenadeTexture);
			}
			if (equippedGrenade == 3) {
				grenade.setTexture(logicalGrenadeTexture);
			}
			if (equippedGrenade == 4) {
				grenade.setTexture(chocolateGrenadeTexture);
			}
			if (equippedGrenade == 5) {
				grenade.setTexture(christmasGrenadeTexture);
			}
			if (equippedGrenade == 6) {
				grenade.setTexture(garlandGrenadeTexture);
			}
			if (equippedGrenade == 7) {
				grenade.setTexture(iceGrenadeTexture);
			}
			if (equippedGrenade == 8) {
				grenade.setTexture(santaGrenadeTexture);
			}
			if (equippedGrenade == 9) {
				grenade.setTexture(dynamiteGrenadeTexture);
			}
			if (equippedGrenade == 10) {
				grenade.setTexture(nukeGrenadeTexture);
			}
			if (equippedGrenade == 11) {
				grenade.setTexture(smokeGrenadeTexture);
			}
			if (equippedGrenade == 12) {
				grenade.setTexture(holyHandGrenadeTexture);
			}
			if (equippedGrenade == 13) {
				grenade.setTexture(apocGrenadeTexture);
			}
			if (equippedExplosion == 0) {
				explosion.setTexture(explosionTexture);
			}
			if (equippedExplosion == 1) {
				explosion.setTexture(yippeeExplosionTexture);
			}
			if (equippedExplosion == 2) {
				explosion.setTexture(festiveExplosionTexture);
			}
			if (equippedExplosion == 3) {
				explosion.setTexture(snowyExplosionTexture);
			}
			if (equippedExplosion == 4) {
				explosion.setTexture(gingerbreadExplosionTexture);
			}
			if (equippedExplosion == 5) {
				explosion.setTexture(elfExplosionTexture);
			}
			if (equippedExplosion == 6) {
				explosion.setTexture(snowExplosionTexture);
			}
			if (equippedExplosion == 7) {
				explosion.setTexture(logicalExplosionTexture);
			}
			if (equippedExplosion == 8) {
				explosion.setTexture(mushroomExplosionTexture);
			}
			if (equippedExplosion == 9) {
				explosion.setTexture(smokeExplosionTexture);
			}
			if (equippedExplosion == 10) {
				explosion.setTexture(apocExplosionTexture);
			}
			if (equippedPlane == 0) {
				plane1.setTexture(planeTexture);
				plane2.setTexture(planeTexture);
				plane3.setTexture(planeTexture);
				plane4.setTexture(planeTexture);
				plane5.setTexture(planeTexture);
				plane6.setTexture(planeTexture);
			}
			if (equippedPlane == 1) {
				plane1.setTexture(yippeePlaneTexture);
				plane2.setTexture(yippeePlaneTexture);
				plane3.setTexture(yippeePlaneTexture);
				plane4.setTexture(yippeePlaneTexture);
				plane5.setTexture(yippeePlaneTexture);
				plane6.setTexture(yippeePlaneTexture);
			}
			if (equippedPlane == 2) {
				plane1.setTexture(firePlaneTexture);
				plane2.setTexture(firePlaneTexture);
				plane3.setTexture(firePlaneTexture);
				plane4.setTexture(firePlaneTexture);
				plane5.setTexture(firePlaneTexture);
				plane6.setTexture(firePlaneTexture);
			}
			if (equippedPlane == 3) {
				plane1.setTexture(logicalPlaneTexture);
				plane2.setTexture(logicalPlaneTexture);
				plane3.setTexture(logicalPlaneTexture);
				plane4.setTexture(logicalPlaneTexture);
				plane5.setTexture(logicalPlaneTexture);
				plane6.setTexture(logicalPlaneTexture);
			}
			if (equippedPlane == 4) {
				plane1.setTexture(festivePlaneTexture);
				plane2.setTexture(festivePlaneTexture);
				plane3.setTexture(festivePlaneTexture);
				plane4.setTexture(festivePlaneTexture);
				plane5.setTexture(festivePlaneTexture);
				plane6.setTexture(festivePlaneTexture);
			}
			if (equippedPlane == 5) {
				plane1.setTexture(cookiePlaneTexture);
				plane2.setTexture(cookiePlaneTexture);
				plane3.setTexture(cookiePlaneTexture);
				plane4.setTexture(cookiePlaneTexture);
				plane5.setTexture(cookiePlaneTexture);
				plane6.setTexture(cookiePlaneTexture);
			}
			if (equippedPlane == 6) {
				plane1.setTexture(rudolphPlaneTexture);
				plane2.setTexture(rudolphPlaneTexture);
				plane3.setTexture(rudolphPlaneTexture);
				plane4.setTexture(rudolphPlaneTexture);
				plane5.setTexture(rudolphPlaneTexture);
				plane6.setTexture(rudolphPlaneTexture);
			}
			if (equippedPlane == 7) {
				plane1.setTexture(santasPlaneTexture);
				plane2.setTexture(santasPlaneTexture);
				plane3.setTexture(santasPlaneTexture);
				plane4.setTexture(santasPlaneTexture);
				plane5.setTexture(santasPlaneTexture);
				plane6.setTexture(santasPlaneTexture);
			}
			if (equippedPlane == 8) {
				plane1.setTexture(treePlaneTexture);
				plane2.setTexture(treePlaneTexture);
				plane3.setTexture(treePlaneTexture);
				plane4.setTexture(treePlaneTexture);
				plane5.setTexture(treePlaneTexture);
				plane6.setTexture(treePlaneTexture);
			}
			if (equippedPlane == 9) {
				plane1.setTexture(fighterPlaneTexture);
				plane2.setTexture(fighterPlaneTexture);
				plane3.setTexture(fighterPlaneTexture);
				plane4.setTexture(fighterPlaneTexture);
				plane5.setTexture(fighterPlaneTexture);
				plane6.setTexture(fighterPlaneTexture);
			}
			if (equippedPlane == 10) {
				plane1.setTexture(apocPlaneTexture);
				plane2.setTexture(apocPlaneTexture);
				plane3.setTexture(apocPlaneTexture);
				plane4.setTexture(apocPlaneTexture);
				plane5.setTexture(apocPlaneTexture);
				plane6.setTexture(apocPlaneTexture);
			}
			if (skins) {
				if (mouseHitbox.getGlobalBounds().intersects(leftArrow.getGlobalBounds())) {
					leftArrow.setScale(4.3f, 4.3f);
					if (hoverable30) {
						hoverable30 = false;
					}
				}
				else {
					leftArrow.setScale(4.f, 4.f);
					hoverable30 = true;
				}
				if (mouseHitbox.getGlobalBounds().intersects(rightArrow.getGlobalBounds())) {
					rightArrow.setScale(4.3f, 4.3f);
					if (hoverable31) {
						hoverable31 = false;
					}
				}
				else {
					rightArrow.setScale(4.f, 4.f);
					hoverable31 = true;
				}
			}
			if (eventActive) {
				if (!altFont) {
					returnButton.setTexture(claimButtonTexture);
				}
				else {
					returnButton.setTexture(claimButtonAltTexture);
				}
				FloatRect pauseRect = pauseText.getLocalBounds();
				pauseText.setOrigin(pauseRect.left + pauseRect.width / 2.f, pauseRect.top + pauseRect.height / 2.f);
				pauseText.setPosition(Vector2f(960.f, 200.f));

				FloatRect eventRect = eventText.getLocalBounds();
				eventText.setOrigin(eventRect.left + eventRect.width / 2.f, eventRect.top + eventRect.height / 2.f);
				eventText.setPosition(Vector2f(960.f, 660.f));
				if (time(NULL) >= 1734411600 && time(NULL) <= 1735362000 && !day1Claimed) {
					pauseText.setString("Day 1");
					eventText.setString("Welcome to the 12 Days of\nChristmas! Login everyday to\nget a gift!");
					eventPlayerModel.setTexture(christmasCannonTexture);
				}
				if (time(NULL) >= 1734498000 && time(NULL) <= 1734584399 && !day2Claimed) {
					pauseText.setString("Day 2");
					eventText.setString("Day 2! The holidays are\ncoming soon!");
					eventPlaneModel.setTexture(festivePlaneTexture);
				}
				if (time(NULL) >= 1734584400 && time(NULL) <= 1734670799 && !day3Claimed) {
					pauseText.setString("Day 3");
					eventText.setString("It's getting cold outside.\nOh no! The bombs are freezing!");
					eventBombModel.setTexture(icyBombTexture);
				}
				if (time(NULL) >= 1734670800 && time(NULL) <= 1734757199 && !day4Claimed) {
					pauseText.setString("Day 4");
					eventText.setString("Remember to leave cookies\nfor Santa!");
					eventExplosionModel.setTexture(cookiePlaneTexture);
				}
				if (time(NULL) >= 1734757200 && time(NULL) <= 1734843599 && !day5Claimed) {
					pauseText.setString("Day 5");
					eventText.setString("On the Fifth Day of Christmas\nmy true love gave to me...\nA golden cannon!");
					eventPlayerModel.setTexture(goldenCannonTexture);
				}
				if (time(NULL) >= 1734843600 && time(NULL) <= 1734929999 && !day6Claimed) {
					pauseText.setString("Day 6");
					eventText.setString("Don't forget to open your\nadvent calendar too!");
					eventGrenadeModel.setTexture(chocolateGrenadeTexture);
				}
				if (time(NULL) >= 1734930000 && time(NULL) <= 1735016399 && !day7Claimed) {
					pauseText.setString("Day 7");
					eventText.setString("It's the Eve of Christmas\nEve!");
					eventBombModel.setTexture(peppermintBombTexture);
				}
				if (time(NULL) >= 1735016400 && time(NULL) <= 1735102799 && !day8Claimed) {
					pauseText.setString("Day 8");
					eventText.setString("Twas the Night Before\nChristmas...");
					eventPlaneModel.setTexture(festiveExplosionTexture);
				}
				if (time(NULL) >= 1735102800 && time(NULL) <= 1735189199 && !day9Claimed) {
					pauseText.setString("Day 9");
					eventText.setString("Thanks for playing\non Christmas! Enjoy this\nlimited time cannon!");
					eventExplosionModel.setTexture(logicalCannonTexture);
				}
				if (time(NULL) >= 1735189200 && time(NULL) <= 1735275599 && !day10Claimed) {
					pauseText.setString("Day 10");
					eventText.setString("Wait... Is that... Snow!?");
					eventExplosionModel.setTexture(snowyExplosionTexture);
				}
				if (time(NULL) >= 1735275600 && time(NULL) <= 1735361999 && !day11Claimed) {
					pauseText.setString("Day 11");
					eventText.setString("Here's a classic stocking\nstuffer!");
					eventBombModel.setTexture(orangeBombTexture);
				}
				if (time(NULL) >= 1735362000 && time(NULL) <= 1735448399 && !day12Claimed) {
					pauseText.setString("Day 12");
					eventText.setString("How was I supposed to know\nthe gingerbread house was\nan explosive!?");
					eventPlayerModel.setTexture(gingerbreadExplosionTexture);
				}
				returnButton.setPosition(960.f, 880.f);
				if (mouseHitbox.getGlobalBounds().intersects(returnButton.getGlobalBounds())) {
					returnButton.setScale(3.2f, 3.2f);
					if (hoverable2) {
						hoverable2 = false;
					}
				}
				else {
					returnButton.setScale(3.f, 3.f);
					hoverable2 = true;
				}
			}
			if (vault) {
				FloatRect textboxRect = textboxText.getLocalBounds();
				textboxText.setOrigin(textboxRect.left + textboxRect.width / 2.f, textboxRect.top + textboxRect.height / 2.f);
				textboxText.setPosition(Vector2f(960.0f, 750.0f));
				FloatRect rewardRect = rewardText.getLocalBounds();
				rewardText.setOrigin(rewardRect.left + rewardRect.width / 2.f, rewardRect.top + rewardRect.height / 2.f);
				rewardText.setPosition(Vector2f(960.0f, 850.0f));
				if (textboxText.getString() == "") {
					textbox.setSize(Vector2f(100, 40));
					textbox.setOrigin(50, 20);
				} else {
					textbox.setSize(Vector2f((textboxRect.getSize().x + 20) / 2, 40));
					textbox.setOrigin((textboxRect.getSize().x + 20) / 4, 20);
				}
			}
			FloatRect titleRect = titleText.getLocalBounds();
			titleText.setOrigin(titleRect.left + titleRect.width / 2, titleRect.top + titleRect.height / 2);
			titleText.setPosition(Vector2f(960.f, 100.f));
			if (!leaderboard && !seasonalShop && !shop && !credit && !setting && !skins && !exiting && !vault && !lobby) {
				titleText.setString("");
				if (mouseHitbox.getGlobalBounds().intersects(playButton.getGlobalBounds()) && !eventActive) {
					playButton.setScale(3.2, 3.2);
					if (hoverable4) {
						hoverable4 = false;
					}
				}
				else {
					playButton.setScale(3, 3);
					hoverable4 = true;
				}
				if (mouseHitbox.getGlobalBounds().intersects(leaderboardButton.getGlobalBounds()) && !eventActive) {
					leaderboardButton.setScale(3.2, 3.2);
					if (hoverable5) {
						hoverable5 = false;
					}
				}
				else {
					leaderboardButton.setScale(3, 3);
					hoverable5 = true;
				}
				if (mouseHitbox.getGlobalBounds().intersects(creditsButton.getGlobalBounds()) && !eventActive) {
					creditsButton.setScale(3.2, 3.2);
					if (hoverable6) {
						hoverable6 = false;
					}
				}
				else {
					creditsButton.setScale(3, 3);
					hoverable6 = true;
				}
				if (mouseHitbox.getGlobalBounds().intersects(settingsButton.getGlobalBounds()) && !eventActive) {
					settingsButton.setScale(3.2, 3.2);
					if (hoverable7) {
						hoverable7 = false;
					}
				}
				else {
					settingsButton.setScale(3, 3);
					hoverable7 = true;
				}
				if (mouseHitbox.getGlobalBounds().intersects(shopButton.getGlobalBounds()) && !eventActive) {
					shopButton.setScale(3.2, 3.2);
					if (hoverable8) {
						hoverable8 = false;
					}
				}
				else {
					shopButton.setScale(3, 3);
					hoverable8 = true;
				}
				if (mouseHitbox.getGlobalBounds().intersects(skinsButton.getGlobalBounds()) && !eventActive) {
					skinsButton.setScale(3.2, 3.2);
					if (hoverable18) {
						hoverable18 = false;
					}
				}
				else {
					skinsButton.setScale(3, 3);
					hoverable18 = true;
				}
				/*if (mouseHitbox.getGlobalBounds().intersects(versusButton.getGlobalBounds()) && !eventActive && s) {
					versusButton.setScale(3.2, 3.2);
					if (hoverable27) {
						hoverable27 = false;
					}
				}
				else {
					versusButton.setScale(3, 3);
					hoverable27 = true;
				}*/
			}
			if (leaderboard) {
				FloatRect scoreTitleRect = scoreTitleText.getLocalBounds();
				scoreTitleText.setOrigin(scoreTitleRect.left + scoreTitleRect.width / 2.f, scoreTitleRect.top + scoreTitleRect.height / 2.f);
				scoreTitleText.setPosition(Vector2f(480, 200));
				scoreTitleText.setString("High Scores");
				FloatRect waveTitleRect = waveTitleText.getLocalBounds();
				waveTitleText.setOrigin(waveTitleRect.left + waveTitleRect.width / 2.f, waveTitleRect.top + waveTitleRect.height / 2.f);
				waveTitleText.setPosition(Vector2f(1440, 200));
				waveTitleText.setString("High Waves");
				FloatRect scoreLeaderboardRect = scoreLeaderboardText.getLocalBounds();
				scoreLeaderboardText.setOrigin(scoreLeaderboardRect.left + scoreLeaderboardRect.width / 2.0f, 0);
				scoreLeaderboardText.setPosition(Vector2f(480, 300));
				scoreLeaderboardText.setString(leaderboardManager.storedLeaderboardTextScore);
				FloatRect waveLeaderboardRect = waveLeaderboardText.getLocalBounds();
				waveLeaderboardText.setOrigin(waveLeaderboardRect.left+ waveLeaderboardRect.width / 2.0f, 0);
				waveLeaderboardText.setPosition(Vector2f(1440, 300));
				waveLeaderboardText.setString(leaderboardManager.storedLeaderboardTextWave);
				if (resetting) {
					FloatRect pauseRect = pauseText.getLocalBounds();
					pauseText.setOrigin(pauseRect.left + pauseRect.width / 2.f, pauseRect.top + pauseRect.height / 2.f);
					pauseText.setPosition(Vector2f(960.f, 200.f));
					pauseText.setString("Are you sure?");
					if (!altFont) {
						returnButton.setTexture(returnButtonTexture);
						exitButton.setTexture(resetDataButtonTexture);
					}
					else {
						returnButton.setTexture(returnButtonAltTexture);
						exitButton.setTexture(resetDataButtonAltTexture);
					}
					returnButton.setPosition(960.f, 880.f);
					exitButton.setPosition(960.f, 440.f);
					if (mouseHitbox.getGlobalBounds().intersects(exitButton.getGlobalBounds())) {
						exitButton.setScale(3.2f, 3.2f);
						if (hoverable1) {
							hoverable1 = false;
						}
					}
					else {
						exitButton.setScale(3.f, 3.f);
						hoverable1 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(returnButton.getGlobalBounds())) {
						returnButton.setScale(3.2f, 3.2f);
						if (hoverable2) {
							hoverable2 = false;
						}
					}
					else {
						returnButton.setScale(3.f, 3.f);
						hoverable2 = true;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(exitButton.getGlobalBounds())) {
						select.play();
						musicVolume = 25;
						SFXVolume = 25;
						saturation = 1;
						contrast = 1;
						scanlines = 1;
						showMPWarning = 1;
						altFont = 0;
						dot.setPosition(760.f + (4.f * musicVolume), 360.f);
						dot2.setPosition(760.f + (4.f * SFXVolume), 720.f);
						dot3.setPosition(760.f + (200.f * saturation), 720 - 150.f);
						dot4.setPosition(760.f + (200.f * saturation), 360.f);
						highScore = 0;
						highWave = 0;
						treasure = 0;
						equippedCannon = 0;
						equippedBomb = 0;
						equippedGrenade = 0;
						equippedExplosion = 0;
						equippedPlane = 0;
						claimPeashooterCannon = 0;
						claimYippeeCannon = 0;
						claimSugarCannon = 0;
						claimFireCannon = 0;
						claimYippeeBomb = 0;
						claimFireBomb = 0;
						claimPeashooterCannon = 0;
						claimYippeeCannon = 0;
						claimSugarCannon = 0;
						claimFireCannon = 0;
						claimYippeeBomb = 0;
						claimFireBomb = 0;
						claimYoshiBomb = 0;
						claimBirdoBomb = 0;
						claimFestivePlane = 0;
						claimIcyBomb = 0;
						claimSnowyExplosion = 0;
						claimGoldenCannon = 0;
						claimChocolateGrenade = 0;
						claimOrangeBomb = 0;
						claimCookiePlane = 0;
						claimGingerbreadExplosion = 0;
						claimFestiveExplosion = 0;
						claimPeppermintBomb = 0;
						claimLogicalCannon = 0;
						claimFireGrenade = 0;
						claimYippeeGrenade = 0;
						claimLogicalGrenade = 0;
						claimDynamiteGrenade = 0;
						claimNukeGrenade = 0;
						claimSmokeGrenade = 0;
						claimHolyHandGrenade = 0;
						claimYippeeExplosion = 0;
						claimYippeePlane = 0;
						claimFirePlane = 0;
						claimLogicalPlane = 0;
						claimFlameCannon = 0;
						claimCandyCaneCannon = 0;
						claimDeadpoolCannon = 0;
						claimShockCannon = 0;
						claimBirdoCannon = 0;
						claimHeartsCannon = 0;
						claimChristmasGrenade = 0;
						claimSnowmanCannon = 0;
						claimGingerbreadCannon = 0;
						claimPresentCannon = 0;
						claimBellBomb = 0;
						claimSantasBomb = 0;
						claimElfExplosion = 0;
						claimSnowExplosion = 0;
						claimGarlandGrenade = 0;
						claimIceGrenade = 0;
						claimSantaGrenade = 0;
						claimRudolphPlane = 0;
						claimSantasPlane = 0;
						claimTreePlane = 0;
						claimLogicalBomb = 0;
						claimLogicalExplosion = 0;
						claimMushroomExplosion = 0;
						claimSmokeExplosion = 0;
						day1Claimed = 0;
						day2Claimed = 0;
						day3Claimed = 0;
						day4Claimed = 0;
						day5Claimed = 0;
						day6Claimed = 0;
						day7Claimed = 0;
						day8Claimed = 0;
						day9Claimed = 0;
						day10Claimed = 0;
						day11Claimed = 0;
						day12Claimed = 0;
						claimTreasure = 0;
						loading = 0;
						firstStrike = 0;
						wave10 = 0;
						resetting = false;
					}
					if (event.type == Event::MouseButtonReleased && mouseHitbox.getGlobalBounds().intersects(returnButton.getGlobalBounds())) {
						select.play();
						resetting = false;
					}
				}
				if (mouseHitbox.getGlobalBounds().intersects(resetDataButton.getGlobalBounds()) && !eventActive) {
					resetDataButton.setScale(3.2f, 3.2f);
					if (hoverable9) {
						hoverable9 = false;
					}
				}
				else {
					resetDataButton.setScale(3.f, 3.f);
					hoverable9 = true;
				}
			}
			if (seasonalShop) {
				FloatRect easterRect = easterText.getLocalBounds();
				easterText.setOrigin(easterRect.left + easterRect.width / 2.f, easterRect.top + easterRect.height / 2.f);
				easterText.setPosition(Vector2f(900, 300 + scrollOffset));
				easterText.setString("Easter");
			}
			if (shop) {
				FloatRect treasureRect = treasureText.getLocalBounds();
				treasureText.setOrigin(treasureRect.left + treasureRect.width, treasureRect.top + treasureRect.height / 2);
				treasureText.setPosition(Vector2f(1900.f, 50.f));
				treasureText.setString(to_string(treasure));
				treasureChest.setPosition(-treasureRect.width + 1850, 57);

				if (claimPeashooterCannon) {
					if (!altFont) {
						buyButton.setTexture(claimedTexture);
					} else {
						buyButton.setTexture(claimedButtonAltTexture);
					}
				}
				else {
					if (!altFont) {
						buyButton.setTexture(buyButtonTexture);
					}
					else {
						buyButton.setTexture(buyButtonAltTexture);
					}
				}
				if (claimYippeeCannon) {
					if (!altFont) {
						buyButton2.setTexture(claimedTexture);
					}
					else {
						buyButton2.setTexture(claimedButtonAltTexture);
					}
				}
				else {
					if (!altFont) {
						buyButton2.setTexture(buyButtonTexture);
					}
					else {
						buyButton2.setTexture(buyButtonAltTexture);
					}
				}
				if (claimSugarCannon) {
					if (!altFont) {
						buyButton3.setTexture(claimedTexture);
					}
					else {
						buyButton3.setTexture(claimedButtonAltTexture);
					}
				}
				else {
					if (!altFont) {
						buyButton3.setTexture(buyButtonTexture);
					}
					else {
						buyButton3.setTexture(buyButtonAltTexture);
					}
				}
				if (claimFireCannon) {
					if (!altFont) {
						buyButton4.setTexture(claimedTexture);
					}
					else {
						buyButton4.setTexture(claimedButtonAltTexture);
					}
				}
				else {
					if (!altFont) {
						buyButton4.setTexture(buyButtonTexture);
					}
					else {
						buyButton4.setTexture(buyButtonAltTexture);
					}
				}
				if (claimFlameCannon) {
					if (!altFont) {
						buyButton7.setTexture(claimedTexture);
					}
					else {
						buyButton7.setTexture(claimedButtonAltTexture);
					}
				} else {
					if (!altFont) {
						buyButton7.setTexture(buyButtonTexture);
					}
					else {
						buyButton7.setTexture(buyButtonAltTexture);
					}
				}
				if (claimDeadpoolCannon) {
					if (!altFont) {
						buyButton15.setTexture(claimedTexture);
					}
					else {
						buyButton15.setTexture(claimedButtonAltTexture);
					}
				}
				else {
					if (!altFont) {
						buyButton15.setTexture(buyButtonTexture);
					}
					else {
						buyButton15.setTexture(buyButtonAltTexture);
					}
				}
				if (claimShockCannon) {
					if (!altFont) {
						buyButton16.setTexture(claimedTexture);
					}
					else {
						buyButton16.setTexture(claimedButtonAltTexture);
					}
				}
				else {
					if (!altFont) {
						buyButton16.setTexture(buyButtonTexture);
					}
					else {
						buyButton16.setTexture(buyButtonAltTexture);
					}
				}
				if (claimBirdoCannon) {
					if (!altFont) {
						buyButton17.setTexture(claimedTexture);
					}
					else {
						buyButton17.setTexture(claimedButtonAltTexture);
					}
				}
				else {
					if (!altFont) {
						buyButton17.setTexture(buyButtonTexture);
					}
					else {
						buyButton17.setTexture(buyButtonAltTexture);
					}
				}
				if (claimHeartsCannon) {
					if (!altFont) {
						buyButton18.setTexture(claimedTexture);
					}
					else {
						buyButton18.setTexture(claimedButtonAltTexture);
					}
				}
				else {
					if (!altFont) {
						buyButton18.setTexture(buyButtonTexture);
					}
					else {
						buyButton18.setTexture(buyButtonAltTexture);
					}
				}
				if (claimLogicalCannon) {
					if (!altFont) {
						buyButton19.setTexture(claimedTexture);
					}
					else {
						buyButton19.setTexture(claimedButtonAltTexture);
					}
				}
				else {
					if (!altFont) {
						buyButton19.setTexture(buyButtonTexture);
					}
					else {
						buyButton19.setTexture(buyButtonAltTexture);
					}
				}
				if (claimApocCannon) {
					if (!altFont) {
						buyButton31.setTexture(claimedTexture);
					}
					else {
						buyButton31.setTexture(claimedButtonAltTexture);
					}
				}
				else {
					if (!altFont) {
						buyButton31.setTexture(buyButtonTexture);
					}
					else {
						buyButton31.setTexture(buyButtonAltTexture);
					}
				}
				if (claimYippeeBomb) {
					if (!altFont) {
						buyButton5.setTexture(claimedTexture);
					}
					else {
						buyButton5.setTexture(claimedButtonAltTexture);
					}
				}
				else {
					if (!altFont) {
						buyButton5.setTexture(buyButtonTexture);
					}
					else {
						buyButton5.setTexture(buyButtonAltTexture);
					}
			}
			if (claimFireBomb) {
				if (!altFont) {
					buyButton6.setTexture(claimedTexture);
				}
				else {
					buyButton6.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton6.setTexture(buyButtonTexture);
				}
				else {
					buyButton6.setTexture(buyButtonAltTexture);
				}
			}
			if (claimYoshiBomb) {
				if (!altFont) {
					buyButton20.setTexture(claimedTexture);
				}
				else {
					buyButton20.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton20.setTexture(buyButtonTexture);
				} 
				else {
					buyButton20.setTexture(buyButtonAltTexture);
				}
			}
			if (claimBirdoBomb) {
				if (!altFont) {
					buyButton21.setTexture(claimedTexture);
				}
				else {
					buyButton21.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton21.setTexture(buyButtonTexture);
				}
				else {
					buyButton21.setTexture(buyButtonAltTexture);
				}
			}
			if (claimLogicalBomb) {
				if (!altFont) {
					buyButton26.setTexture(claimedTexture);
				}
				else {
					buyButton26.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton26.setTexture(buyButtonTexture);
				}
				else {
					buyButton26.setTexture(buyButtonAltTexture);
				}
			}
			if (claimApocBomb) {
				if (!altFont) {
					buyButton32.setTexture(claimedTexture);
				}
				else {
					buyButton32.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton32.setTexture(buyButtonTexture);
				}
				else {
					buyButton32.setTexture(buyButtonAltTexture);
				}
			}
			if (claimFireGrenade) {
				if (!altFont) {
					buyButton8.setTexture(claimedTexture);
				}
				else {
					buyButton8.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton8.setTexture(buyButtonTexture);
				}
				else {
					buyButton8.setTexture(buyButtonAltTexture);
				}
			}
			if (claimYippeeGrenade) {
				if (!altFont) {
					buyButton9.setTexture(claimedTexture);
				}
				else {
					buyButton9.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton9.setTexture(buyButtonTexture);
				}
				else {
					buyButton9.setTexture(buyButtonAltTexture);
				}
			}
			if (claimLogicalGrenade) {
				if (!altFont) {
					buyButton10.setTexture(claimedTexture);
				}
				else {
					buyButton10.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton10.setTexture(buyButtonTexture);
				}
				else {
					buyButton10.setTexture(buyButtonAltTexture);
				}
			}
			if (claimDynamiteGrenade) {
				if (!altFont) {
					buyButton22.setTexture(claimedTexture);
				}
				else {
					buyButton22.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton22.setTexture(buyButtonTexture);
				}
				else {
					buyButton22.setTexture(buyButtonAltTexture);
				}
			}
			if (claimNukeGrenade) {
				if (!altFont) {
					buyButton23.setTexture(claimedTexture);
				}
				else {
					buyButton23.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton23.setTexture(buyButtonTexture);
				}
				else {
					buyButton23.setTexture(buyButtonAltTexture);
				}
			}
			if (claimSmokeGrenade) {
				if (!altFont) {
					buyButton24.setTexture(claimedTexture);
				}
				else {
					buyButton24.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton24.setTexture(buyButtonTexture);
				}
				else {
					buyButton24.setTexture(buyButtonAltTexture);
				}
			}
			if (claimHolyHandGrenade) {
				if (!altFont) {
					buyButton25.setTexture(claimedTexture);
				}
				else {
					buyButton25.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton25.setTexture(buyButtonTexture);
				}
				else {
					buyButton25.setTexture(buyButtonAltTexture);
				}
			}
			if (claimApocGrenade) {
				if (!altFont) {
					buyButton33.setTexture(claimedTexture);
				}
				else {
					buyButton33.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton33.setTexture(buyButtonTexture);
				}
				else {
					buyButton33.setTexture(buyButtonAltTexture);
				}
			}
			if (claimYippeeExplosion) {
				if (!altFont) {
					buyButton11.setTexture(claimedTexture);
				}
				else {
					buyButton11.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton11.setTexture(buyButtonTexture);
				}
				else {
					buyButton11.setTexture(buyButtonAltTexture);
				}
			}
			if (claimLogicalExplosion) {
				if (!altFont) {
					buyButton27.setTexture(claimedTexture);
				}
				else {
					buyButton27.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton27.setTexture(buyButtonTexture);
				}
				else {
					buyButton11.setTexture(buyButtonAltTexture);
				}
			}
			if (claimMushroomExplosion) {
				if (!altFont) {
					buyButton28.setTexture(claimedTexture);
				}
				else {
					buyButton28.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton28.setTexture(buyButtonTexture);
				}
				else {
					buyButton28.setTexture(buyButtonAltTexture);
				}
			}
			if (claimSmokeExplosion) {
				if (!altFont) {
					buyButton29.setTexture(claimedTexture);
				}
				else {
					buyButton29.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton29.setTexture(buyButtonTexture);
				}
				else {
					buyButton29.setTexture(buyButtonAltTexture);
				}
			}
			if (claimApocExplosion) {
				if (!altFont) {
					buyButton34.setTexture(claimedTexture);
				}
				else {
					buyButton34.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton34.setTexture(buyButtonTexture);
				}
				else {
					buyButton34.setTexture(buyButtonAltTexture);
				}
			}
			if (claimYippeePlane) {
				if (!altFont) {
					buyButton12.setTexture(claimedTexture);
				}
				else {
					buyButton12.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton12.setTexture(buyButtonTexture);
				}
				else {
					buyButton12.setTexture(buyButtonAltTexture);
				}
			}
			if (claimFirePlane) {
				if (!altFont) {
					buyButton13.setTexture(claimedTexture);
				}
				else {
					buyButton13.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton13.setTexture(buyButtonTexture);
				}
				else {
					buyButton13.setTexture(buyButtonAltTexture);
				}
			}
			if (claimLogicalPlane) {
				if (!altFont) {
					buyButton14.setTexture(claimedTexture);
				}
				else {
					buyButton14.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton14.setTexture(buyButtonTexture);
				}
				else {
					buyButton14.setTexture(buyButtonAltTexture);
				}
			}
			if (claimFighterPlane) {
				if (!altFont) {
					buyButton30.setTexture(claimedTexture);
				}
				else {
					buyButton30.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton30.setTexture(buyButtonTexture);
				}
				else {
					buyButton30.setTexture(buyButtonAltTexture);
				}
			}
			if (claimApocPlane) {
				if (!altFont) {
					buyButton35.setTexture(claimedTexture);
				}
				else {
					buyButton35.setTexture(claimedButtonAltTexture);
				}
			}
			else {
				if (!altFont) {
					buyButton35.setTexture(buyButtonTexture);
				}
				else {
					buyButton35.setTexture(buyButtonAltTexture);
				}
			}
				if (cannonShop) {
					if (treasure >= 1000) {
						if (!altFont) {
							price1.setTexture(price3Texture);
							price3.setTexture(price3Texture);
							price4.setTexture(price3Texture);
							price6.setTexture(price3Texture);
							price7.setTexture(price3Texture);
							price1.setTextureRect(IntRect(0, 0, price3Texture.getSize().x, price3Texture.getSize().y));
							price3.setTextureRect(IntRect(0, 0, price3Texture.getSize().x, price3Texture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price3Texture.getSize().x, price3Texture.getSize().y));
							price6.setTextureRect(IntRect(0, 0, price3Texture.getSize().x, price3Texture.getSize().y));
							price7.setTextureRect(IntRect(0, 0, price3Texture.getSize().x, price3Texture.getSize().y));
						} else {
							price1.setTexture(price3AltTexture);
							price3.setTexture(price3AltTexture);
							price4.setTexture(price3AltTexture);
							price6.setTexture(price3AltTexture);
							price7.setTexture(price3AltTexture);
							price1.setTextureRect(IntRect(0, 0, price3AltTexture.getSize().x, price3AltTexture.getSize().y));
							price3.setTextureRect(IntRect(0, 0, price3AltTexture.getSize().x, price3AltTexture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price3AltTexture.getSize().x, price3AltTexture.getSize().y));
							price6.setTextureRect(IntRect(0, 0, price3AltTexture.getSize().x, price3AltTexture.getSize().y));
							price7.setTextureRect(IntRect(0, 0, price3AltTexture.getSize().x, price3AltTexture.getSize().y));
						}
					}
					else if (treasure < 1000) {
						if (!altFont) {
							price1.setTexture(price33Texture);
							price3.setTexture(price33Texture);
							price4.setTexture(price33Texture);
							price6.setTexture(price33Texture);
							price7.setTexture(price33Texture);
							price1.setTextureRect(IntRect(0, 0, price33Texture.getSize().x, price33Texture.getSize().y));
							price3.setTextureRect(IntRect(0, 0, price33Texture.getSize().x, price33Texture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price33Texture.getSize().x, price33Texture.getSize().y));
							price6.setTextureRect(IntRect(0, 0, price33Texture.getSize().x, price33Texture.getSize().y));
							price7.setTextureRect(IntRect(0, 0, price33Texture.getSize().x, price33Texture.getSize().y));
						} else {
							price1.setTexture(price33AltTexture);
							price3.setTexture(price33AltTexture);
							price4.setTexture(price33AltTexture);
							price6.setTexture(price33AltTexture);
							price7.setTexture(price33AltTexture);
							price1.setTextureRect(IntRect(0, 0, price33AltTexture.getSize().x, price33AltTexture.getSize().y));
							price3.setTextureRect(IntRect(0, 0, price33AltTexture.getSize().x, price33AltTexture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price33AltTexture.getSize().x, price33AltTexture.getSize().y));
							price6.setTextureRect(IntRect(0, 0, price33AltTexture.getSize().x, price33AltTexture.getSize().y));
							price7.setTextureRect(IntRect(0, 0, price33AltTexture.getSize().x, price33AltTexture.getSize().y));
						}
					}
					price1.setOrigin(132.5f, 33.5f);
					price3.setOrigin(132.5f, 33.5f);
					price4.setOrigin(132.5f, 33.5f);
					price6.setOrigin(132.5f, 33.5f);
					price7.setOrigin(132.5f, 33.5f);
					if (treasure >= 750) {
						if (!altFont) {
							price2.setTexture(price2Texture);
						} else {
							price2.setTexture(price2AltTexture);
						}
					} else if (treasure < 750) {
						if (!altFont) {
							price2.setTexture(price22Texture);
						} else {
							price2.setTexture(price22AltTexture);
						}
					}
					price2.setOrigin(106.5f, 33.5f);
					if (treasure >= 1500) {
						if (!altFont) {
							price5.setTexture(price4Texture);
							price8.setTexture(price4Texture);
							price9.setTexture(price4Texture);
							price10.setTexture(price4Texture);
							price11.setTexture(price4Texture);
							price10.setTextureRect(IntRect(0, 0, price4Texture.getSize().x, price4Texture.getSize().y));
							price11.setTextureRect(IntRect(0, 0, price4Texture.getSize().x, price4Texture.getSize().y));
						} else {
							price5.setTexture(price4AltTexture);
							price8.setTexture(price4AltTexture);
							price9.setTexture(price4AltTexture);
							price10.setTexture(price4AltTexture);
							price11.setTexture(price4AltTexture);
							price10.setTextureRect(IntRect(0, 0, price4AltTexture.getSize().x, price4AltTexture.getSize().y));
							price11.setTextureRect(IntRect(0, 0, price4AltTexture.getSize().x, price4AltTexture.getSize().y));
						}
					}
					else if (treasure < 1500) {
						if (!altFont) {
							price5.setTexture(price44Texture);
							price8.setTexture(price44Texture);
							price9.setTexture(price44Texture);
							price10.setTexture(price44Texture);
							price11.setTexture(price44Texture);
							price10.setTextureRect(IntRect(0, 0, price44Texture.getSize().x, price44Texture.getSize().y));
							price11.setTextureRect(IntRect(0, 0, price44Texture.getSize().x, price44Texture.getSize().y));
						} else {
							price5.setTexture(price44AltTexture);
							price8.setTexture(price44AltTexture);
							price9.setTexture(price44AltTexture);
							price10.setTexture(price44AltTexture);
							price11.setTexture(price44AltTexture);
							price10.setTextureRect(IntRect(0, 0, price44AltTexture.getSize().x, price44AltTexture.getSize().y));
							price11.setTextureRect(IntRect(0, 0, price44AltTexture.getSize().x, price44AltTexture.getSize().y));
						}
					}
					price5.setOrigin(132.5f, 33.5f);
					price8.setOrigin(132.5f, 33.5f);
					price9.setOrigin(132.5f, 33.5f);
					price10.setOrigin(132.5f, 33.5f);
					price11.setOrigin(132.5f, 33.5f);
				}
				if (bombShop) {
					if (treasure >= 500) {
						if (!altFont) {
							price2.setTexture(price1Texture);
							price1.setTexture(price1Texture);
							price1.setTextureRect(IntRect(0, 0, price1Texture.getSize().x, price1Texture.getSize().y));
						} else {
							price2.setTexture(price1AltTexture);
							price1.setTexture(price1AltTexture);
							price1.setTextureRect(IntRect(0, 0, price1AltTexture.getSize().x, price1AltTexture.getSize().y));
						}
					}
					else if (treasure < 500) {
						if (!altFont) {
							price2.setTexture(price11Texture);
							price1.setTexture(price11Texture);
							price1.setTextureRect(IntRect(0, 0, price11Texture.getSize().x, price11Texture.getSize().y));
						}
						else {
							price2.setTexture(price11AltTexture);
							price1.setTexture(price11AltTexture);
							price1.setTextureRect(IntRect(0, 0, price11AltTexture.getSize().x, price11AltTexture.getSize().y));
						}
					}
					if (treasure >= 750) {
						if (!altFont) {
							price3.setTexture(price2Texture);
							price4.setTexture(price2Texture);
							price5.setTexture(price2Texture);
							price6.setTexture(price2Texture);
							price3.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
							price5.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
							price6.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
						}
						else {
							price3.setTexture(price2AltTexture);
							price4.setTexture(price2AltTexture);
							price5.setTexture(price2AltTexture);
							price6.setTexture(price2AltTexture);
							price3.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
							price5.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
							price6.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
						}
					}
					else if (treasure < 750) {
						if (!altFont) {
							price3.setTexture(price22Texture);
							price4.setTexture(price22Texture);
							price5.setTexture(price22Texture);
							price6.setTexture(price22Texture);
							price3.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
							price5.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
							price6.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
						}
						else {
							price3.setTexture(price22AltTexture);
							price4.setTexture(price22AltTexture);
							price5.setTexture(price22AltTexture);
							price6.setTexture(price22AltTexture);
							price3.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
							price5.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
							price6.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
						}
					}
					price1.setOrigin(106.5f, 33.5f);
					price2.setOrigin(106.5f, 33.5f);
					price3.setOrigin(106.5f, 33.5f);
					price4.setOrigin(106.5f, 33.5f);
					price5.setOrigin(106.5f, 33.5f);
					price6.setOrigin(106.5f, 33.5f);
				}
				if (grenadeShop) {
					if (treasure >= 500) {
						if (!altFont) {
							price1.setTexture(price1Texture);
							price5.setTexture(price1Texture);
							price2.setTexture(price1Texture);
							price1.setTextureRect(IntRect(0, 0, price1Texture.getSize().x, price1Texture.getSize().y));
							price5.setTextureRect(IntRect(0, 0, price1Texture.getSize().x, price1Texture.getSize().y));
						} else {
							price1.setTexture(price1AltTexture);
							price5.setTexture(price1AltTexture);
							price2.setTexture(price1AltTexture);
							price1.setTextureRect(IntRect(0, 0, price1AltTexture.getSize().x, price1AltTexture.getSize().y));
							price5.setTextureRect(IntRect(0, 0, price1AltTexture.getSize().x, price1AltTexture.getSize().y));
						}
					}
					else if (treasure < 500) {
						if (!altFont) {
							price1.setTexture(price11Texture);
							price5.setTexture(price11Texture);
							price2.setTexture(price11Texture);
							price1.setTextureRect(IntRect(0, 0, price11Texture.getSize().x, price11Texture.getSize().y));
							price5.setTextureRect(IntRect(0, 0, price11Texture.getSize().x, price11Texture.getSize().y));
						} else {
							price1.setTexture(price11AltTexture);
							price5.setTexture(price11AltTexture);
							price2.setTexture(price11AltTexture);
							price1.setTextureRect(IntRect(0, 0, price11AltTexture.getSize().x, price11AltTexture.getSize().y));
							price5.setTextureRect(IntRect(0, 0, price11AltTexture.getSize().x, price11AltTexture.getSize().y));
						}
					}
					if (treasure >= 750) {
						if (!altFont) {
							price3.setTexture(price2Texture);
							price4.setTexture(price2Texture);
							price6.setTexture(price2Texture);
							price8.setTexture(price2Texture);
							price3.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
							price6.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
							price8.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
						} else {
							price3.setTexture(price2AltTexture);
							price4.setTexture(price2AltTexture);
							price6.setTexture(price2AltTexture);
							price8.setTexture(price2AltTexture);
							price3.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
							price6.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
							price8.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
						}
					}
					else if (treasure < 750) {
						if (!altFont) {
							price3.setTexture(price22Texture);
							price4.setTexture(price22Texture);
							price6.setTexture(price22Texture);
							price8.setTexture(price22Texture);
							price3.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
							price6.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
							price8.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
						} else {
							price3.setTexture(price22AltTexture);
							price4.setTexture(price22AltTexture);
							price6.setTexture(price22AltTexture);
							price8.setTexture(price22AltTexture);
							price3.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
							price6.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
							price8.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
						}
					}
					price3.setOrigin(106.5f, 33.5f);
					price4.setOrigin(106.5f, 33.5f);
					price6.setOrigin(106.5f, 33.5f);
					price8.setOrigin(106.5f, 33.5f);
					if (treasure >= 1000) {
						if (!altFont) {
							price7.setTexture(price3Texture);
							price7.setTextureRect(IntRect(0, 0, price3Texture.getSize().x, price3Texture.getSize().y));
						}
						else {
							price7.setTexture(price3AltTexture);
							price7.setTextureRect(IntRect(0, 0, price3AltTexture.getSize().x, price3AltTexture.getSize().y));
						}
					}
					else if (treasure < 1000) {
						if (!altFont) {
							price7.setTexture(price33Texture);
							price7.setTextureRect(IntRect(0, 0, price33Texture.getSize().x, price33Texture.getSize().y));
						}
						else {
							price7.setTexture(price33AltTexture);
							price7.setTextureRect(IntRect(0, 0, price33AltTexture.getSize().x, price33AltTexture.getSize().y));
						}
					}
					price7.setOrigin(106.5f, 33.5f);
				}
				if (explosionShop) {
					if (treasure >= 750) {
						if (!altFont) {
							price1.setTexture(price2Texture);
							price4.setTexture(price2Texture);
							price5.setTexture(price2Texture);
							price1.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
							price5.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
						} else {
							price1.setTexture(price2AltTexture);
							price4.setTexture(price2AltTexture);
							price5.setTexture(price2AltTexture);
							price1.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
							price5.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
						}
					}
					else if (treasure < 750) {
						if (!altFont) {
							price1.setTexture(price22Texture);
							price4.setTexture(price22Texture);
							price5.setTexture(price22Texture);
							price1.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
							price5.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
						} else {
							price1.setTexture(price22AltTexture);
							price4.setTexture(price22AltTexture);
							price5.setTexture(price22AltTexture);
							price1.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
							price4.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
							price5.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
						}
					}
					price1.setOrigin(106.5f, 33.5f);
					price4.setOrigin(106.5f, 33.5f);
					price5.setOrigin(106.5f, 33.5f);
					if (treasure >= 1000) {
						if (!altFont) {
							price2.setTexture(price3Texture);
							price3.setTexture(price3Texture);
							price2.setTextureRect(IntRect(0, 0, price3Texture.getSize().x, price3Texture.getSize().y));
							price3.setTextureRect(IntRect(0, 0, price3Texture.getSize().x, price3Texture.getSize().y));
						}
						else {
							price2.setTexture(price3AltTexture);
							price3.setTexture(price3AltTexture);
							price2.setTextureRect(IntRect(0, 0, price3AltTexture.getSize().x, price3AltTexture.getSize().y));
							price3.setTextureRect(IntRect(0, 0, price3AltTexture.getSize().x, price3AltTexture.getSize().y));
						}
					}
					else if (treasure < 1000) {
						if (!altFont) {
							price2.setTexture(price33Texture);
							price3.setTexture(price33Texture);
							price2.setTextureRect(IntRect(0, 0, price33Texture.getSize().x, price33Texture.getSize().y));
							price3.setTextureRect(IntRect(0, 0, price33Texture.getSize().x, price33Texture.getSize().y));
						}
						else {
							price2.setTexture(price33AltTexture);
							price3.setTexture(price33AltTexture);
							price2.setTextureRect(IntRect(0, 0, price33AltTexture.getSize().x, price33AltTexture.getSize().y));
							price3.setTextureRect(IntRect(0, 0, price33AltTexture.getSize().x, price33AltTexture.getSize().y));
						}
					}
					price2.setOrigin(106.5f, 33.5f);
					price3.setOrigin(106.5f, 33.5f);
				}
				if (planeShop) {
					if (treasure >= 750) {
						if (!altFont) {
							price1.setTexture(price2Texture);
							price1.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
							price2.setTexture(price2Texture);
							price2.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
							price3.setTexture(price2Texture);
							price3.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
							price5.setTexture(price2Texture);
							price5.setTextureRect(IntRect(0, 0, price2Texture.getSize().x, price2Texture.getSize().y));
						} else {
							price1.setTexture(price2AltTexture);
							price1.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
							price2.setTexture(price2AltTexture);
							price2.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
							price3.setTexture(price2AltTexture);
							price3.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
							price5.setTexture(price2AltTexture);
							price5.setTextureRect(IntRect(0, 0, price2AltTexture.getSize().x, price2AltTexture.getSize().y));
						}
					} else if (treasure < 750) {
						if (!altFont) {
							price1.setTexture(price22Texture);
							price1.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
							price2.setTexture(price22Texture);
							price2.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
							price3.setTexture(price22Texture);
							price3.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
							price5.setTexture(price22Texture);
							price5.setTextureRect(IntRect(0, 0, price22Texture.getSize().x, price22Texture.getSize().y));
						} else {
							price1.setTexture(price22AltTexture);
							price1.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
							price2.setTexture(price22AltTexture);
							price2.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
							price3.setTexture(price22AltTexture);
							price3.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
							price5.setTexture(price22AltTexture);
							price5.setTextureRect(IntRect(0, 0, price22AltTexture.getSize().x, price22AltTexture.getSize().y));
						}
					}
					price1.setOrigin(106.5f, 33.5f);
					price2.setOrigin(106.5f, 33.5f);
					price3.setOrigin(106.5f, 33.5f);
					price5.setOrigin(106.5f, 33.5f);
					if (treasure >= 1000) {
						if (!altFont) {
							price4.setTexture(price3Texture);
							price4.setTextureRect(IntRect(0, 0, price3Texture.getSize().x, price3Texture.getSize().y));
						}
						else {
							price4.setTexture(price3AltTexture);
							price4.setTextureRect(IntRect(0, 0, price3AltTexture.getSize().x, price3AltTexture.getSize().y));
						}
					}
					else if (treasure < 1000) {
						if (!altFont) {
							price4.setTexture(price33Texture);
							price4.setTextureRect(IntRect(0, 0, price33Texture.getSize().x, price33Texture.getSize().y));
						}
						else {
							price4.setTexture(price33AltTexture);
							price4.setTextureRect(IntRect(0, 0, price33AltTexture.getSize().x, price33AltTexture.getSize().y));
						}
					}
					price4.setOrigin(106.5f, 33.5f);
				}
				if (mouseHitbox.getGlobalBounds().intersects(unlockAllSkinsButton.getGlobalBounds()) && !eventActive) {
					unlockAllSkinsButton.setScale(2.2f, 2.2f);
					if (hoverable34) {
						hoverable34 = false;
					}
				}
				else {
					unlockAllSkinsButton.setScale(2.0f, 2.0f);
					hoverable34 = true;
				}
				if (cannonShop) {
					if (mouseHitbox.getGlobalBounds().intersects(buyButton.getGlobalBounds()) && !eventActive && !claimPeashooterCannon) {
						buyButton.setScale(1.2, 1.2);
						if (hoverable9) {
							hoverable9 = false;
						}
					}
					else {
						buyButton.setScale(1, 1);
						hoverable9 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton2.getGlobalBounds()) && !eventActive && !claimYippeeCannon) {
						buyButton2.setScale(1.2, 1.2);
						if (hoverable10) {
							hoverable10 = false;
						}
					}
					else {
						buyButton2.setScale(1, 1);
						hoverable10 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton3.getGlobalBounds()) && !eventActive && !claimSugarCannon) {
						buyButton3.setScale(1.2, 1.2);
						if (hoverable11) {
							hoverable11 = false;
						}
					}
					else {
						buyButton3.setScale(1, 1);
						hoverable11 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton4.getGlobalBounds()) && !eventActive && !claimFireCannon) {
						buyButton4.setScale(1.2, 1.2);
						if (hoverable12) {
							hoverable12 = false;
						}
					}
					else {
						buyButton4.setScale(1, 1);
						hoverable12 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton7.getGlobalBounds()) && !eventActive && !claimFlameCannon) {
						buyButton7.setScale(1.2, 1.2);
						if (hoverable13) {
							hoverable13 = false;
						}
					}
					else {
						buyButton7.setScale(1, 1);
						hoverable13 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton15.getGlobalBounds()) && !eventActive && !claimDeadpoolCannon) {
						buyButton15.setScale(1.2, 1.2);
						if (hoverable28) {
							hoverable28 = false;
						}
					}
					else {
						buyButton15.setScale(1, 1);
						hoverable28 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton16.getGlobalBounds()) && !eventActive && !claimShockCannon) {
						buyButton16.setScale(1.2, 1.2);
						if (hoverable29) {
							hoverable29 = false;
						}
					}
					else {
						buyButton16.setScale(1, 1);
						hoverable29 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton17.getGlobalBounds()) && !eventActive && !claimBirdoCannon) {
						buyButton17.setScale(1.2, 1.2);
						if (hoverable32) {
							hoverable32 = false;
						}
					}
					else {
						buyButton17.setScale(1, 1);
						hoverable32 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton18.getGlobalBounds()) && !eventActive && !claimHeartsCannon) {
						buyButton18.setScale(1.2, 1.2);
						if (hoverable33) {
							hoverable33 = false;
						}
					}
					else {
						buyButton18.setScale(1, 1);
						hoverable33 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton19.getGlobalBounds()) && !eventActive && !claimLogicalCannon) {
						buyButton19.setScale(1.2, 1.2);
						if (hoverable34) {
							hoverable34 = false;
						}
					}
					else {
						buyButton19.setScale(1, 1);
						hoverable34 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton31.getGlobalBounds()) && !eventActive && !claimApocCannon) {
						buyButton31.setScale(1.2, 1.2);
						if (hoverable47) {
							hoverable47 = false;
						}
					}
					else {
						buyButton31.setScale(1, 1);
						hoverable47 = true;
					}
				}
				if (bombShop) {
					if (mouseHitbox.getGlobalBounds().intersects(buyButton6.getGlobalBounds()) && !eventActive && !claimFireBomb) {
						buyButton6.setScale(1.2, 1.2);
						if (hoverable14) {
							hoverable14 = false;
						}
					}
					else {
						buyButton6.setScale(1, 1);
						hoverable14 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton5.getGlobalBounds()) && !eventActive && !claimYippeeBomb) {
						buyButton5.setScale(1.2, 1.2);
						if (hoverable19) {
							hoverable19 = false;
						}
					}
					else {
						buyButton5.setScale(1, 1);
						hoverable19 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton20.getGlobalBounds()) && !eventActive && !claimYoshiBomb) {
						buyButton20.setScale(1.2, 1.2);
						if (hoverable36) {
							hoverable36 = false;
						}
					}
					else {
						buyButton20.setScale(1, 1);
						hoverable36 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton21.getGlobalBounds()) && !eventActive && !claimBirdoBomb) {
						buyButton21.setScale(1.2, 1.2);
						if (hoverable37) {
							hoverable37 = false;
						}
					}
					else {
						buyButton21.setScale(1, 1);
						hoverable37 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton26.getGlobalBounds()) && !eventActive && !claimLogicalBomb) {
						buyButton26.setScale(1.2, 1.2);
						if (hoverable42) {
							hoverable42 = false;
						}
					}
					else {
						buyButton26.setScale(1, 1);
						hoverable42 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton32.getGlobalBounds()) && !eventActive && !claimApocBomb) {
						buyButton32.setScale(1.2, 1.2);
						if (hoverable48) {
							hoverable48 = false;
						}
					}
					else {
						buyButton32.setScale(1, 1);
						hoverable48 = true;
					}
				}
				if (grenadeShop) {
					if (mouseHitbox.getGlobalBounds().intersects(buyButton8.getGlobalBounds()) && !eventActive && !claimFireGrenade) {
						buyButton8.setScale(1.2, 1.2);
						if (hoverable21) {
							hoverable21 = false;
						}
					}
					else {
						buyButton8.setScale(1, 1);
						hoverable21 = true;
					}

					if (mouseHitbox.getGlobalBounds().intersects(buyButton9.getGlobalBounds()) && !eventActive && !claimYippeeGrenade) {
						buyButton9.setScale(1.2, 1.2);
						if (hoverable22) {
							hoverable22 = false;
						}
					}
					else {
						buyButton9.setScale(1, 1);
						hoverable22 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton10.getGlobalBounds()) && !eventActive && !claimLogicalGrenade) {
						buyButton10.setScale(1.2, 1.2);
						if (hoverable23) {
							hoverable23 = false;
						}
					}
					else {
						buyButton10.setScale(1, 1);
						hoverable23 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton22.getGlobalBounds()) && !eventActive && !claimDynamiteGrenade) {
						buyButton22.setScale(1.2, 1.2);
						if (hoverable38) {
							hoverable38 = false;
						}
					}
					else {
						buyButton22.setScale(1, 1);
						hoverable38 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton23.getGlobalBounds()) && !eventActive && !claimNukeGrenade) {
						buyButton23.setScale(1.2, 1.2);
						if (hoverable39) {
							hoverable39 = false;
						}
					}
					else {
						buyButton23.setScale(1, 1);
						hoverable39 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton24.getGlobalBounds()) && !eventActive && !claimSmokeGrenade) {
						buyButton24.setScale(1.2, 1.2);
						if (hoverable40) {
							hoverable40 = false;
						}
					}
					else {
						buyButton24.setScale(1, 1);
						hoverable40 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton25.getGlobalBounds()) && !eventActive && !claimHolyHandGrenade) {
						buyButton25.setScale(1.2, 1.2);
						if (hoverable41) {
							hoverable41 = false;
						}
					}
					else {
						buyButton25.setScale(1, 1);
						hoverable41 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton33.getGlobalBounds()) && !eventActive && !claimApocGrenade) {
						buyButton33.setScale(1.2, 1.2);
						if (hoverable49) {
							hoverable49 = false;
						}
					}
					else {
						buyButton33.setScale(1, 1);
						hoverable49 = true;
					}
				}
				if (explosionShop) {
					if (mouseHitbox.getGlobalBounds().intersects(buyButton11.getGlobalBounds()) && !eventActive && !claimYippeeExplosion) {
						buyButton11.setScale(1.2, 1.2);
						if (hoverable23) {
							hoverable23 = false;
						}
					}
					else {
						buyButton11.setScale(1, 1);
						hoverable23 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton27.getGlobalBounds()) && !eventActive && !claimLogicalExplosion) {
						buyButton27.setScale(1.2, 1.2);
						if (hoverable43) {
							hoverable43 = false;
						}
					}
					else {
						buyButton27.setScale(1, 1);
						hoverable43 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton28.getGlobalBounds()) && !eventActive && !claimMushroomExplosion) {
						buyButton28.setScale(1.2, 1.2);
						if (hoverable44) {
							hoverable44 = false;
						}
					}
					else {
						buyButton28.setScale(1, 1);
						hoverable44 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton29.getGlobalBounds()) && !eventActive && !claimSmokeExplosion) {
						buyButton29.setScale(1.2, 1.2);
						if (hoverable45) {
							hoverable45 = false;
						}
					}
					else {
						buyButton29.setScale(1, 1);
						hoverable45 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton34.getGlobalBounds()) && !eventActive && !claimApocExplosion) {
						buyButton34.setScale(1.2, 1.2);
						if (hoverable50) {
							hoverable50 = false;
						}
					}
					else {
						buyButton34.setScale(1, 1);
						hoverable50 = true;
					}
				}
				if (planeShop) {
					if (mouseHitbox.getGlobalBounds().intersects(buyButton12.getGlobalBounds()) && !eventActive && !claimYippeePlane) {
						buyButton12.setScale(1.2, 1.2);
						if (hoverable24) {
							hoverable24 = false;
						}
					}
					else {
						buyButton12.setScale(1, 1);
						hoverable24 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton13.getGlobalBounds()) && !eventActive && !claimFirePlane) {
						buyButton13.setScale(1.2, 1.2);
						if (hoverable25) {
							hoverable25 = false;
						}
					}
					else {
						buyButton13.setScale(1, 1);
						hoverable25 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton14.getGlobalBounds()) && !eventActive && !claimLogicalPlane) {
						buyButton14.setScale(1.2, 1.2);
						if (hoverable26) {
							hoverable26 = false;
						}
					}
					else {
						buyButton14.setScale(1, 1);
						hoverable26 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton30.getGlobalBounds()) && !eventActive && !claimFighterPlane) {
						buyButton30.setScale(1.2, 1.2);
						if (hoverable46) {
							hoverable46 = false;
						}
					}
					else {
						buyButton30.setScale(1, 1);
						hoverable46 = true;
					}
					if (mouseHitbox.getGlobalBounds().intersects(buyButton35.getGlobalBounds()) && !eventActive && !claimApocPlane) {
						buyButton35.setScale(1.2, 1.2);
						if (hoverable51) {
							hoverable51 = false;
						}
					}
					else {
						buyButton35.setScale(1, 1);
						hoverable51 = true;
					}
				}
			}
			if (credit) {
				if (!altFont) {
					creditsText.setOrigin(320.f, 1068.f);
				}
				else {
					creditsText.setTextureRect(IntRect(0, 0, creditsTextAltTexture.getSize().x, creditsTextAltTexture.getSize().y));
					creditsText.setOrigin(268.f, 1064.f);
				}
				creditsText.setPosition(960.f, creditsText.getPosition().y - 0.9f);
				creditsThanksText.setPosition(960.f, creditsThanksText.getPosition().y - 0.9f);
				if (creditsMusic.getStatus() == SoundSource::Stopped) {
					creditsMusic.stop();
					titleText.setString("");
					credit = false;
					menuMusic.play();
				}
			}
			if (setting) {
				FloatRect musicRect = musicText.getLocalBounds();
				musicText.setOrigin(musicRect.left + musicRect.width / 2.f, musicRect.top + musicRect.height / 2.f);
				musicText.setPosition(Vector2f(960.f, 252.f));
				musicText.setString("Music");
				FloatRect SFXRect = SFXText.getLocalBounds();
				SFXText.setOrigin(SFXRect.left + SFXRect.width / 2.f, SFXRect.top + SFXRect.height / 2.f);
				SFXText.setPosition(Vector2f(960.f, 612.f));
				SFXText.setString("SFX");
				FloatRect satRect = satText.getLocalBounds();
				satText.setOrigin(satRect.left + satRect.width / 2.f, satRect.top + satRect.height / 2.f);
				satText.setPosition(Vector2f(960.f, 252.f));
				satText.setString("Saturation");
				FloatRect conRect = conText.getLocalBounds();
				conText.setOrigin(conRect.left + conRect.width / 2.f, conRect.top + conRect.height / 2.f);
				conText.setPosition(Vector2f(960.f, 612 -150.f));
				conText.setString("Contrast");

				FloatRect saturationRect = saturationText.getLocalBounds();
				saturationText.setOrigin(saturationRect.left + saturationRect.width / 2.f, saturationRect.top + saturationRect.height / 2.f);
				saturationText.setPosition(Vector2f(1300.0f, 360.0f));
				saturationText.setString(to_string(static_cast<int>(saturation * 100)) + "%");
				FloatRect contrastRect = contrastText.getLocalBounds();
				contrastText.setOrigin(contrastRect.left + contrastRect.width / 2.f, contrastRect.top + contrastRect.height / 2.f);
				contrastText.setPosition(Vector2f(1300.0f, 720 - 150.0f));
				contrastText.setString(to_string(static_cast<int>(contrast * 100)) + "%");

				FloatRect scanRect = scanText.getLocalBounds();
				scanText.setOrigin(scanRect.left + scanRect.width / 2.f, scanRect.top + scanRect.height / 2.f);
				scanText.setPosition(Vector2f(1000.0f, 680.0f));
				scanText.setString("Scanlines");

				FloatRect fontRect = fontText.getLocalBounds();
				fontText.setOrigin(fontRect.left + fontRect.width / 2.f, fontRect.top + fontRect.height / 2.f);
				fontText.setPosition(Vector2f(1000.0f, 770.0f));
				fontText.setString("Alt Font");

				FloatRect fullscreenRect = fullscreenText.getLocalBounds();
				fullscreenText.setOrigin(fullscreenRect.left + fullscreenRect.width / 2.f, fullscreenRect.top + fullscreenRect.height / 2.f);
				fullscreenText.setPosition(Vector2f(1000.0f, 860.0f));
				fullscreenText.setString("Fullscreen");

				FloatRect vsyncRect = vsyncText.getLocalBounds();
				vsyncText.setOrigin(vsyncRect.left + vsyncRect.width / 2.f, vsyncRect.top + vsyncRect.height / 2.f);
				vsyncText.setPosition(Vector2f(530.0f, 440.0f));
				vsyncText.setString("Enable Vsync");

				FloatRect unlimitedRect = unlimitedText.getLocalBounds();
				unlimitedText.setOrigin(unlimitedRect.left + unlimitedRect.width / 2.f, unlimitedRect.top + unlimitedRect.height / 2.f);
				unlimitedText.setPosition(Vector2f(530.0f, 520.0f));
				unlimitedText.setString("Unlimited FPS");

				FloatRect frameRect = frameText.getLocalBounds();
				frameText.setOrigin(frameRect.left + frameRect.width / 2.f, frameRect.top + frameRect.height / 2.f);
				frameText.setPosition(Vector2f(480.0f, 252.0f));
				frameText.setString("Framerate");

				FloatRect frameBoxRect = frameBoxText.getLocalBounds();
				frameBoxText.setOrigin(frameBoxRect.left + frameBoxRect.width / 2.f, frameBoxRect.top + frameBoxRect.height / 2.f);
				frameBoxText.setPosition(Vector2f(480.f, 340.f));
				if (frameBoxText.getString() == "") {
					frameBox.setSize(Vector2f(100, 40));
					frameBox.setOrigin(50, 20);
				}
				else {
					frameBox.setSize(Vector2f((frameBoxRect.getSize().x + 20) / 2, 40));
					frameBox.setOrigin((frameBoxRect.getSize().x + 20) / 4, 20);
				}

				dotPos = dot.getPosition();
				dot2Pos = dot2.getPosition();
				musicVolume = ((dotPos.x - 760) / 4);
				SFXVolume = ((dot2Pos.x - 760) / 4);
				saturation = ((dot3.getPosition().x - 760) / 200);
				contrast = ((dot4.getPosition().x - 760) / 200);
			}
			rotateRight = false;
			rotateLeft = false;
			timer = 0.f;
			frames = 0;
			wave = 0;
			wave5 = 0;
			playerSpeed = ((15.f * wave) + 180.f) / (3.f * framerate);
			bombSpeed = ((90.f * wave) + 2100.f) / (5.f * framerate);
			planeSpeed = ((90.f * wave) + 300.f) / (5.f * framerate);
			shoot = false;
			pickable = false;
			switchTo = false;
			bombShoot = true;
			shots = 0;
			corner1 = 1.f;
			corner2 = 0.f;
			score = 0;
			waveString = to_string(wave);
			scoreString = to_string(score);
			explosionBool = false;
			expTimer = 5;
			pause = false;
			player.setRotation(0);
			playerHitbox1.setRotation(player.getRotation());
			bomb.setPosition(960.f, 540.f);
			bombRotation = 0;
			bomb.setRotation(0);
			bombHitbox.setPosition(bomb.getPosition());
			bombHitbox.setRotation(bomb.getRotation());
			grenade.setPosition(3840.f, 2160.f);
			grenadeHitbox.setPosition(grenade.getPosition());
			plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
			plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
			plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
			plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
			plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
			plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
			plane1Hitbox.setPosition(plane1.getPosition());
			plane2Hitbox.setPosition(plane2.getPosition());
			plane3Hitbox.setPosition(plane3.getPosition());
			plane4Hitbox.setPosition(plane4.getPosition());
			plane5Hitbox.setPosition(plane5.getPosition());
			plane6Hitbox.setPosition(plane6.getPosition());
			explosion.setPosition(5760.f, 3240.f);
		}
		if (MPWarning) {
			if (!altFont) {
				returnButton.setTexture(okButtonTexture);
			} else {
				returnButton.setTexture(okButtonAltTexture);
			}
			if (!showMPWarning) {
				MPWarningBox.setFillColor(Color(0, 0, 0, 255));
			}
			else {
				MPWarningBox.setFillColor(Color(38, 38, 38, 255));
			}
			returnButton.setPosition(960.f, 840.f);
		}
		if (!menu && versus) {
			waveString = to_string(wave);
			MP1scoreString = to_string(MP1score);
			MP2scoreString = to_string(MP2score);
			FloatRect MP1scoreRect = MP1scoreText.getLocalBounds();
			MP1scoreText.setOrigin(MP1scoreRect.left + MP1scoreRect.width / 2.f, MP1scoreRect.top + MP1scoreRect.height / 2.f);
			MP1scoreText.setPosition(Vector2f(480.f, 100.f));
			MP1scoreText.setString("Score: " + MP1scoreString);

			FloatRect MP1waveRect = MP1waveText.getLocalBounds();
			MP1waveText.setOrigin(MP1waveRect.left + MP1waveRect.width / 2.f, MP1waveRect.top + MP1waveRect.height / 2.f);
			MP1waveText.setPosition(Vector2f(480.f, 200.f));
			MP1waveText.setString("Wave: " + waveString);

			FloatRect MP2scoreRect = MP2scoreText.getLocalBounds();
			MP2scoreText.setOrigin(MP2scoreRect.left + MP2scoreRect.width / 2.f, MP2scoreRect.top + MP2scoreRect.height / 2.f);
			MP2scoreText.setPosition(Vector2f(1440.f, 100.f));
			MP2scoreText.setString("Score: " + MP2scoreString);

			FloatRect MP2waveRect = MP2waveText.getLocalBounds();
			MP2waveText.setOrigin(MP2waveRect.left + MP2waveRect.width / 2.f, MP2waveRect.top + MP2waveRect.height / 2.f);
			MP2waveText.setPosition(Vector2f(1440.f, 200.f));
			MP2waveText.setString("Wave: " + waveString);
			if (MP1rotateLeft) {
				MP1player.rotate(-playerSpeed);
				if (!MP1shoot) {
					MP1bombRotation -= playerSpeed;
				}
			}
			if (MP1rotateRight) {
				MP1player.rotate(playerSpeed);
				if (!MP1shoot) {
					MP1bombRotation += playerSpeed;
				}
			}
			if (MP2rotateLeft) {
				MP2player.rotate(-playerSpeed);
				if (!MP2shoot) {
					MP2bombRotation -= playerSpeed;
				}
			}
			if (MP2rotateRight) {
				MP2player.rotate(playerSpeed);
				if (!MP2shoot) {
					MP2bombRotation += playerSpeed;
				}
			}
			// Spawn grenade
			if (MP1shots >= 15) {
				if ((MP1grenade.getPosition().x > (1920 / 4) - 250 && MP1grenade.getPosition().x < (1920 / 4) + 250 && MP1grenade.getPosition().y > (1080 / 2) - 250 && MP1grenade.getPosition().y < (1080 / 2) + 250) || MP1grenade.getPosition().x < 150 || MP1grenade.getPosition().x > 960 - 150 || MP1grenade.getPosition().y < 150 || MP1grenade.getPosition().y > 1080 - 150) {
					MP1grenade.setPosition(rand() % (1920 - 100) + 1, rand() % (1080 - 100) + 1);
				} else {
					MP1shots = 0;
					MP1pickable = true;
				}
				MP1grenade.setRotation((rand() % 360) + 1);
			}
			if (MP1bombHitbox.getGlobalBounds().intersects(MP1grenadeHitbox.getGlobalBounds()) && MP1pickable && MP1shoot) {
				MP1switchTo = true;
				MP1pickable = false;
				powerup.play();
			}
			if (MP1switchTo) {
				MP1grenade.setPosition(1920 * 2.f, 1080 * 2.f);
			}
			if (!MP1bombShoot) {
				MP1bomb.setPosition(1920 * 5.f, 1080 * 5.f);
			}
			if (!MP1bombShoot && !MP1shoot) {
				MP1grenade.setRotation(MP1bomb.getRotation());
			}
			if (MP2shots >= 15) {
				if ((MP2grenade.getPosition().x > ((1920 / 4) * 3) - 250 && MP2grenade.getPosition().x < ((1920 / 4) * 3) + 250 && MP2grenade.getPosition().y > (1080 / 2) - 250 && MP2grenade.getPosition().y < (1080 / 2) + 250) || MP2grenade.getPosition().x < 960 + 150 || MP2grenade.getPosition().x > 1920 - 150 || MP2grenade.getPosition().y < 150 || MP2grenade.getPosition().y > 1080 - 150) {
					MP2grenade.setPosition(rand() % (1920 - 100) + 1, rand() % (1080 - 100) + 1);
				}
				else {
					MP2shots = 0;
					MP2pickable = true;
				}
				MP2grenade.setRotation((rand() % 360) + 1);
			}
			if (MP2bombHitbox.getGlobalBounds().intersects(MP2grenadeHitbox.getGlobalBounds()) && MP2pickable && MP2shoot) {
				MP2switchTo = true;
				MP2pickable = false;
				powerup.play();
			}
			if (MP2switchTo) {
				MP2grenade.setPosition(1920 * 2.f, 1080 * 2.f);
			}
			if (!MP2bombShoot) {
				MP2bomb.setPosition(1920 * 5.f, 1080 * 5.f);
			}
			if (!MP2bombShoot && !MP2shoot) {
				MP2grenade.setRotation(MP2bomb.getRotation());
			}
			/*cout << "Bomb Rotation1: " << MP1bomb.getRotation() << ", Grenade Rotation1: " << MP1grenade.getRotation() << ", bombRotation1: " << MP1bombRotation << '\n';
			cout << "Bomb Rotation2: " << MP2bomb.getRotation() << ", Grenade Rotation2: " << MP2grenade.getRotation() << ", bombRotation2: " << MP2bombRotation << '\n';*/
			// Attach Hitboxes
			MP1playerHitbox.setPosition(MP1player.getPosition());
			MP1playerHitbox.setRotation(MP1player.getRotation());

			MP1bombHitbox.setPosition(MP1bomb.getPosition());
			MP1bombHitbox.setRotation(MP1bomb.getRotation());

			MP1plane1Hitbox.setPosition(MP1plane1.getPosition());
			MP1plane2Hitbox.setPosition(MP1plane2.getPosition());
			MP1plane3Hitbox.setPosition(MP1plane3.getPosition());
			MP1plane4Hitbox.setPosition(MP1plane4.getPosition());
			MP1plane5Hitbox.setPosition(MP1plane5.getPosition());
			MP1plane6Hitbox.setPosition(MP1plane6.getPosition());

			MP1grenadeHitbox.setPosition(MP1grenade.getPosition());
			MP1grenadeHitbox.setRotation(MP1grenade.getRotation());

			MP2playerHitbox.setPosition(MP2player.getPosition());
			MP2playerHitbox.setRotation(MP2player.getRotation());

			MP2bombHitbox.setPosition(MP2bomb.getPosition());
			MP2bombHitbox.setRotation(MP2bomb.getRotation());

			MP2plane1Hitbox.setPosition(MP2plane1.getPosition());
			MP2plane2Hitbox.setPosition(MP2plane2.getPosition());
			MP2plane3Hitbox.setPosition(MP2plane3.getPosition());
			MP2plane4Hitbox.setPosition(MP2plane4.getPosition());
			MP2plane5Hitbox.setPosition(MP2plane5.getPosition());
			MP2plane6Hitbox.setPosition(MP2plane6.getPosition());

			MP2grenadeHitbox.setPosition(MP2grenade.getPosition());
			MP2grenadeHitbox.setRotation(MP2grenade.getRotation());
			// Calculate Radians
			MP1bombRadians = ((2.f * PI / 360.f) * MP1bomb.getRotation());
			MP1x = bombSpeed * sin(MP1bombRadians);
			MP1y = bombSpeed * -cos(MP1bombRadians);
			MP2bombRadians = ((2.f * PI / 360.f) * MP2bomb.getRotation());
			MP2x = bombSpeed * sin(MP2bombRadians);
			MP2y = bombSpeed * -cos(MP2bombRadians);
			if (MP1shoot) {
				if (MP1bombShoot) {
					MP1bomb.move(MP1x, MP1y);
				}
				if (!MP1bombShoot) {
					MP1grenade.move(MP1x, MP1y);
				}
			}
			if (MP2shoot) {
				if (MP2bombShoot) {
					MP2bomb.move(MP2x, MP2y);
				}
				if (!MP2bombShoot) {
					MP2grenade.move(MP2x, MP2y);
				}
			}
			/*if (MP1bombRotation > 360.0f || MP1bombRotation < -360.0f) {
				MP1bombRotation = MP1bomb.getRotation();
			}
			if (MP2bombRotation > 360.0f || MP2bombRotation < -360.0f) {
				MP2bombRotation = MP2bomb.getRotation();
			}*/
			if (MP1shoot && MP1bombShoot) {
				if (MP1bomb.getPosition().x < 50.0f || MP1bombHitbox.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1bomb.getPosition().y < 50.0f || MP1bomb.getPosition().y > 1030.0f) {
					MP1shoot = false;
					MP1bombRotation = MP1player.getRotation();
					MP1bomb.setPosition(480.0f, 540.0f);
					if (MP1switchTo) {
						MP1bombShoot = false;
						MP1switchTo = false;
						MP1grenade.setPosition(480.f, 540.f);
					}
				}
			}
			if (MP1shoot && !MP1bombShoot) {
				if (MP1grenade.getPosition().x < 50.0f || MP1grenadeHitbox.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1grenade.getPosition().y < 50.0f || MP1grenade.getPosition().y > 1030.0f) {
					MP1shoot = false;
					MP1bombShoot = true;
					MP1bombRotation = MP1player.getRotation();
					MP1bomb.setPosition(1920 / 4.f, 1080 / 2.f);
					MP1grenade.setPosition(1920 * 2.f, 1080 * 2.f);
				}
			}
			if (MP2shoot && MP2bombShoot) {
				if (MP2bombHitbox.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2bomb.getPosition().x > 1870.0f || MP2bomb.getPosition().y < 50.0f || MP2bomb.getPosition().y > 1030.0f) {
					MP2shoot = false;
					MP2bombRotation = MP2player.getRotation();
					MP2bomb.setPosition(1440.0f, 540.0f);
					if (MP2switchTo) {
						MP2bombShoot = false;
						MP2switchTo = false;
						MP2grenade.setPosition(1440.f, 540.f);
					}
				}
			}
			if (MP2shoot && !MP2bombShoot) {
				if (MP2grenadeHitbox.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2grenade.getPosition().x > 1870.0f || MP2grenade.getPosition().y < 50.0f || MP2grenade.getPosition().y > 1030.0f) {
					MP2shoot = false;
					MP2bombShoot = true;
					MP2bombRotation = MP2player.getRotation();
					MP2bomb.setPosition(1440.0f, 540);
					MP2grenade.setPosition(1920 * 2.f, 1080 * 2.f);
				}
			}
			MP1bomb.setRotation(MP1bombRotation);
			MP2bomb.setRotation(MP2bombRotation);
			if (MP2plane1corner == 0 && MP2corner1 != 0) {
				MP2plane1corner = MP2corner1;
				if (MP2plane1corner == 1) {
					MP2plane1.setPosition(960 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 2) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 3) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane1corner == 4) {
					MP2plane1.setPosition(960 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane2corner == 0 && MP2corner1 != 0) {
				MP2plane2corner = MP2corner1;
				if (MP2plane2corner == 1) {
					MP2plane2.setPosition(960 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 2) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 3) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane2corner == 4) {
					MP2plane2.setPosition(960 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane3corner == 0 && MP2corner1 != 0) {
				MP2plane3corner = MP2corner1;
				if (MP2plane3corner == 1) {
					MP2plane3.setPosition(960 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 2) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 3) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane3corner == 4) {
					MP2plane3.setPosition(960 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane4corner == 0 && MP2corner2 != 0) {
				MP2plane4corner = MP2corner2;
				if (MP2plane4corner == 1) {
					MP2plane4.setPosition(960 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 2) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 3) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane4corner == 4) {
					MP2plane4.setPosition(960 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane5corner == 0 && MP2corner2 != 0) {
				MP2plane5corner = MP2corner2;
				if (MP2plane5corner == 1) {
					MP2plane5.setPosition(960 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 2) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 3) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane5corner == 4) {
					MP2plane5.setPosition(960 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane6corner == 0 && MP2corner2 != 0) {
				MP2plane6corner = MP2corner2;
				if (MP2plane6corner == 1) {
					MP2plane6.setPosition(960 + -(rand() % 400 + 1), -(rand() % 400 + 1));
				}
				if (MP2plane6corner == 2) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 1), -(rand() % 400 + 1));
				}
				if (MP2plane6corner == 3) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 1), 1160 + (rand() % 400 + 1));
				}
				if (MP2plane6corner == 4) {
					MP2plane6.setPosition(960 + -(rand() % 400 + 1), 2000 + (rand() % 400 + 1));
				}
			}
			if (MP2plane1corner == 1 && (MP2plane1.getPosition().x > 2000 || MP2plane1.getPosition().y > 1160)) {
				MP2plane1corner = MP2corner1;
				if (MP2plane1corner == 1) {
					MP2plane1.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 2) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 3) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane1corner == 4) {
					MP2plane1.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane1corner == 2 && (MP2plane1.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane1.getPosition().y > 1160)) {
				MP2plane1corner = MP2corner1;
				if (MP2plane1corner == 1) {
					MP2plane1.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 2) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 3) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane1corner == 4) {
					MP2plane1.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane1corner == 3 && (MP2plane1.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane1.getPosition().y < 0)) {
				MP2plane1corner = MP2corner1;
				if (MP2plane1corner == 1) {
					MP2plane1.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 2) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 3) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane1corner == 4) {
					MP2plane1.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane1corner == 4 && (MP2plane1.getPosition().x > 2000 || MP2plane1.getPosition().y < 0)) {
				MP2plane1corner = MP2corner1;
				if (MP2plane1corner == 1) {
					MP2plane1.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 2) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 3) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane1corner == 4) {
					MP2plane1.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane1corner != MP2corner1) {
				if (MP2plane1corner == 1 && (MP2plane1.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane1.getPosition().y < 0)) {
					MP2plane1corner = MP2corner1;
					if (MP2plane1corner == 1) {
						MP2plane1.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane1corner == 2) {
						MP2plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane1corner == 3) {
						MP2plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane1corner == 4) {
						MP2plane1.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane1corner == 2 && (MP2plane1.getPosition().x > 2000 || MP2plane1.getPosition().y < 0)) {
					MP2plane1corner = MP2corner1;
					if (MP2plane1corner == 1) {
						MP2plane1.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane1corner == 2) {
						MP2plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane1corner == 3) {
						MP2plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane1corner == 4) {
						MP2plane1.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane1corner == 3 && (MP2plane1.getPosition().x > 2000 || MP2plane1.getPosition().y > 1160)) {
					MP2plane1corner = MP2corner1;
					if (MP2plane1corner == 1) {
						MP2plane1.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane1corner == 2) {
						MP2plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane1corner == 3) {
						MP2plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane1corner == 4) {
						MP2plane1.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane1corner == 4 && (MP2plane1.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane1.getPosition().y > 1160)) {
					MP2plane1corner = MP2corner1;
					if (MP2plane1corner == 1) {
						MP2plane1.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane1corner == 2) {
						MP2plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane1corner == 3) {
						MP2plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane1corner == 4) {
						MP2plane1.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (MP2plane1Hitbox.getGlobalBounds().intersects(MP2grenadeHitbox.getGlobalBounds()) && MP2shoot && !MP2bombShoot) {
				MP2plane1corner = MP2corner1;
				MP2plane1Death = true;
				MP2deathEffect1.setPosition(MP2plane1.getPosition());
				MP2explosion.setPosition(MP2plane1.getPosition());
				MP2explosionBool = true;
				MP2grenade.setPosition(3840.f, 2160.f);
				grenadeExplosion.play();
				if (MP2plane1corner == 1) {
					MP2plane1.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 2) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 3) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane1corner == 4) {
					MP2plane1.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane1Hitbox.getGlobalBounds().intersects(MP2bombHitbox.getGlobalBounds()) && MP2shoot) {
				MP2score += 10;
				MP2plane1corner = MP2corner1;
				MP2plane1Death = true;
				MP2deathEffect1.setPosition(MP2plane1.getPosition());
				if (MP2plane1corner == 1) {
					MP2plane1.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 2) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 3) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane1corner == 4) {
					MP2plane1.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP2plane1Hitbox.getGlobalBounds().intersects(MP2explosion.getGlobalBounds())) {
				MP2score += 10;
				MP2plane1corner = MP2corner1;
				MP2plane1Death = true;
				MP2deathEffect1.setPosition(MP2plane1.getPosition());
				if (MP2plane1corner == 1) {
					MP2plane1.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 1));
				}
				if (MP2plane1corner == 2) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane1corner == 3) {
					MP2plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane1corner == 4) {
					MP2plane1.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP2plane2corner == 1 && (MP2plane2.getPosition().x < 2000 || MP2plane2.getPosition().y > 1160)) {
				MP2plane2corner = MP2corner1;
				if (MP2plane2corner == 1) {
					MP2plane2.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 2) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 3) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane2corner == 4) {
					MP2plane2.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (MP2plane2corner == 2 && (MP2plane2.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane2.getPosition().y > 1160)) {
				MP2plane2corner = MP2corner1;
				if (MP2plane2corner == 1) {
					MP2plane2.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 2) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 3) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane2corner == 4) {
					MP2plane2.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane2corner == 3 && (MP2plane2.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane2.getPosition().y < 0)) {
				MP2plane2corner = MP2corner1;
				if (MP2plane2corner == 1) {
					MP2plane2.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 2) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 3) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane2corner == 4) {
					MP2plane2.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane2corner == 4 && (MP2plane2.getPosition().x < 2000 || MP2plane2.getPosition().y < 0)) {
				MP2plane2corner = MP2corner1;
				if (MP2plane2corner == 1) {
					MP2plane2.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 2) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 3) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane2corner == 4) {
					MP2plane2.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane2corner != MP2corner1) {
				if (MP2plane2corner == 1 && (MP2plane2.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane2.getPosition().y < 0)) {
					MP2plane2corner = MP2corner1;
					if (MP2plane2corner == 1) {
						MP2plane2.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane2corner == 2) {
						MP2plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane2corner == 3) {
						MP2plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane2corner == 4) {
						MP2plane2.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane2corner == 2 && (MP2plane2.getPosition().x < 2000 || MP2plane2.getPosition().y < 0)) {
					MP2plane2corner = MP2corner1;
					if (MP2plane2corner == 1) {
						MP2plane2.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane2corner == 2) {
						MP2plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane2corner == 3) {
						MP2plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane2corner == 4) {
						MP2plane2.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane2corner == 3 && (MP2plane2.getPosition().x < 2000 || MP2plane2.getPosition().y > 1160)) {
					MP2plane2corner = MP2corner1;
					if (MP2plane2corner == 1) {
						MP2plane2.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane2corner == 2) {
						MP2plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane2corner == 3) {
						MP2plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane2corner == 4) {
						MP2plane2.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane2corner == 4 && (MP2plane2.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane2.getPosition().y > 1160)) {
					MP2plane2corner = MP2corner1;
					if (MP2plane2corner == 1) {
						MP2plane2.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane2corner == 2) {
						MP2plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane2corner == 3) {
						MP2plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane2corner == 4) {
						MP2plane2.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (MP2plane2Hitbox.getGlobalBounds().intersects(MP2grenadeHitbox.getGlobalBounds()) && MP2shoot && !MP2bombShoot) {
				MP2plane2corner = MP2corner1;
				MP2plane2Death = true;
				MP2deathEffect2.setPosition(MP2plane2.getPosition());
				MP2explosion.setPosition(MP2plane2.getPosition());
				MP2explosionBool = true;
				MP2grenade.setPosition(3840.f, 2160.f);
				grenadeExplosion.play();
				if (MP2plane2corner == 1) {
					MP2plane2.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 2) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 3) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane2corner == 4) {
					MP2plane2.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (MP2plane2Hitbox.getGlobalBounds().intersects(MP2bombHitbox.getGlobalBounds()) && MP2shoot) {
				MP2score += 10;
				MP2plane2corner = MP2corner1;
				MP2plane2Death = true;
				MP2deathEffect2.setPosition(MP2plane2.getPosition());
				if (MP2plane2corner == 1) {
					MP2plane2.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 2) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 3) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane2corner == 4) {
					MP2plane2.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP2plane2Hitbox.getGlobalBounds().intersects(MP2explosion.getGlobalBounds())) {
				MP2score += 10;
				MP2plane2corner = MP2corner1;
				MP2plane2Death = true;
				MP2deathEffect2.setPosition(MP2plane2.getPosition());
				if (MP2plane2corner == 1) {
					MP2plane2.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 2) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane2corner == 3) {
					MP2plane2.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane2corner == 4) {
					MP2plane2.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP2plane3corner == 1 && (MP2plane3.getPosition().x <-80|| MP2plane3.getPosition().y > 1160)) {
				MP2plane3corner = MP2corner1;
				if (MP2plane3corner == 1) {
					MP2plane3.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 2) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 3) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane3corner == 4) {
					MP2plane3.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (MP2plane3corner == 2 && (MP2plane3.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane3.getPosition().y > 1160)) {
				MP2plane3corner = MP2corner1;
				if (MP2plane3corner == 1) {
					MP2plane3.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 2) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 3) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane3corner == 4) {
					MP2plane3.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane3corner == 3 && (MP2plane3.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane3.getPosition().y < 0)) {
				MP2plane3corner = MP2corner1;
				if (MP2plane3corner == 1) {
					MP2plane3.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 2) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 3) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane3corner == 4) {
					MP2plane3.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane3corner == 4 && (MP2plane3.getPosition().x <-80|| MP2plane3.getPosition().y < 0)) {
				MP2plane3corner = MP2corner1;
				if (MP2plane3corner == 1) {
					MP2plane3.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 2) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 3) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane3corner == 4) {
					MP2plane3.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane3corner != MP2corner1) {
				if (MP2plane3corner == 1 && (MP2plane3.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane3.getPosition().y < 0)) {
					MP2plane3corner = MP2corner1;
					if (MP2plane3corner == 1) {
						MP2plane3.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane3corner == 2) {
						MP2plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane3corner == 3) {
						MP2plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane3corner == 4) {
						MP2plane3.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane3corner == 2 && (MP2plane3.getPosition().x <-80|| MP2plane3.getPosition().y < 0)) {
					MP2plane3corner = MP2corner1;
					if (MP2plane3corner == 1) {
						MP2plane3.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane3corner == 2) {
						MP2plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane3corner == 3) {
						MP2plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane3corner == 4) {
						MP2plane3.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane3corner == 3 && (MP2plane3.getPosition().x <-80|| MP2plane3.getPosition().y > 1160)) {
					MP2plane3corner = MP2corner1;
					if (MP2plane3corner == 1) {
						MP2plane3.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane3corner == 2) {
						MP2plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane3corner == 3) {
						MP2plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane3corner == 4) {
						MP2plane3.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane3corner == 4 && (MP2plane3.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane3.getPosition().y > 1160)) {
					MP2plane3corner = MP2corner1;
					if (MP2plane3corner == 1) {
						MP2plane3.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane3corner == 2) {
						MP2plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane3corner == 3) {
						MP2plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane3corner == 4) {
						MP2plane3.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (MP2plane3Hitbox.getGlobalBounds().intersects(MP2grenadeHitbox.getGlobalBounds()) && MP2shoot && !MP2bombShoot) {
				MP2plane3corner = MP2corner1;
				MP2plane3Death = true;
				MP2deathEffect3.setPosition(MP2plane3.getPosition());
				MP2explosion.setPosition(MP2plane3.getPosition());
				MP2explosionBool = true;
				MP2grenade.setPosition(3840.f, 2160.f);
				grenadeExplosion.play();
				if (MP2plane3corner == 1) {
					MP2plane3.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 2) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 3) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane3corner == 4) {
					MP2plane3.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (MP2plane3Hitbox.getGlobalBounds().intersects(MP2bombHitbox.getGlobalBounds()) && MP2shoot) {
				MP2score += 10;
				MP2plane3Death = true;
				MP2deathEffect3.setPosition(MP2plane3.getPosition());
				MP2plane3corner = MP2corner1;
				if (MP2plane3corner == 1) {
					MP2plane3.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 2) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 3) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane3corner == 4) {
					MP2plane3.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP2plane3Hitbox.getGlobalBounds().intersects(MP2explosion.getGlobalBounds())) {
				MP2score += 10;
				MP2plane3corner = MP2corner1;
				MP2plane3Death = true;
				MP2deathEffect3.setPosition(MP2plane3.getPosition());
				if (MP2plane3corner == 1) {
					MP2plane3.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 2) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane3corner == 3) {
					MP2plane3.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane3corner == 4) {
					MP2plane3.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP2plane4corner == 1 && (MP2plane4.getPosition().x <-80|| MP2plane4.getPosition().y > 1160)) {
				MP2plane4corner = MP2corner2;
				if (MP2plane4corner == 1) {
					MP2plane4.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 2) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 3) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane4corner == 4) {
					MP2plane4.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (MP2plane4corner == 2 && (MP2plane4.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane4.getPosition().y > 1160)) {
				MP2plane4corner = MP2corner2;
				if (MP2plane4corner == 1) {
					MP2plane4.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 2) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 3) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane4corner == 4) {
					MP2plane4.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane4corner == 3 && (MP2plane4.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane4.getPosition().y < 0)) {
				MP2plane4corner = MP2corner2;
				if (MP2plane4corner == 1) {
					MP2plane4.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 2) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 3) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane4corner == 4) {
					MP2plane4.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane4corner == 4 && (MP2plane4.getPosition().x <-80|| MP2plane4.getPosition().y < 0)) {
				MP2plane4corner = MP2corner2;
				if (MP2plane4corner == 1) {
					MP2plane4.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 2) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 3) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane4corner == 4) {
					MP2plane4.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane4corner != MP2corner2) {
				if (MP2plane4corner == 1 && (MP2plane4.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane4.getPosition().y < 0)) {
					MP2plane4corner = MP2corner2;
					if (MP2plane4corner == 1) {
						MP2plane4.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane4corner == 2) {
						MP2plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane4corner == 3) {
						MP2plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane4corner == 4) {
						MP2plane4.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane4corner == 2 && (MP2plane4.getPosition().x <-80|| MP2plane4.getPosition().y < 0)) {
					MP2plane4corner = MP2corner2;
					if (MP2plane4corner == 1) {
						MP2plane4.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane4corner == 2) {
						MP2plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane4corner == 3) {
						MP2plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane4corner == 4) {
						MP2plane4.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane4corner == 3 && (MP2plane4.getPosition().x <-80|| MP2plane4.getPosition().y > 1160)) {
					MP2plane4corner = MP2corner2;
					if (MP2plane4corner == 1) {
						MP2plane4.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane4corner == 2) {
						MP2plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane4corner == 3) {
						MP2plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane4corner == 4) {
						MP2plane4.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane4corner == 4 && (MP2plane4.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane4.getPosition().y > 1160)) {
					MP2plane4corner = MP2corner2;
					if (MP2plane4corner == 1) {
						MP2plane4.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane4corner == 2) {
						MP2plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane4corner == 3) {
						MP2plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane4corner == 4) {
						MP2plane4.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (MP2plane4Hitbox.getGlobalBounds().intersects(MP2grenadeHitbox.getGlobalBounds()) && MP2shoot && !MP2bombShoot) {
				MP2plane4corner = MP2corner2;
				MP2plane4Death = true;
				MP2deathEffect4.setPosition(MP2plane4.getPosition());
				MP2explosion.setPosition(MP2plane4.getPosition());
				MP2explosionBool = true;
				MP2grenade.setPosition(3840.f, 2160.f);
				grenadeExplosion.play();
				if (MP2plane4corner == 1) {
					MP2plane4.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 2) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 3) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane4corner == 4) {
					MP2plane4.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (MP2plane4Hitbox.getGlobalBounds().intersects(MP2bombHitbox.getGlobalBounds()) && MP2shoot) {
				MP2score += 10;
				MP2plane4corner = MP2corner2;
				MP2plane4Death = true;
				MP2deathEffect4.setPosition(MP2plane4.getPosition());
				if (MP2plane4corner == 1) {
					MP2plane4.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 2) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 3) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane4corner == 4) {
					MP2plane4.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP2plane4Hitbox.getGlobalBounds().intersects(MP2explosion.getGlobalBounds())) {
				MP2score += 10;
				MP2plane4corner = MP2corner2;
				MP2plane4Death = true;
				MP2deathEffect4.setPosition(MP2plane4.getPosition());
				if (MP2plane4corner == 1) {
					MP2plane4.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 2) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane4corner == 3) {
					MP2plane4.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane4corner == 4) {
					MP2plane4.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP2plane5corner == 1 && (MP2plane5.getPosition().x <-80|| MP2plane5.getPosition().y > 1160)) {
				MP2plane5corner = MP2corner2;
				if (MP2plane5corner == 1) {
					MP2plane5.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 2) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 3) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane5corner == 4) {
					MP2plane5.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (MP2plane5corner == 2 && (MP2plane5.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane5.getPosition().y > 1160)) {
				MP2plane5corner = MP2corner2;
				if (MP2plane5corner == 1) {
					MP2plane5.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 2) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 3) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane5corner == 4) {
					MP2plane5.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane5corner == 3 && (MP2plane5.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane5.getPosition().y < 0)) {
				MP2plane5corner = MP2corner2;
				if (MP2plane5corner == 1) {
					MP2plane5.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 2) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 3) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane5corner == 4) {
					MP2plane5.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane5corner == 4 && (MP2plane5.getPosition().x <-80|| MP2plane5.getPosition().y < 0)) {
				MP2plane5corner = MP2corner2;
				if (MP2plane5corner == 1) {
					MP2plane5.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 2) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 3) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane5corner == 4) {
					MP2plane5.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane5corner != MP2corner2) {
				if (MP2plane5corner == 1 && (MP2plane5.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane5.getPosition().y < 0)) {
					MP2plane5corner = MP2corner2;
					if (MP2plane5corner == 1) {
						MP2plane5.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane5corner == 2) {
						MP2plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane5corner == 3) {
						MP2plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane5corner == 4) {
						MP2plane5.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane5corner == 2 && (MP2plane5.getPosition().x <-80|| MP2plane5.getPosition().y < 0)) {
					MP2plane5corner = MP2corner2;
					if (MP2plane5corner == 1) {
						MP2plane5.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane5corner == 2) {
						MP2plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane5corner == 3) {
						MP2plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane5corner == 4) {
						MP2plane5.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane5corner == 3 && (MP2plane5.getPosition().x <-80|| MP2plane5.getPosition().y > 1160)) {
					MP2plane5corner = MP2corner2;
					if (MP2plane5corner == 1) {
						MP2plane5.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane5corner == 2) {
						MP2plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane5corner == 3) {
						MP2plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane5corner == 4) {
						MP2plane5.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane5corner == 4 && (MP2plane5.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane5.getPosition().y > 1160)) {
					MP2plane5corner = MP2corner2;
					if (MP2plane5corner == 1) {
						MP2plane5.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane5corner == 2) {
						MP2plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane5corner == 3) {
						MP2plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane5corner == 4) {
						MP2plane5.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (MP2plane5Hitbox.getGlobalBounds().intersects(MP2grenadeHitbox.getGlobalBounds()) && MP2shoot && !MP2bombShoot) {
				MP2plane5corner = MP2corner2;
				MP2plane5Death = true;
				MP2deathEffect5.setPosition(MP2plane5.getPosition());
				MP2explosion.setPosition(MP2plane5.getPosition());
				MP2explosionBool = true;
				MP2grenade.setPosition(3840.f, 2160.f);
				grenadeExplosion.play();
				if (MP2plane5corner == 1) {
					MP2plane5.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 2) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 3) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane5corner == 4) {
					MP2plane5.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (MP2plane5Hitbox.getGlobalBounds().intersects(MP2bombHitbox.getGlobalBounds()) && MP2shoot) {
				MP2score += 10;
				MP2plane5corner = MP2corner2;
				MP2plane5Death = true;
				MP2deathEffect5.setPosition(MP2plane5.getPosition());
				if (MP2plane5corner == 1) {
					MP2plane5.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 2) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 3) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane5corner == 4) {
					MP2plane5.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP2plane5Hitbox.getGlobalBounds().intersects(MP2explosion.getGlobalBounds())) {
				MP2score += 10;
				MP2plane5corner = MP2corner2;
				MP2plane5Death = true;
				MP2deathEffect5.setPosition(MP2plane5.getPosition());
				if (MP2plane5corner == 1) {
					MP2plane5.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 2) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane5corner == 3) {
					MP2plane5.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane5corner == 4) {
					MP2plane5.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP2plane6corner == 1 && (MP2plane6.getPosition().x <-80|| MP2plane6.getPosition().y > 1160)) {
				MP2plane6corner = MP2corner2;
				if (MP2plane6corner == 1) {
					MP2plane6.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane6corner == 2) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane6corner == 3) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane6corner == 4) {
					MP2plane6.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (MP2plane6corner == 2 && (MP2plane6.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane6.getPosition().y > 1160)) {
				MP2plane6corner = MP2corner2;
				if (MP2plane6corner == 1) {
					MP2plane6.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane6corner == 2) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane6corner == 3) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane6corner == 4) {
					MP2plane6.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane6corner == 3 && (MP2plane6.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane6.getPosition().y < 0)) {
				MP2plane6corner = MP2corner2;
				if (MP2plane6corner == 1) {
					MP2plane6.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane6corner == 2) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane6corner == 3) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane6corner == 4) {
					MP2plane6.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane6corner == 4 && (MP2plane6.getPosition().x <-80|| MP2plane6.getPosition().y < 0)) {
				MP2plane6corner = MP2corner2;
				if (MP2plane6corner == 1) {
					MP2plane6.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane6corner == 2) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane6corner == 3) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP2plane6corner == 4) {
					MP2plane6.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP2plane6corner != MP2corner2) {
				if (MP2plane6corner == 1 && (MP2plane6.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane6.getPosition().y < 0)) {
					MP2plane6corner = MP2corner2;
					if (MP2plane6corner == 1) {
						MP2plane6.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane6corner == 2) {
						MP2plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane6corner == 3) {
						MP2plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane6corner == 4) {
						MP2plane6.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane6corner == 2 && (MP2plane6.getPosition().x <-80|| MP2plane6.getPosition().y < 0)) {
					MP2plane6corner = MP2corner2;
					if (MP2plane6corner == 1) {
						MP2plane6.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane6corner == 2) {
						MP2plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane6corner == 3) {
						MP2plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane6corner == 4) {
						MP2plane6.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane6corner == 3 && (MP2plane6.getPosition().x <-80|| MP2plane6.getPosition().y > 1160)) {
					MP2plane6corner = MP2corner2;
					if (MP2plane6corner == 1) {
						MP2plane6.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane6corner == 2) {
						MP2plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane6corner == 3) {
						MP2plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane6corner == 4) {
						MP2plane6.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP2plane6corner == 4 && (MP2plane6.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP2plane6.getPosition().y > 1160)) {
					MP2plane6corner = MP2corner2;
					if (MP2plane6corner == 1) {
						MP2plane6.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane6corner == 2) {
						MP2plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP2plane6corner == 3) {
						MP2plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP2plane6corner == 4) {
						MP2plane6.setPosition(880 + -(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (MP2plane6Hitbox.getGlobalBounds().intersects(grenadeHitbox.getGlobalBounds()) && MP2shoot && !MP2bombShoot) {
				MP2plane6corner = MP2corner2;
				MP2plane6Death = true;
				MP2deathEffect6.setPosition(MP2plane6.getPosition());
				MP2explosion.setPosition(MP2plane6.getPosition());
				MP2explosionBool = true;
				MP2grenade.setPosition(3840.f, 2160.f);
				grenadeExplosion.play();
				if (MP2plane6corner == 1) {
					MP2plane6.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane6corner == 2) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane6corner == 3) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane6corner == 4) {
					MP2plane6.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (MP2plane6Hitbox.getGlobalBounds().intersects(MP2bombHitbox.getGlobalBounds()) && MP2shoot) {
				MP2score += 10;
				MP2plane6corner = MP2corner2;
				MP2plane6Death = true;
				MP2deathEffect6.setPosition(MP2plane6.getPosition());
				if (MP2plane6corner == 1) {
					MP2plane6.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane6corner == 2) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane6corner == 3) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane6corner == 4) {
					MP2plane6.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP2plane6Hitbox.getGlobalBounds().intersects(MP2explosion.getGlobalBounds())) {
				MP2score += 10;
				MP2plane6corner = MP2corner2;
				MP2plane6Death = true;
				MP2deathEffect6.setPosition(MP2plane6.getPosition());
				if (MP2plane6corner == 1) {
					MP2plane6.setPosition(880 + -(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane6corner == 2) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP2plane6corner == 3) {
					MP2plane6.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (MP2plane6corner == 4) {
					MP2plane6.setPosition(880 + -(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			switch (MP2plane1corner) {
			case 0:
				MP2plane1.setPosition(2000 * 4.f, 1160 * 4.f);
				break;
			case 1:
				MP2plane1.move(planeSpeed, planeSpeed);
				MP2plane1.setRotation(135);
				break;
			case 2:
				MP2plane1.move(-planeSpeed, planeSpeed);
				MP2plane1.setRotation(225);
				break;
			case 3:
				MP2plane1.move(-planeSpeed, -planeSpeed);
				MP2plane1.setRotation(315);
				break;
			case 4:
				MP2plane1.move(planeSpeed, -planeSpeed);
				MP2plane1.setRotation(45);
				break;
			}
			switch (MP2plane2corner) {
			case 0:
				MP2plane2.setPosition(2000 * 4.f, 1160 * 4.f);
				break;
			case 1:
				MP2plane2.move(planeSpeed, planeSpeed);
				MP2plane2.setRotation(135);
				break;
			case 2:
				MP2plane2.move(-planeSpeed, planeSpeed);
				MP2plane2.setRotation(225);
				break;
			case 3:
				MP2plane2.move(-planeSpeed, -planeSpeed);
				MP2plane2.setRotation(315);
				break;
			case 4:
				MP2plane2.move(planeSpeed, -planeSpeed);
				MP2plane2.setRotation(45);
				break;
			}
			switch (MP2plane3corner) {
			case 0:
				MP2plane3.setPosition(2000 * 4.f, 1160 * 4.f);
				break;
			case 1:
				MP2plane3.move(planeSpeed, planeSpeed);
				MP2plane3.setRotation(135);
				break;
			case 2:
				MP2plane3.move(-planeSpeed, planeSpeed);
				MP2plane3.setRotation(225);
				break;
			case 3:
				MP2plane3.move(-planeSpeed, -planeSpeed);
				MP2plane3.setRotation(315);
				break;
			case 4:
				MP2plane3.move(planeSpeed, -planeSpeed);
				MP2plane3.setRotation(45);
				break;
			}
			switch (MP2plane4corner) {
			case 0:
				MP2plane4.setPosition(2000 * 4.f, 1160 * 4.f);
				break;
			case 1:
				MP2plane4.move(planeSpeed2, planeSpeed2);
				MP2plane4.setRotation(135);
				break;
			case 2:
				MP2plane4.move(-planeSpeed2, planeSpeed2);
				MP2plane4.setRotation(225);
				break;
			case 3:
				MP2plane4.move(-planeSpeed2, -planeSpeed2);
				MP2plane4.setRotation(315);
				break;
			case 4:
				MP2plane4.move(planeSpeed2, -planeSpeed2);
				MP2plane4.setRotation(45);
				break;
			}
			switch (MP2plane5corner) {
			case 0:
				MP2plane5.setPosition(2000 * 4.f, 1160 * 4.f);
				break;
			case 1:
				MP2plane5.move(planeSpeed2, planeSpeed2);
				MP2plane5.setRotation(135);
				break;
			case 2:
				MP2plane5.move(-planeSpeed2, planeSpeed2);
				MP2plane5.setRotation(225);
				break;
			case 3:
				MP2plane5.move(-planeSpeed2, -planeSpeed2);
				MP2plane5.setRotation(315);
				break;
			case 4:
				MP2plane5.move(planeSpeed2, -planeSpeed2);
				MP2plane5.setRotation(45);
				break;
			}
			switch (MP2plane6corner) {
			case 0:
				MP2plane6.setPosition(2000 * 4.f, 1160 * 4.f);
				break;
			case 1:
				MP2plane6.move(planeSpeed2, planeSpeed2);
				MP2plane6.setRotation(135);
				break;
			case 2:
				MP2plane6.move(-planeSpeed2, planeSpeed2);
				MP2plane6.setRotation(225);
				break;
			case 3:
				MP2plane6.move(-planeSpeed2, -planeSpeed2);
				MP2plane6.setRotation(315);
				break;
			case 4:
				MP2plane6.move(planeSpeed2, -planeSpeed2);
				MP2plane6.setRotation(45);
				break;
			}

			if (MP1plane1corner == 0 && MP1corner1 != 0) {
				MP1plane1corner = MP1corner1;
				if (MP1plane1corner == 1) {
					MP1plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 2) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 3) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane1corner == 4) {
					MP1plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane2corner == 0 && MP1corner1 != 0) {
				MP1plane2corner = MP1corner1;
				if (MP1plane2corner == 1) {
					MP1plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 2) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 3) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane2corner == 4) {
					MP1plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane3corner == 0 && MP1corner1 != 0) {
				MP1plane3corner = MP1corner1;
				if (MP1plane3corner == 1) {
					MP1plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 2) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 3) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane3corner == 4) {
					MP1plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane4corner == 0 && MP1corner2 != 0) {
				MP1plane4corner = MP1corner2;
				if (MP1plane4corner == 1) {
					MP1plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 2) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 3) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane4corner == 4) {
					MP1plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane5corner == 0 && MP1corner2 != 0) {
				MP1plane5corner = MP1corner2;
				if (MP1plane5corner == 1) {
					MP1plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 2) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 3) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane5corner == 4) {
					MP1plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane6corner == 0 && MP1corner2 != 0) {
				MP1plane6corner = MP1corner2;
				if (MP1plane6corner == 1) {
					MP1plane6.setPosition(-(rand() % 400 + 1), -(rand() % 400 + 1));
				}
				if (MP1plane6corner == 2) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 1), -(rand() % 400 + 1));
				}
				if (MP1plane6corner == 3) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 1), 1160 + (rand() % 400 + 1));
				}
				if (MP1plane6corner == 4) {
					MP1plane6.setPosition(-(rand() % 400 + 1), 1140 + (rand() % 400 + 1));
				}
			}
			if (MP1plane1corner == 1 && (MP1plane1.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane1.getPosition().y > 1160)) {
				MP1plane1corner = MP1corner1;
				if (MP1plane1corner == 1) {
					MP1plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 2) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 3) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane1corner == 4) {
					MP1plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane1corner == 2 && (MP1plane1.getPosition().x <-80|| MP1plane1.getPosition().y > 1160)) {
				MP1plane1corner = MP1corner1;
				if (MP1plane1corner == 1) {
					MP1plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 2) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 3) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane1corner == 4) {
					MP1plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane1corner == 3 && (MP1plane1.getPosition().x <-80|| MP1plane1.getPosition().y < 0)) {
				MP1plane1corner = MP1corner1;
				if (MP1plane1corner == 1) {
					MP1plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 2) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 3) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane1corner == 4) {
					MP1plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane1corner == 4 && (MP1plane1.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane1.getPosition().y < 0)) {
				MP1plane1corner = MP1corner1;
				if (MP1plane1corner == 1) {
					MP1plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 2) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 3) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane1corner == 4) {
					MP1plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane1corner != MP1corner1) {
				if (MP1plane1corner == 1 && (MP1plane1.getPosition().x <-80|| MP1plane1.getPosition().y < 0)) {
					MP1plane1corner = MP1corner1;
					if (MP1plane1corner == 1) {
						MP1plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane1corner == 2) {
						MP1plane1.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane1corner == 3) {
						MP1plane1.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane1corner == 4) {
						MP1plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane1corner == 2 && (MP1plane1.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane1.getPosition().y < 0)) {
					MP1plane1corner = MP1corner1;
					if (MP1plane1corner == 1) {
						MP1plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane1corner == 2) {
						MP1plane1.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane1corner == 3) {
						MP1plane1.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane1corner == 4) {
						MP1plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane1corner == 3 && (MP1plane1.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane1.getPosition().y > 1160)) {
					MP1plane1corner = MP1corner1;
					if (MP1plane1corner == 1) {
						MP1plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane1corner == 2) {
						MP1plane1.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane1corner == 3) {
						MP1plane1.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane1corner == 4) {
						MP1plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane1corner == 4 && (MP1plane1.getPosition().x <-80|| MP1plane1.getPosition().y > 1160)) {
					MP1plane1corner = MP1corner1;
					if (MP1plane1corner == 1) {
						MP1plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane1corner == 2) {
						MP1plane1.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane1corner == 3) {
						MP1plane1.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane1corner == 4) {
						MP1plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (MP1plane1Hitbox.getGlobalBounds().intersects(MP1grenadeHitbox.getGlobalBounds()) && MP1shoot && !MP1bombShoot) {
				MP1plane1corner = MP1corner1;
				MP1plane1Death = true;
				MP1deathEffect1.setPosition(MP1plane1.getPosition());
				MP1explosion.setPosition(MP1plane1.getPosition());
				MP1explosionBool = true;
				MP1grenade.setPosition(3840.f, 2160.f);
				grenadeExplosion.play();
				if (MP1plane1corner == 1) {
					MP1plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 2) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 3) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane1corner == 4) {
					MP1plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane1Hitbox.getGlobalBounds().intersects(MP1bombHitbox.getGlobalBounds()) && MP1shoot) {
				MP1score += 10;
				MP1plane1corner = MP1corner1;
				MP1plane1Death = true;
				MP1deathEffect1.setPosition(MP1plane1.getPosition());
				if (MP1plane1corner == 1) {
					MP1plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 2) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 3) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane1corner == 4) {
					MP1plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP1plane1Hitbox.getGlobalBounds().intersects(MP1explosion.getGlobalBounds())) {
				MP1score += 10;
				MP1plane1corner = MP1corner1;
				MP1plane1Death = true;
				MP1deathEffect1.setPosition(MP1plane1.getPosition());
				if (MP1plane1corner == 1) {
					MP1plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 1));
				}
				if (MP1plane1corner == 2) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane1corner == 3) {
					MP1plane1.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane1corner == 4) {
					MP1plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP1plane2corner == 1 && (MP1plane2.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane2.getPosition().y > 1160)) {
				MP1plane2corner = MP1corner1;
				if (MP1plane2corner == 1) {
					MP1plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 2) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 3) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane2corner == 4) {
					MP1plane2.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
			}
			if (MP1plane2corner == 2 && (MP1plane2.getPosition().x <-80|| MP1plane2.getPosition().y > 1160)) {
				MP1plane2corner = MP1corner1;
				if (MP1plane2corner == 1) {
					MP1plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 2) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 3) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane2corner == 4) {
					MP1plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane2corner == 3 && (MP1plane2.getPosition().x <-80|| MP1plane2.getPosition().y < 0)) {
				MP1plane2corner = MP1corner1;
				if (MP1plane2corner == 1) {
					MP1plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 2) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 3) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane2corner == 4) {
					MP1plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane2corner == 4 && (MP1plane2.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane2.getPosition().y < 0)) {
				MP1plane2corner = MP1corner1;
				if (MP1plane2corner == 1) {
					MP1plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 2) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 3) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane2corner == 4) {
					MP1plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane2corner != MP1corner1) {
				if (MP1plane2corner == 1 && (MP1plane2.getPosition().x <-80|| MP1plane2.getPosition().y < 0)) {
					MP1plane2corner = MP1corner1;
					if (MP1plane2corner == 1) {
						MP1plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane2corner == 2) {
						MP1plane2.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane2corner == 3) {
						MP1plane2.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane2corner == 4) {
						MP1plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane2corner == 2 && (MP1plane2.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane2.getPosition().y < 0)) {
					MP1plane2corner = MP1corner1;
					if (MP1plane2corner == 1) {
						MP1plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane2corner == 2) {
						MP1plane2.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane2corner == 3) {
						MP1plane2.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane2corner == 4) {
						MP1plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane2corner == 3 && (MP1plane2.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane2.getPosition().y > 1160)) {
					MP1plane2corner = MP1corner1;
					if (MP1plane2corner == 1) {
						MP1plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
				}
			}
			if (MP1plane2Hitbox.getGlobalBounds().intersects(MP1grenadeHitbox.getGlobalBounds()) && MP1shoot && !MP1bombShoot) {
				MP1plane2corner = MP1corner1;
				MP1plane2Death = true;
				MP1deathEffect2.setPosition(MP1plane2.getPosition());
				MP1explosion.setPosition(MP1plane2.getPosition());
				MP1explosionBool = true;
				MP1grenade.setPosition(3840.f, 2160.f);
				grenadeExplosion.play();
				if (MP1plane2corner == 1) {
					MP1plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 2) {
					if (MP1plane2corner == 2) {
						MP1plane2.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane2corner == 3) {
						MP1plane2.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane2corner == 4) {
						MP1plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane2corner == 4 && (MP1plane2.getPosition().x <-80|| MP1plane2.getPosition().y > 1160)) {
					MP1plane2corner = MP1corner1;
					if (MP1plane2corner == 1) {
						MP1plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane2corner == 2) {
						MP1plane2.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane2corner == 3) {
						MP1plane2.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane2corner == 4) {
						MP1plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 3) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane2corner == 4) {
					MP1plane2.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
			}
			if (MP1plane2Hitbox.getGlobalBounds().intersects(MP1bombHitbox.getGlobalBounds()) && MP1shoot) {
				MP1score += 10;
				MP1plane2corner = MP1corner1;
				MP1plane2Death = true;
				MP1deathEffect2.setPosition(MP1plane2.getPosition());
				if (MP1plane2corner == 1) {
					MP1plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 2) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 3) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane2corner == 4) {
					MP1plane2.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP1plane2Hitbox.getGlobalBounds().intersects(MP1explosion.getGlobalBounds())) {
				MP1score += 10;
				MP1plane2corner = MP1corner1;
				MP1plane2Death = true;
				MP1deathEffect2.setPosition(MP1plane2.getPosition());
				if (MP1plane2corner == 1) {
					MP1plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 2) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane2corner == 3) {
					MP1plane2.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane2corner == 4) {
					MP1plane2.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP1plane3corner == 1 && (MP1plane3.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane3.getPosition().y > 1160)) {
				MP1plane3corner = MP1corner1;
				if (MP1plane3corner == 1) {
					MP1plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 2) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 3) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane3corner == 4) {
					MP1plane3.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
			}
			if (MP1plane3corner == 2 && (MP1plane3.getPosition().x <-80|| MP1plane3.getPosition().y > 1160)) {
				MP1plane3corner = MP1corner1;
				if (MP1plane3corner == 1) {
					MP1plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 2) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 3) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane3corner == 4) {
					MP1plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane3corner == 3 && (MP1plane3.getPosition().x <-80|| MP1plane3.getPosition().y < 0)) {
				MP1plane3corner = MP1corner1;
				if (MP1plane3corner == 1) {
					MP1plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 2) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 3) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane3corner == 4) {
					MP1plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane3corner == 4 && (MP1plane3.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane3.getPosition().y < 0)) {
				MP1plane3corner = MP1corner1;
				if (MP1plane3corner == 1) {
					MP1plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 2) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 3) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane3corner == 4) {
					MP1plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane3corner != MP1corner1) {
				if (MP1plane3corner == 1 && (MP1plane3.getPosition().x <-80|| MP1plane3.getPosition().y < 0)) {
					MP1plane3corner = MP1corner1;
					if (MP1plane3corner == 1) {
						MP1plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane3corner == 2) {
						MP1plane3.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane3corner == 3) {
						MP1plane3.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane3corner == 4) {
						MP1plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane3corner == 2 && (MP1plane3.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane3.getPosition().y < 0)) {
					MP1plane3corner = MP1corner1;
					if (MP1plane3corner == 1) {
						MP1plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane3corner == 2) {
						MP1plane3.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane3corner == 3) {
						MP1plane3.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane3corner == 4) {
						MP1plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane3corner == 3 && (MP1plane3.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane3.getPosition().y > 1160)) {
					MP1plane3corner = MP1corner1;
					if (MP1plane3corner == 1) {
						MP1plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane3corner == 2) {
						MP1plane3.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane3corner == 3) {
						MP1plane3.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane3corner == 4) {
						MP1plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane3corner == 4 && (MP1plane3.getPosition().x <-80|| MP1plane3.getPosition().y > 1160)) {
					MP1plane3corner = MP1corner1;
					if (MP1plane3corner == 1) {
						MP1plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane3corner == 2) {
						MP1plane3.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane3corner == 3) {
						MP1plane3.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane3corner == 4) {
						MP1plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (MP1plane3Hitbox.getGlobalBounds().intersects(MP1grenadeHitbox.getGlobalBounds()) && MP1shoot && !MP1bombShoot) {
				MP1plane3corner = MP1corner1;
				MP1plane3Death = true;
				MP1deathEffect3.setPosition(MP1plane3.getPosition());
				MP1explosion.setPosition(MP1plane3.getPosition());
				MP1explosionBool = true;
				MP1grenade.setPosition(3840.f, 2160.f);
				grenadeExplosion.play();
				if (MP1plane3corner == 1) {
					MP1plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 2) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 3) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane3corner == 4) {
					MP1plane3.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
			}
			if (MP1plane3Hitbox.getGlobalBounds().intersects(MP1bombHitbox.getGlobalBounds()) && MP1shoot) {
				MP1score += 10;
				MP1plane3Death = true;
				MP1deathEffect3.setPosition(MP1plane3.getPosition());
				MP1plane3corner = MP1corner1;
				if (MP1plane3corner == 1) {
					MP1plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 2) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 3) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane3corner == 4) {
					MP1plane3.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP1plane3Hitbox.getGlobalBounds().intersects(MP1explosion.getGlobalBounds())) {
				MP1score += 10;
				MP1plane3corner = MP1corner1;
				MP1plane3Death = true;
				MP1deathEffect3.setPosition(MP1plane3.getPosition());
				if (MP1plane3corner == 1) {
					MP1plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 2) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane3corner == 3) {
					MP1plane3.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane3corner == 4) {
					MP1plane3.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP1plane4corner == 1 && (MP1plane4.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane4.getPosition().y > 1160)) {
				MP1plane4corner = MP1corner2;
				if (MP1plane4corner == 1) {
					MP1plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 2) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 3) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane4corner == 4) {
					MP1plane4.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
			}
			if (MP1plane4corner == 2 && (MP1plane4.getPosition().x <-80|| MP1plane4.getPosition().y > 1160)) {
				MP1plane4corner = MP1corner2;
				if (MP1plane4corner == 1) {
					MP1plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 2) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 3) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane4corner == 4) {
					MP1plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane4corner == 3 && (MP1plane4.getPosition().x <-80|| MP1plane4.getPosition().y < 0)) {
				MP1plane4corner = MP1corner2;
				if (MP1plane4corner == 1) {
					MP1plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 2) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 3) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane4corner == 4) {
					MP1plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane4corner == 4 && (MP1plane4.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane4.getPosition().y < 0)) {
				MP1plane4corner = MP1corner2;
				if (MP1plane4corner == 1) {
					MP1plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 2) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 3) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane4corner == 4) {
					MP1plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane4corner != MP1corner2) {
				if (MP1plane4corner == 1 && (MP1plane4.getPosition().x <-80|| MP1plane4.getPosition().y < 0)) {
					MP1plane4corner = MP1corner2;
					if (MP1plane4corner == 1) {
						MP1plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane4corner == 2) {
						MP1plane4.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane4corner == 3) {
						MP1plane4.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane4corner == 4) {
						MP1plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane4corner == 2 && (MP1plane4.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane4.getPosition().y < 0)) {
					MP1plane4corner = MP1corner2;
					if (MP1plane4corner == 1) {
						MP1plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane4corner == 2) {
						MP1plane4.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane4corner == 3) {
						MP1plane4.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane4corner == 4) {
						MP1plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane4corner == 3 && (MP1plane4.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane4.getPosition().y > 1160)) {
					MP1plane4corner = MP1corner2;
					if (MP1plane4corner == 1) {
						MP1plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane4corner == 2) {
						MP1plane4.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane4corner == 3) {
						MP1plane4.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane4corner == 4) {
						MP1plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane4corner == 4 && (MP1plane4.getPosition().x <-80|| MP1plane4.getPosition().y > 1160)) {
					MP1plane4corner = MP1corner2;
					if (MP1plane4corner == 1) {
						MP1plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane4corner == 2) {
						MP1plane4.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane4corner == 3) {
						MP1plane4.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane4corner == 4) {
						MP1plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (MP1plane4Hitbox.getGlobalBounds().intersects(MP1grenadeHitbox.getGlobalBounds()) && MP1shoot && !MP1bombShoot) {
				MP1plane4corner = MP1corner2;
				MP1plane4Death = true;
				MP1deathEffect4.setPosition(MP1plane4.getPosition());
				MP1explosion.setPosition(MP1plane4.getPosition());
				MP1explosionBool = true;
				MP1grenade.setPosition(3840.f, 2160.f);
				grenadeExplosion.play();
				if (MP1plane4corner == 1) {
					MP1plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 2) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 3) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane4corner == 4) {
					MP1plane4.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
			}
			if (MP1plane4Hitbox.getGlobalBounds().intersects(MP1bombHitbox.getGlobalBounds()) && MP1shoot) {
				MP1score += 10;
				MP1plane4corner = MP1corner2;
				MP1plane4Death = true;
				MP1deathEffect4.setPosition(MP1plane4.getPosition());
				if (MP1plane4corner == 1) {
					MP1plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 2) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 3) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane4corner == 4) {
					MP1plane4.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP1plane4Hitbox.getGlobalBounds().intersects(MP1explosion.getGlobalBounds())) {
				MP1score += 10;
				MP1plane4corner = MP1corner2;
				MP1plane4Death = true;
				MP1deathEffect4.setPosition(MP1plane4.getPosition());
				if (MP1plane4corner == 1) {
					MP1plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 2) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane4corner == 3) {
					MP1plane4.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane4corner == 4) {
					MP1plane4.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP1plane5corner == 1 && (MP1plane5.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane5.getPosition().y > 1160)) {
				MP1plane5corner = MP1corner2;
				if (MP1plane5corner == 1) {
					MP1plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 2) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 3) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane5corner == 4) {
					MP1plane5.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
			}
			if (MP1plane5corner == 2 && (MP1plane5.getPosition().x <-80|| MP1plane5.getPosition().y > 1160)) {
				MP1plane5corner = MP1corner2;
				if (MP1plane5corner == 1) {
					MP1plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 2) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 3) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane5corner == 4) {
					MP1plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane5corner == 3 && (MP1plane5.getPosition().x <-80|| MP1plane5.getPosition().y < 0)) {
				MP1plane5corner = MP1corner2;
				if (MP1plane5corner == 1) {
					MP1plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 2) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 3) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane5corner == 4) {
					MP1plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane5corner == 4 && (MP1plane5.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane5.getPosition().y < 0)) {
				MP1plane5corner = MP1corner2;
				if (MP1plane5corner == 1) {
					MP1plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 2) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 3) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane5corner == 4) {
					MP1plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane5corner != MP1corner2) {
				if (MP1plane5corner == 1 && (MP1plane5.getPosition().x <-80|| MP1plane5.getPosition().y < 0)) {
					MP1plane5corner = MP1corner2;
					if (MP1plane5corner == 1) {
						MP1plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane5corner == 2) {
						MP1plane5.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane5corner == 3) {
						MP1plane5.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane5corner == 4) {
						MP1plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane5corner == 2 && (MP1plane5.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane5.getPosition().y < 0)) {
					MP1plane5corner = MP1corner2;
					if (MP1plane5corner == 1) {
						MP1plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane5corner == 2) {
						MP1plane5.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane5corner == 3) {
						MP1plane5.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane5corner == 4) {
						MP1plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane5corner == 3 && (MP1plane5.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane5.getPosition().y > 1160)) {
					MP1plane5corner = MP1corner2;
					if (MP1plane5corner == 1) {
						MP1plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane5corner == 2) {
						MP1plane5.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane5corner == 3) {
						MP1plane5.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane5corner == 4) {
						MP1plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane5corner == 4 && (MP1plane5.getPosition().x <-80|| MP1plane5.getPosition().y > 1160)) {
					MP1plane5corner = MP1corner2;
					if (MP1plane5corner == 1) {
						MP1plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane5corner == 2) {
						MP1plane5.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane5corner == 3) {
						MP1plane5.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane5corner == 4) {
						MP1plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (MP1plane5Hitbox.getGlobalBounds().intersects(MP1grenadeHitbox.getGlobalBounds()) && MP1shoot && !MP1bombShoot) {
				MP1plane5corner = MP1corner2;
				MP1plane5Death = true;
				MP1deathEffect5.setPosition(MP1plane5.getPosition());
				MP1explosion.setPosition(MP1plane5.getPosition());
				MP1explosionBool = true;
				MP1grenade.setPosition(3840.f, 2160.f);
				grenadeExplosion.play();
				if (MP1plane5corner == 1) {
					MP1plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 2) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 3) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane5corner == 4) {
					MP1plane5.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
			}
			if (MP1plane5Hitbox.getGlobalBounds().intersects(MP1bombHitbox.getGlobalBounds()) && MP1shoot) {
				MP1score += 10;
				MP1plane5corner = MP1corner2;
				MP1plane5Death = true;
				MP1deathEffect5.setPosition(MP1plane5.getPosition());
				if (MP1plane5corner == 1) {
					MP1plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 2) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 3) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane5corner == 4) {
					MP1plane5.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP1plane5Hitbox.getGlobalBounds().intersects(MP1explosion.getGlobalBounds())) {
				MP1score += 10;
				MP1plane5corner = MP1corner2;
				MP1plane5Death = true;
				MP1deathEffect5.setPosition(MP1plane5.getPosition());
				if (MP1plane5corner == 1) {
					MP1plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 2) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane5corner == 3) {
					MP1plane5.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane5corner == 4) {
					MP1plane5.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP1plane6corner == 1 && (MP1plane6.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane6.getPosition().y > 1160)) {
				MP1plane6corner = MP1corner2;
				if (MP1plane6corner == 1) {
					MP1plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 2) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 3) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane6corner == 4) {
					MP1plane6.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
			}
			if (MP1plane6corner == 1 && (MP1plane6.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane6.getPosition().y > 1160)) {
				MP1plane6corner = MP1corner2;
				if (MP1plane6corner == 1) {
					MP1plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 2) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 3) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane6corner == 4) {
					MP1plane6.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
			}
			if (MP1plane6corner == 2 && (MP1plane6.getPosition().x <-80|| MP1plane6.getPosition().y > 1160)) {
				MP1plane6corner = MP1corner2;
				if (MP1plane6corner == 1) {
					MP1plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 2) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 3) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane6corner == 4) {
					MP1plane6.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane6corner == 3 && (MP1plane6.getPosition().x <-80|| MP1plane6.getPosition().y < 0)) {
				MP1plane6corner = MP1corner2;
				if (MP1plane6corner == 1) {
					MP1plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 2) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 3) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane6corner == 4) {
					MP1plane6.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane6corner == 4 && (MP1plane6.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane6.getPosition().y < 0)) {
				MP1plane6corner = MP1corner2;
				if (MP1plane6corner == 1) {
					MP1plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 2) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 3) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (MP1plane6corner == 4) {
					MP1plane6.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (MP1plane6corner != MP1corner2) {
				if (MP1plane6corner == 1 && (MP1plane6.getPosition().x <-80|| MP1plane6.getPosition().y < 0)) {
					MP1plane6corner = MP1corner2;
					if (MP1plane6corner == 1) {
						MP1plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane6corner == 2) {
						MP1plane6.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane6corner == 3) {
						MP1plane6.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane6corner == 4) {
						MP1plane6.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane6corner == 2 && (MP1plane6.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane6.getPosition().y < 0)) {
					MP1plane6corner = MP1corner2;
					if (MP1plane6corner == 1) {
						MP1plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane6corner == 2) {
						MP1plane6.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane6corner == 3) {
						MP1plane6.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane6corner == 4) {
						MP1plane6.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane6corner == 3 && (MP1plane6.getGlobalBounds().intersects(divider.getGlobalBounds()) || MP1plane6.getPosition().y > 1160)) {
					MP1plane6corner = MP1corner2;
					if (MP1plane6corner == 1) {
						MP1plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane6corner == 2) {
						MP1plane6.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane6corner == 3) {
						MP1plane6.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane6corner == 4) {
						MP1plane6.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (MP1plane6corner == 4 && (MP1plane6.getPosition().x <-80|| MP1plane6.getPosition().y > 1160)) {
					MP1plane6corner = MP1corner2;
					if (MP1plane6corner == 1) {
						MP1plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane6corner == 2) {
						MP1plane6.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (MP1plane6corner == 3) {
						MP1plane6.setPosition(1140 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (MP1plane6corner == 4) {
						MP1plane6.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (MP1plane6Hitbox.getGlobalBounds().intersects(grenadeHitbox.getGlobalBounds()) && MP1shoot && !MP1bombShoot) {
				MP1plane6corner = MP1corner2;
				MP1plane6Death = true;
				MP1deathEffect6.setPosition(MP1plane6.getPosition());
				MP1explosion.setPosition(MP1plane6.getPosition());
				MP1explosionBool = true;
				MP1grenade.setPosition(3840.f, 2160.f);
				grenadeExplosion.play();
				if (MP1plane6corner == 1) {
					MP1plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 2) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 3) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane6corner == 4) {
					MP1plane6.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
			}
			if (MP1plane6Hitbox.getGlobalBounds().intersects(MP1bombHitbox.getGlobalBounds()) && MP1shoot) {
				MP1score += 10;
				MP1plane6corner = MP1corner2;
				MP1plane6Death = true;
				MP1deathEffect6.setPosition(MP1plane6.getPosition());
				if (MP1plane6corner == 1) {
					MP1plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 2) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 3) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane6corner == 4) {
					MP1plane6.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			if (MP1plane6Hitbox.getGlobalBounds().intersects(MP1explosion.getGlobalBounds())) {
				MP1score += 10;
				MP1plane6corner = MP1corner2;
				MP1plane6Death = true;
				MP1deathEffect6.setPosition(MP1plane6.getPosition());
				if (MP1plane6corner == 1) {
					MP1plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 2) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (MP1plane6corner == 3) {
					MP1plane6.setPosition(1140 + (rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				if (MP1plane6corner == 4) {
					MP1plane6.setPosition(-(rand() % 400 + 100), 1140 + (rand() % 400 + 100));
				}
				bombExplosion.play();
			}
			switch (MP1plane1corner) {
			case 0:
				MP1plane1.setPosition(1140 * 4.f, 1160 * 4.f);
				break;
			case 1:
				MP1plane1.move(planeSpeed, planeSpeed);
				MP1plane1.setRotation(135);
				break;
			case 2:
				MP1plane1.move(-planeSpeed, planeSpeed);
				MP1plane1.setRotation(225);
				break;
			case 3:
				MP1plane1.move(-planeSpeed, -planeSpeed);
				MP1plane1.setRotation(315);
				break;
			case 4:
				MP1plane1.move(planeSpeed, -planeSpeed);
				MP1plane1.setRotation(45);
				break;
			}
			switch (MP1plane2corner) {
			case 0:
				MP1plane2.setPosition(1140 * 4.f, 1160 * 4.f);
				break;
			case 1:
				MP1plane2.move(planeSpeed, planeSpeed);
				MP1plane2.setRotation(135);
				break;
			case 2:
				MP1plane2.move(-planeSpeed, planeSpeed);
				MP1plane2.setRotation(225);
				break;
			case 3:
				MP1plane2.move(-planeSpeed, -planeSpeed);
				MP1plane2.setRotation(315);
				break;
			case 4:
				MP1plane2.move(planeSpeed, -planeSpeed);
				MP1plane2.setRotation(45);
				break;
			}
			switch (MP1plane3corner) {
			case 0:
				MP1plane3.setPosition(1140 * 4.f, 1160 * 4.f);
				break;
			case 1:
				MP1plane3.move(planeSpeed, planeSpeed);
				MP1plane3.setRotation(135);
				break;
			case 2:
				MP1plane3.move(-planeSpeed, planeSpeed);
				MP1plane3.setRotation(225);
				break;
			case 3:
				MP1plane3.move(-planeSpeed, -planeSpeed);
				MP1plane3.setRotation(315);
				break;
			case 4:
				MP1plane3.move(planeSpeed, -planeSpeed);
				MP1plane3.setRotation(45);
				break;
			}
			switch (MP1plane4corner) {
			case 0:
				MP1plane4.setPosition(1140 * 4.f, 1160 * 4.f);
				break;
			case 1:
				MP1plane4.move(planeSpeed2, planeSpeed2);
				MP1plane4.setRotation(135);
				break;
			case 2:
				MP1plane4.move(-planeSpeed2, planeSpeed2);
				MP1plane4.setRotation(225);
				break;
			case 3:
				MP1plane4.move(-planeSpeed2, -planeSpeed2);
				MP1plane4.setRotation(315);
				break;
			case 4:
				MP1plane4.move(planeSpeed2, -planeSpeed2);
				MP1plane4.setRotation(45);
				break;
			}
			switch (MP1plane5corner) {
			case 0:
				MP1plane5.setPosition(1140 * 4.f, 1160 * 4.f);
				break;
			case 1:
				MP1plane5.move(planeSpeed2, planeSpeed2);
				MP1plane5.setRotation(135);
				break;
			case 2:
				MP1plane5.move(-planeSpeed2, planeSpeed2);
				MP1plane5.setRotation(225);
				break;
			case 3:
				MP1plane5.move(-planeSpeed2, -planeSpeed2);
				MP1plane5.setRotation(315);
				break;
			case 4:
				MP1plane5.move(planeSpeed2, -planeSpeed2);
				MP1plane5.setRotation(45);
				break;
			}
			switch (MP1plane6corner) {
			case 0:
				MP1plane6.setPosition(1140 * 4.f, 1160 * 4.f);
				break;
			case 1:
				MP1plane6.move(planeSpeed2, planeSpeed2);
				MP1plane6.setRotation(135);
				break;
			case 2:
				MP1plane6.move(-planeSpeed2, planeSpeed2);
				MP1plane6.setRotation(225);
				break;
			case 3:
				MP1plane6.move(-planeSpeed2, -planeSpeed2);
				MP1plane6.setRotation(315);
				break;
			case 4:
				MP1plane6.move(planeSpeed2, -planeSpeed2);
				MP1plane6.setRotation(45);
				break;
			}
			if (MP1plane1Hitbox.getGlobalBounds().intersects(MP1playerHitbox.getGlobalBounds()) || MP1plane2Hitbox.getGlobalBounds().intersects(MP1playerHitbox.getGlobalBounds()) || MP1plane3Hitbox.getGlobalBounds().intersects(MP1playerHitbox.getGlobalBounds()) || MP1plane4Hitbox.getGlobalBounds().intersects(MP1playerHitbox.getGlobalBounds()) || MP1plane5Hitbox.getGlobalBounds().intersects(MP1playerHitbox.getGlobalBounds()) || MP1plane6Hitbox.getGlobalBounds().intersects(MP1playerHitbox.getGlobalBounds())) {
				MP2wins++;
				player2Local = false;
				if (!player2Remote) {
					player2Joined = false;
				}
				menu = true;
				versus = false;
				lobby = true;
				genret.stop();
				death.play();
				menuMusic.setLoop(true);
				menuMusic.play();
			}
			if (MP2plane1Hitbox.getGlobalBounds().intersects(MP2playerHitbox.getGlobalBounds()) || MP2plane2Hitbox.getGlobalBounds().intersects(MP2playerHitbox.getGlobalBounds()) || MP2plane3Hitbox.getGlobalBounds().intersects(MP2playerHitbox.getGlobalBounds()) || MP2plane4Hitbox.getGlobalBounds().intersects(MP2playerHitbox.getGlobalBounds()) || MP2plane5Hitbox.getGlobalBounds().intersects(MP2playerHitbox.getGlobalBounds()) || MP2plane6Hitbox.getGlobalBounds().intersects(MP2playerHitbox.getGlobalBounds())) {
				MP1wins++;
				menu = true;
				versus = false;
				lobby = true;
				genret.stop();
				death.play();
				menuMusic.setLoop(true);
				menuMusic.play();
			}
			// Timer
			frames++;
			if (frames == 6.f) {
				timer += 6.f / framerate;
				waveTimer += 6.f / framerate;
				if (MP1explosionBool && MP1expTimer > 0) {
					MP1expTimer -= 6.f / framerate;
				}
				if (MP1expTimer < 0) {
					MP1explosion.setPosition(1920 * 3.f, 1080 * 3.f);
					MP1explosionBool = false;
					MP1expTimer = 5;
				}
				if (MP2explosionBool && MP2expTimer > 0) {
					MP2expTimer -= 6.f / framerate;
				}
				if (MP2expTimer < 0) {
					MP2explosion.setPosition(1920 * 3.f, 1080 * 3.f);
					MP2explosionBool = false;
					MP2expTimer = 5;
				}
				frames = 0;
			}
			// Update speeds
			playerSpeed = ((15.f * wave) + 180.f) / (3.f * framerate);
			bombSpeed = (((90.f * wave) + 2100.f) / (5.f * framerate));
			planeSpeed = (((90.f * wave) + 300.f) / (5.f * framerate));
			planeSpeed2 = ((((90.f * wave) + 300.f) / (5.f * framerate))) / 2;
			// Change wave
			if (waveTimer >= 30) {
				MP1lastCorner1 = MP1corner1;
				MP2lastCorner1 = MP2corner1;
				wave += 1.f;
				wave5 += 1.f;
				MP1corner1 = rand() % 4 + 1;
				MP2corner1 = rand() % 4 + 1;
				if (wave5 >= 5) {
					MP1corner2 = rand() % 4 + 1;
					MP2corner2 = rand() % 4 + 1;
					wave5 = 0;
				}
				else {
					MP1corner2 = 0.f;
					MP2corner2 = 0.f;
				}
				waveTimer = 0.f;
				newWave.play();
			}
			if (MP1corner1 == MP1corner2) {
				MP1corner2 = rand() % 4 + 1;
			}
			if (MP1lastCorner1 == MP1corner1) {
				MP1corner1 = rand() % 4 + 1;
			}
			if (MP2corner1 == MP2corner2) {
				MP2corner2 = rand() % 4 + 1;
			}
			if (MP2lastCorner1 == MP2corner1) {
				MP2corner1 = rand() % 4 + 1;
			}
		}
		if (gameOver) {
			FloatRect bestScoreRect = bestScoreText.getLocalBounds();
			bestScoreText.setOrigin(bestScoreRect.left + bestScoreRect.width / 2.f, bestScoreRect.top + bestScoreRect.height / 2.f);
			bestScoreText.setPosition(Vector2f(750.f, 540.f));
			bestScoreText.setString(to_string(highScore));
			FloatRect lastScoreRect = lastScoreText.getLocalBounds();
			lastScoreText.setOrigin(lastScoreRect.left + lastScoreRect.width / 2.f, lastScoreRect.top + lastScoreRect.height / 2.f);
			lastScoreText.setPosition(Vector2f(750.f, 700.f));
			lastScoreText.setString(to_string(score));
		}
		if (!menu && !pause && !versus && !MPWarning) {
			if (!gameOver) {
				window.setMouseCursorVisible(false);
			} else {
				window.setMouseCursorVisible(true);
			}
			if (!altFont) {
				returnButton.setTexture(returnButtonTexture);
				exitButton.setTexture(exitButtonTexture);
			} else {
				returnButton.setTexture(returnButtonAltTexture);
				exitButton.setTexture(exitButtonAltTexture);
			}
			if (wave >= 10 && !wave10) {
				setCAN_WAVE10();
				saveStats();
				wave10 = true;
			}
			// Track positions
			grenadePos = grenade.getPosition();
			bombPos = bomb.getPosition();
			explosionPos = explosion.getPosition();
			// Attach hitboxes
			playerHitbox1.setPosition(player.getPosition());
			playerHitbox1.setRotation(player.getRotation());

			bombHitbox.setPosition(bomb.getPosition());
			bombHitbox.setRotation(bomb.getRotation());

			plane1Hitbox.setPosition(plane1.getPosition());
			plane2Hitbox.setPosition(plane2.getPosition());
			plane3Hitbox.setPosition(plane3.getPosition());
			plane4Hitbox.setPosition(plane4.getPosition());
			plane5Hitbox.setPosition(plane5.getPosition());
			plane6Hitbox.setPosition(plane6.getPosition());

			grenadeHitbox.setPosition(grenade.getPosition());
			grenadeHitbox.setRotation(grenade.getRotation());
			// Reset projectiles
			if (shoot && bombShoot) {
				if (bombPos.x < 50) {
					shoot = false;
					bombRotation = player.getRotation();
					bomb.setPosition(960.f, 540.f);
					if (switchTo) {
						bombShoot = false;
						switchTo = false;
						grenade.setPosition(960.f, 540.f);
					}
				}
				else if (bombPos.x > 1920 - 50) {
					shoot = false;
					bombRotation = player.getRotation();
					bomb.setPosition(960.f, 540.f);
					if (switchTo) {
						bombShoot = false;
						switchTo = false;
						grenade.setPosition(960.f, 540.f);
					}
				}
				else if (bombPos.y < 50) {
					shoot = false;
					bombRotation = player.getRotation();
					bomb.setPosition(960.f, 540.f);
					if (switchTo) {
						bombShoot = false;
						switchTo = false;
						grenade.setPosition(960.f, 540.f);
					}
				}
				else if (bombPos.y > 1080 - 50) {
					shoot = false;
					bombRotation = player.getRotation();
					bomb.setPosition(960.f, 540.f);
					if (switchTo) {
						bombShoot = false;
						switchTo = false;
						grenade.setPosition(960.f, 540.f);
					}
				}
			}

			else if (shoot && !bombShoot) {
				if (grenadePos.x < 50) {
					shoot = false;
					bombShoot = true;
					bombRotation = player.getRotation();
					bomb.setPosition(960.f, 540.f);
					grenade.setPosition(1920 * 2.f, 1080 * 2.f);
				}
				else if (grenadePos.x > 1920 - 50) {
					shoot = false;
					bombShoot = true;
					bombRotation = player.getRotation();
					bomb.setPosition(960.f, 540.f);
					grenade.setPosition(1920 * 2.f, 1080 * 2.f);
				}
				else if (grenadePos.y < 50) {
					shoot = false;
					bombShoot = true;
					bombRotation = player.getRotation();
					bomb.setPosition(960.f, 540.f);
					grenade.setPosition(1920 * 2.f, 1080 * 2.f);
				}
				else if (grenadePos.y > 1080 - 50) {
					shoot = false;
					bombShoot = true;
					bombRotation = player.getRotation();
					bomb.setPosition(1920 / 2.f, 1080 / 2.f);
					grenade.setPosition(1920 * 2.f, 1080 * 2.f);
				}
			}
			// Update text
			waveString = to_string(wave);
			scoreString = to_string(score);
			FloatRect scoreRect = scoreText.getLocalBounds();
			scoreText.setOrigin(scoreRect.left + scoreRect.width / 2.f, scoreRect.top + scoreRect.height / 2.f);
			scoreText.setPosition(Vector2f(960.f, 100.f));
			scoreText.setString("Score: " + scoreString);

			FloatRect waveRect = waveText.getLocalBounds();
			waveText.setOrigin(waveRect.left + waveRect.width / 2.f, waveRect.top + waveRect.height / 2.f);
			waveText.setPosition(Vector2f(960.f, 200.f));
			waveText.setString("Wave: " + waveString);

			// Plane logic
			plane1Pos = plane1.getPosition();
			plane2Pos = plane2.getPosition();
			plane3Pos = plane3.getPosition();
			plane4Pos = plane4.getPosition();
			plane5Pos = plane5.getPosition();
			plane6Pos = plane6.getPosition();

			plane1Hitbox.setPosition(plane1.getPosition());
			plane2Hitbox.setPosition(plane2.getPosition());
			plane3Hitbox.setPosition(plane3.getPosition());
			plane4Hitbox.setPosition(plane4.getPosition());
			plane5Hitbox.setPosition(plane5.getPosition());
			plane6Hitbox.setPosition(plane6.getPosition());
			if (plane1corner == 0 && corner1 != 0) {
				plane1corner = corner1;
				if (plane1corner == 1) {
					plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 2) {
					plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 3) {
					plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane1corner == 4) {
					plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane2corner == 0 && corner1 != 0) {
				plane2corner = corner1;
				if (plane2corner == 1) {
					plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 2) {
					plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 3) {
					plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane2corner == 4) {
					plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane3corner == 0 && corner1 != 0) {
				plane3corner = corner1;
				if (plane3corner == 1) {
					plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 2) {
					plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 3) {
					plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane3corner == 4) {
					plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane4corner == 0 && corner2 != 0) {
				plane4corner = corner2;
				if (plane4corner == 1) {
					plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 2) {
					plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 3) {
					plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane4corner == 4) {
					plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane5corner == 0 && corner2 != 0) {
				plane5corner = corner2;
				if (plane5corner == 1) {
					plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 2) {
					plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 3) {
					plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane5corner == 4) {
					plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane6corner == 0 && corner2 != 0) {
				plane6corner = corner2;
				if (plane6corner == 1) {
					plane6.setPosition(-(rand() % 400 + 1), -(rand() % 400 + 1));
				}
				if (plane6corner == 2) {
					plane6.setPosition(2000 + (rand() % 400 + 1), -(rand() % 400 + 1));
				}
				if (plane6corner == 3) {
					plane6.setPosition(2000 + (rand() % 400 + 1), 1160 + (rand() % 400 + 1));
				}
				if (plane6corner == 4) {
					plane6.setPosition(-(rand() % 400 + 1), 2000 + (rand() % 400 + 1));
				}
			}
			if (plane1corner == 1 && (plane1Pos.x > 2000 || plane1Pos.y > 1160)) {
				plane1corner = corner1;
				if (plane1corner == 1) {
					plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 2) {
					plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 3) {
					plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane1corner == 4) {
					plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane1corner == 2 && (plane1Pos.x <-80|| plane1Pos.y > 1160)) {
				plane1corner = corner1;
				if (plane1corner == 1) {
					plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 2) {
					plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 3) {
					plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane1corner == 4) {
					plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane1corner == 3 && (plane1Pos.x <-80|| plane1Pos.y < 0)) {
				plane1corner = corner1;
				if (plane1corner == 1) {
					plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 2) {
					plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 3) {
					plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane1corner == 4) {
					plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane1corner == 4 && (plane1Pos.x > 2000 || plane1Pos.y < 0)) {
				plane1corner = corner1;
				if (plane1corner == 1) {
					plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 2) {
					plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 3) {
					plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane1corner == 4) {
					plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane1corner != corner1) {
				if (plane1corner == 1 && (plane1Pos.x <-80|| plane1Pos.y < 0)) {
					plane1corner = corner1;
					if (plane1corner == 1) {
						plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane1corner == 2) {
						plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane1corner == 3) {
						plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane1corner == 4) {
						plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane1corner == 2 && (plane1Pos.x > 2000 || plane1Pos.y < 0)) {
					plane1corner = corner1;
					if (plane1corner == 1) {
						plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane1corner == 2) {
						plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane1corner == 3) {
						plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane1corner == 4) {
						plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane1corner == 3 && (plane1Pos.x > 2000 || plane1Pos.y > 1160)) {
					plane1corner = corner1;
					if (plane1corner == 1) {
						plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane1corner == 2) {
						plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane1corner == 3) {
						plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane1corner == 4) {
						plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane1corner == 4 && (plane1Pos.x <-80|| plane1Pos.y > 1160)) {
					plane1corner = corner1;
					if (plane1corner == 1) {
						plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane1corner == 2) {
						plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane1corner == 3) {
						plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane1corner == 4) {
						plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (plane1Hitbox.getGlobalBounds().intersects(grenadeHitbox.getGlobalBounds()) && shoot && !bombShoot) {
				plane1corner = corner1;
				plane1Death = true;
				deathEffect1.setPosition(plane1.getPosition());
				explosion.setPosition(plane1.getPosition());
				explosionBool = true;
				grenade.setPosition(3840.f, 2160.f);
				grenadeExplosion.play();
				if (plane1corner == 1) {
					plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 2) {
					plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 3) {
					plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane1corner == 4) {
					plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				// Update treasure
				treasure += 10;
			}
			if (plane1Hitbox.getGlobalBounds().intersects(bombHitbox.getGlobalBounds()) && shoot) {
				score += 10;
				plane1corner = corner1;
				plane1Death = true;
				deathEffect1.setPosition(plane1.getPosition());
				if (plane1corner == 1) {
					plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 2) {
					plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 3) {
					plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane1corner == 4) {
					plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				bombExplosion.play();
				// Update treasure
				treasure += 10;
				if (!firstStrike) {
					setCAN_FIRSTSTRIKE();
					saveStats();
					firstStrike = true;
				}
			}
			if (plane1Hitbox.getGlobalBounds().intersects(explosion.getGlobalBounds())) {
				score += 10;
				plane1corner = corner1;
				plane1Death = true;
				deathEffect1.setPosition(plane1.getPosition());
				if (plane1corner == 1) {
					plane1.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 1));
				}
				if (plane1corner == 2) {
					plane1.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane1corner == 3) {
					plane1.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane1corner == 4) {
					plane1.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				bombExplosion.play();
				// Update treasure
				treasure += 10;
			}
			if (plane2corner == 1 && (plane2Pos.x > 2000 || plane2Pos.y > 1160)) {
				plane2corner = corner1;
				if (plane2corner == 1) {
					plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 2) {
					plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 3) {
					plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane2corner == 4) {
					plane2.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (plane2corner == 2 && (plane2Pos.x <-80|| plane2Pos.y > 1160)) {
				plane2corner = corner1;
				if (plane2corner == 1) {
					plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 2) {
					plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 3) {
					plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane2corner == 4) {
					plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane2corner == 3 && (plane2Pos.x <-80|| plane2Pos.y < 0)) {
				plane2corner = corner1;
				if (plane2corner == 1) {
					plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 2) {
					plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 3) {
					plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane2corner == 4) {
					plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane2corner == 4 && (plane2Pos.x > 2000 || plane2Pos.y < 0)) {
				plane2corner = corner1;
				if (plane2corner == 1) {
					plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 2) {
					plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 3) {
					plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane2corner == 4) {
					plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane2corner != corner1) {
				if (plane2corner == 1 && (plane2Pos.x <-80|| plane2Pos.y < 0)) {
					plane2corner = corner1;
					if (plane2corner == 1) {
						plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane2corner == 2) {
						plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane2corner == 3) {
						plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane2corner == 4) {
						plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane2corner == 2 && (plane2Pos.x > 2000 || plane2Pos.y < 0)) {
					plane2corner = corner1;
					if (plane2corner == 1) {
						plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane2corner == 2) {
						plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane2corner == 3) {
						plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane2corner == 4) {
						plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane2corner == 3 && (plane2Pos.x > 2000 || plane2Pos.y > 1160)) {
					plane2corner = corner1;
					if (plane2corner == 1) {
						plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane2corner == 2) {
						plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane2corner == 3) {
						plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane2corner == 4) {
						plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane2corner == 4 && (plane2Pos.x <-80|| plane2Pos.y > 1160)) {
					plane2corner = corner1;
					if (plane2corner == 1) {
						plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane2corner == 2) {
						plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane2corner == 3) {
						plane2.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane2corner == 4) {
						plane2.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (plane2Hitbox.getGlobalBounds().intersects(grenadeHitbox.getGlobalBounds()) && shoot && !bombShoot) {
				plane2corner = corner1;
				plane2Death = true;
				deathEffect2.setPosition(plane2.getPosition());
				explosion.setPosition(plane2.getPosition());
				explosionBool = true;
				grenade.setPosition(2000 * 2.f, 1160 * 2.f);
				grenadeExplosion.play();
				if (plane2corner == 1) {
					plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 2) {
					plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 3) {
					plane2.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane2corner == 4) {
					plane2.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				// Update treasure
				treasure += 10;
			}
			if (plane2Hitbox.getGlobalBounds().intersects(bombHitbox.getGlobalBounds()) && shoot) {
				score += 10;
				plane2corner = corner1;
				plane2Death = true;
				deathEffect2.setPosition(plane2.getPosition());
				if (plane2corner == 1) {
					plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 2) {
					plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 3) {
					plane2.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane2corner == 4) {
					plane2.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
				// Update treasure
				treasure += 10;
				if (!firstStrike) {
					setCAN_FIRSTSTRIKE();
					saveStats();
					firstStrike = true;
				}
			}
			if (plane2Hitbox.getGlobalBounds().intersects(explosion.getGlobalBounds())) {
				score += 10;
				plane2corner = corner1;
				plane2Death = true;
				deathEffect2.setPosition(plane2.getPosition());
				if (plane2corner == 1) {
					plane2.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 2) {
					plane2.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane2corner == 3) {
					plane2.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane2corner == 4) {
					plane2.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
				// Update treasure
				treasure += 10;
			}
			if (plane3corner == 1 && (plane3Pos.x > 2000 || plane3Pos.y > 1160)) {
				plane3corner = corner1;
				if (plane3corner == 1) {
					plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 2) {
					plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 3) {
					plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane3corner == 4) {
					plane3.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (plane3corner == 2 && (plane3Pos.x <-80|| plane3Pos.y > 1160)) {
				plane3corner = corner1;
				if (plane3corner == 1) {
					plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 2) {
					plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 3) {
					plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane3corner == 4) {
					plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane3corner == 3 && (plane3Pos.x <-80|| plane3Pos.y < 0)) {
				plane3corner = corner1;
				if (plane3corner == 1) {
					plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 2) {
					plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 3) {
					plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane3corner == 4) {
					plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane3corner == 4 && (plane3Pos.x > 2000 || plane3Pos.y < 0)) {
				plane3corner = corner1;
				if (plane3corner == 1) {
					plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 2) {
					plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 3) {
					plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane3corner == 4) {
					plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane3corner != corner1) {
				if (plane3corner == 1 && (plane3Pos.x <-80|| plane3Pos.y < 0)) {
					plane3corner = corner1;
					if (plane3corner == 1) {
						plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane3corner == 2) {
						plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane3corner == 3) {
						plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane3corner == 4) {
						plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane3corner == 2 && (plane3Pos.x > 2000 || plane3Pos.y < 0)) {
					plane3corner = corner1;
					if (plane3corner == 1) {
						plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane3corner == 2) {
						plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane3corner == 3) {
						plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane3corner == 4) {
						plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane3corner == 3 && (plane3Pos.x > 2000 || plane3Pos.y > 1160)) {
					plane3corner = corner1;
					if (plane3corner == 1) {
						plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane3corner == 2) {
						plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane3corner == 3) {
						plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane3corner == 4) {
						plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane3corner == 4 && (plane3Pos.x <-80|| plane3Pos.y > 1160)) {
					plane3corner = corner1;
					if (plane3corner == 1) {
						plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane3corner == 2) {
						plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane3corner == 3) {
						plane3.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane3corner == 4) {
						plane3.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (plane3Hitbox.getGlobalBounds().intersects(grenadeHitbox.getGlobalBounds()) && shoot && !bombShoot) {
				plane3corner = corner1;
				plane3Death = true;
				deathEffect3.setPosition(plane3.getPosition());
				explosion.setPosition(plane3.getPosition());
				explosionBool = true;
				grenade.setPosition(2000 * 2.f, 1160 * 2.f);
				grenadeExplosion.play();
				if (plane3corner == 1) {
					plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 2) {
					plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 3) {
					plane3.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane3corner == 4) {
					plane3.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				// Update treasure
				treasure += 10;
			}
			if (plane3Hitbox.getGlobalBounds().intersects(bombHitbox.getGlobalBounds()) && shoot) {
				score += 10;
				plane3Death = true;
				deathEffect3.setPosition(plane3.getPosition());
				plane3corner = corner1;
				if (plane3corner == 1) {
					plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 2) {
					plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 3) {
					plane3.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane3corner == 4) {
					plane3.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
				// Update treasure
				treasure += 10;
				if (!firstStrike) {
					setCAN_FIRSTSTRIKE();
					saveStats();
					firstStrike = true;
				}
			}
			if (plane3Hitbox.getGlobalBounds().intersects(explosion.getGlobalBounds())) {
				score += 10;
				plane3corner = corner1;
				plane3Death = true;
				deathEffect3.setPosition(plane3.getPosition());
				if (plane3corner == 1) {
					plane3.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 2) {
					plane3.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane3corner == 3) {
					plane3.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane3corner == 4) {
					plane3.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
				// Update treasure
				treasure += 10;
			}
			if (plane4corner == 1 && (plane4Pos.x > 2000 || plane4Pos.y > 1160)) {
				plane4corner = corner2;
				if (plane4corner == 1) {
					plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 2) {
					plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 3) {
					plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane4corner == 4) {
					plane4.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (plane4corner == 2 && (plane4Pos.x <-80|| plane4Pos.y > 1160)) {
				plane4corner = corner2;
				if (plane4corner == 1) {
					plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 2) {
					plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 3) {
					plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane4corner == 4) {
					plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane4corner == 3 && (plane4Pos.x <-80|| plane4Pos.y < 0)) {
				plane4corner = corner2;
				if (plane4corner == 1) {
					plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 2) {
					plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 3) {
					plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane4corner == 4) {
					plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane4corner == 4 && (plane4Pos.x > 2000 || plane4Pos.y < 0)) {
				plane4corner = corner2;
				if (plane4corner == 1) {
					plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 2) {
					plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 3) {
					plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane4corner == 4) {
					plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane4corner != corner2) {
				if (plane4corner == 1 && (plane4Pos.x <-80|| plane4Pos.y < 0)) {
					plane4corner = corner2;
					if (plane4corner == 1) {
						plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane4corner == 2) {
						plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane4corner == 3) {
						plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane4corner == 4) {
						plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane4corner == 2 && (plane4Pos.x > 2000 || plane4Pos.y < 0)) {
					plane4corner = corner2;
					if (plane4corner == 1) {
						plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane4corner == 2) {
						plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane4corner == 3) {
						plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane4corner == 4) {
						plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane4corner == 3 && (plane4Pos.x > 2000 || plane4Pos.y > 1160)) {
					plane4corner = corner2;
					if (plane4corner == 1) {
						plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane4corner == 2) {
						plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane4corner == 3) {
						plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane4corner == 4) {
						plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane4corner == 4 && (plane4Pos.x <-80|| plane4Pos.y > 1160)) {
					plane4corner = corner2;
					if (plane4corner == 1) {
						plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane4corner == 2) {
						plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane4corner == 3) {
						plane4.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane4corner == 4) {
						plane4.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (plane4Hitbox.getGlobalBounds().intersects(grenadeHitbox.getGlobalBounds()) && shoot && !bombShoot) {
				plane4corner = corner2;
				plane4Death = true;
				deathEffect4.setPosition(plane4.getPosition());
				explosion.setPosition(plane4.getPosition());
				explosionBool = true;
				grenade.setPosition(2000 * 2.f, 1160 * 2.f);
				grenadeExplosion.play();
				if (plane4corner == 1) {
					plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 2) {
					plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 3) {
					plane4.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane4corner == 4) {
					plane4.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				// Update treasure
				treasure += 10;
			}
			if (plane4Hitbox.getGlobalBounds().intersects(bombHitbox.getGlobalBounds()) && shoot) {
				score += 10;
				plane4corner = corner2;
				plane4Death = true;
				deathEffect4.setPosition(plane4.getPosition());
				if (plane4corner == 1) {
					plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 2) {
					plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 3) {
					plane4.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane4corner == 4) {
					plane4.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
				// Update treasure
				treasure += 10;
				if (!firstStrike) {
					setCAN_FIRSTSTRIKE();
					saveStats();
					firstStrike = true;
				}
			}
			if (plane4Hitbox.getGlobalBounds().intersects(explosion.getGlobalBounds())) {
				score += 10;
				plane4corner = corner2;
				plane4Death = true;
				deathEffect4.setPosition(plane4.getPosition());
				if (plane4corner == 1) {
					plane4.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 2) {
					plane4.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane4corner == 3) {
					plane4.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane4corner == 4) {
					plane4.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
				// Update treasure
				treasure += 10;
			}
			if (plane5corner == 1 && (plane5Pos.x > 2000 || plane5Pos.y > 1160)) {
				plane5corner = corner2;
				if (plane5corner == 1) {
					plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 2) {
					plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 3) {
					plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane5corner == 4) {
					plane5.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (plane5corner == 2 && (plane5Pos.x <-80|| plane5Pos.y > 1160)) {
				plane5corner = corner2;
				if (plane5corner == 1) {
					plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 2) {
					plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 3) {
					plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane5corner == 4) {
					plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane5corner == 3 && (plane5Pos.x <-80|| plane5Pos.y < 0)) {
				plane5corner = corner2;
				if (plane5corner == 1) {
					plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 2) {
					plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 3) {
					plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane5corner == 4) {
					plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane5corner == 4 && (plane5Pos.x > 2000 || plane5Pos.y < 0)) {
				plane5corner = corner2;
				if (plane5corner == 1) {
					plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 2) {
					plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 3) {
					plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane5corner == 4) {
					plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane5corner != corner2) {
				if (plane5corner == 1 && (plane5Pos.x <-80|| plane5Pos.y < 0)) {
					plane5corner = corner2;
					if (plane5corner == 1) {
						plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane5corner == 2) {
						plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane5corner == 3) {
						plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane5corner == 4) {
						plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane5corner == 2 && (plane5Pos.x > 2000 || plane5Pos.y < 0)) {
					plane5corner = corner2;
					if (plane5corner == 1) {
						plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane5corner == 2) {
						plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane5corner == 3) {
						plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane5corner == 4) {
						plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane5corner == 3 && (plane5Pos.x > 2000 || plane5Pos.y > 1160)) {
					plane5corner = corner2;
					if (plane5corner == 1) {
						plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane5corner == 2) {
						plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane5corner == 3) {
						plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane5corner == 4) {
						plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane5corner == 4 && (plane5Pos.x <-80|| plane5Pos.y > 1160)) {
					plane5corner = corner2;
					if (plane5corner == 1) {
						plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane5corner == 2) {
						plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane5corner == 3) {
						plane5.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane5corner == 4) {
						plane5.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (plane5Hitbox.getGlobalBounds().intersects(grenadeHitbox.getGlobalBounds()) && shoot && !bombShoot) {
				plane5corner = corner2;
				plane5Death = true;
				deathEffect5.setPosition(plane5.getPosition());
				explosion.setPosition(plane5.getPosition());
				explosionBool = true;
				grenade.setPosition(2000 * 2.f, 1160 * 2.f);
				grenadeExplosion.play();
				if (plane5corner == 1) {
					plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 2) {
					plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 3) {
					plane5.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane5corner == 4) {
					plane5.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				// Update treasure
				treasure += 10;
			}
			if (plane5Hitbox.getGlobalBounds().intersects(bombHitbox.getGlobalBounds()) && shoot) {
				score += 10;
				plane5corner = corner2;
				plane5Death = true;
				deathEffect5.setPosition(plane5.getPosition());
				if (plane5corner == 1) {
					plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 2) {
					plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 3) {
					plane5.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane5corner == 4) {
					plane5.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
				// Update treasure
				treasure += 10;
				if (!firstStrike) {
					setCAN_FIRSTSTRIKE();
					saveStats();
					firstStrike = true;
				}
			}
			if (plane5Hitbox.getGlobalBounds().intersects(explosion.getGlobalBounds())) {
				score += 10;
				plane5corner = corner2;
				plane5Death = true;
				deathEffect5.setPosition(plane5.getPosition());
				if (plane5corner == 1) {
					plane5.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 2) {
					plane5.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane5corner == 3) {
					plane5.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane5corner == 4) {
					plane5.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
				// Update treasure
				treasure += 10;
			}
			if (plane6corner == 1 && (plane6Pos.x > 2000 || plane6Pos.y > 1160)) {
				plane6corner = corner2;
				if (plane6corner == 1) {
					plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 2) {
					plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 3) {
					plane6.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane6corner == 4) {
					plane6.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (plane6corner == 1 && (plane6Pos.x > 2000 || plane6Pos.y > 1160)) {
				plane6corner = corner2;
				if (plane6corner == 1) {
					plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 2) {
					plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 3) {
					plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane6corner == 4) {
					plane6.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
			}
			if (plane6corner == 2 && (plane6Pos.x <-80|| plane6Pos.y > 1160)) {
				plane6corner = corner2;
				if (plane6corner == 1) {
					plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 2) {
					plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 3) {
					plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane6corner == 4) {
					plane6.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane6corner == 3 && (plane6Pos.x <-80|| plane6Pos.y < 0)) {
				plane6corner = corner2;
				if (plane6corner == 1) {
					plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 2) {
					plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 3) {
					plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane6corner == 4) {
					plane6.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane6corner == 4 && (plane6Pos.x > 2000 || plane6Pos.y < 0)) {
				plane6corner = corner2;
				if (plane6corner == 1) {
					plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 2) {
					plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 3) {
					plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
				if (plane6corner == 4) {
					plane6.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
				}
			}
			if (plane6corner != corner2) {
				if (plane6corner == 1 && (plane6Pos.x <-80|| plane6Pos.y < 0)) {
					plane6corner = corner2;
					if (plane6corner == 1) {
						plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane6corner == 2) {
						plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane6corner == 3) {
						plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane6corner == 4) {
						plane6.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane6corner == 2 && (plane6Pos.x > 2000 || plane6Pos.y < 0)) {
					plane6corner = corner2;
					if (plane6corner == 1) {
						plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane6corner == 2) {
						plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane6corner == 3) {
						plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane6corner == 4) {
						plane6.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane6corner == 3 && (plane6Pos.x > 2000 || plane6Pos.y > 1160)) {
					plane6corner = corner2;
					if (plane6corner == 1) {
						plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane6corner == 2) {
						plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane6corner == 3) {
						plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane6corner == 4) {
						plane6.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
				if (plane6corner == 4 && (plane6Pos.x <-80|| plane6Pos.y > 1160)) {
					plane6corner = corner2;
					if (plane6corner == 1) {
						plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane6corner == 2) {
						plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
					}
					if (plane6corner == 3) {
						plane6.setPosition(2000 + (rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
					if (plane6corner == 4) {
						plane6.setPosition(-(rand() % 400 + 100), 1160 + (rand() % 400 + 100));
					}
				}
			}
			if (plane6Hitbox.getGlobalBounds().intersects(grenadeHitbox.getGlobalBounds()) && shoot && !bombShoot) {
				plane6corner = corner2;
				plane6Death = true;
				deathEffect6.setPosition(plane6.getPosition());
				explosion.setPosition(plane6.getPosition());
				explosionBool = true;
				grenade.setPosition(2000 * 2.f, 1160 * 2.f);
				grenadeExplosion.play();
				if (plane6corner == 1) {
					plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 2) {
					plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 3) {
					plane6.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane6corner == 4) {
					plane6.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				// Update treasure
				treasure += 10;
			}
			if (plane6Hitbox.getGlobalBounds().intersects(bombHitbox.getGlobalBounds()) && shoot) {
				score += 10;
				plane6corner = corner2;
				plane6Death = true;
				deathEffect6.setPosition(plane6.getPosition());
				if (plane6corner == 1) {
					plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 2) {
					plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 3) {
					plane6.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane6corner == 4) {
					plane6.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
				// Update treasure
				treasure += 10;
				if (!firstStrike) {
					setCAN_FIRSTSTRIKE();
					saveStats();
					firstStrike = true;
				}
			}
			if (plane6Hitbox.getGlobalBounds().intersects(explosion.getGlobalBounds())) {
				score += 10;
				plane6corner = corner2;
				plane6Death = true;
				deathEffect6.setPosition(plane6.getPosition());
				if (plane6corner == 1) {
					plane6.setPosition(-(rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 2) {
					plane6.setPosition(2000 + (rand() % 400 + 100), -(rand() % 400 + 100));
				}
				if (plane6corner == 3) {
					plane6.setPosition(2000 + (rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				if (plane6corner == 4) {
					plane6.setPosition(-(rand() % 400 + 100), 2000 + (rand() % 400 + 100));
				}
				bombExplosion.play();
				// Update treasure
				treasure += 10;
			}
			switch (plane1corner) {
			case 0:
				plane1.setPosition(2000 * 4.f, 1160 * 4.f);
				break;
			case 1:
				plane1.move(planeSpeed, planeSpeed);
				plane1.setRotation(135);
				break;
			case 2:
				plane1.move(-planeSpeed, planeSpeed);
				plane1.setRotation(225);
				break;
			case 3:
				plane1.move(-planeSpeed, -planeSpeed);
				plane1.setRotation(315);
				break;
			case 4:
				plane1.move(planeSpeed, -planeSpeed);
				plane1.setRotation(45);
				break;
			}
			switch (plane2corner) {
			case 0:
				plane2.setPosition(2000 * 4.f, 1160 * 4.f);
				break;
			case 1:
				plane2.move(planeSpeed, planeSpeed);
				plane2.setRotation(135);
				break;
			case 2:
				plane2.move(-planeSpeed, planeSpeed);
				plane2.setRotation(225);
				break;
			case 3:
				plane2.move(-planeSpeed, -planeSpeed);
				plane2.setRotation(315);
				break;
			case 4:
				plane2.move(planeSpeed, -planeSpeed);
				plane2.setRotation(45);
				break;
			}
			switch (plane3corner) {
			case 0:
				plane3.setPosition(2000 * 4.f, 1160 * 4.f);
				break;
			case 1:
				plane3.move(planeSpeed, planeSpeed);
				plane3.setRotation(135);
				break;
			case 2:
				plane3.move(-planeSpeed, planeSpeed);
				plane3.setRotation(225);
				break;
			case 3:
				plane3.move(-planeSpeed, -planeSpeed);
				plane3.setRotation(315);
				break;
			case 4:
				plane3.move(planeSpeed, -planeSpeed);
				plane3.setRotation(45);
				break;
			}
			switch (plane4corner) {
			case 0:
				plane4.setPosition(2000 * 4.f, 1160 * 4.f);
				break;
			case 1:
				plane4.move(planeSpeed2, planeSpeed2);
				plane4.setRotation(135);
				break;
			case 2:
				plane4.move(-planeSpeed2, planeSpeed2);
				plane4.setRotation(225);
				break;
			case 3:
				plane4.move(-planeSpeed2, -planeSpeed2);
				plane4.setRotation(315);
				break;
			case 4:
				plane4.move(planeSpeed2, -planeSpeed2);
				plane4.setRotation(45);
				break;
			}
			switch (plane5corner) {
			case 0:
				plane5.setPosition(2000 * 4.f, 1160 * 4.f);
				break;
			case 1:
				plane5.move(planeSpeed2, planeSpeed2);
				plane5.setRotation(135);
				break;
			case 2:
				plane5.move(-planeSpeed2, planeSpeed2);
				plane5.setRotation(225);
				break;
			case 3:
				plane5.move(-planeSpeed2, -planeSpeed2);
				plane5.setRotation(315);
				break;
			case 4:
				plane5.move(planeSpeed2, -planeSpeed2);
				plane5.setRotation(45);
				break;
			}
			switch (plane6corner) {
			case 0:
				plane6.setPosition(2000 * 4.f, 1160 * 4.f);
				break;
			case 1:
				plane6.move(planeSpeed2, planeSpeed2);
				plane6.setRotation(135);
				break;
			case 2:
				plane6.move(-planeSpeed2, planeSpeed2);
				plane6.setRotation(225);
				break;
			case 3:
				plane6.move(-planeSpeed2, -planeSpeed2);
				plane6.setRotation(315);
				break;
			case 4:
				plane6.move(planeSpeed2, -planeSpeed2);
				plane6.setRotation(45);
				break;
			}
			if (!gameOver) {
				if (plane1Hitbox.getGlobalBounds().intersects(playerHitbox1.getGlobalBounds())) {
					leaderboardManager.UploadScore(highScore);
					leaderboardManager.UploadWave(highWave);
					gameOver = true;
					genret.stop();
					death.play();
					menuMusic.setLoop(true);
					menuMusic.play();
				}
				if (plane2Hitbox.getGlobalBounds().intersects(playerHitbox1.getGlobalBounds())) {
					leaderboardManager.UploadScore(highScore);
					leaderboardManager.UploadWave(highWave);
					gameOver = true;
					genret.stop();
					death.play();
					menuMusic.setLoop(true);
					menuMusic.play();
				}
				if (plane3Hitbox.getGlobalBounds().intersects(playerHitbox1.getGlobalBounds())) {
					leaderboardManager.UploadScore(highScore);
					leaderboardManager.UploadWave(highWave);
					gameOver = true;
					genret.stop();
					death.play();
					menuMusic.setLoop(true);
					menuMusic.play();
				}
				if (plane4Hitbox.getGlobalBounds().intersects(playerHitbox1.getGlobalBounds())) {
					leaderboardManager.UploadScore(highScore);
					leaderboardManager.UploadWave(highWave);
					gameOver = true;
					genret.stop();
					death.play();
					menuMusic.setLoop(true);
					menuMusic.play();
				}
				if (plane5Hitbox.getGlobalBounds().intersects(playerHitbox1.getGlobalBounds())) {
					leaderboardManager.UploadScore(highScore);
					leaderboardManager.UploadWave(highWave);
					gameOver = true;
					genret.stop();
					death.play();
					menuMusic.setLoop(true);
					menuMusic.play();
				}
				if (plane6Hitbox.getGlobalBounds().intersects(playerHitbox1.getGlobalBounds())) {
					leaderboardManager.UploadScore(highScore);
					leaderboardManager.UploadWave(highWave);
					gameOver = true;
					genret.stop();
					death.play();
					menuMusic.setLoop(true);
					menuMusic.play();
				}
			}
			// Player rotation (logic)
			if (rotateLeft) {
				player.rotate(-playerSpeed);
				if (!shoot) {
					bombRotation -= playerSpeed;
				}
			}
			if (rotateRight) {
				player.rotate(playerSpeed);
				if (!shoot) {
					bombRotation += playerSpeed;
				}
			}
			// Move bomb
			if (shoot) {
				if (bombShoot) {
					bomb.move(x, y);
				}
				if (!bombShoot) {
					grenade.move(x, y);
				}
			}
			// Spawn grenade
			if (shots >= 15) {
				if ((grenadePos.x > (1920 / 2) - 250 && grenadePos.x < (1920 / 2) + 250 && grenadePos.y > (1080 / 2) - 250 && grenadePos.y < (1080 / 2) + 250) || grenadePos.x < 150 || grenadePos.x > 1920 - 150 || grenadePos.y < 150 || grenadePos.y > 1080 - 150) {
					grenade.setPosition(rand() % (1920 - 100) + 1, rand() % (1080 - 100) + 1);
				}
				else {
					shots = 0;
					pickable = true;
				}
				grenade.setRotation((rand() % 360) + 1);
			}
			if (bombHitbox.getGlobalBounds().intersects(grenadeHitbox.getGlobalBounds()) && pickable && shoot) {
				switchTo = true;
				pickable = false;
				powerup.play();
			}
			if (switchTo) {
				grenade.setPosition(1920 * 2.f, 1080 * 2.f);
			}
			if (!bombShoot) {
				bomb.setPosition(1920 * 5.f, 1080 * 5.f);
			}
			// Attach projectiles to player
			bomb.setRotation(bombRotation);
			// Calculate projectile radians
			bombRadians = ((2.f * PI / 360.f) * bomb.getRotation());
			x = bombSpeed * sin(bombRadians);
			y = bombSpeed * -cos(bombRadians);

			if (!bombShoot && !shoot) {
				grenade.setRotation(bomb.getRotation());
			}
			// Timer
			frames++;
			if (frames == 6.f) {
				timer += 6.f / framerate;
				waveTimer += 6.f / framerate;
				if (explosionBool && expTimer > 0) {
					expTimer -= 6.f / framerate;
				}
				if (expTimer < 0) {
					explosion.setPosition(1920 * 3.f, 1080 * 3.f);
					explosionBool = false;
					expTimer = 5;
				}
				frames = 0;
			}
			// Update speeds
			playerSpeed = ((15.f * wave) + 180.f) / (3.f * framerate);
			bombSpeed = (((90.f * wave) + 2100.f) / (5.f * framerate));
			planeSpeed = (((90.f * wave) + 300.f) / (5.f * framerate));
			planeSpeed2 = ((((90.f * wave) + 300.f) / (5.f * framerate))) / 2;
			// Change wave
			if (!gameOver) {
				if (waveTimer >= 30) {
					lastCorner1 = corner1;
						wave += 1.f;
						wave5 += 1.f;
					corner1 = rand() % 4 + 1;
					if (wave5 >= 5) {
						corner2 = rand() % 4 + 1;
						wave5 = 0;
					}
					else {
						corner2 = 0.f;
					}
					waveTimer = 0.f;
					newWave.play();
				}
				if (corner1 == corner2) {
					corner2 = rand() % 4 + 1;
				}
				if (lastCorner1 == corner1) {
					corner1 = rand() % 4 + 1;
				}
			}
		}

		renderTexture.clear(Color(121, 121, 121));
		renderTexture.draw(background1);
		if (!menu && versus) {
			renderTexture.draw(MP1explosion);
			renderTexture.draw(MP2explosion);
			renderTexture.draw(MP1bomb);
			renderTexture.draw(MP2bomb);
			if (MP1pickable || !MP1bombShoot) {
				renderTexture.draw(MP1grenade);
			}
			if (MP2pickable || !MP2bombShoot) {
				renderTexture.draw(MP2grenade);
			}
			renderTexture.draw(MP1player);
			renderTexture.draw(MP2player);
			if (MP1plane1.getPosition().x < 960) {
				renderTexture.draw(MP1plane1);
			}
			if (MP1plane2.getPosition().x < 960) {
				renderTexture.draw(MP1plane2);
			}
			if (MP1plane3.getPosition().x < 960) {
				renderTexture.draw(MP1plane3);
			}
			if (MP1plane4.getPosition().x < 960) {
				renderTexture.draw(MP1plane4);
			}
			if (MP1plane5.getPosition().x < 960) {
				renderTexture.draw(MP1plane5);
			}
			if (MP1plane6.getPosition().x < 960) {
				renderTexture.draw(MP1plane6);
			}
			if (MP2plane1.getPosition().x > 960) {
				renderTexture.draw(MP2plane1);
			}
			if (MP2plane2.getPosition().x > 960) {
				renderTexture.draw(MP2plane2);
			}
			if (MP2plane3.getPosition().x > 960) {
				renderTexture.draw(MP2plane3);
			}
			if (MP2plane4.getPosition().x > 960) {
				renderTexture.draw(MP2plane4);
			}
			if (MP2plane5.getPosition().x > 960) {
				renderTexture.draw(MP2plane5);
			}
			if (MP2plane6.getPosition().x > 960) {
				renderTexture.draw(MP2plane6);
			}
			if (MP1plane1Death) {
				renderTexture.draw(MP1deathEffect1);
			}
			if (MP1plane2Death) {
				renderTexture.draw(MP1deathEffect2);
			}
			if (MP1plane3Death) {
				renderTexture.draw(MP1deathEffect3);
			}
			if (MP1plane4Death) {
				renderTexture.draw(MP1deathEffect4);
			}
			if (MP1plane5Death) {
				renderTexture.draw(MP1deathEffect5);
			}
			if (MP1plane6Death) {
				renderTexture.draw(MP1deathEffect6);
			}
			if (MP2plane1Death) {
				renderTexture.draw(MP2deathEffect1);
			}
			if (MP2plane2Death) {
				renderTexture.draw(MP2deathEffect2);
			}
			if (MP2plane3Death) {
				renderTexture.draw(MP2deathEffect3);
			}
			if (MP2plane4Death) {
				renderTexture.draw(MP2deathEffect4);
			}
			if (MP2plane5Death) {
				renderTexture.draw(MP2deathEffect5);
			}
			if (MP2plane6Death) {
				renderTexture.draw(MP2deathEffect6);
			}
			if (showHitboxes) {
				renderTexture.draw(MP1bombHitbox);
				renderTexture.draw(MP2bombHitbox);
				renderTexture.draw(MP1playerHitbox);
				renderTexture.draw(MP2playerHitbox);
				renderTexture.draw(MP1grenadeHitbox);
				renderTexture.draw(MP2grenadeHitbox);
				if (MP1plane1.getPosition().x < 960) {
					renderTexture.draw(MP1plane1Hitbox);
				}
				if (MP1plane2.getPosition().x < 960) {
					renderTexture.draw(MP1plane2Hitbox);
				}
				if (MP1plane3.getPosition().x < 960) {
					renderTexture.draw(MP1plane3Hitbox);
				}
				if (MP1plane4.getPosition().x < 960) {
					renderTexture.draw(MP1plane4Hitbox);
				}
				if (MP1plane5.getPosition().x < 960) {
					renderTexture.draw(MP1plane5Hitbox);
				}
				if (MP1plane6.getPosition().x < 960) {
					renderTexture.draw(MP1plane6Hitbox);
				}
				if (MP2plane1.getPosition().x > 960) {
					renderTexture.draw(MP2plane1Hitbox);
				}
				if (MP2plane2.getPosition().x > 960) {
					renderTexture.draw(MP2plane2Hitbox);
				}
				if (MP2plane3.getPosition().x > 960) {
					renderTexture.draw(MP2plane3Hitbox);
				}
				if (MP2plane4.getPosition().x > 960) {
					renderTexture.draw(MP2plane4Hitbox);
				}
				if (MP2plane5.getPosition().x > 960) {
					renderTexture.draw(MP2plane5Hitbox);
				}
				if (MP2plane6.getPosition().x > 960) {
					renderTexture.draw(MP2plane6Hitbox);
				}
			}
			renderTexture.draw(MP1scoreText);
			renderTexture.draw(MP1waveText);
			renderTexture.draw(MP2scoreText);
			renderTexture.draw(MP2waveText);
			renderTexture.draw(divider);
		}
		if (!menu && !versus && !MPWarning) {
			// Update window
			if (pickable || !bombShoot) {
				renderTexture.draw(grenade);
			}
			renderTexture.draw(explosion);
			renderTexture.draw(bomb);
			renderTexture.draw(player);
			renderTexture.draw(plane1);
			renderTexture.draw(plane2);
			renderTexture.draw(plane3);
			renderTexture.draw(plane4);
			renderTexture.draw(plane5);
			renderTexture.draw(plane6);
			renderTexture.draw(scoreText);
			renderTexture.draw(waveText);
			if (plane1Death) {
				renderTexture.draw(deathEffect1);
			}
			if (plane2Death) {
				renderTexture.draw(deathEffect2);
			}
			if (plane3Death) {
				renderTexture.draw(deathEffect3);
			}
			if (plane4Death) {
				renderTexture.draw(deathEffect4);
			}
			if (plane5Death) {
				renderTexture.draw(deathEffect5);
			}
			if (plane6Death) {
				renderTexture.draw(deathEffect6);
			}
			if (showHitboxes) {
				renderTexture.draw(grenadeHitbox);
				renderTexture.draw(bombHitbox);
				renderTexture.draw(playerHitbox1);
				renderTexture.draw(plane1Hitbox);
				renderTexture.draw(plane2Hitbox);
				renderTexture.draw(plane3Hitbox);
				renderTexture.draw(plane4Hitbox);
				renderTexture.draw(plane5Hitbox);
				renderTexture.draw(plane6Hitbox);
			}
			if (gameOver) {
				renderTexture.draw(gameOverScreen);
				renderTexture.draw(bestScoreText);
				renderTexture.draw(lastScoreText);
				renderTexture.draw(restartButton);
				renderTexture.draw(menuButton);
			}
		}
		if (menu) {
			player.setPosition(1920 / 2.f, 1080 / 2.f);
			bomb.setPosition(1920 / 2.f, 1080 / 2.f);
			if (seasonalShop) {
				renderTexture.draw(newYearsText);
				renderTexture.draw(easterText);
				renderTexture.draw(patrickText);
				renderTexture.draw(julyText);
				renderTexture.draw(halloweenText);
				renderTexture.draw(thanksgivingText);
				renderTexture.draw(winterText);
				renderTexture.draw(background1Overlay);
			}
			renderTexture.draw(backButton);
			renderTexture.draw(titleText);
			if (time(NULL) >= 1734411600 && time(NULL) < 1735448399) {
				claimCandyCaneCannon = true;
				claimFestivePlane = true;
			}
			if (!leaderboard && !seasonalShop && !shop && !credit && !setting && !skins && !vault && !lobby) {
				renderTexture.draw(playButton);
				renderTexture.draw(leaderboardButton);
				renderTexture.draw(creditsButton);
				renderTexture.draw(settingsButton);
				renderTexture.draw(shopButton);
				renderTexture.draw(skinsButton);
				renderTexture.draw(versusButton);
				renderTexture.draw(seasonalShopButton);
				renderTexture.draw(comingSoonOverlay);
				renderTexture.draw(discord);
				renderTexture.draw(youtube);
				renderTexture.draw(steam);
				renderTexture.draw(versionText);
				renderTexture.draw(steamText);
				renderTexture.draw(devText);
				if (time(NULL) >= 1734411600 && time(NULL) < 1736485200) {
					renderTexture.draw(ornament);
				}
				renderTexture.draw(cannoneer);
				if (exiting) {
					renderTexture.draw(pauseMenu);
					renderTexture.draw(pauseText);
					renderTexture.draw(returnButton);
					renderTexture.draw(exitButton);
				}
			}
			if (lobby) {
				renderTexture.draw(MP1Text);
				renderTexture.draw(MP2Text);
				renderTexture.draw(MPText1);
				renderTexture.draw(MPText2);
				renderTexture.draw(MPWinsText);
				renderTexture.draw(MP1Avatar);
				renderTexture.draw(MP2Avatar);
				renderTexture.draw(joinText);
				renderTexture.draw(rulesText);
				renderTexture.draw(chatBox);
				renderTexture.draw(chatBoxText);
				renderTexture.draw(chatText);
			}
			if (vault) {
				renderTexture.draw(santa);
				renderTexture.draw(textbox);
				renderTexture.draw(textboxText);
				renderTexture.draw(rewardText);
			}
			if (skins) {
				if (cannonSkin) {
					renderTexture.draw(eventPlayerModel);
					if (page == 1) {
						renderTexture.draw(icon1);
						renderTexture.draw(icon2);
						renderTexture.draw(icon3);
						renderTexture.draw(icon4);
						renderTexture.draw(icon5);
						renderTexture.draw(icon6);
						renderTexture.draw(icon7);
						renderTexture.draw(icon8);
						renderTexture.draw(icon21);
						renderTexture.draw(icon38);
						renderTexture.draw(icon39);
						renderTexture.draw(icon40);
					}
					if (page == 2) {
						renderTexture.draw(icon47);
						renderTexture.draw(icon48);
						renderTexture.draw(icon49);
						renderTexture.draw(icon50);
						renderTexture.draw(icon62);
					}
					if (page == 1) {
						if (!claimCandyCaneCannon) {
							renderTexture.draw(lock2);
						}
						if (!claimFireCannon) {
							renderTexture.draw(lock3);
						}
						if (!claimYippeeCannon) {
							renderTexture.draw(lock4);
						}
						if (!claimGoldenCannon) {
							renderTexture.draw(lock5);
						}
						if (!claimLogicalCannon) {
							renderTexture.draw(lock6);
						}
						if (!claimPeashooterCannon) {
							renderTexture.draw(lock7);
						}
						if (!claimSugarCannon) {
							renderTexture.draw(lock8);
						}
						if (!claimFlameCannon) {
							renderTexture.draw(lock9);
						}
						if (!claimGingerbreadCannon) {
							renderTexture.draw(lock10);
						}
						if (!claimSnowmanCannon) {
							renderTexture.draw(lock11);
						}
						if (!claimPresentCannon) {
							renderTexture.draw(lock12);
						}
					}
					if (page == 2) {
						if (!claimDeadpoolCannon) {
							renderTexture.draw(lock);
						}
						if (!claimShockCannon) {
							renderTexture.draw(lock2);
						}
						if (!claimBirdoCannon) {
							renderTexture.draw(lock3);
						}
						if (!claimHeartsCannon) {
							renderTexture.draw(lock4);
						}
						if (!claimApocCannon) {
							renderTexture.draw(lock5);
						}
					}
					if (page == 1) {
						renderTexture.draw(rightArrow);
					}
					if (page == 2) {
						renderTexture.draw(leftArrow);
					}
					if (page == 1 && equippedCannon <= 11) {
						renderTexture.draw(selected);
					}
					if (page == 2 && equippedCannon >= 12) {
						renderTexture.draw(selected);
					}
				}
				if (bombSkin) {
					renderTexture.draw(eventBombModel);
					renderTexture.draw(icon9);
					renderTexture.draw(icon10);
					renderTexture.draw(icon11);
					renderTexture.draw(icon12);
					renderTexture.draw(icon13);
					renderTexture.draw(icon14);
					renderTexture.draw(icon41);
					renderTexture.draw(icon42);
					renderTexture.draw(icon51);
					renderTexture.draw(icon52);
					renderTexture.draw(icon57);
					renderTexture.draw(icon63);
					if (!claimFireBomb) {
						renderTexture.draw(lock2);
					}
					if (!claimIcyBomb) {
						renderTexture.draw(lock3);
					}
					if (!claimOrangeBomb) {
						renderTexture.draw(lock4);
					}
					if (!claimPeppermintBomb) {
						renderTexture.draw(lock5);
					}
					if (!claimYippeeBomb) {
						renderTexture.draw(lock6);
					}
					if (!claimSantasBomb) {
						renderTexture.draw(lock7);
					}
					if (!claimBellBomb) {
						renderTexture.draw(lock8);
					}
					if (!claimYoshiBomb) {
						renderTexture.draw(lock9);
					}
					if (!claimBirdoBomb) {
						renderTexture.draw(lock10);
					}
					if (!claimLogicalBomb) {
						renderTexture.draw(lock11);
					}
					if (!claimApocBomb) {
						renderTexture.draw(lock12);
					}
					renderTexture.draw(selected);
				}
				if (grenadeSkin) {
					renderTexture.draw(eventGrenadeModel);
					if (page == 1) {
						renderTexture.draw(icon22);
						renderTexture.draw(icon23);
						renderTexture.draw(icon24);
						renderTexture.draw(icon25);
						renderTexture.draw(icon26);
						renderTexture.draw(icon15);
						renderTexture.draw(icon16);
						renderTexture.draw(icon17);
						renderTexture.draw(icon18);
						renderTexture.draw(icon53);
						renderTexture.draw(icon54);
						renderTexture.draw(icon55);
					}
					if (page == 2) {
						renderTexture.draw(icon56);
						renderTexture.draw(icon64);
					}
					if (page == 1) {
						if (!claimFireGrenade) {
							renderTexture.draw(lock2);
						}
						if (!claimYippeeGrenade) {
							renderTexture.draw(lock3);
						}
						if (!claimLogicalGrenade) {
							renderTexture.draw(lock4);
						}
						if (!claimChocolateGrenade) {
							renderTexture.draw(lock5);
						}
						if (!claimChristmasGrenade) {
							renderTexture.draw(lock6);
						}
						if (!claimGarlandGrenade) {
							renderTexture.draw(lock7);
						}
						if (!claimIceGrenade) {
							renderTexture.draw(lock8);
						}
						if (!claimSantaGrenade) {
							renderTexture.draw(lock9);
						}
						if (!claimDynamiteGrenade) {
							renderTexture.draw(lock10);
						}
						if (!claimNukeGrenade) {
							renderTexture.draw(lock11);
						}
						if (!claimSmokeGrenade) {
							renderTexture.draw(lock12);
						}
					}
					if (page == 2) {
						if (!claimHolyHandGrenade) {
							renderTexture.draw(lock);
						}
						if (!claimApocGrenade) {
							renderTexture.draw(lock2);
						}
					}
					if (page == 1) {
						renderTexture.draw(rightArrow);
					}
					if (page == 2) {
						renderTexture.draw(leftArrow);
					}
					if (page == 1 && equippedGrenade <= 11) {
						renderTexture.draw(selected);
					}
					if (page == 2 && equippedGrenade >= 12) {
						renderTexture.draw(selected);
					}
				}
				if (explosionSkin) {
					renderTexture.draw(eventExplosionModel);
					renderTexture.draw(icon27);
					renderTexture.draw(icon28);
					renderTexture.draw(icon29);
					renderTexture.draw(icon30);
					renderTexture.draw(icon31);
					renderTexture.draw(icon19);
					renderTexture.draw(icon43);
					renderTexture.draw(icon58);
					renderTexture.draw(icon59);
					renderTexture.draw(icon60);
					renderTexture.draw(icon65);
					if (!claimYippeeExplosion) {
						renderTexture.draw(lock2);
					}
					if (!claimFestiveExplosion) {
						renderTexture.draw(lock3);
					}
					if (!claimSnowyExplosion) {
						renderTexture.draw(lock4);
					}
					if (!claimGingerbreadExplosion) {
						renderTexture.draw(lock5);
					}
					if (!claimElfExplosion) {
						renderTexture.draw(lock6);
					}
					if (!claimSnowExplosion) {
						renderTexture.draw(lock7);
					}
					if (!claimLogicalExplosion) {
						renderTexture.draw(lock8);
					}
					if (!claimMushroomExplosion) {
						renderTexture.draw(lock9);
					}
					if (!claimSmokeExplosion) {
						renderTexture.draw(lock10);
					}
					if (!claimApocExplosion) {
						renderTexture.draw(lock11);
					}
					renderTexture.draw(selected);
				}
				if (planeSkin) {
					renderTexture.draw(eventPlaneModel);
					renderTexture.draw(icon32);
					renderTexture.draw(icon33);
					renderTexture.draw(icon34);
					renderTexture.draw(icon35);
					renderTexture.draw(icon36);
					renderTexture.draw(icon37);
					renderTexture.draw(icon44);
					renderTexture.draw(icon45);
					renderTexture.draw(icon46);
					renderTexture.draw(icon61);
					renderTexture.draw(icon66);
					if (!claimYippeePlane) {
						renderTexture.draw(lock2);
					}
					if (!claimFirePlane) {
						renderTexture.draw(lock3);
					}
					if (!claimLogicalPlane) {
						renderTexture.draw(lock4);
					}
					if (!claimFestivePlane) {
						renderTexture.draw(lock5);
					}
					if (!claimCookiePlane) {
						renderTexture.draw(lock6);
					}
					if (!claimRudolphPlane) {
						renderTexture.draw(lock7);
					}
					if (!claimSantasPlane) {
						renderTexture.draw(lock8);
					}
					if (!claimTreePlane) {
						renderTexture.draw(lock9);
					}
					if (!claimFighterPlane) {
						renderTexture.draw(lock10);
					}
					if (!claimApocPlane) {
						renderTexture.draw(lock11);
					}
					renderTexture.draw(selected);
				}
				renderTexture.draw(cannonButton);
				renderTexture.draw(bombButton);
				renderTexture.draw(grenadeButton);
				renderTexture.draw(explosionButton);
				renderTexture.draw(planeButton);
			}
			if (leaderboard) {
				renderTexture.draw(resetDataButton);
				renderTexture.draw(scoreTitleText);
				renderTexture.draw(waveTitleText);
				renderTexture.draw(scoreLeaderboardText);
				renderTexture.draw(waveLeaderboardText);
				if (resetting) {
					renderTexture.draw(pauseMenu);
					renderTexture.draw(pauseText);
					renderTexture.draw(returnButton);
					renderTexture.draw(exitButton);
				}
			}
			if (shop) {
				renderTexture.draw(cannonShopButton);
				renderTexture.draw(bombShopButton);
				renderTexture.draw(grenadeShopButton);
				renderTexture.draw(explosionShopButton);
				renderTexture.draw(planeShopButton);
				renderTexture.draw(treasureText);
				renderTexture.draw(treasureChest);
				//renderTexture.draw(unlockAllSkinsButton);
				if (cannonShop) {
					renderTexture.draw(playerModel);
					renderTexture.draw(buyButton);
					renderTexture.draw(playerModel2);
					renderTexture.draw(buyButton2);
					renderTexture.draw(playerModel3);
					renderTexture.draw(buyButton3);
					renderTexture.draw(playerModel4);
					renderTexture.draw(buyButton4);
					renderTexture.draw(playerModel5);
					renderTexture.draw(buyButton7);
					renderTexture.draw(playerModel6);
					renderTexture.draw(buyButton15);
					renderTexture.draw(playerModel7);
					renderTexture.draw(buyButton16);
					renderTexture.draw(playerModel8);
					renderTexture.draw(buyButton17);
					renderTexture.draw(playerModel9);
					renderTexture.draw(buyButton18);
					renderTexture.draw(playerModel10);
					renderTexture.draw(buyButton19);
					renderTexture.draw(playerModel11);
					renderTexture.draw(buyButton31);
					renderTexture.draw(price1);
					renderTexture.draw(price2);
					renderTexture.draw(price3);
					renderTexture.draw(price4);
					renderTexture.draw(price5);
					renderTexture.draw(price6);
					renderTexture.draw(price7);
					renderTexture.draw(price8);
					renderTexture.draw(price9);
					renderTexture.draw(price10);
					renderTexture.draw(price11);
				}
				if (bombShop) {
					renderTexture.draw(bombModel);
					renderTexture.draw(buyButton5);
					renderTexture.draw(bombModel2);
					renderTexture.draw(buyButton6);
					renderTexture.draw(bombModel3);
					renderTexture.draw(buyButton20);
					renderTexture.draw(bombModel4);
					renderTexture.draw(buyButton21);
					renderTexture.draw(bombModel5);
					renderTexture.draw(buyButton26);
					renderTexture.draw(bombModel6);
					renderTexture.draw(buyButton32);
					renderTexture.draw(price1);
					renderTexture.draw(price2);
					renderTexture.draw(price3);
					renderTexture.draw(price4);
					renderTexture.draw(price5);
					renderTexture.draw(price6);
				}
				if (grenadeShop) {
					renderTexture.draw(grenadeModel);
					renderTexture.draw(buyButton8);
					renderTexture.draw(grenadeModel2);
					renderTexture.draw(buyButton9);
					renderTexture.draw(grenadeModel3);
					renderTexture.draw(buyButton10);
					renderTexture.draw(grenadeModel4);
					renderTexture.draw(buyButton22);
					renderTexture.draw(grenadeModel5);
					renderTexture.draw(buyButton23);
					renderTexture.draw(grenadeModel6);
					renderTexture.draw(buyButton24);
					renderTexture.draw(grenadeModel7);
					renderTexture.draw(buyButton25);
					renderTexture.draw(grenadeModel8);
					renderTexture.draw(buyButton33);
					renderTexture.draw(price1);
					renderTexture.draw(price2);
					renderTexture.draw(price3);
					renderTexture.draw(price4);
					renderTexture.draw(price5);
					renderTexture.draw(price6);
					renderTexture.draw(price7);
					renderTexture.draw(price8);
				}
				if (explosionShop) {
					renderTexture.draw(explosionModel);
					renderTexture.draw(buyButton11);
					renderTexture.draw(explosionModel2);
					renderTexture.draw(buyButton27);
					renderTexture.draw(explosionModel3);
					renderTexture.draw(buyButton28);
					renderTexture.draw(explosionModel4);
					renderTexture.draw(buyButton29);
					renderTexture.draw(explosionModel5);
					renderTexture.draw(buyButton34);
					renderTexture.draw(price1);
					renderTexture.draw(price2);
					renderTexture.draw(price3);
					renderTexture.draw(price4);
					renderTexture.draw(price5);
				}
				if (planeShop) {
					renderTexture.draw(planeModel);
					renderTexture.draw(buyButton12);
					renderTexture.draw(planeModel2);
					renderTexture.draw(buyButton13);
					renderTexture.draw(planeModel3);
					renderTexture.draw(buyButton14);
					renderTexture.draw(planeModel4);
					renderTexture.draw(buyButton30);
					renderTexture.draw(planeModel5);
					renderTexture.draw(buyButton35);
					renderTexture.draw(price1);
					renderTexture.draw(price2);
					renderTexture.draw(price3);
					renderTexture.draw(price4);
					renderTexture.draw(price5);
				}
			}
			if (credit) {
				renderTexture.draw(creditsText, &creditsFadeShader);
				renderTexture.draw(creditsThanksText, &creditsFadeShader);
			}
			if (setting) {
				if (audio) {
					renderTexture.draw(bar);
					renderTexture.draw(dot);
					renderTexture.draw(bar2);
					renderTexture.draw(dot2);
					renderTexture.draw(musicText);
					renderTexture.draw(SFXText);
				}
				if (display) {
					renderTexture.draw(bar3);
					renderTexture.draw(dot3);
					renderTexture.draw(bar4);
					renderTexture.draw(dot4);
					renderTexture.draw(satText);
					renderTexture.draw(conText);
					renderTexture.draw(saturationText);
					renderTexture.draw(contrastText);
					renderTexture.draw(scanlinesBox);
					renderTexture.draw(scanText);
					renderTexture.draw(fontBox);
					renderTexture.draw(fontText);
					/*renderTexture.draw(fullscreenBox);
					renderTexture.draw(fullscreenText);*/
					renderTexture.draw(frameText);
					renderTexture.draw(frameBox);
					renderTexture.draw(frameBoxText);
					renderTexture.draw(vsyncText);
					renderTexture.draw(vsyncBox);
					renderTexture.draw(unlimitedText);
					renderTexture.draw(unlimitedBox);
				}
				renderTexture.draw(audioButton);
				renderTexture.draw(displayButton);
			}
			if (eventActive) {
				renderTexture.draw(pauseMenu);
				renderTexture.draw(pauseText);
				renderTexture.draw(eventText);
				renderTexture.draw(returnButton);
				if (time(NULL) >= 1734411600 && time(NULL) <= 1735362000 && !day1Claimed) {
					renderTexture.draw(eventPlayerModel);
				}
				if (time(NULL) >= 1734498000 && time(NULL) <= 1734584399 && !day2Claimed) {
					renderTexture.draw(eventPlaneModel);
				}
				if (time(NULL) >= 1734584400 && time(NULL) <= 1734670799 && !day3Claimed) {
					renderTexture.draw(eventBombModel);
				}
				if (time(NULL) >= 1734670800 && time(NULL) <= 1734757199 && !day4Claimed) {
					renderTexture.draw(eventExplosionModel);
				}
				if (time(NULL) >= 1734757200 && time(NULL) <= 1734843599 && !day5Claimed) {
					renderTexture.draw(eventPlayerModel);
				}
				if (time(NULL) >= 1734843600 && time(NULL) <= 1734929999 && !day6Claimed) {
					renderTexture.draw(eventGrenadeModel);
				}
				if (time(NULL) >= 1734930000 && time(NULL) <= 1735016399 && !day7Claimed) {
					renderTexture.draw(eventBombModel);
				}
				if (time(NULL) >= 1735016400 && time(NULL) <= 1735102799 && !day8Claimed) {
					renderTexture.draw(eventPlaneModel);
				}
				if (time(NULL) >= 1735102800 && time(NULL) <= 1735189199 && !day9Claimed) {
					renderTexture.draw(eventExplosionModel);
				}
				if (time(NULL) >= 1735189200 && time(NULL) <= 1735275599 && !day10Claimed) {
					renderTexture.draw(eventExplosionModel);
				}
				if (time(NULL) >= 1735275600 && time(NULL) <= 1735361999 && !day11Claimed) {
					renderTexture.draw(eventBombModel);
				}
				if (time(NULL) >= 1735362000 && time(NULL) <= 1735448399 && !day12Claimed) {
					renderTexture.draw(eventPlayerModel);
				}
			}
			if (showHitboxes) {
				renderTexture.draw(mouseHitbox);
			}
		}
		if (pause) {
			renderTexture.draw(pauseMenu);
			renderTexture.draw(pauseText);
			renderTexture.draw(returnButton);
			renderTexture.draw(exitButton);
			renderTexture.draw(saveButton);
			if (showHitboxes) {
				renderTexture.draw(mouseHitbox);
			}
		}
		if (MPWarning) {
			renderTexture.draw(pauseMenu);
			renderTexture.draw(returnButton);
			renderTexture.draw(MPWarningText);
			renderTexture.draw(MPWarningBox);
			renderTexture.draw(MPWarningBoxText);
		}
		if (showFPS) {
			renderTexture.draw(FPSText);
		}
		renderTexture.display();

		Sprite sceneSprite(renderTexture.getTexture());

		window.setView(view);
		window.clear(Color(121, 121, 121));
		window.draw(sceneSprite, &shader);
		// Display window
		window.display();
	}
	// End application
	return 0;
}