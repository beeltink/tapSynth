/*
  ==============================================================================

    SynthSound.h
    Created: 22 May 2025 1:51:00pm
    Author:  beeltink

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

// Class SynthSound is inherited from class juce::SynthesiserSound
class SynthSound : public juce::SynthesiserSound
{
public:
    // Virtual functions need "override"
    bool appliesToNote(int midiNoteNumber) override { return true; }
    bool appliesToChannel(int midiChannel) override { return true; }
};