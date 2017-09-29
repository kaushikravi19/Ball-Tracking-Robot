from collections import deque
import numpy as np
import argparse
import imutils
import cv2
import serial
import time
r=0
x=0
y=0
ser = serial.Serial('COM36', 9600)
ap = argparse.ArgumentParser()
ap.add_argument("-b", "--buffer", type=int, default=64,help="max buffer size")
args = vars(ap.parse_args())
greenLower = (0,58,255)
greenUpper = (30,255,255)
pts = deque(maxlen=args["buffer"])
camera = cv2.VideoCapture(2)
def ball_track():
	ret, frame = camera.read()
	cv2.circle(frame,(325,215), 2, (0,255,0), -1)
	frame = imutils.resize(frame,width=500)
	blurred = cv2.GaussianBlur(frame, (11, 11), 0)
	hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
	mask = cv2.inRange(hsv, greenLower, greenUpper)
	cv2.imshow("mask",mask)
	mask = cv2.erode(mask, None, iterations=2)
	mask = cv2.dilate(mask, None, iterations=2)
	cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL,cv2.CHAIN_APPROX_SIMPLE)[-2]
	center = None
	if len(cnts) > 0:
		c = max(cnts, key=cv2.contourArea)
		((x1, y1), radius) = cv2.minEnclosingCircle(c)
		M = cv2.moments(c)
		center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))
		if radius > 0:
			cv2.circle(frame, (int(x1), int(y1)), int(radius),(0, 255, 255), 2)
			cv2.circle(frame, center, 5, (0, 0, 255), -1)
			global x
			x=int(x1)
			global y
			y=int(y1)
			global r
			r=int(radius)
			print x,y,r
x1 = 128
x2 = 374
rmax = 125
while True:
    ball_track()
    key=cv2.waitKey(1) & 0xFF
    if key==ord('q'):
        break
    elif(x<x1):
         ser.write("R")
    elif(x>x2):
         ser.write("L")
    elif(r<rmax):
         ser.write("F")
    elif(r>rmax):
         ser.write("S")
ser.close()
camera.release()
cv2.destroyAllWindows()



