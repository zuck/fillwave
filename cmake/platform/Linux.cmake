CMAKE_MINIMUM_REQUIRED( VERSION 2.8.8 )

#CMAKE_POLICY(SET CMP0048 OLD) #Project version cmake policy
#CMAKE_POLICY(SET CMP0046 OLD) #Project dependency cmake policy

# -----------------------------------------------
# Found by cmake macro
# -----------------------------------------------

# OpenMP

ADD_DEFINITIONS("-fopenmp")
FIND_PACKAGE(OpenMP)
IF(OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
ENDIF(OPENMP_FOUND)

# -----------------------------------------------
# Package type
# -----------------------------------------------

MESSAGE("Building binary package")
PROJECT(libfillwave C CXX)

SET(FILLWAVE_EXT_FONTGENERATOR_INCLUDES ext/fontgenerator)

# -----------------------------------------------
# Asset loader
# -----------------------------------------------

INCLUDE_DIRECTORIES(${FILLWAVE_PATH_INCLUDE}
                    ${FILLWAVE_EXT_INCLUDES}
                    ${FILLWAVE_EXT_FONTGENERATOR_INCLUDES}
                    ${FILLWAVE_TEXTURE_LOADER_INCLUDES}
                    ${FILLWAVE_MODEL_LOADER_INCLUDES}
                    /usr/include/freetype2) #uglt freetype2 needs /usr/local/include/freetype2/ft2build.h

# -----------------------------------------------
# Targets
# -----------------------------------------------

add_library(fillwave SHARED ${FILLWAVE_SOURCES})

# -----------------------------------------------
# Installation
# -----------------------------------------------

if(FILLWAVE_BUILD_RPM)
    install(TARGETS fillwave DESTINATION usr/lib64 COMPONENT fillwave)
else(FILLWAVE_BUILD_RPM)
    install(TARGETS fillwave DESTINATION usr/lib COMPONENT fillwave)
endif(FILLWAVE_BUILD_RPM)
   
# -----------------------------------------------
# Subprojects
# -----------------------------------------------

ADD_SUBDIRECTORY(ext)

# -----------------------------------------------
# Linker
# -----------------------------------------------

   TARGET_LINK_LIBRARIES(fillwave ${FILLWAVE_MODEL_LOADER} fontgenerator freetype)

   if(FILLWAVE_BUILD_PACK)
      ADD_DEPENDENCIES(fillwave GLEW)
      TARGET_LINK_LIBRARIES(fillwave GLEW)
   else()
      ADD_DEPENDENCIES(fillwave glew)
      TARGET_LINK_LIBRARIES(fillwave glew)
   endif()

# -----------------------------------------------
# Test app
# -----------------------------------------------

ADD_SUBDIRECTORY(test)

# -----------------------------------------------
# Packaging
# -----------------------------------------------

set(CPACK_DEBIAN_PACKAGE_NAME "libfillwave")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Fillwave graphics engine - library package")
if (FILLWAVE_BUILD_PACK)
#set(CPACK_DEBIAN_PACKAGE_DEPENDS "libglm-dev (>= 0.9.5.1-1), libglew1.10 (>= 1.10.0-3), libglew-dev (>= 1.10.0-3), libassimp3, libassimp-dev (>= 3.0~dfsg-2), libfreetype6 (>= 2.5.2)")
#set(CPACK_RPM_PACKAGE_REQUIRES "freetype, assimp")
#set (CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
endif()

INCLUDE(CPack)
