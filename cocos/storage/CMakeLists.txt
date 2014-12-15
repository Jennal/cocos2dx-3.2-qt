
set(COCOS_STORAGE_SRC
  storage/local-storage/LocalStorage.cpp
  )

set(COCOS_STORAGE_LINK
    sqlite3
)

if(WIN32)
  include_directories(
    ../external/sqlite3/include
  )
endif(WIN32)