set(CCB_SRC
  CCBFileLoader.cpp
  CCMenuItemImageLoader.cpp
  CCBReader.cpp
  CCMenuItemLoader.cpp
  CCControlButtonLoader.cpp
  CCControlButtonBMFontLoader.cpp
  CCNodeLoader.cpp
  CCControlLoader.cpp
  CCNodeLoaderLibrary.cpp
  CCLabelBMFontLoader.cpp
  CCParticleSystemQuadLoader.cpp
  CCLabelTTFLoader.cpp
  CCScale9SpriteLoader.cpp
  CCRepeat9SpriteLoader.cpp
  CCLayerColorLoader.cpp
  CCScrollViewLoader.cpp
  CCLayerGradientLoader.cpp
  CCSpriteLoader.cpp
  CCLayerLoader.cpp
  CCBAnimationManager.cpp
  CCBKeyframe.cpp
  CCBSequence.cpp
  CCBSequenceProperty.cpp
  CCNode+CCBRelativePositioning.cpp
)

include_directories(
  ..
)

if(WIN32)
  include_directories(
    ../../../external/win32-specific/gles/include
  )
endif(WIN32)

add_library(cocosbuilder STATIC
  ${CCB_SRC}
)

set_target_properties(cocosbuilder
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

