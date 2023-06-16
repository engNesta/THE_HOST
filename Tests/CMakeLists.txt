project(The_Host_Test VERSION 0.1)

set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)

include(CTest)

#Declaring that we want 'catch2', a testing framework.
#Instructions on how to find it would appear under CMake/findcatch2.cmake
add_subdirectory(Catch2)

juce_add_console_app(The_Host_Test PRODUCT_NAME "The_Host_Test")

juce_generate_juce_header(The_Host_Test)

set(SOURCE_FILES
       	HostTest.cpp
        ../Source/MainComponent.cpp
        )

target_sources(The_Host_Test PRIVATE ${SOURCE_FILES})

target_compile_definitions(The_Host_Test PRIVATE
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
		JUCE_PLUGINHOST_VST3=1)

target_include_directories(The_Host_Test PRIVATE ../Source/)

target_link_libraries(The_Host_Test PRIVATE
        Catch2WithMain
		juce_recommended_config_flags
		juce_recommended_warning_flags
		juce_recommended_lto_flags
		juce::juce_audio_basics
		juce::juce_gui_basics
		juce::juce_graphics
		juce::juce_audio_processors)

