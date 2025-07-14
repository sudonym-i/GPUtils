install(
    TARGETS GPUtils_exe
    RUNTIME COMPONENT GPUtils_Runtime
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
