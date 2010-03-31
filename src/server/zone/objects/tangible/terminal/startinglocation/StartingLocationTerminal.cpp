/*
 *	server/zone/objects/tangible/terminal/startinglocation/StartingLocationTerminal.cpp generated by engine3 IDL compiler 0.60
 */

#include "StartingLocationTerminal.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/Zone.h"

/*
 *	StartingLocationTerminalStub
 */

StartingLocationTerminal::StartingLocationTerminal() : Terminal(DummyConstructorParameter::instance()) {
	_setImplementation(new StartingLocationTerminalImplementation());
	_getImplementation()->_setStub(this);
}

StartingLocationTerminal::StartingLocationTerminal(DummyConstructorParameter* param) : Terminal(param) {
}

StartingLocationTerminal::~StartingLocationTerminal() {
}


void StartingLocationTerminal::initializeTransientMembers() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((StartingLocationTerminalImplementation*) _getImplementation())->initializeTransientMembers();
}

int StartingLocationTerminal::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return ((StartingLocationTerminalImplementation*) _getImplementation())->handleObjectMenuSelect(player, selectedID);
}

/*
 *	StartingLocationTerminalImplementation
 */

StartingLocationTerminalImplementation::StartingLocationTerminalImplementation(DummyConstructorParameter* param) : TerminalImplementation(param) {
	_initializeImplementation();
}

StartingLocationTerminalImplementation::~StartingLocationTerminalImplementation() {
}


void StartingLocationTerminalImplementation::finalize() {
}

void StartingLocationTerminalImplementation::_initializeImplementation() {
	_setClassHelper(StartingLocationTerminalHelper::instance());

	_serializationHelperMethod();
}

void StartingLocationTerminalImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (StartingLocationTerminal*) stub;
	TerminalImplementation::_setStub(stub);
}

DistributedObjectStub* StartingLocationTerminalImplementation::_getStub() {
	return _this;
}

StartingLocationTerminalImplementation::operator const StartingLocationTerminal*() {
	return _this;
}

TransactionalObject* StartingLocationTerminalImplementation::clone() {
	StartingLocationTerminalImplementation* objectCopy = new StartingLocationTerminalImplementation(DummyConstructorParameter::instance());
	*((StartingLocationTerminalImplementation*) objectCopy) = *this;
	return (TransactionalObject*) objectCopy;
}


void StartingLocationTerminalImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void StartingLocationTerminalImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void StartingLocationTerminalImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void StartingLocationTerminalImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void StartingLocationTerminalImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void StartingLocationTerminalImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void StartingLocationTerminalImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void StartingLocationTerminalImplementation::_serializationHelperMethod() {
	TerminalImplementation::_serializationHelperMethod();

	_setClassName("StartingLocationTerminal");

}

StartingLocationTerminalImplementation::StartingLocationTerminalImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/terminal/startinglocation/StartingLocationTerminal.idl(57):  		Logger.setLoggingName("StartingLocationTerminal");
	Logger::setLoggingName("StartingLocationTerminal");
}

/*
 *	StartingLocationTerminalAdapter
 */

StartingLocationTerminalAdapter::StartingLocationTerminalAdapter(StartingLocationTerminalImplementation* obj) : TerminalAdapter(obj) {
}

Packet* StartingLocationTerminalAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

void StartingLocationTerminalAdapter::initializeTransientMembers() {
	((StartingLocationTerminalImplementation*) impl)->initializeTransientMembers();
}

int StartingLocationTerminalAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((StartingLocationTerminalImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

/*
 *	StartingLocationTerminalHelper
 */

StartingLocationTerminalHelper* StartingLocationTerminalHelper::staticInitializer = StartingLocationTerminalHelper::instance();

StartingLocationTerminalHelper::StartingLocationTerminalHelper() {
	className = "StartingLocationTerminal";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void StartingLocationTerminalHelper::finalizeHelper() {
	StartingLocationTerminalHelper::finalize();
}

DistributedObject* StartingLocationTerminalHelper::instantiateObject() {
	return new StartingLocationTerminal(DummyConstructorParameter::instance());
}

DistributedObjectServant* StartingLocationTerminalHelper::instantiateServant() {
	return new StartingLocationTerminalImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* StartingLocationTerminalHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new StartingLocationTerminalAdapter((StartingLocationTerminalImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

