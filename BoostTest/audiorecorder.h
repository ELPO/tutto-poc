#ifndef AUDIORECORDER_H
#define AUDIORECORDER_H

#include <SFML/Audio.hpp>

class AudioRecorder : public sf::SoundRecorder
{
public:
    AudioRecorder();

    virtual bool onStart();
    virtual bool onProcessSamples(const sf::Int16* Samples, std::size_t SamplesCount);
    virtual void onStop();
};

#endif // AUDIORECORDER_H
