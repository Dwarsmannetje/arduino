import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setup(26, GPIO.OUT)
GPIO.setup(21, GPIO.OUT)
GPIO.setup(20, GPIO.OUT)
GPIO.setup(19, GPIO.IN)
GPIO.setup(16, GPIO.OUT)
GPIO.setup(13, GPIO.IN)
GPIO.setup(12, GPIO.IN)
GPIO.setup(7, GPIO.OUT)
GPIO.setup(6, GPIO.IN)
GPIO.setup(5, GPIO.IN)
gpiostate = [GPIO.LOW, GPIO.HIGH]

try:
    while True:
        GPIO.output(26, gpiostate[GPIO.input(13)])
        GPIO.output(21, gpiostate[GPIO.input(5)])
        GPIO.output(20, gpiostate[GPIO.input(19)])
        GPIO.output(16, gpiostate[GPIO.input(6)])
        GPIO.output(7, gpiostate[GPIO.input(12)])
finally:
    GPIO.cleanup()
