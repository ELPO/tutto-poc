#!/usr/bin/env python3
# Requires PyAudio and PySpeech.
 
import speech_recognition as sr
import sys
import getopt

opts, args = getopt.getopt(sys.argv, "")
 
# Record Audio
r = sr.Recognizer()
with sr.Microphone() as source:
    audio = r.listen(source)
 
# Speech recognition using Google Speech Recognition
try:
    # for testing purposes, we're just using the default API key
    # to use another API key, use `r.recognize_google(audio, key="GOOGLE_SPEECH_RECOGNITION_API_KEY")`
    # instead of `r.recognize_google(audio)`
    ret = r.recognize_google(audio, language=args[1])
except sr.UnknownValueError:
    ret = "Google Speech Recognition could not understand audio"
except sr.RequestError as e:
    ret ="Could not request results from Google Speech Recognition service; {0}".format(e)
	
f = open(args[2], 'w')
f.write(ret)