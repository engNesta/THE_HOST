//
// Created by Nesta on 2023-06-15.
//
#define CATCH_CONFIG_MAIN
#include "../Source/MainComponent.h"
#include <juce_core/juce_core.h>
#include <juce_audio_processors/juce_audio_processors.h>
#include "Catch2/src/catch2/catch_test_macros.hpp"

TEST_CASE("Hosting Test")
{
    MainComponent component;
    SECTION("Test Hosting Instance")
    {
        juce::File file = juce::File::getSpecialLocation(juce::File::SpecialLocationType::currentExecutableFile);
        component.retrieveVST3data(file);
        // Retrieve the plugin description from the file

        REQUIRE(component.infoLabel.getText() == file.getFileNameWithoutExtension() + "\n" +
                                                     file.getFileExtension() + "\n" +
                                                     file.getFullPathName());
    }
}


