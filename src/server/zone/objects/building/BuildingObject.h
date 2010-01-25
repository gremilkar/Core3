/*
 *	server/zone/objects/building/BuildingObject.h generated by engine3 IDL compiler 0.60
 */

#ifndef BUILDINGOBJECT_H_
#define BUILDINGOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace cell {

class CellObject;

} // namespace cell
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::cell;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

#include "server/zone/objects/tangible/TangibleObject.h"

#include "engine/lua/LuaObject.h"

#include "engine/util/QuadTree.h"

#include "engine/util/QuadTreeEntry.h"

#include "system/util/SortedVector.h"

#include "system/util/Vector.h"

namespace server {
namespace zone {
namespace objects {
namespace building {

class BuildingObject : public TangibleObject {
public:
	BuildingObject(LuaObject* templateData);

	void initializeTransientMembers();

	void notifyInsert(QuadTreeEntry* obj);

	void notifyDissapear(QuadTreeEntry* obj);

	void notifyInsertToZone(SceneObject* object);

	void insert(QuadTreeEntry* obj);

	void remove(QuadTreeEntry* obj);

	void update(QuadTreeEntry* obj);

	void inRange(QuadTreeEntry* obj, float range);

	void sendTo(SceneObject* player, bool doClose = true);

	void sendBaselinesTo(SceneObject* player);

	void sendDestroyTo(SceneObject* player);

	void addCell(CellObject* cell);

	bool isStaticBuilding();

	CellObject* getCell(int idx);

	void setStaticBuilding(bool value);

	bool hasNotifiedObject(SceneObject* object);

	void addNotifiedObject(SceneObject* object);

	void removeNotifiedObject(SceneObject* object);

	void onEnter(PlayerCreature* player);

	void onExit(PlayerCreature* player);

protected:
	BuildingObject(DummyConstructorParameter* param);

	virtual ~BuildingObject();

	friend class BuildingObjectHelper;
};

} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building;

namespace server {
namespace zone {
namespace objects {
namespace building {

class BuildingObjectImplementation : public TangibleObjectImplementation, public QuadTree {
protected:
	Vector<ManagedReference<CellObject* > > cells;

	SortedVector<ManagedReference<SceneObject* > > notifiedObjects;

	bool staticBuilding;

public:
	BuildingObjectImplementation(LuaObject* templateData);

	BuildingObjectImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	void notifyInsert(QuadTreeEntry* obj);

	void notifyDissapear(QuadTreeEntry* obj);

	void notifyInsertToZone(SceneObject* object);

	void insert(QuadTreeEntry* obj);

	void remove(QuadTreeEntry* obj);

	void update(QuadTreeEntry* obj);

	void inRange(QuadTreeEntry* obj, float range);

	void sendTo(SceneObject* player, bool doClose = true);

	void sendBaselinesTo(SceneObject* player);

	void sendDestroyTo(SceneObject* player);

	void addCell(CellObject* cell);

	bool isStaticBuilding();

	CellObject* getCell(int idx);

	void setStaticBuilding(bool value);

	bool hasNotifiedObject(SceneObject* object);

	void addNotifiedObject(SceneObject* object);

	void removeNotifiedObject(SceneObject* object);

	virtual void onEnter(PlayerCreature* player);

	virtual void onExit(PlayerCreature* player);

	BuildingObject* _this;

	operator const BuildingObject*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~BuildingObjectImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();

	friend class BuildingObject;
};

class BuildingObjectAdapter : public TangibleObjectAdapter {
public:
	BuildingObjectAdapter(BuildingObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

	void notifyInsertToZone(SceneObject* object);

	void sendTo(SceneObject* player, bool doClose);

	void sendBaselinesTo(SceneObject* player);

	void sendDestroyTo(SceneObject* player);

	void addCell(CellObject* cell);

	bool isStaticBuilding();

	CellObject* getCell(int idx);

	void setStaticBuilding(bool value);

	bool hasNotifiedObject(SceneObject* object);

	void addNotifiedObject(SceneObject* object);

	void removeNotifiedObject(SceneObject* object);

	void onEnter(PlayerCreature* player);

	void onExit(PlayerCreature* player);

};

class BuildingObjectHelper : public DistributedObjectClassHelper, public Singleton<BuildingObjectHelper> {
	static BuildingObjectHelper* staticInitializer;

public:
	BuildingObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<BuildingObjectHelper>;
};

} // namespace building
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::building;

#endif /*BUILDINGOBJECT_H_*/
