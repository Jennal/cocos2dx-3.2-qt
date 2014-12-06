if(WIN32)
  set(SOCKET_FILE wsocket.c)
else()
  set(SOCKET_FILE usocket.c)
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
  serial.c
  tcp.c
  timeout.c
  udp.c
  unix.c
  ${SOCKET_FILE}
)

add_library(luasocket STATIC
  ${SRC_FILES}
)

set_target_properties(luasocket
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
