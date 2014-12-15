if(WIN32)
  set(PLATFORM_SRC
    network/WebSocket.cpp
  )

  set(PLATFORM_LINK
    websockets_dll
  )

  include_directories(
    ../external/curl/include/win32
  )
else()
  set(PLATFORM_SRC
    network/WebSocket.cpp
  )

  set(PLATFORM_LINK
    websockets
    ssl
    crypto
  )
endif()

set(COCOS_NETWORK_SRC
  network/HttpClient.cpp
  network/SocketIO.cpp
  ${PLATFORM_SRC}
)

IF (WIN32 AND NOT MINGW)
  set(COCOS_NETWORK_LINK
    libcurl_imp
    ${PLATFORM_LINK}
  )
ELSE()
  set(COCOS_NETWORK_LINK
    curl_dll
    ${PLATFORM_LINK}
  )
ENDIF()
