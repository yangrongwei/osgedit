#include <reflection/reflectionregistry.h>
#include <osgParticle/MultiSegmentPlacer>
#include <stdexcept>

/**
 * Reflector of class osgParticle::MultiSegmentPlacer
 */
class RefosgParticleMultiSegmentPlacer: public ClassReflection {
public:
	RefosgParticleMultiSegmentPlacer();
	virtual osg::Object *getObject() { return _object.get(); }
	virtual void setObject(osg::Object *obj);
	virtual const std::string &getType() const { return _class_name; }
	virtual const std::string &getOSGVersion() const { return _osg_version; }
	virtual const std::string &getDescription() const { return _class_description; }
	virtual unsigned getNumProperties() const { return _names.size(); }
	virtual const PropertyNames &getPropertyNames() { return _names; }
	virtual void addChild(osg::Object *child);
	virtual void removeChild(osg::Object *child);
	virtual unsigned getNumChildren();
	virtual osg::Object *getChildObject(unsigned i);
	virtual PropertyReflection *getProperty(const std::string &name);
	virtual PropertyReflection *getTableProperty(const std::string &name, unsigned row, unsigned col);
	virtual unsigned getNumTablePropertyColumns(const std::string &name);
	virtual unsigned getNumTablePropertyRows(const std::string &name);
	virtual const PropertyNames &getTablePropertyNames() { return _table_names; }
	virtual const PropertyNames getTablePropertyColumnTitles(const std::string &name);
	virtual const PropertyNames getTablePropertyRowTitles(const std::string &name);
private:
	osg::ref_ptr<osgParticle::MultiSegmentPlacer> _object;
	static PropertyNames _names;
	static PropertyNames _table_names;
	static std::string _class_name;
	static std::string _class_description;
	static std::string _osg_version;
};

static std::string _propnames[] = {"_name","_userData","_dataVariance"};
ClassReflection::PropertyNames RefosgParticleMultiSegmentPlacer::_names(_propnames, _propnames+3);

ClassReflection::PropertyNames RefosgParticleMultiSegmentPlacer::_table_names;

std::string RefosgParticleMultiSegmentPlacer::_class_name("osgParticle::MultiSegmentPlacer");

std::string RefosgParticleMultiSegmentPlacer::_class_description(" A polyline-shaped particle placer. This placer class sets the position of incoming particles by choosing a random point on the specified sequence of connected segments.     ");

std::string RefosgParticleMultiSegmentPlacer::_osg_version("1.2");


/**********************************************************/
RefosgParticleMultiSegmentPlacer::RefosgParticleMultiSegmentPlacer() {
}

/**********************************************************/
void RefosgParticleMultiSegmentPlacer::setObject(osg::Object *obj) {
	_object = dynamic_cast<osgParticle::MultiSegmentPlacer*>(obj);
}
static class Enum_osg_object_datavariance: public Enum<osg::Object::DataVariance> {
public:
	Enum_osg_object_datavariance() {
		add("DYNAMIC", osg::Object::DYNAMIC);
		add("STATIC", osg::Object::STATIC);
		add("UNSPECIFIED", osg::Object::UNSPECIFIED);
	}
} osg_object_datavariance;

using namespace osgParticle;

/**********************************************************/
void RefosgParticleMultiSegmentPlacer::addChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
void RefosgParticleMultiSegmentPlacer::removeChild(osg::Object *child) {
	throw InvalidTypeException();
}

/**********************************************************/
osg::Object *RefosgParticleMultiSegmentPlacer::getChildObject(unsigned i) {
	throw std::out_of_range("child");
}

/**********************************************************/
unsigned RefosgParticleMultiSegmentPlacer::getNumChildren() {
	unsigned cnt = 0;
	return cnt;
}

/**********************************************************/
PropertyReflection* RefosgParticleMultiSegmentPlacer::getProperty(const std::string &name) {
	if (name == "_dataVariance") {
		return new GetterSetterEnumProperty<osg::Object::DataVariance, osg::Object>("_dataVariance", _object.get(), &osgParticle::MultiSegmentPlacer::getDataVariance, &osgParticle::MultiSegmentPlacer::setDataVariance, osg_object_datavariance);
	}
	if (name == "_name") {
		// Getter overloaded, must specify one type
		typedef const std::string & (osg::Object::*getNameFN)() const;
		// Setter overloaded, must specify one type
		typedef void (osg::Object::*setNameFN)(const std::string &) ;
		return new GetterSetterProperty<std::string, osg::Object>("_name", _object.get(), (getNameFN)&osgParticle::MultiSegmentPlacer::getName, (setNameFN)&osgParticle::MultiSegmentPlacer::setName);
	}
	if (name == "_userData") {
		// Getter overloaded, must specify one type
		typedef Referenced * (osg::Object::*getUserDataFN)() ;
		return new GetterSetterProperty<Referenced*, osg::Object>("_userData", _object.get(), (getUserDataFN)&osgParticle::MultiSegmentPlacer::getUserData, &osgParticle::MultiSegmentPlacer::setUserData);
	}
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleMultiSegmentPlacer::getNumTablePropertyColumns(const std::string &name) {
	throw PropertyNotFoundException(name);
}
unsigned RefosgParticleMultiSegmentPlacer::getNumTablePropertyRows(const std::string &name) {
	throw PropertyNotFoundException(name);
}
PropertyReflection *RefosgParticleMultiSegmentPlacer::getTableProperty(const std::string &name, unsigned row, unsigned col) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleMultiSegmentPlacer::getTablePropertyColumnTitles(const std::string &name) {
	throw PropertyNotFoundException(name);
}
const ClassReflection::PropertyNames RefosgParticleMultiSegmentPlacer::getTablePropertyRowTitles(const std::string &name) {
	PropertyNames titles;
	return titles;
}

/** REGISTERING **/
RegisterWrapperClass<osgParticle::MultiSegmentPlacer, RefosgParticleMultiSegmentPlacer> _registerRefosgParticleMultiSegmentPlacer;
