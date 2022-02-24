import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BCM)
GPIO.setup(2, GPIO.OUT)
GPIO.setup(3, GPIO.IN)
timer = 0
timer2 = 0
gpiostate = [GPIO.HIGH, GPIO.LOW]
gpio = 0
gpio2 = 0

try:
    while True:
        if gpio2 == 1:
            gpio2 = GPIO.input(3)
        # if timer + 1 <= time.time():
        if GPIO.input(3) != gpio2:
            GPIO.output(2, gpiostate[gpio % 2])
            # print(gpiostate[gpio % 2])
            gpio += 1
            # timer = time.time()
            gpio2 = 1
        '''if timer2 + 3 <= time.time():
            GPIO.output(3, gpiostate[gpio2 % 2])
            print(gpiostate[gpio2 % 2])
            gpio2 += 1
            timer2 = time.time()'''
finally:
    GPIO.cleanup()
