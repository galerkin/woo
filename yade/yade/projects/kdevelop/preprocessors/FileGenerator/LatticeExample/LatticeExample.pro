# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./preprocessors/FileGenerator/LatticeExample
# Target is a library:  

LIBS += -lParticleParameters \
        -lInteractingGeometrySet \
        -lAABB \
        -lSphere \
        -lLineSegment \
        -lLatticeSetParameters \
        -lLatticeBeamParameters \
        -lLatticeNodeParameters \
        -rdynamic 
INCLUDEPATH += $(YADEINCLUDEPATH) 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../../plugins/Body/PhysicalParameters/ParticleParameters/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/InteractingGeometry/InteractionDescriptionSet/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/BoundingVolume/AABB/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/GeometricalModel/Sphere/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/GeometricalModel/LineSegment/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/PhysicalParameters/LatticeSetParameters/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/PhysicalParameters/LatticeBeamParameters/$(YADEDYNLIBPATH) \
               ../../../plugins/Body/PhysicalParameters/LatticeNodeParameters/$(YADEDYNLIBPATH) \
               $(YADEDYNLIBPATH) 
QMAKE_CXXFLAGS_RELEASE += -lpthread \
                          -pthread 
QMAKE_CXXFLAGS_DEBUG += -lpthread \
                        -pthread 
DESTDIR = $(YADEDYNLIBPATH) 
CONFIG += debug \
          warn_on \
          dll 
TEMPLATE = lib 
HEADERS += LatticeExample.hpp 
SOURCES += LatticeExample.cpp 
