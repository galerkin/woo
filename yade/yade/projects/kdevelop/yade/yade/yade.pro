# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./yade/yade
# Target is an application:  

LIBS += -lSerialization \
        -lMath \
        -lBody \
        -lEngine \
        -lGeometry \
        -lInteraction \
        -lMultiMethods \
        -lFactory \
        -lInteractionVecSet \
        -lInteractionHashMap \
        -lBodyAssocVec \
        -lBodyRedirectionVector \
        -lThreads \
        -lboost_thread \
        -lboost_filesystem \
        -lboost_date_time \
        -lglut \
        -lQGLViewer \
        -rdynamic 
INCLUDEPATH = $(YADEINCLUDEPATH) 
MOC_DIR = $(YADECOMPILATIONPATH) 
UI_DIR = $(YADECOMPILATIONPATH) 
OBJECTS_DIR = $(YADECOMPILATIONPATH) 
QMAKE_LIBDIR = ../../toolboxes/Libraries/Serialization/$(YADEDYNLIBPATH) \
               ../../toolboxes/Libraries/Math/$(YADEDYNLIBPATH) \
               ../../yade/Body/$(YADEDYNLIBPATH) \
               ../../yade/Engine/$(YADEDYNLIBPATH) \
               ../../yade/Geometry/$(YADEDYNLIBPATH) \
               ../../yade/Interaction/$(YADEDYNLIBPATH) \
               ../../yade/MultiMethods/$(YADEDYNLIBPATH) \
               ../../toolboxes/Libraries/Factory/$(YADEDYNLIBPATH) \
               ../../toolboxes/DataStructures/InteractionContainer/InteractionVecSet/$(YADEDYNLIBPATH) \
               ../../toolboxes/DataStructures/InteractionContainer/InteractionHashMap/$(YADEDYNLIBPATH) \
               ../../toolboxes/DataStructures/BodyContainer/BodyAssocVec/$(YADEDYNLIBPATH) \
               ../../toolboxes/DataStructures/BodyContainer/BodyRedirectionVector/$(YADEDYNLIBPATH) \
               ../../toolboxes/Libraries/Threads/$(YADEDYNLIBPATH) \
               $(YADEDYNLIBPATH) 
QMAKE_CXXFLAGS_RELEASE += -lpthread \
                          -pthread 
QMAKE_CXXFLAGS_DEBUG += -lpthread \
                        -pthread 
DESTDIR = $(YADEBINPATH) 
CONFIG += debug \
          warn_on 
TEMPLATE = app 
HEADERS += Chrono.hpp \
           Omega.hpp \
           Tree.hpp \
           Actor.hpp \
           ActorParameter.hpp \
           FrontEnd.hpp \
           FileGenerator.hpp \
           SimulationLoop.hpp \
           RenderingEngine.hpp 
SOURCES += Chrono.cpp \
           Omega.cpp \
           yade.cpp \
           FrontEnd.cpp \
           SimulationLoop.cpp 
