from gtts import gTTS

import sys
import getopt

lang = ''
opts, args = getopt.getopt(sys.argv, "")
	
tts = gTTS(text=args[1], lang=args[2])
tts.save(args[3])