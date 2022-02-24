import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(26, GPIO.OUT)
GPIO.setup(19, GPIO.IN)
GPIO.setup(13, GPIO.OUT)
GPIO.setup(6, GPIO.OUT)
GPIO.setup(5, GPIO.IN)
timer = 0
timer2 = 0
gpiostate = [GPIO.HIGH, GPIO.LOW]
gpio = 0
gpio2 = 0

try:
    while True:
        GPIO.output(26, gpiostate[GPIO.input(5)])
        # GPIO.output(26, gpiostate[0])
        GPIO.output(13, gpiostate[(GPIO.input(5)+1) % 2])
        GPIO.output(6, gpiostate[GPIO.input(19)])
finally:
    GPIO.cleanup()
