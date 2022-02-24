from RPi import GPIO
import time

BUTTON1 = 19
BUTTON2 = 26

GPIO.setmode(GPIO.BCM)
GPIO.setup(BUTTON1, GPIO.IN)
GPIO.setup(BUTTON2, GPIO.IN)
GPIO.setup(14, GPIO.OUT)

pwm = GPIO.PWM(14, 50)
pwm.start(0)


def SetAngle(angle):
    duty = angle / 18 + 2.5
    pwm.ChangeDutyCycle(duty)


x = 0
while True:
    aan = GPIO.input(BUTTON2)
    snel = GPIO.input(BUTTON1)
    print(aan)
    if aan or snel:
        while x < 120:
            SetAngle(x)
            time.sleep(0.1)
            if GPIO.input(BUTTON2):
                time.sleep(0.1)

            x = x + 30

        while x > 0:
            SetAngle(x)
            time.sleep(0.1)
            if GPIO.input(BUTTON2):
                time.sleep(0.1)

            x = x - 30
