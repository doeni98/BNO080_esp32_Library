# Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES )
set(COMPONENT_PRIV_REQUIRES )

set(COMPONENT_SRCS "main.cpp" SPIClass.cpp TwoWire.cpp DebugStream.cpp SparkFun_BNO080_Arduino_Library.cpp )
set(COMPONENT_ADD_INCLUDEDIRS ".")

register_component()
