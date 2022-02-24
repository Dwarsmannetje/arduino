import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(19, GPIO.IN)
GPIO.setup(21, GPIO.OUT)
GPIO.setup(20, GPIO.OUT)
GPIO.setup(26, GPIO.IN)
lastTime = time.time()
lastTime2 = time.time()
# currentState = 0
# currentState2 = 0


while True:
    # if GPIO.input(19):
        # if lastTime < time.time():
        #     GPIO.output(21, GPIO.HIGH)
        # if lastTime < time.time() - 0.7:
        #     GPIO.output(21, GPIO.LOW)
        # if lastTime < time.time() - 1.4:
        #     lastTime = time.time()
    if GPIO.input(26):
        # if lastTime < time.time():
        #     GPIO.output(21, GPIO.HIGH)
        if lastTime2 < time.time():
            GPIO.output(20, GPIO.HIGH)
            GPIO.output(21, GPIO.LOW)
        # if lastTime < time.time()-1.3:
        #     GPIO.output(21, GPIO.LOW)
        if lastTime2 < time.time()-1:
            GPIO.output(20, GPIO.LOW)
            GPIO.output(21, GPIO.HIGH)
        # if lastTime < time.time()-2:
        #     lastTime = time.time()
        if lastTime2 < time.time()-2:
            lastTime2 = time.time()
        # GPIO.output(21, GPIO.HIGH)
    else:
        if lastTime2 < time.time():
            GPIO.output(20, GPIO.HIGH)
            GPIO.output(21, GPIO.LOW)
        if lastTime2 < time.time() - 1.3:
            GPIO.output(20, GPIO.LOW)
            GPIO.output(21, GPIO.HIGH)
        if lastTime2 < time.time() - 2:
            lastTime2 = time.time()
        # GPIO.output(21, GPIO.LOW)
        # GPIO.output(20, GPIO.LOW)
    time.sleep(0.1)
