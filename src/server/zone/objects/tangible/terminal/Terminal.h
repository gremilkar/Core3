/*
 *	server/zone/objects/tangible/terminal/Terminal.h generated by engine3 IDL compiler 0.60
 */

#ifndef TERMINAL_H_
#define TERMINAL_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

#include "engine/lua/LuaObject.h"

#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {

class Terminal : public TangibleObject {
public:
	Terminal(LuaObject* templateData);

	void initializeTransientMembers();

protected:
	Terminal(DummyConstructorParameter* param);

	virtual ~Terminal();

	friend class TerminalHelper;
};

} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace terminal {

class TerminalImplementation : public TangibleObjectImplementation {

public:
	TerminalImplementation(LuaObject* templateData);

	TerminalImplementation(DummyConstructorParameter* param);

	void initializeTransientMembers();

	Terminal* _this;

	operator const Terminal*();

	DistributedObjectStub* _getStub();
protected:
	virtual ~TerminalImplementation();

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

	friend class Terminal;
};

class TerminalAdapter : public TangibleObjectAdapter {
public:
	TerminalAdapter(TerminalImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void initializeTransientMembers();

};

class TerminalHelper : public DistributedObjectClassHelper, public Singleton<TerminalHelper> {
	static TerminalHelper* staticInitializer;

public:
	TerminalHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<TerminalHelper>;
};

} // namespace terminal
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::terminal;

#endif /*TERMINAL_H_*/
