import time

from RPi import GPIO

GPIO.setmode(GPIO.BCM)

gpioPins = [6, 13, 19, 26]
for i in gpioPins:
    GPIO.setup(i, GPIO.OUT)
GPIO.setup(21, GPIO.IN)
GPIO.setup(16, GPIO.IN)

setting = 0
wait = (5 - 0.0) / (512 * 8)
wait2 = (12 - 0.0) / (512 * 8)
timer = 0

try:
    while True:
        while GPIO.input(21):
            for i in range(0, 4):
                for x in gpioPins:
                    GPIO.output(x, GPIO.LOW)
                GPIO.output(gpioPins[i], GPIO.HIGH)
                timer = time.perf_counter()
                while timer + wait > time.perf_counter():
                    pass
                GPIO.output(gpioPins[(i + 1) % 4], GPIO.HIGH)
                timer = time.perf_counter()
                while timer + wait > time.perf_counter():
                    pass
        while GPIO.input(16):
            for i in range(3, -1, -1):
                for x in gpioPins:
                    GPIO.output(x, GPIO.LOW)
                GPIO.output(gpioPins[i], GPIO.HIGH)
                timer = time.perf_counter()
                while timer + wait2 > time.perf_counter():
                    pass
                GPIO.output(gpioPins[(i - 1) % 4], GPIO.HIGH)
                timer = time.perf_counter()
                while timer + wait2 > time.perf_counter():
                    pass
        for x in gpioPins:
            GPIO.output(x, GPIO.LOW)
finally:
    GPIO.cleanup()
