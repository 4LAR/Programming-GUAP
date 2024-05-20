
const collider_height = 50;
document.addEventListener("mousemove", function(event) {
  var coordinatesTag = document.getElementsByTagName('h3')[0]; // Получаем тег h3
  coordinatesTag.textContent = 'X: ' + event.clientX + ', Y: ' + event.clientY; // Записываем координаты
});

function updateClock() {
  var now = new Date();
  var hours = now.getHours();
  var minutes = now.getMinutes();

  var hoursElement = document.getElementById('hours');
  var minutesElement = document.getElementById('minutes');

  hoursElement.textContent = hours < 10 ? '0' + hours : hours;
  minutesElement.textContent = minutes < 10 ? '0' + minutes : minutes;

  // Окраска цифр в зависимости от четности значений
  hoursElement.classList.toggle('even-hour', hours % 2 === 0);
  hoursElement.classList.toggle('odd-hour', hours % 2 !== 0);
  minutesElement.classList.toggle('even-minute', minutes % 2 === 0);
  minutesElement.classList.toggle('odd-minute', minutes % 2 !== 0);
}

// Запуск обновления часов каждую секунду
setInterval(updateClock, 1000);

// Начальное обновление часов
updateClock();

function change_color(element) {
  element.style.color = "#FF0000";
}

function change_width(element) {
  element.style.width = "100px";
  element.style.height = "100px";
}

function addrow(){
  let table = document.getElementById("table")
  var row = table.insertRow(2);
  var cell1 = row.insertCell(0);
  // cell1.innerHTML = "Пустая строка";
  cell1.innerHTML = document.getElementById('table_1').value;
  var cell2 = row.insertCell(1);
  // cell2.innerHTML = "Пустая строка";
  cell2.innerHTML = document.getElementById('table_2').value;
  var cell3 = row.insertCell(2);
  // cell3.innerHTML = "-";
  cell3.innerHTML = document.getElementById('table_3').value;
  var cell4 = row.insertCell(3);
  // cell4.innerHTML = "-";
  cell4.innerHTML = document.getElementById('table_4').value;
}

function me() {
  alert("Шатров Данила Николаевич 4134к");
}
