/*
  ==============================================================================

    SynthVoice.h
    Created: 22 May 2025 1:50:23pm
    Author:  beeltink

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
    // from https://docs.juce.com/master/classSynthesiserVoice.html
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound, int currentPitchWheelPosition) override;
    void stopNote (float velocity, bool allowTailOff) override;
    void controllerMoved (int controllerNumber, int newControllerValue) override;
    void pitchWheelMoved (int newPitchWheelValue) override;
    
    // Added basic oscillator code
    void prepareToPlay (double sampleRate, int samplesPerBlock, int outputChannels);

    void renderNextBlock (juce::AudioBuffer< float > &outputBuffer, int startSample, int numSamples) override;

private:
    // Added ADSR Envelope
    juce::ADSR adsr;
    juce::ADSR::Parameters adsrParams;

    // Added basic oscillator code
    juce::dsp::Oscillator<float> osc{
    [](float x) {
            // * sine wave *
            // return std::sin(x);
            // * saw wave *
            return x / juce::MathConstants<float>::pi;
            // * square wave *
            // return x < 0.0f ? -1.0f : 1.0f;
        }
    };

    juce::dsp::Gain<float> gain;
    bool isPrepared{ false };
};
