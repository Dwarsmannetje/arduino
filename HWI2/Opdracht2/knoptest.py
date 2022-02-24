import time

from RPi import GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(19, GPIO.IN)
GPIO.setup(26, GPIO.IN)

while True:
    print("knop 1: " + str(GPIO.input(19)))
    print("knop 2: " + str(GPIO.input(26)))
    time.sleep(0.3)
