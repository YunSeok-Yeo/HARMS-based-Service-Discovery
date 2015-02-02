//
// Generated file, do not edit! Created by opp_msgc 4.5 from tictoc13.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "CustomPacket.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');

    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

Register_Class(CustomPacket);

CustomPacket::CustomPacket(const char *name, int kind) : ::cMessage(name,kind)
{
    this->type = 0;
    this->sourceId = 0;
    this->destinationId = 0;
    this->maxHopCount = 0;
    this->destinationService = 0;
    this->sequenceNum = 0;
    this->proxyId = 0;
    this->originSourceId = 0;
    this->originSourceSeqNum = 0;

}

CustomPacket::CustomPacket(const CustomPacket& other) : ::cMessage(other) {
    // TODO Auto-generated constructor stub
    copy(other);
}

CustomPacket::~CustomPacket() {
    // TODO Auto-generated destructor stub
}

CustomPacket& CustomPacket::operator=(const CustomPacket& other)
{
    if (this==&other) return *this;
    ::cMessage::operator=(other);
    copy(other);
    return *this;
}

void CustomPacket::copy(const CustomPacket& other)
{
    this->type = other.type;
    this->sourceId = other.sourceId;
    this->destinationId = other.destinationId;
    this->maxHopCount = other.maxHopCount;
    this->destinationService = other.destinationService;
    this->sequenceNum = other.sequenceNum;
    this->proxyId = other.proxyId;
    this->originSourceId = other.originSourceId;
    this->originSourceSeqNum = other.originSourceSeqNum;
    this->lastHop = other.lastHop;
}

void CustomPacket::parsimPack(cCommBuffer *b)
{
    ::cMessage::parsimPack(b);
    doPacking(b,this->type);
    doPacking(b,this->sequenceNum);
    doPacking(b,this->sourceId);
    doPacking(b,this->destinationId);
    doPacking(b,this->maxHopCount);
    doPacking(b,this->destinationService);
    doPacking(b,this->proxyId);
    doPacking(b,this->originSourceId);
    doPacking(b,this->originSourceSeqNum);
    doPacking(b,this->lastHop);
}

void CustomPacket::parsimUnpack(cCommBuffer *b)
{
    ::cMessage::parsimUnpack(b);
    doUnpacking(b,this->type);
    doUnpacking(b,this->sequenceNum);
    doUnpacking(b,this->sourceId);
    doUnpacking(b,this->destinationId);
    doUnpacking(b,this->maxHopCount);
    doUnpacking(b,this->destinationService);
    doUnpacking(b,this->proxyId);
    doUnpacking(b,this->originSourceId);
    doUnpacking(b,this->originSourceSeqNum);
    doUnpacking(b,this->lastHop);
}
int CustomPacket::GetType() const
{
    return type;
}
void CustomPacket::SetType(int type){
    this->type = type;
}
int CustomPacket::GetSource() const
{
    return sourceId;
}

void CustomPacket::SetSource(int source)
{
    this->sourceId = source;
}

int CustomPacket::GetDestination() const
{
    return destinationId;
}

void CustomPacket::SetDestination(int destination)
{
    this->destinationId = destination;
}

int CustomPacket::GetMaxHopCount() const
{
    return maxHopCount;
}

void CustomPacket::SetMaxHopCount(int maxHopCount)
{
    this->maxHopCount = maxHopCount;
}
int CustomPacket::GetSeqNum() const
{
    return sequenceNum;
}

void CustomPacket::SetSeqNum(int seqNum)
{
    this->sequenceNum = seqNum;
}
int CustomPacket::GetDestinationService() const
{
    return destinationService;
}

