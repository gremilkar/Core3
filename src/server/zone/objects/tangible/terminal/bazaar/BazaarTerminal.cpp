/*
 *	server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.cpp generated by engine3 IDL compiler 0.60
 */

#include "BazaarTerminal.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/packets/object/ObjectMenuResponse.h"

#include "server/zone/objects/tangible/terminal/bazaar/AuctionItem.h"

#include "server/zone/Zone.h"

/*
 *	BazaarTerminalStub
 */

BazaarTerminal::BazaarTerminal() : Terminal(DummyConstructorParameter::instance()) {
	_setImplementation(new BazaarTerminalImplementation());
	_getImplementation()->_setStub(this);
}

BazaarTerminal::BazaarTerminal(DummyConstructorParameter* param) : Terminal(param) {
}

BazaarTerminal::~BazaarTerminal() {
}


void BazaarTerminal::initializeTransientMembers() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((BazaarTerminalImplementation*) _getImplementation())->initializeTransientMembers();
}

int BazaarTerminal::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(player);
		method.addByteParameter(selectedID);

		return method.executeWithSignedIntReturn();
	} else
		return ((BazaarTerminalImplementation*) _getImplementation())->handleObjectMenuSelect(player, selectedID);
}

void BazaarTerminal::addAuction(AuctionItem* item) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(item);

		method.executeWithVoidReturn();
	} else
		((BazaarTerminalImplementation*) _getImplementation())->addAuction(item);
}

void BazaarTerminal::dropAuction(unsigned long long auctionItemID) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addUnsignedLongParameter(auctionItemID);

		method.executeWithVoidReturn();
	} else
		((BazaarTerminalImplementation*) _getImplementation())->dropAuction(auctionItemID);
}

VectorMap<unsigned long long, ManagedReference<AuctionItem* > >* BazaarTerminal::getAuctions() {
	if (isNull()) {
		throw ObjectNotLocalException(this);

	} else
		return ((BazaarTerminalImplementation*) _getImplementation())->getAuctions();
}

void BazaarTerminal::setBazaarRegion(const String& region) {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addAsciiParameter(region);

		method.executeWithVoidReturn();
	} else
		((BazaarTerminalImplementation*) _getImplementation())->setBazaarRegion(region);
}

String BazaarTerminal::getBazaarRegion() {
	if (isNull()) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		method.executeWithAsciiReturn(_return_getBazaarRegion);
		return _return_getBazaarRegion;
	} else
		return ((BazaarTerminalImplementation*) _getImplementation())->getBazaarRegion();
}

/*
 *	BazaarTerminalImplementation
 */

BazaarTerminalImplementation::BazaarTerminalImplementation(DummyConstructorParameter* param) : TerminalImplementation(param) {
	_initializeImplementation();
}

BazaarTerminalImplementation::~BazaarTerminalImplementation() {
}


void BazaarTerminalImplementation::finalize() {
}

void BazaarTerminalImplementation::_initializeImplementation() {
	_setClassHelper(BazaarTerminalHelper::instance());

	_serializationHelperMethod();
}

void BazaarTerminalImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (BazaarTerminal*) stub;
	TerminalImplementation::_setStub(stub);
}

DistributedObjectStub* BazaarTerminalImplementation::_getStub() {
	return _this;
}

BazaarTerminalImplementation::operator const BazaarTerminal*() {
	return _this;
}

TransactionalObject* BazaarTerminalImplementation::clone() {
	BazaarTerminalImplementation* objectCopy = new BazaarTerminalImplementation(DummyConstructorParameter::instance());
	*((BazaarTerminalImplementation*) objectCopy) = *this;
	return (TransactionalObject*) objectCopy;
}


void BazaarTerminalImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void BazaarTerminalImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void BazaarTerminalImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void BazaarTerminalImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void BazaarTerminalImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void BazaarTerminalImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void BazaarTerminalImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void BazaarTerminalImplementation::_serializationHelperMethod() {
	TerminalImplementation::_serializationHelperMethod();

	_setClassName("BazaarTerminal");

	addSerializableVariable("bazaarRegion", &bazaarRegion);
	addSerializableVariable("auctions", &auctions);
}

