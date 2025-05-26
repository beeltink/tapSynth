/*
  ==============================================================================

    SynthVoice.cpp
    Created: 22 May 2025 1:50:23pm
    Author:  beeltink

  ==============================================================================
*/

#include "SynthVoice.h"

bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound)
{
    // checks if the synthesizer can play a sound
    // juce::SynthesiserSound* = pointer
    // sound = sound coming in
    // returns TRUE if everything is working correctly
    return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;
}

void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
    
}

void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
    
}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{

}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{

}

void SynthVoice::renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples)
{
    juce::dsp::AudioBlock<float> audioBlock{ outputBuffer };
}

