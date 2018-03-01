#include "audiorecorder.h"

AudioRecorder::AudioRecorder()
{
    // first check if an input audio device is available on the system
    if (!sf::SoundBufferRecorder::isAvailable())
    {
        // error: audio capture is not available on this system
        ...
    }

    // create the recorder
    sf::SoundBufferRecorder recorder;

    // start the capture
    recorder.start();

    // wait...

    // stop the capture
    recorder.stop();

    // retrieve the buffer that contains the captured audio data
    const sf::SoundBuffer& buffer = recorder.getBuffer();
}
