import cv2
import numpy as np
import asyncio

caps = {}

async def generate_frames(camera_index: int):
    global caps
    if camera_index not in caps:
        caps[camera_index] = cv2.VideoCapture(camera_index)

    cap = caps[camera_index]

    while True:
        # Read a frame from the camera
        success, frame = cap.read()
        if not success:
            break

        # Convert the frame to grayscale for detection
        gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

        # Detect humans in the frame
        humans = human_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5)

        # Draw rectangles around detected humans
        for (x, y, w, h) in humans:
            cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)

        # Encode the frame as JPEG
        ret, buffer = cv2.imencode('.jpg', frame)
        frame = buffer.tobytes()

        # Yield the frame as a byte stream
        yield (b'--frame\r\n'
               b'Content-Type: image/jpeg\r\n\r\n' + frame + b'\r\n')

        # Sleep to allow for a smoother stream
        await asyncio.sleep(0.01)

async def generate_multiple_frames(camera_indices):
    while True:
        frames = []
        for index in camera_indices:
            if index not in caps:
                caps[index] = cv2.VideoCapture(index)

            cap = caps[index]
            success, frame = cap.read()
            if success:
                # Convert the frame to grayscale for detection
                gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

                # Detect humans in the frame
                humans = human_cascade.detectMultiScale(gray, scaleFactor=1.1, minNeighbors=5)

                # Draw rectangles around detected humans
                for (x, y, w, h) in humans:
                    cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)

                # Encode the frame as JPEG
                ret, buffer = cv2.imencode('.jpg', frame)
                frames.append(buffer.tobytes())
            else:
                frames.append(None)

        # Create a multi-frame response
        yield (b'--frame\r\n'
               b'Content-Type: multipart/x-mixed-replace; boundary=frame\r\n\r\n' +
               b'\r\n'.join(f for f in frames if f is not None) + b'\r\n')

        # Sleep to allow for a smoother stream
        await asyncio.sleep(0.01)
