#pragma once
#include "BlockLegacy.h"
#include "MultiPlayerLevel.h"

class Actor {
private:
	char pad_0008[256]; //0x0008
public:
	uint64_t entityId; //0x0108
private:
	char pad_0110[16]; //0x0110
public:
	Vec2 bodyRot; //0x0120
private:
	char pad_0128[152]; //0x0128
public:
	bool onGround; //0x01C0
private:
	char pad_01C1[95]; //0x01C1
	char pad_0224[292]; //0x0224
public:
	class BlockSource* BlockSource; //0x0348
private:
	char pad_0350[8]; //0x0350
public:
	class MultiPlayerLevel* MultiPlayerLevel; //0x0358
private:
	char pad_0360[340]; //0x0360
public:
	Vec2 collision; //0x04B4
private:
	char pad_04BC[24]; //0x04BC
public:
	Vec3 velocity; //0x04D4
private:
	char pad_04E0[880]; //0x04E0

private:
	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
public:
	virtual void reset(void);
	virtual void getOnDeathExperience(void);
	virtual int getOwnerEntityType(void);
	virtual void remove(void);
	virtual void setPos(Vec3 const&);
private:
	virtual void Function13();
public:
	virtual Vec3* getPos();
	virtual Vec3* getPosOld();
	virtual Vec3* getPosExtrapolated(float);
private:
	virtual void Function17();
public:
	virtual Vec3* getFiringPos(void);
	virtual void setRot(Vec3 const&);
private:
	virtual void Function20();
public:
	virtual void move(Vec3 const&);
private:
	virtual void Function22();
public:
	virtual float getInterpolatedBodyRot(float);
	virtual float getShadowHeightOffs(void);
private:
	virtual void Function25();
public:
	virtual float getYawSpeedInDegreesPerSecond(void);
	virtual float getInterpolatedWalkAnimSpeed(float);
private:
	virtual void Function28();
public:
	virtual void checkBlockCollisions(void);
private:
	virtual void Function30();
public:
	virtual bool isFireImmune(void);
private:
	virtual void Function32();
	virtual void Function33();
public:
	virtual void teleportTo(Vec3 const&, bool, int, int, uint64_t); //Last param is ActorUniqueID
	virtual void tryTeleportTo(Vec3 const&, bool, bool, int, int);
	virtual void chorusFruitTeleport(Vec3&);
	virtual void lerpTo(Vec3 const&, Vec2 const&, int);
	virtual void lerpMotion(Vec3 const&);
private:
	virtual void Function39();
public:
	virtual void normalTick(void);
	virtual void baseTick(void);
	virtual void rideTick(void);
	virtual void positionRider(Actor&, float);
	virtual float getRidingHeight(void);
	virtual void startRiding(Actor&);
	virtual void addRider(Actor&);
	virtual void flagRiderToRemove(Actor&);
private:
	virtual void Function48();
public:
	virtual bool intersects(Vec3 const&, Vec3 const&);
	virtual bool isFree(Vec3 const&);
private:
	virtual void Function51();
public:
	virtual bool isInWall(void);
	virtual bool isInvisible(void);
	virtual bool canShowNameTag(void);
private:
	virtual void Function55();
public:
	virtual void setNameTagVisible(bool);
private:
	virtual void Function57();
public:
	virtual __int64 getNameTagAsHash(void);
	virtual std::string getFormattedNameTag(void);
private:
	virtual void Function60();
public:
	virtual void setNameTag(std::string const&);
private:
	virtual void Function62();
	virtual void Function63();
	virtual void Function64();
public:
	virtual bool isInWater(void);
	virtual bool hasEnteredWater(void);
	virtual bool isImmersedInWater(void);
	virtual bool isInWaterOrRain(void);
	virtual bool isInLava(void);
	virtual bool isUnderLiquid(class MaterialType);
	virtual bool isOverWater(void);
	virtual void makeStuckInBlock(Vec3 const&);
private:
	virtual void Function73();
	virtual void Function74();
public:
	virtual float getShadowRadius(void);
	virtual Vec3* getHeadLookVector(float);
private:
	virtual void Function77();
public:
	virtual bool canSee(Vec3 const&);
	virtual bool canSee(Actor const&);
	virtual bool isSkyLit(float);
	virtual float getBrightness(float);
private:
	virtual void Function82();
	virtual void Function83();
public:
	virtual void onAboveBubbleColumn(bool);
	virtual void onInsideBubbleColumn(bool);
	virtual bool isImmobile(void);
	virtual bool isSilent(void);
	virtual bool isPickable();
private:
	virtual void Function89();
public:
	virtual bool isSleeping(void);
private:
	virtual void Function91();
public:
	virtual void setSneaking(bool);
	virtual bool isBlocking(void);
private:
	virtual void Function94();
public:
	virtual bool isAlive(void);
	virtual bool isOnFire(void);
	virtual bool isOnHotBlock(void);
private:
	virtual void Function98();
public:
	virtual bool isSurfaceMob(void);
private:
	virtual void Function100();
	virtual void Function101();
	virtual void Function102();
public:
	virtual bool canAttack(Actor*, bool);
	virtual void setTarget(Actor*);
private:
	virtual void Function105();
	virtual void Function106();
public:
	virtual void attack(Actor&);
	virtual void performRangedAttack(Actor&, float);
	virtual void adjustDamageAmount(int&);
	virtual int getEquipmentCount(void);
	virtual void setOwner(uint64_t); //Param is ActorUniqueID
	virtual void setSitting(bool);
private:
	virtual void Function113();
	virtual void Function114();
public:
	virtual int getInventorySize(void);
	virtual int getEquipSlots(void);
	virtual int getChestSlots(void);
	virtual void setStanding(bool);
	virtual bool canPowerJump(void);
	virtual void setCanPowerJump(bool);
	virtual bool isJumping(void);
	virtual bool isEnchanted(void);
private:
	virtual void Function123();
	virtual void Function124();
public:
	virtual bool shouldRender(void);
private:
	virtual void Function126();
	virtual void Function127();
	virtual void Function128();
public:
	virtual void animateHurt(void);
	virtual void doFireHurt(void);
	virtual void onLightningHit(void);
	virtual void onBounceStarted(void);
	virtual void feed(int);
	virtual void handleEntityEvent(class ActorEvent, int);
	virtual float getPickRadius(void);
	virtual void getActorRendererId(void);
	virtual void spawnAtLocation(class ItemStack const&, float);
	virtual void spawnAtLocation(class Block const&, int, float);
	virtual void spawnAtLocation(class Block const&, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(int, int);
	virtual void despawn(void);
	virtual void killed(Actor&);
private:
	virtual void Function144();
public:
	virtual void setArmor(int, class ItemStack const&);
	virtual class ItemStack getArmor(int);
private:
	virtual void Function147();
	virtual void Function148();
public:
	virtual float getModelScale(void);
	virtual class ItemStack getEquippedSlot(int);
	virtual void setEquippedSlot(int, class ItemStack const&);
	virtual class ItemStack getSelectedItem(void);
	virtual void setCarriedItem(class ItemStack const&);
	virtual void setOffhandSlot(class ItemStack const&);
	virtual class ItemStack getEquippedTotem(void);
	virtual void consumeTotem(void);
private:
	virtual void Function157();
	virtual void Function158();
	virtual void Function159();
	virtual void Function160();
public:
	virtual int getEntityTypeId(void);
	virtual void queryEntityRenderer(void);
	virtual __int64 getSourceUniqueID(void);
	virtual void setOnFire(int);
	virtual void getHandleWaterAABB(void);
	virtual void handleInsidePortal(Vec3 const&);
private:
	virtual void Function167();
public:
	virtual __int64 getPortalCooldown(void);
	virtual int getDimensionId(void);
private:
	virtual void Function170();
	virtual void Function171();
public:
	virtual void changeDimension(int, bool);
private:
	virtual void Function173();
public:
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float);
	virtual void handleFallDistanceOnServer(float, bool);
private:
	virtual void Function177();
	virtual void Function178();
public:
	virtual void onSynchedDataUpdate(int);
	virtual bool canAddRider(Actor&);
private:
	virtual void Function181();
	virtual void Function182();
public:
	virtual bool isInCaravan(void);
private:
	virtual void Function184();
public:
	virtual void tickLeash(void);
	virtual void sendMotionPacketIfNeeded(void);
private:
	virtual void Function187();
public:
	virtual void stopRiding(bool, bool, bool);
	virtual void startSwimming(void);
	virtual void stopSwimming(void);
private:
	virtual void Function191();
public:
	virtual int getCommandPermissionLevel(void);
private:
	virtual void Function193();
	virtual void Function194();
public:
	virtual int getDeathTime(void);
	virtual void heal(int);
	virtual bool isInvertedHealAndHarm(void);
private:
	virtual void Function198();
public:
	virtual bool canBeAffected(int);
private:
	virtual void Function200();
	virtual void Function201();
	virtual void Function202();
	virtual void Function203();
	virtual void Function204();
	virtual void Function205();
public:
	virtual void swing(void);
private:
	virtual void Function206();
	virtual void Function207();
	virtual void Function208();
	virtual void Function209();
public:
	virtual float getMapDecorationRotation(void);
	virtual float getRiderYRotation(Actor const&);
private:
	virtual void Function212();
	virtual void Function213();
public:
	virtual bool isCreative(void);
	virtual bool isAdventure(void);
	virtual void add(class ItemStack&);
	virtual void drop(class ItemStack const&, bool);
private:
	virtual void Function218();
	virtual void Function219();
	virtual void Function220();
public:
	virtual void setSize(float, float);
	virtual int getLifeSpan(void);
	virtual void onOrphan(void);
	virtual void wobble(void);
	virtual bool wasHurt(void);
	virtual void startSpinAttack(void);
	virtual void stopSpinAttack(void);
	virtual void setDamageNearbyMobs(bool);
private:
	virtual void Function229();
	virtual void Function230();
public:
	virtual void reloadLootTable(void);
private:
	virtual void Function232();
public:
	virtual void kill(void);
	virtual void die(void);
	virtual bool shouldTick(void);
	virtual void createMovementProxy(void);
private:
	virtual void Function237();
public:
	virtual void shouldTryMakeStepSound(void);
	virtual float getNextStep(float);
private:
	virtual void Function240();
public:
	virtual bool outOfWorld(void);
private:
	virtual void Function242();
public:
	virtual void markHurt(void);
private:
	virtual void Function244();
	virtual void Function245();
	virtual void Function246();
	virtual void Function247();
	virtual void Function248();
public:
	virtual void checkInsideBlocks(float);
	virtual void pushOutOfBlocks(Vec3 const&);
	virtual void updateWaterState(void);
	virtual void doWaterSplashEffect(void);
	virtual void spawnTrailBubbles(void);
	virtual void updateInsideBlock(void);
	virtual struct LootTable getLootTable(void);
private:
	virtual void Function256();
	virtual void Function257();
	virtual void Function258();
	virtual void Function259();
public:
	virtual void knockback(Actor*, int, float, float, float, float, float);
};