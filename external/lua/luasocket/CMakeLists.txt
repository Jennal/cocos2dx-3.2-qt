if(WIN32)
  set(SOCKET_FILE wsocket.c)
else()
  set(SOCKET_FILE 
    usocket.c
    unix.c
    serial.c
  )
endif()

set(SRC_FILES
  auxiliar.c
  buffer.c
  except.c
  inet.c
  io.c
  luasocket.c
  mime.c
  options.c
  select.c
  tcp.c
  timeout.c
  udp.c
  ${SOCKET_FILE}
)

include_directories(
  ../lua
)

add_library(luasocket STATIC
  ${SRC_FILES}
)

set_target_properties(luasocket
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
