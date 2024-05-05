const eye_left = document.getElementById('eye_left');
const pupil_left = document.getElementById('pupil_left');

const eye_right = document.getElementById('eye_right');
const pupil_right = document.getElementById('pupil_right');

function movePupil(eye, pupil, mouseX, mouseY) {
  const eyeRect = eye.getBoundingClientRect();
  // console.log("eyeRect", eyeRect);
  const relativeX = mouseX - (eyeRect.left + eye.offsetWidth / 2);
  const relativeY = mouseY - (eyeRect.top + eye.offsetHeight / 2);
  const distance = Math.sqrt(relativeX ** 2 + relativeY ** 2);
  const maxRadius = Math.min(eye.offsetWidth / 2 - pupil.offsetWidth / 2, eye.offsetHeight / 2 - pupil.offsetHeight / 2);
  const pupilRadius = Math.min(distance, maxRadius);
  pupil.style.transform = `translate(${(relativeX / distance) * pupilRadius}px, ${(relativeY / distance) * pupilRadius}px)`;
}

function movePupils(event) {
  const mouse = [event.clientX, event.clientY]

  movePupil(eye_left, pupil_left, mouse[0], mouse[1]);
  movePupil(eye_right, pupil_right, mouse[0], mouse[1]);
}

document.addEventListener("mousemove", movePupils);
