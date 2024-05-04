//
// console.log(window.innerWidth);
// console.log(window.innerHeight);
//
// const eye_left = document.getElementById('eye_left');
// const pupil_left = document.getElementById('pupil_left');
//
// const eye_right = document.getElementById('eye_right');
// const pupil_right = document.getElementById('pupil_right');
//
// function drag_eye(event) {
//   const mouse = [event.screenX, event.screenY];
//   console.log(mouse);
//   pupil_left.style.left = `${(eye_left.offsetWidth / window.innerWidth) * event.screenX - pupil_left.offsetWidth/2}px`;
//   pupil_left.style.top = `${(eye_left.offsetHeight / window.innerHeight) * event.screenY - pupil_left.offsetHeight/2}px`;
//
//   pupil_right.style.left = `${(eye_right.offsetWidth / window.innerWidth) * event.screenX - eye_right.offsetWidth/2}px`;
//   pupil_right.style.top = `${(eye_right.offsetHeight / window.innerHeight) * event.screenY - eye_right.offsetHeight/2}px`;
//   // console.log(pupil_left.style.left);
// }
//
// addEventListener("mousemove", drag_eye);
const eye_left = document.getElementById('eye_left');
const pupil_left = document.getElementById('pupil_left');

const eye_right = document.getElementById('eye_right');
const pupil_right = document.getElementById('pupil_right');

function drag_eye(event) {
    // Получаем координаты курсора относительно окна браузера
    const mouseX = event.clientX;
    const mouseY = event.clientY;

    // Получаем размеры глаз и зрачков
    const eyeLeftWidth = eye_left.offsetWidth;
    const eyeLeftHeight = eye_left.offsetHeight;
    const pupilLeftWidth = pupil_left.offsetWidth;
    const pupilLeftHeight = pupil_left.offsetHeight;

    const eyeRightWidth = eye_right.offsetWidth;
    const eyeRightHeight = eye_right.offsetHeight;
    const pupilRightWidth = pupil_right.offsetWidth;
    const pupilRightHeight = pupil_right.offsetHeight;

    // Рассчитываем положение зрачков для левого глаза
    const pupilLeftX = mouseX - eye_left.getBoundingClientRect().left - pupilLeftWidth / 2;
    const pupilLeftY = mouseY - eye_left.getBoundingClientRect().top - pupilLeftHeight / 2;

    // Рассчитываем положение зрачков для правого глаза
    const pupilRightX = mouseX - eye_right.getBoundingClientRect().left - pupilRightWidth / 2;
    const pupilRightY = mouseY - eye_right.getBoundingClientRect().top - pupilRightHeight / 2;

    // Ограничиваем положение зрачков в пределах глаз
    const maxLeftX = eyeLeftWidth - pupilLeftWidth;
    const maxLeftY = eyeLeftHeight - pupilLeftHeight;

    const maxRightX = eyeRightWidth - pupilRightWidth;
    const maxRightY = eyeRightHeight - pupilRightHeight;

    // Применяем новое положение зрачков к стилям
    pupil_left.style.left = `${Math.min(maxLeftX, Math.max(0, pupilLeftX))}px`;
    pupil_left.style.top = `${Math.min(maxLeftY, Math.max(0, pupilLeftY))}px`;

    pupil_right.style.left = `${Math.min(maxRightX, Math.max(0, pupilRightX))}px`;
    pupil_right.style.top = `${Math.min(maxRightY, Math.max(0, pupilRightY))}px`;
}

// Добавляем обработчик события перемещения мыши
document.addEventListener("mousemove", drag_eye);
