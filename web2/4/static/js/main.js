//
//  Набор js функций которые пригодятся в разработке
//

// функция для скрытия эелемента
function closeModal(modalId) {
  try {
    var modal = document.getElementById(modalId);
    modal.style.display = "none";
  } catch {
  }
}

// функция для показа эелемента (если элемент скрыт)
function openModal(modalId) {
  try {
    var modal = document.getElementById(modalId);
    modal.style.display = "block";
  } catch {
  }
}

// проверка на показ элемента
function checkModal(modalId) {
  try {
    var modal = document.getElementById(modalId);
    return (modal.style.display == "block")

  } catch {
    return false;
  }
}

// открыть новую вкладку
function openLinkInNewTab(url) {
  window.open(url, '_blank').focus();
}

// открыть новую вкладку
function openLink(url) {
  window.location = url;
}

// добавить элемент в список (ul)
function append_to_ul(id, content, onclick=undefined) {
  var ul = document.getElementById(id);

  var li = document.createElement("li");

  li.innerHTML = content;

  if (onclick) {
    li.onclick = onclick;
  }

  ul.appendChild(li);
}

// очистить список (ul)
function clear_ul(id) {
  document.getElementById(id).innerHTML = '';
}

// скрол до самого низа
function scroll_to_bottom(id) {
  var objDiv = document.getElementById(id);
  objDiv.scrollTop = objDiv.scrollHeight;
}

// скрол до самого верха
function scroll_to_top(id) {
  var objDiv = document.getElementById(id);
  objDiv.scrollTop = 0;
}

//
function debounce(func, wait_ms) {
  let timeout;
  return function (...args) {
    const context = this;
    clearTimeout(timeout);
    timeout = setTimeout(() => func.apply(context, args), wait_ms);
  };
}

// получить данные из локального хранилища
function get_localStorage(key, default_return=null) {
  if (localStorage.getItem(key) != null)
    return localStorage.getItem(key);

  else
    return default_return;
}

// фокус ввода на элемент
function on_focus(id) {
  document.getElementById(id).focus()
}

// получить адрес текущей страницы без домена
function get_current_page() {
  var addr = window.location.href.split("//")[1];
  return addr.slice(addr.indexOf("/"))
}

//
const getMethods = (obj) => {
  let properties = new Set()
  let currentObj = obj
  do {
    Object.getOwnPropertyNames(currentObj).map(item => properties.add(item))
  } while ((currentObj = Object.getPrototypeOf(currentObj)))
  return [...properties.keys()].filter(item => typeof obj[item] === 'function')
}

//
function check_device() {
  return (/Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent));
}

//
function generate_random_hex_color() {
  var letters = '0123456789ABCDEF';
  var color = '#';
  for (var i = 0; i < 6; i++) {
    color += letters[Math.floor(Math.random() * 16)];
  }
  return color;
}

// генерация рандомного числа
function getRndInteger(min, max) {
  return Math.floor(Math.random() * (max - min) ) + min;
}

//
function show_me() {
  alert("Столяров Никита Сергеевич 4134К");
}