void CustomPacket::SetDestinationService(int desService)
{
    this->destinationService = desService;
}
int CustomPacket::GetProxy() const
{
    return proxyId;
}
void CustomPacket::SetProxy(int proxy)
{
    this->proxyId = proxy;
}
int CustomPacket::GetOriginSourceId() const
{
    return originSourceId;
}
void CustomPacket::SetOriginSourceId(int originSourceId){
    this->originSourceId = originSourceId;
}
int CustomPacket::GetOriginSourceSeqNum() const
{
    return originSourceSeqNum;
}
void CustomPacket::SetOriginSourceSeqNum(int originSourceSeqNum){
    this->originSourceSeqNum = originSourceSeqNum;
}
string CustomPacket::GetLastHop() const
{
    return lastHop;
}
void CustomPacket::SetLastHop(string lastHop){
    this->lastHop = lastHop;
}
int CustomPacket::GetDestinationLocation() const
{
    return destinationLocation;
}
void CustomPacket::SetDestinationLocation(int destinationLocation){
    this->destinationLocation = destinationLocation;
}
int CustomPacket::GetHopCount() const
{
    return hopCount;
}
void CustomPacket::SetHopCount(int hopCount){
    this->hopCount = hopCount;
}
class CustomPacketDescriptor : public cClassDescriptor
{
  public:
    CustomPacketDescriptor();
    virtual ~CustomPacketDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(CustomPacketDescriptor);

CustomPacketDescriptor::CustomPacketDescriptor() : cClassDescriptor("CustomPacket", "cMessage")
{
}

CustomPacketDescriptor::~CustomPacketDescriptor()
{
}

bool CustomPacketDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<CustomPacket *>(obj)!=NULL;
}

const char *CustomPacketDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int CustomPacketDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount(object) : 11;
}

unsigned int CustomPacketDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *CustomPacketDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "type",
        "sequenceNum",
        "sourceId",
        "destinationId",
        "hopCount",
        "destinationService",
        "proxyId",
        "originSourceId",
        "originSourceSeqNum",
        "lastHop",
        "destinationLocation",
        "hopCount",
    };
    return (field>=0 && field<11) ? fieldNames[field] : NULL;
}

int CustomPacketDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNum")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceId")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationId")==0) return base+3;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationService")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "proxyId")==0) return base+6;
    if (fieldName[0]=='o' && strcmp(fieldName, "originSourceId")==0) return base+7;
    if (fieldName[0]=='o' && strcmp(fieldName, "originSourceSeqNum")==0) return base+8;
    if (fieldName[0]=='l' && strcmp(fieldName, "lastHop")==0) return base+9;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationLocation")==0) return base+10;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopCount")==0) return base+11;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *CustomPacketDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "int",
        "string",
        "int",
        "int",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : NULL;
}

const char *CustomPacketDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    }
}

int CustomPacketDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    CustomPacket *pp = (CustomPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string CustomPacketDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    CustomPacket *pp = (CustomPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->GetType());
        case 1: return long2string(pp->GetSeqNum());
        case 2: return long2string(pp->GetSource());
        case 3: return long2string(pp->GetDestination());
        case 4: return long2string(pp->GetMaxHopCount());
        case 5: return long2string(pp->GetDestinationService());
        case 6: return long2string(pp->GetProxy());
        case 7: return long2string(pp->GetOriginSourceId());
        case 8: return long2string(pp->GetOriginSourceSeqNum());
        case 9: return pp->GetLastHop();
        case 10: return long2string(pp->GetDestinationLocation());
        case 11: return long2string(pp->GetHopCount());
        default: return "";
    }
}

bool CustomPacketDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    CustomPacket *pp = (CustomPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->SetType(string2long(value)); return true;
        case 1: pp->SetSeqNum(string2long(value)); return true;
        case 2: pp->SetSource(string2long(value)); return true;
        case 3: pp->SetDestination(string2long(value)); return true;
        case 4: pp->SetMaxHopCount(string2long(value)); return true;
        case 5: pp->SetDestinationService(string2long(value)); return true;
        case 6: pp->SetProxy(string2long(value)); return true;
        case 7: pp->SetOriginSourceId(string2long(value)); return true;
        case 8: pp->SetOriginSourceSeqNum(string2long(value)); return true;
        case 9: pp->SetLastHop(value); return true;
        case 10: pp->SetDestinationLocation(string2long(value)); return true;
        case 11: pp->SetHopCount(string2long(value)); return true;
        default: return false;
    }
}

const char *CustomPacketDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *CustomPacketDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    CustomPacket *pp = (CustomPacket *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


