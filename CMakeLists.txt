cmake_minimum_required( VERSION 3.10.2 )
project( cppunit )

set( cppunit_SRCS MoneyApp.cpp Money.h MoneyTest.h MoneyTest.cpp )

add_executable( cppunit_app ${cppunit_SRCS} )

find_package(PkgConfig)
pkg_check_modules(CPPUNIT cppunit)

target_link_libraries( cppunit_app ${CPPUNIT_LIBRARIES})

enable_testing()
add_test( money_test cppunit_app )