BazaarTerminalImplementation::BazaarTerminalImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.idl(62):  		auctions.setNullValue(null);
	(&auctions)->setNullValue(NULL);
	// server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.idl(63):  		auctions.setNoDuplicateInsertPlan();
	(&auctions)->setNoDuplicateInsertPlan();
	// server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.idl(65):  		Logger.setLoggingName("BazaarTerminal");
	Logger::setLoggingName("BazaarTerminal");
}

int BazaarTerminalImplementation::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	// server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.idl(77):  		return 0;
	return 0;
}

void BazaarTerminalImplementation::addAuction(AuctionItem* item) {
	// server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.idl(81):  		item.setBazaarTerminal(this);
	item->setBazaarTerminal(_this);
	// server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.idl(82):  		auctions.put(item.getAuctionedItemObjectID(), item);
	(&auctions)->put(item->getAuctionedItemObjectID(), item);
}

void BazaarTerminalImplementation::dropAuction(unsigned long long auctionItemID) {
	// server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.idl(86):  		AuctionItem item = auctions.get(auctionItemID);
	AuctionItem* item = (&auctions)->get(auctionItemID);
	// server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.idl(88):  	}
	if (item != NULL){
	// server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.idl(89):  			item.setBazaarTerminal(null);
	item->setBazaarTerminal(NULL);
	// server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.idl(90):  			auctions.drop(auctionItemID);
	(&auctions)->drop(auctionItemID);
}
}

VectorMap<unsigned long long, ManagedReference<AuctionItem* > >* BazaarTerminalImplementation::getAuctions() {
	// server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.idl(96):  		return auctions;
	return (&auctions);
}

void BazaarTerminalImplementation::setBazaarRegion(const String& region) {
	// server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.idl(100):  		bazaarRegion = region;
	bazaarRegion = region;
}

String BazaarTerminalImplementation::getBazaarRegion() {
	// server/zone/objects/tangible/terminal/bazaar/BazaarTerminal.idl(104):  		return bazaarRegion;
	return bazaarRegion;
}

/*
 *	BazaarTerminalAdapter
 */

BazaarTerminalAdapter::BazaarTerminalAdapter(BazaarTerminalImplementation* obj) : TerminalAdapter(obj) {
}

Packet* BazaarTerminalAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		resp->insertSignedInt(handleObjectMenuSelect((PlayerCreature*) inv->getObjectParameter(), inv->getByteParameter()));
		break;
	case 8:
		addAuction((AuctionItem*) inv->getObjectParameter());
		break;
	case 9:
		dropAuction(inv->getUnsignedLongParameter());
		break;
	case 10:
		setBazaarRegion(inv->getAsciiParameter(_param0_setBazaarRegion__String_));
		break;
	case 11:
		resp->insertAscii(getBazaarRegion());
		break;
	default:
		return NULL;
	}

	return resp;
}

void BazaarTerminalAdapter::initializeTransientMembers() {
	((BazaarTerminalImplementation*) impl)->initializeTransientMembers();
}

int BazaarTerminalAdapter::handleObjectMenuSelect(PlayerCreature* player, byte selectedID) {
	return ((BazaarTerminalImplementation*) impl)->handleObjectMenuSelect(player, selectedID);
}

void BazaarTerminalAdapter::addAuction(AuctionItem* item) {
	((BazaarTerminalImplementation*) impl)->addAuction(item);
}

void BazaarTerminalAdapter::dropAuction(unsigned long long auctionItemID) {
	((BazaarTerminalImplementation*) impl)->dropAuction(auctionItemID);
}

void BazaarTerminalAdapter::setBazaarRegion(const String& region) {
	((BazaarTerminalImplementation*) impl)->setBazaarRegion(region);
}

String BazaarTerminalAdapter::getBazaarRegion() {
	return ((BazaarTerminalImplementation*) impl)->getBazaarRegion();
}

/*
 *	BazaarTerminalHelper
 */

BazaarTerminalHelper* BazaarTerminalHelper::staticInitializer = BazaarTerminalHelper::instance();

BazaarTerminalHelper::BazaarTerminalHelper() {
	className = "BazaarTerminal";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void BazaarTerminalHelper::finalizeHelper() {
	BazaarTerminalHelper::finalize();
}

DistributedObject* BazaarTerminalHelper::instantiateObject() {
	return new BazaarTerminal(DummyConstructorParameter::instance());
}

DistributedObjectServant* BazaarTerminalHelper::instantiateServant() {
	return new BazaarTerminalImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* BazaarTerminalHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new BazaarTerminalAdapter((BazaarTerminalImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

