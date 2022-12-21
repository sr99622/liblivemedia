#/*********************************************************
#
# Copyright (c) 2022 Stephen Rhodes
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#***********************************************************/

find_path(LIVEMEDIA_INCLUDE_DIR liveMedia.hh
    HINTS
        /usr/include/x86_64-linux-gnu/liveMedia
)

find_path(GROUPSOCK_INCLUDE_DIR Groupsock.hh
    HINTS
        /usr/include/x86_64-linux-gnu/groupsock
)

find_path(USAGE_INCLUDE_DIR UsageEnvironment.hh
    HINTS
        /usr/include/x86_64-linux-gnu/UsageEnvironment
)

find_path(BASIC_INCLUDE_DIR BasicUsageEnvironment.hh
    HINTS
        /usr/include/x86_64-linux-gnu/BasicUsageEnvironment
)

find_library(LIVEMEDIA_LIBRARIES NAMES livemedia
    HINTS
        /usr/lib/x86_64-linux-gnu
)

set(LIVEMEDIA_INCLUDE_DIRS 
    ${LIVEMEDIA_INCLUDE_DIR} 
    ${GROUPSOCK_INCLUDE_DIR} 
    ${USAGE_INCLUDE_DIR} 
    ${BASIC_INCLUDE_DIR})

if (LIVEMEDIA_INCLUDE_DIR AND EXISTS "${LIVEMEDIA_INCLUDE_DIR}/liveMedia_version.hh")
    file(STRINGS "${LIVEMEDIA_INCLUDE_DIR}/liveMedia_version.hh" LIVEMEDIA_VERSION)
    string(FIND "${LIVEMEDIA_VERSION}" LIVEMEDIA_LIBRARY_VERSION_STRING START)
    string(LENGTH LIVEMEDIA_LIBRARY_VERSION_STRING LEN)
    string(SUBSTRING "${LIVEMEDIA_VERSION}" ${START} -1 LIVEMEDIA_VERSION)
    string(FIND "${LIVEMEDIA_VERSION}" ";" START)
    string(SUBSTRING "${LIVEMEDIA_VERSION}" 0 ${START} LIVEMEDIA_VERSION)
    string(SUBSTRING "${LIVEMEDIA_VERSION}" ${LEN} -1 LIVEMEDIA_VERSION)
    string(STRIP "${LIVEMEDIA_VERSION}" LIVEMEDIA_VERSION)
    string(LENGTH "${LIVEMEDIA_VERSION}" LEN)
    MATH(EXPR LEN "${LEN}-2")
    string(SUBSTRING "${LIVEMEDIA_VERSION}" 1 ${LEN} LIVEMEDIA_VERSION)
    set(LIVEMEDIA_VERSION_STRING ${LIVEMEDIA_VERSION})
endif()

include(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(LiveMedia
    REQUIRED_VARS LIVEMEDIA_INCLUDE_DIRS LIVEMEDIA_LIBRARIES
    VERSION_VAR LIVEMEDIA_VERSION_STRING
)

if (LiveMedia_FOUND)
    add_library(LiveMedia::LiveMedia INTERFACE IMPORTED)
    set_target_properties(LiveMedia::LiveMedia PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${LIVEMEDIA_INCLUDE_DIRS}"
        INTERFACE_LINK_LIBRARIES "${LIVEMEDIA_LIBRARIES}")
endif()
